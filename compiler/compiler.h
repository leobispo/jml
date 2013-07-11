/* compiler.h                                                      -*- C++ -*-
   Jeremy Barnes, 1 February 2005
   Copyright (c) 2005 Jeremy Barnes.  All rights reserved.

   This file is part of "Jeremy's Machine Learning Library", copyright (c)
   1999-2005 Jeremy Barnes.
   
   This program is available under the GNU General Public License, the terms
   of which are given by the file "license.txt" in the top level directory of
   the source code distribution.  If this file is missing, you have no right
   to use the program; please contact the author.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   ---

   Compiler detection, etc.
*/

#ifndef __compiler__compiler_h__
#define __compiler__compiler_h__

#ifdef __CUDACC__
# define JML_COMPILER_NVCC 1
#endif

#define JML_ALWAYS_INLINE __attribute__((__always_inline__)) inline 
#define JML_NORETURN __attribute__((__noreturn__))
#define JML_UNUSED  __attribute__((__unused__))
#define JML_PACKED  __attribute__((__packed__))
#define JML_PURE_FN __attribute__((__pure__))
#define JML_CONST_FN __attribute__((__const__))
#define JML_WEAK_FN __attribute__((__weak__))
#define JML_LIKELY(x) __builtin_expect((x), true)
#define JML_UNLIKELY(x) __builtin_expect((x), false)
#define JML_DEPRECATED __attribute__((__deprecated__))
#define JML_ALIGNED(x) __attribute__((__aligned__(x)))
#define JML_FORMAT_STRING(arg1, arg2) __attribute__((__format__ (printf, arg1, arg2)))

#ifdef __clang__
#include <xmmintrin.h>

