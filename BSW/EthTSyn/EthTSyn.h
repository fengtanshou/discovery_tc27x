/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  EthTSyn.h
 *        \brief  EthTSyn module header file
 *
 *      \details  Contains all public function declarations and global definitions with respect to the EthTSyn module
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Jeroen Laverman               vislje        Vector Informatik
 *  Michael Seidenspinner         vissem        Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2014-08-28  vislje  ESCAN00077557 created
 *            2014-09-23  vislje  -             Support for Software-Timestamping added
 *                                              Added Bugfixes / Features from SysService_Gptp802As[1.01.01]
 *            2014-09-24  vislje  -             Changed SyncSend[].TxConfirmationPending to sint8 
 *            2014-10-23  vislje  -             Organization of types
 *  01.00.01  2014-11-11  vislje  ESCAN00079492 Module causes DET in Eth-Module at initialization
 *                        vissem  ESCAN00079841 Added missing DET to MainFunction
 *                                -             Changed Module ID from 676 to 164
 *                                -             Added EthTSyn_SetTransmissionMode API
 *  01.00.02  2014-11-21  vissem  ESCAN00079837 Pdelay calculation is not valid if Pdelay responder response very fast
 *                                ESCAN00079849 Unexpected behavior of API EthTSyn_SetTransmissionMode
 *                                ESCAN00079853 Wrong RequestingPortNumber of PdelayRespFollowUp message undetected
 *            2015-01-07  vissem  ESCAN00080431 Compiler error: Wrong DET in EthTSyn_SetTransmissionMode 
 *  01.01.00  2015-02-17  vissem  ESCAN00081290 Timestamp is not sent correctly
 *            2015-02-18  vissem  ESCAN00080071 FEAT-1268: Add timestamp support (STBM) in software for EthTSyn
 *            2015-02-27  vissem  ESCAN00081498 Wrong Transceiver Link State/Enabled Flag after Re-Initialization of
 *                                              EthTSyn
 *            2015-03-03  vissem  ESCAN00081543 Negative Pdelay leads to AsCapable = false
 *            2015-03-24  vissem  ESCAN00081965 Incorrect TimestampType in EthTSyn_SetGlobalTime 
 *  01.01.01  2015-04-22  vissem  ESCAN00082125 Code Clean-Up and correction of issues found by review
 *  01.01.02  2015-07-07  vissem  ESCAN00083506 Compiler warning: Unused variable IngressTimestampRaw
 *                                ESCAN00083505 Compiler warning: Unused variable TimestampQuality
 *                                ESCAN00083508 Compiler warning: Declared but unused function
 *                                              EthTSyn_RawTimeToTimestamp
 *                                ESCAN00083507 Compiler warning: Declared but unused function:
 *                                              EthTSyn_ProcessSmSiteSyncSync
 *                                ESCAN00083497 Os Error Hook: Disabled Interrupts
 *                                ESCAN00083503 Synchronized time in Time Slave lags behind
 *            2015-07-08  vissem  ESCAN00083501 Time calculated by EthTsyn lags behind real time
 *                                ESCAN00083638 Compiler warning: EthTSyn - Possible loss of data due to implicit type
 *                                              conversion
 *                                ESCAN00084291 Compiler error: C2440: 'function' : cannot convert from
 *                                              'EthTSyn_GlobalTimestampType' to 'Eth_TimeStampType'
 *  01.02.00  2015-07-09  vissem  ESCAN00083859 Adopt Type of DataPtr in EthTSyn_RxIndication
 *                                ESCAN00083403 StbM_TimeStampRawType is not compatible to AR 4.2.1
 *            2015-07-22  vissem  ESCAN00084123 Removed AUTOSAR Version filter
 *  01.02.01  2015-08-14  vissem  ESCAN00084533 Calculation of RateRatio is incorrect
 *  02.00.00  2015-09-01  vissem  ESCAN00085374 FEAT-1529: Support Ethernet Switches for Ethernet Time Sync
 *                                ESCAN00085671 FEAT-1555: Ethernet Stack Bugfixing
 *            2015-10-01  vissem  ESCAN00085562 Invalid Pointer passed to EthIf_GetIngressTimestamp
 *            2015-10-12  vissem  ESCAN00085796 Valid PDelay_Resp_FollowUp is discarded
 *            2015-10-14  vissem  ESCAN00085769 EthTSyn issues a DET error if a gPTP frame is received on a network/VLAN
 *                                              on which EthTSyn itself is not active
 *                        vissem  ESCAN00084129 Allow the use of always AsCapable
 *                        vissem  ESCAN00085186 AUTOSAR 4.2.2 API adoptions
 *                        vissem  ESCAN00085629 Incompatible Timestamp types
 *  02.00.01  2016-01-26  vissem  ESCAN00087452 FollowUp-CorrectionField is not taken into account at the
 *                                              synchronization of a Time-Slave
 *  02.00.02  2016-02-19  vissem  ESCAN00088420 Review Integration
 *  02.01.00  2016-04-01  vissem  ESCAN00087687 FEAT-1691: EthTSyn shall support RateCorrection as OffsetCorrection
 *                                              and/or FrequencyRateCorrection below and above SynchronizationThreshold
 *                                ESCAN00084951 Added support of RateRatio for SW-Timestamping
 *                                ESCAN00087691 FEAT-1689: Each Time Communication Port shall be able to support
 *                                              Time Master & Time Slave functionality in parallel
 *                                ESCAN00088535 Time slave does not synchronize to the time master without former
 *                                              Announce message
 *                                ESCAN00086975 EthTSyn does not release TxBuffers if the transmission failed
 *                                ESCAN00088539 In a Time-Aware-Bridge the modification of the SourcePortIdenty is now
 *                                              optional
 *                                ESCAN00088655 EthTSyn_Cbk_TrcvLinkStateChg renamed to EthTSyn_TrcvLinkStateChg 
 *                                              (according to AUTOSAR 4.2.2)
 *                                ESCAN00088877 StbM_SetGlobalTime() is called instead of StbM_BusSetGlobalTime()
 *                                ESCAN00088493 FEAT-1694: Time Gateway shall be supported and EthTSyn shall support
 *                                              Boundary Clock on each Time Master Port
 *                                ESCAN00088660 Added SourcePortIdentity check for Sync/FollowUp messages received
 *                                              by a slave port
 *                                ESCAN00087695 FEAT-1201: Release of FEAT-971 ETH only
 *                                              (Time Sync over Ethernet module development) [AR4-954]
 *  02.02.00  2016-05-13  vissem  ESCAN00089687 FEAT-1987: Support of flexible Pdelay configuration
 *  02.02.01  2016-06-24  vissem  ESCAN00090251 Synchronization might be erroneous if corrective action RATE_RATIO is
 *                                              used
 *  03.00.00  2016-11-25  vissem  ESCAN00091272 Compiler error: #154: expression must have struct or union type
 *                                FEATC-248     FEAT-1998: Support of HW Time Stamping for Switch for EthTSyn
 *                                              (SysService_AsrTSynEth)
 *                                ESCAN00091957 Inconsistent use of the configuration parameter
 *                                              EthTSynGlobalTimeFollowUpTimeout
 *                                ESCAN00092113 Added support of the configuration parameter
 *                                              EthTSynTimeHardwareCorrectionThreshold
 *                                ESCAN00091972 Missing comparison of the source port identity for
 *                                              received Sync/FollowUp
 *  03.00.01  2016-11-29  vissem  ESCAN00093066 Used EthTSyn_TimediffType is too small when HW-Timestamping is active
 *                                ESCAN00093137 Using RateRatio correction in conjunction if HW-Timestamping can cause
 *                                              an Os TickTime error
 *                                ESCAN00093131 EthIf_GetIngressTimestamp is called in invalid context
 *                                ESCAN00093296 DET may occur on transmission of FollowUp message or buffer data is
 *                                              overwritten
 *                                ESCAN00093361 DET may occur on transmission of Announce message or buffer data is
 *                                              overwritten
 *                                ESCAN00093326 Message buffers with invalid Switch Mgmt info are not released
 *                                ESCAN00093325 Received message with invalid switch information might not be dropped
 *                                ESCAN00093248 DET ETHTSYN_SWT_MGMT_E_NO_MSG_AVAILABLE is issued when
 *                                              EthTSyn_SwitchMgmtInfoIndication is called after a message was
 *                                              discarded by the EthTSyn
 *                                ESCAN00091834 Call of the OS-API GetCounterValue() during disabled interrupts
 *                                ESCAN00093366 Compiler error: Syntax error
 *                                ESCAN00093411 ResponseOriginTimestamp is always 0 after first Pdelay message flow
 *                                ESCAN00093384 Compiler error: EthIf_SwitchEnableEgressTimestamp declared implicitly
 *                                ESCAN00093247 Reception of Announce leads to DET ETHTSYN_E_INV_MSG_LENGTH
 *                                ESCAN00093327 Sync receive Timeout is supervised although Grandmaster Capable is
 *                                              disabled
 *  03.00.02  2017-01-24  vissem  ESCAN00093708 Precision of the RateRatio is insufficient when HW-Timestamping is used
 *  04.00.00  2017-03-31  vissem  ESCAN00093838 Misalignment exception during reception of a frame with odd length on
 *                                              RH850/V850 platform
 *                                ESCAN00093937 Message handling with enabled Switch Timestamping not working properly
 *                                FEATC-383     FEAT-2279: Time Synchronization acc. AR 4.3 for EthTSyn
 *  04.00.01  2017-04-18  vissem  ESCAN00094545 CrcTime1 value of the Time Secured SubTlv is invalid when SequenceId is
 *                                              included
 *                                ESCAN00094780 FollowUp IEEE Information Tlv invalid organization Id
 *  04.00.02  2017-05-03  vissem  ESCAN00094784 Compiler error: Multiple errors (e.g. undeclared identifier) with
 *                                              Switch Mgmt and Rx Announce support
 *                                ESCAN00094847 StbM APIs called with disabled interrupts
 *                                ESCAN00094973 Missing observation of EthTSynPdelayRespAndRespFollowUpTimeout
 *********************************************************************************************************************/

