/* Include files */
#include "mantran_mdl_demo_v14_sfun.h"
#include "c2_mantran_mdl_demo_v14.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _mantran_mdl_demo_v14MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void mantran_mdl_demo_v14_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void mantran_mdl_demo_v14_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_mantran_mdl_demo_v14_method_dispatcher(SimStruct *simstructPtr,
 unsigned int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==2) {
    c2_mantran_mdl_demo_v14_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_mantran_mdl_demo_v14_process_check_sum_call( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3498640823U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2147538737U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2205284071U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3738490464U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(973294070U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3880933462U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804996426U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2339115267U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 2:
        {
          extern void sf_c2_mantran_mdl_demo_v14_get_check_sum(mxArray *plhs[]);
          sf_c2_mantran_mdl_demo_v14_get_check_sum(plhs);
          break;
        }

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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(758670769U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2394082695U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1667441623U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(975805067U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_mantran_mdl_demo_v14_autoinheritance_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern mxArray
        *sf_c2_mantran_mdl_demo_v14_get_autoinheritance_info(void);
        plhs[0] = sf_c2_mantran_mdl_demo_v14_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
unsigned int sf_mantran_mdl_demo_v14_get_eml_resolved_functions_info( int nlhs,
 mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern const mxArray
        *sf_c2_mantran_mdl_demo_v14_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c2_mantran_mdl_demo_v14_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void mantran_mdl_demo_v14_debug_initialize(void)
{
  _mantran_mdl_demo_v14MachineNumber_ =
    sf_debug_initialize_machine("mantran_mdl_demo_v14","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_mantran_mdl_demo_v14MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_mantran_mdl_demo_v14MachineNumber_,0);
}

void mantran_mdl_demo_v14_register_exported_symbols(SimStruct* S)
{
}
