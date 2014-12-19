#ifndef __hil14_test_sfun_h__
#define __hil14_test_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                 sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "sfcdebug.h"

#define rtInf                           (mxGetInf())
#define rtMinusInf                      (-(mxGetInf()))
#define rtNaN                           (mxGetNaN())
#define rtIsNaN(X) ((int)mxIsNaN(X))
#define rtIsInf(X) ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                      (MAX_uint8_T)

/* Variable Declarations */
extern uint8_T _sfEvent_;
extern uint32_T _hil14_testMachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
void hil14_test_initializer(void);
void hil14_test_terminator(void);

/* Function Definitions */

#endif

