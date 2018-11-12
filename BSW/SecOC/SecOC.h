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
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SecOC.h
 *        \brief  MICROSAR  Secure Onboard Communication header file
 *
 *      \details  This is the implementation of the MICROSAR Secure Onboard Communication module.
 *                The basic software module is based on the AUTOSAR Communication specification.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Heiko Huebler                 vishho        Vector Informatik GmbH
 *  Gunnar Meiss                  visms         Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2014-08-14  vishho  ESCAN00077857 AR4-667: CONC_607_SecureOnboardCommunication
 *  01.00.01  2014-11-07  vishho  ESCAN00079423 include of PduR_SecOC.h misses and leads to compile errors
 *  01.00.02  2015-03-30  vishho  ESCAN00082132 Buffer overflow when truncated Freshness value is copied to Secured Pdu
 *  01.00.02  2015-03-30  vishho  ESCAN00082134 < overwrites its internal Key data buffer.
 *  01.01.00  2015-06-17  vishho  ESCAN00083471 FEAT-1475: SecOC-Extensions, TP, CSM and encryption
 *  01.01.00  2015-06-19  vishho  ESCAN00082484 Authentication of valid secured PDUs fails
 *  01.01.01  2015-10-27  vishho  ESCAN00086110 Compiler error: error #20: identifier "Cal_VerifyResultType" is undefined
 *  01.01.02  2015-11-17  vishho  ESCAN00086559 DET occurs if SecOC_StartOfReception is called with a NULL_PTR
 *  01.01.02  2015-11-17  vishho  ESCAN00086367 RTE VerificationStatus service is not called
 *  01.01.02  2015-11-20  vishho  ESCAN00086659 Truncated freshness value is written in Little Endian instead of Big Endian
 *  01.01.02  2015-12-08  vishho  ESCAN00086690 Compiler error: SecOC.c: Det.h: No such file or directory
 *  01.02.00  2016-02-25  visms   ESCAN00087833 FEAT-1631: Trigger Transmit API with SduLength In/Out according to ASR4.2.2
 *  02.00.00  2016-07-07  vishho  ESCAN00090889 FEAT-1574: SecOC extension
 *            2016-08-11  visms   ESCAN00091423 FEAT-1779: Release SecOC
 *            2016-08-12  visms   ESCAN00091447 Rx Authentication fails Using Csm
 *  03.00.00  2016-09-12  vishho  FEATC-305: FEAT-2001: SecOC
 *            2016-11-15  vishho  FEATC-457: SecOC
 *            2016-11-15  vishho  FEATC-379: SecOC Release
 *  03.00.01  2016-11-28  vishho  ESCAN00093038 Wrong MAC values
 *  03.00.02  2016-12-21  vishho  ESCAN00093402 Compiler error: 'SecOC_KeyMgt_isKeyAssigned' undefined; assuming extern returning int
 *  03.01.00  2017-02-20  vishho  FEATC-1168: SecOC use Parameter Names like in 4.3
 *            2017-03-07  vishho  ESCAN00094276 SecOCVerificationStatusCallout is not called with SECOC_FRESHNESSFAILURE if GetRxFreshnessValue returns E_NOT_OK
 *            2017-03-13  vishho  ESCAN00094308 Transmission trigger of an Authentic Tx Pdu will not lead to an Secured Pdu transmission
 *            2017-03-13  vishho  ESCAN00094318 Reception of authentic PDU not indicated by SecOC if CSM 4.3 is used asynchronous
 *            2017-03-16  vishho  ESCAN00094379 Message Linker evaluation leads to read from invalid pointer
 *********************************************************************************************************************/

#ifndef SECOC_H
# define SECOC_H

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* *INDENT-ON* */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "SecOC_Cfg.h"
# include "SecOC_Lcfg.h"
# include "SecOC_PBcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define SECOC_VENDOR_ID                           30U
# define SECOC_MODULE_ID                           150U
# define SECOC_INSTANCE_ID_DET                     0U

/**
  \defgroup  SecOCARReleaseVersion SecOC AUTOSAR release version number
  \brief  Version number of AUTOSAR release on which the appropriate implementation is based on.
  \{
*/
# define SECOC_AR_RELEASE_MAJOR_VERSION            4U
# define SECOC_AR_RELEASE_MINOR_VERSION            0U
# define SECOC_AR_RELEASE_REVISION_VERSION         3U
/**
  \}
*/

/**
  \defgroup  SecOCSWVersion SecOC version number
  \brief  Version number of this implementation.
  \{
*/
# define SECOC_SW_MAJOR_VERSION                    3U
# define SECOC_SW_MINOR_VERSION                    1U
# define SECOC_SW_PATCH_VERSION                    0U
/**
  \}
*/