#if !defined(ETHTSYN_H)
# define ETHTSYN_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 MACRO_LIMIT */ /* MD_MSR_1.1_857 */
# include "EthTSyn_Cbk.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* vendor and module identification */
# define ETHTSYN_VENDOR_ID                             (30u)
# define ETHTSYN_MODULE_ID                             (164u)
# define ETHTSYN_INSTANCE_ID                           (0U)

/* AUTOSAR Software specification version information */
# define ETHTSYN_AR_RELEASE_MAJOR_VERSION              (0x04u)
# define ETHTSYN_AR_RELEASE_MINOR_VERSION              (0x03u)
# define ETHTSYN_AR_RELEASE_REVISION_VERSION           (0x00u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define ETHTSYN_SW_MAJOR_VERSION                      (4u)
# define ETHTSYN_SW_MINOR_VERSION                      (0u)
# define ETHTSYN_SW_PATCH_VERSION                      (2u)

/* ----- API service IDs ----- */
/* AR */
# define ETHTSYN_SID_INIT                              0x01U /*!< Service ID: EthTSyn_Init() */
# define ETHTSYN_SID_GET_VERSION_INFO                  0x02U /*!< Service ID: EthTSyn_GetVersionInfo() */
# define ETHTSYN_SID_SET_TRANSMISSION_MODE             0x05U /*!< Service ID: EthTSyn_SetTransmissionMode() */
# define ETHTSYN_SID_RX_INDICATION                     0x06U /*!< Service ID: EthTSyn_RxIndication() */
# define ETHTSYN_SID_TX_CONFIRMATION                   0x07U /*!< Service ID: EthTSyn_TxConfirmation() */
# define ETHTSYN_SID_TRCV_LINK_STATE_CHG               0x08U /*!< Service ID: EthTSyn_TrcvLinkStateChg() */
# define ETHTSYN_SID_MAIN_FUNCTION                     0x09U /*!< Service ID: EthTSyn_MainFunction() */

