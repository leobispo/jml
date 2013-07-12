ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

algebra_include_HEADERS = \
  glz.h \
  irls.h \
  lapack.h \
  least_squares.h \
  matrix_ops.h \
  multi_array_utils.h \
  svd.h

algebra_includedir = $(includedir)/jml/algebra

lib_LTLIBRARIES = libalgebra.la

libalgebra_la_LDFLAGS = -avoid-version
libalgebra_la_SOURCES = \
  least_squares.cc \
  irls.cc \
  lapack.cc \
  ilaenv.f \
  svd.cc \
  matrix_ops.cc

libalgebra_la_LIBADD = \
  $(BOOST_SYSTEM_LIB) \
  $(LAPACK_LIBS) \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(abs_top_builddir)/jml/db/libdb.la

CC_TESTS = \
  least_squares_test \
  remove_dependent_test

AM_CXXFLAGS = 
AM_CFLAGS = 

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

least_squares_test_SOURCES = testing/least_squares_test.cc
remove_dependent_test_SOURCES = testing/remove_dependent_test.cc

TEST_LIB = \
  $(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
  $(BOOST_SYSTEM_LIB) \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  libalgebra.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la

least_squares_test_LDADD = $(TEST_LIB)
remove_dependent_test_LDADD = $(TEST_LIB)
