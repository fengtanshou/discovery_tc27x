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
/**        \file  Etm.c
 *        \brief  Etm source file
 *
 *      \details  Implementation of the Etm module
 *                (Ethernet Testability Module for TCP/IP for interaction with IxANVL from Ixia)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define ETM_SOURCE

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Etm.h"
#include "Etm_Priv.h"
#include "Etm_Lcfg.h"
#include "SchM_Etm.h"
#include "TcpIp.h"
#include "TcpIp_Priv.h"
#include "IpBase_Sock.h"
#include "IpBase_Copy.h"

#if (ETM_IPV6_ENABLED == STD_ON)
# include "TcpIp_Ndp.h"
# include "TcpIp_IpV6_Priv.h"
#endif /* (ETM_IPV6_ENABLED == STD_ON) */

#if (ETM_USERSCRIPT_ENABLED == STD_ON)

# if (ETM_ETHIF_ENABLED == STD_ON)
#  include "EthIf.h"
#  include "Eth_Types.h"
# endif /* (ETM_ETHIF_ENABLED == STD_ON) */

#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of Etm header file */
#if (  (ETM_SW_MAJOR_VERSION != (4U)) \
    || (ETM_SW_MINOR_VERSION != (2U)) \
    || (ETM_SW_PATCH_VERSION != (1U)) )
# error "Vendor specific version numbers of Etm.c and Etm.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

#define ETM_MIN(a, b)         (((a) <= (b)) ? (a) : (b)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_MAX(a, b)         (((a) <= (b)) ? (b) : (a)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (ETM_IPV4_ENABLED == STD_ON)
# define ETM_HTONL(a)         IPV4_HTONL(a)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define ETM_HTONS(a)         IPV4_HTONS(a)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define ETM_HTONS_UINT8(a)   IPV4_UINT8_HTONS(a) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define ETM_HTONL(a)         IPV6_HTONL(a)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define ETM_HTONS(a)         IPV6_HTONS(a)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define ETM_HTONS_UINT8(a)   IPV6_UINT8_HTONS(a) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Preprocessor define STATIC is no longer available in Compiler.h in MSR4 - provide local define */
#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define ETM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR(boolean, ETM_VAR_ZERO_INIT) Etm_ModuleInitialized = 0;

#define ETM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************/
 
#define ETM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR(boolean, ETM_VAR_NOINIT) Etm_ModuleInitAll;
STATIC VAR(boolean, ETM_VAR_NOINIT) Etm_IpV4LinkAssigned;
STATIC VAR(boolean, ETM_VAR_NOINIT) Etm_IpV6LinkAssigned;
STATIC VAR(boolean, ETM_VAR_NOINIT) Etm_DataProcessingMode;

#define ETM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************/

#define ETM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (ETM_USERSCRIPT_ENABLED == STD_ON)
STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_UserScript_Pid;
STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_UserScript_DataLength;
# endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */

STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_SendBufferLength;
STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_EventDestSocketId;
STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_SendDataCommandIsPending;
STATIC VAR(uint16, ETM_VAR_NOINIT) Etm_SendDataCommandAlreadySend;

#define ETM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************/

#define ETM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (ETM_USERSCRIPT_ENABLED == STD_ON)
STATIC VAR(uint8, ETM_VAR_NOINIT) Etm_UserScript_DataPtr[ETM_USERSCRIPT_MAX_COMMAND_SIZE]; /* PRQA S 3218 */ /* MD_Etm_8.7_3218 */
# endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */

STATIC VAR(TcpIp_SockAddrInXType, ETM_VAR_NOINIT) Etm_EventDestAddr;
STATIC VAR(uint8, ETM_VAR_NOINIT) Etm_SendBuffer[ETM_MESSAGE_LENGTH_MAX];
STATIC VAR(uint8, ETM_VAR_NOINIT) Etm_SendDataCommand[ETM_STUB_MAX_COMMAND_SIZE];

#define ETM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define ETM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Etm_InitMemory()
 **********************************************************************************************************************/
/*! \brief        Function for *_INIT_*-variable initialization
 *  \details      Service to initialize module global variables at power up. This function initializes the
 *                variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \param        void none
 *  \return       none
 *  \pre          Module is uninitialized.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_InitMemory(void)
{
  Etm_ModuleInitialized = FALSE;
}  /* Etm_InitMemory() */

/***********************************************************************************************************************
 *  Etm_Init()
 **********************************************************************************************************************/
/*! \brief        Initialization function
 *  \details      This function initializes the module Etm. It initializes all variables and sets the module state to
 *                initialized.
 *  \param[in]    ConfigPtr Configuration structure for initializing the module.
 *  \return       none
 *  \pre          Interrupts are disabled.
 *  \pre          Module is uninitialized.
 *  \pre          Etm_InitMemory has been called unless Etm_ModuleInitialized is initialized by start-up code.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 *  \note         Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_Init(ETM_P2C(Etm_ConfigType) ConfigPtr)
{
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnVoid(Etm_ModuleInitialized == FALSE, ETM_SID_INIT, ETM_E_ALREADY_INITIALIZED);
  /* ------------------------------------------------- */
  
  ETM_DUMMY_STATEMENT_CONST(ConfigPtr); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */

#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  Etm_UserScript_Pid = ETM_PID_USERSCRIPT__UNDEFINED;
  Etm_UserScript_DataLength = 0u;
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */
  ((ETM_P2V(TcpIp_SockAddrType))&Etm_EventDestAddr)->domain = TCPIP_AF_UNDEFINED; /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  Etm_SendBufferLength = 0u;
  Etm_EventDestSocketId = TCPIP_INV_SOCKET_ID;
  Etm_SendDataCommandIsPending = FALSE;
  Etm_SendDataCommandAlreadySend = 0u;

  Etm_ModuleInitAll = FALSE;
  Etm_IpV4LinkAssigned = FALSE;
  Etm_IpV6LinkAssigned = FALSE;
  Etm_DataProcessingMode = FALSE;  
  
  Etm_ModuleInitialized = TRUE;
} /* Etm_Init() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (ETM_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Etm_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief        Returns the version information
 *  \details      Etm_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]   VersionInfoPtr Pointer to where to store the version information. Parameter must not be NULL.
 *  \return       none
 *  \pre          none
 *  \context      TASK
 *  \reentrant    Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_GetVersionInfo(ETM_P2V(Std_VersionInfoType) VersionInfoPtr)
{
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnVoid(NULL_PTR != VersionInfoPtr, ETM_SID_GET_VERSION_INFO, ETM_E_NULL_POINTER);
  /* ------------------------------------------------- */

  VersionInfoPtr->vendorID = (ETM_VENDOR_ID);
  VersionInfoPtr->moduleID = (ETM_MODULE_ID);
  VersionInfoPtr->sw_major_version = (ETM_SW_MAJOR_VERSION);
  VersionInfoPtr->sw_minor_version = (ETM_SW_MINOR_VERSION);
  VersionInfoPtr->sw_patch_version = (ETM_SW_PATCH_VERSION);
} /* Etm_GetVersionInfo() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (ETM_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
 *  Etm_MainFunction()
 **********************************************************************************************************************/
/*! \brief        Schedules the Etm module. (Entry point for scheduling) 
 *  \param        void none
 *  \return       none
 *  \pre          Module is uninitialized.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_MainFunction(void)
{
  if(Etm_ModuleInitialized != TRUE)
  {
    Etm_ReportDetError(ETM_SID_MAIN_FUNCTION, ETM_E_NOT_INITIALIZED); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    return;
  }

#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  /* process pending script commands */
  if(Etm_UserScript_Pid != ETM_PID_USERSCRIPT__UNDEFINED)
  {
    (void)Etm_VProcessUserScriptCommandsPending();
    return;
  }
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */
  
  while(Etm_SendDataCommandIsPending == TRUE)
  {
    if(E_OK != Etm_VApiSendDataPending())
    {
      break;
    }
  }

  if(Etm_ModuleInitAll == FALSE)
  {
    /* Init ETMv4 */
    if(Etm_IpV4LinkAssigned == TRUE)
    {
      Etm_VOpenCommandChannel(ETM_CMD_CHAN_IDX_UDP_V4);
      Etm_VOpenCommandChannel(ETM_CMD_CHAN_IDX_TCP_V4);
    }

    /* Init ETMv6 */
    if(Etm_IpV6LinkAssigned == TRUE)
    {
      Etm_VOpenCommandChannel(ETM_CMD_CHAN_IDX_UDP_V6);
      Etm_VOpenCommandChannel(ETM_CMD_CHAN_IDX_TCP_V6);
    }
    
    if(((Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V4].ChannelState == ETM_CMD_CHAN_INACTIVE) /* NOT USED */ ||
        (Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V4].ChannelState == ETM_CMD_CHAN_ACTIVE)   /* READY */ ) &&
       ((Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V6].ChannelState == ETM_CMD_CHAN_INACTIVE) /* NOT USED */ ||
        (Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V6].ChannelState == ETM_CMD_CHAN_ACTIVE)   /* READY */ ) &&
       ((Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].ChannelState == ETM_CMD_CHAN_INACTIVE) /* NOT USED */ ||
        (Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].ChannelState == ETM_CMD_CHAN_ACTIVE)   /* READY */ ) &&
       ((Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].ChannelState == ETM_CMD_CHAN_INACTIVE) /* NOT USED */ ||
        (Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].ChannelState == ETM_CMD_CHAN_ACTIVE)   /* READY */))
    {
      /* All channels active or not used (inactive) */
      Etm_ModuleInitAll = TRUE;
    }

    return;
  }
} /* Etm_MainFunction() */ /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Etm_RxIndication()
 **********************************************************************************************************************/
