/* Copyright (c) 2019 Griefer@Work                                            *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifdef __INTELLISENSE__
#include "../ata.c"

#define IO_DMA 1
//#define IO_CHS 1
//#define IO_LBA28 1
//#define IO_LBA48 1
#define IO_READ 1
//#define IO_WRITE 1
//#define IO_VECTOR 1
//#define IO_PHYS 1
#endif

#if (defined(IO_DMA) + defined(IO_CHS) + defined(IO_LBA28) + defined(IO_LBA48)) != 1
#error "Must #define exactly one of `IO_DMA', `IO_CHS', `IO_LBA28', `IO_LBA48'"
#endif
#if (defined(IO_READ) + defined(IO_WRITE)) != 1
#error "Must #define exactly one of `IO_READ' or `IO_WRITE'"
#endif

#ifdef IO_DMA
#define FUNC0(x) Ata_DmaDrive##x
#elif defined(IO_CHS)
#define FUNC0(x) Ata_ChsDrive##x
#elif defined(IO_LBA28)
#define FUNC0(x) Ata_Lba28Drive##x
#elif defined(IO_LBA48)
#define FUNC0(x) Ata_Lba48Drive##x
#endif

#ifdef IO_READ
#define FUNC1(x) FUNC0(Read##x)
#else
#define FUNC1(x) FUNC0(Write##x)
#endif

#if defined(IO_VECTOR) && defined(IO_PHYS)
#define FUNC_VP(x)  x##v_phys
#define FUNC_VP2(x) x##VectorPhys
#define FUNC2    FUNC1(VectorPhys)
#define BUFFER_TYPE struct aio_pbuffer *__restrict
#define VECTOR_TYPE struct aio_pbuffer
#elif defined(IO_VECTOR)
#define FUNC_VP(x)  x##v
#define FUNC_VP2(x) x##Vector
#define FUNC2    FUNC1(Vector)
#define BUFFER_TYPE struct aio_buffer *__restrict
#define VECTOR_TYPE struct aio_buffer
#elif defined(IO_PHYS)
#define FUNC_VP(x)  x##_phys
#define FUNC_VP2(x) x##Phys
#define FUNC2    FUNC1(Phys)
#define BUFFER_TYPE vm_phys_t
#elif defined(IO_READ)
#define FUNC_VP(x)     x
#define FUNC_VP2(x)    x
#define FUNC2    FUNC0(Read)
#define BUFFER_TYPE USER CHECKED void *
#else
#define FUNC_VP(x)     x
#define FUNC_VP2(x)    x
#define FUNC2    FUNC0(Write)
#define BUFFER_TYPE USER CHECKED void const *
#endif


#if defined(IO_VECTOR) && defined(IO_PHYS)
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromPhysVector(prd_buf,prd_siz,buf,num_bytes)
#elif defined(IO_PHYS)
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromPhys(prd_buf,prd_siz,buf,num_bytes)
#elif defined(IO_VECTOR)
#ifdef IO_READ
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromVirtVector(prd_buf,prd_siz,buf,num_bytes,handle,false)
#else
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromVirtVector(prd_buf,prd_siz,buf,num_bytes,handle,true)
#endif
#else
#ifdef IO_READ
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromVirt(prd_buf,prd_siz,(vm_virt_t)(buf),num_bytes,handle,true)
#else
#define AtaPRD_INIT_FROM_BUF(prd_buf,prd_siz,buf,num_bytes,handle) \
        AtaPRD_InitFromVirt(prd_buf,prd_siz,(vm_virt_t)(buf),num_bytes,handle,false)
#endif
#endif


DECL_BEGIN



INTERN NONNULL((1, 5)) void KCALL
FUNC2(
#ifdef IO_DMA
      struct ata_dmadrive *__restrict self,
#else
      struct ata_drive *__restrict self,
#endif
      BUFFER_TYPE buf,
      size_t num_sectors,
      lba_t addr,
      struct aio_handle *__restrict aio)
		THROWS(E_IOERROR, E_BADALLOC,...) {
#ifdef IO_DMA
	size_t prd_count;
	AtaPRD prd0;
	struct ata_bus *bus    = self->d_bus;
	AtaAIOHandleData *data = (AtaAIOHandleData *)aio->ah_data;
	if unlikely(num_sectors > 0xffff)
		goto service_without_dma;
#if 0
	if unlikely(!PREEMPTION_ENABLED()) {
		/* TODO: Perform I/O without use of interrupts
		 *       If we managed to get this working, that would be huge, because
		 *       it would mean that we could just disable preemption in single-thread
		 *       situations such as the debugger or GDBstub driver in order to access
		 *       the disk.
		 *       I know that it's possible to do this (you can poll-wait for disk access),
		 *       but it might be complicated to implement given the fact that our ATA
		 *       driver is designed around the idea of asynchronous DMA transfer with
		 *       interrupt-driven PIO as fallback (so we'd need a fall-fall-back for
		 *       poll-driven PIO access)
		 * TODO: Check to see if we can perform the PREEMPTION_ENABLED() check later,
		 *       since testing this is one of the more expensive operations since we
		 *       can only access EFLAGS.IF by pushing it onto the stack... */
	}
