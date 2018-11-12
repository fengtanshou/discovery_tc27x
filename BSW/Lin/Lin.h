
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *           File:  Lin.h
 *      Component:  AUTOSAR LIN Driver
 *         Module:  DrvLin_TricoreAsr
 *      Generator:  DrvLin_TricoreAsr
 *
 *  Target system:  Tricore
 *       Compiler:  Tasking
 *                  GNU
 *
 *    Derivatives:  TC2XX
 *  
 *    Description:  Implementation of the AUTOSAR LIN Driver
 *                  Declaration of functions, variables and constants
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Lutz Pflueger                 vislpr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  04.00.00  2013-08-14  vislpr  ESCAN00069798 Implement new AUTOSAR 4, R7 LIN driver for Tricore Aurix
 *  05.00.00  2013-11-04  vislpr  ESCAN00071569 Implement AUTOSAR 4, R8  LIN driver for Tricore Aurix
 *                                ESCAN00070430 Enabling of the LIN Interface does not work
 *                                ESCAN00069442 Improve handling of BSW DBG Data
 *                                -             Improve frame handling at timing violation (frame delay)
 *            2013-11-12  vislpr  -             Justify Lin_Interrupt() due RTM complexity 
 *  06.00.00  2014-11-26  vislpr  -             R11, HL Part was updated
 *  07.00.00  2015-02-17  vislpr  ESCAN00081297 FEAT-427: SafeBSW Step I
 *  07.00.01  2015-03-16  vislpr  ESCAN00081849 Compiler error: Incompatible types at osWritePeripheral32() in Lin_Init()
 *  07.00.02  2015-06-23  vislpr  -             Update HL Part
 *  07.01.00  2015-07-08  vislpr  ESCAN00083857 Remove LinEnSettingOfISRConfiguration and LinEnSettingOfInputPinConfig switch
 *            2015-08-10  vislpr  ESCAN00081553 Value of BITCON.SM not clearly set
 *  07.01.01  2015-09-18  vislpr  -             Update HL Part
 *  07.01.02  2015-09-22  vislpr  ESCAN00085383 Compiler error:  #error "Source and Types Header are inconsistent (LIN_TPS_PATCH_VERSION)!"
 *  07.02.00  2016-01-19  vislpr  -             Update HL Part
 *  07.03.00  2016-04-13  vislpr  ESCAN00089454 Compiler error: Identifier "ApiId" is undefined
 *                                -             Update HL Part
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Friedrich Kiesel              visfki        Vector Informatik GmbH
 *  Lutz Pflueger                 vislpr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY - CORE -
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  04.00.00  2012-07-20  visfki  ESCAN00059300 Implementation of High Level AUTOSAR 4 LIN Driver
 *  04.01.00  2012-11-20  visfki  ESCAN00061782 AR4-220: Remove STATIC
 *                                ESCAN00063147 Rename Lin_WakeUp to Lin_Wakeup
 *  04.02.00  2013-02-08  visfki  ESCAN00064956 AR4-325: Implement Post-Build Loadable
 *                                ESCAN00065149 Compiler error: LIN_CH_OPERATIONAL changed in ASR4 to LIN_OPERATIONAL
 *  05.00.00  2013-09-19  vislpr  ESCAN00066851 Improve include structure for EcuM headers
 *                                ESCAN00079533 AR4-260: Remove ProdErrorDetection configuration switch
 *                                ESCAN00069952 Justify MISRA Warnings on functions
 *                                ESCAN00067708 AR4-328: Predefined Runtime Measurement Points
 *  05.00.01  2013-11-19  vislpr  ESCAN00071647 Remove MISRA warning 0850/3453
 *                                ESCAN00072030 Change RTM macros
 *  05.00.02  2013-11-21  vislpr  ESCAN00072030 Fix MISRA Warnings and GNU Compiler error on RTM
 *  06.00.00  2014-10-01  vislpr  ESCAN00076482 AR4-832: External wake up via LIN transceiver
 *                                ESCAN00078696 AR4-698: Post-Build Selectable (Identity Manager)
 *  06.00.01  2014-11-14  vislpr  ESCAN00079471 Compiler error: lin.c: 'Lin_Dev_InitDetect'/'LIN_DEV_INITVALUE'
 *  06.00.02  2014-11-14  vislpr  ESCAN00079588 Compiler error: Identifier Channel not declared
 *  06.00.03  2014-12-02  vislpr  -             Change wakeup handling
 *  07.00.00  2014-12-12  vislpr  ESCAN00080307 FEAT-427: SafeBSW Step I
 *  07.00.01  2015-01-27  vislpr  ESCAN00080823 Add channel DET check for out of bounds of channel id and channel idx
 *                        vislpr  ESCAN00080824 Use LOCAL_INLINE macro of Compiler.h instead "static inline"
 *  07.00.02  2015-03-26  vislpr  ESCAN00082080 Remove redundant code in Lin_GoToSleep
 *  07.00.03  2015-05-26  vislpr  ESCAN00083154 Dem.h not included if Dem repoting enabled
 *                        vislpr  ESCAN00083156 EcuM_BswErrorHook() are used on precompile with Selectable enabled
 *  07.01.00  2015-07-13  vislpr  ESCAN00081794 FEAT-1275: SafeBSW Step 2
 *  07.01.01  2015-09-15  vislpr  ESCAN00085267 Unkown return value 0x01u of Lin_GetStatus() in case of LIN_TX_BUSY error
 *  07.01.02  2015-10-23  vislpr  ESCAN00086056 Check data length parameter of Lin_SendFrame()
 *  07.02.00  2015-11-04  vislpr  ESCAN00086254 Unification the register base address struct and typedef for each driver
 *            2015-11-04  vislpr  ESCAN00086267 Code refactoring
 *            2015-11-16  vislpr  ESCAN00086493 Remove Lin_GetRxPin() Macro.
 *            2015-11-16  vislpr  ESCAN00086494 Do not set the state to wake after calling Lin_CheckWakeup()
 *            2015-11-17  vislpr  ESCAN00086546 Inconsistency of wakeup support between Lin, LinIf and EcuM in variant Post Build
 *  07.03.00  2016-01-27  vislpr  ESCAN00087812 FEAT-1688: SafeBSW Step 4
 *  07.03.01  2016-03-16  vislpr  -             SafeBSW review rework
 *  07.04.00  2016-04-13  vislpr  -             SafeBSW review rework (ISR)
 *  07.04.01  2016-05-23  vislpr  -             SafeBSW review rework
 *********************************************************************************************************************/

