ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

neural_include_HEADERS = \
  auto_encoder.h \
  auto_encoder_stack.h \
  auto_encoder_trainer.h \
  backprop_cuda.h \
  dense_layer.h \
  dense_layer_impl.h \
  dense_shared_reverse_layer.h \
  dense_shared_reverse_layer_impl.h \
  discriminative_trainer.h \
  layer.h \
  layer_stack.h \
  layer_stack_impl.h \
  loss_function.h \
  output_encoder.h \
  parameters.h \
  parameters_impl.h \
  perceptron_defs.h \
  perceptron_generator.h \
  perceptron.h \
  reconstruct_layer_adaptor.h \
  reverse_layer_adaptor.h \
  transfer_function.h \
  twoway_layer.h

neural_includedir = $(includedir)/jml/neural

lib_LTLIBRARIES = libneural.la

libneural_la_LDFLAGS = -avoid-version
libneural_la_SOURCES = \
 perceptron.cc \
 perceptron_defs.cc \
 layer.cc \
 dense_layer.cc \
 perceptron_generator.cc \
 parameters.cc \
 transfer_function.cc \
 layer_stack.cc \
 discriminative_trainer.cc \
 auto_encoder.cc \
 auto_encoder_stack.cc \
 twoway_layer.cc \
 auto_encoder_trainer.cc \
 reverse_layer_adaptor.cc \
 reconstruct_layer_adaptor.cc \
 output_encoder.cc


libneural_la_LIBADD = \
  $(BOOST_SYSTEM_LIB) \
  $(abs_top_builddir)/jml/judy/libjudy.la \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/db/libdb.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(abs_top_builddir)/jml/algebra/libalgebra.la \
  $(abs_top_builddir)/jml/boosting/libboosting.la \
  $(abs_top_builddir)/jml/stats/libstats.la

if HAVE_CUDA
noinst_LIBRARIES = libneural_cuda_st.a
libneural_cuda_st_a_SOURCES = \
  backprop_cuda.cu

lib_LTLIBRARIES += libneural_cuda.la
libneural_cuda_la_LIBADD = libneural.la libneural_cuda_st.a
libneural_cuda_la_LDFLAGS = -avoid-version
libneural_cuda_la_SOURCES =

.cu.o:
	$(NVCC) -o $@ -c $< $(NVCCFLAGS) $(AM_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) -Xcompiler "$(CXXFLAGS)"
endif

AM_CXXFLAGS = 
AM_CFLAGS = 

CC_TESTS = \
  parameters_test \
  dense_layer_test \
  layer_stack_test \
  discriminative_trainer_test \
  output_encoder_test
#  twoway_layer_test
#  perceptron_test

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

check_PROGRAMS = $(CC_TESTS)

TEST_LIB = \
  $(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
  $(BOOST_SYSTEM_LIB) \
  $(abs_top_builddir)/jml/judy/libjudy.la \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/db/libdb.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(abs_top_builddir)/jml/algebra/libalgebra.la \
  $(abs_top_builddir)/jml/boosting/libboosting.la \
  $(abs_top_builddir)/jml/stats/libstats.la \
  libneural.la

parameters_test_SOURCES = testing/parameters_test.cc
dense_layer_test_SOURCES = testing/dense_layer_test.cc
layer_stack_test_SOURCES = testing/layer_stack_test.cc
discriminative_trainer_test_SOURCES = testing/discriminative_trainer_test.cc
output_encoder_test_SOURCES = testing/output_encoder_test.cc
#twoway_layer_test_SOURCES = testing/twoway_layer_test.cc
#perceptron_test_SOURCES = testing/perceptron_test.cc

parameters_test_LDADD = $(TEST_LIB)
dense_layer_test_LDADD = $(TEST_LIB)
layer_stack_test_LDADD = $(TEST_LIB)
discriminative_trainer_test_LDADD = $(TEST_LIB)
output_encoder_test_LDADD = $(TEST_LIB)
#twoway_layer_test_LDADD = $(TEST_LIB)
#perceptron_test_LDADD = $(TEST_LIB)
