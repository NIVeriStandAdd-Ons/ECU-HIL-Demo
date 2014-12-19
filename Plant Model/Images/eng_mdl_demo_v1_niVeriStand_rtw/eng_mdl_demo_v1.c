/*
 * eng_mdl_demo_v1.c
 *
 * Real-Time Workshop code generation for Simulink model "eng_mdl_demo_v1.mdl".
 *
 * Model Version              : 1.181
 * Real-Time Workshop version : 7.0.1  (R2007b+)  21-Apr-2008
 * C source code generated on : Fri Jun 20 12:10:01 2014
 */

#include "eng_mdl_demo_v1.h"
#include "eng_mdl_demo_v1_private.h"

/* Block signals (auto storage) */
BlockIO_eng_mdl_demo_v1 eng_mdl_demo_v1_B;

/* Continuous states */
ContinuousStates_eng_mdl_demo_v eng_mdl_demo_v1_X;

/* Solver Matrices */

/* A and B matrices used by ODE3 fixed-step solver */
static const real_T rt_ODE3_A[3] = {
  1.0/2.0, 3.0/4.0, 1.0
};

static const real_T rt_ODE3_B[3][3] = {
  { 1.0/2.0, 0.0, 0.0 },

  { 0.0, 3.0/4.0, 0.0 },

  { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
};

/* Block states (auto storage) */
D_Work_eng_mdl_demo_v1 eng_mdl_demo_v1_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_eng_mdl_demo_v1 eng_mdl_demo_v1_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_eng_mdl_demo_v1 eng_mdl_demo_v1_Y;

/* Real-time model */
RT_MODEL_eng_mdl_demo_v1 eng_mdl_demo_v1_M_;
RT_MODEL_eng_mdl_demo_v1 *eng_mdl_demo_v1_M = &eng_mdl_demo_v1_M_;

/*********************************************************************
 * Lookup Binary Search Utility BINARYSEARCH_real_T
 */
void BINARYSEARCH_real_T( uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1 ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* end macro BINARYSEARCH_real_T
 *********************************************************************/

/*********************************************************************
 * Lookup 2D Lookup Utility Look2D_real_T_real_T_real_T_SAT
 */
void Look2D_real_T_real_T_real_T_SAT( real_T *pY, const real_T *pYData, real_T
  u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data,
  uint32_T iHiU1)
{
  uint32_T iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_real_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_real_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    real_T u0Left = pU0Data[iLeftU0];
    real_T u0Rght = pU0Data[iRghtU0];
    real_T u1Left = pU1Data[iLeftU1];
    real_T u1Rght = pU1Data[iRghtU1];
    real_T yTemp;
    real_T yLeftLeft;
    real_T yLeftRght;
    real_T yRghtLeft;
    real_T yRghtRght;
    real_T u1Lambda;
    real_T u0Lambda;
    if (u1Rght > u1Left ) {
      real_T num;
      real_T den;
      den = u1Rght;
      den = den - u1Left;
      num = u1;
      num = num - u1Left;
      u1Lambda = num / den;
    } else {
      u1Lambda = 0;
    }

    if (u0Rght > u0Left ) {
      real_T num;
      real_T den;
      den = u0Rght;
      den = den - u0Left;
      num = u0;
      num = num - u0Left;
      u0Lambda = num / den;
    } else {
      u0Lambda = 0;
    }

    iHiU0++;
    iLeftU1 *= iHiU0;
    iRghtU1 *= iHiU0;
    yRghtLeft = pYData[(iRghtU0+iLeftU1)];
    yRghtRght = pYData[(iRghtU0+iRghtU1)];
    yLeftLeft = pYData[(iLeftU0+iLeftU1)];
    yLeftRght = pYData[(iLeftU0+iRghtU1)];

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the left u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yLeftLeft;
      yRghtCast = yLeftRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yRghtLeft;
      yRghtCast = yRghtRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      yTemp = yLeftCast;
    }

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (*pY);
      yRghtCast = yTemp;
      yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/* end function Look2D_real_T_real_T_real_T_SAT
 *********************************************************************/

/* This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  eng_mdl_demo_v1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  eng_mdl_demo_v1_output(0);
  eng_mdl_demo_v1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE3_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  eng_mdl_demo_v1_output(0);
  eng_mdl_demo_v1_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE3_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void eng_mdl_demo_v1_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Product;
  real_T rtb_Product1_m;
  real_T rtb_SpringTorque;
  real_T rtb_Nettorque;
  real_T rtb_Sum_cb;
  real_T rtb_Product1_p;
  real_T rtb_Switch;
  real_T rtb_MultiportSwitch;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(eng_mdl_demo_v1_M)) {
    eng_mdl_demo_v1_M->Timing.t[0] = rtsiGetT(&eng_mdl_demo_v1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&eng_mdl_demo_v1_M->solverInfo,
                          ((eng_mdl_demo_v1_M->Timing.clockTick0+1)*
      eng_mdl_demo_v1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Integrator: '<S12>/p0 = amb.p//10 bar' */
  if (eng_mdl_demo_v1_X.p0ambp10bar_CSTATE >=
      eng_mdl_demo_v1_P.p0ambp10bar_UpperSat ) {
    eng_mdl_demo_v1_X.p0ambp10bar_CSTATE =
      eng_mdl_demo_v1_P.p0ambp10bar_UpperSat;
  } else if (eng_mdl_demo_v1_X.p0ambp10bar_CSTATE <=
             eng_mdl_demo_v1_P.p0ambp10bar_LowerSat ) {
    eng_mdl_demo_v1_X.p0ambp10bar_CSTATE =
      eng_mdl_demo_v1_P.p0ambp10bar_LowerSat;
  }

  rtb_Sum_cb = eng_mdl_demo_v1_X.p0ambp10bar_CSTATE;

  /* Integrator: '<S3>/Integrator' */
  rtb_Product1_p = eng_mdl_demo_v1_X.Integrator_CSTATE;

  /* Lookup2D Block: '<S12>/volumetric efficiency'
   * About '<S12>/volumetric efficiency :'
   * Lookup2D Block: '<S12>/volumetric efficiency'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Saturation Mode: Saturate
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0


   */
  Look2D_real_T_real_T_real_T_SAT( &(eng_mdl_demo_v1_B.volumetricefficiency),
    eng_mdl_demo_v1_P.volumetricefficiency_Table, rtb_Sum_cb,
    eng_mdl_demo_v1_P.volumetricefficiency_RowIdx, 16U, rtb_Product1_p,
    eng_mdl_demo_v1_P.volumetricefficiency_ColIdx, 15U);

  /* Gain: '<S12>/ideal air mass//cycle (g)' */
  eng_mdl_demo_v1_B.idealairmasscycleg =
    eng_mdl_demo_v1_P.idealairmasscycleg_Gain *
    eng_mdl_demo_v1_B.volumetricefficiency;

  /* Product: '<S12>/Product' incorporates:
   *  Gain: '<S12>/1//(4*pi)'
   */
  rtb_Product = eng_mdl_demo_v1_P.upi_Gain * rtb_Product1_p *
    eng_mdl_demo_v1_B.idealairmasscycleg;

  /* Outport: '<Root>/MANF::MAF (g//s)' */
  eng_mdl_demo_v1_Y.MANFMAFgs = rtb_Product;

  /* Outport: '<Root>/MANF::MAP(bar)' */
  eng_mdl_demo_v1_Y.MANFMAPbar = rtb_Sum_cb;

  /* Outport: '<Root>/MANF::APC(g)' */
  eng_mdl_demo_v1_Y.MANFAPCg = eng_mdl_demo_v1_B.idealairmasscycleg;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<Root>/Gain1' */
  eng_mdl_demo_v1_B.Gain1 = eng_mdl_demo_v1_P.Gain1_Gain * rtb_Product1_p;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Lookup2D Block: '<S1>/combustion efficiency'
     * About '<S1>/combustion efficiency :'
     * Lookup2D Block: '<S1>/combustion efficiency'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0


     */
    Look2D_real_T_real_T_real_T_SAT( &(eng_mdl_demo_v1_B.combustionefficiency),
      eng_mdl_demo_v1_P.combustionefficiency_Table, eng_mdl_demo_v1_P.phi1_Value,
      eng_mdl_demo_v1_P.combustionefficiency_RowIdx, 2U, 0.0,
      eng_mdl_demo_v1_P.combustionefficiency_ColIdx, 1U);
  }

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<Root>/phi'
   *  Gain: '<S1>/Stoichiometric Fuel'
   */
  eng_mdl_demo_v1_B.fuelmassg = eng_mdl_demo_v1_P.StoichiometricFuel_Gain *
    eng_mdl_demo_v1_B.idealairmasscycleg * eng_mdl_demo_v1_P.phi_Value;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S3>/Gain' incorporates:
   *  Constant: '<S1>/thermodynamic efficiency'
   *  Fcn: '<S1>/ideal chem->mech conversion'
   *  Gain: '<S3>/Gain2'
   *  Product: '<S1>/Product1'
   *  Sum: '<S3>/Sum'
   */
  eng_mdl_demo_v1_B.Gain = (eng_mdl_demo_v1_B.fuelmassg * 0.001 * 42700000.0 /
    1.2566370614359172E+001 * eng_mdl_demo_v1_B.combustionefficiency *
    eng_mdl_demo_v1_P.thermodynamicefficiency_Value -
    eng_mdl_demo_v1_P.Gain2_Gain * rtb_Product1_p) * eng_mdl_demo_v1_P.Gain_Gain;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Fcn: '<S13>/f(theta)' incorporates:
     *  Constant: '<Root>/TPS'
     */
    eng_mdl_demo_v1_B.ftheta = (((0.2821 - 0.052310000000000002 *
      eng_mdl_demo_v1_P.TPS_Value) + 0.10299 * eng_mdl_demo_v1_P.TPS_Value *
      eng_mdl_demo_v1_P.TPS_Value) - 0.00063000000000000003 *
      eng_mdl_demo_v1_P.TPS_Value * eng_mdl_demo_v1_P.TPS_Value *
      eng_mdl_demo_v1_P.TPS_Value) * 0.59999999999999998;
  }

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<Root>/ENV::Baro (kPa)'
   */
  rtb_Product1_p = rtb_Sum_cb / eng_mdl_demo_v1_P.ENVBarokPa_Value;

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<Root>/ENV::Baro (kPa)'
   */
  rtb_Switch = 1.0 / rtb_Sum_cb * eng_mdl_demo_v1_P.ENVBarokPa_Value;

  /* MinMax: '<S13>/MinMax' */
  rtb_Switch = rt_MIN(rtb_Product1_p, rtb_Switch);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Sonic Flow '
   *  Fcn: '<S13>/g(pratio)'
   */
  if (rtb_Switch >= eng_mdl_demo_v1_P.Switch_Threshold) {
    rtb_Switch = sqrt(rtb_Switch - rtb_Switch * rtb_Switch) * 2.0;
  } else {
    rtb_Switch = eng_mdl_demo_v1_P.SonicFlow_Value;
  }

  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<Root>/ENV::Baro (kPa)'
   */
  rtb_Sum_cb = eng_mdl_demo_v1_P.ENVBarokPa_Value - rtb_Sum_cb;

  /* Product: '<S13>/Product' incorporates:
   *  Signum: '<S13>/flow direction'
   */
  eng_mdl_demo_v1_B.Product = eng_mdl_demo_v1_B.ftheta * rtb_Switch * rt_SGN
    (rtb_Sum_cb);

  /* Gain: '<S12>/im.RT_over_V' incorporates:
   *  Sum: '<S12>/Sum'
   */
  eng_mdl_demo_v1_B.imRT_over_V = (eng_mdl_demo_v1_B.Product - rtb_Product) *
    eng_mdl_demo_v1_P.imRT_over_V_Gain;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToWorkspace: '<S12>/To Workspace1' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK.LoggedData),
                    &eng_mdl_demo_v1_B.imRT_over_V, 0);

    /* ToWorkspace: '<S12>/To Workspace4' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK.LoggedData),
                    &eng_mdl_demo_v1_B.volumetricefficiency, 0);

    /* UnitDelay: '<S2>/Unit Delay2' */
    eng_mdl_demo_v1_B.UnitDelay2 = eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE;

    /* Sum: '<S11>/Add1' incorporates:
     *  Constant: '<S2>/Alpha'
     *  Inport: '<Root>/ETC::Motor Duty Cycle (%)'
     *  Product: '<S11>/Product2'
     *  Sum: '<S11>/Add'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    eng_mdl_demo_v1_B.DC = (eng_mdl_demo_v1_U.ETCMotorDutyCycle -
      eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE) * eng_mdl_demo_v1_P.Alpha_Value +
      eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE;

    /* Product: '<S6>/Product1' incorporates:
     *  Constant: '<Root>/Vbatt(Vdc)'
     *  Constant: '<S2>/Kt//R'
     */
    rtb_Product1_m = eng_mdl_demo_v1_P.KtR_Value * eng_mdl_demo_v1_B.DC *
      eng_mdl_demo_v1_P.VbattVdc_Value;

    /* Lookup: '<S2>/SpringTorque' incorporates:
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    rtb_SpringTorque = rt_Lookup(&eng_mdl_demo_v1_P.SpringTorque_XData[0], 15,
      eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g,
      &eng_mdl_demo_v1_P.SpringTorque_YData[0]);

    /* Product: '<S2>/Product1' incorporates:
     *  Constant: '<S2>/Damping Const'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtb_MultiportSwitch = eng_mdl_demo_v1_P.DampingConst_Value *
      eng_mdl_demo_v1_DWork.UnitDelay_DSTATE;

    /* Sum: '<S2>/Add' */
    rtb_Nettorque = (rtb_Product1_m - rtb_SpringTorque) - rtb_MultiportSwitch;

    /* Logic: '<S5>/Logical Operator1' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     *  RelationalOperator: '<S8>/Compare'
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    rtb_LogicalOperator1 = ((rtb_Nettorque <= eng_mdl_demo_v1_P.Constant_Value) &&
                            (eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g <=
      eng_mdl_demo_v1_P.Constant_Value_c));

    /* Logic: '<S5>/Logical Operator2' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S9>/Constant'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S9>/Compare'
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    rtb_LogicalOperator2 = ((eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g ==
      eng_mdl_demo_v1_P.Constant_Value_n) && (rtb_Nettorque >=
      eng_mdl_demo_v1_P.Constant_Value_f));

    /* Logic: '<S5>/Logical Operator' */
    eng_mdl_demo_v1_B.LogicalOperator = (rtb_LogicalOperator1 ||
      rtb_LogicalOperator2);

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    if (eng_mdl_demo_v1_B.LogicalOperator &&
        (eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE =
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator_IC;
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator =
        eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE;
    } else {
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator =
        eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE;
    }

    if (eng_mdl_demo_v1_B.LogicalOperator) {
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese = 1;
    } else {
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese = 0;
    }

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    eng_mdl_demo_v1_B.DiscreteTimeIntegrator1 =
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE;
    if (eng_mdl_demo_v1_B.DiscreteTimeIntegrator1 >=
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_UpperSa) {
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator1 =
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (eng_mdl_demo_v1_B.DiscreteTimeIntegrator1 <=
               eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_LowerSa) {
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator1 =
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_LowerSa;
    }

    /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    if (eng_mdl_demo_v1_B.LogicalOperator == 0) {
      rtb_MultiportSwitch = rtb_Nettorque;
    } else {
      rtb_MultiportSwitch = eng_mdl_demo_v1_P.Constant4_Value;
    }

    /* Product: '<S2>/Product2' incorporates:
     *  Constant: '<S2>/Inertia'
     */
    eng_mdl_demo_v1_B.Product2 = rtb_MultiportSwitch /
      eng_mdl_demo_v1_P.Inertia_Value;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void eng_mdl_demo_v1_update(int_T tid)
{
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S2>/Unit Delay2' */
    eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE =
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator1;

    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE = eng_mdl_demo_v1_B.DC;

    /* Update for UnitDelay: '<S2>/Unit Delay1' */
    eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g =
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator1;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    eng_mdl_demo_v1_DWork.UnitDelay_DSTATE =
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator;

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE =
      eng_mdl_demo_v1_P.DiscreteTimeIntegrator_gainval *
      eng_mdl_demo_v1_B.Product2 +
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
      eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_gainval *
      eng_mdl_demo_v1_B.DiscreteTimeIntegrator +
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE;
    if (eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE >=
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_UpperSa) {
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE <=
               eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_LowerSa) {
      eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
        eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M)) {
    rt_ertODEUpdateContinuousStates(&eng_mdl_demo_v1_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++eng_mdl_demo_v1_M->Timing.clockTick0))
    ++eng_mdl_demo_v1_M->Timing.clockTickH0;
  eng_mdl_demo_v1_M->Timing.t[0] = eng_mdl_demo_v1_M->Timing.clockTick0 *
    eng_mdl_demo_v1_M->Timing.stepSize0 + eng_mdl_demo_v1_M->Timing.clockTickH0 *
    eng_mdl_demo_v1_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(eng_mdl_demo_v1_M) &&
      eng_mdl_demo_v1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++eng_mdl_demo_v1_M->Timing.clockTick1))
      ++eng_mdl_demo_v1_M->Timing.clockTickH1;
    eng_mdl_demo_v1_M->Timing.t[1] = eng_mdl_demo_v1_M->Timing.clockTick1 *
      eng_mdl_demo_v1_M->Timing.stepSize1 +
      eng_mdl_demo_v1_M->Timing.clockTickH1 *
      eng_mdl_demo_v1_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void eng_mdl_demo_v1_derivatives(void)
{
  /* Limited Integrator Block: '<S12>/p0 = amb.p//10 bar' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( eng_mdl_demo_v1_X.p0ambp10bar_CSTATE <=
            eng_mdl_demo_v1_P.p0ambp10bar_LowerSat );
    usat = ( eng_mdl_demo_v1_X.p0ambp10bar_CSTATE >=
            eng_mdl_demo_v1_P.p0ambp10bar_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (eng_mdl_demo_v1_B.imRT_over_V > 0)) ||
        (usat && (eng_mdl_demo_v1_B.imRT_over_V < 0)) ) {
      ((StateDerivatives_eng_mdl_demo_v *) eng_mdl_demo_v1_M->ModelData.derivs
        )->p0ambp10bar_CSTATE = eng_mdl_demo_v1_B.imRT_over_V;
    } else {
      /* in saturation */
      ((StateDerivatives_eng_mdl_demo_v *) eng_mdl_demo_v1_M->ModelData.derivs
        )->p0ambp10bar_CSTATE = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S3>/Integrator' */
  ((StateDerivatives_eng_mdl_demo_v *) eng_mdl_demo_v1_M->ModelData.derivs)
    ->Integrator_CSTATE = eng_mdl_demo_v1_B.Gain;
}

