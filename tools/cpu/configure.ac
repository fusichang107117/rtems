## Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rtems-tools-cpu],[_RTEMS_VERSION],[https://devel.rtems.org/newticket])
AC_CONFIG_SRCDIR([generic])
RTEMS_TOP(../..)
RTEMS_SOURCE_TOP
RTEMS_BUILD_TOP

RTEMS_CANONICAL_TARGET_CPU

AM_INIT_AUTOMAKE([no-define foreign subdir-objects 1.12.2])
AM_MAINTAINER_MODE

RTEMS_PATH_KSH

RTEMS_TOOLPATHS
AC_SUBST(program_prefix)

AC_CONFIG_SUBDIRS(generic)
case "$RTEMS_CPU" in
sh ) AC_CONFIG_SUBDIRS(sh);;
nios2 ) AC_CONFIG_SUBDIRS(nios2);;
esac

# Explicitly list all Makefiles here
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
