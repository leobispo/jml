ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) -I .. $(BOOST_CPPFLAGS)

utils_include_HEADERS = \
  abort.h \
  boost_fixes.h \
  check_not_nan.h \
  circular_buffer.h \
  compact_vector.h \
  configuration.h \
  csv.h \
  enum_info.h \
  environment.h \
  exc_assert.h \
  exc_check.h \
  fast_float_parsing.h \
  fast_int_parsing.h \
  file_functions.h \
  filter_streams.h \
  fixed_array.h \
  floating_point.h \
  float_traits.h \
  guard.h \
  hash.h \
  hash_map.h \
  hash_set.h \
  hash_specializations.h \
  hex_dump.h \
  info.h \
  json_parsing.h \
  less.h \
  lightweight_hash.h \
  lzma.h \
  map_reduce.h \
  move.h \
  multi_array_utils.h \
  pair_utils.h \
  parse_context.h \
  positioned_types.h \
  profile.h \
  ring_buffer.h \
  rng.h \
  set_utils.h \
  sgi_algorithm.h \
  sgi_functional.h \
  sgi_numeric.h \
  smart_ptr_utils.h \
  sorted_vector.h \
  string_functions.h \
  unnamed_bool.h \
  vector_utils.h \
  worker_task.h

utils_includedir = $(includedir)/jml/utils

lib_LTLIBRARIES = libutils.la libworker_task.la

libutils_la_LDFLAGS = -avoid-version

libutils_la_SOURCES = \
  abort.cc \
  configuration.cc \
  csv.cc \
  environment.cc \
  exc_assert.cc \
  exc_check.cc \
  file_functions.cc \
  filter_streams.cc \
  floating_point.cc \
  hash.cc \
  hex_dump.cc \
  json_parsing.cc \
  lzma.cc \
  parse_context.cc \
  rng.cc \
  string_functions.cc

libworker_task_la_LDFLAGS = -avoid-version
libworker_task_la_SOURCES = worker_task.cc

libutils_la_LIBADD = \
  $(LZMA_LIB) \
  $(CRYPTO_LIB) \
  $(BOOST_SYSTEM_LIB) \
  $(BOOST_IOSTREAMS_LIB) \
  $(BOOST_THREAD_LIB) \
  $(abs_top_builddir)/jml/arch/libarch.la 

libworker_task_la_LIBADD = $(libutils_la_LIBADD) $(ACE_LIB)

AM_CXXFLAGS = 
AM_CFLAGS = 

CC_TESTS = \
  circular_buffer_test \
  compact_vector_test \
  configuration_test \
  csv_parsing_test \
  environment_test \
  filter_streams_test \
  lightweight_hash_test \
  parse_context_test
#  worker_task_test

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

circular_buffer_test_SOURCES = testing/circular_buffer_test.cc
compact_vector_test_SOURCES = testing/compact_vector_test.cc
configuration_test_SOURCES = testing/configuration_test.cc
csv_parsing_test_SOURCES = testing/csv_parsing_test.cc
environment_test_SOURCES = testing/environment_test.cc
filter_streams_test_SOURCES = testing/filter_streams_test.cc
lightweight_hash_test_SOURCES = testing/lightweight_hash_test.cc
parse_context_test_SOURCES = testing/parse_context_test.cc
#worker_task_test_SOURCES = testing/worker_task_test.cc

TEST_LIB = $(BOOST_THREAD_LIB) \
  $(BOOST_LDFLAGS) \
  $(BOOST_IOSTREAMS_LIB) \
  $(BOOST_SYSTEM_LIB) \
  $(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
  libutils.la \
  $(abs_top_builddir)/jml/arch/libarch.la 

circular_buffer_test_LDADD = $(TEST_LIB)
compact_vector_test_LDADD = $(TEST_LIB)
configuration_test_LDADD = $(TEST_LIB)
csv_parsing_test_LDADD = $(TEST_LIB)
environment_test_LDADD = $(TEST_LIB)
filter_streams_test_LDADD = $(TEST_LIB)
lightweight_hash_test_LDADD = $(TEST_LIB)
parse_context_test_LDADD = $(TEST_LIB)
#worker_task_test_LDADD = $(TEST_LIB) libworker_task.la