/**
  \defgroup  SecOCApiIds SecOC Module Service Identifiers
  \brief  Unique identifier of a SECOC module service.
  \{
*/
/*! \brief Service ID: SecOC_Init() */
# define SECOC_SID_INIT                            1U
/*! \brief Service ID: SecOC_GetVersionInfo() */
# define SECOC_SID_GET_VERSION_INFO                2U
/*! \brief Service ID: SecOC_Transmit() */
# define SECOC_SID_TRANSMIT                        3U
/*! \brief Service ID: SecOC_CancelTransmit() */
# define SECOC_SID_CANCEL_TRANSMIT                 4U
/*! \brief Service ID: SecOC_DeInit() */
# define SECOC_SID_DE_INIT                         5U
/*! \brief Service ID: SecOC_AssociateKey() */
# define SECOC_SID_ASSOCIATE_KEY                   7U
/*! \brief Service ID: SecOC_FreshnessValueRead() */
# define SECOC_SID_FRESHNESS_VALUE_READ            8U
/*! \brief Service ID: SecOC_FreshnessValueWrite() */
# define SECOC_SID_FRESHNESS_VALUE_WRITE           9U
/*! \brief Service ID: SecOC_RxIndication() */
# define SECOC_SID_VERIFY_STATUS_OVERRIDE          11U
/*! \brief Service ID: SecOC_RxIndication() */
# define SECOC_SID_RX_INDICATION                   12U
/*! \brief Service ID: SecOC_TxConfirmation() */
# define SECOC_SID_TX_CONFIRMATION                 14U
/*! \brief Service ID: SecOC_TxConfirmation() */
# define SECOC_SID_TRIGGER_TRANSMIT                15U
/*! \brief Service ID: SecOC_CopyTxData() */
# define SECOC_SID_COPY_TX_DATA                    67U
/*! \brief Service ID: SecOC_CopyRxData() */
# define SECOC_SID_COPY_RX_DATA                    68U
/*! \brief Service ID: SecOC_TpRxIndication() */
# define SECOC_SID_TP_RX_INDICATION                69U
/*! \brief Service ID: SecOC_StartOfReception() */
# define SECOC_SID_START_OF_RECEPTION              70U
/*! \brief Service ID: SecOC_TpTxConfirmation() */
# define SECOC_SID_TP_TX_CONFIRMATION              72U
/*! \brief Service ID: SecOC_MainFunctionRx() */
# define SECOC_SID_MAIN_FUNCTION_RX                20U
/*! \brief Service ID: SecOC_MainFunctionTx() */
# define SECOC_SID_MAIN_FUNCTION_TX                21U
/**
  \}
*/

/**
  \defgroup  SecOCDetErrorCodes SecOC Det Error Codes
  \brief  SecOC development error IDs.
  \{
*/
/*! \brief this code is used to detect that no error occurred. Det_ReportError() is not called. */
# define SECOC_E_NO_ERROR                          0U
/*! \brief Error code: An API service was called with a NULL pointer */
# define SECOC_E_PARAM_POINTER                     1U
/*! \brief Error code: API service used without module initialization or PduR_Init called  */
# define SECOC_E_INVALID_REQUEST                   2U
/*! \brief Error code: Invalid I-PDU identifier */
# define SECOC_E_INVALID_PDU_SDU_ID                3U
/*! \brief Error code: Crypto service failed */
# define SECOC_E_CRYPTO_FAILURE                    4U
/*! \brief Error code: Unable to restore Freshness Value and key information from NVRAM */
# define SECOC_E_RESTORE_FAILURE                   5U
/*! \brief Error code: Freshness Value at limit */
# define SECOC_E_FRESHNESS_VALUE_AT_LIMIT          6U
/*! \brief Error code: An API service was called with an invalid parameter. */
# define SECOC_E_PARAM                             7U
/**
  \}
*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# if(SECOC_USE_INIT_POINTER == STD_ON)
#  define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*! \brief Pointer to the current configuration */
extern P2CONST(SecOC_ConfigType, SECOC_VAR_ZERO_INIT, SECOC_PBCFG) SecOC_ConfigDataPtr;
#  define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define SECOC_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_CopyAuthenticatorToSecuredPdu
**********************************************************************************************************************/
/*! \brief      Copies the Authenticator to the Secured PDU buffer. This function is only used internal!
    \param[in]  txPduId  tx PduId
    \param[in]  authenticatorArray  authenticator
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Authenticate_CopyAuthenticatorToSecuredPdu(SecOC_TxPduInfoIterType txPduId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) authenticatorArray);
# endif

# if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_IncrementBuildAttempts
**********************************************************************************************************************/
/*! \brief      Increments Build Attempts and checks if build attempts threshold is reached. This function is only used internal!
    \param[in]  rxPduId  Rx Pdu Id
    \return     E_OK     build attempts threshold not reached.
                E_NOT_OK build attempts threshold reached.
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Verify_IncrementBuildAttempts(SecOC_RxPduInfoIterType rxPduId);
# endif

# if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_IncrementAndCheckBuildAttempts
**********************************************************************************************************************/
/*! \brief      Increments the build attempts counter and checks if the configured build attempts threshold is reached.
    \param[in]  txPduId              tx PduId
    \return     none
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Authenticate_IncrementAndCheckBuildAttempts(SecOC_TxPduInfoIterType txPduId);
# endif

/* Service functions */
/***********************************************************************************************************************
 *  SecOC_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_InitMemory(void);

/**********************************************************************************************************************
 * SecOC_Init()
 **********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module SecOC. It initializes all variables and sets the module state to
 *              initialized.
 *  \param[in]  config   Configuration structure for initializing the module
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Init(P2CONST(SecOC_ConfigType, AUTOMATIC, SECOC_INIT_DATA) config);

/**********************************************************************************************************************
 * SecOC_DeInit()
 **********************************************************************************************************************/
