/*
 * eng_mdl_demo_v1.h
 *
 * Real-Time Workshop code generation for Simulink model "eng_mdl_demo_v1.mdl".
 *
 * Model Version              : 1.181
 * Real-Time Workshop version : 7.0.1  (R2007b+)  21-Apr-2008
 * C source code generated on : Fri Jun 20 12:10:01 2014
 */
#ifndef RTW_HEADER_eng_mdl_demo_v1_h_
#define RTW_HEADER_eng_mdl_demo_v1_h_
#ifndef eng_mdl_demo_v1_COMMON_INCLUDES_
# define eng_mdl_demo_v1_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtlibsrc.h"
#endif                                 /* eng_mdl_demo_v1_COMMON_INCLUDES_ */

#include "eng_mdl_demo_v1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define eng_mdl_demo_v1_rtModel        RT_MODEL_eng_mdl_demo_v1

/* Block signals (auto storage) */
typedef struct {
  real_T volumetricefficiency;         /* '<S12>/volumetric efficiency' */
  real_T idealairmasscycleg;           /* '<S12>/ideal air mass//cycle (g)' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T combustionefficiency;         /* '<S1>/combustion efficiency' */
  real_T fuelmassg;                    /* '<S1>/Product' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T ftheta;                       /* '<S13>/f(theta)' */
  real_T Product;                      /* '<S13>/Product' */
  real_T imRT_over_V;                  /* '<S12>/im.RT_over_V' */
  real_T UnitDelay2;                   /* '<S2>/Unit Delay2' */
  real_T DC;                           /* '<S11>/Add1' */
  real_T DiscreteTimeIntegrator;       /* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S2>/Discrete-Time Integrator1' */
  real_T Product2;                     /* '<S2>/Product2' */
  boolean_T LogicalOperator;           /* '<S5>/Logical Operator' */
} BlockIO_eng_mdl_demo_v1;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay2_DSTATE;            /* '<S2>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S11>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_g;          /* '<S2>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T ETCPositiondeg_DWORK1;        /* '<S2>/ETC::Position(deg)' */
  struct {
    void *LoggedData;
  } APCg_PWORK;                        /* '<Root>/APC(g)' */

  struct {
    void *LoggedData;
  } RPM_PWORK;                         /* '<Root>/RPM' */

  struct {
    void *LoggedData;
  } ComEff_PWORK;                      /* '<S1>/ComEff' */

  struct {
    void *LoggedData;
  } FPCg_PWORK;                        /* '<S1>/FPC(g)' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S12>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S12>/To Workspace4' */

  struct {
    void *LoggedData;
  } MAF_PWORK;                         /* '<S13>/MAF' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S2>/Scope2' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S2>/Scope4' */

  struct {
    void *LoggedData;
  } Torque_PWORK;                      /* '<S2>/Torque' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S5>/Scope' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S2>/Discrete-Time Integrator' */
  uint8_T ETCPositiondeg_DWORK2[16];   /* '<S2>/ETC::Position(deg)' */
} D_Work_eng_mdl_demo_v1;

/* Continuous states (auto storage) */
typedef struct {
  real_T p0ambp10bar_CSTATE;           /* '<S12>/p0 = amb.p//10 bar' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} ContinuousStates_eng_mdl_demo_v;

/* State derivatives (auto storage) */
typedef struct {
  real_T p0ambp10bar_CSTATE;           /* '<S12>/p0 = amb.p//10 bar' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} StateDerivatives_eng_mdl_demo_v;

/* State disabled  */
typedef struct {
  boolean_T p0ambp10bar_CSTATE;        /* '<S12>/p0 = amb.p//10 bar' */
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
} StateDisabled_eng_mdl_demo_v1;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T ETCMotorDutyCycle;            /* '<Root>/ETC::Motor Duty Cycle (%)' */
} ExternalInputs_eng_mdl_demo_v1;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T MANFMAFgs;                    /* '<Root>/MANF::MAF (g//s)' */
  real_T MANFMAPbar;                   /* '<Root>/MANF::MAP(bar)' */
  real_T MANFAPCg;                     /* '<Root>/MANF::APC(g)' */
} ExternalOutputs_eng_mdl_demo_v1;

