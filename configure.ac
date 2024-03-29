#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Infer the source directory as the path to the ./configure script

AC_PREREQ([2.69])
AC_INIT([programming_paradigms],[0.0.1],[benkirk@ucar.edu])
AC_MSG_RESULT(----------------------------------------------------)
AC_MSG_RESULT(-------- Configuring Programming Paradigms ---------)
AC_MSG_RESULT(----------------------------------------------------)
AC_CONFIG_SRCDIR([gs_openmp.c])
AC_CONFIG_HEADERS([programming_paradigms_config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([dist-xz dist-bzip2 tar-ustar color-tests serial-tests 1.12])
AM_SILENT_RULES(yes)

srcdir=`dirname $0`
top_srcdir=`dirname $0`

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_SEARCH_LIBS([ceil], [m], [], [AC_MSG_ERROR([unable to find the ceil() function]) ])


#AC_PROG_FC
#AC_FC_LIBRARY_LDFLAGS
#AC_FC_WRAPPERS
#AM_PROG_CC_C_O
AM_PATH_PYTHON
AC_ARG_VAR(PYTHONPATH, compile-time PYTHONPATH (e.g. for mpi4py))

# Default to C++, and get OpenMP flags for all used languages
AC_LANG([C++])
AX_OPENMP
AC_SUBST(OPENMP_CXXFLAGS)
AC_LANG_PUSH([C])
AX_OPENMP
AC_SUBST(OPENMP_CFLAGS)
AC_LANG_POP([C])


#---------------------------------------------------
# optional packages
enableeigensparse=yes
CONFIGURE_EIGEN(3.1.2,no)
#AC_CONFIG_FILES([contrib/eigen/eigen/Makefile])
AM_CONDITIONAL(HAVE_EIGEN, test x$enableeigen = xyes)

CONFIGURE_TBB
AM_CONDITIONAL(HAVE_TBB, test x$enabletbb = xyes)


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
AC_MSG_RESULT(---------------------------------------------------------)
AC_MSG_RESULT(-------- Done Configuring Programming Paradigms ---------)
AC_MSG_RESULT(---------------------------------------------------------)

AX_SUMMARIZE_CONFIG
