ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

math_include_HEADERS = \
  bound.h \
  metrics.h \
  round.h \
  xdiv.h

math_includedir = $(includedir)/jml/math

CC_TESTS = roundtest

LDADD = $(BOOST_UNIT_TEST_FRAMEWORK_LIB)

AM_CXXFLAGS = 
AM_CFLAGS = 

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

roundtest_SOURCES = testing/round_test.cc
