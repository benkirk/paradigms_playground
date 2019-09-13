#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([omp_scaling], [0.0.1], [benjamin.kirk@nasa.gov])
AC_MSG_RESULT(---------------------------------------------)
AC_MSG_RESULT(-------- Configuring OpenMP Scaling ---------)
AC_MSG_RESULT(---------------------------------------------)
AC_CONFIG_SRCDIR([gs_openmp.c])
AC_CONFIG_HEADERS([openmp_config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([dist-bzip2 subdir-objects color-tests 1.11])
# use silent rules - automake 1.11
#AM_SILENT_RULES(yes)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_FC
AC_FC_LIBRARY_LDFLAGS
AC_FC_WRAPPERS
AM_PATH_PYTHON
AC_ARG_VAR(PYTHONPATH, compile-time PYTHONPATH (e.g. for mpi4py))

# Default to C++, and get OpenMP flags for all used languages
AC_LANG(C++)
AX_OPENMP
AC_LANG_PUSH([C])
AX_OPENMP
AC_SUBST(OPENMP_CFLAGS)
AC_LANG_POP([C])
AC_LANG_PUSH([Fortran])
AX_OPENMP
AC_LANG_POP([Fortran])


# Checks for MPI features
#AC_CHECK_FUNC([MPI_Win_create], [mpi_win_create=true])
#AC_CHECK_FUNC([MPI_Ibarrier],   [mpi_ibarrier=true], [mpi_ibarrier=false])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Check for external libraries

# Set up output files
AC_CONFIG_FILES([Makefile
                 ])
AC_OUTPUT
AC_MSG_RESULT(---------------------------------------------)
AC_MSG_RESULT(------ Done Configuring OpenMP Scaling ------)
AC_MSG_RESULT(---------------------------------------------)

#AX_SUMMARIZE_CONFIG