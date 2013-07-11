/* exception_internals.h                                           -*- C++ -*-
   Jeremy Barnes, 18 October 2010
   Copyright (c) 2010 Datacratic.  All rights reserved.

   Internals needed to interoperate with the exception handling.  These are
   copied from the libsupc++ sources, but contain no functionality, only
   definitions.
*/

#ifndef __jml__arch__exception_internals_h__
#define __jml__arch__exception_internals_h__

#include <typeinfo>
#include <exception>
#include <cstddef>
#include <unwind.h>

#ifdef __clang__
#ifdef __cplusplus
extern "C" {
#endif

#define __unwind_word__ word

/* Level 1: Base ABI  */

/* @@@ The IA-64 ABI uses uint64 throughout.  Most places this is
   inefficient for 32-bit and smaller machines.  */
typedef unsigned _Unwind_Word __attribute__((__mode__(__unwind_word__)));
typedef signed _Unwind_Sword __attribute__((__mode__(__unwind_word__)));
#if defined(__ia64__) && defined(__hpux__)
typedef unsigned _Unwind_Ptr __attribute__((__mode__(__word__)));
#else
typedef unsigned _Unwind_Ptr __attribute__((__mode__(__pointer__)));
#endif
typedef unsigned _Unwind_Internal_Ptr __attribute__((__mode__(__pointer__)));

/* @@@ The IA-64 ABI uses a 64-bit word to identify the producer and
   consumer of an exception.  We'll go along with this for now even on
   32-bit machines.  We'll need to provide some other option for
   16-bit machines and for machines with > 8 bits per byte.  */
typedef unsigned _Unwind_Exception_Class __attribute__((__mode__(__DI__)));

/* The unwind interface uses a pointer to an exception header object
   as its representation of an exception being thrown. In general, the
   full representation of an exception object is language- and
   implementation-specific, but it will be prefixed by a header
   understood by the unwind interface.  */

struct _Unwind_Exception;

typedef void (*_Unwind_Exception_Cleanup_Fn) (_Unwind_Reason_Code,
					      struct _Unwind_Exception *);

struct _Unwind_Exception
{
  _Unwind_Exception_Class exception_class;
  _Unwind_Exception_Cleanup_Fn exception_cleanup;
  _Unwind_Word private_1;
  _Unwind_Word private_2;

  /* @@@ The IA-64 ABI says that this structure must be double-word aligned.
     Taking that literally does not make much sense generically.  Instead we
     provide the maximum alignment required by any type for the machine.  */
} __attribute__((__aligned__));

#ifdef __cplusplus
}
#endif
#endif

namespace __cxxabiv1 {

// A C++ exception object consists of a header, which is a wrapper around
// an unwind object header with additional C++ specific information,
// followed by the exception object itself.

struct __cxa_exception
{ 
  // Manage the exception object itself.
  std::type_info *exceptionType;
  void (*exceptionDestructor)(void *); 

  // The C++ standard has entertaining rules wrt calling set_terminate
  // and set_unexpected in the middle of the exception cleanup process.
  std::unexpected_handler unexpectedHandler;
  std::terminate_handler terminateHandler;

  // The caught exception stack threads through here.
  __cxa_exception *nextException;

  // How many nested handlers have caught this exception.  A negated
  // value is a signal that this object has been rethrown.
  int handlerCount;

  // Cache parsed handler data from the personality routine Phase 1
  // for Phase 2 and __cxa_call_unexpected.
  int handlerSwitchValue;
  const unsigned char *actionRecord;
  const unsigned char *languageSpecificData;
  _Unwind_Ptr catchTemp;
  void *adjustedPtr;

  // The generic exception header.  Must be last.
  _Unwind_Exception unwindHeader;
};

struct __cxa_eh_globals
{
  __cxa_exception *caughtExceptions;
  unsigned int uncaughtExceptions;
};

extern "C" __cxa_eh_globals *__cxa_get_globals () throw();

} // __cxxabiv1


#endif /* __jml__arch__exception_internals_h__ */
