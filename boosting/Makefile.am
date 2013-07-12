ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir) $(BOOST_CPPFLAGS)

boosting_include_HEADERS = \
  bagging_generator.h \
  binary_symmetric.h \
  bit_compressed_index.h \
  boolean_expression.h \
  boosted_stumps_core.h \
  boosted_stumps_generator.h \
  boosted_stumps.h \
  boosted_stumps_impl.h \
  boosting_core.h \
  boosting_core_parallel.h \
  boosting_generator.h \
  boosting_training.h \
  buckets.h \
  classifier_generator.h \
  classifier.h \
  classifier_mlp_averager.h \
  classifier_mlp.h \
  classifier_persist_impl.h \
  committee.h \
  config.h \
  config_impl.h \
  config_options.h \
  data_aliases.h \
  dataset_functions.h \
  decision_tree_generator.h \
  decision_tree.h \
  decoded_classifier.h \
  decoder.h \
  dense_features.h \
  dual_float_accum.h \
  early_stopping_generator.h \
  evaluation.h \
  feature.h \
  feature_info.h \
  feature_map.h \
  feature_set_filter.h \
  feature_set.h \
  feature_space.h \
  feature_transformer.h \
  feature_transform.h \
  fixed_point_accum.h \
  glz_classifier_generator.h \
  glz_classifier.h \
  judy_array.h \
  judy_multi_array.h \
  judy_trie.h \
  label.h \
  memusage.h \
  naive_bayes_generator.h \
  naive_bayes.h \
  null_classifier_generator.h \
  null_classifier.h \
  null_decoder.h \
  null_feature_space.h \
  probabilizer.h \
  registry.h \
  sparse_features.h \
  split_fwd.h \
  split.h \
  stump_accum.h \
  stump_generator.h \
  stump.h \
  stump_predict.h \
  stump_regress.h \
  stump_training_bin.h \
  stump_training_core.h \
  stump_training_cuda.h \
  stump_training.h \
  stump_training_multi.h \
  stump_training_parallel.h \
  thread_context.h \
  training_data.h \
  training_index_entry.h \
  training_index.h \
  training_index_iterators.h \
  training_index_iterators_impl.h \
  training_params.h \
  transformed_classifier.h \
  transform_list.h \
  tree.h \
  weighted_training.h \
  weight_updating_generator.h

boosting_includedir = $(includedir)/jml/boosting

lib_LTLIBRARIES = libboosting.la libboosting_tools.la

libboosting_la_LDFLAGS = -avoid-version
libboosting_la_SOURCES = \
  boosted_stumps.cc \
  classifier.cc \
  data_aliases.cc \
  decoded_classifier.cc \
  decision_tree.cc \
  null_feature_space.cc \
  decoder.cc \
  dense_features.cc \
  evaluation.cc \
  feature_info.cc \
  feature_set.cc \
  feature_space.cc \
  glz_classifier.cc \
  naive_bayes.cc \
  null_classifier.cc \
  null_decoder.cc \
  probabilizer.cc \
  sparse_features.cc \
  stump.cc \
  training_data.cc \
  training_index.cc \
  training_index_entry.cc \
  weighted_training.cc \
  transformed_classifier.cc \
  stump_training.cc \
  config_options.cc \
  stump_regress.cc \
  boosted_stumps_generator.cc \
  bagging_generator.cc \
  boosting_generator.cc \
  naive_bayes_generator.cc \
  decision_tree_generator.cc \
  feature_transformer.cc \
  glz_classifier_generator.cc \
  classifier_generator.cc \
  stump_generator.cc \
  binary_symmetric.cc \
  early_stopping_generator.cc \
  stump_training_bin.cc \
  feature_transform.cc \
  transform_list.cc \
  committee.cc \
  boosting_training.cc \
  null_classifier_generator.cc \
  tree.cc \
  split.cc \
  training_index_iterators.cc \
  feature.cc \
  bit_compressed_index.cc \
  label.cc \
  buckets.cc

libboosting_la_LIBADD = \
  $(BOOST_SYSTEM_LIB) \
  $(abs_top_builddir)/jml/judy/libjudy.la \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/db/libdb.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(abs_top_builddir)/jml/algebra/libalgebra.la

