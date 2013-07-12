ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

stats_include_HEADERS = \
  auc.h \
  distribution.h \
  distribution_ops.h \
  distribution_simd.h \
  moments.h \
  rmse.h \
  sparse_distribution.h

stats_includedir = $(includedir)/jml/arch

lib_LTLIBRARIES = libstats.la

libstats_la_LIBADD = $(abs_top_builddir)/jml/arch/libarch.la $(abs_top_builddir)/jml/utils/libutils.la

libstats_la_SOURCES = \
  distribution.cc \
  auc.cc

libstats_la_LDFLAGS = -avoid-version

CC_TESTS = \
  auc_test \
  rmse_test

AM_CXXFLAGS = 
AM_CFLAGS = 

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

auc_test_SOURCES = testing/auc_test.cc 
rmse_test_SOURCES = testing/rmse_test.cc

TEST_LIB = $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(abs_top_builddir)/jml/arch/libarch.la $(abs_top_builddir)/jml/utils/libutils.la

auc_test_LDADD = $(TEST_LIB)
rmse_test_LDADD = $(TEST_LIB) 
