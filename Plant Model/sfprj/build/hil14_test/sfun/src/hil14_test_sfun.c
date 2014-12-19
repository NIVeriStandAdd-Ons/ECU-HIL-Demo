/* Include files */
#include "hil14_test_sfun.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _hil14_testMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void hil14_test_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void hil14_test_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hil14_test_method_dispatcher(SimStruct *simstructPtr, unsigned
 int chartFileNumber, int_T method, void *data)
{
  return 0;
}
unsigned int sf_hil14_test_process_check_sum_call( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(469333674U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3868312603U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2928290567U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2122778324U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2777529849U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1565034280U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2813709473U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4034742153U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(643529248U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1058096195U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3308740155U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3053004113U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3288671175U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1435522493U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(884743672U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2595184104U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_hil14_test_autoinheritance_info( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
unsigned int sf_hil14_test_get_eml_resolved_functions_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0])) return 0;
  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_eml_resolved_functions_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void hil14_test_debug_initialize(void)
{
  _hil14_testMachineNumber_ =
  sf_debug_initialize_machine("hil14_test","sfun",0,0,0,0,0);
  sf_debug_set_machine_event_thresholds(_hil14_testMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_hil14_testMachineNumber_,0);
}

void hil14_test_register_exported_symbols(SimStruct* S)
{
}
