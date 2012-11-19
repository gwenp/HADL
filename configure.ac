#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([hadl],[1.0])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Used for making libraries
AM_PROG_LIBTOOL
AC_PROG_MAKE_SET

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([LIBJSONCPP], [jsoncpp])
PKG_CHECK_MODULES([LIBSIGC], [sigc++-2.0])


# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile src/Makefile src/api/Makefile])

AC_OUTPUT
