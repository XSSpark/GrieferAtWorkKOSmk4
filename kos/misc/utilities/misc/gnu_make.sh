# Copyright (c) 2019-2022 Griefer@Work
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgement (see the following) in the product
#    documentation is required:
#    Portions Copyright (c) 2019-2022 Griefer@Work
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.

# Helpers to automate configure+make+install of packages that make
# use of GNU autoconf+automake

# Extract the package filename from the URL
_PACKAGE_URL_FILENAME="${PACKAGE_URL##*/}"

# Extract the package name from its filename
if test -z "$PACKAGE_NAME"; then
	PACKAGE_NAME="$_PACKAGE_URL_FILENAME"
	if [[ "$PACKAGE_NAME" == *.tar* ]]; then
		PACKAGE_NAME="${PACKAGE_NAME%.tar*}"
	fi
	if [[ "$PACKAGE_NAME" == "$_PACKAGE_URL_FILENAME" ]]; then
		echo "Unable to determine PACKAGE_NAME from"
		echo "	PACKAGE_URL:           $PACKAGE_URL"
		echo "	_PACKAGE_URL_FILENAME: $_PACKAGE_URL_FILENAME"
		exit 1
	fi
fi

if test -z "$PACKAGE_RAWNAME"; then
	PACKAGE_RAWNAME="$PACKAGE_NAME"
	if [[ "$PACKAGE_RAWNAME" == *-* ]]; then
		PACKAGE_RAWNAME="${PACKAGE_RAWNAME%-*}"
	fi
	if [[ "$PACKAGE_RAWNAME" == "$PACKAGE_NAME" ]]; then
		echo "Unable to determine PACKAGE_RAWNAME from"
		echo "	PACKAGE_NAME:          $PACKAGE_NAME"
		echo "	PACKAGE_URL:           $PACKAGE_URL"
		echo "	_PACKAGE_URL_FILENAME: $_PACKAGE_URL_FILENAME"
		exit 1
	fi
fi

if test -z "$PACKAGE_VERSION"; then
	PACKAGE_VERSION="$PACKAGE_NAME"
	if [[ "$PACKAGE_VERSION" == *-* ]]; then
		PACKAGE_VERSION="${PACKAGE_VERSION#*-}"
	fi
	if [[ "$PACKAGE_VERSION" == "$PACKAGE_NAME" ]]; then
		echo "Unable to determine PACKAGE_VERSION from"
		echo "	PACKAGE_NAME:          $PACKAGE_NAME"
		echo "	PACKAGE_URL:           $PACKAGE_URL"
		echo "	_PACKAGE_URL_FILENAME: $_PACKAGE_URL_FILENAME"
		exit 1
	fi
fi

if test -z "$PACKAGE_PREFIX";         then PACKAGE_PREFIX="/"; fi
if test -z "$PACKAGE_EPREFIX";        then PACKAGE_EPREFIX="$PACKAGE_PREFIX"; fi
if test -z "$PACKAGE_BINDIR";         then PACKAGE_BINDIR="${PACKAGE_EPREFIX%/}/bin"; fi
if test -z "$PACKAGE_SBINDIR";        then PACKAGE_SBINDIR="${PACKAGE_EPREFIX%/}/bin"; fi
if test -z "$PACKAGE_LIBEXECDIR";     then PACKAGE_LIBEXECDIR="${PACKAGE_EPREFIX%/}/libexec"; fi
if test -z "$PACKAGE_SYSCONFDIR";     then PACKAGE_SYSCONFDIR="${PACKAGE_PREFIX%/}/etc"; fi
if test -z "$PACKAGE_SHAREDSTATEDIR"; then PACKAGE_SHAREDSTATEDIR="${PACKAGE_PREFIX%/}/usr/com"; fi
if test -z "$PACKAGE_LOCALSTATEDIR";  then PACKAGE_LOCALSTATEDIR="${PACKAGE_PREFIX%/}/var"; fi
if test -z "$PACKAGE_RUNSTATEDIR";    then PACKAGE_RUNSTATEDIR="${PACKAGE_LOCALSTATEDIR}/run"; fi
if test -z "$PACKAGE_LIBDIR";         then PACKAGE_LIBDIR="${PACKAGE_EPREFIX%/}/$TARGET_LIBPATH"; fi
if test -z "$PACKAGE_INCLUDEDIR";     then PACKAGE_INCLUDEDIR="${PACKAGE_PREFIX%/}/usr/include"; fi
if test -z "$PACKAGE_OLDINCLUDEDIR";  then PACKAGE_OLDINCLUDEDIR="$PACKAGE_INCLUDEDIR"; fi
if test -z "$PACKAGE_DATAROOTDIR";    then PACKAGE_DATAROOTDIR="${PACKAGE_PREFIX%/}/usr/share"; fi
if test -z "$PACKAGE_DATADIR";        then PACKAGE_DATADIR="$PACKAGE_DATAROOTDIR"; fi
if test -z "$PACKAGE_INFODIR";        then PACKAGE_INFODIR="$PACKAGE_DATAROOTDIR/info"; fi
if test -z "$PACKAGE_LOCALEDIR";      then PACKAGE_LOCALEDIR="$PACKAGE_DATAROOTDIR/locale"; fi
if test -z "$PACKAGE_MANDIR";         then PACKAGE_MANDIR="$PACKAGE_DATAROOTDIR/man"; fi
if test -z "$PACKAGE_DOCDIR";         then PACKAGE_DOCDIR="$PACKAGE_DATAROOTDIR/doc/$PACKAGE_RAWNAME"; fi
if test -z "$PACKAGE_HTMLDIR";        then PACKAGE_HTMLDIR="$PACKAGE_DOCDIR"; fi
if test -z "$PACKAGE_DVIDIR";         then PACKAGE_DVIDIR="$PACKAGE_DOCDIR"; fi
if test -z "$PACKAGE_PDFDIR";         then PACKAGE_PDFDIR="$PACKAGE_DOCDIR"; fi
if test -z "$PACKAGE_PSDIR";          then PACKAGE_PSDIR="$PACKAGE_DOCDIR"; fi
if test -z "$PACKAGE_HOST";           then PACKAGE_HOST="$TARGET_NAME-linux-gnu"; fi
if test -z "$PACKAGE_TARGET";         then PACKAGE_TARGET="$PACKAGE_HOST"; fi


echo "gnu_make: PACKAGE_RAWNAME    '$PACKAGE_RAWNAME'"
echo "gnu_make: PACKAGE_VERSION    '$PACKAGE_VERSION'"
echo "gnu_make: PACKAGE_NAME       '$PACKAGE_NAME'"
if ! test -z "$PACKAGE_URL"; then
	echo "gnu_make: PACKAGE_URL        '$PACKAGE_URL'"
elif ! test -z "$PACKAGE_GIT_URL"; then
	echo "gnu_make: PACKAGE_GIT_URL    '$PACKAGE_GIT_URL'"
	if ! test -z "$PACKAGE_GIT_COMMIT"; then
		echo "gnu_make: PACKAGE_GIT_COMMIT '$PACKAGE_GIT_COMMIT'"
	fi
fi

#echo "gnu_make: PACKAGE_PREFIX         '$PACKAGE_PREFIX'"
#echo "gnu_make: PACKAGE_EPREFIX        '$PACKAGE_EPREFIX'"
#echo "gnu_make: PACKAGE_BINDIR         '$PACKAGE_BINDIR'"
#echo "gnu_make: PACKAGE_SBINDIR        '$PACKAGE_SBINDIR'"
#echo "gnu_make: PACKAGE_LIBEXECDIR     '$PACKAGE_LIBEXECDIR'"
#echo "gnu_make: PACKAGE_SYSCONFDIR     '$PACKAGE_SYSCONFDIR'"
#echo "gnu_make: PACKAGE_SHAREDSTATEDIR '$PACKAGE_SHAREDSTATEDIR'"
#echo "gnu_make: PACKAGE_LOCALSTATEDIR  '$PACKAGE_LOCALSTATEDIR'"
#echo "gnu_make: PACKAGE_LIBDIR         '$PACKAGE_LIBDIR'"
#echo "gnu_make: PACKAGE_INCLUDEDIR     '$PACKAGE_INCLUDEDIR'"
#echo "gnu_make: PACKAGE_OLDINCLUDEDIR  '$PACKAGE_OLDINCLUDEDIR'"
#echo "gnu_make: PACKAGE_DATAROOTDIR    '$PACKAGE_DATAROOTDIR'"
#echo "gnu_make: PACKAGE_DATADIR        '$PACKAGE_DATADIR'"
#echo "gnu_make: PACKAGE_INFODIR        '$PACKAGE_INFODIR'"
#echo "gnu_make: PACKAGE_LOCALEDIR      '$PACKAGE_LOCALEDIR'"
#echo "gnu_make: PACKAGE_MANDIR         '$PACKAGE_MANDIR'"
#echo "gnu_make: PACKAGE_DOCDIR         '$PACKAGE_DOCDIR'"
#echo "gnu_make: PACKAGE_HTMLDIR        '$PACKAGE_HTMLDIR'"
#echo "gnu_make: PACKAGE_DVIDIR         '$PACKAGE_DVIDIR'"
#echo "gnu_make: PACKAGE_PDFDIR         '$PACKAGE_PDFDIR'"
#echo "gnu_make: PACKAGE_PSDIR          '$PACKAGE_PSDIR'"
#echo "gnu_make: PACKAGE_HOST   '$PACKAGE_HOST'"
#echo "gnu_make: PACKAGE_TARGET '$PACKAGE_TARGET'"