#endif
	for (;;) {
		union ata_bus_state_and_flags state, newstate;
		COMPILER_READ_BARRIER();
		/* Try to switch from READ --> INDMA to immediately start a DMA I/O operation. */
		state = *ATA_BUSATA_BUS_STATE_AND_FLAGS(bus);
		COMPILER_READ_BARRIER();
		if (state.b_state != ATA_BUS_STATE_READY)
			break; /* The bus isn't ready to start DMAing immediately. */
		if (state.b_flags & ATA_BUS_FSUSPEND)
			break; /* The bus has been suspended */
		newstate.b_state = ATA_BUS_STATE_INDMA_SWITCH;
		newstate.b_flags = state.b_flags;
		if (!ATOMIC_CMPXCH_WEAK(*(uintptr_t *)ATA_BUSATA_BUS_STATE_AND_FLAGS(bus), state.b_word, newstate.b_word))
			continue;
		/* Don't kfree() `hd_prd_vector' */
#ifdef IO_READ
		data->hd_flags = ATA_AIO_HANDLE_FSINGLE;
#else
		data->hd_flags         = ATA_AIO_HANDLE_FSINGLE | ATA_AIO_HANDLE_FWRITING;
#endif
		/* Immediately start a new DMA operation. */
		prd_count = AtaPRD_INIT_FROM_BUF(bus->b_prdt,
		                                 ATA_PRD_MAXCOUNT,
		                                 buf,
		                                 num_sectors * ATA_SECTOR_SIZE(self),
		                                 data);
		if unlikely(!prd_count || prd_count > ATA_PRD_MAXCOUNT) {
			ata_check_suspended_and_load_future(bus);
			goto service_without_dma; /* Request contains non-canonical memory. */
		}
		ATA_VERBOSE("Switch to `ATA_BUS_STATE_INDMA_SWITCH' to setup initial DMA\n");
		aio->ah_type   = &Ata_DmaHandleType;
		data->hd_drive = self;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		*(u32 *)&data->hd_io_lbaaddr[0] = (u32)addr;
		*(u16 *)&data->hd_io_lbaaddr[4] = (u16)(addr >> 32);
		*(u16 *)&data->hd_io_sectors[0] = (u16)num_sectors;
#else
		data->hd_io_lbaaddr[0] = (u8)(addr);
		data->hd_io_lbaaddr[1] = (u8)(addr >> 8);
		data->hd_io_lbaaddr[2] = (u8)(addr >> 16);
		data->hd_io_lbaaddr[3] = (u8)(addr >> 24);
		data->hd_io_lbaaddr[4] = (u8)(addr >> 32);
		data->hd_io_lbaaddr[5] = (u8)(addr >> 40);
		data->hd_io_sectors[0] = (u8)(num_sectors);
		data->hd_io_sectors[1] = (u8)(num_sectors >> 8);
#endif
#ifdef IO_PHYS
		data->hd_dmalockvec = NULL;
		assert(!(data->hd_flags & ATA_AIO_HANDLE_FONEDMA));
#endif
		bus->b_dma_current = aio;
		/* Start the DMA operation, and handle any potential initialization failure. */
		if (!dostart_dma_operation(bus, aio)) {
			assert(bus->b_state == ATA_BUS_STATE_INDMA_SWITCH);
			ata_check_suspended_and_load_future(bus);
		}
		return;
	}
	/* The bus isn't in a ready state. - Setup `aio' as a pending DMA
	 * operation, and schedule it for execution at a later point in time. */
#ifdef IO_READ
	data->hd_flags = ATA_AIO_HANDLE_FSINGLE;
#else
	data->hd_flags = ATA_AIO_HANDLE_FSINGLE | ATA_AIO_HANDLE_FWRITING;