/* Backward compatible GRT Identifiers */
#define rtB                            eng_mdl_demo_v1_B
#define BlockIO                        BlockIO_eng_mdl_demo_v1
#define rtU                            eng_mdl_demo_v1_U
#define ExternalInputs                 ExternalInputs_eng_mdl_demo_v1
#define rtX                            eng_mdl_demo_v1_X
#define ContinuousStates               ContinuousStates_eng_mdl_demo_v
#define rtY                            eng_mdl_demo_v1_Y
#define ExternalOutputs                ExternalOutputs_eng_mdl_demo_v1
#define rtP                            eng_mdl_demo_v1_P
#define Parameters                     Parameters_eng_mdl_demo_v1
#define rtDWork                        eng_mdl_demo_v1_DWork
#define D_Work                         D_Work_eng_mdl_demo_v1

/* Parameters (auto storage) */
struct Parameters_eng_mdl_demo_v1 {
  real_T p0ambp10bar_IC;               /* Expression: amb.p/10
                                        * '<S12>/p0 = amb.p//10 bar'
                                        */
  real_T p0ambp10bar_UpperSat;         /* Expression: 0.99*amb.p
                                        * '<S12>/p0 = amb.p//10 bar'
                                        */
  real_T p0ambp10bar_LowerSat;         /* Expression: 0.001*amb.p
                                        * '<S12>/p0 = amb.p//10 bar'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * '<S3>/Integrator'
                                        */
  real_T volumetricefficiency_RowIdx[17];/* Expression: cylinder.ve.map
                                          * '<S12>/volumetric efficiency'
                                          */
  real_T volumetricefficiency_ColIdx[16];/* Expression: cylinder.ve.rpm*pi/30
                                          * '<S12>/volumetric efficiency'
                                          */
  real_T volumetricefficiency_Table[272];/* Expression: 0.79*cylinder.ve.table
                                          * '<S12>/volumetric efficiency'
                                          */
  real_T idealairmasscycleg_Gain;      /* Expression: air.rho*cylinder.V
                                        * '<S12>/ideal air mass//cycle (g)'
                                        */
  real_T upi_Gain;                     /* Expression: 1/(4*pi)
                                        * '<S12>/1//(4*pi)'
                                        */
  real_T Gain1_Gain;                   /* Expression: 30/pi
                                        * '<Root>/Gain1'
                                        */
  real_T phi1_Value;                   /* Expression: 25
                                        * '<Root>/phi1'
                                        */
  real_T combustionefficiency_RowIdx[3];/* Expression: cylinder.ce.spark_timing
                                         * '<S1>/combustion efficiency'
                                         */
  real_T combustionefficiency_ColIdx[2];/* Expression: cylinder.ce.rpm*pi/30
                                         * '<S1>/combustion efficiency'
                                         */
  real_T combustionefficiency_Table[6];/* Expression: cylinder.ce.table
                                        * '<S1>/combustion efficiency'
                                        */
  real_T StoichiometricFuel_Gain;      /* Expression: 1/14.6
                                        * '<S1>/Stoichiometric Fuel'
                                        */
  real_T phi_Value;                    /* Expression: 1
                                        * '<Root>/phi'
                                        */
  real_T thermodynamicefficiency_Value;/* Expression: 0.4
                                        * '<S1>/thermodynamic efficiency'
                                        */
  real_T ENVBarokPa_Value;             /* Expression: 1.0133
                                        * '<Root>/ENV::Baro (kPa)'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.45
                                        * '<S3>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/10
                                        * '<S3>/Gain'
                                        */
  real_T TPS_Value;                    /* Expression: 6
                                        * '<Root>/TPS'
                                        */
  real_T SonicFlow_Value;              /* Expression: 1.0
                                        * '<S13>/Sonic Flow '
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * '<S13>/Switch'
                                        */
  real_T imRT_over_V_Gain;             /* Expression: im.RT_over_V
                                        * '<S12>/im.RT_over_V'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 20
                                        * '<S2>/Unit Delay2'
                                        */
  real_T ETCPositiondeg_P1;            /* Expression: width
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T ETCPositiondeg_P2;            /* Expression: dtype
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T ETCPositiondeg_P3;            /* Expression: portnum
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T ETCPositiondeg_P4;            /* Expression: stime
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T ETCPositiondeg_P5;            /* Expression: stype
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T ETCPositiondeg_P6;            /* Expression: btype
                                        * '<S2>/ETC::Position(deg)'
                                        */
  real_T KtR_Value;                    /* Expression: 1/12
                                        * '<S2>/Kt//R'
                                        */
  real_T Alpha_Value;                  /* Expression: .0005
                                        * '<S2>/Alpha'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * '<S11>/Unit Delay1'
                                        */
  real_T VbattVdc_Value;               /* Expression: 13.7
                                        * '<Root>/Vbatt(Vdc)'
                                        */
  real_T UnitDelay1_X0_l;              /* Expression: 20
                                        * '<S2>/Unit Delay1'
                                        */
  real_T SpringTorque_XData[15];       /* Expression: [0 10 15 18 20 22 25 30 40 50 60 70 80 90 100]
                                        * '<S2>/SpringTorque'
                                        */
  real_T SpringTorque_YData[15];       /* Expression: [-20 -18 -17 -12 0 12 17 18 18 19 20 20 21 21 22]
                                        * '<S2>/SpringTorque'
                                        */
  real_T DampingConst_Value;           /* Expression: 1
                                        * '<S2>/Damping Const'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * '<S2>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S8>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * '<S7>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * '<S10>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * '<S9>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: gainval
                                         * '<S2>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * '<S2>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: gainval
                                          * '<S2>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 20
                                        * '<S2>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_UpperSa;/* Expression: 90
                                          * '<S2>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_LowerSa;/* Expression: 0
                                          * '<S2>/Discrete-Time Integrator1'
                                          */
  real_T Inertia_Value;                /* Expression: .3
                                        * '<S2>/Inertia'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * '<S2>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_eng_mdl_demo_v1 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[2];
    real_T odeF[3][2];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_eng_mdl_demo_v1 eng_mdl_demo_v1_P;

/* Block signals (auto storage) */
extern BlockIO_eng_mdl_demo_v1 eng_mdl_demo_v1_B;

/* Continuous states (auto storage) */
extern ContinuousStates_eng_mdl_demo_v eng_mdl_demo_v1_X;

/* Block states (auto storage) */
extern D_Work_eng_mdl_demo_v1 eng_mdl_demo_v1_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_eng_mdl_demo_v1 eng_mdl_demo_v1_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_eng_mdl_demo_v1 eng_mdl_demo_v1_Y;

/* Model entry point functions */
extern void eng_mdl_demo_v1_initialize(boolean_T firstTime);
extern void eng_mdl_demo_v1_output(int_T tid);
extern void eng_mdl_demo_v1_update(int_T tid);
extern void eng_mdl_demo_v1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_eng_mdl_demo_v1 *eng_mdl_demo_v1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : eng_mdl_demo_v1
 * '<S1>'   : eng_mdl_demo_v1/Combustion Torque Model
 * '<S2>'   : eng_mdl_demo_v1/ETC Motor Model
 * '<S3>'   : eng_mdl_demo_v1/Engine Speed
 * '<S4>'   : eng_mdl_demo_v1/Manifod Model
 * '<S5>'   : eng_mdl_demo_v1/ETC Motor Model/DeadStops
 * '<S6>'   : eng_mdl_demo_v1/ETC Motor Model/Motor
 * '<S7>'   : eng_mdl_demo_v1/ETC Motor Model/DeadStops/LowerStop
 * '<S8>'   : eng_mdl_demo_v1/ETC Motor Model/DeadStops/NegativeTorque
 * '<S9>'   : eng_mdl_demo_v1/ETC Motor Model/DeadStops/PositiveTorque
 * '<S10>'  : eng_mdl_demo_v1/ETC Motor Model/DeadStops/UpperStop
 * '<S11>'  : eng_mdl_demo_v1/ETC Motor Model/Motor/First Oder Filter
 * '<S12>'  : eng_mdl_demo_v1/Manifod Model/Intake Manifold
 * '<S13>'  : eng_mdl_demo_v1/Manifod Model/Throttle
 */
#endif                                 /* RTW_HEADER_eng_mdl_demo_v1_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_eng_mdl_demo_v1
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

Parameters_eng_mdl_demo_v1 rtParameter[NUMST+!TID01EQ];
Parameters_eng_mdl_demo_v1 *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

Parameters_eng_mdl_demo_v1 rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern Parameters_eng_mdl_demo_v1* param_lookup[NUMST][2];

#else

extern Parameters_eng_mdl_demo_v1 rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define eng_mdl_demo_v1_P              (*param_lookup[tid][READSIDE])
#else
#define eng_mdl_demo_v1_P              rtParameter[READSIDE]
#endif
#endif
#endif