/*! \brief      Deinitialization function
 *  \details    This function stops the secure onboard communication. All buffered I-PDU are removed and
 *              have to be optained again, if needed, after SecOC_Init has been called. By a call to SecOC_DeInit
 *              the AUTOSAR SecOC module is put into an not initialized state (SecOC_UNINIT).
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_DeInit(void);

# if (SECOC_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief      Returns the version information
 *  \details    SecOC_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out] versioninfo             Pointer to where to store the version information
 *  \pre        Input parameter must not be NULL.
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SECOC_APPL_DATA) versioninfo);
# endif

/***********************************************************************************************************************
 *  SecOC_Transmit()
 **********************************************************************************************************************/
/*! \brief      Transmits an Authentic I-PDU.
 *  \details    Function is called by the PduR to request authentication and transmission of an Authentic I-PDU.
 *  \param[in]  id              ID of the Authentic I-PDU to be transmitted.
 *  \param[in]  info            A pointer to a structure with Authentic I-PDU related data that shall be transmitted:
 *                              data length and pointer to I-SDU buffer
 *  \return     Std_ReturnType
 *              E_OK:      request is accepted by the SecOC module. transmission is continued.
 *              E_NOT_OK:  request is not accepted by the SecOC module. transmission is aborted.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_Transmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info);

# if (SECOC_ENABLE_KEY_INTERFACE == STD_ON)
/***********************************************************************************************************************
 *  SecOC_AssociateKey()
 **********************************************************************************************************************/
/*! \brief      Sets the key of the given key id.
 *  \details    Function associates a given key value to a given key id (see also parameter SecOCKeyID).
 *  \param[in]  keyID           Identifier of a local key slot.
 *  \param[in]  keyPtr          This element points to the key data or a key handle.
 *  \return     Std_ReturnType
 *              E_OK:       if successful
 *              E_NOT_OK:   if unsuccessful
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_AssociateKey(uint8 keyID, P2CONST(SecOC_KeyType, AUTOMATIC, SECOC_APPL_DATA) keyPtr);
# endif

/***********************************************************************************************************************
 *  SecOC_FreshnessValueRead()
 **********************************************************************************************************************/
/*! \brief      Reads the FreshnessValue
 *  \details    Function is used to read a specific Freshness Value value residing in the SecOC module.
 *  \param[in]  freshnessValueID Identifier of a specific Freshness Value.
 *  \param[out] counterValue     Holds the current value of the counter.
 *  \return     Std_ReturnType
 *              E_OK:      request successful
 *              E_NOT_OK:  request failed
 *  \deprecated This function is deprecated and will be removed with the next release. Use the generic freshness value interface instead.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValueRead(uint16 freshnessValueID, P2VAR(uint64, AUTOMATIC, SECOC_APPL_VAR) counterValue);

/***********************************************************************************************************************
 *  SecOC_FreshnessValueWrite()
 **********************************************************************************************************************/
