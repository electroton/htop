# Process this file with autoconf to produce a configure script.
AC_INIT([htop],[3.3.0],[htop@groups.io],[htop],[https://htop.dev/])
AC_CONFIG_SRCDIR([htop.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_STDC
AM_PROG_CC_C_O

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h sys/param.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_UID_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strdup strerror])

# Platform detection
AC_CANONICAL_HOST

case "$host_os" in
  linux*)
    my_htop_platform=linux
    AC_DEFINE([HTOP_LINUX], [1], [Define if building on Linux])
    ;;
  freebsd*)
    my_htop_platform=freebsd
    AC_DEFINE([HTOP_FREEBSD], [1], [Define if building on FreeBSD])
    ;;
  openbsd*)
    my_htop_platform=openbsd
    AC_DEFINE([HTOP_OPENBSD], [1], [Define if building on OpenBSD])
    ;;
  netbsd*)
    my_htop_platform=netbsd
    AC_DEFINE([HTOP_NETBSD], [1], [Define if building on NetBSD])
    ;;
  darwin*)
    my_htop_platform=darwin
    AC_DEFINE([HTOP_DARWIN], [1], [Define if building on Darwin/macOS])
    ;;
  solaris*)
    my_htop_platform=solaris
    AC_DEFINE([HTOP_SOLARIS], [1], [Define if building on Solaris])
    ;;
  *)
    AC_MSG_ERROR([Unsupported platform: $host_os])
    ;;
esac

AM_CONDITIONAL([HTOP_LINUX],   [test "$my_htop_platform" = linux])
AM_CONDITIONAL([HTOP_FREEBSD], [test "$my_htop_platform" = freebsd])
AM_CONDITIONAL([HTOP_OPENBSD], [test "$my_htop_platform" = openbsd])
AM_CONDITIONAL([HTOP_NETBSD],  [test "$my_htop_platform" = netbsd])
AM_CONDITIONAL([HTOP_DARWIN],  [test "$my_htop_platform" = darwin])
AM_CONDITIONAL([HTOP_SOLARIS], [test "$my_htop_platform" = solaris])

# ncurses
AC_ARG_WITH([ncurses],
  [AS_HELP_STRING([--with-ncurses], [use ncurses (default: auto)])],
  [], [with_ncurses=auto])

if test "$with_ncurses" != no; then
  PKG_CHECK_MODULES([NCURSES], [ncursesw],
    [AC_DEFINE([HAVE_NCURSESW], [1], [Define if ncursesw is available])],
    [PKG_CHECK_MODULES([NCURSES], [ncurses],
      [],
      [AC_CHECK_LIB([ncurses], [initscr], [NCURSES_LIBS="-lncurses"],
        [AC_MSG_ERROR([ncurses library not found])])])])
fi

AC_SUBST([NCURSES_CFLAGS])
AC_SUBST([NCURSES_LIBS])

# Optional features
AC_ARG_ENABLE([proc],
  [AS_HELP_STRING([--enable-proc], [use Linux /proc filesystem (default: yes on Linux)])],
  [], [enable_proc=auto])

AC_ARG_ENABLE([unicode],
  [AS_HELP_STRING([--enable-unicode], [enable Unicode support (default: yes)])],
  [], [enable_unicode=yes])

if test "$enable_unicode" = yes; then
  AC_DEFINE([HAVE_UNICODE], [1], [Define if Unicode support is enabled])
fi

AC_ARG_ENABLE([sensors],
  [AS_HELP_STRING([--enable-sensors], [enable libsensors support (default: auto)])],
  [], [enable_sensors=auto])

if test "$enable_sensors" != no; then
  AC_CHECK_LIB([sensors], [sensors_init],
    [AC_DEFINE([HAVE_SENSORS], [1], [Define if libsensors is available])
     SENSORS_LIBS="-lsensors"],
    [if test "$enable_sensors" = yes; then
       AC_MSG_ERROR([libsensors not found])
     fi])
fi

AC_SUBST([SENSORS_LIBS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

AC_MSG_RESULT([
  htop $VERSION
  Platform:   $my_htop_platform
  Unicode:    $enable_unicode
  Sensors:    $enable_sensors
])
