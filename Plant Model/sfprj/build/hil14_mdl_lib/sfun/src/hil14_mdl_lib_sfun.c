/* Include files */
#include "hil14_mdl_lib_sfun.h"
#include "c2_hil14_mdl_lib.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hil14_mdl_libMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void hil14_mdl_lib_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void hil14_mdl_lib_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hil14_mdl_lib_method_dispatcher(SimStruct *simstructPtr,
 unsigned int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==2) {
    c2_hil14_mdl_lib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_hil14_mdl_lib_process_check_sum_call( int nlhs, mxArray *
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
  if(nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if(!strcmp(machineName,"hil14_mdl_lib")){
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3973006670U);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1521634273U);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(808408290U);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3252158869U);
      }else{
        return 0;
      }
    }
  }else {
    return 0;
  }

  return 1;
#else
  return 0;
#endif
}

unsigned int sf_hil14_mdl_lib_autoinheritance_info( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
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
        extern mxArray *sf_c2_hil14_mdl_lib_get_autoinheritance_info(void);
        plhs[0] = sf_c2_hil14_mdl_lib_get_autoinheritance_info();
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
unsigned int sf_hil14_mdl_lib_get_eml_resolved_functions_info( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
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
        *sf_c2_hil14_mdl_lib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c2_hil14_mdl_lib_get_eml_resolved_functions_info();
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
void hil14_mdl_lib_debug_initialize(void)
{
  _hil14_mdl_libMachineNumber_ =
  sf_debug_initialize_machine("hil14_mdl_lib","sfun",1,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_hil14_mdl_libMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_hil14_mdl_libMachineNumber_,0);
}

void hil14_mdl_lib_register_exported_symbols(SimStruct* S)
{
}