/* Model initialize function */
void eng_mdl_demo_v1_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)eng_mdl_demo_v1_M,0,
                sizeof(RT_MODEL_eng_mdl_demo_v1));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&eng_mdl_demo_v1_M->solverInfo,
                          &eng_mdl_demo_v1_M->Timing.simTimeStep);
    rtsiSetTPtr(&eng_mdl_demo_v1_M->solverInfo, &rtmGetTPtr(eng_mdl_demo_v1_M));
    rtsiSetStepSizePtr(&eng_mdl_demo_v1_M->solverInfo,
                       &eng_mdl_demo_v1_M->Timing.stepSize0);
    rtsiSetdXPtr(&eng_mdl_demo_v1_M->solverInfo,
                 &eng_mdl_demo_v1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&eng_mdl_demo_v1_M->solverInfo,
                         &eng_mdl_demo_v1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&eng_mdl_demo_v1_M->solverInfo,
      &eng_mdl_demo_v1_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&eng_mdl_demo_v1_M->solverInfo, (&rtmGetErrorStatus
      (eng_mdl_demo_v1_M)));
    rtsiSetRTModelPtr(&eng_mdl_demo_v1_M->solverInfo, eng_mdl_demo_v1_M);
  }

  rtsiSetSimTimeStep(&eng_mdl_demo_v1_M->solverInfo, MAJOR_TIME_STEP);
  eng_mdl_demo_v1_M->ModelData.intgData.y = eng_mdl_demo_v1_M->ModelData.odeY;
  eng_mdl_demo_v1_M->ModelData.intgData.f[0] = eng_mdl_demo_v1_M->
    ModelData.odeF[0];
  eng_mdl_demo_v1_M->ModelData.intgData.f[1] = eng_mdl_demo_v1_M->
    ModelData.odeF[1];
  eng_mdl_demo_v1_M->ModelData.intgData.f[2] = eng_mdl_demo_v1_M->
    ModelData.odeF[2];
  eng_mdl_demo_v1_M->ModelData.contStates = ((real_T *) &eng_mdl_demo_v1_X);
  rtsiSetSolverData(&eng_mdl_demo_v1_M->solverInfo, (void *)
                    &eng_mdl_demo_v1_M->ModelData.intgData);
  rtsiSetSolverName(&eng_mdl_demo_v1_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = eng_mdl_demo_v1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    eng_mdl_demo_v1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    eng_mdl_demo_v1_M->Timing.sampleTimes =
      (&eng_mdl_demo_v1_M->Timing.sampleTimesArray[0]);
    eng_mdl_demo_v1_M->Timing.offsetTimes =
      (&eng_mdl_demo_v1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    eng_mdl_demo_v1_M->Timing.sampleTimes[0] = (0.0);
    eng_mdl_demo_v1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    eng_mdl_demo_v1_M->Timing.offsetTimes[0] = (0.0);
    eng_mdl_demo_v1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(eng_mdl_demo_v1_M, &eng_mdl_demo_v1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = eng_mdl_demo_v1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    eng_mdl_demo_v1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(eng_mdl_demo_v1_M, 100.0);
  eng_mdl_demo_v1_M->Timing.stepSize0 = 0.001;
  eng_mdl_demo_v1_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    eng_mdl_demo_v1_M->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(eng_mdl_demo_v1_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(eng_mdl_demo_v1_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(eng_mdl_demo_v1_M->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(eng_mdl_demo_v1_M->rtwLogInfo, "rt_");
    rtliSetLogT(eng_mdl_demo_v1_M->rtwLogInfo, "tout");
    rtliSetLogX(eng_mdl_demo_v1_M->rtwLogInfo, "");
    rtliSetLogXFinal(eng_mdl_demo_v1_M->rtwLogInfo, "");
    rtliSetSigLog(eng_mdl_demo_v1_M->rtwLogInfo, "");
    rtliSetLogXSignalInfo(eng_mdl_demo_v1_M->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(eng_mdl_demo_v1_M->rtwLogInfo, NULL);
    rtliSetLogY(eng_mdl_demo_v1_M->rtwLogInfo, "yout");

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &eng_mdl_demo_v1_Y.MANFMAFgs,
        &eng_mdl_demo_v1_Y.MANFMAPbar,
        &eng_mdl_demo_v1_Y.MANFAPCg
      };

      rtliSetLogYSignalPtrs(eng_mdl_demo_v1_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        NULL,
        NULL,
        NULL
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "eng_mdl_demo_v1/MANF::MAF (g//s)",
        "eng_mdl_demo_v1/MANF::MAP(bar)",
        "eng_mdl_demo_v1/MANF::APC(g)" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          NULL,

          { rt_LoggedOutputLabels },
          NULL,
          NULL,
          NULL,

          { rt_LoggedOutputBlockNames },

          { NULL },
          NULL,
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(eng_mdl_demo_v1_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }
  }

  eng_mdl_demo_v1_M->solverInfoPtr = (&eng_mdl_demo_v1_M->solverInfo);
  eng_mdl_demo_v1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&eng_mdl_demo_v1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&eng_mdl_demo_v1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  eng_mdl_demo_v1_M->ModelData.blockIO = ((void *) &eng_mdl_demo_v1_B);
  (void) memset(((void *) &eng_mdl_demo_v1_B),0,
                sizeof(BlockIO_eng_mdl_demo_v1));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&eng_mdl_demo_v1_B.volumetricefficiency);
    for (i = 0; i < 14; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  eng_mdl_demo_v1_M->ModelData.defaultParam = ((real_T *) &eng_mdl_demo_v1_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &eng_mdl_demo_v1_X;
    eng_mdl_demo_v1_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_eng_mdl_demo_v));
  }

  /* states (dwork) */
  eng_mdl_demo_v1_M->Work.dwork = ((void *) &eng_mdl_demo_v1_DWork);
  (void) memset((char_T *) &eng_mdl_demo_v1_DWork,0,
                sizeof(D_Work_eng_mdl_demo_v1));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE;
    for (i = 0; i < 7; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* external inputs */
  eng_mdl_demo_v1_M->ModelData.inputs = (((void*) &eng_mdl_demo_v1_U));
  eng_mdl_demo_v1_U.ETCMotorDutyCycle = 0.0;

  /* external outputs */
  eng_mdl_demo_v1_M->ModelData.outputs = (&eng_mdl_demo_v1_Y);
  eng_mdl_demo_v1_Y.MANFMAFgs = 0.0;
  eng_mdl_demo_v1_Y.MANFMAPbar = 0.0;
  eng_mdl_demo_v1_Y.MANFAPCg = 0.0;
}

/* Model terminate function */
void eng_mdl_demo_v1_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  eng_mdl_demo_v1_output(tid);
}

void MdlUpdate(int_T tid)
{
  eng_mdl_demo_v1_update(tid);
}

void MdlInitializeSizes(void)
{
  eng_mdl_demo_v1_M->Sizes.numContStates = (2);/* Number of continuous states */
  eng_mdl_demo_v1_M->Sizes.numY = (3); /* Number of model outputs */
  eng_mdl_demo_v1_M->Sizes.numU = (1); /* Number of model inputs */
  eng_mdl_demo_v1_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  eng_mdl_demo_v1_M->Sizes.numSampTimes = (2);/* Number of sample times */
  eng_mdl_demo_v1_M->Sizes.numBlocks = (83);/* Number of blocks */
  eng_mdl_demo_v1_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  eng_mdl_demo_v1_M->Sizes.numBlockPrms = (390);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Limited Integrator Block: '<S12>/p0 = amb.p//10 bar' */
  eng_mdl_demo_v1_X.p0ambp10bar_CSTATE = eng_mdl_demo_v1_P.p0ambp10bar_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  eng_mdl_demo_v1_X.Integrator_CSTATE = eng_mdl_demo_v1_P.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
  eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE = eng_mdl_demo_v1_P.UnitDelay2_X0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE = eng_mdl_demo_v1_P.UnitDelay1_X0;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g = eng_mdl_demo_v1_P.UnitDelay1_X0_l;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  eng_mdl_demo_v1_DWork.UnitDelay_DSTATE = eng_mdl_demo_v1_P.UnitDelay_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE =
    eng_mdl_demo_v1_P.DiscreteTimeIntegrator_IC;
  eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
    eng_mdl_demo_v1_P.DiscreteTimeIntegrator1_IC;
}

void MdlStart(void)
{
  /* ToWorkspace Block: '<S12>/To Workspace1' */
  {
    int_T dimensions[1] = { 1 };

    eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      eng_mdl_demo_v1_M->rtwLogInfo,
      rtmGetTFinal(eng_mdl_demo_v1_M),
      eng_mdl_demo_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(eng_mdl_demo_v1_M)),
      "hist_mdot_diff",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      NULL,
      10000,
      1,
      0.001,
      1);
    if (eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK.LoggedData == NULL)
      return;
  }

  /* ToWorkspace Block: '<S12>/To Workspace4' */
  {
    int_T dimensions[1] = { 1 };

    eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
      eng_mdl_demo_v1_M->rtwLogInfo,
      rtmGetTFinal(eng_mdl_demo_v1_M),
      eng_mdl_demo_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(eng_mdl_demo_v1_M)),
      "hist_ve",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      NULL,
      10000,
      1,
      0.001,
      1);
    if (eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK.LoggedData == NULL)
      return;
  }

  MdlInitialize();
}