/*! \brief        The TCP/IP stack calls this function after the reception of data on a socket.
 *  \param[in]    SocketId        Socket identifier of the related local socket resource.
 *  \param[in]    RemoteAddrPtr   Pointer to memory containing IP address and port of the remote host which sent the data.
 *  \param[in]    BufPtr          Pointer to the received data.
 *  \param[in]    BufLength       Data length of the received TCP segment or UDP datagram.
 *  \return       none
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Reentrant for different SocketIds. Non reentrant for the same SocketId.
 *  \synchronous  Synchronous.
 *  \warning      The frame buffer has to be released later.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_RxIndication(
  const TcpIp_SocketIdType SocketId,
  ETM_P2C(TcpIp_SockAddrType) RemoteAddrPtr,
  ETM_P2C(uint8) BufPtr,
  const uint16 BufLength)
{
  uint16 ReceivedSid = 0;
  Etm_HeaderType ReceivedHeader;
  (void)Etm_VGetNext16Bit(BufPtr, BufLength, ETM_MESSAGE_OFFSET_SID, &ReceivedSid);

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnVoid(ETM_COND_VALID_PTR(BufPtr), ETM_SID_RX_INDICATION, ETM_E_INV_POINTER);
  Etm_CheckDetErrorReturnVoid(ETM_COND_VALID_PTR(RemoteAddrPtr), ETM_SID_RX_INDICATION, ETM_E_INV_POINTER);
  Etm_CheckDetErrorReturnVoid(ETM_COND_VALID_DOMAIN(RemoteAddrPtr), ETM_SID_RX_INDICATION, ETM_E_INV_SOCK_ADDR_FAMILY);
  /* ------------------------------------------------- */
  
  if((ReceivedSid == ETM_STUB_SERVICE_ID) && 
    ((SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V6].SocketId) ||
   /*(SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].SocketId) ||*/
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C6].SocketId)))
  {
    ReceivedHeader.UsePhysAddr = FALSE;
    ReceivedHeader.ReceivedSocketId = SocketId;
    (void)IpBase_CopySockAddr((ETM_P2V(IpBase_SockAddrType))&(ReceivedHeader.ReceivedRemoteAddress), (ETM_P2C(IpBase_SockAddrType))RemoteAddrPtr); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    
    if(E_OK == Etm_VParseHeader(BufPtr, BufLength, &ReceivedHeader))
    {
      Etm_DataProcessingMode = TRUE;
    
      /* \trace SPEC-2168555 */
      (void)Etm_VProcessEtmCommands(&ReceivedHeader);
    }
    else
    {
      (void)Etm_VSendResponseWithoutPayload(&ReceivedHeader, ETM_RID_E_NOK);
    }

    return;
  }
  
  /* ETM Handling */
  if(Etm_DataProcessingMode == TRUE)
  {
    const uint8 TestChannelIndex = Etm_VFindTestChannelIndex(SocketId);

    if((TestChannelIndex != TCPIP_INV_SOCKET_ID) && ETM_COND_VALID_SOCKET_ID(SocketId))
    {
      /* channel found and valid */

      /* \trace SPEC-2171516 */
      if(Etm_TestChannels[TestChannelIndex].RecvFwdActive == TRUE)
      {
        /* data sould be forwarded */

        uint16 ForwardLength = ETM_MIN(BufLength, Etm_TestChannels[TestChannelIndex].RecvFwdMaxForward);

        if(Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength != ETM_FORWARD_FOREVER)
        {
          if(BufLength >= Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength)
          {
            ForwardLength = ETM_MIN(Etm_TestChannels[TestChannelIndex].RecvFwdMaxForward, Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength);

            Etm_TestChannels[TestChannelIndex].RecvFwdActive = FALSE;
            Etm_TestChannels[TestChannelIndex].RecvFwdDropCount = (uint32)(BufLength - Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength);
            Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength = 0u;
          }
          else
          {
            Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength -= BufLength;
          }
        }
        
#if (ETM_TCP_ENABLED == STD_ON)
        if(ETM_COND_VALID_TCP_SOCKET_ID(Etm_TestChannels[TestChannelIndex].SocketId))
        {
          /* consume 'all' received data. subtract dropcount (sould be zero) in case maxlength is reached */
          (void)TcpIp_TcpReceived(SocketId, (uint32)(BufLength - Etm_TestChannels[TestChannelIndex].RecvFwdDropCount));
        }
#endif

        {
          /* Build Event Header */
          Etm_HeaderType EventHeader;

          if(ETM_COND_VALID_UDP_SOCKET_ID(SocketId))
          {
            EventHeader.Gid = ETM_GID_UDP;
            EventHeader.Pid = ETM_PID_UDP_RECEIVE_AND_FORWARD;
            EventHeader.UsePhysAddr = FALSE;
          }
          else
          {
            EventHeader.Gid = ETM_GID_TCP;
            EventHeader.Pid = ETM_PID_TCP_RECEIVE_AND_FORWARD;
            EventHeader.UsePhysAddr = FALSE;
          }

          /* Set Event Payload */
          {
            uint16 Index = ETM_MESSAGE_LENGTH_HEADER;
            const uint16 AddressLength = ((RemoteAddrPtr->domain == TCPIP_AF_INET6) ? ETM_DATA_LEN_ADDRESS_IPV6 : ETM_DATA_LEN_ADDRESS_IPV4);

            (void)Etm_VSetNext16Bit(BufLength, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX);
            Index += 2u;

            if(ETM_COND_VALID_UDP_SOCKET_ID(SocketId))
            {
              (void)Etm_VSetNext16Bit(ETM_HTONS(((ETM_P2C(TcpIp_SockAddrInetType))RemoteAddrPtr)->port), Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
              Index += 2u;
              (void)Etm_VSetNext16Bit(AddressLength, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX);
              Index += 2u;
              IpBase_Copy(&Etm_SendBuffer[Index], &(((ETM_P2C(TcpIp_SockAddrInet6Type))RemoteAddrPtr)->addr), AddressLength);
              Index += AddressLength;
            }

            (void)Etm_VSetNext16Bit(ForwardLength, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX);
            Index += 2u;
            IpBase_Copy(&Etm_SendBuffer[Index], BufPtr, ForwardLength);
            Index += ForwardLength;
            Etm_SendBufferLength = Index;

            /* Send Event */
            (void)Etm_VSendEvent(&EventHeader);
          }
        }
      }
      else
      {
        /* data sould not be forwarded */

        Etm_TestChannels[TestChannelIndex].RecvFwdDropCount += BufLength;
      }
    }

    return;
  }
} /* Etm_RxIndication() */ /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Etm_EthIf_RxIndication()
 **********************************************************************************************************************/
/*! \brief        Indicates the reception of an Ethernet frame.
 *  \param[in]    CtrlIdx       Index of the Ethernet controller within the context of the Ethernet Interface.
 *  \param[in]    FrameType     Frame type of received Ethernet frame.
 *  \param[in]    IsBroadcast   Parameter to indicate a broadcast frame.
 *  \param[in]    PhysAddrPtr   Pointer to Physical source address (MAC address in network byte order) of received Ethernet frame.
 *  \param[in]    DataPtr       Pointer to payload of the received Ethernet frame (i.e. Ethernet header is not provided).
 *  \param[in]    LenByte       Length of received data.
 *  \return       none
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Don't care.
 *  \synchronous  --
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_EthIf_RxIndication(
  const uint8 CtrlIdx,
  const Eth_FrameType FrameType,
  const boolean IsBroadcast,
  ETM_P2C(uint8) PhysAddrPtr,
  ETM_P2C(uint8) DataPtr,
  const uint16 LenByte)
{
#if ((ETM_ETHIF_ENABLED == STD_ON) && (ETM_USERSCRIPT_ENABLED == STD_ON))

  /* PRQA S 3112 3 */ /* MD_Etm_14.2_3112 */
  ETM_DUMMY_STATEMENT_CONST(IsBroadcast);

  if((FrameType == ETM_ETHIF_FRAME_TYPE)
    && (LenByte >= ETM_MESSAGE_LENGTH_HEADER))
  {
    uint16 ReceivedSid = 0u;
    Etm_HeaderType ReceivedHeader;
    (void)Etm_VGetNext16Bit(DataPtr, LenByte, ETM_MESSAGE_OFFSET_SID, &ReceivedSid);
  
    if(ReceivedSid == ETM_STUB_SERVICE_ID)
    {
      ReceivedHeader.UsePhysAddr = TRUE;
      ReceivedHeader.ReceivedCtrlIdx = CtrlIdx;
      ReceivedHeader.ReceivedSocketId = 0u;
      IpBase_Copy(&(ReceivedHeader.ReceivedRemotePhysAddr), PhysAddrPtr, ETH_PHYS_ADDR_LEN_BYTE);

      if(E_OK == Etm_VParseHeader(DataPtr, LenByte, &ReceivedHeader))
      {
        if(ReceivedHeader.Gid == ETM_GID_USERSCRIPT)
        {
          (void)Etm_VProcessUserScriptCommands(&ReceivedHeader);
        }
        else
        {
          (void)Etm_VSendResponseWithoutPayload(&ReceivedHeader, ETM_RID_E_NTF);
        }
      }
      else
      {
        (void)Etm_VSendResponseWithoutPayload(&ReceivedHeader, ETM_RID_E_NOK);
      }
    }
  }
#else
  /* PRQA S 3112 6 */ /* MD_Etm_14.2_3112 */
  ETM_DUMMY_STATEMENT_CONST(CtrlIdx);
  ETM_DUMMY_STATEMENT_CONST(FrameType);
  ETM_DUMMY_STATEMENT_CONST(IsBroadcast);
  ETM_DUMMY_STATEMENT_CONST(PhysAddrPtr);
  ETM_DUMMY_STATEMENT_CONST(DataPtr);
  ETM_DUMMY_STATEMENT_CONST(LenByte);
#endif /* ((ETM_ETHIF_ENABLED == STD_ON) && (ETM_USERSCRIPT_ENABLED == STD_ON)) */
} /*  Etm_EthIf_RxIndication() */ /* PRQA S 6030, 6060 */ /* MD_MSR_STCYC, MD_MSR_STPAR */

/***********************************************************************************************************************
 *  Etm_TcpAccepted()
 **********************************************************************************************************************/
/*! \brief        This function gets called if the stack put a socket into the listen mode before (as server) and a peer
                  connected to it (as client).
 *  \details      The TCP/IP stack calls this function after a socket was set into the listen state with TcpIp_TcpListen()
                  and a TCP connection is requested by the peer. 
 *  \param[in]    SocketId            Socket identifier of the related local socket resource which has been used at TcpIp_Bind().
 *  \param[in]    SocketIdConnected   Socket identifier of the local socket resource used for the established connection.
 *  \param[in]    RemoteAddrPtr       IP address and port of the remote host.
 *  \return       E_OK                Accepts the established connection.
 *  \return       E_NOT_OK            Refuses the established connection, TcpIp stack shall close the connection.
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETM_CODE) Etm_TcpAccepted(
  const TcpIp_SocketIdType SocketId,
  const TcpIp_SocketIdType SocketIdConnected,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, ETM_APPL_DATA) RemoteAddrPtr)
{
  if(Etm_DataProcessingMode == TRUE)
  {
    /* Etm_TcpPreAccepted allready called */

    const uint8 TestChannelIndexA = Etm_VFindTestChannelIndex(SocketId);
    const uint8 TestChannelIndexB = Etm_VFindTestChannelIndex(SocketIdConnected);

    if((TestChannelIndexA != TCPIP_INV_SOCKET_ID) && (TestChannelIndexB != TCPIP_INV_SOCKET_ID))
    {
      uint16 Index = ETM_MESSAGE_LENGTH_HEADER;
      const uint16 AddressLength = ((RemoteAddrPtr->domain == TCPIP_AF_INET6) ? ETM_DATA_LEN_ADDRESS_IPV6 : ETM_DATA_LEN_ADDRESS_IPV4);

      /* Build Event Header */
      Etm_HeaderType EventHeader;
      EventHeader.Gid = ETM_GID_TCP;
      EventHeader.Pid = ETM_PID_TCP_LISTEN_AND_ACCEPT;
      EventHeader.UsePhysAddr = FALSE;

      /* Set Event Payload */
      (void)Etm_VSetNext16Bit(SocketId, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX);
      Index += 2u;
      (void)Etm_VSetNext16Bit(SocketIdConnected, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX);
      Index += 2u;
      (void)Etm_VSetNext16Bit(ETM_HTONS(((ETM_P2C(TcpIp_SockAddrInetType))RemoteAddrPtr)->port), Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      Index += 2u;
      (void)Etm_VSetNext16Bit(AddressLength, Index, Etm_SendBuffer, ETM_MESSAGE_LENGTH_MAX); /* Set vint length */
      Index += 2u;
      IpBase_Copy(&Etm_SendBuffer[Index], &(((ETM_P2C(TcpIp_SockAddrInet6Type))RemoteAddrPtr)->addr), AddressLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      Index += AddressLength;
      Etm_SendBufferLength = Index;

      /* Send Event */
      (void)Etm_VSendEvent(&EventHeader);
    }
  }

  return E_OK;
}

/***********************************************************************************************************************
 *  Etm_TcpPreAccepted()
 **********************************************************************************************************************/
/*! \brief        This function is similar to 'Etm_TcpAccepted'.
 *  \details      This function is similar to 'Etm_TcpAccepted'. This function is called right after receiving a
                  'SYN' on a TCP listen socket and reports the listen socket ID and the ID of the socket that will
                  accept the connection request. These sockets are the same ones that are reported in the offical call
                  'Etm_TcpAccepted' later on. The reported socket IDs may only be used for analysis purposes,
                  the accepting socket may not be used in any way before it is fully connected (reported by call of
                  'Etm_TcpAccepted'). This function is needed if the socket IDs are needed in the TCP states
                  SYN-RECV or SYN-SEND.
 *  \param[in]    SocketId            Socket identifier of the related local socket resource which has been used at TcpIp_Bind().
 *  \param[in]    SocketIdConnected   Socket identifier of the local socket resource used for the established connection.
 *  \param[in]    RemoteAddrPtr       IP address and port of the remote host.
 *  \return       E_OK                Return always E_OK.
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETM_CODE) Etm_TcpPreAccepted(
  const TcpIp_SocketIdType SocketId,
  const TcpIp_SocketIdType SocketIdConnected,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, ETM_APPL_DATA) RemoteAddrPtr)
{
  ETM_DUMMY_STATEMENT_CONST(RemoteAddrPtr); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */

  if(Etm_DataProcessingMode == TRUE)
  {
    const uint8 TestChannelIndex = Etm_VFindTestChannelIndex(SocketId);

    if(TestChannelIndex != TCPIP_INV_SOCKET_ID)
    {
      const uint8 TestChannelIndexUsed = Etm_VFindTestChannelIndex(SocketIdConnected);   /* socketid not yet indexed */
      const uint8 TestChannelIndexFree = Etm_VFindTestChannelIndex(TCPIP_INV_SOCKET_ID); /* free index present */

      if((TestChannelIndexUsed == TCPIP_INV_SOCKET_ID) && (TestChannelIndexFree != TCPIP_INV_SOCKET_ID))
      {
        Etm_TestChannels[TestChannelIndexFree].SocketId = SocketIdConnected;
      }
    }
  }
  else if(Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].SocketId == SocketId)
  {
    Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C4].SocketId = SocketIdConnected;
  }
  else if(Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].SocketId == SocketId)
  {
    Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C6].SocketId = SocketIdConnected;
  }
  else
  {
    /* MISRA */
  }
  return E_OK;
}