/* Non-AR */
# define ETHTSYN_SID_TIMESTAMP_MINUS_TIMESTAMP         0x50U /*!< Service ID: EthTSyn_TimestampMinusTimestamp() */
# define ETHTSYN_SID_TIMESTAMP_PLUS_TIMEDIFF           0x51U /*!< Service ID: EthTSyn_TimestampPlusTimediff() */

# define ETHTSYN_SID_QUALIFY_ANNOUNCE_MSG              0x60U /*!< Service ID: EthTSyn_QualifyAnnounceMsg() */
# define ETHTSYN_SID_TRANSMIT                          0x61U /*!< Service ID: EthTSyn_Transmit() */
# define ETHTSYN_SID_SM_SYNC_SEND                      0x62U /*!< Service ID: EthTSyn_ProcessSmSyncSend() */
# define ETHTSYN_SID_SM_SITE_SYNC_SYNC                 0x63U /*!< Service ID: EthTSyn_ProcessSmSiteSyncSync() */
# define ETHTSYN_SID_PROCESS_RECEIVED_SYNC             0x64U /*!< Service ID: EthTSyn_ProcessReceivedSyncMsg() */

/* ----- Error codes ----- */
/* AR runtime errors */
# define ETHTSYN_E_TMCONFLICT                          0x01U /*!< Time Master Conflict */
# define ETHTSYN_E_TSCONFLICT                          0x02U /*!< Time Slave Conflict */

