ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -I $(abs_top_builddir)

judy_include_HEADERS = \
  Judy.h

judy_includedir = $(includedir)/jml/judy

lib_LTLIBRARIES = libjudy.la

libjudy_la_LDFLAGS = -avoid-version

libjudy_la_SOURCES = \
  JudyLByCount.cc \
  JudyLCreateBranch.cc \
  JudyLCascade.cc \
  JudyLCount.cc \
  judy_malloc_allocator.cc \
  JudyLDecascade.cc \
  JudyLDel.cc \
  JudyLFirst.cc \
  JudyLFreeArray.cc \
  JudyLGet.cc \
  JudyLIns.cc \
  JudyLInsArray.cc \
  JudyLInsertBranch.cc \
  JudyLMallocIF.cc \
  JudyLMemActive.cc \
  JudyLMemUsed.cc \
  JudyLNext.cc \
  JudyLNextEmpty.cc \
  JudyLPrev.cc \
  JudyLPrevEmpty.cc \
  JudyLTables.cc \
  JudyLTablesGen.cc \
  j__udyLGet.cc
