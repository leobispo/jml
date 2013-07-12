ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

arch_include_HEADERS = \
  arch.h \
  atomic_init.h \
  atomic_ops.h \
  backtrace.h \
  bitops.h \
  bit_range_ops.h \
  cache.h \
  cmp_xchg.h \
  cpuid.h \
  cpu_info.h \
  cuda.h \
  demangle.h \
  exception.h \
  exception_handler.h \
  exception_hook.h \
  exception_internals.h \
  format.h \
  futex.h \
  gpgpu.h \
  info.h \
  integer.h \
  math_builtins.h \
  math.h \
  rt.h \
  rtti_utils.h \
  rusage.h \
  rwlock.h \
  simd.h \
  simd_vector.h \
  spinlock.h \
  sse2_exp.h \
  sse2.h \
  sse2_log.h \
  sse2_math.h \
  sse2_misc.h \
  sse2_poly.h \
  sse.h \
  threads.h \
  thread_specific.h \
  tick_counter.h \
  timers.h \
  vm.h \
  wakeup_fd.h

arch_includedir = $(includedir)/jml/arch

noinst_LTLIBRARIES = libsimdvector.la

libsimdvector_la_SOURCES = simd_vector.cc

if !HAVE_CLANG
libsimdvector_la_CXXFLAGS = -funsafe-loop-optimizations -Wunsafe-loop-optimizations
endif

lib_LTLIBRARIES = libarch.la libexception_hook.la libnode_exception_tracing.la

libarch_la_LDFLAGS = -avoid-version
libarch_la_SOURCES = \
  demangle.cc \
  tick_counter.cc \
  cpuid.cc \
  simd.cc \
  exception.cc \
  backtrace.cc \
  format.cc \
  exception_handler.cc \
  gpgpu.cc \
  environment_static.cc \
  cpu_info.cc \
  vm.cc \
  info.cc \
  rtti_utils.cc \
  rt.cc

libarch_la_LIBADD = libsimdvector.la $(BOOST_SYSTEM_LIB)

if HAVE_CUDA
lib_LTLIBRARIES += libarch_cuda.la
libarch_cuda_la_LIBADD = libarch.la
libarch_cuda_la_LDFLAGS = -avoid-version
libarch_cuda_la_SOURCES = cuda.cc
endif

if HAVE_CAL
lib_LTLIBRARIES += libarch_cal.la
libarch_cal_la_LIBADD = libarch.la
libarch_cal_la_LDFLAGS = -avoid-version -lamd
libarch_cal_la_SOURCES = cal.cc
endif

libexception_hook_la_LDFLAGS = -avoid-version
libexception_hook_la_LIBADD = $(BOOST_SYSTEM_LIB)
libexception_hook_la_SOURCES = exception_hook.cc

libnode_exception_tracing_la_LDFLAGS = -avoid-version
libnode_exception_tracing_la_LIBADD = $(BOOST_SYSTEM_LIB)
libnode_exception_tracing_la_SOURCES = node_exception_tracing.cc

CC_TESTS = \
  bitops_test \
  cpuid_test \
  simd_test \
  cmp_xchg_test \
  simd_vector_test \
  backtrace_test \
  atomic_ops_test \
  sse2_math_test \
  vm_test \
  info_test \
  rtti_utils_test
#  bit_range_ops_test
#  tick_counter_test

AM_CXXFLAGS = 
AM_CFLAGS = 

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

#tick_counter_test_SOURCES = testing/tick_counter_test.cc
bitops_test_SOURCES = testing/bitops_test.cc
cpuid_test_SOURCES = testing/cpuid_test.cc
simd_test_SOURCES = testing/simd_test.cc
cmp_xchg_test_SOURCES = testing/cmp_xchg_test.cc
simd_vector_test_SOURCES = testing/simd_vector_test.cc
backtrace_test_SOURCES = testing/backtrace_test.cc
#bit_range_ops_test_SOURCES = testing/bit_range_ops_test.cc
atomic_ops_test_SOURCES = testing/atomic_ops_test.cc
sse2_math_test_SOURCES = testing/sse2_math_test.cc
vm_test_SOURCES = testing/vm_test.cc
info_test_SOURCES = testing/info_test.cc
rtti_utils_test_SOURCES = testing/rtti_utils_test.cc

TEST_LIB = $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_THREAD_LIB) libarch.la 
#tick_counter_test_LDADD = $(TEST_LIB)
bitops_test_LDADD = $(TEST_LIB)
cpuid_test_LDADD = $(TEST_LIB)
simd_test_LDADD = $(TEST_LIB)
cmp_xchg_test_LDADD = $(TEST_LIB)
simd_vector_test_LDADD = $(TEST_LIB)
backtrace_test_LDADD = $(TEST_LIB)
#bit_range_ops_test_LDADD = $(TEST_LIB)
atomic_ops_test_LDADD = $(TEST_LIB)
sse2_math_test_LDADD = $(TEST_LIB)
vm_test_LDADD = $(TEST_LIB)
info_test_LDADD = $(TEST_LIB)
rtti_utils_test_LDADD = $(TEST_LIB)