#if !defined (LIN_H)
#define LIN_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Lin_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Component version information (decimal version of ALM implementation package) */
#define LIN_SW_MAJOR_VERSION 7
#define LIN_SW_MINOR_VERSION 3
#define LIN_SW_PATCH_VERSION 0

/* Vendor and module identification */
#define LIN_VENDOR_ID 0x001Eu       /*!< Vendor ID: Vector Informatik GmbH. */
#define LIN_MODULE_ID ((uint16)82)  /*!< Module ID: DrvLin */

/* AUTOSAR Software specification version information */
#define LIN_AR_RELEASE_MAJOR_VERSION 0x04u
#define LIN_AR_RELEASE_MINOR_VERSION 0x00u
#define LIN_AR_RELEASE_PATCH_VERSION 0x03u

/* API service IDs */
#define LIN_SID_INIT_ID              0x00u /*!< Service ID: Lin_Init() */
#define LIN_SID_GETVERSIONINFO_ID    0x01u /*!< Service ID: Lin_GetVersionInfo() */
#define LIN_SID_SENDFRAME_ID         0x04u /*!< Service ID: Lin_SendFrame() */
#define LIN_SID_GOTOSLEEP_ID         0x06u /*!< Service ID: Lin_GoToSleep() */
#define LIN_SID_WAKEUP_ID            0x07u /*!< Service ID: Lin_Wakeup() */
#define LIN_SID_GETSTATUS_ID         0x08u /*!< Service ID: Lin_GetStatus() */
#define LIN_SID_GOTOSLEEPINTERNAL_ID 0x09u /*!< Service ID: Lin_GoToSleepInternal() */
#define LIN_SID_CHECKWAKEUP_ID       0x0Au /*!< Service ID: Lin_CheckWakeup() */
#define LIN_SID_WAKEUPINTERNAL_ID    0x0Bu /*!< Service ID: Lin_WakeupInternal() */
#define LIN_SID_INTERRUPT_ID         0x90u /*!< Service ID: Lin_Interrupt() */