#endif
	prd_count = AtaPRD_INIT_FROM_BUF(&prd0,
	                                 1,
	                                 buf,
	                                 num_sectors * ATA_SECTOR_SIZE(self),
	                                 data);
	if (prd_count == 1) {
		/* Only a single PRD is required. */
		data->hd_prd0_bufaddr = prd0.p_bufaddr;
		data->hd_prd0_bufsize = prd0.p_bufsize;
	} else {
		AtaPRD *prdv;
		size_t new_prd_count;
		if unlikely(!prd_count || prd_count > ATA_PRD_MAXCOUNT)
			goto service_without_dma;
		/* Need multiple PRDs */
		prdv = (AtaPRD *)kmalloc(prd_count * sizeof(AtaPRD),
		                         GFP_LOCKED | GFP_PREFLT);
again_init_prdv:
#ifdef IO_READ
		data->hd_flags = ATA_AIO_HANDLE_FNORMAL;
#else /* IO_READ */
		data->hd_flags = ATA_AIO_HANDLE_FNORMAL | ATA_AIO_HANDLE_FWRITING;
#endif /* !IO_READ */
		new_prd_count = AtaPRD_INIT_FROM_BUF(prdv,
		                                     prd_count,
		                                     buf,
		                                     num_sectors * ATA_SECTOR_SIZE(self),
		                                     data);
		if unlikely(new_prd_count != prd_count) {
			AtaPRD *new_prdv;
			if unlikely(!new_prd_count || new_prd_count > ATA_PRD_MAXCOUNT) {
				kfree(prdv);
				goto service_without_dma;
			}
			if (new_prd_count > prd_count) {
				/* Allocate more memory for additional PRDs */
				TRY {
					new_prdv = (AtaPRD *)krealloc(prdv,
					                              new_prd_count * sizeof(AtaPRD),
					                              GFP_LOCKED | GFP_PREFLT);
				} EXCEPT {
					kfree(prdv);
					RETHROW();
				}
				prdv      = new_prdv;
				prd_count = new_prd_count;
				goto again_init_prdv;
			}
			new_prdv = (AtaPRD *)krealloc_nx(prdv,
			                                 new_prd_count * sizeof(AtaPRD),
			                                 GFP_LOCKED | GFP_PREFLT);
			if likely(new_prdv)
				prdv = new_prdv;
		}
		data->hd_prd_count  = new_prd_count;
		data->hd_prd_vector = prdv; /* Inherit */
	}
	/* Initialize additional stuff... */
	aio->ah_type   = &Ata_DmaHandleType;
	data->hd_drive = self;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	*(u32 *)&data->hd_io_lbaaddr[0] = (u32)addr;
	*(u16 *)&data->hd_io_lbaaddr[4] = (u16)(addr >> 32);
	*(u16 *)&data->hd_io_sectors[0] = (u16)num_sectors;
#else
	data->hd_io_lbaaddr[0] = (u8)(addr);
	data->hd_io_lbaaddr[1] = (u8)(addr >> 8);
	data->hd_io_lbaaddr[2] = (u8)(addr >> 16);
	data->hd_io_lbaaddr[3] = (u8)(addr >> 24);
	data->hd_io_lbaaddr[4] = (u8)(addr >> 32);
	data->hd_io_lbaaddr[5] = (u8)(addr >> 40);
	data->hd_io_sectors[0] = (u8)(num_sectors);
	data->hd_io_sectors[1] = (u8)(num_sectors >> 8);
#endif
#ifdef IO_PHYS
	data->hd_dmalockvec = NULL;
	assert(!(data->hd_flags & ATA_AIO_HANDLE_FONEDMA));
#endif
	/* Schedule the AIO handle as a pending I/O operation of the bus. */
	{
		struct aio_handle *next;
		COMPILER_READ_BARRIER();
		do {
			aio->ah_next = next = ATOMIC_READ(bus->b_dma_future);
		} while (!ATOMIC_CMPXCH_WEAK(bus->b_dma_future, next, aio));
		if (!next) { /* First pending DMA command. */
			/* The previous DMA chain may have completed the mean time, so
			 * we must manually start DMA once again to ensure that our
			 * operation will get serviced. */
			union ata_bus_state_and_flags state;
			union ata_bus_state_and_flags newstate;
			for (;;) {
				COMPILER_READ_BARRIER();
				state = *ATA_BUSATA_BUS_STATE_AND_FLAGS(bus);
				COMPILER_READ_BARRIER();
				if (state.b_state != ATA_BUS_STATE_READY)
					break; /* The bus isn't ready */
				if (state.b_flags & ATA_BUS_FSUSPEND)
					break; /* There are pending suspension requests (don't start DMAing now) */
				newstate.b_state = ATA_BUS_STATE_INDMA_SWITCH;
				newstate.b_flags = state.b_flags;
				if (!ATOMIC_CMPXCH_WEAK(*(uintptr_t *)ATA_BUSATA_BUS_STATE_AND_FLAGS(bus),
				                        state.b_word, newstate.b_word))
					continue;
				/* Start DMAing now. */
				ata_check_suspended_and_load_future(bus);
				break;
			}
		}
	}
	return;
