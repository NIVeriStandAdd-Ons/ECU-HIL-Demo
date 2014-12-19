/* Include files */
#include "mantran_mdl_demo_v14_sfun.h"
#include "c2_mantran_mdl_demo_v14.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "mantran_mdl_demo_v14_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_event_DOWN                   (0U)
#define c2_event_UP                     (2U)
#define c2_IN_NO_ACTIVE_CHILD           (0)
#define c2_IN_downshifting              (1)
#define c2_IN_fourth                    (2)
#define c2_IN_second                    (3)
#define c2_IN_third                     (4)
#define c2_IN_first                     (1)
#define c2_IN_upshifting                (3)
#define c2_IN_steady_state              (2)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_mantran_mdl_demo_v14InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_mantran_mdl_demo_v14(void);
static void initialize_params_c2_mantran_mdl_demo_v14(void);
static void enable_c2_mantran_mdl_demo_v14(void);
static void disable_c2_mantran_mdl_demo_v14(void);
static void finalize_c2_mantran_mdl_demo_v14(void);
static void sf_c2_mantran_mdl_demo_v14(void);
static void c2_chartstep_c2_mantran_mdl_demo_v14(void);
static void c2_gear_state(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static uint8_T c2__u8_u32_(uint32_T c2_b);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_mantran_mdl_demo_v14(void)
{
  real_T *c2_gear;
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_gear_state = 0U;
  chartInstance.c2_is_gear_state = 0U;
  chartInstance.c2_tp_gear_state = 0U;
  chartInstance.c2_tp_first = 0U;
  chartInstance.c2_tp_fourth = 0U;
  chartInstance.c2_tp_second = 0U;
  chartInstance.c2_tp_third = 0U;
  chartInstance.c2_is_active_selection_state = 0U;
  chartInstance.c2_is_selection_state = 0U;
  chartInstance.c2_tp_selection_state = 0U;
  chartInstance.c2_tp_downshifting = 0U;
  chartInstance.c2_tp_steady_state = 0U;
  chartInstance.c2_tp_upshifting = 0U;
  chartInstance.c2_is_active_c2_mantran_mdl_demo_v14 = 0U;
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c2_gear = 1.0;
  }
}

static void initialize_params_c2_mantran_mdl_demo_v14(void)
{
  real_T c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating data 'TWAIT' in the parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 0, 0),
   "sf_mex_get_sfun_param", &c2_d0, 0, 0, 0U, 0, 0);
  chartInstance.c2_TWAIT = (uint8_T)c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_mantran_mdl_demo_v14(void)
{
  sf_call_output_fcn_enable(chartInstance.S, 0, "CALC_TH", 0);
}

static void disable_c2_mantran_mdl_demo_v14(void)
{
  sf_call_output_fcn_disable(chartInstance.S, 0, "CALC_TH", 0);
}

static void finalize_c2_mantran_mdl_demo_v14(void)
{
}