libboosting_tools_la_LIBADD = \
  $(abs_top_builddir)/jml/judy/libjudy.la \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/db/libdb.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(abs_top_builddir)/jml/algebra/libalgebra.la \
  libboosting.la \
  $(BOOST_SYSTEM_LIB) \
  $(BOOST_REGEX_LIB)

if HAVE_CUDA
noinst_LIBRARIES = libboosting_cuda_st.a
libboosting_cuda_st_a_SOURCES = \
  stump_training_cuda.cu \
  stump_training_cuda_packed.cu

lib_LTLIBRARIES += libboosting_cuda.la
libboosting_cuda_la_LIBADD = libboosting.la libboosting_cuda_st.a
libboosting_cuda_la_LDFLAGS = -avoid-version
libboosting_cuda_la_SOURCES = \
  stump_training_cuda_host.cc

.cu.o:
	$(NVCC) -o $@ -c $< $(NVCCFLAGS) $(AM_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) -Xcompiler "$(CXXFLAGS)"
endif

boosting_tools_include_HEADERS = \
  tools/boosting_tool_common.h \
  tools/datasets.h

boosting_tools_includedir = $(includedir)/jml/boosting/tools

libboosting_tools_la_LDFLAGS = -avoid-version
libboosting_tools_la_SOURCES = \
  tools/boosting_tool_common.cc \
  tools/datasets.cc

AM_CXXFLAGS = 
AM_CFLAGS = 

CC_TESTS = \
  decision_tree_xor_test \
  split_test \
  decision_tree_multithreaded_test \
  decision_tree_unlimited_depth_test \
  glz_classifier_test \
  probabilizer_test \
  feature_info_test \
  dataset_nan_test

TESTS = $(CC_TESTS)

TESTS_ENVIRONMENT = $(abs_top_builddir)/test_driver.sh

bin_PROGRAMS = classifier_training_tool training_data_tool

classifier_training_tool_SOURCES = tools/classifier_training_tool.cc
classifier_training_tool_LDADD = \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  libboosting.la \
  libboosting_tools.la \
  $(BOOST_SYSTEM_LIB) \
  $(BOOST_REGEX_LIB) \
  $(BOOST_PROGRAM_OPTIONS_LIB)

training_data_tool_SOURCES = tools/training_data_tool.cc
training_data_tool_LDADD = \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  libboosting.la \
  libboosting_tools.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la \
  $(BOOST_SYSTEM_LIB) \
  $(BOOST_REGEX_LIB) \
  $(BOOST_PROGRAM_OPTIONS_LIB)

check_PROGRAMS = $(CC_TESTS)

decision_tree_xor_test_SOURCES = testing/decision_tree_xor_test.cc
split_test_SOURCES = testing/split_test.cc
decision_tree_multithreaded_test_SOURCES = testing/decision_tree_multithreaded_test.cc
decision_tree_unlimited_depth_test_SOURCES = testing/decision_tree_unlimited_depth_test.cc
glz_classifier_test_SOURCES = testing/glz_classifier_test.cc
probabilizer_test_SOURCES = testing/probabilizer_test.cc
feature_info_test_SOURCES = testing/feature_info_test.cc
dataset_nan_test_SOURCES = testing/dataset_nan_test.cc

TEST_LIB = $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(BOOST_SYSTEM_LIB) \
  $(abs_top_builddir)/jml/arch/libarch.la \
  $(abs_top_builddir)/jml/utils/libutils.la \
  libboosting.la \
  $(abs_top_builddir)/jml/utils/libworker_task.la

decision_tree_xor_test_LDADD = $(TEST_LIB) 
split_test_LDADD = $(TEST_LIB)
decision_tree_multithreaded_test_LDADD = $(TEST_LIB)
decision_tree_unlimited_depth_test_LDADD = $(TEST_LIB)
glz_classifier_test_LDADD = $(TEST_LIB)
probabilizer_test_LDADD = $(TEST_LIB)
feature_info_test_LDADD = $(TEST_LIB)
dataset_nan_test_LDADD = $(TEST_LIB) libboosting_tools.la libboosting.la $(BOOST_REGEX_LIB) $(BOOST_UNIT_TEST_FRAMEWORK_LIB) $(BOOST_SYSTEM_LIB)