/***********************************************************************************************************************
 *  Etm_TcpIpEvent()
 **********************************************************************************************************************/
/*! \brief        This function gets called if the stack encounters a condition described by the values in TcpIpEvent.
 *  \param[in]    SocketId    Socket identifier of the related local socket resource.
 *  \param[in]    Event       This parameter contains a description of the event just encountered.
 *  \return       none
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_TcpIpEvent(
  const TcpIp_SocketIdType SocketId,
  const IpBase_TcpIpEventType Event)
{
  switch(Event)
  {
  case TCPIP_TCP_CLOSED : /* IPBASE_TCP_EVENT_CLOSED */
    {
      uint8 TestChannelIndex = Etm_VFindTestChannelIndex(SocketId);

      if(TestChannelIndex != TCPIP_INV_SOCKET_ID)
      {
        Etm_TestChannels[TestChannelIndex].SocketId = TCPIP_INV_SOCKET_ID;
        Etm_TestChannels[TestChannelIndex].RecvFwdActive = FALSE;
        Etm_TestChannels[TestChannelIndex].RecvFwdDropCount = 0u;
        Etm_TestChannels[TestChannelIndex].RecvFwdMaxForward = 0u;
        Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength = 0u;
      }
    }
    break;
  case TCPIP_TCP_FIN_RECEIVED : /* fall through */ /* IPBASE_TCP_EVENT_FIN_RECEIVED */
  case TCPIP_TCP_RESET :        /* fall through */ /* IPBASE_TCP_EVENT_RESET */
  default :
    {
      /* do nothing */
    }
    break;
  }
} /* Etm_TcpIpEvent() */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  Etm_LocalIpAddrAssignmentChg()
 **********************************************************************************************************************/
/*! \brief        This function gets called by the TCP/IP stack if an IP address assignment changes
                  (i.e. new address assigned or assigned address becomes invalid).
 *  \param[in]    LocalAddrId   IP address Identifier, representing an IP address specified in the TcpIp module
                                configuraiton (e.g. static IPv4 address on EthIf controller 0).
 *  \param[in]    State         State of IP address assignment.
 *  \return       none
 *  \pre          Module is initialized.
 *  \context      INTERRUPT
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_LocalIpAddrAssignmentChg(
  const TcpIp_LocalAddrIdType IpAddrId,
  const TcpIp_IpAddrStateType State)
{

#if ((ETM_IPV4_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4))
  /* ETMv4 */
  if(IpAddrId == ETM_TCPIP_LOCAL_ADDRESS_IDV4)
  {
    if(State == TCPIP_IPADDR_STATE_ASSIGNED)
    {
      Etm_IpV4LinkAssigned = TRUE;
    }
    else
    {
      Etm_DataProcessingMode = FALSE;
      Etm_IpV4LinkAssigned = FALSE;
      Etm_ModuleInitAll = FALSE;

      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_UDP_V4);
      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_TCP_V4);
      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_TCP_C4);
    }
  }
#endif /* ((ETM_IPV4_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4)) */

#if ((ETM_IPV6_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6))
  /* ETMv6 */
  if(IpAddrId == ETM_TCPIP_LOCAL_ADDRESS_IDV6)
  {
    if(State == TCPIP_IPADDR_STATE_ASSIGNED)
    {
      Etm_IpV6LinkAssigned = TRUE;

      {
        IpV6_AddrType IpV6AddrPrefix = {{0u}}; /* PRQA S 0759 */ /* MD_Etm_18.4_0759 */
        uint8 TmpPrefixLength = 64u;
        uint8 PlEntryIdx = 0u;

        IpV6AddrPrefix.addr[0u] = 0x20u;
        IpV6AddrPrefix.addr[1u] = 0x01u;

        if (E_OK == IpV6_Ndp_VPLGetOrCreateEntry(ETM_TCPIP_IPV6_CTRLIDX, (ETM_P2C(IpV6_AddrType))&IpV6AddrPrefix, TmpPrefixLength, &PlEntryIdx))
        {
          IpV6_PrefixList[ETM_TCPIP_IPV6_CTRLIDX][PlEntryIdx].ExpireTime.S  = IPV6_LIFETIME_UNLIMITED;
          IpV6_PrefixList[ETM_TCPIP_IPV6_CTRLIDX][PlEntryIdx].ExpireTime.Ms = 0u;
        }
      }
    }
    else
    {
      Etm_DataProcessingMode = FALSE;
      Etm_IpV6LinkAssigned = FALSE;
      Etm_ModuleInitAll = FALSE;

      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_UDP_V6);
      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_TCP_V6);
      Etm_VCloseCommandChannel(ETM_CMD_CHAN_IDX_TCP_C6);
    }
  }
#endif /* ((ETM_IPV6_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6)) */
}

BufReq_ReturnType Etm_CopyTxData(
  const TcpIp_SocketIdType SocketId,
  P2VAR(uint8, AUTOMATIC, ETM_APPL_DATA) BufPtr,
  const uint16 BufLength)
{
  uint16 TmpSocketId = 0u;

  BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
  Std_ReturnType ResultStd = Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 0u, &TmpSocketId);

  if((ResultStd == E_OK) && (SocketId == TmpSocketId))
  {
    uint16 TotalLength = 0u;
    uint16 TmpDestAddrLength = 0u;
    TcpIp_SockAddrInXType TmpDestAddr = {0u};

    uint8 TmpData = 0u;
    uint8 *DataPtr = &TmpData;
    uint16 DataLength = 0u;

    if(ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))
    { /* Copy UDP data */
      ResultStd |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 2u, &TotalLength);
      ResultStd |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 4u, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      ResultStd |= Etm_VGetVIntAddr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 6u, (ETM_P2V(TcpIp_SockAddrType))&TmpDestAddr, &TmpDestAddrLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      ResultStd |= Etm_VGetVIntDataPtr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, (6u + 2u /* uint16 */ + TmpDestAddrLength), &DataPtr, &DataLength, FALSE);

      ((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port = ETM_HTONS(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    }
    else
    { /* Copy TCP data */
      ResultStd |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 2u, &TotalLength);
      ResultStd |= Etm_VGetVIntDataPtr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 4u, &DataPtr, &DataLength, FALSE);
    }

    if(ResultStd == E_OK)
    {
      uint16 Index = 0;
      uint16 TmpCopyPatternStartPosition = Etm_SendDataCommandAlreadySend % DataLength;

      for(; Index < BufLength; Index++)
      {
        BufPtr[Index] = DataPtr[(TmpCopyPatternStartPosition + Index) % DataLength];
      }

      Etm_SendDataCommandAlreadySend += Index;

      if(ETM_MAX(TotalLength, DataLength) <= Etm_SendDataCommandAlreadySend)
      { /* Transmission completed --> all data send */
        Etm_SendDataCommandIsPending = FALSE;
        Etm_SendDataCommandAlreadySend = 0;
      }
    }

    Result = BUFREQ_OK;
  }

  if(ResultStd != E_OK)
  {
    Result = BUFREQ_E_NOT_OK;
  }
  
  return Result;
}

/**********************************************************************************************************************
 *  GENERAL -- BUFFER HANDLING
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ETM_CODE) Etm_VCheckLength(const uint32 TotalDataLength, const uint32 Offset, const uint32 LengthToReadOrWrite)
{
  return (Std_ReturnType)((TotalDataLength >= (Offset + LengthToReadOrWrite)) ? E_OK : E_NOT_OK);
}

FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext8Bit(const uint8 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength)
{
  Std_ReturnType Result = Etm_VCheckLength(ResultDataLength, Offset, 1u); /* Check data length to write */

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultDataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(Result == E_OK)
  {
    ResultDataPtr[Offset] = Data;
  }

  return Result;
} /* Etm_VSetNext8Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext16Bit(const uint16 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength)
{
  Std_ReturnType Result = Etm_VCheckLength(ResultDataLength, Offset, 2u); /* Check data length to write */

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultDataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(Result == E_OK)
  {
    ResultDataPtr[Offset + 0u] = (uint8)(Data >> 8u);
    ResultDataPtr[Offset + 1u] = (uint8)(Data);
  }

  return Result;
} /* Etm_VSetNext16Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext32Bit(const uint32 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength)
{
  Std_ReturnType Result = Etm_VCheckLength(ResultDataLength, Offset, 4u); /* Check data length to write */

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultDataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(Result == E_OK)
  {
    ResultDataPtr[Offset + 0u] = (uint8)(Data >> 24u);
    ResultDataPtr[Offset + 1u] = (uint8)(Data >> 16u);
    ResultDataPtr[Offset + 2u] = (uint8)(Data >> 8u);
    ResultDataPtr[Offset + 3u] = (uint8)(Data);
  }

  return Result;
} /* Etm_VSetNext32Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext8Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint8) ResultPtr)
{
  Std_ReturnType Result = E_OK;

  const uint16 ConstLength = 1u;
  
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */
  
  Result |= Etm_VCheckLength(DataLength, Offset, ConstLength); /* Check data length to read */

  if(Result == E_OK)
  {
    ResultPtr[0u] = DataPtr[Offset];
  }

  return Result;
} /* Etm_VGetNext8Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext16Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint16) ResultPtr)
{
  Std_ReturnType Result = E_OK;

  const uint16 ConstLength = 2u;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */
  
  Result |= Etm_VCheckLength(DataLength, Offset, ConstLength); /* Check data length to read */

  if(Result == E_OK)
  {
    ResultPtr[0u]  = (uint16)(((uint16)DataPtr[Offset + 0u]) << 8u);
    ResultPtr[0u] |= (uint16) ((uint16)DataPtr[Offset + 1u]);
  }

  return Result;
} /* Etm_VGetNext16Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext32Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint32) ResultPtr)
{
  Std_ReturnType Result = E_OK;

  const uint16 ConstLength = 4u;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */
  
  Result |= Etm_VCheckLength(DataLength, Offset, ConstLength); /* Check data length to read */

  if(Result == E_OK)
  {
    ResultPtr[0u]  = ((uint32)DataPtr[Offset + 0u]) << 24u;
    ResultPtr[0u] |= ((uint32)DataPtr[Offset + 1u]) << 16u;
    ResultPtr[0u] |= ((uint32)DataPtr[Offset + 2u]) << 8u;
    ResultPtr[0u] |= ((uint32)DataPtr[Offset + 3u]);
  }

  return Result;
} /* Etm_VGetNext32Bit() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  ETM HELPERS -- GENERAL
 *********************************************************************************************************************/

