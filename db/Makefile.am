ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

db_include_HEADERS = \
  compact_size_types.h \
  nested_archive.h \
  persistent_fwd.h \
  persistent.h \
  portable_iarchive.h \
  portable_oarchive.h \
  serialization_order.h

db_includedir = $(includedir)/jml/db

lib_LTLIBRARIES = libdb.la

libdb_la_SOURCES = \
  compact_size_types.cc \
  nested_archive.cc \
  portable_iarchive.cc \
  portable_oarchive.cc

libdb_la_LDFLAGS = -avoid-version
libdb_la_LIBADD = $(BOOST_SYSTEM_LIB) $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(abs_top_builddir)/jml/arch/libarch.la $(abs_top_builddir)/jml/utils/libutils.la

CC_TESTS = \
  compact_size_type_test \
  serialize_reconstitute_test

AM_CXXFLAGS = 
AM_CFLAGS = 

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

compact_size_type_test_SOURCES = testing/compact_size_type_test.cc 
serialize_reconstitute_test_SOURCES = testing/serialize_reconstitute_test.cc

TEST_LIB =  $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(abs_top_builddir)/jml/arch/libarch.la $(abs_top_builddir)/jml/utils/libutils.la libdb.la
compact_size_type_test_LDADD = $(TEST_LIB)
serialize_reconstitute_test_LDADD = $(TEST_LIB)
