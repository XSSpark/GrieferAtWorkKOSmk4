# Copyright (c) 2019-2020 Griefer@Work
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
#    Portions Copyright (c) 2019-2020 Griefer@Work
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.

require_program aclocal
require_program autoreconf
require_program autoconf
require_program libtool

XORG_CONFIGURE_PREFIX="/"
XORG_CONFIGURE_EXEC_PREFIX="/"
XORG_CONFIGURE_BINDIR="/bin"
XORG_CONFIGURE_SBINDIR="/bin"
XORG_CONFIGURE_LIBEXECDIR="/libexec"
XORG_CONFIGURE_SYSCONFDIR="/etc"
XORG_CONFIGURE_SHAREDSTATEDIR="/usr/com"
XORG_CONFIGURE_LOCALSTATEDIR="/var"
XORG_CONFIGURE_RUNSTATEDIR="/var/run"
XORG_CONFIGURE_LIBDIR="/$TARGET_LIBPATH"
XORG_CONFIGURE_INCLUDEDIR="/usr/include"
XORG_CONFIGURE_OLDINCLUDEDIR="$XORG_CONFIGURE_INCLUDEDIR"
XORG_CONFIGURE_DATAROOTDIR="/usr/share"
XORG_CONFIGURE_DATADIR="$XORG_CONFIGURE_DATAROOTDIR"
XORG_CONFIGURE_INFODIR="$XORG_CONFIGURE_DATADIR/info"
XORG_CONFIGURE_LOCALEDIR="$XORG_CONFIGURE_DATADIR/locale"
XORG_CONFIGURE_MANDIR="$XORG_CONFIGURE_DATADIR/man"
XORG_CONFIGURE_DOCDIR_PREFIX="$XORG_CONFIGURE_DATADIR/doc"
XORG_CONFIGURE_HTMLDIR_PREFIX="$XORG_CONFIGURE_DATADIR/doc"
XORG_CONFIGURE_DVIDIR_PREFIX="$XORG_CONFIGURE_DATADIR/doc"
XORG_CONFIGURE_PDFDIR_PREFIX="$XORG_CONFIGURE_DATADIR/doc"
XORG_CONFIGURE_PSDIR_PREFIX="$XORG_CONFIGURE_DATADIR/doc"
XORG_CONFIGURE_LOCALE_LIB_DIR="$XORG_CONFIGURE_LIBDIR/X11/locale"


# For copy & pasting:
#				--prefix="$XORG_CONFIGURE_PREFIX" \
#				--exec-prefix="$XORG_CONFIGURE_EXEC_PREFIX" \
#				--bindir="$XORG_CONFIGURE_BINDIR" \
#				--sbindir="$XORG_CONFIGURE_SBINDIR" \
#				--libexecdir="$XORG_CONFIGURE_LIBEXECDIR" \
#				--sysconfdir="$XORG_CONFIGURE_SYSCONFDIR" \
#				--sharedstatedir="$XORG_CONFIGURE_SHAREDSTATEDIR" \
#				--localstatedir="$XORG_CONFIGURE_LOCALSTATEDIR" \
#				--libdir="$XORG_CONFIGURE_LIBDIR" \
#				--includedir="$XORG_CONFIGURE_INCLUDEDIR" \
#				--oldincludedir="$XORG_CONFIGURE_OLDINCLUDEDIR" \
#				--datarootdir="$XORG_CONFIGURE_DATAROOTDIR" \
#				--datadir="$XORG_CONFIGURE_DATADIR" \
#				--infodir="$XORG_CONFIGURE_INFODIR" \
#				--localedir="$XORG_CONFIGURE_LOCALEDIR" \
#				--mandir="$XORG_CONFIGURE_MANDIR" \
#				--docdir="$XORG_CONFIGURE_DOCDIR_PREFIX/$NAME" \
#				--htmldir="$XORG_CONFIGURE_HTMLDIR_PREFIX/$NAME" \
#				--dvidir="$XORG_CONFIGURE_DVIDIR_PREFIX/$NAME" \
#				--pdfdir="$XORG_CONFIGURE_PDFDIR_PREFIX/$NAME" \
#				--psdir="$XORG_CONFIGURE_PSDIR_PREFIX/$NAME" \
# ...