/* AR development errors */
# define ETHTSYN_E_NOT_INITIALIZED                     0x20U /*!< API service used in un-initialized state */
# define ETHTSYN_E_INIT_FAILED                         0x21U /*!< EthTSyn initialization failed */
# define ETHTSYN_E_CTRL_IDX                            0x22U /*!< API called with invalid controller index */
# define ETHTSYN_E_PARAM_POINTER                       0x23U /*!< API called with invalid Pointer */
# define ETHTSYN_E_PARAM                               0x24U /*!< API called with invalid parameter */

/* Non-AR */
# define ETHTSYN_E_NO_ERROR                            0x00U /*!< no error occurred */

# define ETHTSYN_E_TX_FAILED                           0x30U /*!< Message transmission failed */
# define ETHTSYN_E_GET_INGRESS_TIMESTAMP_FAILED        0x31U /*!< Unable to retrieve ingress timestamp */
# define ETHTSYN_E_PDELAY_REQ_MSG_DROPPED              0x32U /*!< Dropped received Pdelay Req message */
# define ETHTSYN_E_PDELAY_RESP_MSG_DROPPED             0x33U /*!< Dropped received Pdelay Resp message */
# define ETHTSYN_E_PDELAY_RESP_FUP_MSG_DROPPED         0x34U /*!< Dropped received Pdelay Resp FollowUp message */
# define ETHTSYN_E_SYNC_MSG_DROPPED                    0x35U /*!< Dropped received Sync message */
# define ETHTSYN_E_FOLLOW_UP_MSG_DROPPED               0x36U /*!< Dropped received FollowUp message */
# define ETHTSYN_E_ANNOUNCE_MSG_DROPPED                0x37U /*!< Dropped received Announce message */
# define ETHTSYN_E_INV_MSG_LENGTH                      0x38U /*!< Received message with an invalid Message length */
# define ETHTSYN_E_INV_PROTOCOL_VERSION                0x39U /*!< Received message with an invalid Protocol Version */
# define ETHTSYN_E_INV_MSG_TYPE                        0x3AU /*!< Received message with an invalid Message Type */
# define ETHTSYN_E_INV_FRAME_TYPE                      0x3BU /*!< Received message with an invalid Frame Type */
# define ETHTSYN_E_INV_DOMAIN_NUMBER                   0x3CU /*!< Received message with an invalid Domain Number */
# define ETHTSYN_E_TRCV_DOWN                           0x3DU /*!< RxIndication called for inactive controller */
# define ETHTSYN_E_SRC_PORT_IDENT_CHECK_FAILED         0x3EU /*!< Source Port Identity check failed */
# define ETHTSYN_E_ANNOUNCE_CHECK_FAILED               0x3FU /*!< Announce check failed */