#define __builtin_ia32_loadupd _mm_loadu_pd
#define __builtin_ia32_loadups _mm_loadu_ps
#define __builtin_ia32_addps _mm_add_ps
#define __builtin_ia32_addsd _mm_add_sd
#define __builtin_ia32_addpd _mm_add_pd
#define __builtin_ia32_addss _mm_add_ss
#define __builtin_ia32_paddb128 _mm_add_epi8
#define __builtin_ia32_paddw128 _mm_add_epi16
#define __builtin_ia32_paddd128 _mm_add_epi32
#define __builtin_ia32_paddq128 _mm_add_epi64
#define __builtin_ia32_subps _mm_sub_ps
#define __builtin_ia32_subsd _mm_sub_sd
#define __builtin_ia32_subpd _mm_sub_pd
#define __builtin_ia32_subss _mm_sub_ss
#define __builtin_ia32_psubb128 _mm_sub_epi8
#define __builtin_ia32_psubw128 _mm_sub_epi16
#define __builtin_ia32_psubd128 _mm_sub_epi32
#define __builtin_ia32_psubq128 _mm_sub_epi64
#define __builtin_ia32_mulsd _mm_mul_sd
#define __builtin_ia32_mulpd _mm_mul_pd
#define __builtin_ia32_mulps _mm_mul_ps
#define __builtin_ia32_mulss _mm_mul_ss
#define __builtin_ia32_pmullw128 _mm_mullo_epi16
#define __builtin_ia32_divsd _mm_div_sd
#define __builtin_ia32_divpd _mm_div_pd
#define __builtin_ia32_divps _mm_div_ps
#define __builtin_ia32_divss _mm_div_ss
#define __builtin_ia32_andpd _mm_and_pd
#define __builtin_ia32_andps _mm_and_ps
#define __builtin_ia32_pand128 _mm_and_si128
#define __builtin_ia32_andnpd _mm_andnot_pd
#define __builtin_ia32_andnps _mm_andnot_ps
#define __builtin_ia32_pandn128 _mm_andnot_si128
#define __builtin_ia32_orpd _mm_or_pd
#define __builtin_ia32_orps _mm_or_ps
#define __builtin_ia32_por128 _mm_or_si128
#define __builtin_ia32_xorpd _mm_xor_pd
#define __builtin_ia32_xorps _mm_xor_ps
#define __builtin_ia32_pxor128 _mm_xor_si128
#define __builtin_ia32_cvtps2dq _mm_cvtps_epi32
#define __builtin_ia32_cvtsd2ss _mm_cvtsd_ss
#define __builtin_ia32_cvtsi2sd _mm_cvtsi32_sd
#define __builtin_ia32_cvtss2sd _mm_cvtss_sd
#define __builtin_ia32_cvttsd2si _mm_cvttsd_si32
#define __builtin_ia32_vec_ext_v2df _mm_cvtsd_f64
#define __builtin_ia32_loadhpd _mm_loadh_pd
#define __builtin_ia32_loadlpd _mm_loadl_pd
#define __builtin_ia32_loadlv4si _mm_loadl_epi64
#define __builtin_ia32_cmpeqps _mm_cmpeq_ps
#define __builtin_ia32_cmpltps _mm_cmplt_ps
#define __builtin_ia32_cmpleps _mm_cmple_ps
#define __builtin_ia32_cmpgtps _mm_cmpgt_ps
#define __builtin_ia32_cmpgeps _mm_cmpge_ps
#define __builtin_ia32_cmpunordps _mm_cmpunord_ps
#define __builtin_ia32_cmpneqps _mm_cmpneq_ps
#define __builtin_ia32_cmpnltps _mm_cmpnlt_ps
#define __builtin_ia32_cmpnleps _mm_cmpnle_ps
#define __builtin_ia32_cmpngtps _mm_cmpngt_ps
#define __builtin_ia32_cmpordps _mm_cmpord_ps
#define __builtin_ia32_cmpeqss _mm_cmpeq_ss
#define __builtin_ia32_cmpltss _mm_cmplt_ss
#define __builtin_ia32_cmpless _mm_cmple_ss
#define __builtin_ia32_cmpunordss _mm_cmpunord_ss
#define __builtin_ia32_cmpneqss _mm_cmpneq_ss
#define __builtin_ia32_cmpnltss _mm_cmpnlt_ss
#define __builtin_ia32_cmpnless _mm_cmpnle_ss
#define __builtin_ia32_cmpngtss _mm_cmpngt_ss
#define __builtin_ia32_cmpngess _mm_cmpnge_ss
#define __builtin_ia32_cmpordss _mm_cmpord_ss
#define __builtin_ia32_movss _mm_move_ss
#define __builtin_ia32_movsd _mm_move_sd
#define __builtin_ia32_movhlps _mm_movehl_ps
#define __builtin_ia32_movlhps _mm_movelh_ps
#define __builtin_ia32_movqv4si _mm_move_epi64
#define __builtin_ia32_unpckhps _mm_unpackhi_ps
#define __builtin_ia32_unpckhpd _mm_unpackhi_pd
#define __builtin_ia32_punpckhbw128 _mm_unpackhi_epi8
#define __builtin_ia32_punpckhwd128 _mm_unpackhi_epi16
#define __builtin_ia32_punpckhdq128 _mm_unpackhi_epi32
#define __builtin_ia32_punpckhqdq128 _mm_unpackhi_epi64
#define __builtin_ia32_unpcklps _mm_unpacklo_ps
#define __builtin_ia32_unpcklpd _mm_unpacklo_pd
#define __builtin_ia32_punpcklbw128 _mm_unpacklo_epi8
#define __builtin_ia32_punpcklwd128 _mm_unpacklo_epi16
#define __builtin_ia32_punpckldq128 _mm_unpacklo_epi32
#define __builtin_ia32_punpcklqdq128 _mm_unpacklo_epi64
#define __builtin_ia32_cmpeqpd _mm_cmpeq_pd
#define __builtin_ia32_cmpltpd _mm_cmplt_pd
#define __builtin_ia32_cmplepd _mm_cmple_pd
#define __builtin_ia32_cmpgtpd _mm_cmpgt_pd
#define __builtin_ia32_cmpgepd _mm_cmpge_pd
#define __builtin_ia32_cmpunordpd _mm_cmpunord_pd
#define __builtin_ia32_cmpneqpd _mm_cmpneq_pd
#define __builtin_ia32_cmpnltpd _mm_cmpnlt_pd
#define __builtin_ia32_cmpnlepd _mm_cmpnle_pd
#define __builtin_ia32_cmpngtpd _mm_cmpngt_pd
#define __builtin_ia32_cmpngepd _mm_cmpnge_pd
#define __builtin_ia32_cmpordpd _mm_cmpord_pd
#define __builtin_ia32_cmpeqsd _mm_cmpeq_sd
#define __builtin_ia32_cmpltsd _mm_cmplt_sd
#define __builtin_ia32_cmplesd _mm_cmple_sd
#define __builtin_ia32_cmpunordsd _mm_cmpunord_sd
#define __builtin_ia32_cmpneqsd _mm_cmpneq_sd
#define __builtin_ia32_cmpnltsd _mm_cmpnlt_sd
#define __builtin_ia32_cmpnlesd _mm_cmpnle_sd
#define __builtin_ia32_cmpordsd _mm_cmpord_sd
#define __builtin_ia32_cvtsi642ss _mm_cvtsi64_ss
#define __builtin_ia32_cvttss2si64 _mm_cvtss_si64
#define __builtin_ia32_shufps _mm_shuffle_ps
#define __builtin_ia32_shufpd _mm_shuffle_pd
#define __builtin_ia32_pshufhw _mm_shufflehi_epi16
#define __builtin_ia32_pshuflw _mm_shufflelo_epi16
#define __builtin_ia32_pshufd _mm_shuffle_epi32
#define __builtin_ia32_movshdup _mm_movehdup_ps
#define __builtin_ia32_movsldup _mm_moveldup_ps
#define __builtin_ia32_maxps _mm_max_ps
#define __builtin_ia32_pslldi128 _mm_slli_epi32
#define __builtin_ia32_vec_set_v16qi _mm_insert_epi8
#define __builtin_ia32_vec_set_v8hi _mm_insert_epi16
#define __builtin_ia32_vec_set_v4si _mm_insert_epi32
#define __builtin_ia32_vec_set_v2di _mm_insert_epi64
#define __builtin_ia32_vec_set_v4hi _mm_insert_pi16
#define __builtin_ia32_vec_ext_v16qi _mm_extract_epi8
#define __builtin_ia32_vec_ext_v8hi _mm_extract_epi16
#define __builtin_ia32_vec_ext_v4si _mm_extract_epi32
#define __builtin_ia32_vec_ext_v2di _mm_extract_epi64
#define __builtin_ia32_vec_ext_v4hi _mm_extract_pi16
#define __builtin_ia32_vec_ext_v4sf _mm_extract_ps
#endif

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#  define jml_typeof(x) decltype(x)
#  define JML_HAS_RVALUE_REFERENCES 1
#else
#  define jml_typeof(x) typeof(x)
#endif

#ifdef JML_COMPILER_NVCC
# define JML_COMPUTE_METHOD __device__ __host__
# undef  JML_LIKELY
# define JML_LIKELY(x) x
# undef  JML_UNLIKELY
# define JML_UNLIKELY(x) x

#if 0 // CUDA 2.1 only
// Required so that nvcc works with optimization on under CUDA 2.1, GCC 4.3.3
static __typeof__(int (pthread_t)) __gthrw_pthread_cancel __attribute__((__alias__("pthread_cancel"))); 
#endif

#else
# define JML_COMPUTE_METHOD 
#endif

#ifdef __CUDACC__
# define JML_COMPILER_NVCC 1
#endif

#endif /* __compiler__compiler_h__ */