FUNC(void, ETM_CODE) Etm_VOpenCommandChannel(const uint8 ChannelIdx)
{
  TcpIp_ProtocolType TmpProtocol = TCPIP_SOCK_PROT_NONE;
  TcpIp_DomainType TmpDomain = TCPIP_AF_UNDEFINED;

  if((ChannelIdx == ETM_CMD_CHAN_IDX_UDP_V4) ||
     (ChannelIdx == ETM_CMD_CHAN_IDX_UDP_V6))
  {
    TmpProtocol = TCPIP_SOCK_PROT_UDP;
  }
  if((ChannelIdx == ETM_CMD_CHAN_IDX_TCP_V4) ||
     (ChannelIdx == ETM_CMD_CHAN_IDX_TCP_V6))
  {
    TmpProtocol = TCPIP_SOCK_PROT_TCP;
  }

  if((ChannelIdx == ETM_CMD_CHAN_IDX_UDP_V4) ||
     (ChannelIdx == ETM_CMD_CHAN_IDX_TCP_V4))
  {
    TmpDomain = TCPIP_AF_INET;
  }
  if((ChannelIdx == ETM_CMD_CHAN_IDX_UDP_V6) ||
     (ChannelIdx == ETM_CMD_CHAN_IDX_TCP_V6))
  {
    TmpDomain = TCPIP_AF_INET6;
  }

  if((TmpProtocol == TCPIP_SOCK_PROT_NONE) || (TmpDomain == TCPIP_AF_UNDEFINED))
  {
    return;
  }

  switch(Etm_CommandChannels[ChannelIdx].ChannelState)
  {
  case ETM_CMD_CHAN_DO_GETSOCKET:
    /* TCP & UDP */
    {
      if(E_OK == TcpIp_EtmGetSocket(TmpDomain, TmpProtocol, &(Etm_CommandChannels[ChannelIdx].SocketId)))
      {
        Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_DO_BIND;
      }
    }
    break;
  case ETM_CMD_CHAN_DO_BIND:
    /* TCP & UDP */
    {
      uint16 ListenPort = ETM_STUB_LISTEN_PORT;

      TcpIp_LocalAddrIdType TmpLocAddrId = (TcpIp_LocalAddrIdType)TCPIP_LOCALADDRID_INV;
      
#if ((ETM_IPV6_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6))
      if(TmpDomain == TCPIP_AF_INET6)
      {
        TmpLocAddrId = (TcpIp_LocalAddrIdType)ETM_TCPIP_LOCAL_ADDRESS_IDV6;
      }
#endif /* ((ETM_IPV6_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6)) */
#if ((ETM_IPV4_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4))
      if(TmpDomain == TCPIP_AF_INET)
      {
        TmpLocAddrId = (TcpIp_LocalAddrIdType)ETM_TCPIP_LOCAL_ADDRESS_IDV4;
      }
#endif /* ((ETM_IPV4_ENABLED == STD_ON) && (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4)) */

      if(E_OK == TcpIp_Bind(Etm_CommandChannels[ChannelIdx].SocketId, TmpLocAddrId, &ListenPort))
      {
        if(TmpProtocol == TCPIP_SOCK_PROT_UDP)
        {
          /* UDP */
          Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_ACTIVE;
        }
        else
        {
          /* TCP */
          Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_DO_RX_BUFFER;
        }
      }
    }
    break;
  case ETM_CMD_CHAN_DO_RX_BUFFER:
    /* TCP only */
    {
      uint32 tmpBufSizeRx = ETM_TCPIP_BUFFER_SIZE_TCP_RX_CMD;

      if(E_OK == TcpIp_ChangeParameter(Etm_CommandChannels[ChannelIdx].SocketId, TCPIP_PARAMID_TCP_RXWND_MAX, (ETM_P2V(uint8))&tmpBufSizeRx)) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_Api */
      {
        Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_DO_TX_BUFFER;
      }
    }
    break;
  case ETM_CMD_CHAN_DO_TX_BUFFER:
    /* TCP only */
    {
      uint32 tmpBufSizeTx = ETM_TCPIP_BUFFER_SIZE_TCP_TX_CMD;

      if(E_OK == TcpIp_ChangeParameter(Etm_CommandChannels[ChannelIdx].SocketId, TCPIP_PARAMID_V_TCP_TXBUFSIZE, (ETM_P2V(uint8))&tmpBufSizeTx)) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_Api */
      {
        Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_DO_LISTEN;
      }
    }
    break;
  case ETM_CMD_CHAN_DO_LISTEN:
    /* TCP only */
    {
#if (ETM_TCP_ENABLED == STD_ON)
      if(E_OK == TcpIp_TcpListen(Etm_CommandChannels[ChannelIdx].SocketId, 1u))
      {
        Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_ACTIVE;
      }
#else
      Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_INACTIVE;
#endif
    }
    break;
  case ETM_CMD_CHAN_INACTIVE: /* fall through */
  case ETM_CMD_CHAN_ACTIVE:   /* fall through */
  default:
    /* nothing to do -- channel is active or not used (inactive) */
    break;
  }
} /* Etm_VOpenCommandChannel() */ /* PRQA S 2006, 6010, 6030 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC */

FUNC(void, ETM_CODE) Etm_VCloseCommandChannel(const uint8 ChannelIdx)
{
  if((ChannelIdx < ETM_CHANNELS_COMMAND) && (Etm_CommandChannels[ChannelIdx].SocketId != TCPIP_INV_SOCKET_ID))
  {
    (void)TcpIp_Close(Etm_CommandChannels[ChannelIdx].SocketId, TRUE);
    Etm_CommandChannels[ChannelIdx].SocketId = TCPIP_INV_SOCKET_ID;
    Etm_CommandChannels[ChannelIdx].ChannelState = ETM_CMD_CHAN_DO_GETSOCKET;
  }
}

FUNC(uint8, ETM_CODE) Etm_VFindTestChannelIndex(const TcpIp_SocketIdType SocketId)
{
  uint8 Result = TCPIP_INV_SOCKET_ID;
  uint8 Index = 0u;
  
  for(; Index < ETM_CHANNELS_TEST; Index++)
  {
    if(Etm_TestChannels[Index].SocketId == SocketId)
    {
      Result = Index;
      break;
    }
  }

  return Result;
}

FUNC(boolean, ETM_CODE) Etm_VTestChannelActive(const TcpIp_SocketIdType SocketId)
{
  return (boolean)(Etm_VFindTestChannelIndex(SocketId) != TCPIP_INV_SOCKET_ID);
}

FUNC(TcpIp_LocalAddrIdType, ETM_CODE) Etm_VGetLocAddrIdFromAddr(ETM_P2C(TcpIp_SockAddrType) Addr)
{
  TcpIp_LocalAddrIdType TmpLocAddrId = TCPIP_LOCALADDRID_INV;
  TcpIp_SockAddrInXType IpAddress = {0u};
  TcpIp_SockAddrInXType DefaultRouter = {0u};
  uint8 Netmask[ETM_DATA_LEN_ADDRESS_IPV6] = {0u};

  TcpIp_DomainType Domain = Addr->domain;

  if(Domain == TCPIP_AF_INET6)
  {
#if (ETM_IPV6_ENABLED == STD_ON)
    ((ETM_P2V(TcpIp_SockAddrType))&IpAddress)->domain = TCPIP_AF_INET6; /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6_MULTI)
    if(IPV6_ADDR_IS_MULTICAST(((ETM_P2C(TcpIp_SockAddrInet6Type))Addr)[0u]) /* IP=MULTI */) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV6_MULTI;
    }
    else
# endif
# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6_ANY)
    if(TRUE == TcpIp_VSockIpAddrIsEqual((ETM_P2C(IpBase_SockAddrType))&IpAddress, (ETM_P2C(IpBase_SockAddrType))Addr) /* IP=ANY */) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV6_ANY;
    }
    else
# endif
# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV6)
    /* PRQA S 3415 2 */ /* MD_Etm_12.4_3415_Side */
    if((E_OK == TcpIp_GetIpAddr(ETM_TCPIP_LOCAL_ADDRESS_IDV6, (ETM_P2V(TcpIp_SockAddrType))&IpAddress, &Netmask[0u], (ETM_P2V(TcpIp_SockAddrType))&DefaultRouter)) && /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      (TRUE == TcpIp_VSockIpAddrIsEqual((ETM_P2C(IpBase_SockAddrType))&IpAddress, (ETM_P2C(IpBase_SockAddrType))Addr) /* IP=LOCAL */)) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV6;
    }
    else
# endif
    {
# if ((defined ETM_TCPIP_LOCAL_ADDRESS_IDV6) && (ETM_TCPIP_LOCAL_ADDRESS_USE_DEFAULT == STD_ON))
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV6;
# else
      TmpLocAddrId = TCPIP_LOCALADDRID_INV;
# endif
    }
#endif /* (ETM_IPV6_ENABLED == STD_ON) */
  }
  else if(Domain == TCPIP_AF_INET)
  {
#if (ETM_IPV4_ENABLED == STD_ON)
    ((ETM_P2V(TcpIp_SockAddrType))&IpAddress)->domain = TCPIP_AF_INET; /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4_MULTI)
    if(IPV4_ADDR_IS_MULTICAST(((ETM_P2C(TcpIp_SockAddrInetType))Addr)->addr[0u]) /* IP=MULTI */) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV4_MULTI;
    }
    else
# endif
# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4_ANY)
    if(TRUE == TcpIp_VSockIpAddrIsEqual((ETM_P2C(IpBase_SockAddrType))&IpAddress, (ETM_P2C(IpBase_SockAddrType))Addr) /* IP=ANY */) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV4_ANY;
    }
    else
# endif
# if (defined ETM_TCPIP_LOCAL_ADDRESS_IDV4)
    /* PRQA S 3415 2 */ /* MD_Etm_12.4_3415_Side */
    if((E_OK == TcpIp_GetIpAddr(ETM_TCPIP_LOCAL_ADDRESS_IDV4, (ETM_P2V(TcpIp_SockAddrType))&IpAddress, &Netmask[0u], (ETM_P2V(TcpIp_SockAddrType))&DefaultRouter)) && /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      (TRUE == TcpIp_VSockIpAddrIsEqual((ETM_P2C(IpBase_SockAddrType))&IpAddress, (ETM_P2C(IpBase_SockAddrType))Addr) /* IP=LOCAL */)) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    {
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV4;
    }
    else
# endif
    {
# if ((defined ETM_TCPIP_LOCAL_ADDRESS_IDV4) && (ETM_TCPIP_LOCAL_ADDRESS_USE_DEFAULT == STD_ON))
      TmpLocAddrId = ETM_TCPIP_LOCAL_ADDRESS_IDV4;
# else
      TmpLocAddrId = TCPIP_LOCALADDRID_INV;
# endif
    }
