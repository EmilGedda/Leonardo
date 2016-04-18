# $Id$

AC_PREREQ(2.59)

AC_INIT([leonardo-logo-parser], [0.1.0])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_AUX_DIR([scripts])

AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE

if test "$CFLAGS" == ""; then
    CFLAGS="-g -I/usr/include"
fi
if test "$CXXFLAGS" == ""; then
    CXXFLAGS="-g -I/usr/include"
fi

# enable full optimization by configure switch
AC_ARG_ENABLE(optimize,
	AS_HELP_STRING([--enable-optimize],
		       [Build with full optimization @<:@default=no@:>@]),
        [ case "${enableval}" in
          yes)
                CFLAGS="$CFLAGS -O3 -DNDEBUG";
                CXXFLAGS="$CXXFLAGS -O3 -DNDEBUG";
          ;;
          no) ;;
          *) AC_MSG_ERROR(bad value ${enableval} for --enable-optimize) ;;
          esac ],
        [ optimize=false ])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_LEX
AC_PROG_YACC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([inttypes.h libintl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset pow])
# Create Makefiles
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
