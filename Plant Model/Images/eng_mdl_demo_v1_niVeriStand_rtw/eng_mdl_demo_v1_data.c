/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/

#ifdef VXWORKS
# define DataSection(t)                __attribute__ ((section((t))))
# define eng_mdl_demo_v1_P             eng_mdl_demo_v1_P DataSection(".NIVS.defaultparams")
#endif

/*
 * eng_mdl_demo_v1_data.c
 *
 * Real-Time Workshop code generation for Simulink model "eng_mdl_demo_v1.mdl".
 *
 * Model Version              : 1.181
 * Real-Time Workshop version : 7.0.1  (R2007b+)  21-Apr-2008
 * C source code generated on : Fri Jun 20 12:10:01 2014
 */
#include "eng_mdl_demo_v1.h"
#include "eng_mdl_demo_v1_private.h"

/* Block parameters (auto storage) */
Parameters_eng_mdl_demo_v1 eng_mdl_demo_v1_P = {
  1.0132501000000001E-001,             /* p0ambp10bar_IC : '<S12>/p0 = amb.p//10 bar'
                                        */
  1.003117599,                         /* p0ambp10bar_UpperSat : '<S12>/p0 = amb.p//10 bar'
                                        */
  0.0010132501,                        /* p0ambp10bar_LowerSat : '<S12>/p0 = amb.p//10 bar'
                                        */
  0.0,                                 /* Integrator_IC : '<S3>/Integrator'
                                        */

  /*  volumetricefficiency_RowIdx : '<S12>/volumetric efficiency'
   */
  { 0.0, 0.0625, 0.125, 0.1875, 0.25, 0.3125, 0.375, 0.4375, 0.5, 0.5625, 0.625,
    0.6875, 0.75, 0.8125, 0.875, 0.9375, 1.0 },

  /*  volumetricefficiency_ColIdx : '<S12>/volumetric efficiency'
   */
  { 2.0943951023931955E+001, 7.3303828583761828E+001, 1.0471975511965977E+002,
    1.2566370614359172E+002, 1.8849555921538757E+002, 2.3038346126325149E+002,
    2.7227136331111541E+002, 3.1415926535897933E+002, 3.5604716740684319E+002,
    3.9793506945470716E+002, 4.3982297150257102E+002, 4.8171087355043494E+002,
    5.2359877559829886E+002, 5.6548667764616278E+002, 6.0737457969402669E+002,
    6.4926248174189061E+002 },

  /*  volumetricefficiency_Table : '<S12>/volumetric efficiency'
   */
  { 0.00079, 0.00158, 0.00237, 0.00316, 0.30968, 3.1758000000000003E-001,
    0.32943, 3.5234000000000004E-001, 0.36419, 4.0290000000000004E-001,
    4.1080000000000005E-001, 4.4161000000000006E-001, 0.46057,
    4.8822000000000004E-001, 0.51903, 5.3799000000000008E-001,
    5.3799000000000008E-001, 0.00079, 0.00158, 0.00237, 0.00316, 0.30968,
    3.1758000000000003E-001, 0.34049, 3.5629000000000005E-001,
    4.2976000000000003E-001, 4.0290000000000004E-001, 4.1080000000000005E-001,
    4.4161000000000006E-001, 0.46057, 0.48032, 4.8822000000000004E-001, 0.54589,
    0.54589, 0.00079, 0.00158, 0.00237, 0.00316, 0.34444,
    3.5234000000000004E-001, 0.36814, 0.38315, 4.5661999999999997E-001,
    4.1080000000000005E-001, 0.42581, 4.2976000000000003E-001,
    4.4555999999999996E-001, 0.49928, 5.1508000000000009E-001, 0.52693, 0.52693,
    0.00079, 0.00158, 0.00237, 0.00316, 3.5629000000000005E-001, 0.36814,
    4.1791000000000006E-001, 4.4161000000000006E-001, 4.4950999999999997E-001,
    0.46847, 0.46847, 0.48032, 5.0323000000000007E-001, 5.0718000000000008E-001,
    5.3799000000000008E-001, 0.56169, 0.56169, 0.00079, 0.00158, 0.00237,
    0.00316, 0.39895, 4.2186000000000007E-001, 4.3766000000000005E-001, 0.47637,
    4.8427000000000003E-001, 4.8822000000000004E-001, 4.9533000000000005E-001,
    5.0718000000000008E-001, 5.1113000000000008E-001, 0.53088, 0.54589, 0.5767,
    0.5767, 0.00079, 0.00158, 0.00237, 0.00316, 4.2976000000000003E-001,
    4.3766000000000005E-001, 4.4950999999999997E-001, 4.8822000000000004E-001,
    0.49928, 0.49928, 5.1508000000000009E-001, 0.51903, 0.53088, 0.58065, 0.5925,
    6.1225000000000007E-001, 6.1225000000000007E-001, 0.00079, 0.00158, 0.00237,
    0.00316, 4.0685000000000004E-001, 4.4555999999999996E-001,
    4.8822000000000004E-001, 0.51903, 5.1508000000000009E-001,
    5.0718000000000008E-001, 0.51903, 0.52298, 5.3404000000000007E-001, 0.54589,
    6.3516000000000006E-001, 0.65807, 0.65807, 0.00079, 0.00158, 0.00237,
    0.00316, 4.0290000000000004E-001, 0.45346, 4.8822000000000004E-001, 0.52298,
    0.52298, 5.1113000000000008E-001, 0.52298, 5.3404000000000007E-001,
    5.3799000000000008E-001, 0.55379, 0.64306, 0.68572, 0.68572, 0.00079,
    0.00158, 0.00237, 0.00316, 4.0685000000000004E-001, 0.47637,
    4.9533000000000005E-001, 0.52693, 5.3799000000000008E-001, 0.51903,
    5.3404000000000007E-001, 5.3799000000000008E-001, 5.3799000000000008E-001,
    0.57275, 0.66992, 0.68967, 0.68967, 0.00079, 0.00158, 0.00237, 0.00316,
    4.1080000000000005E-001, 5.0323000000000007E-001, 0.51903, 0.53088,
    5.3404000000000007E-001, 5.3404000000000007E-001, 5.3799000000000008E-001,
    5.3799000000000008E-001, 5.3799000000000008E-001, 0.54984, 0.65096, 0.66992,
    0.66992, 0.00079, 0.00158, 0.00237, 0.00316, 4.1080000000000005E-001,
    5.1113000000000008E-001, 0.51903, 0.53088, 5.3404000000000007E-001,
    5.3799000000000008E-001, 5.3799000000000008E-001, 5.4194000000000009E-001,
    5.4194000000000009E-001, 5.3799000000000008E-001, 0.65096, 0.66202, 0.66202,
    0.00079, 0.00158, 0.00237, 0.00316, 4.1080000000000005E-001,
    5.1113000000000008E-001, 0.51903, 0.53088, 5.3404000000000007E-001,
    5.3799000000000008E-001, 5.3799000000000008E-001, 5.4194000000000009E-001,
    5.4194000000000009E-001, 5.3799000000000008E-001, 0.65412, 0.65412, 0.65412,
    0.00079, 0.00158, 0.00237, 0.00316, 4.1080000000000005E-001,
    5.1113000000000008E-001, 0.51903, 0.53088, 5.3404000000000007E-001,
    5.3799000000000008E-001, 5.3799000000000008E-001, 5.4194000000000009E-001,
    5.4194000000000009E-001, 5.3404000000000007E-001, 0.65412, 0.65412, 0.65412,
    0.00079, 0.00158, 0.00237, 0.00316, 4.1080000000000005E-001,
    4.8822000000000004E-001, 4.9533000000000005E-001, 0.51903, 0.51903, 0.52693,
    5.3404000000000007E-001, 5.3404000000000007E-001, 5.3799000000000008E-001,
    0.51903, 0.62726, 0.65096, 0.65096, 0.00079, 0.00158, 0.00237, 0.00316,
    4.1080000000000005E-001, 0.45346, 0.48032, 4.8822000000000004E-001,
    4.9533000000000005E-001, 0.49928, 5.0323000000000007E-001,
    5.1113000000000008E-001, 0.52298, 0.49928, 0.62331, 0.62726, 0.62726,
    0.00079, 0.00158, 0.00237, 0.00316, 4.1080000000000005E-001,
    4.2976000000000003E-001, 4.4555999999999996E-001, 0.45346, 0.48032, 0.48032,
    4.8427000000000003E-001, 4.9533000000000005E-001, 0.49217, 0.48032, 0.5846,
    0.6004, 0.6004 },
  2.204826,                            /* idealairmasscycleg_Gain : '<S12>/ideal air mass//cycle (g)'
                                        */
  7.9577471545947673E-002,             /* upi_Gain : '<S12>/1//(4*pi)'
                                        */
  9.5492965855137211E+000,             /* Gain1_Gain : '<Root>/Gain1'
                                        */
  25.0,                                /* phi1_Value : '<Root>/phi1'
                                        */

  /*  combustionefficiency_RowIdx : '<S1>/combustion efficiency'
   */
  { 0.0, 25.0, 50.0 },

  /*  combustionefficiency_ColIdx : '<S1>/combustion efficiency'
   */
  { 2.0943951023931955E+001, 6.4926248174189061E+002 },

  /*  combustionefficiency_Table : '<S1>/combustion efficiency'
   */
  { 0.75, 1.0, 0.75, 0.75, 1.0, 0.75 },
  6.8493150684931503E-002,             /* StoichiometricFuel_Gain : '<S1>/Stoichiometric Fuel'
                                        */
  1.0,                                 /* phi_Value : '<Root>/phi'
                                        */
  0.4,                                 /* thermodynamicefficiency_Value : '<S1>/thermodynamic efficiency'
                                        */
  1.0133,                              /* ENVBarokPa_Value : '<Root>/ENV::Baro (kPa)'
                                        */
  0.45,                                /* Gain2_Gain : '<S3>/Gain2'
                                        */
  0.1,                                 /* Gain_Gain : '<S3>/Gain'
                                        */
  6.0,                                 /* TPS_Value : '<Root>/TPS'
                                        */
  1.0,                                 /* SonicFlow_Value : '<S13>/Sonic Flow '
                                        */
  0.5,                                 /* Switch_Threshold : '<S13>/Switch'
                                        */
  2.3040802675585284E-001,             /* imRT_over_V_Gain : '<S12>/im.RT_over_V'
                                        */
  20.0,                                /* UnitDelay2_X0 : '<S2>/Unit Delay2'
                                        */
  -1.0,                                /* ETCPositiondeg_P1 : '<S2>/ETC::Position(deg)'
                                        */
  1.0,                                 /* ETCPositiondeg_P2 : '<S2>/ETC::Position(deg)'
                                        */
  1.0,                                 /* ETCPositiondeg_P3 : '<S2>/ETC::Position(deg)'
                                        */
  -1.0,                                /* ETCPositiondeg_P4 : '<S2>/ETC::Position(deg)'
                                        */
  1.0,                                 /* ETCPositiondeg_P5 : '<S2>/ETC::Position(deg)'
                                        */
  0.0,                                 /* ETCPositiondeg_P6 : '<S2>/ETC::Position(deg)'
                                        */
  8.3333333333333329E-002,             /* KtR_Value : '<S2>/Kt//R'
                                        */
  0.0005,                              /* Alpha_Value : '<S2>/Alpha'
                                        */
  0.0,                                 /* UnitDelay1_X0 : '<S11>/Unit Delay1'
                                        */
  13.7,                                /* VbattVdc_Value : '<Root>/Vbatt(Vdc)'
                                        */
  20.0,                                /* UnitDelay1_X0_l : '<S2>/Unit Delay1'
                                        */

  /*  SpringTorque_XData : '<S2>/SpringTorque'
   */
  { 0.0, 10.0, 15.0, 18.0, 20.0, 22.0, 25.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0,
    90.0, 100.0 },

  /*  SpringTorque_YData : '<S2>/SpringTorque'
   */
  { -20.0, -18.0, -17.0, -12.0, 0.0, 12.0, 17.0, 18.0, 18.0, 19.0, 20.0, 20.0,
    21.0, 21.0, 22.0 },
  1.0,                                 /* DampingConst_Value : '<S2>/Damping Const'
                                        */
  0.0,                                 /* UnitDelay_X0 : '<S2>/Unit Delay'
                                        */
  0.0,                                 /* Constant_Value : '<S8>/Constant'
                                        */
  0.01,                                /* Constant_Value_c : '<S7>/Constant'
                                        */
  90.0,                                /* Constant_Value_n : '<S10>/Constant'
                                        */
  0.0,                                 /* Constant_Value_f : '<S9>/Constant'
                                        */
  0.001,                               /* DiscreteTimeIntegrator_gainval : '<S2>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* DiscreteTimeIntegrator_IC : '<S2>/Discrete-Time Integrator'
                                        */
  0.001,                               /* DiscreteTimeIntegrator1_gainval : '<S2>/Discrete-Time Integrator1'
                                        */
  20.0,                                /* DiscreteTimeIntegrator1_IC : '<S2>/Discrete-Time Integrator1'
                                        */
  90.0,                                /* DiscreteTimeIntegrator1_UpperSa : '<S2>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* DiscreteTimeIntegrator1_LowerSa : '<S2>/Discrete-Time Integrator1'
                                        */
  0.3,                                 /* Inertia_Value : '<S2>/Inertia'
                                        */
  0.0                                  /* Constant4_Value : '<S2>/Constant4'
                                        */
};

#ifdef VXWORKS

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth Parameters_eng_mdl_demo_v1_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(Parameters_eng_mdl_demo_v1), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 17, 0 },

  { sizeof(real_T), 16, 0 },

  { sizeof(real_T), 272, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 15, 0 },

  { sizeof(real_T), 15, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