/* Interrupt calling type */
#define LIN_ISR_CAT2 0x00u /*!< Interrupt category 2: Using Os (ISR() macro) */
#define LIN_ISR_CAT1 0x01u /*!< Interrupt category 1: Call ISR direct (compiler depend) */
#define LIN_ISR_VOID 0x02u /*!< Use ISR void/void prototype */

/* Generator compatibility version */
#define LIN_HL_GENERATORMSR_COMPATIBILITY_VERSION 0x1400u /*!< Compatibilitiy version of base Generator */
#define LIN_LL_GENERATORMSR_COMPATIBILITY_VERSION 0x1400u /*!< Compatibilitiy version of platform Generator */

/* Error codes */
#define LIN_E_NO_ERROR         0xFFu /*!< No error. */
#define LIN_E_UNINIT           0x00u /*!< API service used without module initialization. */
#define LIN_E_INVALID_CHANNEL  0x02u /*!< API service used with an invalid or inactive channel parameter. */
#define LIN_E_INVALID_POINTER  0x03u /*!< API service called with invalid configuration pointer. */
#define LIN_E_STATE_TRANSITION 0x04u /*!< Invalid state transition for the current state. */
#define LIN_E_PARAM_POINTER    0x05u /*!< API service called with a NULL pointer. */
#define LIN_E_PARAM_VALUE      0x06u /*!< API service called with invalid parameter value. */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define LIN_START_SEC_CODE_ISR
#include "MemMap.h"
/***********************************************************************************************************************
 *  Lin_Interrupt
 **********************************************************************************************************************/
/*! \brief       Interrupt processing function.
 *  \details     Handles the internal state machine.
 *  \param[in]   ChanneHw ChannelHw index (not Channel ID) of configuration from where the interrupt occurred.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous FALSE
 *  \note        The user should not call this function directly.
 *  \trace       CREQ-208, CREQ-209, CREQ-211, CREQ-217, CREQ-224, DSGN-Lin23162, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(void, LIN_CODE_ISR) Lin_Interrupt( uint8 ChannelHw );
#define LIN_STOP_SEC_CODE_ISR
#include "MemMap.h"


#define LIN_START_SEC_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *  Lin_InitMemory
 **********************************************************************************************************************/
/*! \brief       Initializes the module memory.
 *  \details     Sets the module state to uninitialized. Must be called in case LIN_VAR_ZERO_INIT variables are not
 *               initialized with 0 after reset.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This service function has to be called before Lin_Init() function.
 *  \trace       CREQ-216, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_InitMemory( void );

/***********************************************************************************************************************
 *  Lin_Init
 **********************************************************************************************************************/
/*! \brief       Initializes the Lin Driver.
 *  \details     Initializes the LIN module channel hardware and sets the state to initialize.
 *  \param[in]   Config: Pointer to a selected configuration structure.
 *  \pre         Lin interrupts must be locked.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-216, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_Init( P2CONST(Lin_ConfigType, AUTOMATIC, LIN_PBCFG) Config );

#if ( LIN_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  Lin_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns the version information of this module as decimal numbers. 
 *  \param[in]   versioninfo: Pointer to where to store the version information of this module. The version information
 *                            are in decimal.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-214
 *  \note        Configuration parameter LinVersionInfoApi must be enabled.
 **********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_VAR) versioninfo );
#endif

/***********************************************************************************************************************
 *  Lin_SendFrame
 **********************************************************************************************************************/
