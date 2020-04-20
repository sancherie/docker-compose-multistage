AC_PREREQ([2.69])
AC_INIT([docker-compose-multistage], [1.0], [clement@sanchez.sh])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

LT_INIT

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile examples/Makefile man/Makefile scripts/Makefile])
AC_OUTPUT