/*! \brief      Writes the FreshnessValue
 *  \details    Function is used to write a specific Freshness Value value to the SecOC module.
 *  \param[in]  freshnessValueID Identifier of a specific Freshness Value.
 *  \param[in]  counterValue     Holds the counter value to be written.
 *  \return     Std_ReturnType
 *              E_OK:      request successful
 *              E_NOT_OK:  request failed
 *  \deprecated This function is deprecated and will be removed with the next release. Use the generic freshness value interface instead.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValueWrite(uint16 freshnessValueID, uint64 counterValue);

/***********************************************************************************************************************
 *  SecOC_VerifyStatusOverride()
 **********************************************************************************************************************/
/*!
 * \brief      Sets verification status override.
 * \details    This service provides the ability to override the VerifyStatus with "Fail" or "Pass" when using a specific Freshness Value
 *             to verify authenticity of data making up an I-PDU. Using this interface, VerifyStatus may be overridden
 *             1. Indefinitely for received I-PDUs which use the specific Freshness Value for authentication verification
 *             2. For a number of sequentially received I-PDUs which use the specific Freshness Value for authentication verification.
 * \param[in]  freshnessValueID           ID of the Freshness Value which when used to authenticate data, results in SecOC_VerifyStatus
 *                                        equal to OverrideStatus independent of the actual authentication status.
 * \param[in]  overrideStatus             0  = Override VerifyStatus to "Fail" until further notice
 *                                        1  = Override VerifyStatus to "Fail" until NumberOfMessagesToOverride is reached
 *                                        2  = Cancel Override of VerifyStatus
 *                                        41 = Override VerifyStatus to "Pass" until NumberOfMessagesToOverride is reached;
 *                                             only available if SecOCEnableForcedPassOverride is set to TRUE
 *
 * \param[in]  numberOfMessagesToOverride Number of sequential VerifyStatus to override when using a specific counter
 *                                        for authentication verification. This is only considered when OverrideStatus is equal to 1 or 41.
 * \return     Std_ReturnType
 *              E_OK:      request successful
 *              E_NOT_OK:  request failed
 * \context    TASK
 */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyStatusOverride(uint16 freshnessValueID, uint8 overrideStatus, uint8 numberOfMessagesToOverride);

/***********************************************************************************************************************
 *  SecOC_MainFunctionRx()
 **********************************************************************************************************************/
/*! \brief      Scheduled Main Function for the rx path
 *  \details    This function performs the processing of the SecOC module's authentication and verification processing for the rx path.
 **********************************************************************************************************************/
/* function defined in file 'SchM_SecOC.h' */

/***********************************************************************************************************************
 *  SecOC_MainFunctionRx()
 **********************************************************************************************************************/
/*! \brief      Scheduled Main Function for the tx path
 *  \details    This function performs the processing of the SecOC module's authentication and verification processing for the tx path.
 **********************************************************************************************************************/
/* function defined in file 'SchM_SecOC.h' */

# define SECOC_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/*!
* \exclusivearea SECOC_EXCLUSIVE_AREA_RXSTATE
* Ensures consistency of global RAM variables.
* \protects Global RAM variables used of Rx path.
* \usedin SecOC_MainFunctionRx, SecOC_RxIndication
* \exclude All functions provided by SecOC.
* \length SHORT depending on the API and the call graph.
* \endexclusivearea
*/

/*!
* \exclusivearea SECOC_EXCLUSIVE_AREA_TXSTATE
* Ensures consistency of global RAM variables.
* \protects Global RAM variables used of Tx path.
* \usedin SecOC_MainFunctionTx, SecOC_Transmit, SecOC_TxConfirmation, SecOC_TriggerTransmit
* \exclude All functions provided by SecOC.
* \length SHORT depending on the API and the call graph.
* \endexclusivearea
*/

/*!
* \exclusivearea SECOC_EXCLUSIVE_AREA_KEY_VALUE
* Ensures consistency of global RAM variables.
* \protects SecOC_KeyArray.
* \usedin SecOC_MainFunctionRx, SecOC_MainFunctionTx, SecOC_AssociateKey
* \exclude All functions provided by SecOC.
* \length SHORT depending on the API and the call graph.
* \endexclusivearea
*/

/*!
* \exclusivearea EXCLUSIVE_AREA_FRESHNESS_VALUE
* Ensures consistency of the global RAM variables.
* \protects SecOC_FreshnessValue.
* \usedin SecOC_MainFunctionTx, SecOC_FreshnessValueRead, SecOC_FreshnessValueWrite, SecOC_TriggerTransmit
* \exclude All functions provided by SecOC.
* \length SHORT depending on the API and the call graph.
* \endexclusivearea
*/

#endif /* SECOC_H */

/**********************************************************************************************************************
 *  END OF FILE: SecOC.h
 *********************************************************************************************************************/
