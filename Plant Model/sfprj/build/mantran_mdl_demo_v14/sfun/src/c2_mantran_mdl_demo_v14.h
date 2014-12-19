#ifndef __c2_mantran_mdl_demo_v14_h__
#define __c2_mantran_mdl_demo_v14_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */

typedef struct {
  SimStruct *S;
  void *c2_testPointAddrMap[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c2_TWAIT;
  uint8_T c2_is_active_c2_mantran_mdl_demo_v14;
  uint8_T c2_is_active_gear_state;
  uint8_T c2_is_active_selection_state;
  uint8_T c2_is_gear_state;
  uint8_T c2_is_selection_state;
  uint8_T c2_temporalCounter_i1;
  uint8_T c2_tp_downshifting;
  uint8_T c2_tp_first;
  uint8_T c2_tp_fourth;
  uint8_T c2_tp_gear_state;
  uint8_T c2_tp_second;
  uint8_T c2_tp_selection_state;
  uint8_T c2_tp_steady_state;
  uint8_T c2_tp_third;
  uint8_T c2_tp_upshifting;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
} SFc2_mantran_mdl_demo_v14InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c2_mantran_mdl_demo_v14_get_eml_resolved_functions_info(void);

/* Function Definitions */

extern void sf_c2_mantran_mdl_demo_v14_get_check_sum(mxArray *plhs[]);
extern void c2_mantran_mdl_demo_v14_method_dispatcher(SimStruct *S, int_T
 method, void *data);

#endif

