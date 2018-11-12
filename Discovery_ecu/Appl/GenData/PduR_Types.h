/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Types.h
 *   Generation Time: 2018-08-21 08:49:57
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be unique. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/CanTp/CanTpConfig/CanTpChannel_Func/CanTpRxNSdu[0:CanTpRxNSduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd), /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx_Functional_Address[0:DcmDslProtocolRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Functional_request), /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be[0:ComIPduType](value=NORMAL)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request/PduRDestPdu[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Functional_request) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request/PduRSrcPdu[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be unique. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/CanTp/CanTpConfig/CanTpChannel_physical/CanTpRxNSdu_002[0:CanTpRxNSduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_PhysReq_P2P_PP_DIAG_PhysReq_P2P_Rx_0fb271d2_c07658fd), /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx_Physical_Address[0:DcmDslProtocolRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Physical_request), /ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be[0:ComIPduType](value=NORMAL)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request/PduRDestPdu_1[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Physical_request) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request/PduRSrcPdu_1[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_PhysReq_P2P_PP_DIAG_PhysReq_P2P_Rx_0fb271d2_c07658fd) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type TRANSPORT_PROTOCOL of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type TRANSPORT_PROTOCOL of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 *********************************************************************************************************************/

#if !defined (PDUR_TYPES_H)
# define PDUR_TYPES_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ComStack_Types.h"
/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* \trace SPEC-631, SPEC-38457 */

typedef P2VAR(PduInfoType, TYPEDEF, PDUR_APPL_DATA) PduInfoTypeApplPtr; /* Helper type for compiler abstraction */

typedef uint16 PduR_RoutingPathGroupIdType;

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_TYPES_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Types.h
 *********************************************************************************************************************/

