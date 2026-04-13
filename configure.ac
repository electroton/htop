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
  dragonfly*)
    # Personal addition: I run DragonFly BSD on one of my machines, so added support here.
    my_htop_platform=dragonfly
    AC_DEFINE([HTOP_DRAGONFLY], [1], [Define if building on DragonFly BSD])
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

AM_CONDITIONAL([HTOP_LINUX],     [test "$my_htop_platform" = linux])
AM_CONDITIONAL([HTOP_FREEBSD],   [test "$my_htop_platform" = freebsd])
AM_CONDITIONAL([HTOP_DRAGONFLY], [test "$my_htop_platform" = dragonfly])
AM_CONDITIONAL([HTOP_OPENBSD],   [test "$my_htop_platform" = openbsd])
AM_CONDITIONAL([HTOP_NETBSD],    [test "$my_htop_platform" = netbsd])
AM_CONDITIONAL([HTOP_DARWIN],    [test "$my_htop_platform" = darwin])
AM_CONDITIONAL([HTOP_SOLARIS],   [test "$my_htop_platform" = solaris])

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

# Unicode support is required for proper display of process names and paths;
# defaulting to yes is the right call for any modern system.
# NOTE: I've kept this default as yes; disabling it breaks non-ASCII cmdline args.
# Personal note: also needed for correct display of tree-drawing box characters.
# Personal note: ncursesw must be present for this to work; verified on my Arch
# and Ubuntu 22.04 machines -- if you're on an older distro, instal