/*! \brief       Generates a LIN frame.
 *  \details     Generates a LIN frame on the addressed LIN channel.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \param[in]   PduInfoPtr: Pointer to PDU containing the PID, Checksum model, Response type, Dl and SDU data pointer.
 *  \return      E_OK: send command has been accepted.
 *  \return      E_NOT_OK: send command has not been accepted, development or production error occurred.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous FALSE
 *  \trace       CREQ-208, DSGN-Lin23162
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame( uint8 Channel, P2VAR(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr );

/***********************************************************************************************************************
 *  Lin_GoToSleep
 **********************************************************************************************************************/
/*! \brief       Transmits a go-to-sleep command.
 *  \details     Transmits a go-to-sleep command on the addressed LIN channel and sets the channel into sleep mode.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Sleep command has been accepted.
 *  \return      E_NOT_OK: Sleep command has not been accepted, development or production error occurred.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous FALSE
 *  \trace       CREQ-209, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep( uint8 Channel );

/***********************************************************************************************************************
 *  Lin_GoToSleepInternal
 **********************************************************************************************************************/
/*! \brief       Sets the channel to sleep mode.
 *  \details     Sets the channel to sleep mode without sending a go-to-sleep command.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Sleep command has been accepted
 *  \return      E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous TRUE
 *  \trace       CREQ-209, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal( uint8 Channel );

/***********************************************************************************************************************
 *  Lin_Wakeup
 **********************************************************************************************************************/
/*! \brief       Sends a wakeup frame.
 *  \details     Sends a wakeup frame on the addressed LIN channel.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Wake-up request has been accepted.
 *  \return      E_NOT_OK: Wake-up request has not been accepted, development or production error occurred.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous FALSE
 *  \trace       CREQ-211, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup( uint8 Channel );

/***********************************************************************************************************************
 *  Lin_WakeupInternal
 **********************************************************************************************************************/
/*! \brief       Sets the channel state to LIN_CH_OPERATIONAL.
 *  \details     Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Wake-up request has been accepted
 *  \return      E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 *  \pre         LIN interrupts for hardware channel of Channel must be locked..
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous TRUE
 *  \trace       CREQ-211, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal( uint8 Channel );

/***********************************************************************************************************************
 *  Lin_CheckWakeup
 **********************************************************************************************************************/
/*! \brief       Checks if a wakeup has occurred on the addressed Lin Channel.
 *  \details     Lin_CheckWakeup called by the LIN Interface module to identify the corresponding LIN channel. If a
 *               wakeup occurred on the channel the status are reported to LinIf and EcuM.
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: No error has occurred during execution of the API
 *  \return      E_NOT_OK:  An error has occurred during execution of the API
 *  \pre         The LIN driver shall have been initialized before this service is called.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous TRUE
 *  \trace       CREQ-217, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup( uint8 Channel );

/***********************************************************************************************************************
 *  Lin_GetStatus
 **********************************************************************************************************************/
/*! \brief       Returns the Status.
 *  \details     Returns the Status and sets the Status to operational if necessary (wrong or no interrupt occurred).
 *  \param[in]   Channel: LIN channel to be addressed
 *  \param[out]  Lin_SduPtr: Pointer to pointer to shadow buffer or memory mapped LIN Hardware receive buffer
 *  \return      Lin_StatusType: Information about the current message state.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous TRUE
 *  \note        Do not poll this function. On some platform calling this function on an ongoing frame
 *               transmission/reception disrupt the frame transmission/reception.
 *  \trace       CREQ-208, CREQ-209, CREQ-211, DSGN-Lin23162, DSGN-Lin22334
 **********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus( uint8 Channel, P2VAR(Lin_u8PtrType, AUTOMATIC, LIN_APPL_VAR) Lin_SduPtr );
#define LIN_STOP_SEC_CODE
#include "MemMap.h"


#endif /* LIN_H */

/**********************************************************************************************************************
 *  END OF FILE: Lin.h
 *********************************************************************************************************************/