XORG_MACROS_VERSION="1.19.2"
XORG_MACROS_SRCPATH="$KOS_ROOT/binutils/src/Xorg/xorg-macros-$XORG_MACROS_VERSION"
XORG_MACROS_OPTPATH="$BINUTILS_SYSROOT/opt/Xorg/xorg-macros-$XORG_MACROS_VERSION"

# xorg-macros
if ! [ -f "$PKG_CONFIG_PATH/xorg-macros.pc" ]; then
	if ! [ -f "$XORG_MACROS_OPTPATH/Makefile" ]; then
		if ! [ -f "$XORG_MACROS_SRCPATH/configure" ]; then
			cmd mkdir -p "$KOS_ROOT/binutils/src/Xorg"
			cmd cd "$KOS_ROOT/binutils/src/Xorg"
			cmd rm -rf "xorg-macros-$XORG_MACROS_VERSION"
			cmd rm -rf "util-macros-$XORG_MACROS_VERSION"
			if ! [ -f "xorg-macros-$XORG_MACROS_VERSION.tar.gz" ]; then
				download_file \
					"util-macros-$XORG_MACROS_VERSION.tar.gz" \
					"https://www.x.org/releases/individual/util/util-macros-$XORG_MACROS_VERSION.tar.gz"
				cmd mv \
					"util-macros-$XORG_MACROS_VERSION.tar.gz" \
					"xorg-macros-$XORG_MACROS_VERSION.tar.gz"
			fi
			cmd tar xvf "xorg-macros-$XORG_MACROS_VERSION.tar.gz"
			cmd mv "util-macros-$XORG_MACROS_VERSION" "xorg-macros-$XORG_MACROS_VERSION"
		fi
		cmd rm -rf "$XORG_MACROS_OPTPATH"
		cmd mkdir -p "$XORG_MACROS_OPTPATH"
		cmd cd "$XORG_MACROS_OPTPATH"
		(
			export CC="${CROSS_PREFIX}gcc"
			export CPP="${CROSS_PREFIX}cpp"
			export CFLAGS="-ggdb"
			export CXX="${CROSS_PREFIX}g++"
			export CXXCPP="${CROSS_PREFIX}cpp"
			export CXXFLAGS="-ggdb"
			cmd bash "../../../../src/Xorg/xorg-macros-$XORG_MACROS_VERSION/configure" \
				--prefix="$BINUTILS_SYSROOT/usr/local" \
				--exec-prefix="$BINUTILS_SYSROOT/usr/local"
		) || exit $?
	fi
	cmd cd "$XORG_MACROS_OPTPATH"
	cmd make -j $MAKE_PARALLEL_COUNT
	cmd make -j $MAKE_PARALLEL_COUNT install

	# The actual macros file is:
	#     $BINUTILS_SYSROOT/usr/local/share/aclocal/xorg-macros.m4
	cat > "$PKG_CONFIG_PATH/xorg-macros.pc" <<EOF
prefix=$BINUTILS_SYSROOT/usr/local
exec_prefix=$BINUTILS_SYSROOT/usr/local
includedir=$KOS_ROOT/kos/include
datarootdir=$BINUTILS_SYSROOT/usr/local/share
datadir=$BINUTILS_SYSROOT/usr/local/share
PACKAGE=util-macros
# Used by XORG_INSTALL
pkgdatadir=$BINUTILS_SYSROOT/usr/local/share/util-macros
# docdir is kept for backwards compatibility with XORG_INSTALL from
# util-macros 1.4
docdir=$BINUTILS_SYSROOT/usr/local/share/util-macros

Name: X.Org Macros
Description: A set of autoconf project macros for X.Org modules
Version: $XORG_MACROS_VERSION
EOF
fi