_UTILITY_RELPATH=""
if [[ "$UTILITY_NAME" == */* ]]; then
	_UTILITY_RELPATH="${UTILITY_NAME%/*}"
	if ! test -z "$_UTILITY_RELPATH"; then
		_UTILITY_RELPATH="$_UTILITY_RELPATH/"
	fi
fi
SRCPATH="$KOS_ROOT/binutils/src/${_UTILITY_RELPATH}$PACKAGE_NAME"
OPTPATH="$BINUTILS_SYSROOT/opt/${_UTILITY_RELPATH}$PACKAGE_NAME"
DESTDIR="$BINUTILS_SYSROOT/opt/${_UTILITY_RELPATH}${PACKAGE_NAME}-install"

# libtool tends to be buggy when using DESTDIR install, and tries to
# include host system libraries during linking when it really shouldn't
# s.a. http://metastatic.org/text/libtool.html
#
# As a work-around, don't directly invoke gcc & friends, but use a set of
# hack-wrappers that will filter out attempts to bind system libraries or
# headers.
. "$KOS_MISC/utilities/misc/gcc_hack.sh"

if [ "$MODE_FORCE_MAKE" == yes ] || ! [ -d "$DESTDIR" ]; then
	if [ "$MODE_FORCE_MAKE" == yes ] || ! [ -f "$OPTPATH/_didmake" ]; then
		if [ "$MODE_FORCE_CONF" == yes ] || ! [ -f "$OPTPATH/Makefile" ]; then
			if ! [ -f "$SRCPATH/configure" ]; then
				# Remove $SRCPATH if it's just an empty directory
				rmdir "$SRCPATH" > /dev/null 2>&1
				if ! [ -d "$SRCPATH" ]; then
					BINUTILS_SOURCES="$(dirname "$SRCPATH")"
					cmd mkdir -p "$BINUTILS_SOURCES"
					cmd cd "$BINUTILS_SOURCES"
					if ! test -z "$PACKAGE_URL"; then
						_PACKAGE_URL_FILENAME="${PACKAGE_URL##*/}"
						# Figure out how to download+unpack the package
						if [[ "$_PACKAGE_URL_FILENAME" == *.tar* ]]; then
							# Tar archive. Extract the filename of the file that will be downloaded
							# After downloading, make sure that filename becomes "$PACKAGE_NAME.tar[.gz|.xz|...]"
							_PACKAGE_URL_NAME="${_PACKAGE_URL_FILENAME%.tar*}"
							_PACKAGE_URL_FILENAME_EXT=".tar${_PACKAGE_URL_FILENAME#*.tar}"
							_PACKAGE_URL_WANTED_FILENAME="${PACKAGE_NAME}.tar${_PACKAGE_URL_FILENAME#*.tar}"
							if ! [ -f "$_PACKAGE_URL_WANTED_FILENAME" ]; then
								download_file "$_PACKAGE_URL_FILENAME" "$PACKAGE_URL"
								if [ "$_PACKAGE_URL_WANTED_FILENAME" != "$_PACKAGE_URL_FILENAME" ]; then
									cmd mv "$_PACKAGE_URL_FILENAME" "$_PACKAGE_URL_WANTED_FILENAME"
								fi
							fi
							rm -r "./$_PACKAGE_URL_NAME" > /dev/null 2>&1
							cmd mkdir -p "$SRCPATH"
							cmd tar xvf "$_PACKAGE_URL_WANTED_FILENAME" -C "$SRCPATH"
						else
							# Unrecognized package distribution format
							echo "No known way of extracting files from: '$_PACKAGE_URL_FILENAME'"
							exit 1
						fi
					elif ! test -z "$PACKAGE_GIT_URL"; then
						# Figure out the directory name that
						cmd mkdir -p "$SRCPATH"
						cmd cd "$SRCPATH"
						cmd git clone "$PACKAGE_GIT_URL"
						if ! test -z "$PACKAGE_GIT_COMMIT"; then
							# Checkout the requested git revision
							cmd cd "$(ls -A)"
							cmd git checkout -f "$PACKAGE_GIT_COMMIT"
						fi
					else
						echo "No way of downloading $PACKAGE_NAME"
					fi
				fi
				cmd cd "$SRCPATH"
				# Fix-up doubly-packaged packages
				while [[ `ls -A | wc -l` == 1 ]]; do
					subdirname=`ls -A`
					echo "Fix-up doubly-packed package '$subdirname' -> '${PACKAGE_NAME}'"
					rm -r "$BINUTILS_SOURCES/.${PACKAGE_NAME}-real" > /dev/null 2>&1
					cmd mv "$subdirname" "../.${PACKAGE_NAME}-real"
					cmd cd ".."
					cmd rmdir "${PACKAGE_NAME}"
					cmd mv ".${PACKAGE_NAME}-real" "${PACKAGE_NAME}"
					cmd cd "$SRCPATH"
				done
				# (Try to) generate configure (if it's missing)
				if ! [ -f "$SRCPATH/configure" ]; then
					if [ -f "$SRCPATH/configure.ac" ]; then
						_PACKAGE_AUTOCONF_INPUT="$SRCPATH/configure.ac"
					elif [ -f "$SRCPATH/configure.in" ]; then
						_PACKAGE_AUTOCONF_INPUT="$SRCPATH/configure.in"
					else
						echo "Not a GNU autoconf project (missing file: 'configure')"
						exit 1
					fi
					# Check for autoconf dependencies of this project
					ac_requires_xorg=no
					while IFS= read -r line; do
						case "$line" in

						*XORG_MACROS_VERSION*)
							ac_requires_xorg=yes
							;;

						*) ;;
						esac
					done < "$_PACKAGE_AUTOCONF_INPUT"
					# Bind xorg-macros
					if test x"$ac_requires_xorg" != xno; then
						. "$KOS_MISC/utilities/Xorg/misc/xorg-macros.sh"
					fi
					# Generate all of the missing files.
					cmd autoreconf -i
					if ! [ -f "$SRCPATH/Makefile.in" ] && [ -f "$SRCPATH/Makefile.am" ]; then
						cmd cd "$SRCPATH"
						cmd automake
					fi
					if ! [ -f "$SRCPATH/configure" ]; then
						cmd cd "$SRCPATH"
						cmd autoconf
					fi
					# Try to converse disk space by getting rid of cache files created by autoreconf.
					rm -r "$SRCPATH/autom4te.cache" > /dev/null 2>&1
				fi
			fi
			if [ -f "$KOS_PATCHES/$PACKAGE_NAME.patch" ]; then
				apply_patch "$SRCPATH" "$KOS_PATCHES/$PACKAGE_NAME.patch"
			fi

			${GM_HOOK_BEFORE_CONFARGS:-:}

			rm -r "$OPTPATH" > /dev/null 2>&1
			cmd mkdir -p "$OPTPATH"
			cmd cd "$OPTPATH"

			# Auto-configure arguments for ./configure
			if ! test -z "$PACKAGE_CONFIGURE"; then
				CONFIGURE="$PACKAGE_CONFIGURE $CONFIGURE"
				if ! test -z "$CONFIGURE"; then
					echo "Using given \$PACKAGE_CONFIGURE and \$CONFIGURE options:"
					for opt in $CONFIGURE; do
						echo "	option: $opt"
					done
				fi
			else
				# Auto-detect supported, but unset options
				if ! [ -f "$SRCPATH/._configure_help" ]; then
					echo "Creating file: '$SRCPATH/._configure_help'"
					cmd bash "$SRCPATH/configure" --help > "$SRCPATH/._configure_help.temp" 2>&1
					cmd mv "$SRCPATH/._configure_help.temp" "$SRCPATH/._configure_help"
				fi
				if ! test -z "$CONFIGURE"; then
					echo "Using given \$CONFIGURE options:"
					for opt in $CONFIGURE; do
						echo "	option: $opt"
					done
				fi
				echo "Scanning '$SRCPATH/configure --help' for options..."
				while IFS= read -r line; do
					case "$line" in
					*--prefix=*)         if ! [[ "$CONFIGURE" == *--prefix=*         ]]; then echo "	option: --prefix=$PACKAGE_PREFIX";                 CONFIGURE="$CONFIGURE --prefix=$PACKAGE_PREFIX"; fi ;;
					*--eprefix=*)        if ! [[ "$CONFIGURE" == *--eprefix=*        ]]; then echo "	option: --eprefix=$PACKAGE_EPREFIX";               CONFIGURE="$CONFIGURE --eprefix=$PACKAGE_EPREFIX"; fi ;;
					*--exec-prefix=*)    if ! [[ "$CONFIGURE" == *--exec-prefix=*    ]]; then echo "	option: --exec-prefix=$PACKAGE_EPREFIX";           CONFIGURE="$CONFIGURE --exec-prefix=$PACKAGE_EPREFIX"; fi ;;
					*--bindir=*)         if ! [[ "$CONFIGURE" == *--bindir=*         ]]; then echo "	option: --bindir=$PACKAGE_BINDIR";                 CONFIGURE="$CONFIGURE --bindir=$PACKAGE_BINDIR"; fi ;;
					*--sbindir=*)        if ! [[ "$CONFIGURE" == *--sbindir=*        ]]; then echo "	option: --sbindir=$PACKAGE_SBINDIR";               CONFIGURE="$CONFIGURE --sbindir=$PACKAGE_SBINDIR"; fi ;;
					*--libexecdir=*)     if ! [[ "$CONFIGURE" == *--libexecdir=*     ]]; then echo "	option: --libexecdir=$PACKAGE_SBINDIR";            CONFIGURE="$CONFIGURE --libexecdir=$PACKAGE_SBINDIR"; fi ;;
					*--sysconfdir=*)     if ! [[ "$CONFIGURE" == *--sysconfdir=*     ]]; then echo "	option: --sysconfdir=$PACKAGE_SYSCONFDIR";         CONFIGURE="$CONFIGURE --sysconfdir=$PACKAGE_SYSCONFDIR"; fi ;;
					*--sharedstatedir=*) if ! [[ "$CONFIGURE" == *--sharedstatedir=* ]]; then echo "	option: --sharedstatedir=$PACKAGE_SHAREDSTATEDIR"; CONFIGURE="$CONFIGURE --sharedstatedir=$PACKAGE_SHAREDSTATEDIR"; fi ;;
					*--localstatedir=*)  if ! [[ "$CONFIGURE" == *--localstatedir=*  ]]; then echo "	option: --localstatedir=$PACKAGE_LOCALSTATEDIR";   CONFIGURE="$CONFIGURE --localstatedir=$PACKAGE_LOCALSTATEDIR"; fi ;;
					*--runstatedir=*)    if ! [[ "$CONFIGURE" == *--runstatedir=*    ]]; then echo "	option: --runstatedir=$PACKAGE_RUNSTATEDIR";       CONFIGURE="$CONFIGURE --runstatedir=$PACKAGE_RUNSTATEDIR"; fi ;;
					*--libdir=*)         if ! [[ "$CONFIGURE" == *--libdir=*         ]]; then echo "	option: --libdir=$PACKAGE_LIBDIR";                 CONFIGURE="$CONFIGURE --libdir=$PACKAGE_LIBDIR"; fi ;;
					*--includedir=*)     if ! [[ "$CONFIGURE" == *--includedir=*     ]]; then echo "	option: --includedir=$PACKAGE_INCLUDEDIR";         CONFIGURE="$CONFIGURE --includedir=$PACKAGE_INCLUDEDIR"; fi ;;
					*--oldincludedir=*)  if ! [[ "$CONFIGURE" == *--oldincludedir=*  ]]; then echo "	option: --oldincludedir=$PACKAGE_OLDINCLUDEDIR";   CONFIGURE="$CONFIGURE --oldincludedir=$PACKAGE_OLDINCLUDEDIR"; fi ;;
					*--datarootdir=*)    if ! [[ "$CONFIGURE" == *--datarootdir=*    ]]; then echo "	option: --datarootdir=$PACKAGE_DATAROOTDIR";       CONFIGURE="$CONFIGURE --datarootdir=$PACKAGE_DATAROOTDIR"; fi ;;
					*--datadir=*)        if ! [[ "$CONFIGURE" == *--datadir=*        ]]; then echo "	option: --datadir=$PACKAGE_DATADIR";               CONFIGURE="$CONFIGURE --datadir=$PACKAGE_DATADIR"; fi ;;
					*--infodir=*)        if ! [[ "$CONFIGURE" == *--infodir=*        ]]; then echo "	option: --infodir=$PACKAGE_INFODIR";               CONFIGURE="$CONFIGURE --infodir=$PACKAGE_INFODIR"; fi ;;
					*--localedir=*)      if ! [[ "$CONFIGURE" == *--localedir=*      ]]; then echo "	option: --localedir=$PACKAGE_LOCALEDIR";           CONFIGURE="$CONFIGURE --localedir=$PACKAGE_LOCALEDIR"; fi ;;
					*--mandir=*)         if ! [[ "$CONFIGURE" == *--mandir=*         ]]; then echo "	option: --mandir=$PACKAGE_MANDIR";                 CONFIGURE="$CONFIGURE --mandir=$PACKAGE_MANDIR"; fi ;;
					*--docdir=*)         if ! [[ "$CONFIGURE" == *--docdir=*         ]]; then echo "	option: --docdir=$PACKAGE_DOCDIR";                 CONFIGURE="$CONFIGURE --docdir=$PACKAGE_DOCDIR"; fi ;;
					*--htmldir=*)        if ! [[ "$CONFIGURE" == *--htmldir=*        ]]; then echo "	option: --htmldir=$PACKAGE_HTMLDIR";               CONFIGURE="$CONFIGURE --htmldir=$PACKAGE_HTMLDIR"; fi ;;
					*--dvidir=*)         if ! [[ "$CONFIGURE" == *--dvidir=*         ]]; then echo "	option: --dvidir=$PACKAGE_DVIDIR";                 CONFIGURE="$CONFIGURE --dvidir=$PACKAGE_DVIDIR"; fi ;;
					*--pdfdir=*)         if ! [[ "$CONFIGURE" == *--pdfdir=*         ]]; then echo "	option: --pdfdir=$PACKAGE_PDFDIR";                 CONFIGURE="$CONFIGURE --pdfdir=$PACKAGE_PDFDIR"; fi ;;
					*--psdir=*)          if ! [[ "$CONFIGURE" == *--psdir=*          ]]; then echo "	option: --psdir=$PACKAGE_PSDIR";                   CONFIGURE="$CONFIGURE --psdir=$PACKAGE_PSDIR"; fi ;;
					*--host=*)           if ! [[ "$CONFIGURE" == *--host=*           ]]; then echo "	option: --host=$PACKAGE_HOST";                     CONFIGURE="$CONFIGURE --host=$PACKAGE_HOST"; fi ;;
					*--target=*)         if ! [[ "$CONFIGURE" == *--target=*         ]]; then echo "	option: --target=$PACKAGE_TARGET";                 CONFIGURE="$CONFIGURE --target=$PACKAGE_TARGET"; fi ;;

					# System root
					*--with-sysroot*)
						if ! [[ "$CONFIGURE" == *--with-sysroot=* ]]; then
							echo "	option: --with-sysroot=$BINUTILS_SYSROOT"
							CONFIGURE="$CONFIGURE --with-sysroot=$BINUTILS_SYSROOT"
						fi
						;;

					# Install location
					*--with-install-prefix*)
						if ! [[ "$CONFIGURE" == *--with-install-prefix=* ]]; then
							echo "	option: --with-install-prefix=$DESTDIR-temp"
							CONFIGURE="$CONFIGURE --with-install-prefix=$DESTDIR-temp"
						fi
						;;

					# Name of the host machine
					*--build=*)
						if ! [[ "$CONFIGURE" == *--build=* ]]; then
							if test -z "$PACKAGE_BUILD"; then
								PACKAGE_BUILD="$(gcc -dumpmachine)"
							fi
							echo "	option: --build=$PACKAGE_BUILD"
							CONFIGURE="$CONFIGURE --build=$PACKAGE_BUILD"
						fi
						;;

					# Misc default feature selection
					*--disable-largefile* | *--enable-largefile*)
						if ! [[ "$CONFIGURE" == *--enable-largefile* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-largefile* ]]; then
							if test -z "$PACKAGE_WITHOUT_LARGEFILE"; then
								echo "	option: --enable-largefile"
								CONFIGURE="$CONFIGURE --enable-largefile"
							else
								echo "	option: --disable-largefile"
								CONFIGURE="$CONFIGURE --disable-largefile"
							fi
						fi
						;;

					*--disable-nls* | *--enable-nls*)
						if ! [[ "$CONFIGURE" == *--enable-nls* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-nls* ]]; then
							echo "	option: --enable-nls"
							CONFIGURE="$CONFIGURE --enable-nls"
						fi
						;;

					*--enable-malloc0returnsnull* | *--disable-malloc0returnsnull*)
						# Used by (some) Xorg utilities
						if ! [[ "$CONFIGURE" == *--enable-malloc0returnsnull* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-malloc0returnsnull* ]]; then
							echo "	option: --disable-malloc0returnsnull"
							CONFIGURE="$CONFIGURE --disable-malloc0returnsnull"
						fi
						;;

					*--disable-specs* | *--enable-specs*)
						# Used by Xorg utilities
						if ! [[ "$CONFIGURE" == *--enable-specs* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-specs* ]]; then
							if test -z "$PACKAGE_WITH_SPECS"; then
								echo "	option: --disable-specs"
								CONFIGURE="$CONFIGURE --disable-specs"
							else
								echo "	option: --enable-specs"
								CONFIGURE="$CONFIGURE --enable-specs"
							fi
						fi
						;;

					*--disable-docs* | *--enable-docs*)
						if ! [[ "$CONFIGURE" == *--enable-docs* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-docs* ]]; then
							if test -z "$PACKAGE_WITH_DOCS"; then
								echo "	option: --disable-docs"
								CONFIGURE="$CONFIGURE --disable-docs"
							else
								echo "	option: --enable-docs"
								CONFIGURE="$CONFIGURE --enable-docs"
							fi
						fi
						;;

					*--disable-doc* | *--enable-doc*)
						if ! [[ "$CONFIGURE" == *--enable-doc* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-doc* ]]; then
							if test -z "$PACKAGE_WITH_DOCS"; then
								echo "	option: --disable-doc"
								CONFIGURE="$CONFIGURE --disable-doc"
							else
								echo "	option: --enable-doc"
								CONFIGURE="$CONFIGURE --enable-doc"
							fi
						fi
						;;

					*--without-docs* | *--with-docs*)
						if ! [[ "$CONFIGURE" == *--with-docs* ]] && \
						   ! [[ "$CONFIGURE" == *--without-docs* ]]; then
							if test -z "$PACKAGE_WITH_DOCS"; then
								echo "	option: --without-docs"
								CONFIGURE="$CONFIGURE --without-docs"
							else
								echo "	option: --with-docs"
								CONFIGURE="$CONFIGURE --with-docs"
							fi
						fi
						;;

					*--disable-devel-docs* | *--enable-devel-docs*)
						if ! [[ "$CONFIGURE" == *--enable-devel-docs* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-devel-docs* ]]; then
							if test -z "$PACKAGE_WITH_DOCS"; then
								echo "	option: --disable-devel-docs"
								CONFIGURE="$CONFIGURE --disable-devel-docs"
							else
								echo "	option: --enable-devel-docs"
								CONFIGURE="$CONFIGURE --enable-devel-docs"
							fi
						fi
						;;

					*--without-manpages* | *--with-manpages*)
						if ! [[ "$CONFIGURE" == *--with-manpages* ]] && \
						   ! [[ "$CONFIGURE" == *--without-manpages* ]]; then
							if test -z "$PACKAGE_WITH_DOCS"; then
								echo "	option: --without-manpages"
								CONFIGURE="$CONFIGURE --without-manpages"
							else
								echo "	option: --with-manpages"
								CONFIGURE="$CONFIGURE --with-manpages"
							fi
						fi
						;;

					*--without-examples* | *--with-examples*)
						if ! [[ "$CONFIGURE" == *--with-examples* ]] && \
						   ! [[ "$CONFIGURE" == *--without-examples* ]]; then
							echo "	option: --without-examples"
							CONFIGURE="$CONFIGURE --without-examples"
						fi
						;;

					*--without-doxygen* | *--with-doxygen*)
						if ! [[ "$CONFIGURE" == *--with-doxygen* ]] && \
						   ! [[ "$CONFIGURE" == *--without-doxygen* ]]; then
							echo "	option: --without-doxygen"
							CONFIGURE="$CONFIGURE --without-doxygen"
						fi
						;;

					*--without-tests* | *--with-tests*)
						if ! [[ "$CONFIGURE" == *--with-tests* ]] && \
						   ! [[ "$CONFIGURE" == *--without-tests* ]]; then
							echo "	option: --without-tests"
							CONFIGURE="$CONFIGURE --without-tests"
						fi
						;;

					*--disable-tests* | *--enable-tests*)
						if ! [[ "$CONFIGURE" == *--enable-tests* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-tests* ]]; then
							echo "	option: --disable-tests"
							CONFIGURE="$CONFIGURE --disable-tests"
						fi
						;;

					*--disable-unit-tests* | *--enable-unit-tests*)
						if ! [[ "$CONFIGURE" == *--enable-unit-tests* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-unit-tests* ]]; then
							echo "	option: --disable-unit-tests"
							CONFIGURE="$CONFIGURE --disable-unit-tests"
						fi
						;;

					*--without-xmlto* | *--with-xmlto*)
						if ! [[ "$CONFIGURE" == *--with-xmlto* ]] && \
						   ! [[ "$CONFIGURE" == *--without-xmlto* ]]; then
							echo "	option: --without-xmlto"
							CONFIGURE="$CONFIGURE --without-xmlto"
						fi
						;;

					*--without-fop* | *--with-fop*)
						if ! [[ "$CONFIGURE" == *--with-fop* ]] && \
						   ! [[ "$CONFIGURE" == *--without-fop* ]]; then
							echo "	option: --without-fop"
							CONFIGURE="$CONFIGURE --without-fop"
						fi
						;;

					*--without-lint* | *--with-lint*)
						if ! [[ "$CONFIGURE" == *--with-lint* ]] && \
						   ! [[ "$CONFIGURE" == *--without-lint* ]]; then
							echo "	option: --without-lint"
							CONFIGURE="$CONFIGURE --without-lint"
						fi
						;;

					*--without-launchd* | *--with-launchd*)
						if ! [[ "$CONFIGURE" == *--with-launchd* ]] && \
						   ! [[ "$CONFIGURE" == *--without-launchd* ]]; then
							echo "	option: --without-launchd"
							CONFIGURE="$CONFIGURE --without-launchd"
						fi
						;;

					# Misc options
					*--with-libiconv-prefix* | *--without-libiconv-prefix*)
						if ! [[ "$CONFIGURE" == *--with-libiconv-prefix* ]] && \
						   ! [[ "$CONFIGURE" == *--without-libiconv-prefix* ]]; then
							echo "	option: --without-libiconv-prefix"
							CONFIGURE="$CONFIGURE --without-libiconv-prefix"
						fi
						;;

					*--with-libintl-prefix* | *--without-libintl-prefix*)
						if ! [[ "$CONFIGURE" == *--with-libintl-prefix* ]] && \
						   ! [[ "$CONFIGURE" == *--without-libintl-prefix* ]]; then
							echo "	option: --without-libintl-prefix"
							CONFIGURE="$CONFIGURE --without-libintl-prefix"
						fi
						;;

					*--with-gnu-ld* | *--without-gnu-ld*)
						if ! [[ "$CONFIGURE" == *--with-gnu-ld* ]] && \
						   ! [[ "$CONFIGURE" == *--without-gnu-ld* ]]; then
							if test -z "$PACKAGE_WITHOUT_GNU_LD"; then
								echo "	option: --with-gnu-ld"
								CONFIGURE="$CONFIGURE --with-gnu-ld"
							else
								echo "	option: --without-gnu-ld"
								CONFIGURE="$CONFIGURE --without-gnu-ld"
							fi
						fi
						;;

					*--enable-rpath* | *--disable-rpath*)
						if ! [[ "$CONFIGURE" == *--enable-rpath* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-rpath* ]]; then
							echo "	option: --disable-rpath"
							CONFIGURE="$CONFIGURE --disable-rpath"
						fi
						;;

					*--enable-shared* | *--disable-shared*)
						if ! [[ "$CONFIGURE" == *--enable-shared* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-shared* ]]; then
							echo "	option: --enable-shared"
							CONFIGURE="$CONFIGURE --enable-shared"
						fi
						;;

					*--enable-static* | *--disable-static*)
						if ! [[ "$CONFIGURE" == *--enable-static* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-static* ]]; then
							echo "	option: --enable-static"
							CONFIGURE="$CONFIGURE --enable-static"
						fi
						;;

					*--with-shared* | *--without-shared*)
						# Alternate name for --enable-shared
						if ! [[ "$CONFIGURE" == *--with-shared* ]] && \
						   ! [[ "$CONFIGURE" == *--without-shared* ]]; then
							echo "	option: --with-shared"
							CONFIGURE="$CONFIGURE --with-shared"
						fi
						;;

					*--with-normal* | *--without-normal*)
						# Alternate name for --enable-static
						if ! [[ "$CONFIGURE" == *--with-normal* ]] && \
						   ! [[ "$CONFIGURE" == *--without-normal* ]]; then
							echo "	option: --with-normal"
							CONFIGURE="$CONFIGURE --with-normal"
						fi
						;;

					*--with-debug* | *--without-debug*)
						# Enable debug features (KOS is still young, so any debug
						# features offered by hosted applications should be enabled
						# by default)
						if ! [[ "$CONFIGURE" == *--with-debug* ]] && \
						   ! [[ "$CONFIGURE" == *--without-debug* ]]; then
							echo "	option: --with-debug"
							CONFIGURE="$CONFIGURE --with-debug"
						fi
						;;

					*--with-profile* | *--without-profile*)
						# Disable profiling features by default
						if ! [[ "$CONFIGURE" == *--with-profile* ]] && \
						   ! [[ "$CONFIGURE" == *--without-profile* ]]; then
							echo "	option: --without-profile"
							CONFIGURE="$CONFIGURE --without-profile"
						fi
						;;

					*--enable-stripping* | *--disable-stripping*)
						# Prevent debug symbols from being stripped
						if ! [[ "$CONFIGURE" == *--enable-stripping* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-stripping* ]]; then
							echo "	option: --disable-stripping"
							CONFIGURE="$CONFIGURE --disable-stripping"
						fi
						;;

					*--enable-pc-files* | *--disable-pc-files*)
						# Instruct to generate *.pc (PKG_CONFIG) files
						if ! [[ "$CONFIGURE" == *--enable-pc-files* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-pc-files* ]]; then
							echo "	option: --enable-pc-files"
							CONFIGURE="$CONFIGURE --enable-pc-files"
						fi
						;;

					*--enable-lint-library* | *--disable-lint-library*)
						if ! [[ "$CONFIGURE" == *--enable-lint-library* ]] && \
						   ! [[ "$CONFIGURE" == *--disable-lint-library* ]]; then
							echo "	option: --disable-lint-library"
							CONFIGURE="$CONFIGURE --disable-lint-library"
						fi
						;;

					*--with-xsltproc* | *--without-xsltproc*)
						if ! [[ "$CONFIGURE" == *--with-xsltproc* ]] && \
						   ! [[ "$CONFIGURE" == *--without-xsltproc* ]]; then
							echo "	option: --without-xsltproc"
							CONFIGURE="$CONFIGURE --without-xsltproc"
						fi
						;;

					*--disable-doxygen-doc* | *--enable-doxygen-doc*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-doc* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-doc* ]]; then
							echo "	option: --disable-doxygen-doc"
							CONFIGURE="$CONFIGURE --disable-doxygen-doc"
						fi
						;;

					*--disable-doxygen-dot* | *--enable-doxygen-dot*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-dot* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-dot* ]]; then
							echo "	option: --disable-doxygen-dot"
							CONFIGURE="$CONFIGURE --disable-doxygen-dot"
						fi
						;;

					*--disable-doxygen-man* | *--enable-doxygen-man*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-man* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-man* ]]; then
							echo "	option: --disable-doxygen-man"
							CONFIGURE="$CONFIGURE --disable-doxygen-man"
						fi
						;;

					*--disable-doxygen-rtf* | *--enable-doxygen-rtf*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-rtf* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-rtf* ]]; then
							echo "	option: --disable-doxygen-rtf"
							CONFIGURE="$CONFIGURE --disable-doxygen-rtf"
						fi
						;;

					*--disable-doxygen-xml* | *--enable-doxygen-xml*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-xml* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-xml* ]]; then
							echo "	option: --disable-doxygen-xml"
							CONFIGURE="$CONFIGURE --disable-doxygen-xml"
						fi
						;;

					*--disable-doxygen-chm* | *--enable-doxygen-chm*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-chm* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-chm* ]]; then
							echo "	option: --disable-doxygen-chm"
							CONFIGURE="$CONFIGURE --disable-doxygen-chm"
						fi
						;;

					*--disable-doxygen-chi* | *--enable-doxygen-chi*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-chi* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-chi* ]]; then
							echo "	option: --disable-doxygen-chi"
							CONFIGURE="$CONFIGURE --disable-doxygen-chi"
						fi
						;;

					*--disable-doxygen-html* | *--enable-doxygen-html*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-html* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-html* ]]; then
							echo "	option: --disable-doxygen-html"
							CONFIGURE="$CONFIGURE --disable-doxygen-html"
						fi
						;;

					*--disable-doxygen-ps* | *--enable-doxygen-ps*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-ps* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-ps* ]]; then
							echo "	option: --disable-doxygen-ps"
							CONFIGURE="$CONFIGURE --disable-doxygen-ps"
						fi
						;;

					*--disable-doxygen-pdf* | *--enable-doxygen-pdf*)
						if ! [[ "$CONFIGURE" == *--disable-doxygen-pdf* ]] && \
						   ! [[ "$CONFIGURE" == *--enable-doxygen-pdf* ]]; then
							echo "	option: --disable-doxygen-pdf"
							CONFIGURE="$CONFIGURE --disable-doxygen-pdf"
						fi
						;;

					*) ;;
					esac
				done < "$SRCPATH/._configure_help"
			fi

			# Auto-configure a custom config.site for ./configure
			if ! test -z "$PACKAGE_CONFIG_SITE"; then
				CONFIG_SITE="$PACKAGE_CONFIG_SITE
