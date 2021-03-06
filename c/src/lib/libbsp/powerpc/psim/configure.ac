## Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rtems-c-src-lib-libbsp-powerpc-psim],[_RTEMS_VERSION],[https://devel.rtems.org/newticket])
RTEMS_TOP(../../../../../..)
RTEMS_SOURCE_TOP
RTEMS_BUILD_TOP
RTEMS_BSP_LINKCMDS

RTEMS_CANONICAL_TARGET_CPU
AM_INIT_AUTOMAKE([no-define nostdinc foreign 1.12.2])
RTEMS_BSP_CONFIGURE




RTEMS_BSPOPTS_SET([PPC_USE_SPRG],[*],[0])
RTEMS_BSPOPTS_HELP([PPC_USE_SPRG],
[If defined, then the PowerPC specific code in RTEMS will use some
of the special purpose registers to slightly optimize interrupt
response time.  The use of these registers can conflict with
other tools like debuggers.])

RTEMS_BSPOPTS_SET([PPC_VECTOR_FILE_BASE],[*],[0xFFF00100])
RTEMS_BSPOPTS_HELP([PPC_VECTOR_FILE_BASE],
[This defines the base address of the exception table.
 NOTE: Vectors are actually at 0xFFF00000 but file starts at offset.])

RTEMS_BSPOPTS_SET([CLOCK_DRIVER_USE_FAST_IDLE],[psim],[1])
RTEMS_BSPOPTS_HELP([CLOCK_DRIVER_USE_FAST_IDLE],
[This sets a mode where the time runs as fast as possible when
 a clock ISR occurs while the IDLE thread is executing.  This can
 significantly reduce simulation times.])

RTEMS_BSPOPTS_SET([CONFIGURE_MALLOC_BSP_SUPPORTS_SBRK], [*], [1])
RTEMS_BSPOPTS_HELP([CONFIGURE_MALLOC_BSP_SUPPORTS_SBRK],
[If defined then the BSP may reduce the available memory size
initially. This can be useful for debugging (reduce the core
size) or dynamic loading (std gcc text offsets/jumps are < +/-32M).
Note that the policy can still be defined by the application
(see sbrk.c, BSP_sbrk_policy). By undefining
CONFIGURE_MALLOC_BSP_SUPPORTS_SBRK this feature is removed
and a little memory is saved.])

RTEMS_BSPOPTS_SET([BSP_INTERRUPT_STACK_AT_WORK_AREA_BEGIN],[*],[1])
RTEMS_BSPOPTS_HELP([BSP_INTERRUPT_STACK_AT_WORK_AREA_BEGIN],[indicate that the interrupt stack is at the work area begin])

RTEMS_BSP_CLEANUP_OPTIONS

# Explicitly list all Makefiles here
AC_CONFIG_FILES([Makefile])

RTEMS_PPC_EXCEPTIONS

AC_OUTPUT