RT_MODEL_eng_mdl_demo_v1 *eng_mdl_demo_v1(void)
{
  eng_mdl_demo_v1_initialize(1);
  return eng_mdl_demo_v1_M;
}

void MdlTerminate(void)
{
  eng_mdl_demo_v1_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_eng_mdl_demo_v1
#include "model_info.h"
#include "NIVERISTAND_API.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#ifdef VXWORKS
# define DataSection(t)                __attribute__ ((section((t))))
#else
# define DataSection(t)
#endif

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return (double)(((int_T*)ptr)[subindex]);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 14:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    ((int_T *)ptr)[subindex] = (int_T)value;
    return NI_OK;

   case 13:
    //Type is array. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 15:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 16:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern eng_mdl_demo_v1_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;
  ExternalInputs_eng_mdl_demo_v1 *rtIN = (ExternalInputs_eng_mdl_demo_v1*)
    S->ModelData.inputs;

  /* rtIN->ETCMotorDutyCycle Type 0 Width 1 */
  if (TaskSampleHit[1]) {              // sample and hold
    NIRT_SetValueByDataType(&rtIN->ETCMotorDutyCycle, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 0;
}

double ni_extout[4];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;
  ExternalOutputs_eng_mdl_demo_v1* rtOUT = (ExternalOutputs_eng_mdl_demo_v1*)
    S->ModelData.outputs;

  /* rtOUT->MANFMAFgs has width 1 type 0 */
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFMAFgs),0,0,0);
  } else {
    index += 1;
  }

  /* rtOUT->MANFMAPbar has width 1 type 0 */
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFMAPbar),0,0,0);
  } else {
    index += 1;
  }

  /* rtOUT->MANFAPCg has width 1 type 0 */
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFAPCg),0,0,0);
  } else {
    index += 1;
  }

  // ETC Motor Model/ETC::Position(deg): Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_B.UnitDelay2,0,
      0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 4;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;
  ExternalOutputs_eng_mdl_demo_v1* rtOUT = (ExternalOutputs_eng_mdl_demo_v1*)
    S->ModelData.outputs;

  /* rtOUT->MANFMAFgs has width 1 type 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFMAFgs),0,0,0);

  /* rtOUT->MANFMAPbar has width 1 type 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFMAPbar),0,0,0);

  /* rtOUT->MANFAPCg has width 1 type 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->MANFAPCg),0,0,0);

  // ETC Motor Model/ETC::Position(deg): Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_B.UnitDelay2,0,0,
    0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/p0 = amb.p//10 bar/InitialCondition",
    offsetof(Parameters_eng_mdl_demo_v1, p0ambp10bar_IC), 30, 1, 2, 0, 0 },

  { 1,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/p0 = amb.p//10 bar/UpperSaturationLimit",
    offsetof(Parameters_eng_mdl_demo_v1, p0ambp10bar_UpperSat), 30, 1, 2, 2, 0 },

  { 2,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/p0 = amb.p//10 bar/LowerSaturationLimit",
    offsetof(Parameters_eng_mdl_demo_v1, p0ambp10bar_LowerSat), 30, 1, 2, 4, 0 },

  { 3, "eng_mdl_demo_v1/Engine Speed/Integrator/InitialCondition", offsetof
    (Parameters_eng_mdl_demo_v1, Integrator_IC), 30, 1, 2, 6, 0 },

  { 4,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/volumetric efficiency/RowIndex",
    offsetof(Parameters_eng_mdl_demo_v1, volumetricefficiency_RowIdx), 31, 17, 2,
    8, 0 },

  { 5,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/volumetric efficiency/ColumnIndex",
    offsetof(Parameters_eng_mdl_demo_v1, volumetricefficiency_ColIdx), 32, 16, 2,
    10, 0 },

  { 6,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/volumetric efficiency/Table",
    offsetof(Parameters_eng_mdl_demo_v1, volumetricefficiency_Table), 33, 272, 2,
    12, 0 },

  { 7,
    "eng_mdl_demo_v1/Manifod Model/Intake Manifold/ideal air mass//cycle (g)/Gain",
    offsetof(Parameters_eng_mdl_demo_v1, idealairmasscycleg_Gain), 30, 1, 2, 14,
    0 },

  { 8, "eng_mdl_demo_v1/Manifod Model/Intake Manifold/1//(4*pi)/Gain", offsetof
    (Parameters_eng_mdl_demo_v1, upi_Gain), 30, 1, 2, 16, 0 },

  { 9, "eng_mdl_demo_v1/Gain1/Gain", offsetof(Parameters_eng_mdl_demo_v1,
    Gain1_Gain), 30, 1, 2, 18, 0 },

  { 10, "eng_mdl_demo_v1/phi1/Value", offsetof(Parameters_eng_mdl_demo_v1,
    phi1_Value), 30, 1, 2, 20, 0 },

  { 11, "eng_mdl_demo_v1/Combustion Torque Model/combustion efficiency/RowIndex",
    offsetof(Parameters_eng_mdl_demo_v1, combustionefficiency_RowIdx), 34, 3, 2,
    22, 0 },

  { 12,
    "eng_mdl_demo_v1/Combustion Torque Model/combustion efficiency/ColumnIndex",
    offsetof(Parameters_eng_mdl_demo_v1, combustionefficiency_ColIdx), 35, 2, 2,
    24, 0 },

  { 13, "eng_mdl_demo_v1/Combustion Torque Model/combustion efficiency/Table",
    offsetof(Parameters_eng_mdl_demo_v1, combustionefficiency_Table), 36, 6, 2,
    26, 0 },

  { 14, "eng_mdl_demo_v1/Combustion Torque Model/Stoichiometric Fuel/Gain",
    offsetof(Parameters_eng_mdl_demo_v1, StoichiometricFuel_Gain), 30, 1, 2, 28,
    0 },

  { 15, "eng_mdl_demo_v1/phi/Value", offsetof(Parameters_eng_mdl_demo_v1,
    phi_Value), 30, 1, 2, 30, 0 },

  { 16, "eng_mdl_demo_v1/Combustion Torque Model/thermodynamic efficiency/Value",
    offsetof(Parameters_eng_mdl_demo_v1, thermodynamicefficiency_Value), 30, 1,
    2, 32, 0 },

  { 17, "eng_mdl_demo_v1/ENV::Baro (kPa)/Value", offsetof
    (Parameters_eng_mdl_demo_v1, ENVBarokPa_Value), 30, 1, 2, 34, 0 },

  { 18, "eng_mdl_demo_v1/Engine Speed/Gain2/Gain", offsetof
    (Parameters_eng_mdl_demo_v1, Gain2_Gain), 30, 1, 2, 36, 0 },

  { 19, "eng_mdl_demo_v1/Engine Speed/Gain/Gain", offsetof
    (Parameters_eng_mdl_demo_v1, Gain_Gain), 30, 1, 2, 38, 0 },

  { 20, "eng_mdl_demo_v1/TPS/Value", offsetof(Parameters_eng_mdl_demo_v1,
    TPS_Value), 30, 1, 2, 40, 0 },

  { 21, "eng_mdl_demo_v1/Manifod Model/Throttle/Sonic Flow/Value", offsetof
    (Parameters_eng_mdl_demo_v1, SonicFlow_Value), 30, 1, 2, 42, 0 },

  { 22, "eng_mdl_demo_v1/Manifod Model/Throttle/Switch/Threshold", offsetof
    (Parameters_eng_mdl_demo_v1, Switch_Threshold), 30, 1, 2, 44, 0 },

  { 23, "eng_mdl_demo_v1/Manifod Model/Intake Manifold/im.RT_over_V/Gain",
    offsetof(Parameters_eng_mdl_demo_v1, imRT_over_V_Gain), 30, 1, 2, 46, 0 },

  { 24, "eng_mdl_demo_v1/ETC Motor Model/Unit Delay2/X0", offsetof
    (Parameters_eng_mdl_demo_v1, UnitDelay2_X0), 30, 1, 2, 48, 0 },

  { 25, "eng_mdl_demo_v1/ETC Motor Model/Kt//R/Value", offsetof
    (Parameters_eng_mdl_demo_v1, KtR_Value), 30, 1, 2, 50, 0 },

  { 26, "eng_mdl_demo_v1/ETC Motor Model/Alpha/Value", offsetof
    (Parameters_eng_mdl_demo_v1, Alpha_Value), 30, 1, 2, 52, 0 },

  { 27, "eng_mdl_demo_v1/ETC Motor Model/Motor/First Oder Filter/Unit Delay1/X0",
    offsetof(Parameters_eng_mdl_demo_v1, UnitDelay1_X0), 30, 1, 2, 54, 0 },

  { 28, "eng_mdl_demo_v1/Vbatt(Vdc)/Value", offsetof(Parameters_eng_mdl_demo_v1,
    VbattVdc_Value), 30, 1, 2, 56, 0 },

  { 29, "eng_mdl_demo_v1/ETC Motor Model/Unit Delay1/X0", offsetof
    (Parameters_eng_mdl_demo_v1, UnitDelay1_X0_l), 30, 1, 2, 58, 0 },

  { 30, "eng_mdl_demo_v1/ETC Motor Model/SpringTorque/InputValues", offsetof
    (Parameters_eng_mdl_demo_v1, SpringTorque_XData), 37, 15, 2, 60, 0 },

  { 31, "eng_mdl_demo_v1/ETC Motor Model/SpringTorque/Table", offsetof
    (Parameters_eng_mdl_demo_v1, SpringTorque_YData), 37, 15, 2, 62, 0 },

  { 32, "eng_mdl_demo_v1/ETC Motor Model/Damping Const/Value", offsetof
    (Parameters_eng_mdl_demo_v1, DampingConst_Value), 30, 1, 2, 64, 0 },

  { 33, "eng_mdl_demo_v1/ETC Motor Model/Unit Delay/X0", offsetof
    (Parameters_eng_mdl_demo_v1, UnitDelay_X0), 30, 1, 2, 66, 0 },

  { 34,
    "eng_mdl_demo_v1/ETC Motor Model/DeadStops/NegativeTorque/Constant/Value",
    offsetof(Parameters_eng_mdl_demo_v1, Constant_Value), 30, 1, 2, 68, 0 },

  { 35, "eng_mdl_demo_v1/ETC Motor Model/DeadStops/LowerStop/Constant/Value",
    offsetof(Parameters_eng_mdl_demo_v1, Constant_Value_c), 30, 1, 2, 70, 0 },

  { 36, "eng_mdl_demo_v1/ETC Motor Model/DeadStops/UpperStop/Constant/Value",
    offsetof(Parameters_eng_mdl_demo_v1, Constant_Value_n), 30, 1, 2, 72, 0 },

  { 37,
    "eng_mdl_demo_v1/ETC Motor Model/DeadStops/PositiveTorque/Constant/Value",
    offsetof(Parameters_eng_mdl_demo_v1, Constant_Value_f), 30, 1, 2, 74, 0 },

  { 38, "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator/gainval",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator_gainval), 0, 1,
    2, 76, 0 },

  { 39,
    "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator/InitialCondition",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator_IC), 30, 1, 2,
    78, 0 },

  { 40, "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator1/gainval",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator1_gainval), 0, 1,
    2, 80, 0 },

  { 41,
    "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator1/InitialCondition",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator1_IC), 30, 1, 2,
    82, 0 },

  { 42,
    "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator1/UpperSaturationLimit",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator1_UpperSa), 30, 1,
    2, 84, 0 },

  { 43,
    "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator1/LowerSaturationLimit",
    offsetof(Parameters_eng_mdl_demo_v1, DiscreteTimeIntegrator1_LowerSa), 30, 1,
    2, 86, 0 },

  { 44, "eng_mdl_demo_v1/ETC Motor Model/Inertia/Value", offsetof
    (Parameters_eng_mdl_demo_v1, Inertia_Value), 30, 1, 2, 88, 0 },

  { 45, "eng_mdl_demo_v1/ETC Motor Model/Constant4/Value", offsetof
    (Parameters_eng_mdl_demo_v1, Constant4_Value), 30, 1, 2, 90, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 46;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  17, 1,                               /* Parameter at index 4 */
  1, 16,                               /* Parameter at index 5 */
  17, 16,                              /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  3, 1,                                /* Parameter at index 11 */
  1, 2,                                /* Parameter at index 12 */
  3, 2,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 15,                               /* Parameter at index 30 */
  1, 15,                               /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "eng_mdl_demo_v1/Manifod Model/Intake Manifold/volumetric efficiency", 0,
    "", offsetof(BlockIO_eng_mdl_demo_v1, volumetricefficiency), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 1, "eng_mdl_demo_v1/Manifod Model/Intake Manifold/ideal air mass//cycle (g)",
    0, "", offsetof(BlockIO_eng_mdl_demo_v1, idealairmasscycleg), BLOCKIO_SIG, 0,
    1, 2, 2, 0 },

  { 2, "eng_mdl_demo_v1/Gain1", 0, "", offsetof(BlockIO_eng_mdl_demo_v1, Gain1),
    BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "eng_mdl_demo_v1/Combustion Torque Model/combustion efficiency", 0, "",
    offsetof(BlockIO_eng_mdl_demo_v1, combustionefficiency), BLOCKIO_SIG, 0, 1,
    2, 6, 0 },

  { 4, "eng_mdl_demo_v1/Combustion Torque Model/Product", 0, "fuel mass (g)",
    offsetof(BlockIO_eng_mdl_demo_v1, fuelmassg), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "eng_mdl_demo_v1/Engine Speed/Gain", 0, "", offsetof
    (BlockIO_eng_mdl_demo_v1, Gain), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "eng_mdl_demo_v1/Manifod Model/Throttle/f(theta)", 0, "", offsetof
    (BlockIO_eng_mdl_demo_v1, ftheta), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "eng_mdl_demo_v1/Manifod Model/Throttle/Product", 0, "", offsetof
    (BlockIO_eng_mdl_demo_v1, Product), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "eng_mdl_demo_v1/Manifod Model/Intake Manifold/im.RT_over_V", 0, "",
    offsetof(BlockIO_eng_mdl_demo_v1, imRT_over_V), BLOCKIO_SIG, 0, 1, 2, 16, 0
  },

  { 9, "eng_mdl_demo_v1/ETC Motor Model/Unit Delay2", 0, "", offsetof
    (BlockIO_eng_mdl_demo_v1, UnitDelay2), BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "eng_mdl_demo_v1/ETC Motor Model/Motor/First Oder Filter/Add1", 0, "DC",
    offsetof(BlockIO_eng_mdl_demo_v1, DC), BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator", 0, "",
    offsetof(BlockIO_eng_mdl_demo_v1, DiscreteTimeIntegrator), BLOCKIO_SIG, 0, 1,
    2, 22, 0 },

  { 12, "eng_mdl_demo_v1/ETC Motor Model/Discrete-Time Integrator1", 0, "",
    offsetof(BlockIO_eng_mdl_demo_v1, DiscreteTimeIntegrator1), BLOCKIO_SIG, 0,
    1, 2, 24, 0 },

  { 13, "eng_mdl_demo_v1/ETC Motor Model/Product2", 0, "", offsetof
    (BlockIO_eng_mdl_demo_v1, Product2), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "eng_mdl_demo_v1/ETC Motor Model/DeadStops/Logical Operator", 0, "",
    offsetof(BlockIO_eng_mdl_demo_v1, LogicalOperator), BLOCKIO_SIG, 8, 1, 2, 28,
    0 },

  { 15, "eng_mdl_demo_v1/ETC::Motor Duty Cycle (%)", 0, "", offsetof
    (ExternalInputs_eng_mdl_demo_v1, ETCMotorDutyCycle), EXTIO_SIG, 0, 1, 2, 30,
    0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 16;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 5;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "ETC::Motor Duty Cycle (%)", 1, EXT_IN, 1, 1, 1 },

  { 0, "MANF::MAF (g//s)", 0, EXT_OUT, 1, 1, 1 },

  { 1, "MANF::MAP(bar)", 0, EXT_OUT, 1, 1, 1 },

  { 2, "MANF::APC(g)", 0, EXT_OUT, 1, 1, 1 },

  { 3, "ETC Motor Model/ETC::Position(deg)", 1, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.001, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "eng_mdl_demo_v1";
static char* NI_CompiledModelVersion = "1.181";
static char* NI_CompiledModelDateTime = "Fri Jun 20 12:10:00 2014";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2013.0.1.0 (2013) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2013.0.1.0";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#ifndef VXWORKS

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#ifndef VXWORKS

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 0; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real eng_mdl_demo_v1_P
   In the rest of the code eng_mdl_demo_v1_P is redefine to be the read-side
   of rtParameter.
 */
#undef eng_mdl_demo_v1_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &eng_mdl_demo_v1_P, sizeof(Parameters_eng_mdl_demo_v1));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka eng_mdl_demo_v1_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(Parameters_eng_mdl_demo_v1));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (Parameters_eng_mdl_demo_v1));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (Parameters_eng_mdl_demo_v1));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (Parameters_eng_mdl_demo_v1));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (Parameters_eng_mdl_demo_v1));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (Parameters_eng_mdl_demo_v1));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 2;
      *numDiscStates = 37;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&rtX.p0ambp10bar_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "p0ambp10bar_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&rtX.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.UnitDelay_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.UnitDelay_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_DWork.APCg_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&eng_mdl_demo_v1_DWork.APCg_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_DWork.RPM_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&eng_mdl_demo_v1_DWork.RPM_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.ComEff_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.ComEff_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_DWork.FPCg_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&eng_mdl_demo_v1_DWork.FPCg_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_DWork.MAF_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&eng_mdl_demo_v1_DWork.MAF_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&eng_mdl_demo_v1_DWork.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&eng_mdl_demo_v1_DWork.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.Scope1_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.Scope1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.Scope2_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.Scope2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.Scope4_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.Scope4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.Torque_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.Torque_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.Scope_PWORK_j, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.Scope_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese");
    for (count = 0; count < 16; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK2, count, 14, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK2");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&rtX.p0ambp10bar_CSTATE, 0, contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rtX.Integrator_CSTATE, 0, contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.UnitDelay2_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.UnitDelay1_DSTATE_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.UnitDelay_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_DSTATE,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator1_DSTATE, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.APCg_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.RPM_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.ComEff_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.FPCg_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.ToWorkspace1_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.ToWorkspace4_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.MAF_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Scope_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Scope1_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Scope2_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Scope4_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Torque_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.Scope_PWORK_j, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType
      (&eng_mdl_demo_v1_DWork.DiscreteTimeIntegrator_PrevRese, 0, discStates[idx
       ++], 2, 0);
    for (count = 0; count < 16; count++) {
      NIRT_SetValueByDataType(&eng_mdl_demo_v1_DWork.ETCPositiondeg_DWORK2,
        count, discStates[idx++], 14, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_eng_mdl_demo_v1