$CONFIG_SITE"
				if ! test -z "$CONFIG_SITE"; then
					echo "Using given \$PACKAGE_CONFIG_SITE and \$CONFIG_SITE options:"
					while IFS= read -r line; do
						echo "	>> $line"
					done <<< "$CONFIG_SITE"
				fi
			else
				# Auto-detect necessary config.site options
				if ! test -z "$CONFIG_SITE"; then
					echo "Using given \$CONFIG_SITE options:"
					while IFS= read -r line; do
						echo "	>> $line"
					done <<< "$CONFIG_SITE"
				fi
				echo "Scanning '$SRCPATH/configure' for needed config.site options..."
				_config_site_option() {
					if ! [[ "$CONFIG_SITE" == *$1* ]]; then
						echo "	config.site: $1=$2"
						CONFIG_SITE="$1=$2
$CONFIG_SITE"
					fi
				}
				_test_links() {
					"${CROSS_PREFIX}gcc" -o "$OPTPATH/_gm_outfile" -x c - > /dev/null 2>&1
					local error="$?"
					unlink "$OPTPATH/_gm_outfile" > /dev/null 2>&1
					return "$error"
				}
				_test_expr() {
					_test_links <<< "$2
					static int a[($1) ? 1 : -1] = { 42 };
					int main() { return a[0]; }
					"
				}
				while IFS= read -r line; do
					case "$line" in

					*ac_cv_c_stack_direction*)
						# Stack growth direction
						. "$KOS_MISC/utilities/misc/target-info.sh"
						_config_site_option "ac_cv_c_stack_direction" "$TARGET_CONFIG_STACK_DIRECTION"
						;;

					*ac_cv_func_chown_works*)
						# Check if chown() accepts "(uid_t)-1, (gid_t)-1" (which it does on KOS)
						_config_site_option "ac_cv_func_chown_works" "yes"
						;;

					*ac_cv_func_fnmatch_works*)
						# "Define to 1 if your system has a working POSIX `fnmatch' function."
						_config_site_option "ac_cv_func_fnmatch_works" "yes"
						;;

					*ac_cv_func_fnmatch_gnu*)
						# "Define to 1 if your system has a working GNU `fnmatch' function."
						_config_site_option "ac_cv_func_fnmatch_gnu" "yes"
						;;

					*ac_cv_func_getgroups_works*)
						# >> assert(getgroups(0, 0) != -1)
						_config_site_option "ac_cv_func_getgroups_works" "yes"
						;;

					*ac_cv_func_lstat_dereferences_slashed_symlink*)
						# "... whether lstat correctly handles trailing slash"
						_config_site_option "ac_cv_func_lstat_dereferences_slashed_symlink" "yes"
						;;

					*ac_cv_func_malloc_0_nonnull*)
						# >> assert(malloc(0) != NULL)
						_config_site_option "ac_cv_func_malloc_0_nonnull" "yes"
						;;

					*ac_cv_func_memcmp_working*)
						# "... for working memcmp"
						_config_site_option "ac_cv_func_memcmp_working" "yes"
						;;

					*ac_cv_func_working_mktime*)
						# "... for working mktime"
						_config_site_option "ac_cv_func_working_mktime" "yes"
						;;

					*ac_cv_func_mmap_fixed_mapped*)
						# When cross-compiling, `AC_FUNC_MMAP' defaults to `no', even
						# though KOS has a fully working mmap(2) system call that would
						# pass all of autoconf's tests (at least I hope...)
						# Anyways: Just hammer it home to autoconf and manually tell it
						#          what we're capable of via a custom config.site entry.
						_config_site_option "ac_cv_func_mmap_fixed_mapped" "yes"
						;;

					*ac_cv_func_realloc_0_nonnull*)
						# >> assert(realloc(0) != NULL)
						_config_site_option "ac_cv_func_realloc_0_nonnull" "yes"
						;;

					*ac_cv_func_stat_empty_string_bug*)
						# >> assert(stat("", &st) == -1)
						_config_site_option "ac_cv_func_stat_empty_string_bug" "no"
						;;

					*ac_cv_func_lstat_empty_string_bug*)
						# >> assert(lstat("", &st) == -1)
						_config_site_option "ac_cv_func_lstat_empty_string_bug" "no"
						;;

					*ac_cv_func_strtod*)
						# "... for working strtod"
						_config_site_option "ac_cv_func_strtod" "yes"
						;;

					*ac_cv_func_strnlen_working*)
						# "... for working strnlen"
						_config_site_option "ac_cv_func_strnlen_working" "yes"
						;;

					*ac_cv_func_strcoll_works*)
						# "... for working strcoll"
						_config_site_option "ac_cv_func_strcoll_works" "yes"
						;;

					*ac_cv_func_utime_null*)
						# >> assert(IS_WORKING(utime(file, NULL)))
						_config_site_option "ac_cv_func_utime_null" "yes"
						;;

					*ac_cv_func_fork_works*)
						# >> assert(IS_WORKING(fork()))
						_config_site_option "ac_cv_func_fork_works" "yes"
						;;

					*ac_cv_func_vfork_works*)
						# >> assert(IS_WORKING(vfork()))
						_config_site_option "ac_cv_func_vfork_works" "yes"
						;;

					*ac_cv_func_wait3_rusage*)
						# "... for wait3 that fills in rusage"
						_config_site_option "ac_cv_func_wait3_rusage" "yes"
						;;

					*ac_cv_c_bigendian*)
						# "... whether byte ordering is bigendian"
						. "$KOS_MISC/utilities/misc/target-info.sh"
						if [[ "$TARGET_ENDIAN" == "big" ]]; then
							_config_site_option "ac_cv_c_bigendian" "yes"
						else
							_config_site_option "ac_cv_c_bigendian" "no"
						fi
						;;

					*ac_cv_type_getgroups*)
						# "... type of array argument to getgroups"
						_config_site_option "ac_cv_type_getgroups" "gid_t"
						;;

					# Misc stuff from gnulib
					*ac_cv_func__set_invalid_parameter_handler*) # We might emulate it, but not by default; plus: this tends to screw up a bunch of stuff...
						_config_site_option "ac_cv_func__set_invalid_parameter_handler" "no"; ;;

					*gl_cv_func_aligned_alloc_works*) # aligned_alloca()
						_config_site_option "gl_cv_func_aligned_alloc_works" "yes"; ;;
					*gl_cv_func_btowc_nul*) # assert(btowc(0) == 0)
						_config_site_option "gl_cv_func_btowc_nul" "yes"; ;;
					*gl_cv_func_btowc_eof*) # assert(btowc(EOF) == WEOF)
						_config_site_option "gl_cv_func_btowc_eof" "yes"; ;;
					*gl_cv_func_c32rtomb_retval*) # assert(c32rtomb (NULL, 0, NULL) == 1)
						_config_site_option "gl_cv_func_c32rtomb_retval" "yes"; ;;
					*ac_cv_func_calloc_0_nonnull*) # assert(calloc(0, 0) != NULL)
						_config_site_option "ac_cv_func_calloc_0_nonnull" "yes"; ;;
					*gl_cv_func_realpath_works*) # realpath(3)
						_config_site_option "gl_cv_func_realpath_works" "yes"; ;;
					*gl_cv_func_cbrtf_works*)
						_config_site_option "gl_cv_func_cbrtf_works" "yes"; ;;
					*gl_cv_func_cbrtl_ieee*)
						_config_site_option "gl_cv_func_cbrtl_ieee" "yes"; ;;
					*gl_cv_func_cbrtl_works*)
						_config_site_option "gl_cv_func_cbrtl_works" "yes"; ;;
					*gl_cv_func_ceil_ieee*)
						_config_site_option "gl_cv_func_ceil_ieee" "yes"; ;;
					*gl_cv_func_ceilf_ieee*)
						_config_site_option "gl_cv_func_ceilf_ieee" "yes"; ;;
					*gl_cv_func_ceill_ieee*)
						_config_site_option "gl_cv_func_ceill_ieee" "yes"; ;;
					*gl_cv_func_ceill_works*)
						_config_site_option "gl_cv_func_ceill_works" "yes"; ;;
					*gl_cv_func_chown_slash_works*) # symlink(\"file\", \"link\"); assert(chown(\"link/\") != 0)
						_config_site_option "gl_cv_func_chown_slash_works" "yes"; ;;
					*gl_cv_func_chown_ctime_works*) # symlink(3) updates st_ctime (doesn't on KOS, where st_ctime is file-creation time)
						_config_site_option "gl_cv_func_chown_ctime_works" "no"; ;;
					*gl_cv_func_chown_follows_symlink*)
						_config_site_option "gl_cv_func_chown_follows_symlink" "yes"; ;;
					*gl_cv_struct_dirent_d_ino*)
						_config_site_option "gl_cv_struct_dirent_d_ino" "yes"; ;;
					*gl_cv_func_dup_works*)
						_config_site_option "gl_cv_func_dup_works" "yes"; ;;
					*gl_cv_func_dup2_works*)
						_config_site_option "gl_cv_func_dup2_works" "yes"; ;;
					*gl_cv_func_duplocale_works*)
						_config_site_option "gl_cv_func_duplocale_works" "yes"; ;;
					*gl_cv_func_exp2_works*)
						_config_site_option "gl_cv_func_exp2_works" "yes"; ;;
					*gl_cv_func_exp2l_works*)
						_config_site_option "gl_cv_func_exp2l_works" "yes"; ;;
					*gl_cv_func_exp2l_ieee*)
						_config_site_option "gl_cv_func_exp2l_ieee" "yes"; ;;
					*gl_cv_func_expl_works*)
						_config_site_option "gl_cv_func_expl_works" "yes"; ;;
					*gl_cv_func_expm1_ieee*)
						_config_site_option "gl_cv_func_expm1_ieee" "yes"; ;;
					*gl_cv_func_expm1f_ieee*)
						_config_site_option "gl_cv_func_expm1f_ieee" "yes"; ;;
					*gl_cv_func_expm1f_works*)
						_config_site_option "gl_cv_func_expm1f_works" "yes"; ;;
					*gl_cv_func_expm1l_works*)
						_config_site_option "gl_cv_func_expm1l_works" "yes"; ;;
					*gl_cv_func_fabsl_works*)
						_config_site_option "gl_cv_func_fabsl_works" "yes"; ;;
					*gl_cv_func_open_directory_works*) # assert(open(\".\", O_RDONLY) != -1)
						_config_site_option "gl_cv_func_open_directory_works" "yes"; ;;
					*gl_cv_func_fchmodat_works*)
						_config_site_option "gl_cv_func_fchmodat_works" "yes"; ;;
					*gl_cv_func_fchownat_nofollow_works*) # AT_SYMLINK_NOFOLLOW
						_config_site_option "gl_cv_func_fchownat_nofollow_works" "yes"; ;;
					*gl_cv_func_fchownat_empty_filename_works*) # assert(fchownat(fd, \"\", ...) != 0)
						_config_site_option "gl_cv_func_fchownat_empty_filename_works" "yes"; ;;
					*gl_cv_func_fclose_stdin*)
						_config_site_option "gl_cv_func_fclose_stdin" "yes"; ;;
					*gl_cv_func_fcntl_f_dupfd_works*)
						_config_site_option "gl_cv_func_fcntl_f_dupfd_works" "yes"; ;;
					*gl_cv_func_fcntl_f_dupfd_cloexec*)
						_config_site_option "gl_cv_func_fcntl_f_dupfd_cloexec" "yes"; ;;
					*gl_cv_header_working_fcntl_h*)
						_config_site_option "gl_cv_header_working_fcntl_h" "yes"; ;;
					*gl_cv_func_fdopen_works*)
						_config_site_option "gl_cv_func_fdopen_works" "yes"; ;;
					*gl_cv_func_fdopendir_works*)
						_config_site_option "gl_cv_func_fdopendir_works" "yes"; ;;
					*gl_cv_func_fflush_stdin*)
						_config_site_option "gl_cv_func_fflush_stdin" "yes"; ;;
					*gl_cv_func_ffsll_works*)
						_config_site_option "gl_cv_func_ffsll_works" "yes"; ;;
					*gl_cv_func_floor_ieee*)
						_config_site_option "gl_cv_func_floor_ieee" "yes"; ;;
					*gl_cv_func_floorf_ieee*)
						_config_site_option "gl_cv_func_floorf_ieee" "yes"; ;;
					*gl_cv_func_fma_works*)
						_config_site_option "gl_cv_func_fma_works" "yes"; ;;
					*gl_cv_func_fmaf_works*)
						_config_site_option "gl_cv_func_fmaf_works" "yes"; ;;
					*gl_cv_func_fmal_works*)
						_config_site_option "gl_cv_func_fmal_works" "yes"; ;;
					*gl_cv_func_fmod_ieee*)
						_config_site_option "gl_cv_func_fmod_ieee" "yes"; ;;
					*gl_cv_func_fmodf_ieee*)
						_config_site_option "gl_cv_func_fmodf_ieee" "yes"; ;;
					*gl_cv_func_fmodl_ieee*)
						_config_site_option "gl_cv_func_fmodl_ieee" "yes"; ;;
					*gl_cv_func_fnmatch_* | *gl_fnmatch_required_lowercase* | *gl_fnmatch_cache_var*)
						_config_site_option "gl_cv_func_fnmatch_posix" "yes"
						_config_site_option "gl_cv_func_fnmatch_gnu" "yes"    # GNU extensions (s.a. __USE_GNU in <fnmatch.h>)
						;;
					*gl_cv_func_fopen_slash*) # assert(fopen(\"foo/\") == NULL)
						_config_site_option "gl_cv_func_fopen_slash" "yes"; ;;
					*gl_cv_func_fopen_mode_x*) # Support for \"x\" option
						_config_site_option "gl_cv_func_fopen_mode_x" "yes"; ;;
					*gl_cv_func_fopen_mode_e*) # Support for \"e\" option
						_config_site_option "gl_cv_func_fopen_mode_e" "yes"; ;;
					*gl_cv_func_fpurge_works*)
						_config_site_option "gl_cv_func_fpurge_works" "yes"; ;;
					*gl_cv_func_freopen_works_on_closed*) # freopen() works after close(fileno())
						_config_site_option "gl_cv_func_freopen_works_on_closed" "yes"; ;;
					*gl_cv_func_frexp_works*)
						_config_site_option "gl_cv_func_frexp_works" "yes"; ;;
					*gl_cv_func_frexpf_works*)
						_config_site_option "gl_cv_func_frexpf_works" "yes"; ;;
					*gl_cv_func_frexpl_works*)
						_config_site_option "gl_cv_func_frexpl_works" "yes"; ;;
					*gl_cv_func_fstatat_zero_flag*) # assert(fstatat(AT_FDCWD, \".\", atflags: 0) == 0)
						_config_site_option "gl_cv_func_fstatat_zero_flag" "yes"; ;;
					*fu_cv_sys_stat_statfs2_frsize*) # DECLARED(statfs(char const *file, struct statfs *buf)) && EXISTS(struct statfs::f_frsize)
						_config_site_option "fu_cv_sys_stat_statfs2_frsize" "yes"; ;;
					*fu_cv_sys_stat_statfs3_osf1*) # Some other statfs() variant
						_config_site_option "fu_cv_sys_stat_statfs3_osf1" "no"; ;;
					*fu_cv_sys_stat_statfs2_bsize*) # DECLARED(statfs(char const *file, struct statfs *buf)) && EXISTS(struct statfs::f_bsize)
						_config_site_option "fu_cv_sys_stat_statfs2_bsize" "yes"; ;;
					*fu_cv_sys_stat_statfs4*) # Some other statfs() variant
						_config_site_option "fu_cv_sys_stat_statfs4" "no"; ;;
					*fu_cv_sys_stat_statfs2_fsize*) # DECLARED(statfs(char const *file, struct statfs *buf)) && EXISTS(struct statfs::f_fsize)
						_config_site_option "fu_cv_sys_stat_statfs2_fsize" "no"; ;;
					*gl_cv_func_ftello_works*)
						_config_site_option "gl_cv_func_ftello_works" "yes"; ;;
					*gl_cv_func_futimens_works*)
						_config_site_option "gl_cv_func_futimens_works" "yes"; ;;
					*gl_cv_func_getcwd_null*) # assert(getcwd(NULL, 0) != NULL)   -- malloc'd buffer
						_config_site_option "gl_cv_func_getcwd_null" "yes"; ;;
					*gl_cv_func_getcwd_succeeds_beyond_4k*) # getcwd() with strlen(\$PWD) >= 4096 works  (KOS never imposes path limits, so: yes)
						_config_site_option "gl_cv_func_getcwd_succeeds_beyond_4k" "yes"; ;;
					*gl_cv_func_getcwd_path_max*) # getcwd() works for paths > PATH_MAX        (KOS never imposes path limits, so: yes)
						_config_site_option "gl_cv_func_getcwd_path_max" "yes"; ;;
					*gl_cv_func_working_getdelim*)
						_config_site_option "gl_cv_func_working_getdelim" "yes"; ;;
					*gl_cv_func_getdtablesize_works*)
						_config_site_option "gl_cv_func_getdtablesize_works" "yes"; ;;
					*gl_cv_func_getgroups_works*) # assert(getgroups(-1, list) == -1)
						_config_site_option "gl_cv_func_getgroups_works" "yes"; ;;
					*am_cv_func_working_getline*)
						_config_site_option "am_cv_func_working_getline" "yes"; ;;
					*gl_cv_func_getlogin_r_works*)
						_config_site_option "gl_cv_func_getlogin_r_works" "yes"; ;;
					*gl_cv_func_getopt_posix*)
						_config_site_option "gl_cv_func_getopt_posix" "yes"; ;;
					*gl_cv_func_getopt_gnu*)
						_config_site_option "gl_cv_func_getopt_gnu" "yes"; ;;
					*gl_cv_func_getopt_long_gnu*)
						_config_site_option "gl_cv_func_getopt_long_gnu" "yes"; ;;
					*gl_cv_glob_lists_symlinks*) # If a program ever needs it, _I_ want to implement it!
						_config_site_option "gl_cv_glob_lists_symlinks" "yes"; ;;
					*gl_cv_func_hypot_ieee*)
						_config_site_option "gl_cv_func_hypot_ieee" "yes"; ;;
					*gl_cv_func_hypotf_ieee*)
						_config_site_option "gl_cv_func_hypotf_ieee" "yes"; ;;
					*gl_cv_func_hypotf_works*)
						_config_site_option "gl_cv_func_hypotf_works" "yes"; ;;
					*gl_cv_func_hypotl_ieee*)
						_config_site_option "gl_cv_func_hypotl_ieee" "yes"; ;;
					*gl_cv_func_hypotl_works*)
						_config_site_option "gl_cv_func_hypotl_works" "yes"; ;;
					*am_cv_func_iconv_works*)
						_config_site_option "am_cv_func_iconv_works" "yes"; ;;
					*gl_cv_func_iconv_supports_utf*)
						_config_site_option "gl_cv_func_iconv_supports_utf" "yes"; ;;
					*gl_cv_func_ilogb_works*)
						_config_site_option "gl_cv_func_ilogb_works" "yes"; ;;
					*gl_cv_func_ilogbf_works*)
						_config_site_option "gl_cv_func_ilogbf_works" "yes"; ;;
					*gl_cv_func_ilogbl_works*)
						_config_site_option "gl_cv_func_ilogbl_works" "yes"; ;;
					*gl_cv_func_itold_works*)
						_config_site_option "gl_cv_func_itold_works" "yes"; ;;
					*gt_cv_locale_fake*)
						_config_site_option "gt_cv_locale_fake" "no"; ;;
					*gt_cv_func_uselocale_works*)
						_config_site_option "gt_cv_func_uselocale_works" "yes"; ;;
					*gl_cv_pipes_are_fifos*) # fstate(pipe()) --> S_IFIFO
						_config_site_option "gl_cv_pipes_are_fifos" "yes"; ;;
					*gl_cv_func_isfinitel_works*)
						_config_site_option "gl_cv_func_isfinitel_works" "yes"; ;;
					*gl_cv_func_isinfl_works*)
						_config_site_option "gl_cv_func_isinfl_works" "yes"; ;;
					*gl_cv_func_isnanf_works*)
						_config_site_option "gl_cv_func_isnanf_works" "yes"; ;;
					*gl_cv_func_isnanl_works*)
						_config_site_option "gl_cv_func_isnanl_works" "yes"; ;;
					*gl_cv_func_iswdigit_works*)
						_config_site_option "gl_cv_func_iswdigit_works" "yes"; ;;
					*gl_cv_func_iswxdigit_works*)
						_config_site_option "gl_cv_func_iswxdigit_works" "yes"; ;;
					*gl_cv_func_ldexpl_works*)
						_config_site_option "gl_cv_func_ldexpl_works" "yes"; ;;
					*gl_cv_func_link_works*)
						_config_site_option "gl_cv_func_link_works" "yes"; ;;
					*gl_cv_func_linkat_nofollow*)
						_config_site_option "gl_cv_func_linkat_nofollow" "yes"; ;;
					*gl_cv_func_linkat_slash*)
						_config_site_option "gl_cv_func_linkat_slash" "yes"; ;;
					*gl_cv_func_link_follows_symlink*) # link(symlink) creates hard-links of symlinks; use AT_SYMLINK_FOLLOW to follow them
						_config_site_option "gl_cv_func_link_follows_symlink" "no"; ;;
					*gl_cv_func_log_ieee*)
						_config_site_option "gl_cv_func_log_ieee" "yes"; ;;
					*gl_cv_func_log_works*)
						_config_site_option "gl_cv_func_log_works" "yes"; ;;
					*gl_cv_func_log1p_ieee*)
						_config_site_option "gl_cv_func_log1p_ieee" "yes"; ;;
					*gl_cv_func_log1pf_ieee*)
						_config_site_option "gl_cv_func_log1pf_ieee" "yes"; ;;
					*gl_cv_func_log1pf_works*)
						_config_site_option "gl_cv_func_log1pf_works" "yes"; ;;
					*gl_cv_func_log1pl_ieee*)
						_config_site_option "gl_cv_func_log1pl_ieee" "yes"; ;;
					*gl_cv_func_log1pl_works*)
						_config_site_option "gl_cv_func_log1pl_works" "yes"; ;;
					*gl_cv_func_log2_ieee*)
						_config_site_option "gl_cv_func_log2_ieee" "yes"; ;;
					*gl_cv_func_log2_works*)
						_config_site_option "gl_cv_func_log2_works" "yes"; ;;
					*gl_cv_func_log2f_ieee*)
						_config_site_option "gl_cv_func_log2f_ieee" "yes"; ;;
					*gl_cv_func_log2f_works*)
						_config_site_option "gl_cv_func_log2f_works" "yes"; ;;
					*gl_cv_func_log2l_works*)
						_config_site_option "gl_cv_func_log2l_works" "yes"; ;;
					*gl_cv_func_log10_ieee*)
						_config_site_option "gl_cv_func_log10_ieee" "yes"; ;;
					*gl_cv_func_log10_works*)
						_config_site_option "gl_cv_func_log10_works" "yes"; ;;
					*gl_cv_func_log10f_ieee*)
						_config_site_option "gl_cv_func_log10f_ieee" "yes"; ;;
					*gl_cv_func_log10f_works*)
						_config_site_option "gl_cv_func_log10f_works" "yes"; ;;
					*gl_cv_func_log10l_works*)
						_config_site_option "gl_cv_func_log10l_works" "yes"; ;;
					*gl_cv_func_logb_works*)
						_config_site_option "gl_cv_func_logb_works" "yes"; ;;
					*gl_cv_func_logbf_works*)
						_config_site_option "gl_cv_func_logbf_works" "yes"; ;;
					*gl_cv_func_logbl_works*)
						_config_site_option "gl_cv_func_logbl_works" "yes"; ;;
					*gl_cv_func_logf_ieee*)
						_config_site_option "gl_cv_func_logf_ieee" "yes"; ;;
					*gl_cv_func_logf_works*)
						_config_site_option "gl_cv_func_logf_works" "yes"; ;;
					*gl_cv_func_logl_works*)
						_config_site_option "gl_cv_func_logl_works" "yes"; ;;
					*ac_cv_type_long_long_int*) # At least with gcc
						_config_site_option "ac_cv_type_long_long_int" "yes"; ;;
					*gl_cv_func_lstat_dereferences_slashed_symlink*) # lstat(\"symlink/\") still dereferences (yes, it does on KOS)
						_config_site_option "gl_cv_func_lstat_dereferences_slashed_symlink" "yes"; ;;
					*gl_cv_malloc_alignment*)
						. "$KOS_MISC/utilities/misc/target-info.sh"
						_config_site_option "gl_cv_malloc_alignment" "$TARGET_CONFIG_ALIGNOF_MAXALIGN_T"; ;;
					*gl_cv_func_mbrlen_incomplete_state*)
						_config_site_option "gl_cv_func_mbrlen_incomplete_state" "yes"; ;;
					*gl_cv_func_mbrlen_retval*)
						_config_site_option "gl_cv_func_mbrlen_retval" "yes"; ;;
					*gl_cv_func_mbrlen_nul_retval*)
						_config_site_option "gl_cv_func_mbrlen_nul_retval" "yes"; ;;
					*gl_cv_func_mbrlen_empty_input*)
						_config_site_option "gl_cv_func_mbrlen_empty_input" "yes"; ;;
					*gl_cv_func_mbrtoc32_empty_input*)
						_config_site_option "gl_cv_func_mbrtoc32_empty_input" "yes"; ;;
					*gl_cv_func_mbrtoc32_sanitycheck*)
						_config_site_option "gl_cv_func_mbrtoc32_sanitycheck" "yes"; ;;
					*gl_cv_func_mbrtowc_incomplete_state*)
						_config_site_option "gl_cv_func_mbrtowc_incomplete_state" "yes"; ;;
					*gl_cv_func_mbrtowc_sanitycheck*)
						_config_site_option "gl_cv_func_mbrtowc_sanitycheck" "yes"; ;;
					*gl_cv_func_mbrtowc_null_arg1*)
						_config_site_option "gl_cv_func_mbrtowc_null_arg1" "yes"; ;;
					*gl_cv_func_mbrtowc_null_arg2*)
						_config_site_option "gl_cv_func_mbrtowc_null_arg2" "yes"; ;;
					*gl_cv_func_mbrtowc_retval*)
						_config_site_option "gl_cv_func_mbrtowc_retval" "yes"; ;;
					*gl_cv_func_mbrtowc_nul_retval*)
						_config_site_option "gl_cv_func_mbrtowc_nul_retval" "yes"; ;;
					*gl_cv_func_mbrtowc_stores_incomplete*)
						_config_site_option "gl_cv_func_mbrtowc_stores_incomplete" "yes"; ;;
					*gl_cv_func_mbrtowc_empty_input*)
						_config_site_option "gl_cv_func_mbrtowc_empty_input" "yes"; ;;
					*gl_cv_func_mbsnrtowcs_works_in_traditional_locale*)
						_config_site_option "gl_cv_func_mbsnrtowcs_works_in_traditional_locale" "yes"; ;;
					*gl_cv_func_mbsrtowcs_works*)
						_config_site_option "gl_cv_func_mbsrtowcs_works" "yes"; ;;
					*gl_cv_func_memalign_works*)
						_config_site_option "gl_cv_func_memalign_works" "yes"; ;;
					*gl_cv_func_memchr_works*)
						_config_site_option "gl_cv_func_memchr_works" "yes"; ;;
					*gl_cv_func_memcmp_working*)
						_config_site_option "gl_cv_func_memcmp_working" "yes"; ;;
					*gl_cv_func_memmem_works_always*) # We actually have 2 memmem() versions (s.a. _MEMMEM_EMPTY_NEEDLE_NULL_SOURCE; but the regular one is standard-conforming)
						_config_site_option "gl_cv_func_memmem_works_always" "yes"; ;;
					*gl_cv_func_memmem_works_fast*) # Yes: our memmem() does a memchr(needle[0]) to filter candidates, so its the \"fast\" variant
						_config_site_option "gl_cv_func_memmem_works_fast" "yes"; ;;
					*gl_cv_func_mkdir_trailing_slash_works*) # assert(mkdir(\"foo/\") == 0)
						_config_site_option "gl_cv_func_mkdir_trailing_slash_works" "yes"; ;;
					*gl_cv_func_mkdir_trailing_dot_works*) # assert(mkdir(\"foo/./\") != 0)
						_config_site_option "gl_cv_func_mkdir_trailing_dot_works" "yes"; ;;
					*gl_cv_func_mkfifo_works*) # assert(mkfifo(\"foo/\") != 0)
						_config_site_option "gl_cv_func_mkfifo_works" "yes"; ;;
					*gl_cv_func_mkfifoat_works*) # assert(mkfifoat(\"foo/\") != 0)
						_config_site_option "gl_cv_func_mkfifoat_works" "yes"; ;;
					*gl_cv_func_mknod_works*) # mknod() can create FIFO w/o root (yes; that works on KOS)
						_config_site_option "gl_cv_func_mknod_works" "yes"; ;;
					*gl_cv_func_working_mkstemp*)
						_config_site_option "gl_cv_func_working_mkstemp" "yes"; ;;
					*gl_cv_func_working_mktime*)
						_config_site_option "gl_cv_func_working_mktime" "yes"; ;;
					*gl_cv_func_modf_ieee*)
						_config_site_option "gl_cv_func_modf_ieee" "yes"; ;;
					*gl_cv_func_modff_ieee*)
						_config_site_option "gl_cv_func_modff_ieee" "yes"; ;;
					*gl_cv_func_modfl_ieee*)
						_config_site_option "gl_cv_func_modfl_ieee" "yes"; ;;
					*gl_cv_func_mprotect_works*)
						_config_site_option "gl_cv_func_mprotect_works" "yes"; ;;
					*gl_cv_func_nanosleep*)
						_config_site_option "gl_cv_func_nanosleep" "yes"; ;;
					*gl_cv_func_nl_langinfo_yesexpr_works*) # assert(strcmp(nl_langinfo(YESEXPR), \"\") != 0)
						_config_site_option "gl_cv_func_nl_langinfo_yesexpr_works" "yes"; ;;
					*gl_cv_func_open_slash*) # assert(open(\"file/\") == -1)
						_config_site_option "gl_cv_func_open_slash" "yes"; ;;
					*gl_cv_func_perror_works*)
						_config_site_option "gl_cv_func_perror_works" "yes"; ;;
					*ac_cv_func_poll*)
						_config_site_option "ac_cv_func_poll" "yes"; ;;
					*gl_cv_func_poll*)
						_config_site_option "gl_cv_func_poll" "yes"; ;;
					*gl_cv_func_popen_works*)
						_config_site_option "gl_cv_func_popen_works" "yes"; ;;
					*gl_cv_func_posix_memalign_works*)
						_config_site_option "gl_cv_func_posix_memalign_works" "yes"; ;;
					*gl_cv_func_posix_spawn_works*)
						_config_site_option "gl_cv_func_posix_spawn_works" "yes"; ;;
					*gl_cv_func_posix_spawn_secure_exec*) # Yes, our posix_spawn() doesn't accept shell-scripts w/o #!-marker
						_config_site_option "gl_cv_func_posix_spawn_secure_exec" "yes"; ;;
					*gl_cv_func_posix_spawnp_secure_exec*) # *ditto*
						_config_site_option "gl_cv_func_posix_spawnp_secure_exec" "yes"; ;;
					*gl_cv_func_posix_spawn_file_actions_addclose_works*)
						_config_site_option "gl_cv_func_posix_spawn_file_actions_addclose_works" "yes"; ;;
					*gl_cv_func_posix_spawn_file_actions_adddup2_works*)
						_config_site_option "gl_cv_func_posix_spawn_file_actions_adddup2_works" "yes"; ;;
					*gl_cv_func_posix_spawn_file_actions_addopen_works*)
						_config_site_option "gl_cv_func_posix_spawn_file_actions_addopen_works" "yes"; ;;
					*gl_cv_func_pread_works*)
						_config_site_option "gl_cv_func_pread_works" "yes"; ;;
					*gl_cv_func_printf_sizes_c99*)
						_config_site_option "gl_cv_func_printf_sizes_c99" "yes"; ;;
					*gl_cv_func_printf_long_double*)
						_config_site_option "gl_cv_func_printf_long_double" "yes"; ;;
					*gl_cv_func_printf_infinite*)
						_config_site_option "gl_cv_func_printf_infinite" "yes"; ;;
					*gl_cv_func_printf_infinite_long_double*)
						_config_site_option "gl_cv_func_printf_infinite_long_double" "yes"; ;;
					*gl_cv_func_printf_directive_a*)
						_config_site_option "gl_cv_func_printf_directive_a" "yes"; ;;
					*gl_cv_func_printf_directive_f*)
						_config_site_option "gl_cv_func_printf_directive_f" "yes"; ;;
					*gl_cv_func_printf_directive_n*)
						_config_site_option "gl_cv_func_printf_directive_n" "yes"; ;;
					*gl_cv_func_printf_directive_ls*)
						_config_site_option "gl_cv_func_printf_directive_ls" "yes"; ;;
					*gl_cv_func_printf_positions*) # Probably someday... (but already say we do)
						_config_site_option "gl_cv_func_printf_positions" "yes"; ;;
					*gl_cv_func_printf_flag_grouping*)
						_config_site_option "gl_cv_func_printf_flag_grouping" "yes"; ;;
					*gl_cv_func_printf_flag_leftadjust*)
						_config_site_option "gl_cv_func_printf_flag_leftadjust" "yes"; ;;
					*gl_cv_func_printf_flag_zero*)
						_config_site_option "gl_cv_func_printf_flag_zero" "yes"; ;;
					*gl_cv_func_printf_precision*)
						_config_site_option "gl_cv_func_printf_precision" "yes"; ;;
					*gl_cv_func_snprintf_truncation_c99*) # Yes, we do this now. But once-upon-a-time, this was a bug (s.a. snprintf(3))
						_config_site_option "gl_cv_func_snprintf_truncation_c99" "yes"; ;;
					*gl_cv_func_snprintf_retval_c99*)
						_config_site_option "gl_cv_func_snprintf_retval_c99" "yes"; ;;
					*gl_cv_func_snprintf_directive_n*)
						_config_site_option "gl_cv_func_snprintf_directive_n" "yes"; ;;
					*gl_cv_func_snprintf_size1*)
						_config_site_option "gl_cv_func_snprintf_size1" "yes"; ;;
					*gl_cv_func_vsnprintf_zerosize_c99*)
						_config_site_option "gl_cv_func_vsnprintf_zerosize_c99" "yes"; ;;
					*gl_cv_func_pselect_detects_ebadf*)
						_config_site_option "gl_cv_func_pselect_detects_ebadf" "yes"; ;;
					*gl_cv_pthread_rwlock_rdlock_prefer_writer*) # No, on KOS readers are preferred
						_config_site_option "gl_cv_pthread_rwlock_rdlock_prefer_writer" "no"; ;;
					*gl_cv_func_pthread_sigmask_in_libc_works*) # Yes, we have pthread_sigmask() w/o -lpthread (actually, we don't have -lpthread)
						_config_site_option "gl_cv_func_pthread_sigmask_in_libc_works" "yes"; ;;
					*gl_cv_func_pthread_sigmask_return_works*)
						_config_site_option "gl_cv_func_pthread_sigmask_return_works" "yes"; ;;
					*gl_cv_func_pthread_sigmask_unblock_works*)
						_config_site_option "gl_cv_func_pthread_sigmask_unblock_works" "yes"; ;;
					*gl_cv_func_ptsname_sets_errno*)
						_config_site_option "gl_cv_func_ptsname_sets_errno" "yes"; ;;
					*gl_cv_func_ptsname_r_retval_ok*)
						_config_site_option "gl_cv_func_ptsname_r_retval_ok" "yes"; ;;
					*gl_cv_func_isatty_sets_errno*)
						_config_site_option "gl_cv_func_isatty_sets_errno" "yes"; ;;
					*gl_cv_func_svid_putenv*)
						_config_site_option "gl_cv_func_svid_putenv" "yes"; ;;
					*gl_cv_func_pwrite_works*)
						_config_site_option "gl_cv_func_pwrite_works" "yes"; ;;
					*gl_cv_func_readlink_trailing_slash*) # assert(readlink(\"file/\") == -1)
						_config_site_option "gl_cv_func_readlink_trailing_slash" "yes"; ;;
					*gl_cv_func_readlink_truncate*) # Oof; don't remind me (s.a. AT_READLINK_REQSIZE)
						_config_site_option "gl_cv_func_readlink_truncate" "yes"; ;;
					*ac_cv_func_realloc_0_nonnull*) # assert(realloc(NULL, 0) != NULL)
						_config_site_option "ac_cv_func_realloc_0_nonnull" "yes"; ;;
					*gl_cv_func_re_compile_pattern_working*) # Not yet, but hopefully someday
						_config_site_option "gl_cv_func_re_compile_pattern_working" "yes"; ;;
					*gl_cv_func_remainder_ieee*)
						_config_site_option "gl_cv_func_remainder_ieee" "yes"; ;;
					*gl_cv_func_remainderf_ieee*)
						_config_site_option "gl_cv_func_remainderf_ieee" "yes"; ;;
					*gl_cv_func_remainderf_works*)
						_config_site_option "gl_cv_func_remainderf_works" "yes"; ;;
					*gl_cv_func_remainderl_ieee*)
						_config_site_option "gl_cv_func_remainderl_ieee" "yes"; ;;
					*gl_cv_func_remainderl_works*)
						_config_site_option "gl_cv_func_remainderl_works" "yes"; ;;
					*gl_cv_func_remove_dir_works*) # Yes, remove() also removes directories (s.a. AT_REMOVEREG | AT_REMOVEDIR)
						_config_site_option "gl_cv_func_remove_dir_works" "yes"; ;;
					*gl_cv_func_rename_slash_dst_works*) # FIXME: yeah, this one's not 100% (s.a. sys_renameat2_impl)
						_config_site_option "gl_cv_func_rename_slash_dst_works" "yes"; ;;
					*gl_cv_func_rename_slash_src_works*) # FIXME: *ditto*
						_config_site_option "gl_cv_func_rename_slash_src_works" "yes"; ;;
					*gl_cv_func_rename_link_works*)
						_config_site_option "gl_cv_func_rename_link_works" "yes"; ;;
					*gl_cv_func_rename_dest_works*)
						_config_site_option "gl_cv_func_rename_dest_works" "yes"; ;;
					*gl_cv_func_rintl_works*)
						_config_site_option "gl_cv_func_rintl_works" "yes"; ;;
					*gl_cv_func_rmdir_works*)
						_config_site_option "gl_cv_func_rmdir_works" "yes"; ;;
					*gl_cv_func_rmdir_errno_not_empty*)
						_config_site_option "gl_cv_func_rmdir_errno_not_empty" "ENOTEMPTY"; ;;
					*gl_cv_func_round_works*)
						_config_site_option "gl_cv_func_round_works" "yes"; ;;
					*gl_cv_func_round_ieee*)
						_config_site_option "gl_cv_func_round_ieee" "yes"; ;;
					*gl_cv_func_roundf_works*)
						_config_site_option "gl_cv_func_roundf_works" "yes"; ;;
					*gl_cv_func_roundf_ieee*)
						_config_site_option "gl_cv_func_roundf_ieee" "yes"; ;;
					*gl_cv_func_roundl_ieee*)
						_config_site_option "gl_cv_func_roundl_ieee" "yes"; ;;
					*gl_cv_func_select_supports0*) # select(0, NULL, NULL, NULL, ...) works
						_config_site_option "gl_cv_func_select_supports0" "yes"; ;;
					*gl_cv_func_select_detects_ebadf*)
						_config_site_option "gl_cv_func_select_detects_ebadf" "yes"; ;;
					*gl_cv_func_setenv_works*)
						_config_site_option "gl_cv_func_setenv_works" "yes"; ;;
					*gl_cv_func_unsetenv_works*)
						_config_site_option "gl_cv_func_unsetenv_works" "yes"; ;;
					*gl_cv_func_setlocale_works*)
						_config_site_option "gl_cv_func_setlocale_works" "yes"; ;;
					*sv_cv_sigaltstack*)
						_config_site_option "sv_cv_sigaltstack" "yes"; ;;
					*sv_cv_sigaltstack_low_base*)
						_config_site_option "sv_cv_sigaltstack_low_base" "yes"; ;;
					*gl_cv_func_signbit*)
						_config_site_option "gl_cv_func_signbit" "yes"; ;;
					*gl_cv_func_signbit_builtins*) # At least on gcc
						_config_site_option "gl_cv_func_signbit_builtins" "yes"; ;;
					*gl_cv_func_signbit_gcc*) # Alias used by older gnulibs
						_config_site_option "gl_cv_func_signbit_gcc" "yes"; ;;
					*gl_cv_func_sleep_works*)
						_config_site_option "gl_cv_func_sleep_works" "yes"; ;;
					*gl_cv_func_sqrtl_works*)
						_config_site_option "gl_cv_func_sqrtl_works" "yes"; ;;
					*gl_cv_func_stat_file_slash*) # assert(stat(\"file/\") == -1)
						_config_site_option "gl_cv_func_stat_file_slash" "yes"; ;;
					*gl_cv_header_working_stdint_h*)
						_config_site_option "gl_cv_header_working_stdint_h" "yes"; ;;
					*gl_cv_func_stpncpy*)
						_config_site_option "gl_cv_func_stpncpy" "yes"; ;;
					*gl_cv_func_strcasestr_works_always*)
						_config_site_option "gl_cv_func_strcasestr_works_always" "yes"; ;;
					*gl_cv_func_strcasestr_linear*)
						_config_site_option "gl_cv_func_strcasestr_linear" "yes"; ;;
					*gl_cv_func_strchrnul_works*)
						_config_site_option "gl_cv_func_strchrnul_works" "yes"; ;;
					*gl_cv_func_working_strerror*)
						_config_site_option "gl_cv_func_working_strerror" "yes"; ;;
					*gl_cv_func_strerror_0_works*)
						_config_site_option "gl_cv_func_strerror_0_works" "yes"; ;;
					*gl_cv_func_strerror_r_works*)
						_config_site_option "gl_cv_func_strerror_r_works" "yes"; ;;
					*gl_cv_func_strerrorname_np_works*)
						_config_site_option "gl_cv_func_strerrorname_np_works" "yes"; ;;
					*gl_cv_strfmon_l_works*) # It doesn't, but I don't want it to be substituted; if it ends up needed, _I'll_ implement it
						_config_site_option "gl_cv_strfmon_l_works" "yes"; ;;
					*gl_cv_func_strncat_works*)
						_config_site_option "gl_cv_func_strncat_works" "yes"; ;;
					*gl_cv_func_strndup_works*)
						_config_site_option "gl_cv_func_strndup_works" "yes"; ;;
					*gl_cv_func_working_strsignal*)
						_config_site_option "gl_cv_func_working_strsignal" "yes"; ;;
					*gl_cv_func_strstr_works_always*)
						_config_site_option "gl_cv_func_strstr_works_always" "yes"; ;;
					*gl_cv_func_strstr_linear*)
						_config_site_option "gl_cv_func_strstr_linear" "yes"; ;;
					*gl_cv_func_strtod_works*)
						_config_site_option "gl_cv_func_strtod_works" "yes"; ;;
					*gl_cv_func_strtoimax*)
						_config_site_option "gl_cv_func_strtoimax" "yes"; ;;
					*gl_cv_func_strtok_r_works*)
						_config_site_option "gl_cv_func_strtok_r_works" "yes"; ;;
					*gl_cv_func_strtol_works*)
						_config_site_option "gl_cv_func_strtol_works" "yes"; ;;
					*gl_cv_func_strtold_works*)
						_config_site_option "gl_cv_func_strtold_works" "yes"; ;;
					*gl_cv_func_strtoll_works*)
						_config_site_option "gl_cv_func_strtoll_works" "yes"; ;;
					*gl_cv_func_strtoul_works*)
						_config_site_option "gl_cv_func_strtoul_works" "yes"; ;;
					*gl_cv_func_strtoull_works*)
						_config_site_option "gl_cv_func_strtoull_works" "yes"; ;;
					*gl_cv_func_symlink_works*) # assert(symlink(\"content\", \"file/\") == -1)
						_config_site_option "gl_cv_func_symlink_works" "yes"; ;;
					*gl_cv_func_symlinkat_works*) # assert(symlinkat(\"content\", \"file/\") == -1)
						_config_site_option "gl_cv_func_symlinkat_works" "yes"; ;;
					*gl_cv_func_thrd_join_works*)
						_config_site_option "gl_cv_func_thrd_join_works" "yes"; ;;
					*gl_cv_have_weak*) # KOS uses ELF, so yes
						_config_site_option "gl_cv_have_weak" "yes"; ;;
					*gl_cv_func_localtime_works*)
						_config_site_option "gl_cv_func_localtime_works" "yes"; ;;
					*gl_cv_func_tmpfile_works*)
						_config_site_option "gl_cv_func_tmpfile_works" "yes"; ;;
					*gl_cv_func_trunc_ieee*)
						_config_site_option "gl_cv_func_trunc_ieee" "yes"; ;;
					*gl_cv_func_truncate_works*) # assert(truncate(\"file/\") == -1)
						_config_site_option "gl_cv_func_truncate_works" "yes"; ;;
					*gl_cv_func_truncf_ieee*)
						_config_site_option "gl_cv_func_truncf_ieee" "yes"; ;;
					*gl_cv_func_truncl_works*)
						_config_site_option "gl_cv_func_truncl_works" "yes"; ;;
					*gl_cv_func_truncl_ieee*)
						_config_site_option "gl_cv_func_truncl_ieee" "yes"; ;;
					*gl_cv_func_tdelete_works*)
						_config_site_option "gl_cv_func_tdelete_works" "yes"; ;;
					*gl_cv_func_ttyname_r_not_stub*)
						_config_site_option "gl_cv_func_ttyname_r_not_stub" "yes"; ;;
					*gl_cv_func_ttyname_r_works*)
						_config_site_option "gl_cv_func_ttyname_r_works" "yes"; ;;
					*gl_cv_func_ungetc_works*)
						_config_site_option "gl_cv_func_ungetc_works" "yes"; ;;
					*gl_cv_func_unlink_honors_slashes*) # assert(unlink(\"file/\") == -1)
						_config_site_option "gl_cv_func_unlink_honors_slashes" "yes"; ;;
					*gl_cv_func_unlink_parent_fails*) # assert(unlink(\"..\") == -1)
						_config_site_option "gl_cv_func_unlink_parent_fails" "yes"; ;;
					*gl_cv_func_unlink_busy_text*) # assert(unlink(readlink(\"/proc/self/exe\")) == 0)   (yes: this works on KOS)
						_config_site_option "gl_cv_func_unlink_busy_text" "yes"; ;;
					*gl_cv_func_usleep_works*)
						_config_site_option "gl_cv_func_usleep_works" "yes"; ;;
					*gl_cv_func_utime_file_slash*) # assert(utime(\"file/\") == -1)
						_config_site_option "gl_cv_func_utime_file_slash" "yes"; ;;
					*gl_cv_func_futimesat_works*) # assert(futimesat(fd, NULL, NULL) == 0)
						_config_site_option "gl_cv_func_futimesat_works" "yes"; ;;
					*gl_cv_func_utimensat_works*)
						_config_site_option "gl_cv_func_utimensat_works" "yes"; ;;
					*gl_cv_func_working_utimes*)
						_config_site_option "gl_cv_func_working_utimes" "yes"; ;;
					*gl_cv_func_wcrtomb_works*)
						_config_site_option "gl_cv_func_wcrtomb_works" "yes"; ;;
					*gl_cv_func_wcrtomb_retval*)
						_config_site_option "gl_cv_func_wcrtomb_retval" "yes"; ;;
					*gl_cv_func_wcsnrtombs_works_in_traditional_locale*)
						_config_site_option "gl_cv_func_wcsnrtombs_works_in_traditional_locale" "yes"; ;;
					*gl_cv_func_wcsrtombs_termination*)
						_config_site_option "gl_cv_func_wcsrtombs_termination" "yes"; ;;
					*gl_cv_func_wcsrtombs_null*)
						_config_site_option "gl_cv_func_wcsrtombs_null" "yes"; ;;
					*gl_cv_func_wctob_works*)
						_config_site_option "gl_cv_func_wctob_works" "yes"; ;;
					*gl_cv_func_iswcntrl_works*)
						_config_site_option "gl_cv_func_iswcntrl_works" "yes"; ;;
					*gl_cv_func_wcwidth_works*)
						_config_site_option "gl_cv_func_wcwidth_works" "yes"; ;;

					*gl_cv_func_mbrtoc32_C_locale_sans_EILSEQ* | \
					*gl_cv_func_mbrtowc_C_locale_sans_EILSEQ* | \
					*gl_cv_C_locale_sans_EILSEQ*)
						# Technically, we would have to say "no" here, because our C locale is utf-8, so
						# e.g.: mbrtowc(&wc, \"\\x80\", 1, &mbs) == (size_t)-2  (-2: incomplete sequence)
						# Meaning that our "C" locale isn't "free of encoding errors".
						#
						# For reference, here's gnulib's test program:
						# >> #include <limits.h>
						# >> #include <locale.h>
						# >> #include <wchar.h>
						# >> int main() {
						# >>     int i;
						# >>     char *locale = setlocale (LC_ALL, "C");
						# >>     if (!locale)
						# >>         return 2;
						# >>     for (i = CHAR_MIN; i <= CHAR_MAX; i++) {
						# >>         char c = i;
						# >>         wchar_t wc;
						# >>         mbstate_t mbs = { 0, };
						# >>         size_t ss = mbrtowc(&wc, &c, 1, &mbs);
						# >>         if (1 < ss)
						# >>             return 3;
						# >>     }
						# >>     return 0;
						# >> }
						# And yes: running this program under KOS returns "$? == 3", which
						# would indicate a failure.
						#
						# However, because gnulib >>>𝐒𝐔𝐗 𝐃𝟏𝐗<<<, guess what happens when
						# you use its own replacement for our perfectly working "mbrtowc",
						# after configuring it for utf-8 (as it also would if ran natively
						# under KOS)
						#
						# THATS RIGHT! IT RETURNS INCOMPLTE SEQUENCE ERRORS JUST LIKE OURS
						# DOES, MEANING THAT THIS FEATURE TEST IS TOTALLY SCREWED UP AND
						# WRONG!
						#
						# As a matter of fact, this test only normally succeeds on systems
						# with BROKEN (or non-utf-8) C locale environments.
						if false; then
							_config_site_option "gl_cv_func_mbrtoc32_C_locale_sans_EILSEQ" "no"
							_config_site_option "gl_cv_func_mbrtowc_C_locale_sans_EILSEQ" "no"
							_config_site_option "gl_cv_C_locale_sans_EILSEQ" "no"
							# NOTE: With these options, "gl_FUNC_MBRTOWC" would do:
							# >> case $gl_cv_C_locale_sans_EILSEQ in
							# >>   *yes) ;;
							# >>   *) AC_DEFINE([C_LOCALE_MAYBE_EILSEQ], [1],
							# >>        [Define to 1 if the C locale may have encoding errors.])
							# >>      REPLACE_MBRTOWC=1
							# >>      ;;
							# >> esac
							# Turning on "REPLACE_MBRTOWC=1", which is something we don't want
						else
							# Prevent gnulib from replacing perfectly operational functions
							# with a bloated replacement that exhibits the same "bugs" it was
							# meant to "fix" in the first place (though I wouldn't call them
							# "bugs", since THEY INTENDED, CORRECT, DOCUMENTED, AND EXPECTED
							# BEHAVIOR!!!!)
							_config_site_option "gl_cv_func_mbrtoc32_C_locale_sans_EILSEQ" "yes"
							_config_site_option "gl_cv_func_mbrtowc_C_locale_sans_EILSEQ" "yes"
							_config_site_option "gl_cv_C_locale_sans_EILSEQ" "yes"
						fi
						;;
					############################################################################
					# Options we intentionally don't set (because they're too CPU-specific):
					# - gl_cv_cc_double_expbit0
					# - gl_cv_cc_float_expbit0
					# - gl_cv_cc_long_double_expbit0
					# - ac_cv_x87_double_rounding
					############################################################################

					############################################################################
					# Detection of type sizes always takes forever, so we speed it up
					*ac_cv_sizeof_*)
						. "$KOS_MISC/utilities/misc/target-info.sh"
						_config_site_option "ac_cv_sizeof_char" "$TARGET_CONFIG_SIZEOF_CHAR"
						_config_site_option "ac_cv_sizeof_short" "$TARGET_CONFIG_SIZEOF_SHORT"
						_config_site_option "ac_cv_sizeof_int" "$TARGET_CONFIG_SIZEOF_INT"
						_config_site_option "ac_cv_sizeof_long" "$TARGET_CONFIG_SIZEOF_LONG"
						_config_site_option "ac_cv_sizeof_long_long" "$TARGET_CONFIG_SIZEOF_LLONG"
						_config_site_option "ac_cv_sizeof_wchar_t" "$TARGET_CONFIG_SIZEOF_WCHAR_T"
						_config_site_option "ac_cv_sizeof_float" "$TARGET_CONFIG_SIZEOF_FLOAT"
						_config_site_option "ac_cv_sizeof_double" "$TARGET_CONFIG_SIZEOF_DOUBLE"
						_config_site_option "ac_cv_sizeof_long_double" "$TARGET_CONFIG_SIZEOF_LDOUBLE"
						_config_site_option "ac_cv_sizeof_void_p" "$TARGET_CONFIG_SIZEOF_POINTER"
						_config_site_option "ac_cv_sizeof_size_t" "$TARGET_CONFIG_SIZEOF_POINTER"
						_config_site_option "ac_cv_sizeof_ssize_t" "$TARGET_CONFIG_SIZEOF_POINTER"
						_config_site_option "ac_cv_sizeof_ptrdiff_t" "$TARGET_CONFIG_SIZEOF_POINTER"
						_config_site_option "ac_cv_sizeof_intptr_t" "$TARGET_CONFIG_SIZEOF_POINTER"
						_config_site_option "ac_cv_sizeof_uintptr_t" "$TARGET_CONFIG_SIZEOF_POINTER"
						;;
					*ac_cv_alignof_*)
						. "$KOS_MISC/utilities/misc/target-info.sh"
						_config_site_option "ac_cv_alignof_char" "$TARGET_CONFIG_ALIGNOF_CHAR"
						_config_site_option "ac_cv_alignof_short" "$TARGET_CONFIG_ALIGNOF_SHORT"
						_config_site_option "ac_cv_alignof_int" "$TARGET_CONFIG_ALIGNOF_INT"
						_config_site_option "ac_cv_alignof_long" "$TARGET_CONFIG_ALIGNOF_LONG"
						_config_site_option "ac_cv_alignof_long_long" "$TARGET_CONFIG_ALIGNOF_LLONG"
						_config_site_option "ac_cv_alignof_wchar_t" "$TARGET_CONFIG_ALIGNOF_WCHAR_T"
						_config_site_option "ac_cv_alignof_float" "$TARGET_CONFIG_ALIGNOF_FLOAT"
						_config_site_option "ac_cv_alignof_double" "$TARGET_CONFIG_ALIGNOF_DOUBLE"
						_config_site_option "ac_cv_alignof_long_double" "$TARGET_CONFIG_ALIGNOF_LDOUBLE"
						_config_site_option "ac_cv_alignof_void_p" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_size_t" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_ssize_t" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_ptrdiff_t" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_intptr_t" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_uintptr_t" "$TARGET_CONFIG_ALIGNOF_POINTER"
						_config_site_option "ac_cv_alignof_maxalign_t" "$TARGET_CONFIG_ALIGNOF_MAXALIGN_T"
						;;
					############################################################################


					# Some more found in misc programs

					# nano
					*gl_cv_func_printf_enomem*)
						_config_site_option "gl_cv_func_printf_enomem" "yes"; ;;
					*gt_cv_func_printf_posix*)
						_config_site_option "gt_cv_func_printf_posix" "yes"; ;;
					*gl_cv_func_gettimeofday_clobber*) # No, our gettimeofday() doesn't clobber localtime(3)'s buffer
						_config_site_option "gl_cv_func_gettimeofday_clobber" "no"; ;;
					*gt_cv_int_divbyzero_sigfpe*)
						_config_site_option "gt_cv_int_divbyzero_sigfpe" "yes"; ;;

					# Xorg
					*xorg_cv_malloc0_returns_null*)
						_config_site_option "xorg_cv_malloc0_returns_null" "no"; ;;

					# Python
					*ac_cv_pthread_is_default*) # <pthread.h> works even without passing "-pthread" (yes: it does)
						_config_site_option "ac_cv_pthread_is_default" "yes"; ;;
					*ac_cv_pthread*)
						# Yes, our gcc does define "-pthread", but it only does "-D_REENTRANT"
						# This in turn turns on "__USE_REENTRANT", which is used to expose a
						# couple of functions here and there, but doesn't affect <pthread.h>
						_config_site_option "ac_cv_pthread" "yes"; ;;
					*ac_cv_kpthread*) # No, our gcc doesn't accept "-Kpthread"
						_config_site_option "ac_cv_kpthread" "no"; ;;
					*ac_cv_kthread*) # No, our gcc doesn't accept "-Kthread"
						_config_site_option "ac_cv_kthread" "no"; ;;
					*ac_cv_pthread_system_supported*) # pthread_attr_setscope(PTHREAD_SCOPE_SYSTEM) doesn't return an error (which it doesn't')
						_config_site_option "ac_cv_pthread_system_supported" "yes"; ;;
					*ac_cv_have_chflags*) # As for right now, we don't have this function. But it may be added someday
						_config_site_option "ac_cv_have_chflags" "no"; ;;
					*ac_cv_have_lchflags*) # As for right now, we don't have this function. But it may be added someday
						_config_site_option "ac_cv_have_lchflags" "no"; ;;
					*ac_cv_buggy_getaddrinfo*)
						_config_site_option "ac_cv_buggy_getaddrinfo" "no"; ;;
					*ac_cv_little_endian_double* | *ac_cv_big_endian_double* | *ac_cv_mixed_endian_double*)
						if _test_expr "__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__" "#include <ieee754.h>"; then
							_config_site_option "ac_cv_little_endian_double" "no"
							_config_site_option "ac_cv_big_endian_double" "yes"
							_config_site_option "ac_cv_mixed_endian_double" "no"
						elif _test_expr "__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__" "#include <ieee754.h>"; then
							_config_site_option "ac_cv_little_endian_double" "no"
							_config_site_option "ac_cv_big_endian_double" "no"
							_config_site_option "ac_cv_mixed_endian_double" "yes"
						else
							_config_site_option "ac_cv_little_endian_double" "yes"
							_config_site_option "ac_cv_big_endian_double" "no"
							_config_site_option "ac_cv_mixed_endian_double" "no"
						fi
						;;
					*ac_cv_tanh_preserves_zero_sign*)
						_config_site_option "ac_cv_tanh_preserves_zero_sign" "yes"; ;;
					*ac_cv_posix_semaphores_enabled*)
						_config_site_option "ac_cv_posix_semaphores_enabled" "yes"; ;;
					*ac_cv_broken_sem_getvalue*)
						_config_site_option "ac_cv_broken_sem_getvalue" "no"; ;;
					*ac_cv_file__dev_ptmx*)
						_config_site_option "ac_cv_file__dev_ptmx" "no"; ;;
					*ac_cv_file__dev_ptc*)
						_config_site_option "ac_cv_file__dev_ptc" "no"; ;;
					*ac_cv_wchar_t_signed*)
						# s.a. __WCHAR_UNSIGNED__
						if _test_expr "(wchar_t)-1 < (wchar_t)0" "#include <wchar.h>"; then
							_config_site_option "ac_cv_wchar_t_signed" "yes"
						else
							_config_site_option "ac_cv_wchar_t_signed" "no"
						fi
						;;
					*ac_cv_rshift_extends_sign*)
						# s.a. __ARCH_SIGNED_SHIFT_IS_SDIV
						if _test_links <<< "
							#include <asm/signed-shift.h>
							#ifndef __ARCH_SIGNED_SHIFT_IS_SDIV
							#error coke me
							#endif
							int main() { return 0; }
						"; then
							_config_site_option "ac_cv_rshift_extends_sign" "yes"
						else
							_config_site_option "ac_cv_rshift_extends_sign" "no"
						fi
						;;
					*ac_cv_broken_nice*)
						_config_site_option "ac_cv_broken_nice" "no"; ;;
					*ac_cv_broken_poll*)
						_config_site_option "ac_cv_broken_poll" "no"; ;;
					*ac_cv_working_tzset*)
						_config_site_option "ac_cv_working_tzset" "yes"; ;;
					*ac_cv_have_long_long_format*) # printf("%lld")
						_config_site_option "ac_cv_have_long_long_format" "yes"; ;;
					*ac_cv_have_size_t_format*) # printf("%zd")
						_config_site_option "ac_cv_have_size_t_format" "yes"; ;;
					*ac_cv_computed_gotos*) # At least under GCC
						_config_site_option "ac_cv_computed_gotos" "yes"; ;;

					*) ;;
					esac
				done < "$SRCPATH/configure"
			fi
			(
				export CC="${CROSS_PREFIX}gcc"
				export CFLAGS="-ggdb"
				export CXX="${CROSS_PREFIX}g++"
				export CXXFLAGS="-ggdb"
				export CPP="${CROSS_PREFIX}cpp"
				export CXXCPP="${CROSS_PREFIX}cpp"
				if ! test -z "$CONFIG_SITE"; then
					cat > "$OPTPATH/config.site" <<< "$CONFIG_SITE"
					export CONFIG_SITE="$OPTPATH/config.site"
				fi
				${GM_HOOK_BEFORE_CONFIGURE:-:}
				cmd cd "$OPTPATH"
				echo "gnu_make: Now running $PACKAGE_NAME: './configure'..."
				cmd bash "$SRCPATH/configure" $CONFIGURE
			) || exit $?
			${GM_HOOK_AFTER_CONFIGURE:-:}
		fi # if [ "$MODE_FORCE_CONF" == yes ] || ! [ -f "$OPTPATH/Makefile" ];
		${GM_HOOK_BEFORE_MAKE:-:}
		cmd cd "$OPTPATH"
		echo "gnu_make: Now running $PACKAGE_NAME: 'make'..."
		cmd make -j $MAKE_PARALLEL_COUNT
		${GM_HOOK_AFTER_MAKE:-:}
		> "$OPTPATH/_didmake"
	fi     # if [ "$MODE_FORCE_MAKE" == yes ] || ! [ -f "$OPTPATH/_didmake" ]
	cmd cd "$OPTPATH"
	# Don't directly install to $DESTDIR to prevent a successful install
	# from being detected when "make install" fails, or get interrupted.
	rm -r "$DESTDIR-temp" > /dev/null 2>&1
	echo "gnu_make: Now running $PACKAGE_NAME: 'make install'..."
	(
		export DESTDIR="$DESTDIR-temp"
		${GM_HOOK_BEFORE_INSTALL:-:}
		cmd make -j $MAKE_PARALLEL_COUNT DESTDIR="$DESTDIR" install
	) || exit $?
	${GM_HOOK_AFTER_INSTALL:-:}
	rm -r "$DESTDIR" > /dev/null 2>&1
	cmd mv "$DESTDIR-temp" "$DESTDIR"
fi         # if [ "$MODE_FORCE_MAKE" == yes ] || ! [ -d "$DESTDIR" ]

# Install to disk
. "$KOS_MISC/utilities/misc/install-DESTDIR.sh"