service_without_dma:
	/* Perform a non-canonical I/O operation. */
#ifdef IO_READ
	(*self->FUNC_VP(d_noncanon_read))(self, buf, num_sectors, addr, aio);
#else
	(*self->FUNC_VP(d_noncanon_write))(self, buf, num_sectors, addr, aio);
#endif
#else /* IO_DMA */
#ifdef IO_LBA48
#define MAX_SECTORS_PER_TRANSFER 0xffff
#define MAX_SECTORS_PER_TRANSFER_T u16
#elif defined(IO_LBA28)
#define MAX_SECTORS_PER_TRANSFER 0xff
#define MAX_SECTORS_PER_TRANSFER_T u8
#elif defined(IO_CHS)
#define MAX_SECTORS_PER_TRANSFER 0xff /* ??? */
#define MAX_SECTORS_PER_TRANSFER_T u8
#endif
#ifdef IO_VECTOR
	VECTOR_TYPE view, view2;
#endif
	unsigned int reset_counter = 0;
	errr_t error;
	struct ata_bus *bus = self->d_bus;
	AtaBus_LockPIO(bus);
again_service_io:
	TRY {
		for (;;) {
			MAX_SECTORS_PER_TRANSFER_T part_sectors;
			assert(!task_isconnected());
			part_sectors = MAX_SECTORS_PER_TRANSFER;
			if ((size_t)part_sectors > num_sectors)
				part_sectors = (MAX_SECTORS_PER_TRANSFER_T)num_sectors;
			error = Ata_WaitForBusy(bus->b_ctrlio);
			if unlikely(error != ERRR_OK)
				goto err_io_error;
			task_connect(&bus->b_piointr);
#ifdef IO_CHS
			{
				u32 temp = (u32)((u32)addr / (u8)self->d_chs_sectors_per_track);
				u8 sector = (u8)(((u32)addr % (u8)self->d_chs_sectors_per_track) + 1);
				u8 head = (u8)((u32)temp % (u8)self->d_chs_number_of_heads);
				u16 cylinder = (u16)((u32)temp / (u8)self->d_chs_number_of_heads);
				u8 max_count = self->d_chs_sectors_per_track - sector;
				if (part_sectors > max_count)
					part_sectors = (MAX_SECTORS_PER_TRANSFER_T)max_count;
				outb(bus->b_busio + ATA_DRIVE_SELECT,
				     (self->d_drive + (0xe0 - ATA_DRIVE_MASTER)) | (head & 0xf));
				ATA_SELECT_DELAY(bus->b_busio);
				outb(bus->b_busio + ATA_SECTOR_COUNT, part_sectors);
				outb(bus->b_busio + ATA_ADDRESS1, (u8)sector);
				outb(bus->b_busio + ATA_ADDRESS2, (u8)cylinder);
				outb(bus->b_busio + ATA_ADDRESS3, (u8)(cylinder >> 8));
#ifdef IO_READ
				outb(bus->b_busio + ATA_COMMAND, ATA_COMMAND_READ_SECTORS);
#else
				outb(bus->b_busio + ATA_COMMAND, ATA_COMMAND_WRITE_SECTORS);
#endif
			}
#else /* IO_CHS */
#ifdef IO_LBA48
			outb(bus->b_busio + ATA_DRIVE_SELECT, self->d_drive);
			ATA_SELECT_DELAY(bus->b_ctrlio);
			outb(bus->b_busio + ATA_SECTOR_COUNT, (u8)(part_sectors >> 8));
			outb(bus->b_busio + ATA_ADDRESS1, (u8)(addr >> 24));
			outb(bus->b_busio + ATA_ADDRESS2, (u8)(addr >> 32));
			outb(bus->b_busio + ATA_ADDRESS3, (u8)(addr >> 40));
#else /* IO_LBA48 */
			outb(bus->b_busio + ATA_DRIVE_SELECT,
			     (0xe0 | (self->d_drive - ATA_DRIVE_MASTER)) |
			     ((u8)(addr >> 24) & 0xf));
			ATA_SELECT_DELAY(bus->b_ctrlio);
#endif /* !IO_LBA48 */
			outb(bus->b_busio + ATA_SECTOR_COUNT, (u8)part_sectors);
			outb(bus->b_busio + ATA_ADDRESS1, (u8)addr);
			outb(bus->b_busio + ATA_ADDRESS2, (u8)(addr >> 8));
			outb(bus->b_busio + ATA_ADDRESS3, (u8)(addr >> 16));
			outb(bus->b_busio + ATA_COMMAND,
#ifdef IO_READ
#ifdef IO_LBA48
			     ATA_COMMAND_READ_PIO_EXT
#else /* IO_LBA48 */
			     ATA_COMMAND_READ_PIO
#endif /* !IO_LBA48 */
#else
#ifdef IO_LBA48
			     ATA_COMMAND_WRITE_PIO_EXT
#else /* IO_LBA48 */
			     ATA_COMMAND_WRITE_PIO
#endif /* !IO_LBA48 */
#endif
			);
#endif /* !IO_CHS */

			/* Transfer sectors! */
#ifdef IO_READ
			error = FUNC_VP2(Ata_ReceiveDataSectors)(bus,
			                                         self,
#if defined(IO_PHYS) || defined(IO_VECTOR)
			                                         buf,
#else
			                                         (byte_t *)buf,
#endif
			                                         part_sectors);
#else /* IO_READ */
			error = FUNC_VP2(Ata_TransmitDataSectors)(bus,
			                                          self,
#if defined(IO_PHYS) || defined(IO_VECTOR)
			                                          buf,
#else
			                                          (byte_t const *)buf,
#endif
			                                          part_sectors);
#endif /* !IO_READ */
			assert(!task_isconnected());

			if (error != ERRR_OK)
				goto err_io_error;

			/* Check for transfer completion, and update pointers */
			if (part_sectors >= num_sectors)
				break;
			num_sectors -= part_sectors;
			addr += (lba_t)part_sectors;
#if defined(IO_VECTOR) && defined(IO_PHYS)
			if (buf == &view) {
				aio_pbuffer_init_view_after(&view2, &view, part_sectors * ATA_SECTOR_SIZE(self));
				buf = &view2;
			} else {
				aio_pbuffer_init_view_after(&view, buf, part_sectors * ATA_SECTOR_SIZE(self));
				buf = &view;
			}
#elif defined(IO_VECTOR)
			if (buf == &view) {
				aio_buffer_init_view_after(&view2, &view, part_sectors * ATA_SECTOR_SIZE(self));
				buf = &view2;
			} else {
				aio_buffer_init_view_after(&view, buf, part_sectors * ATA_SECTOR_SIZE(self));
				buf = &view;
			}
#elif defined(IO_PHYS)
			buf += (part_sectors * ATA_SECTOR_SIZE(self));
#else
			buf = (byte_t *)buf + (part_sectors * ATA_SECTOR_SIZE(self));
#endif
		}
	} EXCEPT {
		AtaBus_UnlockPIO(bus);
		RETHROW();
	}
	AtaBus_UnlockPIO(bus);
	/* Indicate AIO completion to the caller. */
	aio_handle_success(aio);
	return;