#endif /* (ETM_IPV4_ENABLED == STD_ON) */
  }
  else
  {
    /* MISRA */
  }
  
  return TmpLocAddrId;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  ETM HELPERS -- MESSAGE HANDLING
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ETM_CODE) Etm_VGetVIntDataPtr(
                    ETM_P2C(uint8) DataPtr,
                    const uint32 DataLength,
                    const uint32 Offset,
                    ETM_P2V(uint8*) ResultPtrPtr,
                    ETM_P2V(uint16) ResultLengthPtr,
                    const boolean CopyData)
{
  Std_ReturnType Result = E_OK;

  uint16 Index = 0u;
  uint16 ResultLength = 0u;

  Result |= Etm_VGetNext16Bit(DataPtr, DataLength, Offset, &ResultLength);

  if((Result == E_OK) &&
    ((Offset + 2u /* uint16 */ /* \trace SPEC-2171519 */ + ResultLength) <= DataLength))
  {
    if(CopyData == TRUE)
    {
      for(; Index < ResultLength; Index++)
      {
        ResultPtrPtr[0u][Index] = DataPtr[Offset + 2u /* uint16 */ /* \trace SPEC-2171519 */ + Index];
      }
    }
    else
    {
      ResultPtrPtr[0u] = (ETM_P2V(uint8))&DataPtr[Offset + 2u /* uint16 */ /* \trace SPEC-2171519 */]; /* PRQA S 0311 */ /* MD_Etm_11.4_0311_Const */
    }
    ResultLengthPtr[0u] = ResultLength;
    Result = E_OK;
  }
  else
  {
    Result = E_NOT_OK;
  }

  return Result;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

FUNC(Std_ReturnType, ETM_CODE) Etm_VGetVIntAddr(
                    ETM_P2C(uint8) DataPtr,
                    const uint32 DataLength,
                    const uint32 Offset,
                    ETM_P2V(TcpIp_SockAddrType) ResultPtr,
                    ETM_P2V(uint16) ResultLengthPtr /* can be used to calculate data offset for next parameter access */)
{
  Std_ReturnType Result = E_OK;

  uint16 ResultLength = 0u;
  uint8 *AddrDataPtr = ((ETM_P2V(uint8))&(((ETM_P2V(TcpIp_SockAddrInet6Type))ResultPtr)->addr[0u])); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  Result |= Etm_VGetVIntDataPtr(DataPtr, DataLength, Offset, &AddrDataPtr, &ResultLength, TRUE);
  ResultLengthPtr[0u] = ResultLength;

  if(Result == E_OK)
  {
    if(ResultLength == ETM_DATA_LEN_ADDRESS_IPV4)
    {
      ResultPtr->domain = TCPIP_AF_INET;
    }
    else if(ResultLength == ETM_DATA_LEN_ADDRESS_IPV6)
    {
      ResultPtr->domain = TCPIP_AF_INET6;
    }
    else
    {
      Result = E_NOT_OK;
    }
  }
  
  return Result;
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderSid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint16) ResultPtr)
{
  Std_ReturnType Result = E_NOT_OK;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= (ETM_MESSAGE_OFFSET_SID + 2u /* DataSize */))
  {
    Result = Etm_VGetNext16Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_SID, ResultPtr);
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderEvb(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(boolean) ResultPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= (ETM_MESSAGE_OFFSET_EVB_GID + 1u /* DataSize */))
  {
    Result = Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_EVB_GID, ResultPtr);
  }

  ResultPtr[0u] = (uint8)((ResultPtr[0u] & ETM_UINT8_MASK_EVB_BIT) > 1u); /* only TRUE if EVB==1 */

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderGid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= (ETM_MESSAGE_OFFSET_EVB_GID + 1u /* DataSize */))
  {
    Result = Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_EVB_GID, ResultPtr);
  }

  ResultPtr[0u] = (uint8)(ResultPtr[0u] & ETM_UINT8_MASK_GID);

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderPid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= (ETM_MESSAGE_OFFSET_PID + 1u /* DataSize */))
  {
    Result = Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_PID, ResultPtr);
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderLen(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint32) ResultPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  
  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= (ETM_MESSAGE_OFFSET_LEN + 4u /* DataSize */))
  {
    Result = Etm_VGetNext32Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_LEN, ResultPtr);
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderTid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr)
{
  Std_ReturnType Result = E_OK;
  uint32 LenField = 0u;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  Result |= Etm_VGetHeaderLen(DataPtr, DataLength, &LenField);

  if((Result == E_OK) && (LenField >= 7u /* necessary data size to cover TID field */))
  {
    if(DataLength >= (ETM_MESSAGE_OFFSET_TID + 1u /* DataSize */))
    {
      Result = Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_TID, ResultPtr);
    }
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderRid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr)
{
  Std_ReturnType Result = E_OK;
  uint32 LenField = 0u;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  Result |= Etm_VGetHeaderLen(DataPtr, DataLength, &LenField);

  if((Result == E_OK) && (LenField >= 8u /* necessary data size to cover RID field */))
  {
    if(DataLength >= (ETM_MESSAGE_OFFSET_RID + 1u /* DataSize */))
    {
      Result = Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_RID, ResultPtr);
    }
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetSidInBuffer(const uint16 Sid, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSetNext16Bit(Sid, ETM_MESSAGE_OFFSET_SID, DataPtr, DataLength);
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetEvbInBuffer(const boolean Evb, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  Std_ReturnType Result = E_OK;

#if (ETM_STUB_PROTOCOL_VERSION >= 0x0006U)
  {
    uint8 Data = 0u;

    Result |= Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_EVB_GID, &Data);

    /* Read GID (7-Bit) from buffer and merge with EVB (1-Bit) to uint8 */
    Data = (uint8)((Data & ETM_UINT8_MASK_GID) | ((uint8)(Evb << 7u) & ETM_UINT8_MASK_EVB_BIT));
  
    if(Result == E_OK)
    {
      Result = Etm_VSetNext8Bit(Data, ETM_MESSAGE_OFFSET_EVB_GID, DataPtr, DataLength);
    }
  }
#else
  /* PRQA S 3112 3 */ /* MD_Etm_14.2_3112 */
  ETM_DUMMY_STATEMENT_CONST(Evb);
  ETM_DUMMY_STATEMENT_CONST(DataPtr);
  ETM_DUMMY_STATEMENT_CONST(DataLength);
#endif

  return Result;
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetGidInBuffer(const uint8 Gid, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  Std_ReturnType Result = E_OK;
  uint8 TmpData = 0u;
  
  Result |= Etm_VGetNext8Bit(DataPtr, DataLength, ETM_MESSAGE_OFFSET_EVB_GID, &TmpData);

  /* Read EVB (1-Bit) from buffer and merge with GID (7-Bit) to uint8 */
  TmpData = (uint8)((TmpData & ETM_UINT8_MASK_EVB_BIT) | (Gid & ETM_UINT8_MASK_GID));
  
  if(Result == E_OK)
  {
    Result = Etm_VSetNext8Bit(TmpData, ETM_MESSAGE_OFFSET_EVB_GID, DataPtr, DataLength);
  }

  return Result;
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetPidInBuffer(const uint8 Pid, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSetNext8Bit(Pid, ETM_MESSAGE_OFFSET_PID, DataPtr, DataLength);
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetLenInBuffer(const uint32 Len, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSetNext32Bit(Len, ETM_MESSAGE_OFFSET_LEN, DataPtr, DataLength);
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetTidInBuffer(const Etm_TypeIdType Tid, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSetNext8Bit((uint8)Tid, ETM_MESSAGE_OFFSET_TID, DataPtr, DataLength);
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetRidInBuffer(const Etm_ResultIdType Rid, ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSetNext8Bit((uint8)Rid, ETM_MESSAGE_OFFSET_RID, DataPtr, DataLength);
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetVersionsInBuffer(ETM_P2V(uint8) DataPtr, const uint32 DataLength)
{
  Std_ReturnType Result = E_OK;

  Result |= Etm_VSetNext8Bit(ETM_SOMEIP_PROTOCOL_VERSION, ETM_MESSAGE_OFFSET_PROTO_VER, DataPtr, DataLength);
  Result |= Etm_VSetNext8Bit(ETM_SOMEIP_INTERFACE_VERSION, ETM_MESSAGE_OFFSET_IFACE_VER, DataPtr, DataLength);

  return Result;
}

/* \trace SPEC-2171512 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VParseHeader(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(Etm_HeaderType) ResultPtr)
{
  Std_ReturnType Result = E_OK;

  /* ----- Development Error Checks ------------------ */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(DataPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  Etm_CheckDetErrorReturnValue(ETM_COND_VALID_PTR(ResultPtr), ETM_SID_INTERNAL_FUNCTION, ETM_E_INV_POINTER, E_NOT_OK);
  /* ------------------------------------------------- */

  if(DataLength >= 16u)
  {
    Result |= Etm_VGetHeaderSid(DataPtr, DataLength, &(ResultPtr->Sid));
    Result |= Etm_VGetHeaderEvb(DataPtr, DataLength, &(ResultPtr->Evb));
    Result |= Etm_VGetHeaderGid(DataPtr, DataLength, &(ResultPtr->Gid));
    Result |= Etm_VGetHeaderPid(DataPtr, DataLength, &(ResultPtr->Pid));
    Result |= Etm_VGetHeaderLen(DataPtr, DataLength, &(ResultPtr->Len));
    Result |= Etm_VGetHeaderTid(DataPtr, DataLength, &(ResultPtr->Tid));
    Result |= Etm_VGetHeaderRid(DataPtr, DataLength, &(ResultPtr->Rid));

    ResultPtr->ProtocolVersion = ETM_SOMEIP_PROTOCOL_VERSION;
    ResultPtr->InterfaceVersion = ETM_SOMEIP_INTERFACE_VERSION;
    ResultPtr->PayloadLength = (uint16)((ResultPtr->Len >= 8u) ? (ResultPtr->Len - 8u) : 0u);
    ResultPtr->Payload = (ETM_P2V(uint8))&DataPtr[ETM_MESSAGE_OFFSET_DAT]; /* PRQA S 0311 */ /* MD_Etm_11.4_0311_Const */
  }

  return Result;
} /* PRQA S 2006, 6050 */ /* MD_MSR_14.7, MD_MSR_STCAL */

FUNC(Std_ReturnType, ETM_CODE) Etm_VSendMessage(
                    ETM_P2C(Etm_HeaderType) Header,
                    const Etm_TypeIdType Tid,
                    const Etm_ResultIdType Rid,
                    ETM_P2C(uint8) DataPtr,
                    const uint32 DataLength)
{
  Std_ReturnType Result = E_OK;

  uint32 Index = 0u;
  uint16 FullMessageLength;
  
  if(DataLength == 0u)
  {
    if(Etm_SendBufferLength == 0u)
    {
      Etm_SendBufferLength = ETM_MESSAGE_LENGTH_HEADER;
    }
    FullMessageLength = Etm_SendBufferLength;
  }
  else
  {
    FullMessageLength = (uint16)(ETM_MESSAGE_LENGTH_HEADER + DataLength);
  }
  
  Result |= Etm_VSetSidInBuffer(ETM_STUB_SERVICE_ID, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetEvbInBuffer((boolean)(Tid == ETM_TID_EVENT) /* Set EVB regarding to TID */, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetGidInBuffer(Header->Gid, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetPidInBuffer(Header->Pid, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetLenInBuffer((FullMessageLength - 8u /* some fields not coverd by LEN */), Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetTidInBuffer(Tid, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetRidInBuffer(Rid, Etm_SendBuffer, FullMessageLength);
  Result |= Etm_VSetVersionsInBuffer(Etm_SendBuffer, FullMessageLength);

  if((Result == E_OK) &&
    (FullMessageLength <= ETM_MESSAGE_LENGTH_MAX))
  {
    if(DataPtr != NULL_PTR)
    {
      for(; Index < (uint16)(FullMessageLength - ETM_MESSAGE_OFFSET_DAT); Index++)
      {
        Etm_SendBuffer[ETM_MESSAGE_OFFSET_DAT + Index] = DataPtr[Index];
      }
    }

#if (ETM_TCP_ENABLED == STD_ON)
    if((Header->UsePhysAddr == FALSE) && ETM_COND_VALID_TCP_SOCKET_ID(Header->ReceivedSocketId))
    {
      if(E_OK == TcpIp_TcpTransmit(Header->ReceivedSocketId, Etm_SendBuffer, FullMessageLength, FALSE))
      {
        Etm_SendBufferLength = 0;
        return E_OK;
      }
      else
      {
        return E_NOT_OK;
      }
    }
    else
#endif
    if((Header->UsePhysAddr == FALSE) && ETM_COND_VALID_UDP_SOCKET_ID(Header->ReceivedSocketId))
    {
      if(TCPIP_OK == TcpIp_UdpTransmit(Header->ReceivedSocketId, Etm_SendBuffer, (ETM_P2V(TcpIp_SockAddrType))&(Header->ReceivedRemoteAddress), FullMessageLength)) /* PRQA S 0310, 0311 */ /* MD_Etm_11.4_0310_AddrPtr, MD_Etm_11.4_0311_Const */
      {
        Etm_SendBufferLength = 0;
        return E_OK;
      }
      else
      {
        return E_NOT_OK;
      }
    }
    else
#if (ETM_ETHIF_ENABLED == STD_ON)
    if((Header->UsePhysAddr == TRUE) &&
       (Header->ReceivedSocketId == 0u) &&
      ((Header->ReceivedRemotePhysAddr[0u] != 0u) ||
       (Header->ReceivedRemotePhysAddr[1u] != 0u) ||
       (Header->ReceivedRemotePhysAddr[2u] != 0u) ||
       (Header->ReceivedRemotePhysAddr[3u] != 0u) ||
       (Header->ReceivedRemotePhysAddr[4u] != 0u) ||
       (Header->ReceivedRemotePhysAddr[5u] != 0u)))
    {
      uint8 TmpBufIdx = 0u;
      uint16 TmpBufLen = (uint16)((DataLength == 0u) ? (18u /* ETH */ + 16u /* ETM */ + 1u /* DATA */) : (18u /* ETH */ + 16u /* ETM */ + DataLength /* DATA */));
      uint16 BufLenParam = TmpBufLen;
      Eth_DataType *TmpBufPtr;
      if(BUFREQ_OK == EthIf_ProvideTxBuffer(Header->ReceivedCtrlIdx, ETM_ETHIF_FRAME_TYPE, 0u, &TmpBufIdx, &TmpBufPtr, &BufLenParam))
      {
        if(BufLenParam >= TmpBufLen)
        {
          IpBase_Copy(TmpBufPtr, Etm_SendBuffer, TmpBufLen);
          Etm_SendBufferLength = 0;
          return EthIf_Transmit(Header->ReceivedCtrlIdx, TmpBufIdx, ETM_ETHIF_FRAME_TYPE, FALSE, TmpBufLen, (ETM_P2V(uint8))&(Header->ReceivedRemotePhysAddr)); /* PRQA S 0310, 0311 */ /* MD_Etm_11.4_0310_AddrPtr, MD_Etm_11.4_0311_Const */
        }
        else
        {
          return E_NOT_OK;
        }
      }
      else
      {
        return E_NOT_OK;
      }
    }
    else
#endif /* (ETM_ETHIF_ENABLED == STD_ON) */
    {
      return E_NOT_OK;
    }
  }

  return E_NOT_OK;
} /* PRQA S 2006, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF  */

FUNC(Std_ReturnType, ETM_CODE) Etm_VSendResponse(ETM_P2C(Etm_HeaderType) Header, const Etm_ResultIdType Rid, ETM_P2C(uint8) DataPtr, const uint32 DataLength)
{
  return Etm_VSendMessage(Header, ETM_TID_RESPONSE, Rid, DataPtr, DataLength);
}

FUNC(Std_ReturnType, ETM_CODE) Etm_VSendResponseWithoutPayload(ETM_P2C(Etm_HeaderType) Header, const Etm_ResultIdType Rid)
{
  return Etm_VSendMessage(Header, ETM_TID_RESPONSE, Rid, NULL_PTR, 0u);
}

FUNC(Std_ReturnType, ETM_CODE) Etm_VSendEvent(ETM_P2V(Etm_HeaderType) Header)
{
  Header->ReceivedSocketId = (TcpIp_SocketIdType)Etm_EventDestSocketId;
  (void)IpBase_CopySockAddr((ETM_P2V(IpBase_SockAddrType))&(Header->ReceivedRemoteAddress), (ETM_P2C(IpBase_SockAddrType))&Etm_EventDestAddr); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  return Etm_VSendMessage(Header, ETM_TID_EVENT, ETM_RID_E_OK, NULL_PTR, 0u);
}

/**********************************************************************************************************************
 *  ETM HELPERS -- COMMAND HANDLING
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessEtmCommands(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  switch(Header->Gid)
  {
  case ETM_GID_GENERAL:
    {
      Result |= Etm_VProcessGerneralCommands(Header);
    }
    break;
  case ETM_GID_UDP:
    {
      Result |= Etm_VProcessUdpCommands(Header);
    }
    break;
  case ETM_GID_TCP:
    {
      Result |= Etm_VProcessTcpCommands(Header);
    }
    break;
#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  case ETM_GID_USERSCRIPT :
    {
      Result |= Etm_VProcessUserScriptCommands(Header);
    }
    break;
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */
  default:
    {
      /* Service Primitive not found */
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_NTF);
    }
    break;
  }

  return Result;
}

/* \trace SPEC-2171522 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessGerneralCommands(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  switch(Header->Pid)
  {
  case ETM_PID_GET_VERSION:
    {
      Result |= Etm_VGeneralGetVersion(Header);
    }
    break;
  case ETM_PID_START_TEST:
    {
      Result |= Etm_VGeneralStartTest(Header);
    }
    break;
  case ETM_PID_END_TEST:
    {
      Result |= Etm_VGeneralEndTest(Header);
    }
    break;
  default:
    {
      /* Service Primitive not found */
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_NTF);
    }
    break;
  }

  return Result;
}

/* \trace SPEC-2171523 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUdpCommands(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  switch(Header->Pid)
  {
  case ETM_PID_UDP_CLOSE_SOCKET:
    {
      Result |= Etm_VUdpCloseSocket(Header);
    }
    break;
  case ETM_PID_UDP_CREATE_AND_BIND:
    {
      Result |= Etm_VUdpCreateAndBind(Header);
    }
    break;
  case ETM_PID_UDP_SEND_DATA:
    {
      Result |= Etm_VUdpSendData(Header);
    }
    break;
  case ETM_PID_UDP_RECEIVE_AND_FORWARD:
    {
      Result |= Etm_VUdpReceiveAndForward(Header);
    }
    break;
  case ETM_PID_UDP_CONFIGURE_SOCKET:
    {
      Result |= Etm_VUdpConfigureSocket(Header);
    }
    break;
  case ETM_PID_UDP_SHUTDOWN:
    {
      Result |= Etm_VUdpShutdown(Header);
    }
    break;
  default:
    {
      /* Service Primitive not found */
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_NTF);
    }
    break;
  }

  return Result;
}

/* \trace SPEC-2171524 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessTcpCommands(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  switch(Header->Pid)
  {
  case ETM_PID_TCP_CLOSE_SOCKET:
    {
      Result |= Etm_VTcpCloseSocket(Header);
    }
    break;
  case ETM_PID_TCP_CREATE_AND_BIND:
    {
      Result |= Etm_VTcpCreateAndBind(Header);
    }
    break;
  case ETM_PID_TCP_SEND_DATA:
    {
      Result |= Etm_VTcpSendData(Header);
    }
    break;
  case ETM_PID_TCP_RECEIVE_AND_FORWARD:
    {
      Result |= Etm_VTcpReceiveAndForward(Header);
    }
    break;
  case ETM_PID_TCP_LISTEN_AND_ACCEPT:
    {
      Result |= Etm_VTcpListenAndAccept(Header);
    }
    break;
  case ETM_PID_TCP_CONNECT:
    {
      Result |= Etm_VTcpConnect(Header);
    }
    break;
  case ETM_PID_TCP_CONFIGURE_SOCKET:
    {
      Result |= Etm_VTcpConfigureSocket(Header);
    }
    break;
  case ETM_PID_TCP_SHUTDOWN:
    {
      Result |= Etm_VTcpShutdown(Header);
    }
    break;
  default:
    {
      /* Service Primitive not found */
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_NTF);
    }
    break;
  }

  return Result;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUserScriptCommands(ETM_P2C(Etm_HeaderType) Header)
{
#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  ETM_DUMMY_STATEMENT_CONST(Header); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */
  return E_NOT_OK;
#else
  ETM_DUMMY_STATEMENT_CONST(Header); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */
  return E_NOT_OK;
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */
} /* Etm_VProcessUserScriptCommands() */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUserScriptCommandsPending(void)
{
  Std_ReturnType Result = E_OK;

#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  Etm_UserScript_Pid = ETM_PID_USERSCRIPT__UNDEFINED;
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */
  
  return Result;
} /* Etm_VProcessUserScriptCommandsPending() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, ETM_CODE) Etm_VSaveUserScriptCommand(ETM_P2C(Etm_HeaderType) Header)
{
#if (ETM_USERSCRIPT_ENABLED == STD_ON)
  /* Save required parameters and process command in MainFunction/Etm_VProcessUserScriptCommandsPending() */
  Etm_UserScript_Pid = Header->Pid;
  Etm_UserScript_DataLength = Header->PayloadLength;
  IpBase_Copy(Etm_UserScript_DataPtr, Header->Payload, Header->PayloadLength);

  ETM_DUMMY_STATEMENT_CONST(Etm_UserScript_DataLength); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */
#else
  ETM_DUMMY_STATEMENT_CONST(Header); /* PRQA S 3112 */ /* MD_Etm_14.2_3112 */
#endif /* (ETM_USERSCRIPT_ENABLED == STD_ON) */

  return E_OK;
}

FUNC(Std_ReturnType, ETM_CODE) Etm_VSaveCommand(ETM_P2C(Etm_HeaderType) Header)
{
  if(Header->PayloadLength <= ETM_STUB_MAX_COMMAND_SIZE)
  {
    IpBase_Copy(Etm_SendDataCommand, Header->Payload, Header->PayloadLength);
    return E_OK;
  }
  else
  {
    return E_NOT_OK;
  }
}

/**********************************************************************************************************************
 *  ETM HELPERS -- COMMAND HANDLING -- GROUP: GENERAL
 *********************************************************************************************************************/

/* \trace SPEC-2171525 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralGetVersion(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  uint8 TmpData[4u]; /* Etm Protocol Version */
  uint16 EtmProtocolVersion = ETM_STUB_PROTOCOL_VERSION;

  /* Etm Protocol Version - Major */
  TmpData[0u] = 0u;
  TmpData[1u] = ((uint8)(EtmProtocolVersion >> 8));
  /* Etm Protocol Version - Minor */
  TmpData[2u] = 0u;
  TmpData[3u] = ((uint8)(EtmProtocolVersion));
  
  Result |= Etm_VSendResponse(Header, ETM_RID_E_OK, TmpData, 4u);

  return Result;
}

/* \trace SPEC-2171526 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralStartTest(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  /* \trace SPEC-2168556 */
  (void)IpBase_CopySockAddr((ETM_P2V(IpBase_SockAddrType))&Etm_EventDestAddr, (ETM_P2C(IpBase_SockAddrType))&(Header->ReceivedRemoteAddress)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Etm_EventDestSocketId = Header->ReceivedSocketId;

  Result |= Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_OK);

  return Result;
}

/* \trace SPEC-2171527 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralEndTest(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  uint8 Index = 0u;

  ((ETM_P2V(TcpIp_SockAddrType))&Etm_EventDestAddr)->domain = TCPIP_AF_UNDEFINED; /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Etm_EventDestSocketId = TCPIP_INV_SOCKET_ID;

  Etm_DataProcessingMode = FALSE; /* \trace SPEC-2171515 */
  
  for(; Index < ETM_CHANNELS_TEST; Index++)
  {
    if(Etm_TestChannels[Index].SocketId != TCPIP_INV_SOCKET_ID)
    {
      if((Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V4].SocketId) &&
         (Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V6].SocketId) &&
         (Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].SocketId) &&
         (Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].SocketId) &&
         (Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C4].SocketId) &&
         (Etm_TestChannels[Index].SocketId != Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C6].SocketId))
      {
        /* close test channel only */
        (void)TcpIp_Close(Etm_TestChannels[Index].SocketId, TRUE);
      }
      
      Etm_TestChannels[Index].SocketId = TCPIP_INV_SOCKET_ID;
      Etm_TestChannels[Index].RecvFwdActive = FALSE;
      Etm_TestChannels[Index].RecvFwdDropCount = 0u;
      Etm_TestChannels[Index].RecvFwdMaxForward = 0u;
      Etm_TestChannels[Index].RecvFwdMaxLength = 0u;
    }
  }
  
  Result |= Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_OK);

  return Result;
}

/**********************************************************************************************************************
 *  ETM HELPERS -- COMMAND HANDLING -- GROUP: UDP
 *********************************************************************************************************************/