static void sf_c2_mantran_mdl_demo_v14(void)
{
  uint8_T c2_previousEvent;
  real_T *c2_speed;
  real_T *c2_gear;
  real_T *c2_up_th;
  real_T *c2_down_th;
  c2_speed = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_up_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_down_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_speed, 4U);
  _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c2_TWAIT, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_up_th, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_down_th, 3U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_chartstep_c2_mantran_mdl_demo_v14();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_mantran_mdl_demo_v14MachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c2_chartstep_c2_mantran_mdl_demo_v14(void)
{
  uint8_T c2_previousEvent;
  uint8_T c2_b_previousEvent;
  real_T *c2_speed;
  real_T *c2_down_th;
  real_T *c2_up_th;
  real_T *c2_gear;
  c2_speed = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_up_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_down_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  if(_sfEvent_ == CALL_EVENT) {
    if(chartInstance.c2_temporalCounter_i1 < 255) {
      chartInstance.c2_temporalCounter_i1 =
        (uint8_T)(chartInstance.c2_temporalCounter_i1 + 1);
    }
  }
  if(chartInstance.c2_is_active_c2_mantran_mdl_demo_v14 == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
    chartInstance.c2_is_active_c2_mantran_mdl_demo_v14 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    chartInstance.c2_is_active_gear_state = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c2_tp_gear_state = 1U;
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,11);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
    if(chartInstance.c2_is_gear_state != 1) {
      chartInstance.c2_is_gear_state = (uint8_T)c2_IN_first;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
      chartInstance.c2_tp_first = 1U;
      *c2_gear = 1.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
    }
    chartInstance.c2_is_active_selection_state = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c2_tp_selection_state = 1U;
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,13);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
    chartInstance.c2_is_selection_state = (uint8_T)c2_IN_steady_state;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c2_tp_steady_state = 1U;
  } else {
    c2_gear_state();
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
    if(chartInstance.c2_is_active_selection_state != 0) {
      sf_call_output_fcn_call(chartInstance.S, 0, "CALC_TH", 0);
      switch(chartInstance.c2_is_selection_state) {
       case c2_IN_downshifting:
        CV_STATE_EVAL(0,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
        if(CV_TRANSITION_EVAL(1U, (_SFD_CCP_CALL(1,0,((_sfEvent_ ==
              CALL_EVENT)!=0)) != 0) && (_SFD_CCP_CALL(1,1,((chartInstance.
              c2_temporalCounter_i1 >=
              c2__u8_u32_(_SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance.c2_TWAIT,
                8U, 1U)))!=0)) != 0) && (_SFD_CCP_CALL(1,2,((
              *c2_speed <= *c2_down_th)!=0)) != 0)) != 0U != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
          sf_mex_printf("%s\\n", "DOWN");
          c2_previousEvent = _sfEvent_;
          _sfEvent_ = c2_event_DOWN;
          _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG,c2_event_DOWN);
          c2_gear_state();
          _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG,c2_event_DOWN);
          _sfEvent_ = c2_previousEvent;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
          chartInstance.c2_tp_downshifting = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
          chartInstance.c2_is_selection_state = (uint8_T)c2_IN_steady_state;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
          chartInstance.c2_tp_steady_state = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
          if(CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0,0,((*c2_speed >
               *c2_down_th)!=0))) != 0U != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
            chartInstance.c2_tp_downshifting = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
            chartInstance.c2_is_selection_state = (uint8_T)c2_IN_steady_state;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
            chartInstance.c2_tp_steady_state = 1U;
          }
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
        break;
       case c2_IN_steady_state:
        CV_STATE_EVAL(0,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
        if(chartInstance.c2_is_selection_state == 2) {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,8);
          if(CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8,0,((*c2_speed >
               *c2_up_th)!=0))) != 0U != 0) {
            if(sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions=1;
              transitionList[0] = 8;
              sf_debug_transition_conflict_check_begin();
              if(*c2_speed < *c2_down_th) {
                transitionList[numTransitions] = 10;
                numTransitions++;
              }
              sf_debug_transition_conflict_check_end();
              if(numTransitions>1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
            chartInstance.c2_tp_steady_state = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
            chartInstance.c2_is_selection_state = (uint8_T)c2_IN_upshifting;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
            chartInstance.c2_temporalCounter_i1 = 0U;
            chartInstance.c2_tp_upshifting = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,10);
            if(CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10,0,((*c2_speed <
                 *c2_down_th)!=0))) != 0U != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
              _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
              chartInstance.c2_tp_steady_state = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
              chartInstance.c2_is_selection_state = (uint8_T)c2_IN_downshifting;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
              chartInstance.c2_temporalCounter_i1 = 0U;
              chartInstance.c2_tp_downshifting = 1U;
            }
          }
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        break;
       case c2_IN_upshifting:
        CV_STATE_EVAL(0,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
        if(chartInstance.c2_is_selection_state == 3) {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
          if(CV_TRANSITION_EVAL(3U, (_SFD_CCP_CALL(3,0,((_sfEvent_ ==
                CALL_EVENT)!=0)) != 0) && (_SFD_CCP_CALL(3,1,((chartInstance.
                c2_temporalCounter_i1 >=
                c2__u8_u32_(_SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance.c2_TWAIT,
                  8U, 3U)))!=0)) != 0) && (_SFD_CCP_CALL(3,2,((
                *c2_speed >= *c2_up_th)!=0)) != 0)) != 0U != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
            sf_mex_printf("%s\\n", "UP");
            c2_b_previousEvent = _sfEvent_;
            _sfEvent_ = c2_event_UP;
            _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG,c2_event_UP);
            c2_gear_state();
            _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG,c2_event_UP);
            _sfEvent_ = c2_b_previousEvent;
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
            chartInstance.c2_tp_upshifting = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
            chartInstance.c2_is_selection_state = (uint8_T)c2_IN_steady_state;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
            chartInstance.c2_tp_steady_state = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
            if(CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4,0,((*c2_speed <
                 *c2_up_th)!=0))) != 0U != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
              _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
              chartInstance.c2_tp_upshifting = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
              chartInstance.c2_is_selection_state = (uint8_T)c2_IN_steady_state;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
              chartInstance.c2_tp_steady_state = 1U;
            }
          }
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
        break;
       default:
        CV_STATE_EVAL(0,0,0);
        chartInstance.c2_is_selection_state = (uint8_T)c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
        break;
      }
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void c2_gear_state(void)
{
  real_T *c2_gear;
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
  if(chartInstance.c2_is_active_gear_state != 0) {
    switch(chartInstance.c2_is_gear_state) {
     case c2_IN_first:
      CV_STATE_EVAL(8,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,9);
      if(CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9,0,((_sfEvent_ ==
           c2_event_UP)!=0))) != 0U != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c2_tp_first = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c2_is_gear_state = (uint8_T)c2_IN_second;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
        chartInstance.c2_tp_second = 1U;
        *c2_gear = 2.0;
        _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      break;
     case c2_IN_fourth:
      CV_STATE_EVAL(8,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,7);
      if(CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7,0,((_sfEvent_ ==
           c2_event_DOWN)!=0))) != 0U != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
        chartInstance.c2_tp_fourth = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
        chartInstance.c2_is_gear_state = (uint8_T)c2_IN_third;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
        chartInstance.c2_tp_third = 1U;
        *c2_gear = 3.0;
        _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
      break;
     case c2_IN_second:
      CV_STATE_EVAL(8,0,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
      if(chartInstance.c2_is_gear_state == 3) {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,6);
        if(CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6,0,((_sfEvent_ ==
             c2_event_UP)!=0))) != 0U != 0) {
          if(sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions=1;
            transitionList[0] = 6;
            sf_debug_transition_conflict_check_begin();
            if(_sfEvent_ == c2_event_DOWN) {
              transitionList[numTransitions] = 2;
              numTransitions++;
            }
            sf_debug_transition_conflict_check_end();
            if(numTransitions>1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
          chartInstance.c2_tp_second = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
          chartInstance.c2_is_gear_state = (uint8_T)c2_IN_third;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
          chartInstance.c2_tp_third = 1U;
          *c2_gear = 3.0;
          _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
          if(CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2,0,((_sfEvent_ ==
               c2_event_DOWN)!=0))) != 0U != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
            chartInstance.c2_tp_second = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
            chartInstance.c2_is_gear_state = (uint8_T)c2_IN_first;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
            chartInstance.c2_tp_first = 1U;
            *c2_gear = 1.0;
            _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
          }
        }
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
      break;
     case c2_IN_third:
      CV_STATE_EVAL(8,0,4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
      if(chartInstance.c2_is_gear_state == 4) {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,5);
        if(CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5,0,((_sfEvent_ ==
             c2_event_UP)!=0))) != 0U != 0) {
          if(sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions=1;
            transitionList[0] = 5;
            sf_debug_transition_conflict_check_begin();
            if(_sfEvent_ == c2_event_DOWN) {
              transitionList[numTransitions] = 12;
              numTransitions++;
            }
            sf_debug_transition_conflict_check_end();
            if(numTransitions>1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
          chartInstance.c2_tp_third = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
          chartInstance.c2_is_gear_state = (uint8_T)c2_IN_fourth;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
          chartInstance.c2_tp_fourth = 1U;
          *c2_gear = 4.0;
          _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,12);
          if(CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12,0,((_sfEvent_ ==
               c2_event_DOWN)!=0))) != 0U != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
            chartInstance.c2_tp_third = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
            chartInstance.c2_is_gear_state = (uint8_T)c2_IN_second;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
            chartInstance.c2_tp_second = 1U;
            *c2_gear = 2.0;
            _SFD_DATA_RANGE_CHECK_MIN_MAX(*c2_gear, 0U, 1.0, 4.0);
          }
        }
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      break;
     default:
      CV_STATE_EVAL(8,0,0);
      chartInstance.c2_is_gear_state = (uint8_T)c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
      break;
    }
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

