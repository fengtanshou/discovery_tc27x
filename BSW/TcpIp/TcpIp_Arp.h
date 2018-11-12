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
 *         \file  TcpIp_Arp.h
 *        \brief  Implementation of Address Resolution Protocol (ARP) for IPv4
 *
 *      \details  This file is part of the TcpIp IPv4 submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp IPv4 submodule. >> TcpIp_IpV4.h
 *********************************************************************************************************************/

#if !defined (IPV4_ARP_H)
# define IPV4_ARP_H

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)

/*
|0              |8              |16             |24             |
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          HwAddrType           |         ProtAddrType          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   HwAddrSize  |  ProtAddrSize |           Operation           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          SrcMacAddr                           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          SrcMacAddr           |       Source IP Address       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|       Source IP Address       |          DestMacAddr          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          DestMacAddr                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                     Destination Address                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
ARP packet format
*/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_IpV4.h"
#include "TcpIp_IpV4_Cfg.h"

#include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ARP ApiIds */
#define IPV4_ARP_API_ID_RX_INDICATION           0x40u
#define IPV4_ARP_API_ID_TX_CONFIRMATION         0x41u

#define IPV4_ARP_API_ID_INIT                    0x50u
#define IPV4_ARP_API_ID_RESET                   0x51u
#define IPV4_ARP_API_ID_MAIN_FUNCTION           0x52u
#define IPV4_ARP_API_ID_GET_PHYS_ADDR           0x53u
#define IPV4_ARP_API_ID_SEND_ARP_REQUEST        0x54u
#define IPV4_ARP_API_ID_MAP_IP_TO_PHYS_MC_ADDR  0x55u
#define IPV4_ARP_API_ID_SEND_ARP_PROBE          0x56u
#define IPV4_ARP_API_ID_SEND_ARP_ANNOUNCEMENT   0x57u
#define IPV4_ARP_API_ID_SEND_GRATUITOUS_ARP_REQ 0x58u

#define IPV4_ARP_API_ID_V_INTERNAL_FUNCTION     0xFFu

/* ARP state */
#define IPV4_ARP_STATE_UNINIT                   0x00u
#define IPV4_ARP_STATE_INITMEMORY               0x01u
#define IPV4_ARP_STATE_INIT                     0x02u

#define IPV4_ARP_HW_ADDR_SIZE_ETHERNET                6
#define IPV4_ARP_PROT_ADDR_SIZE_IPV4                  4
#define IPV4_ARP_PACKET_LEN_BYTE                     28

/* status of ARP table elements */
#define IPV4_ARP_ELSTATUS_INVALID                     0
#define IPV4_ARP_ELSTATUS_VALID                       1
#define IPV4_ARP_ELSTATUS_INPROGESS                   2
#define IPV4_ARP_ELSTATUS_PROBE                       3

#define IPV4_ARP_MAX_TIME_DIFF              (0x7FFFFFFF)

#define IPV4_ARP_FRAME_TYPE                      0x0806

#if CPU_BYTE_ORDER == LOW_BYTE_FIRST
/* LITTLEENDIAN */
#define IPV4_ARP_HW_ADDR_TYPE_ETHERNET           0x0100
#define IPV4_ARP_PROT_ADDR_TYPE_IPV4             0x0008
#define IPV4_ARP_OP_REQUEST                      0x0100
#define IPV4_ARP_OP_REPLY                        0x0200
#else
/* BIGENDIAN */
#define IPV4_ARP_HW_ADDR_TYPE_ETHERNET           0x0001
#define IPV4_ARP_PROT_ADDR_TYPE_IPV4             0x0800
#define IPV4_ARP_OP_REQUEST                      0x0001
#define IPV4_ARP_OP_REPLY                        0x0002
#endif /* CPU_BYTE_ORDER */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 IpV4_Arp_StateType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define IPV4_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */
/***********************************************************************************************************************
 *  IpV4_Arp_Init
 **********************************************************************************************************************/
/*! \brief      This API call stores the start address of the post build time configuration of the Address Resolution
 *              Protocol and may be used to initialize the data structures.
 *  \param[in]  CfgPtr             pointer to module configuration
 *  \context    initialization
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Arp_Init(
    P2CONST(IpV4_Arp_ConfigType, IPV4_APPL_DATA, IPV4_CONST) CfgPtr );

/***********************************************************************************************************************
 *  IpV4_Arp_MapIpToPhysMulticastAddr
 **********************************************************************************************************************/
/*! \brief      Map ip multicast address to physical multicast address
 *  \param[in]  NetMcAddr             network layer multicast address (network byte order)
 *  \param[out] PhysMcAddr            physical layer multicast address (network byte order)
 *  \context    task level
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Arp_MapIpToPhysMulticastAddr(IpBase_AddrInType NetMcAddr, P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) PhysMcAddr);

/***********************************************************************************************************************
 *  IpV4_Arp_GetPhysicalAddress
 **********************************************************************************************************************/