# define ETHTSYN_E_INTERNAL_ERROR                      0xFFU /*!< Internal error occurred */

/* PRQA L:MACRO_LIMIT */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_CODE
# include "MemMap.h"

# if (ETHTSYN_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  EthTSyn_GetVersionInfo
 *********************************************************************************************************************/
/**
  \brief        Return the BCD-coded version information of the EthTSyn module.
  \param[in]    VersionInfoPtr   Pointer to a memory location where the EthTSyn version information shall be stored.
  \return       none
  \context      This function can be called in any context.
  \availability This function is only available if EthTSynVersionInfoApi is enabled.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_GetVersionInfo(
    ETHTSYN_P2VAR(Std_VersionInfoType) VersionInfoPtr);
# endif /* (ETHTSYN_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_Init
 *********************************************************************************************************************/
/*! \brief        Initialization of the EthTSyn module
 *  \param[in]    CfgPtr   Pointer to post-build configuration or null pointer
 *  \return       none
 *  \note         This function must be called before using the module
 *  \pre          The function EthTSyn_InitMemory() must be called first
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_Init(
    ETHTSYN_P2CONSTCFGROOT(EthTSyn_ConfigType) CfgPtr);

/**********************************************************************************************************************
 *  EthTSyn_InitMemory
 *********************************************************************************************************************/
/**
  \brief        Memory initialization of the EthTSyn module
  \param        none
  \return       none
  \note         This function must be called before using the module
  \context      This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_InitMemory(void);

/**********************************************************************************************************************
 *  EthTSyn_TimestampPlusTimediff
 *********************************************************************************************************************/
/**
  \brief         Calculates the sum of a timestamps and a time difference
  \param[inout]  DestTimestampPtr       Pointer to timestamp where the first summand is stored and the
                                        sum is written
  \param[in]     TimediffPtr            Pointer the value where the time difference is stored
  \return        E_OK      Sum of added timestamps is valid
                 E_NOT_OK  Sum of added timestamps is invalid
  \pre           The function EthTSyn_Init() must be called first
  \context       This function can be called in any context.
 *********************************************************************************************************************/
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TimestampPlusTimediff(
    ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) DestTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_TimediffType)        TimediffPtr);

/**********************************************************************************************************************
 *  EthTSyn_TimestampMinusTimestamp
 *********************************************************************************************************************/
/**
  \brief         Calculates the time difference between Timestamp1 and Timestamp2 (diff = Timestamp1 - Timestamp2)
  \param[in]     Timestamp1Ptr          Pointer to timestamp of the first timestamp
  \param[in]     Timestamp2Ptr          Pointer to timestamp of the second timestamp
  \param[out]    TimediffPtr            Pointer to time difference between Timestamp1 and Timestamp2
  \return        E_OK      Timediff is valid
                 E_NOT_OK  Timediff is invalid
  \pre           The function EthTSyn_Init() must be called first
  \context       This function can be called in any context.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TimestampMinusTimestamp(
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) Timestamp1Ptr,
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) Timestamp2Ptr,
    ETHTSYN_P2VAR(EthTSyn_TimediffType)        TimediffPtr);

/**********************************************************************************************************************
 *  EthTSyn_SetTransmissionMode
 *********************************************************************************************************************/
/**
  \brief         This API is used to turn on and off the TX capabilities of the EthTSyn.
  \param[in]     CtrlIdx      Index of the Ethernet controller
  \param[in]     Mode         ETHTSYN_TX_OFF
                              ETHTSYN_TX_ON
  \return        none
  \pre           The function EthTSyn_Init() must be called first
  \context       This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_SetTransmissionMode(
    uint8                        CtrlIdx,
    EthTSyn_TransmissionModeType Mode);

/* PRQA L: STMIF */

# define ETHTSYN_STOP_SEC_CODE
# include "MemMap.h"

#endif /* ETHTSYN_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTSyn.h
 *********************************************************************************************************************/