const mxArray *sf_c2_mantran_mdl_demo_v14_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create(NULL, "nameCaptureInfo", 0,
    0U, 1U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static uint8_T c2__u8_u32_(uint32_T c2_b)
{
  uint8_T c2_a;
  c2_a = (uint8_T)c2_b;
  if((uint32_T)c2_a != c2_b) {
    sf_debug_overflow_detection(0U, 0U);
  }
  return c2_a;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c2_testPointAddrMap[0] = &chartInstance.c2_tp_gear_state;
  chartInstance.c2_testPointAddrMap[1] = &chartInstance.c2_tp_first;
  chartInstance.c2_testPointAddrMap[2] = &chartInstance.c2_tp_fourth;
  chartInstance.c2_testPointAddrMap[3] = &chartInstance.c2_tp_second;
  chartInstance.c2_testPointAddrMap[4] = &chartInstance.c2_tp_third;
  chartInstance.c2_testPointAddrMap[5] = &chartInstance.c2_tp_selection_state;
  chartInstance.c2_testPointAddrMap[6] = &chartInstance.c2_tp_downshifting;
  chartInstance.c2_testPointAddrMap[7] = &chartInstance.c2_tp_steady_state;
  chartInstance.c2_testPointAddrMap[8] = &chartInstance.c2_tp_upshifting;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c2_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c2_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c2_mantran_mdl_demo_v14_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(564264445U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2146076376U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(534910372U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2469629434U);
}

mxArray *sf_c2_mantran_mdl_demo_v14_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(912175934U);
    pr[1] = (double)(3809242753U);
    pr[2] = (double)(2624735244U);
    pr[3] = (double)(4251707102U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
 fullDebuggerInitialization)
{
  if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_mantran_mdl_demo_v14MachineNumber_,
         2,
         9,
         14,
         5,
         3,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_mantran_mdl_demo_v14MachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_mantran_mdl_demo_v14MachineNumber_,chartInstance.chartNumber,0);
          sf_debug_set_chart_event_thresholds(_mantran_mdl_demo_v14MachineNumber_,
           chartInstance.chartNumber,
           3,
           3,
           3);

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"speed",0,NULL);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"gear",0,NULL);
          _SFD_SET_DATA_PROPS(1,10,0,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"TWAIT",0,NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"up_th",0,NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"down_th",0,NULL);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(0,0);
          _SFD_EVENT_SCOPE(2,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,8);
          _SFD_CH_SUBSTATE_INDEX(1,0);
          _SFD_ST_SUBSTATE_COUNT(8,4);
          _SFD_ST_SUBSTATE_INDEX(8,0,1);
          _SFD_ST_SUBSTATE_INDEX(8,1,6);
          _SFD_ST_SUBSTATE_INDEX(8,2,2);
          _SFD_ST_SUBSTATE_INDEX(8,3,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,7);
          _SFD_ST_SUBSTATE_INDEX(0,1,3);
          _SFD_ST_SUBSTATE_INDEX(0,2,5);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }
        _SFD_CV_INIT_CHART(2,0,0,0);
        {
          _SFD_CV_INIT_STATE(8,4,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {14};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {14};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {12,0,19};
          static unsigned int sEndGuardMap[] = {16,17,35};
          static int sPostFixPredicateTree[] = {0,1,-3,2,-3};
          _SFD_CV_INIT_TRANS(1,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {12,0,19};
          static unsigned int sEndGuardMap[] = {16,17,33};
          static int sPostFixPredicateTree[] = {0,1,-3,2,-3};
          _SFD_CV_INIT_TRANS(3,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,&(sPostFixPredicateTree[0]));
        }
        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          _SFD_TRANS_COV_MAPS(5,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          _SFD_TRANS_COV_MAPS(6,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(9,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {2};
          _SFD_TRANS_COV_MAPS(9,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(11,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(11,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          _SFD_TRANS_COV_MAPS(7,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          _SFD_TRANS_COV_MAPS(12,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {4};
          _SFD_TRANS_COV_MAPS(2,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(13,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(13,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {14};
          _SFD_TRANS_COV_MAPS(8,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(10,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          _SFD_TRANS_COV_MAPS(10,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {14};
          _SFD_TRANS_COV_MAPS(4,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(0,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(1,0,3,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {12,0,19};
          static unsigned int sEndGuardMap[] = {16,17,35};
          _SFD_TRANS_COV_MAPS(1,
           0,NULL,NULL,
           3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(3,0,3,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {12,0,19};
          static unsigned int sEndGuardMap[] = {16,17,33};
          _SFD_TRANS_COV_MAPS(3,
           0,NULL,NULL,
           3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }

        {
          real_T *c2_speed;
          real_T *c2_gear;
          real_T *c2_up_th;
          real_T *c2_down_th;
          c2_speed = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_up_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_down_th = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_speed);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_gear);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c2_TWAIT);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_up_th);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_down_th);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_mantran_mdl_demo_v14MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_mantran_mdl_demo_v14(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_mantran_mdl_demo_v14();
  initialize_c2_mantran_mdl_demo_v14();
}

static void sf_opaque_enable_c2_mantran_mdl_demo_v14(void *chartInstanceVar)
{
  enable_c2_mantran_mdl_demo_v14();
}

static void sf_opaque_disable_c2_mantran_mdl_demo_v14(void *chartInstanceVar)
{
  disable_c2_mantran_mdl_demo_v14();
}

static void sf_opaque_gateway_c2_mantran_mdl_demo_v14(void *chartInstanceVar)
{
  sf_c2_mantran_mdl_demo_v14();
}

static void sf_opaque_terminate_c2_mantran_mdl_demo_v14(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_mantran_mdl_demo_v14();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mantran_mdl_demo_v14(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_mantran_mdl_demo_v14();
  }
}

static void mdlSetWorkWidths_c2_mantran_mdl_demo_v14(SimStruct *S)
{
  /* Actual parameters from chart:
     TWAIT 
   */
  const char_T *rtParamNames[] = {"p1"};

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  /* registration for TWAIT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);

  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("mantran_mdl_demo_v14",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("mantran_mdl_demo_v14",2,"gatewayCannotBeInlinedMultipleTimes"));
    sf_mark_output_events_with_multiple_callers(S,"mantran_mdl_demo_v14",2,1);
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"mantran_mdl_demo_v14",2,3);
      sf_mark_chart_reusable_outputs(S,"mantran_mdl_demo_v14",2,1);
    }
    sf_set_rtw_dwork_info(S,"mantran_mdl_demo_v14",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3645365236U));
  ssSetChecksum1(S,(2423545149U));
  ssSetChecksum2(S,(964550729U));
  ssSetChecksum3(S,(3710013676U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_mantran_mdl_demo_v14(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "mantran_mdl_demo_v14", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_mantran_mdl_demo_v14(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_mantran_mdl_demo_v14;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
    init_dsm_address_info();
  }
  chart_debug_initialization(S,1);
}

void c2_mantran_mdl_demo_v14_method_dispatcher(SimStruct *S, int_T method, void
 *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_mantran_mdl_demo_v14(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mantran_mdl_demo_v14(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mantran_mdl_demo_v14(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_mantran_mdl_demo_v14_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  {"uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0}};

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  {NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0}};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  {rtwCAPI_SCALAR, 0, 2}};

static const uint_T dimensionArray[] = {
  1, 1};

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  {&sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0}
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  {0, 0, "StateflowChart/gear_state", "gear_state", 0, 0, 0, 0, 0},
  {1, 0, "StateflowChart/gear_state.first", "first", 0, 0, 0, 0, 0},
  {2, 0, "StateflowChart/gear_state.fourth", "fourth", 0, 0, 0, 0, 0},
  {3, 0, "StateflowChart/gear_state.second", "second", 0, 0, 0, 0, 0},
  {4, 0, "StateflowChart/gear_state.third", "third", 0, 0, 0, 0, 0},
  {5, 0, "StateflowChart/selection_state", "selection_state", 0, 0, 0, 0, 0},
  {6, 0, "StateflowChart/selection_state.downshifting", "downshifting", 0, 0, 0,
    0, 0},
  {7, 0, "StateflowChart/selection_state.steady_state", "steady_state", 0, 0, 0,
    0, 0},
  {8, 0, "StateflowChart/selection_state.upshifting", "upshifting", 0, 0, 0, 0,
    0}};

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                   /* Block signals Array  */
    9                                   /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                               /* Block parameters Array    */
    0,                                  /* Num block parameters      */
    NULL,                               /* Variable parameters Array */
    0                                   /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                               /* Block States array        */
    0                                   /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                        /* Data Type Map            */
    dimensionMap,                       /* Data Dimension Map       */
    fixedPointMap,                      /* Fixed Point Map          */
    NULL,                               /* Structure Element map    */
    sampleTimeMap,                      /* Sample Times Map         */
    dimensionArray                      /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S) {
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;

  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();

  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);

  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}