/*! \brief        Get physical address for a given network address
 *  \description  The cache table access is optimised for requesting the same address many times for the same socket.
 *                To use this optimization the parameter 'UseSockInfo' has to be TRUE. If the optimized access shall
 *                not be used the parameter 'UseSockInfo' has to be FALSE.
 *  \param[in]  IpCtrlIdx               Controller index
 *  \param[in]  SockIdx                 Socket index
 *  \param[in]  UseSockInfo             Use the socket information for faster table access and update mapping table
 *  \param[in]  NetAddr                 Network address (network byte order)
 *  \param[out] PhysAddrPtr             Pointer for physical address (network byte order)
 *  \param[in]  InitRes                 Specifies if the address resolution shall be initiated (TRUE) or not (FALSE) in
 *                                      case the physical address related to the specified IP address is currently
 *                                      unknown.
 *  \return     TCP_OK                  Address could be resolved
 *              TCP_E_NOT_OK            Address could not be resolved, resolution has NOT been triggered, even in case
 *                                      the parameter InitRes has indicated the callers wish to do so,
 *              TCPIP_E_PHYS_ADDR_MISS  Address could not be resolved, resolution has been triggered successfully,
 *                                      depending on the value of the parameter InitRes.
 *  \context    initialization or task level
 **********************************************************************************************************************/
extern FUNC(TcpIp_ReturnType, IPV4_CODE) IpV4_Arp_GetPhysicalAddress(
    uint8 IpCtrlIdx,
    TcpIp_SockIdxType SockIdx,
    boolean UseSockInfo,
    IpBase_AddrInType NetAddr,
    P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) PhysAddrPtr,
    boolean InitRes );

/***********************************************************************************************************************
 *  IpV4_Arp_SendArpRequest
 **********************************************************************************************************************/
/*! \brief      Send ARP request message
 *  \param[in]  IpCtrlIdx             controller index
 *  \param[in]  NetAddr               network address
 *  \context    task level
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpRequest(
    uint8 IpCtrlIdx,
    IpBase_AddrInType NetAddr );

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_SendArpProbe
 **********************************************************************************************************************/
/*! \brief      Sends an ARP Probe packet as specified in [RFC3927 1.2. Terminology]
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \param[in]  IpAddrToProbe         network address to be probed
 *  \context    task level
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpProbe(
    uint8             IpCtrlIdx,
    IpBase_AddrInType IpAddrToProbe);

/***********************************************************************************************************************
 *  IpV4_Arp_SendArpAnnouncement
 **********************************************************************************************************************/
/*! \brief      Sends an ARP Announcement packet as specified in [RFC3927 1.2. Terminology]
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \param[in]  IpAddrToAnnounce      network address to be announced
 *  \context    task level
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpAnnouncement(
    uint8             IpCtrlIdx,
    IpBase_AddrInType IpAddrToAnnounce);
#endif

/***********************************************************************************************************************
 *  IpV4_Arp_SendGratuitousArpReq
 **********************************************************************************************************************/
/*! \brief      Sends an gratuitous ARP request packet as specified in [RFC2002 4.6. second indentation]
 *  \details    This function sends an ARP REQUEST packet with these properties:
 *              1. THE NODES [NEW, I.E. CURRENT] IP ADDRESS
 *              2. THE NODES [NEW, I.E. CURRENT] MAC ADDRESS
 *              The packets field TARGET HW ADDRESS is handled like at any other ARP request implemented by the ARP subcomponent:
 *              The request packet is finally sent using IpV4_Arp_VSendMessage() with parameter IPV4_ARP_OP_REQUEST
 *              The packet is sent only in case the affected interface has an assigned IP address
 *              The function returns E_NOT_OK in case one of the conditions 4. or 5. are not fulfilled or a step to check them can not be conducted.
 *
 *  \param[in]    IpAddrId        Local address identifier implicitely specifing the EthIf controller for which the
 *                                physical address shall be obtained.
 *  \return       Std_ReturnType: E_OK in case all parameters were valid, conditions were 'ok' and
 *                                the gratuitous ARP message was successfully handed to the lower layer.
 *                                E_NOT_OK otherwise.
 *  \pre          PRE_TCPIP_ARP_INIT
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        DSGN-TcpIpGratuitousArpRequestTransmission
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendGratuitousArpReq(
    IpV4_AddrIdType IpAddrId );

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_MainFunction
 **********************************************************************************************************************/
/*! \brief      Main function
 *  \context    task level
 *  \note       This function is called every IPV4_MAIN_FCT_PERIOD_MSEC ms
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Arp_MainFunction(void);

/***********************************************************************************************************************
 *  IpV4_Arp_Reset
 **********************************************************************************************************************/
/*! \brief      Reset elements in Arp_ResTable for given controller index
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \context    task level
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Arp_Reset(
    uint8 IpCtrlIdx );
#endif

#define IPV4_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#endif  /* (TCPIP_SUPPORT_IPV4 == STD_ON) */
#endif  /* IPV4_ARP_H */

/* \PRE PRE_TCPIP_ARP_INIT
        IpV4_Arp must have been initialized by a call to IpV4_Arp_Init(<valid configuration pointer>). */

/**********************************************************************************************************************
 *  END OF FILE: IpV4_Arp.h
 *********************************************************************************************************************/