/* \trace SPEC-2171528 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpCloseSocket(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  uint16 TmpSocketId = 0u;
  const boolean Abort = TRUE;
  
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  
  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))
    {
      Result = Etm_VApiCloseSocket(Header, (TcpIp_SocketIdType)TmpSocketId, Abort);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171529 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpCreateAndBind(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiCreateAndBind(Header, TCPIP_SOCK_PROT_UDP);
}

/* \trace SPEC-2171530 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpSendData(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  uint16 TmpSocketId = 0u;
  uint16 TotalLength = 0u;
  uint16 TmpDestAddrLength = 0u;
  TcpIp_SockAddrInXType TmpDestAddr = {0u};

  uint8 TmpData = 0u;
  uint8 *DataPtr = &TmpData;
  uint16 DataLength = 0u;

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &TotalLength);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 4u, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Result |= Etm_VGetVIntAddr(Header->Payload, Header->PayloadLength, 6u, (ETM_P2V(TcpIp_SockAddrType))&TmpDestAddr, &TmpDestAddrLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Result |= Etm_VGetVIntDataPtr(Header->Payload, Header->PayloadLength, (6u + 2u /* uint16 */ + TmpDestAddrLength), &DataPtr, &DataLength, FALSE);

  ((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port = ETM_HTONS(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))
    {
      Result = Etm_VApiSendData(Header, (TcpIp_SocketIdType)TmpSocketId, TotalLength, (ETM_P2C(TcpIp_SockAddrType))&TmpDestAddr, DataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171531 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpReceiveAndForward(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiReceiveAndForward(Header, TCPIP_SOCK_PROT_UDP);
}

/* \trace SPEC-2171534 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpConfigureSocket(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiConfigureSocket(Header);
}

/* \trace SPEC-2238731 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpShutdown(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiShutdown(Header);
}

/**********************************************************************************************************************
 *  ETM HELPERS -- COMMAND HANDLING -- GROUP: TCP
 *********************************************************************************************************************/

/* \trace SPEC-2171528 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpCloseSocket(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  uint16 TmpSocketId = 0u;
  boolean Abort = TRUE;
  
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext8Bit(Header->Payload, Header->PayloadLength, 2u, &Abort);
  
  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_TCP_SOCKET_ID(TmpSocketId))
    {
      Result = Etm_VApiCloseSocket(Header, (TcpIp_SocketIdType)TmpSocketId, Abort);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171529 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpCreateAndBind(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiCreateAndBind(Header, TCPIP_SOCK_PROT_TCP);
}

/* \trace SPEC-2171530 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpSendData(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  uint16 TmpSocketId = 0u;
  uint16 TotalLength = 0u;

  uint8 TmpData = 0u;
  uint8 *DataPtr = &TmpData;
  uint16 DataLength = 0u;

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &TotalLength);
  Result |= Etm_VGetVIntDataPtr(Header->Payload, Header->PayloadLength, 4u, &DataPtr, &DataLength, FALSE);

  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_TCP_SOCKET_ID(TmpSocketId))
    {
      Result = Etm_VApiSendData(Header, (TcpIp_SocketIdType)TmpSocketId, TotalLength, NULL_PTR, DataLength);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171531 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpReceiveAndForward(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiReceiveAndForward(Header, TCPIP_SOCK_PROT_TCP);
}

/* \trace SPEC-2171532 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpListenAndAccept(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  uint16 TmpSocketId = 0u;
  uint16 MaxConnections = 0u;

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &MaxConnections);

  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_TCP_SOCKET_ID(TmpSocketId))
    {
#if (ETM_TCP_ENABLED == STD_ON)
      /* Check for free tcp sockets */
      /* Check number of possible connections and check number of configured connection limit */
      if((MaxConnections < ETM_TCPIP_NUM_TCP_SOCKETS) && (MaxConnections <= ETM_CHANNELS_TEST_TCP))
      {
        Result = TcpIp_TcpListen((TcpIp_SocketIdType)TmpSocketId, MaxConnections);
      }
      else
      {
        Result = E_NOT_OK;
      }
#else
      Result = E_NOT_OK;
#endif
      
      (void)Etm_VSendResponseWithoutPayload(Header, (Etm_ResultIdType)Result);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171533 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpConnect(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;

  uint16 TmpSocketId = 0u;
  uint16 DestAddrLength = 0u;
  TcpIp_SockAddrInXType TmpDestAddr = {0u};

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Result |= Etm_VGetVIntAddr(Header->Payload, Header->PayloadLength, 4u, (ETM_P2V(TcpIp_SockAddrType))&TmpDestAddr, &DestAddrLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  ((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port = ETM_HTONS(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_TCP_SOCKET_ID(TmpSocketId))
    {
#if (ETM_TCP_ENABLED == STD_ON)
      Result = TcpIp_TcpConnect((TcpIp_SocketIdType)TmpSocketId, (ETM_P2C(TcpIp_SockAddrType))&TmpDestAddr); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
#else
      Result = E_NOT_OK;
#endif

      (void)Etm_VSendResponseWithoutPayload(Header, (Etm_ResultIdType)Result);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2171534 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpConfigureSocket(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiConfigureSocket(Header);
}

/* \trace SPEC-2238731 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpShutdown(ETM_P2C(Etm_HeaderType) Header)
{
  /* TCP and UDP handling is the same so move parameter handling to function call */
  return Etm_VApiShutdown(Header);
}

/**********************************************************************************************************************
 *  ETM HELPERS -- COMMAND HANDLING -- COMMON APIS
 *********************************************************************************************************************/

/* \trace SPEC-2171528 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiCloseSocket(ETM_P2C(Etm_HeaderType) Header, const TcpIp_SocketIdType SocketId, const boolean Abort)
{
  Std_ReturnType Result = E_NOT_OK;

  if((SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_UDP_V6].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_V6].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C4].SocketId) ||
     (SocketId == Etm_CommandChannels[ETM_CMD_CHAN_IDX_TCP_C6].SocketId))
  {
    /* do not close command channel */
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
  }
  else
  {
#if (ETM_TCPIP_ERRORS_ENABLED == STD_ON)
    TcpIp_SetLastSockError(0 /* no error */);
#endif

    Result = TcpIp_Close(SocketId, Abort);
    
#if (ETM_TCPIP_ERRORS_ENABLED == STD_ON)
    if(TcpIp_LastSockError != 0 /* no error */)
    {
      Result = E_NOT_OK;
    }
#endif
    
    (void)Etm_VSendResponseWithoutPayload(Header, (Etm_ResultIdType)Result);
  }

  return Result;
}

/* \trace SPEC-2171529 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiCreateAndBind(ETM_P2C(Etm_HeaderType) Header, const TcpIp_ProtocolType Protocol)
{
  Std_ReturnType Result = E_OK;
  
  uint16 ResultData = ETM_HTONS_UINT8(TCPIP_INV_SOCKET_ID);
  uint16 LocAddrLength = 0u;
  const uint16 ResultDataLength = 2u;

  boolean DoBind = TRUE;
  TcpIp_SockAddrInXType TmpLocAddr = {0u};

  Result |= Etm_VGetNext8Bit(Header->Payload, Header->PayloadLength, 0u, &DoBind);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 1u, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpLocAddr)->port)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
  Result |= Etm_VGetVIntAddr(Header->Payload, Header->PayloadLength, 3u, (ETM_P2V(TcpIp_SockAddrType))&TmpLocAddr, &LocAddrLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

  /* htons (byte order) is called during bind call */

  if(Result == E_OK)
  {
    uint8 TestChannelIndex = Etm_VFindTestChannelIndex(TCPIP_INV_SOCKET_ID);

    if(TestChannelIndex != TCPIP_INV_SOCKET_ID)
    {
      Result = TcpIp_EtmGetSocket(((ETM_P2C(TcpIp_SockAddrType))&TmpLocAddr)->domain, Protocol, &(Etm_TestChannels[TestChannelIndex].SocketId)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
      ResultData = ETM_HTONS_UINT8(Etm_TestChannels[TestChannelIndex].SocketId);
    }
    else
    {
      Result = E_NOT_OK;
    }

    if((Result == E_OK) && (TestChannelIndex != TCPIP_INV_SOCKET_ID))
    {
      if(Protocol == TCPIP_SOCK_PROT_TCP)
      {
        uint32 tmpBufSizeRx = ETM_TCPIP_BUFFER_SIZE_TCP_RX;
        uint32 tmpBufSizeTx = ETM_TCPIP_BUFFER_SIZE_TCP_TX;

        Result  = TcpIp_ChangeParameter(Etm_TestChannels[TestChannelIndex].SocketId, TCPIP_PARAMID_TCP_RXWND_MAX, (ETM_P2V(uint8))&tmpBufSizeRx);    /* PRQA S 0310, 3689 */ /* MD_Etm_11.4_0310_Api, MD_Etm_21.1_3689 */
        Result |= TcpIp_ChangeParameter(Etm_TestChannels[TestChannelIndex].SocketId, TCPIP_PARAMID_V_TCP_TXBUFSIZE, (ETM_P2V(uint8))&tmpBufSizeTx);  /* PRQA S 0310, 3689 */ /* MD_Etm_11.4_0310_Api, MD_Etm_21.1_3689 */
      }

      if(Result == E_OK)
      {
        if((DoBind == TRUE) || (Protocol == TCPIP_SOCK_PROT_TCP))
        {
          TcpIp_LocalAddrIdType TmpLocAddrId = Etm_VGetLocAddrIdFromAddr((ETM_P2C(TcpIp_SockAddrType))&TmpLocAddr); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
          
          if( ((ETM_P2C(TcpIp_SockAddrInetType))&TmpLocAddr)->port == ETM_PORT_ANY) /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
          {
            ((ETM_P2V(TcpIp_SockAddrInetType))&TmpLocAddr)->port = TCPIP_PORT_ANY; /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
          }

          Result = TcpIp_Bind(Etm_TestChannels[TestChannelIndex].SocketId, TmpLocAddrId, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpLocAddr)->port)); /* PRQA S 0310, 3689 */ /* MD_Etm_11.4_0310_AddrPtr, MD_Etm_21.1_3689 */
        }
        
        if(Result == E_OK)
        {
          (void)Etm_VSendResponse(Header, ETM_RID_E_OK, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
        }
        else
        {
          Result = E_NOT_OK;
          (void)Etm_VSendResponse(Header, ETM_RID_E_UBS, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
        }
      }
      else
      {
        Result = E_NOT_OK;
        (void)Etm_VSendResponse(Header, ETM_RID_E_ISB, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
      }
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponse(Header, ETM_RID_E_UCS, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponse(Header, ETM_RID_E_INV, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
  }

  return Result;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* \trace SPEC-2171530 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiSendData(
                    ETM_P2C(Etm_HeaderType) Header,
                    const TcpIp_SocketIdType SocketId,
                    const uint16 TotalLength,
                    ETM_P2C(TcpIp_SockAddrType) DestinationAddressPtr,
                    const uint16 DataLength)
{
  Std_ReturnType Result = E_NOT_OK;

  uint16 TmpLengthToTransmit = ETM_MAX(TotalLength, DataLength);
  uint16 TmpLengthToTransmitNow;
  
  if(Etm_SendDataCommandIsPending == TRUE)
  {
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_PEN);
    return Result;
  }

  if((Etm_VTestChannelActive(SocketId)) && ETM_COND_VALID_SOCKET_ID(SocketId))
  {
    if(E_OK == Etm_VSaveCommand(Header))
    {
      if(ETM_COND_VALID_UDP_SOCKET_ID(SocketId))
      {
        TmpLengthToTransmitNow = ETM_MIN(TmpLengthToTransmit, ETM_TCPIP_MIN_MMS);
      }
      else
      {
        TmpLengthToTransmitNow = ETM_MIN(TmpLengthToTransmit, ETM_TCPIP_BUFFER_SIZE_TCP_TX);
      }

      if(TmpLengthToTransmit == TmpLengthToTransmitNow)
      { /* Send data directly at once */
      
        if(ETM_COND_VALID_UDP_SOCKET_ID(SocketId))
        {
          if(TCPIP_OK == TcpIp_UdpTransmit(SocketId, NULL_PTR, (ETM_P2V(TcpIp_SockAddrType))DestinationAddressPtr, TmpLengthToTransmitNow)) /* PRQA S 0311 */ /* MD_Etm_11.4_0311_Const */
          {
            Result = E_OK;
          }
          else
          {
            Result = E_NOT_OK;
          }
        }
        else
        {
#if (ETM_TCP_ENABLED == STD_ON)
          Result = TcpIp_TcpTransmit(SocketId, NULL_PTR, TmpLengthToTransmitNow, TRUE);
#else
          Result = E_NOT_OK;
#endif
        }
      }
      else
      { /* Send data in the next main functions */
        Etm_SendDataCommandIsPending = TRUE;
        Etm_SendDataCommandAlreadySend = 0;
        Result = E_OK;
      }
    }

    (void)Etm_VSendResponseWithoutPayload(Header, (Etm_ResultIdType)Result);
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
  }

  return Result;
} /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */

FUNC(Std_ReturnType, ETM_CODE) Etm_VApiSendDataPending(void)
{
  uint16 TmpSocketId = 0u;
  Std_ReturnType Result = Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 0u, &TmpSocketId);

  if(Result == E_OK)
  {
    if(Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId))
    {
      uint16 TotalLength = 0u;
      uint16 TmpDestAddrLength = 0u;
      TcpIp_SockAddrInXType TmpDestAddr = {0u};

      uint8 TmpData = 0u;
      uint8 *DataPtr = &TmpData;
      uint16 DataLength = 0u;

      if(ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))
      { /* Send UDP data */
        Result |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 2u, &TotalLength);
        Result |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 4u, &(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port)); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
        Result |= Etm_VGetVIntAddr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 6u, (ETM_P2V(TcpIp_SockAddrType))&TmpDestAddr, &TmpDestAddrLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */
        Result |= Etm_VGetVIntDataPtr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, (6u + 2u /* uint16 */ + TmpDestAddrLength), &DataPtr, &DataLength, FALSE);

        ((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port = ETM_HTONS(((ETM_P2V(TcpIp_SockAddrInetType))&TmpDestAddr)->port); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_AddrPtr */

        if(Result == E_OK)
        {
          uint16 TmpLength;
          /* max length (overall) who should be send */
          TmpLength = ETM_MAX(TotalLength, DataLength);
          /* max length (overall)  who must/could be send now */
          TmpLength = ETM_MIN((uint16)(TmpLength - Etm_SendDataCommandAlreadySend), ETM_TCPIP_MIN_MMS);

          if(TCPIP_OK == TcpIp_UdpTransmit((TcpIp_SocketIdType)TmpSocketId, NULL_PTR, (ETM_P2V(TcpIp_SockAddrType))&TmpDestAddr, TmpLength)) /* PRQA S 0311 */ /* MD_Etm_11.4_0311_Const */
          {
            Result = E_OK;
          }
          else
          {
            Result = E_NOT_OK;
          }
        }
      }
      else
      { /* Send TCP data */
        Result |= Etm_VGetNext16Bit(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 2u, &TotalLength);
        Result |= Etm_VGetVIntDataPtr(Etm_SendDataCommand, ETM_STUB_MAX_COMMAND_SIZE, 4u, &DataPtr, &DataLength, FALSE);

        if(Result == E_OK)
        {
          uint16 TmpLength;
          /* max length (overall) who should be send */
          TmpLength = ETM_MAX(TotalLength, DataLength);
          /* max length (overall)  who must/could be send now */
          TmpLength = ETM_MIN((uint16)(TmpLength - Etm_SendDataCommandAlreadySend), ETM_TCPIP_BUFFER_SIZE_TCP_TX);

  #if (ETM_TCP_ENABLED == STD_ON)
          if(E_OK == TcpIp_TcpTransmit((TcpIp_SocketIdType)TmpSocketId, NULL_PTR, TmpLength, TRUE))
          {
            Result = E_OK;
          }
          else
          {
            Result = E_NOT_OK;
          }
  #else
          /* Transmission failed */
          /* No TCP configured */
          Etm_SendDataCommandIsPending = FALSE;
          Etm_SendDataCommandAlreadySend = 0;
          Result = E_NOT_OK;
  #endif
        }
      }
    }
    else
    {
      /* Transmission failed */
      /* TestChannel (Socket) closed - abort fransmission */
      Etm_SendDataCommandIsPending = FALSE;
      Etm_SendDataCommandAlreadySend = 0;
      Result = E_NOT_OK;
    }
  }
  return Result;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* \trace SPEC-2171516 */
/* \trace SPEC-2171531 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiReceiveAndForward(ETM_P2C(Etm_HeaderType) Header, const TcpIp_ProtocolType Protocol)
{
  Std_ReturnType Result = E_OK;
  
  uint16 TmpSocketId = 0u;
  uint16 MaxForward = 0u;
  uint16 MaxLength = 0u;

  uint16 ResultData = 0u;
  const uint16 ResultDataLength = 2u;

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &MaxForward);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 4u, &MaxLength);
  
  if((Result == E_OK) &&
    ((Protocol == TCPIP_SOCK_PROT_UDP) || (Protocol == TCPIP_SOCK_PROT_TCP)))
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) &&
      (((Protocol == TCPIP_SOCK_PROT_UDP) && (ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))) ||
       ((Protocol == TCPIP_SOCK_PROT_TCP) && (ETM_COND_VALID_TCP_SOCKET_ID(TmpSocketId)))))
    {
      uint8 TestChannelIndex = Etm_VFindTestChannelIndex((TcpIp_SocketIdType)TmpSocketId);

      if(TestChannelIndex != TCPIP_INV_SOCKET_ID)
      {
        ResultData = ETM_HTONS((uint16)Etm_TestChannels[TestChannelIndex].RecvFwdDropCount);

        if(ETM_COND_VALID_UDP_SOCKET_ID(TmpSocketId))
        {
          Result = E_OK;
        }
        else
        {
#if (ETM_TCP_ENABLED == STD_ON)
          Result = TcpIp_TcpReceived((TcpIp_SocketIdType)TmpSocketId, ResultData);
#else
          Result = E_NOT_OK;
#endif
        }

        /*
         * Etm_TestChannels[TestChannelIndex].RecvFwdMaxForward
         * Due to the reason that it is not possible to forward a received full sized tcp or udp package back to the tester the forwardeed/mirrowed payload is cut off.
         * In addition to a full sized 1500 byte received tcp or udp package an extra etm event header is added and so it is not possible to forward all of the received
         * data. Etm cut off the data to fit in an 'general sized' package that mean: etm substract all the maximum header sizes (eth,ipv4,ipv6,tcp,udp,etm) from the
         * full mtu size - this is a 'general size' used for the payload size. Etm cut off the forwarded payload to a minimal/maximum size fitting for all configurations
         * so it does not matter if the package is forwarded with ipv4 over udp or with ipv6 over tcp.
         */
        Etm_TestChannels[TestChannelIndex].RecvFwdActive = TRUE;
        Etm_TestChannels[TestChannelIndex].RecvFwdMaxForward = ETM_MIN(ETM_MIN(MaxForward, ETM_STUB_MAX_FORWARD_LENGTH), (ETM_TCPIP_MIN_MMS - ETM_EVENT_LENGTH_FORWARD_FIX));
        Etm_TestChannels[TestChannelIndex].RecvFwdMaxLength = MaxLength;
        Etm_TestChannels[TestChannelIndex].RecvFwdDropCount = 0u;
      }
      else
      {
        Result = E_NOT_OK;
      }

      (void)Etm_VSendResponse(Header, (Etm_ResultIdType)Result, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponse(Header, ETM_RID_E_ISD, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponse(Header, ETM_RID_E_INV, (ETM_P2C(uint8))&ResultData, ResultDataLength); /* PRQA S 0310 */ /* MD_Etm_11.4_0310_BufPtr */
  }

  return Result;
}

/* \trace SPEC-2171534 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiConfigureSocket(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_OK;
  
  uint16 TmpSocketId = 0u;
  uint16 ParamId = 0u;
  TcpIp_ParamIdType ParamIdTcpIp = 0u;

  uint8 TmpData = 0u;
  uint8 *DataPtr = &TmpData;
  uint16 DataLength = 0u;

  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 0u, &TmpSocketId);
  Result |= Etm_VGetNext16Bit(Header->Payload, Header->PayloadLength, 2u, &ParamId);
  Result |= Etm_VGetVIntDataPtr(Header->Payload, Header->PayloadLength, 4u, &DataPtr, &DataLength, FALSE);

  if(Result == E_OK)
  {
    /* ParamId mapping */
    switch(ParamId)
    {
    case ETM_CONFIGURE_SOCKET_TTL :
      {
        ParamIdTcpIp = TCPIP_PARAMID_TTL;
      }
      break;
    case ETM_CONFIGURE_SOCKET_PRIORITY :
      {
        ParamIdTcpIp = TCPIP_PARAMID_FRAMEPRIO;
      }
      break;
    default:
      {
        Result = E_NOT_OK;
      }
      break;
    }
  }

  if(Result == E_OK)
  {
    if((Etm_VTestChannelActive((TcpIp_SocketIdType)TmpSocketId)) && ETM_COND_VALID_SOCKET_ID(TmpSocketId))
    {
      Result = TcpIp_ChangeParameter((TcpIp_SocketIdType)TmpSocketId, ParamIdTcpIp, DataPtr);

      (void)Etm_VSendResponseWithoutPayload(Header, (Etm_ResultIdType)Result);
    }
    else
    {
      Result = E_NOT_OK;
      (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_ISD);
    }
  }
  else
  {
    Result = E_NOT_OK;
    (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_INV);
  }

  return Result;
}

/* \trace SPEC-2238731 */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiShutdown(ETM_P2C(Etm_HeaderType) Header)
{
  Std_ReturnType Result = E_NOT_OK;

  (void)Etm_VSendResponseWithoutPayload(Header, ETM_RID_E_NOK); /* not yet supported */

  return Result;
}

/**********************************************************************************************************************
 *  ETM HELPERS
 *********************************************************************************************************************/

#define ETM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
  
  MD_Etm_8.7_3218:
    Reason:     Static variable is only to be used in one function.
    Risk:       No functional risk.
    Prevention: Covered by code review.

  MD_Etm_11.4_0310_AddrPtr:
    Reason:     TcpIp_SockAddrType includes address family to differ between IPv4 and IPv6. The corresponding
                structs also start with the family field so casting is possible.
    Risk:       Casing from IpBase_SockAddrInType or IpBase_SockAddrIn6Type to TcpIp_SockAddrType is allowed. Cast
                from TcpIp_SockAddrType to IpBase_SockAddrInType or IpBase_SockAddrIn6Type is possible if the address
                family field is evaluated. The corresponding struct IpBase_SockAddrInType or IpBase_SockAddrIn6Type
                has the port field on the same position so port can accesed without casting.
    Prevention: Covered by code review.
    
  MD_Etm_11.4_0310_BufPtr:
    Reason:     Cast from uint32/(uint16) to uint8 for easer access to byte fields.
    Risk:       Depending on the buffer, an unaligned memory exception may occur on certain platforms.
    Prevention: Buffers passed to the function need to be 4/(2) byte aligned.

  MD_Etm_11.4_0310_Api:
    Reason:     Cast parameter to uint8 pointer used by API.
    Risk:       Cast to different object pointer type.
    Prevention: Covered by code review.

  MD_Etm_11.4_0310_CmdChn:
    Reason:     See MD_Etm_11.4_0310_AddrPtr.
    Risk:       See MD_Etm_11.4_0310_AddrPtr.
    Prevention: Covered by code review.

  MD_Etm_11.5_0311_Const:
    Reason:     Cast removing const qualifier is necessary. Used API has no const qualifier.
    Risk:       The component is able to modify the pointer content which could result in undefined behavior.
    Prevention: Covered by code review.

  MD_Etm_12.4_3415_Side:
    Reason:     Second statement is only needed when first statement is true. The side effect is for local usage only (if both statements are true).
    Risk:       Undefined behavior in relation to the evaluation.
    Prevention: Covered by code review.

  MD_Etm_14.1:
    Reason:     Unrechable statement or constant boolean value due to comparation to precompiled data.
    Risk:       Compiler warning.
    Prevention: Covered by code review.

  MD_Etm_14.2_3112:
    Reason:     Dummy statement to avoid compiler warnings.
    Risk:       There is no risk as such statements have no effect on the code.
    Prevention: Covered by code review.

  MD_Etm_17.4_0488:
    Reason:     Usage of pointer within array.
    Risk:       Memory access violation.
    Prevention: Covered by code review.

  MD_Etm_18.4_0759:
    Reason:     Usage of union type is used to save IPv6 address. Data can accessed as uint8(byte)/uint32 array.
    Risk:       No functional risk.
    Prevention: Covered by code review.

  MD_Etm_21.1_3382:
    Reason:     Subtract unsigned numbers (e.g. A - B) may fail if B represents a higher number. The wraparound cannot be represented by an unsigned integer.
    Risk:       Operation will sometimes result in wraparound.
    Prevention: Covered by code review. Check size from A and B and subtract only if B is higher.

  MD_Etm_21.1_3689:
    Reason:     Array Index is calculated automatically and is cecked befor usage.
    Risk:       Undefinded memory operation results in undefined behavior.
    Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Etm.c
 *********************************************************************************************************************/