err_io_error:
	/* Always reset the bus (even if merely done for the next access) */
	assert(!task_isconnected());
	printk(KERN_ERR "Reseting IDE on PIO-I/O error code %#Ix:%#Ix (bus:%#I16x;ctrl:%#I16x;dma:%#I16x)\n",
	       ERRR_E(error), ERRR_R(error), bus->b_busio, bus->b_ctrlio, bus->b_dmaio);
	Ata_ResetAndReinitializeBus(bus);
	if (reset_counter < 3) { /* TODO: Make this `3' configurable */
		++reset_counter;
		/* Reset the bus, then try again! */
		goto again_service_io;
	}
	AtaBus_UnlockPIO(bus);
	handle_completion_ioerror_generic(aio, error);
#undef MAX_SECTORS_PER_TRANSFER_T
#undef MAX_SECTORS_PER_TRANSFER
#endif /* !IO_DMA */
}



DECL_END

#undef AtaPRD_INIT_FROM_BUF
#undef BUFFER_TYPE
#undef VECTOR_TYPE
#undef FUNC_VP2
#undef FUNC_VP
#undef FUNC0
#undef FUNC1
#undef FUNC2


#undef IO_DMA
#undef IO_CHS
#undef IO_LBA28
#undef IO_LBA48
#undef IO_READ
#undef IO_WRITE
#undef IO_VECTOR
#undef IO_PHYS
