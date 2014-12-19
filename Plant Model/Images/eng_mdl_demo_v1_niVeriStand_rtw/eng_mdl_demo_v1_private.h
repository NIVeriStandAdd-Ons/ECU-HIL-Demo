/*
 * eng_mdl_demo_v1_private.h
 *
 * Real-Time Workshop code generation for Simulink model "eng_mdl_demo_v1.mdl".
 *
 * Model Version              : 1.181
 * Real-Time Workshop version : 7.0.1  (R2007b+)  21-Apr-2008
 * C source code generated on : Fri Jun 20 12:10:01 2014
 */
#ifndef RTW_HEADER_eng_mdl_demo_v1_private_h_
#define RTW_HEADER_eng_mdl_demo_v1_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* private model entry point functions */
extern void eng_mdl_demo_v1_derivatives(void);
void BINARYSEARCH_real_T( uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void Look2D_real_T_real_T_real_T_SAT( real_T *pY, const real_T *pYData, real_T
  u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data,
  uint32_T iHiU1);

#endif                                 /* RTW_HEADER_eng_mdl_demo_v1_private_h_ */
