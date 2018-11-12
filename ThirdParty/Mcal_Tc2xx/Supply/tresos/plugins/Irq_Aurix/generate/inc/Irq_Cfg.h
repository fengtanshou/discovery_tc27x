[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Irq_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   $DATE       : 2015-10-13 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Irq configuration generated out of ECU configuration file  **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*************************************************************************/!][!//
[!// 
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Irq_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**   GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : Irq configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                            **
*******************************************************************************/
#ifndef IRQ_CFG_H 
#define IRQ_CFG_H 
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Irq')[1]"!][!//
[!//
[!//
[!VAR "Readbit" = "num:i(0)"!][!//
[!VAR "ErrorFlag" = "num:i(0)"!][!//
[!VAR "Variable0" = "num:i(0)"!][!//
[!VAR "Variable1" = "num:i(0)"!][!//
[!VAR "Variable2" = "num:i(0)"!][!//
[!VAR "Variable3" = "num:i(0)"!][!//
[!VAR "Variable4" = "num:i(0)"!][!//
[!VAR "Variable5" = "num:i(0)"!][!//
[!VAR "Variable6" = "num:i(0)"!][!//
[!VAR "Variable7" = "num:i(0)"!][!//
[!VAR "Variable8" = "num:i(0)"!][!//
[!VAR "Variable9" = "num:i(0)"!][!//
[!VAR "Variable10" = "num:i(0)"!][!//
[!VAR "Variable11" = "num:i(0)"!][!//
[!VAR "Variable12" = "num:i(0)"!][!//
[!VAR "Variable13" = "num:i(0)"!][!//
[!VAR "Variable14" = "num:i(0)"!][!//
[!VAR "Variable15" = "num:i(0)"!][!//
[!VAR "DmaMaxPrio" = "num:i(ecu:get('Irq.DmaMaxPrio'))"!][!//

[!//
[!/*****************************************************************************
  MACRO: CG_PriorityCheck 
  
  Macro to determine whether the configured priorities are different or not
  
  Input Parameters:
  Givenno - Value of the node (SrnId: Priority Number)
  cont - Module Name
*****************************************************************************/!]
[!MACRO "CG_PriorityCheck", "Givenno" = "","cont" = ""!][!//
[!IF "($Givenno != num:i(0))"!][!//
[!VAR "Givenno1" = "num:i($Givenno div num:i(32))"!][!//
[!VAR "Givenno2" = "num:i($Givenno mod num:i(32))"!][!//
[!IF "($Givenno1 = num:i(0))"!][!//
[!IF "bit:getbit($Variable0,$Givenno2) != 'true'"!][!//
[!VAR "Variable0" = "bit:bitset($Variable0,$Givenno2)"!][!//
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!]
[!ENDIF!][!//			
[!ELSEIF "($Givenno1 = num:i(1))"!][!//
[!IF "bit:getbit($Variable1,$Givenno2) != 'true'"!][!//
[!VAR "Variable1" = "bit:bitset($Variable1, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(2))"!][!//
[!IF "bit:getbit($Variable2,$Givenno2) != 'true'"!][!//
[!VAR "Variable2" = "bit:bitset($Variable2, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(3))"!][!//
[!IF "bit:getbit($Variable3,$Givenno2) != 'true'"!][!//
[!VAR "Variable3" = "bit:bitset($Variable3, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(4))"!][!//
[!IF "bit:getbit($Variable4,$Givenno2) != 'true'"!][!//
[!VAR "Variable4" = "bit:bitset($Variable4, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(5))"!][!//
[!IF "bit:getbit($Variable5,$Givenno2) != 'true'"!][!//
[!VAR "Variable5" = "bit:bitset($Variable5, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(6))"!][!//
[!IF "bit:getbit($Variable6,$Givenno2) != 'true'"!][!//
[!VAR "Variable6" = "bit:bitset($Variable6, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(7))"!][!//
[!IF "bit:getbit($Variable7,$Givenno2) != 'true'"!][!//
[!VAR "Variable7" = "bit:bitset($Variable7, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(8))"!][!//
[!IF "bit:getbit($Variable8,$Givenno2) != 'true'"!][!//
[!VAR "Variable8" = "bit:bitset($Variable8, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(9))"!][!//
[!IF "bit:getbit($Variable9,$Givenno2) != 'true'"!][!//
[!VAR "Variable9" = "bit:bitset($Variable9, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(10))"!][!//
[!IF "bit:getbit($Variable10,$Givenno2) != 'true'"!][!//
[!VAR "Variable10" = "bit:bitset($Variable10, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(11))"!][!//
[!IF "bit:getbit($Variable11,$Givenno2) != 'true'"!][!//
[!VAR "Variable11" = "bit:bitset($Variable11, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(12))"!][!//
[!IF "bit:getbit($Variable12,$Givenno2) != 'true'"!][!//
[!VAR "Variable12" = "bit:bitset($Variable12, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(13))"!][!//
[!IF "bit:getbit($Variable13,$Givenno2) != 'true'"!][!//
[!VAR "Variable13" = "bit:bitset($Variable13, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(14))"!][!//
[!IF "bit:getbit($Variable14,$Givenno2) != 'true'"!][!//
[!VAR "Variable14" = "bit:bitset($Variable14, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSEIF "($Givenno1 = num:i(15))"!][!//
[!IF "bit:getbit($Variable15,$Givenno2) != 'true'"!][!//
[!VAR "Variable15" = "bit:bitset($Variable15, $Givenno2)"!][!//	
[!ELSE!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "($ErrorFlag != num:i(0))"!][!//
[!ERROR!][!//
Same Priority is configured in two places, check [!"$cont"!] and some other container.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/************************* interrupt CATEGORY *********************************/
#define IRQ_CAT1                    (0)
#define IRQ_CAT23                   (1)
/************************* interrupt Type of Service **************************/
#define IRQ_TOS_CPU0                (0x0000)
#define IRQ_TOS_CPU1                (0x0800)
#define IRQ_TOS_CPU2                (0x1000)
#define IRQ_TOS_DMA                 (0x1800)
/*
                     Container : IrqGeneralConfiguration
*/

/*
Configuration: IRQ_OSEK_ENABLE 
- if TRUE, OSEK RTOS is used, 
  Both CAT1 and CAT23 interrupt categories can be configured 
  Any CAT23 interrupt priority should be greater than CAT1 interrupt priority
- if FALSE,OSEK RTOS is not used
  Only CAT1 interrupt category can be configured 
*/

#define IRQ_OSEK_ENABLE  [!IF "IrqGeneral/IrqOsekEnable = 'true'"!][!//
           (STD_ON)[!//
[!ELSE!][!//
           (STD_OFF)[!//
[!ENDIF!]

[!NOCODE!][!//
[!VAR "MIN_CAT1_LEVEL" = "num:i(511)"!][!//
[!VAR "MAX_CAT2_LEVEL" = "num:i(0)"!][!//
[!VAR "PREVIOUS"       = "num:i(0)"!][!// 
[!ENDNOCODE!][!//

[!VAR "IrqAscLinExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqAscLinConfig/*)) = 1"!][!//
/*
                     Container : IrqAscLin interruptConfiguration
*/
[!VAR "IrqAscLinExist" = "'STD_ON'"!][!//
/* ASC Lin Tx interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinTxCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_CAT          (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinTxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_CAT         (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinTxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* ASC Lin Tx interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinTxTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ASCLINTX'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_PRIO         [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_PRIO        [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinTxCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
   [!IF "$TypeOfService != 'DMA'"!][!//   
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
    [!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!// 
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ASCLINTX interrupt Priority Setting for loop */!][!//

/* ASC Lin Tx interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinTxTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_TOS          (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinTxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_TX_TOS         (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinTxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinTxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinTxTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* ASC Lin Rx interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinRxCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_CAT          (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinRxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_CAT         (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinRxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* ASC Lin Rx interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinRxTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ASCLINRX'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_PRIO         [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_PRIO        [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinRxCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ASCLINRX interrupt Priority Setting for loop */!][!//

/* ASC Lin Rx interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinRxTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_TOS          (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinRxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_RX_TOS         (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinRxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinRxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinRxTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* ASC Lin Err interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_CAT         (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_CAT        (IRQ_[!"IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* ASC Lin Err interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinErrTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ASCLINERR'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_PRIO        [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_PRIO       [!"num:inttohex(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ASCLINERR interrupt Priority Setting for loop */!][!//

/* ASC Lin Err interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinErrTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_TOS         (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinErrTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_ASCLIN[!"num:i($SrnId - 1)"!]_ERR_TOS        (IRQ_TOS_[!"IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinErrTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAscLinConfig/*[1]/IrqAscLinPrioConfig/IrqAscLinErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAscLinConfig/*[1]/IrqAscLinTosConfig/IrqAscLinErrTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqQspiExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqQspiConfig/*)) = 1"!][!//
/*
                     Container : IrqQspi interruptConfiguration
*/
[!VAR "IrqQspiExist" = "'STD_ON'"!][!//
[!//
/* Qspi Tx interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiTxCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_TX_CAT            (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiTxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi Tx interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiTxPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiTxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiTxTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPITX'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_TX_PRIO           [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiTxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiTxPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiTxCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPITX interrupt Priority Setting for loop */!][!//

/* Qspi Tx interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiTxTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_TX_TOS            (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiTxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiTxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiTxTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* Qspi Rx interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiRxCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_RX_CAT            (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiRxCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi Rx interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiRxPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiRxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiRxTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPIRX'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_RX_PRIO           [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiRxPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiRxPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiRxCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPIRX interrupt Priority Setting for loop */!][!//

/* Qspi Rx interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiRxTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_RX_TOS            (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiRxTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiRxPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiRxTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* Qspi Err interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiErrCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_ERR_CAT           (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiErrCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi Err interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiErrPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiErrTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPIERR'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_ERR_PRIO          [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiErrPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiErrPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiErrCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPIERR interrupt Priority Setting for loop */!][!//

/* Qspi Err interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiErrTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_ERR_TOS           (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiErrTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiErrTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* Qspi PT interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiPTCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_PT_CAT            (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiPTCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi PT interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiPTPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiPTPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiPTTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPIPT'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_PT_PRIO           [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiPTPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiPTPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiPTCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPIPT interrupt Priority Setting for loop */!][!//

/* Qspi PT interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiPTTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_PT_TOS            (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiPTTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiPTPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiPTTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* Qspi HC interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiHCCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_HC_CAT            (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiHCCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi HC interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiHCPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiHCPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiHCTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPIHC'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_HC_PRIO           [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiHCPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiHCPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiHCCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPIHC interrupt Priority Setting for loop */!][!//

/* Qspi HC interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiHCTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_HC_TOS            (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiHCTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiHCPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiHCTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* Qspi UD interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiUDCatConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_UD_CAT            (IRQ_[!"IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiUDCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Qspi UD interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiUDPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiUDPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiUDTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'QSPIUD'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_UD_PRIO           [!"num:inttohex(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiUDPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiUDPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqQspiConfig/*[1]/IrqQspiCatConfig/IrqQspiUDCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of QSPIUD interrupt Priority Setting for loop */!][!//

/* Qspi UD interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiUDTosConfig/*))"!][!//
#define IRQ_QSPI[!"num:i($SrnId - 1)"!]_UD_TOS            (IRQ_TOS_[!"IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiUDTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqQspiConfig/*[1]/IrqQspiPrioConfig/IrqQspiUDPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqQspiConfig/*[1]/IrqQspiTosConfig/IrqQspiUDTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqMscExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqMscConfig/*)) = 1"!][!//
/*
                     Container : IrqMSC interruptConfiguration
*/
[!VAR "IrqMscExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.MscAvailable'), 'IrqMsc0' )"!][!//
/*MSC0 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0CatConfig/*))"!][!//
#define IRQ_MSC0_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/*MSC0 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'MSC0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_MSC0_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of MSC0 interrupt Priority Setting for loop */!][!//

/*MSC0 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0TosConfig/*))"!][!//
#define IRQ_MSC0_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc0Config/IrqMsc0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.MscAvailable'), 'IrqMsc1' )"!][!//
/*MSC1 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1CatConfig/*))"!][!//
#define IRQ_MSC1_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/*MSC1 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'MSC1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_MSC1_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of MSC1 interrupt Priority Setting for loop */!][!//

/*MSC1 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1TosConfig/*))"!][!//
#define IRQ_MSC1_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc1Config/IrqMsc1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.MscAvailable'), 'IrqMsc2' )"!][!//
/*MSC2 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2CatConfig/*))"!][!//
#define IRQ_MSC2_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/*MSC2 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'MSC2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_MSC2_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of MSC2 interrupt Priority Setting for loop */!][!//

/*MSC2 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2TosConfig/*))"!][!//
#define IRQ_MSC2_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqMscConfig/*[1]/IrqMsc2Config/IrqMsc2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "IrqCCU6Exist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqCCU6Config/*)) = 1"!][!//
/*
                     Container : IrqCCU6 interruptConfiguration
*/
[!VAR "IrqCCU6Exist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.CCU6Available'), 'IrqCCU60' )"!][!//
/*CCU60 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60CatConfig/*))"!][!//
#define IRQ_CCU60_SR[!"num:i($SrnId - 1)"!]_CAT           (IRQ_[!"IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/*CCU60 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'CCU60'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_CCU60_SR[!"num:i($SrnId - 1)"!]_PRIO          [!"num:inttohex(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of CCU60 interrupt Priority Setting for loop */!][!//

/*CCU60 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60TosConfig/*))"!][!//
#define IRQ_CCU60_SR[!"num:i($SrnId - 1)"!]_TOS           (IRQ_TOS_[!"IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCCU6Config/*[1]/IrqCCU60Config/IrqCCU60TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.CCU6Available'), 'IrqCCU61' )"!][!//
/*CCU61 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61CatConfig/*))"!][!//
#define IRQ_CCU61_SR[!"num:i($SrnId - 1)"!]_CAT           (IRQ_[!"IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/*CCU61 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'CCU61'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_CCU61_SR[!"num:i($SrnId - 1)"!]_PRIO          [!"num:inttohex(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of CCU61 interrupt Priority Setting for loop */!][!//

/*CCU61 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61TosConfig/*))"!][!//
#define IRQ_CCU61_SR[!"num:i($SrnId - 1)"!]_TOS           (IRQ_TOS_[!"IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCCU6Config/*[1]/IrqCCU61Config/IrqCCU61TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "IrqGptExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqGptConfig/*)) = 1"!][!//
/*
                     Container : IrqGPTinterruptConfiguration
*/
[!VAR "IrqGptExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.GPT12Available'), 'IrqGPT120' )"!][!//
/* GPT120 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120CatConfig/*))"!][!//
[!IF "($SrnId <= 1)"!][!//
#define IRQ_GPT120_CARPEL_CAT       (IRQ_[!"IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_GPT120_T[!"num:i($SrnId)"!]_CAT           (IRQ_[!"IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/*  GPT120 interrupt Priority setting  */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GPT120'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!// 
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 1)"!][!//
#define IRQ_GPT120_CARPEL_PRIO      [!"num:inttohex(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_GPT120_T[!"num:i($SrnId)"!]_PRIO          [!"num:inttohex(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*[num:i($SrnId)])"!][!//    
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GPT120 interrupt Priority Setting for loop */!][!//

/* GPT120 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120TosConfig/*))"!][!//
[!IF "($SrnId <= 1)"!][!//
#define IRQ_GPT120_CARPEL_TOS       (IRQ_TOS_[!"IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_GPT120_T[!"num:i($SrnId)"!]_TOS           (IRQ_TOS_[!"IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGptConfig/*[1]/IrqGpt120Config/IrqGpt120TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//[!/* End of GPT interrupt */!]  

[!VAR "IrqStmExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqStmConfig/*)) = 1"!][!//
/*
                     Container : IrqSTMinterruptConfiguration
*/
[!VAR "IrqStmExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM0' )"!][!//
/* STM0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0CatConfig/*))"!][!//
#define IRQ_STM0_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqStmConfig/*[1]/IrqStm0Config/IrqStm0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* STM0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm0Config/IrqStm0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'STM0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_STM0_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqStmConfig/*[1]/IrqStm0Config/IrqStm0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of STM0 interrupt Priority Setting for loop */!][!//

/* STM0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0TosConfig/*))"!][!//
#define IRQ_STM0_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqStmConfig/*[1]/IrqStm0Config/IrqStm0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqStmConfig/*[1]/IrqStm0Config/IrqStm0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm0Config/IrqStm0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM1' )"!][!//
/* STM1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1CatConfig/*))"!][!//
#define IRQ_STM1_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqStmConfig/*[1]/IrqStm1Config/IrqStm1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* STM1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm1Config/IrqStm1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'STM1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_STM1_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqStmConfig/*[1]/IrqStm1Config/IrqStm1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of STM1 interrupt Priority Setting for loop */!][!//

/* STM1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1TosConfig/*))"!][!//
#define IRQ_STM1_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqStmConfig/*[1]/IrqStm1Config/IrqStm1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqStmConfig/*[1]/IrqStm1Config/IrqStm1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm1Config/IrqStm1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM2' )"!][!//
/* STM2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2CatConfig/*))"!][!//
#define IRQ_STM2_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqStmConfig/*[1]/IrqStm2Config/IrqStm2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* STM2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm2Config/IrqStm2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'STM2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_STM2_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqStmConfig/*[1]/IrqStm2Config/IrqStm2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of STM2 interrupt Priority Setting for loop */!][!//

/* STM2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2TosConfig/*))"!][!//
#define IRQ_STM2_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqStmConfig/*[1]/IrqStm2Config/IrqStm2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqStmConfig/*[1]/IrqStm2Config/IrqStm2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqStmConfig/*[1]/IrqStm2Config/IrqStm2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "IrqDmaExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqDmaConfig/*)) = 1"!][!//
/*
                     Container : IrqDMAinterruptConfiguration
*/
[!VAR "IrqDmaExist" = "'STD_ON'"!][!//
/* DMA interrupt Category settings */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDmaConfig/*[1]/IrqDmaCatConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)])"!][!//
[!IF "not(contains($ParamName,'Ch'))"!][!//
#define IRQ_DMA_ERR_SR_CAT           (IRQ_[!"IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
[!VAR "ChNum" = "substring-after($ParamName,'IrqDmaCh')"!][!//
[!VAR "ChNum" = "substring-before($ChNum,'SRCat')"!][!//
[!IF "($ChNum <= 9)"!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_CAT      (IRQ_[!"IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_CAT     (IRQ_[!"IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* DMA interrupt Priority settings */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'DMA'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "ParamName" = "node:name(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!//
[!IF "not(contains($ParamName,'Ch'))"!][!//
#define IRQ_DMA_ERR_SR_PRIO          [!"num:inttohex(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
[!VAR "ChNum" = "substring-after($ParamName,'IrqDmaCh')"!][!//
[!VAR "ChNum" = "substring-before($ChNum,'SRPrio')"!][!//
[!IF "($ChNum <= 9)"!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_PRIO     [!"num:inttohex(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_PRIO    [!"num:inttohex(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of DMA interrupt Priority Setting for loop */!][!//

/* DMA interrupt type of service settings */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDmaConfig/*[1]/IrqDmaTosConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)])"!][!//
[!IF "not(contains($ParamName,'Ch'))"!][!//
#define IRQ_DMA_ERR_SR_TOS           (IRQ_TOS_[!"IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
[!VAR "ChNum" = "substring-after($ParamName,'IrqDmaCh')"!][!//
[!VAR "ChNum" = "substring-before($ChNum,'SRTos')"!][!//
[!IF "($ChNum <= 9)"!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_TOS      (IRQ_TOS_[!"IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_SR_TOS     (IRQ_TOS_[!"IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqDmaConfig/*[1]/IrqDmaPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqDmaConfig/*[1]/IrqDmaTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!/* Macro for Dma.Irq.c */!][!//
[!VAR "AdcCheck" = "'false'"!][!//
[!VAR "SpiCheck" = "'false'"!][!//
[!SELECT "as:modconf('Adc')[1]"!][!//
[!IF "AdcGeneral/AdcUseEmux = 'true'"!][!//
[!VAR "AdcCheck" = "'true'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!VAR "SpiCheck" = "'true'"!][!//
[!ENDIF!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 0"!][!//
[!IF "SpiSafety/SpiSafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!]
[!VAR "SpiCheck" = "'true'"!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!ENDSELECT!][!//

[!ENDIF!][!/* End of DMA interrupt Setting */!][!//


/* Macro for Dma_Irq.c*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDmaConfig/*[1]/IrqDmaCatConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqDmaConfig/*[1]/IrqDmaCatConfig/*[num:i($SrnId)])"!][!//
[!IF "not(contains($ParamName,'Ch'))"!][!//
[!ELSE!][!//
[!NOCODE!][!//
[!VAR "ChNum" = "substring-after($ParamName,'IrqDmaCh')"!][!//
[!VAR "ChNum" = "substring-before($ChNum,'SRCat')"!][!//
[!VAR "UsedResource" = "'IRQ_DMA_AVAILABLE'"!][!//
[!VAR "UsedParam" = "'255'"!][!//
[!VAR "DMAChannelId" = "'255'"!][!//
[!// Check whether the given DMA channel is used in ADC 
[!IF "$AdcCheck = 'true'"!][!//
[!SELECT "as:modconf('Adc')[1]"!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
	[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
	[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
	[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
	[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
		[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
		[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
		[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
		[!VAR "AdcEmuxScan" = "AdcGroup/*[@index = $GroupId]/AdcEmuxScanEnable"!][!//
		[!IF "($AdcEmuxScan = 'true')"!][!//
		[!ASSERT "node:refexists(./AdcDmaChannelRef) = 'true'", "DMA Channel reference not provided"!][!//
		[!VAR "DMAChannelId" = "(node:ref(./AdcDmaChannelRef)/ChannelId)"!][!//
		[!ENDIF!][!//
		[!IF "$DMAChannelId = $ChNum"!][!//
		[!VAR "UsedResource" = "'IRQ_DMA_USED_MCALADC'"!][!//
	  [!VAR "UsedParam1" = "./AdcHwUnitId"!][!//
		[!VAR "UsedParam" = "substring-after($UsedParam1,'ADC')"!]
		[!BREAK!][!//
		[!ENDIF!][!//		
		[!ENDFOR!][!//
		[!ENDSELECT!][!//
		[!IF "$DMAChannelId = $ChNum"!][!//
		[!BREAK!][!//
		[!ENDIF!][!//		
    [!ENDFOR!][!//
	[!ENDSELECT!][!//
	[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "$SpiCheck = 'true'"!][!//
	[!SELECT "as:modconf('Spi')[1]"!][!//  
	[!FOR "HwNumber" = "num:i(0)" TO "num:i(5)"!][!//
	[!VAR "SpiDmaRef" = "concat('SpiHwConfiguration/SpiHwConfigurationQspi',$HwNumber)"!][!//  
	[!VAR "DmaTxNode" = "concat($SpiDmaRef,'/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef')"!][!//
	[!VAR "DmaRxNode" = "concat($SpiDmaRef,'/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef')"!][!//
    [!IF "node:exists($DmaTxNode) = 'true'"!][!//
    [!IF "node:refexists(node:ref($DmaTxNode)) = 'true'"!][!//
	[!VAR "DmaChTxNum" = "node:ref(node:ref($DmaTxNode))/ChannelId"!][!//
	 [!IF "$DmaChTxNum = $ChNum"!][!//
	  [!VAR "UsedResource" = "'IRQ_DMA_USED_MCALSPI_TX'"!][!//
	  [!VAR "UsedParam" = "num:i($HwNumber)"!][!//
	  [!ENDIF!][!//
	[!ENDIF!]
	[!ENDIF!]
    [!IF "node:exists($DmaRxNode) = 'true'"!][!//
	[!IF "node:refexists(node:ref($DmaRxNode)) = 'true'"!][!//
	[!VAR "DmaChRxNum" = "node:ref(node:ref($DmaRxNode))/ChannelId"!][!//
	  [!IF "$DmaChRxNum = $ChNum"!][!//
	  [!VAR "UsedResource" = "'IRQ_DMA_USED_MCALSPI_RX'"!][!//
	  [!VAR "UsedParam" = "num:i($HwNumber)"!][!//
	  [!ENDIF!][!//
	[!ENDIF!][!//
	[!ENDIF!][!//	
	[!ENDFOR!][!//
	[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($ChNum <= 9)"!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_USED        ([!"$UsedResource"!])[!CR!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_PARAM       ([!"$UsedParam"!]U)[!CR!][!//
[!ELSE!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_USED       ([!"$UsedResource"!])[!CR!][!//
#define IRQ_DMA_CHANNEL[!"num:i($ChNum)"!]_PARAM      ([!"$UsedParam"!]U)[!CR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* Macro for AscLin_Irq.c*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqAscLinConfig/*[1]/IrqAscLinCatConfig/IrqAscLinErrCatConfig/*[num:i($SrnId)])"!][!//
[!NOCODE!][!//
[!VAR "ChNum" = "substring-after($ParamName,'IrqAscLin')"!][!//
[!VAR "ChNum" = "substring-before($ChNum,'ErrorCat')"!][!//
[!VAR "UsedResource" = "'IRQ_ASCLIN_AVAILABLE'"!][!//
[!// Check whether the given ASCLIN channel is used in LIN 
[!SELECT "as:modconf('Lin')[1]"!][!//
[!VAR "TotalLinConfig" = "num:i(count(LinGlobalConfig/*))"!][!//
	[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalLinConfig)"!][!//
	[!SELECT "LinGlobalConfig/*[num:i($CfgCount)]"!][!//
	[!VAR "TotalLinUnit" = "num:i(count(LinChannel/*))"!][!//
	[!FOR "LinId" ="num:i(1)" TO "num:i($TotalLinUnit)"!][!//
		[!SELECT "LinChannel/*[num:i($LinId)]"!][!//
		[!VAR "LinHwChan"= "./LinChanAssignedHw"!][!//
    [!VAR "CurChNum" = "substring-after($LinHwChan,'ASCLIN')"!][!//
		[!IF "$CurChNum = $ChNum"!][!//
		[!VAR "UsedResource" = "'IRQ_ASCLIN_USED_MCALLIN'"!][!//
		[!BREAK!][!//
		[!ENDIF!][!//		
		[!ENDSELECT!][!//
    [!ENDFOR!][!//
	[!ENDSELECT!][!//
	[!ENDFOR!][!//
[!ENDSELECT!][!//
[!// Check whether the given ASCLIN channel is used in UART 
[!SELECT "as:modconf('Uart')[1]"!][!//
[!VAR "TotalUartConfig" = "num:i(count(UartConfigSet/*))"!][!//
	[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalUartConfig)"!][!//
	[!SELECT "UartConfigSet/*[num:i($CfgCount)]"!][!//
	[!VAR "TotalUartUnit" = "num:i(count(UartChannel/*))"!][!//
	[!FOR "UartId" ="num:i(1)" TO "num:i($TotalUartUnit)"!][!//
		[!SELECT "UartChannel/*[num:i($UartId)]"!][!//
		[!VAR "UartHwChan"= "./UartHwUnit"!][!//
    [!VAR "CurChNum" = "substring-after($UartHwChan,'ASCLIN')"!][!//
		[!IF "$CurChNum = $ChNum"!][!//
		[!VAR "UsedResource" = "'IRQ_ASCLIN_USED_MCALUART'"!][!//
		[!BREAK!][!//
		[!ENDIF!][!//		
		[!ENDSELECT!][!//
    [!ENDFOR!][!//
	[!ENDSELECT!][!//
	[!ENDFOR!][!//
[!ENDSELECT!][!//
[!// Check whether the given ASCLIN channel is used in STDLIN 
[!SELECT "as:modconf('StdLin')[1]"!][!//
[!VAR "TotalStdLinConfig" = "num:i(count(StdLinConfigSet/*))"!][!//
	[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalStdLinConfig)"!][!//
	[!SELECT "StdLinConfigSet/*[num:i($CfgCount)]"!][!//
	[!VAR "TotalStdLinUnit" = "num:i(count(StdLinChannel/*))"!][!//
	[!FOR "StdLinId" ="num:i(1)" TO "num:i($TotalStdLinUnit)"!][!//
		[!SELECT "StdLinChannel/*[num:i($StdLinId)]"!][!//
		[!VAR "StdLinHwChan"= "./StdLinHwUnit"!][!//
    [!VAR "CurChNum" = "substring-after($StdLinHwChan,'ASCLIN')"!][!//
		[!IF "$CurChNum = $ChNum"!][!//
		[!ASSERT "$UsedResource = 'IRQ_ASCLIN_AVAILABLE'", "CONFIG ERROR: ASCLIN channel is used by  STDLIN and LIN/UART"!][!//
		[!VAR "UsedResource" = "'IRQ_ASCLIN_USED_MCALSTDLIN'"!][!//
		[!BREAK!][!//
		[!ENDIF!][!//		
		[!ENDSELECT!][!//
    [!ENDFOR!][!//
	[!ENDSELECT!][!//
	[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
#define IRQ_ASCLIN_CHANNEL[!"num:i($ChNum)"!]_USED      ([!"$UsedResource"!])[!CR!][!//
[!ENDFOR!][!//



[!VAR "IrqETHExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqETHConfig/*)) = 1"!][!//
/*
                     Container : Ethernet interrupt Configuration
*/
[!NOCODE!][!//
[!VAR "IrqETHExist" = "'STD_ON'"!][!//	
[!ENDNOCODE!][!//
/* Ethernet interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqETHConfig/*[1]/IrqETHCatConfig/*))"!][!//
#define IRQ_ETH_SR_CAT              (IRQ_[!"IrqETHConfig/*[1]/IrqETHCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* Ethernet interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqETHConfig/*[1]/IrqETHPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqETHConfig/*[1]/IrqETHPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqETHConfig/*[1]/IrqETHTosConfig/*[num:i($SrnId)]"!][!//
[!NOCODE!][!//
[!VAR "cont" = "'ETH'"!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ETH_SR_PRIO             [!"num:inttohex(IrqETHConfig/*[1]/IrqETHPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqETHConfig/*[1]/IrqETHPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqETHConfig/*[1]/IrqETHCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of Ethernet interrupt Priority Setting for loop */!][!//

/* Ethernet interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqETHConfig/*[1]/IrqETHTosConfig/*))"!][!//
#define IRQ_ETH_SR_TOS              (IRQ_TOS_[!"IrqETHConfig/*[1]/IrqETHTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqETHConfig/*[1]/IrqETHPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqETHConfig/*[1]/IrqETHTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "num:i(count(IrqCanConfig/*)) = 1"!][!//
/*
                     Container : IrqCaninterruptConfiguration
*/
/* CAN interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCanConfig/*[1]/IrqCanCatConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqCanConfig/*[1]/IrqCanCatConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqCanSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Cat')"!][!//
[!IF "($SrNum <= 9)"!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_CAT             (IRQ_[!"IrqCanConfig/*[1]/IrqCanCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_CAT            (IRQ_[!"IrqCanConfig/*[1]/IrqCanCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/*  CAN interrupt Priority setting  */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCanConfig/*[1]/IrqCanPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCanConfig/*[1]/IrqCanTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'CAN'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!// 
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "ParamName" = "node:name(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqCanSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Prio')"!][!//
[!IF "($SrNum <= 9)"!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_PRIO            [!"num:inttohex(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_PRIO           [!"num:inttohex(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!//    
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqCanConfig/*[1]/IrqCanCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//[!/* End of CAN interrupt Priority Setting for loop */!]

/* CAN interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqCanConfig/*[1]/IrqCanTosConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqCanConfig/*[1]/IrqCanTosConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqCanSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Tos')"!][!//
[!IF "($SrNum <= 9)"!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_TOS             (IRQ_TOS_[!"IrqCanConfig/*[1]/IrqCanTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_CAN_SR[!"num:i($SrNum)"!]_TOS            (IRQ_TOS_[!"IrqCanConfig/*[1]/IrqCanTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqCanConfig/*[1]/IrqCanPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqCanConfig/*[1]/IrqCanTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//


[!IF "num:i(count(IrqHSMConfig/*)) = 1"!][!//
/*
                     Container : IrqHSMinterruptConfiguration
*/
/* HSM interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHSMConfig/*[1]/IrqHSMCatConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqHSMConfig/*[1]/IrqHSMCatConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqHSMSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Cat')"!][!//
#define IRQ_HSM_SR[!"num:i($SrNum)"!]_CAT             (IRQ_[!"IrqHSMConfig/*[1]/IrqHSMCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*  HSM interrupt Priority setting  */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHSMConfig/*[1]/IrqHSMTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'HSM'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!// 
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "ParamName" = "node:name(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqHSMSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Prio')"!][!//
#define IRQ_HSM_SR[!"num:i($SrNum)"!]_PRIO            [!"num:inttohex(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*[num:i($SrnId)])"!][!//    
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHSMConfig/*[1]/IrqHSMCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//[!/* End of HSM interrupt Priority Setting for loop */!]

/* HSM interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHSMConfig/*[1]/IrqHSMTosConfig/*))"!][!//
[!VAR "ParamName" = "node:name(IrqHSMConfig/*[1]/IrqHSMTosConfig/*[num:i($SrnId)])"!][!//
[!VAR "SrNum" = "substring-after($ParamName,'IrqHSMSR')"!][!//
[!VAR "SrNum" = "substring-before($SrNum,'Tos')"!][!//
#define IRQ_HSM_SR[!"num:i($SrNum)"!]_TOS             (IRQ_TOS_[!"IrqHSMConfig/*[1]/IrqHSMTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHSMConfig/*[1]/IrqHSMPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHSMConfig/*[1]/IrqHSMTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!//  ADC configuration
[!VAR "IrqAdcExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqAdcConfig/*)) = 1"!][!//
/* Mcaro to identify SHS ADC or SAR ADC */
[!IF "ecu:get('Adc.StartUpCal') = 'HW_CAL'"!][!//
#define IRQ_ADC_CG0SR0_USED_FOR_BGNDRS   (STD_ON)
[!ELSE!][!//
#define IRQ_ADC_CG0SR0_USED_FOR_BGNDRS   (STD_OFF)
[!ENDIF!][!//
/*
                     Container : Irq ADC configuration
*/
[!VAR "IrqAdcExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC0' )"!][!//
/*ADC0 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0CatConfig/*))"!][!//
#define IRQ_ADC0_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC0 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC0_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC0 interrupt Priority Setting for loop */!][!//

/*ADC0 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0TosConfig/*))"!][!//
#define IRQ_ADC0_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc0Config/IrqAdc0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC1' )"!][!//
/*ADC1 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1CatConfig/*))"!][!//
#define IRQ_ADC1_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC1 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC1_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC1 interrupt Priority Setting for loop */!][!//

/*ADC1 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1TosConfig/*))"!][!//
#define IRQ_ADC1_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc1Config/IrqAdc1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC2' )"!][!//
/*ADC2 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2CatConfig/*))"!][!//
#define IRQ_ADC2_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC2 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC2_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC2 interrupt Priority Setting for loop */!][!//

/*ADC2 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2TosConfig/*))"!][!//
#define IRQ_ADC2_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc2Config/IrqAdc2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC3' )"!][!//
/*ADC3 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3CatConfig/*))"!][!//
#define IRQ_ADC3_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC3 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC3'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC3_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC3 interrupt Priority Setting for loop */!][!//

/*ADC3 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3TosConfig/*))"!][!//
#define IRQ_ADC3_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc3Config/IrqAdc3TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC4' )"!][!//
/*ADC4 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4CatConfig/*))"!][!//
#define IRQ_ADC4_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC4 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC4'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC4_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC4 interrupt Priority Setting for loop */!][!//

/*ADC4 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4TosConfig/*))"!][!//
#define IRQ_ADC4_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc4Config/IrqAdc4TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC5' )"!][!//
/*ADC5 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5CatConfig/*))"!][!//
#define IRQ_ADC5_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC5 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC5'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC5_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC5 interrupt Priority Setting for loop */!][!//

/*ADC5 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5TosConfig/*))"!][!//
#define IRQ_ADC5_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc5Config/IrqAdc5TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC6' )"!][!//
/*ADC6 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6CatConfig/*))"!][!//
#define IRQ_ADC6_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC6 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC6'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC6_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC6 interrupt Priority Setting for loop */!][!//

/*ADC6 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6TosConfig/*))"!][!//
#define IRQ_ADC6_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc6Config/IrqAdc6TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC7' )"!][!//
/*ADC7 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7CatConfig/*))"!][!//
#define IRQ_ADC7_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC7 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC7'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC7_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC7 interrupt Priority Setting for loop */!][!//

/*ADC7 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7TosConfig/*))"!][!//
#define IRQ_ADC7_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc7Config/IrqAdc7TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC8' )"!][!//
/*ADC8 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8CatConfig/*))"!][!//
#define IRQ_ADC8_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC8 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC8'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC8_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC8 interrupt Priority Setting for loop */!][!//

/*ADC8 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8TosConfig/*))"!][!//
#define IRQ_ADC8_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc8Config/IrqAdc8TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC9' )"!][!//
/*ADC9 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9CatConfig/*))"!][!//
#define IRQ_ADC9_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC9 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC9'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC9_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC9 interrupt Priority Setting for loop */!][!//

/*ADC9 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9TosConfig/*))"!][!//
#define IRQ_ADC9_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc9Config/IrqAdc9TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC10' )"!][!//
/*ADC10 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10CatConfig/*))"!][!//
#define IRQ_ADC10_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC10 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADC10'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADC10_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC10 interrupt Priority Setting for loop */!][!//

/*ADC10 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10TosConfig/*))"!][!//
#define IRQ_ADC10_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdc10Config/IrqAdc10TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADCCG0' )"!][!//
/*ADC CG0 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0CatConfig/*))"!][!//
#define IRQ_ADCCG0_SR[!"num:i($SrnId - 1)"!]_CAT          (IRQ_[!"IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC CG0 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADCCG0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADCCG0_SR[!"num:i($SrnId - 1)"!]_PRIO         [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC CG0 interrupt Priority Setting for loop */!][!//

/*ADC CG0 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0TosConfig/*))"!][!//
#define IRQ_ADCCG0_SR[!"num:i($SrnId - 1)"!]_TOS          (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdcCG0Config/IrqAdcCG0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADCCG1' )"!][!//
/*ADC CG1 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1CatConfig/*))"!][!//
#define IRQ_ADCCG1_SR[!"num:i($SrnId - 1)"!]_CAT          (IRQ_[!"IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/*ADC CG1 interrupt Priority setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'ADCCG1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_ADCCG1_SR[!"num:i($SrnId - 1)"!]_PRIO         [!"num:inttohex(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of ADC CG1 interrupt Priority Setting for loop */!][!//

/*ADC CG1 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1TosConfig/*))"!][!//
#define IRQ_ADCCG1_SR[!"num:i($SrnId - 1)"!]_TOS          (IRQ_TOS_[!"IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqAdcConfig/*[1]/IrqAdcCG1Config/IrqAdcCG1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "IrqDSAdcExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqDSAdcConfig/*)) = 1"!][!//
/*
                     Container : IrqDSADCinterruptConfiguration
*/
[!VAR "IrqDSAdcExist" = "'STD_ON'"!][!//
/*DSADC interrupt Category setting */
[!VAR "DsAdcId" = "num:i(1)"!][!//
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDSAdcConfig/*[1]/IrqDSAdcCatConfig/*))"!][!//
[!VAR "DsAdcModId" = "num:i(num:div(num:i($SrnId - 1),num:i(2)))"!][!//
[!IF "(num:mod(num:i($SrnId - 1),num:i(2)) = num:i(0))"!][!//
[!IF "not(contains( ecu:get('Irq.DSAdcSrnAvailable'), concat('IrqDSAdcSrM', $DsAdcModId)))"!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(2)"!][!//
[!ENDIF!][!//
#define IRQ_DSADC_SRM[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_CAT          (IRQ_[!"IrqDSAdcConfig/*[1]/IrqDSAdcCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_DSADC_SRA[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_CAT          (IRQ_[!"IrqDSAdcConfig/*[1]/IrqDSAdcCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(1)"!][!//
[!ENDFOR!][!//

/*DSADC interrupt Priority setting */
[!VAR "DsAdcId" = "num:i(1)"!][!//
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqDSAdcConfig/*[1]/IrqDSAdcTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'DSADC'"!][!//
[!VAR "DsAdcModId" = "num:i(num:div(num:i($SrnId - 1),num:i(2)))"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "(num:mod(num:i($SrnId - 1),num:i(2)) = num:i(0))"!][!//
[!IF "not(contains( ecu:get('Irq.DSAdcSrnAvailable'), concat('IrqDSAdcSrM', $DsAdcModId)))"!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(2)"!][!//
[!ENDIF!][!//
#define IRQ_DSADC_SRM[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_PRIO          [!"num:inttohex(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_DSADC_SRA[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_PRIO          [!"num:inttohex(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(1)"!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqDSAdcConfig/*[1]/IrqDSAdcCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of DSADC interrupt Priority Setting for loop */!][!//

/*DSADC interrupt type of service setting */
[!VAR "DsAdcId" = "num:i(1)"!][!//
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqDSAdcConfig/*[1]/IrqDSAdcTosConfig/*))"!][!//
[!VAR "DsAdcModId" = "num:i(num:div(num:i($SrnId - 1),num:i(2)))"!][!//
[!IF "(num:mod(num:i($SrnId - 1),num:i(2)) = num:i(0))"!][!//
[!IF "not(contains( ecu:get('Irq.DSAdcSrnAvailable'), concat('IrqDSAdcSrM', $DsAdcModId)))"!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(2)"!][!//
[!ENDIF!][!//
#define IRQ_DSADC_SRM[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_TOS           (IRQ_TOS_[!"IrqDSAdcConfig/*[1]/IrqDSAdcTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_DSADC_SRA[!"num:i(num:div(num:i($DsAdcId - 1),num:i(2)))"!]_TOS           (IRQ_TOS_[!"IrqDSAdcConfig/*[1]/IrqDSAdcTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!VAR "DsAdcId" = "num:i($DsAdcId) + num:i(1)"!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqDSAdcConfig/*[1]/IrqDSAdcPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqDSAdcConfig/*[1]/IrqDSAdcTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqFlexRayExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqFlexRayConfig/*)) = 1"!][!//
/*
                     Container : IrqFLEXRAYinterruptConfiguration
*/
[!VAR "IrqFlexRayExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.FlexRayAvailable'), 'IrqFlexRay0' )"!][!//
/* FLEXRAY0 interrupt Category Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*))"!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY0_SR[!"num:i($SrnId - 1)"!]_CAT         (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY0_TIMER_INT[!"num:i($SrnId - 3)"!]_CAT  (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY0_NEW_DATA[!"num:i($SrnId - 5)"!]_CAT   (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY0_MBSC[!"num:i($SrnId - 7)"!]_CAT       (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY0_OB_BUSY_CAT     (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY0_IB_BUSY_CAT     (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* FLEXRAY0 interrupt Priority Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'FLEXRAY0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY0_SR[!"num:i($SrnId - 1)"!]_PRIO        [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY0_TIMER_INT[!"num:i($SrnId - 3)"!]_PRIO [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY0_NEW_DATA[!"num:i($SrnId - 5)"!]_PRIO  [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY0_MBSC[!"num:i($SrnId - 7)"!]_PRIO      [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY0_OB_BUSY_PRIO    [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY0_IB_BUSY_PRIO    [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of FlexRay0 interrupt Priority Setting for loop */!][!//

/* FLEXRAY0 interrupt type of service Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*))"!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY0_SR[!"num:i($SrnId - 1)"!]_TOS         (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY0_TIMER_INT[!"num:i($SrnId - 3)"!]_TOS  (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY0_NEW_DATA[!"num:i($SrnId - 5)"!]_TOS   (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY0_MBSC[!"num:i($SrnId - 7)"!]_TOS       (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY0_OB_BUSY_TOS     (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY0_IB_BUSY_TOS     (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqFlexRayConfig/*[1]/IrqFlexRay0Config/IrqFlexRay0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.FlexRayAvailable'), 'IrqFlexRay1' )"!][!//
/* FLEXRAY1 interrupt Category Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*))"!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY1_SR[!"num:i($SrnId - 1)"!]_CAT         (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY1_TIMER_INT[!"num:i($SrnId - 3)"!]_CAT  (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY1_NEW_DATA[!"num:i($SrnId - 5)"!]_CAT   (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY1_MBSC[!"num:i($SrnId - 7)"!]_CAT       (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY1_OB_BUSY_CAT     (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY1_IB_BUSY_CAT     (IRQ_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* FLEXRAY1 interrupt Priority Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'FLEXRAY1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY1_SR[!"num:i($SrnId - 1)"!]_PRIO        [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY1_TIMER_INT[!"num:i($SrnId - 3)"!]_PRIO [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY1_NEW_DATA[!"num:i($SrnId - 5)"!]_PRIO  [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY1_MBSC[!"num:i($SrnId - 7)"!]_PRIO      [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY1_OB_BUSY_PRIO    [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY1_IB_BUSY_PRIO    [!"num:inttohex(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of FlexRay1 interrupt Priority Setting for loop */!][!//

/* FLEXRAY1 interrupt type of service Setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*))"!][!//
[!IF "($SrnId <= 2)"!][!//
#define IRQ_FLEXRAY1_SR[!"num:i($SrnId - 1)"!]_TOS         (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 4)"!][!//
#define IRQ_FLEXRAY1_TIMER_INT[!"num:i($SrnId - 3)"!]_TOS  (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 6)"!][!//
#define IRQ_FLEXRAY1_NEW_DATA[!"num:i($SrnId - 5)"!]_TOS   (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 8)"!][!//
#define IRQ_FLEXRAY1_MBSC[!"num:i($SrnId - 7)"!]_TOS       (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId <= 9)"!][!//
#define IRQ_FLEXRAY1_OB_BUSY_TOS     (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_FLEXRAY1_IB_BUSY_TOS     (IRQ_TOS_[!"IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqFlexRayConfig/*[1]/IrqFlexRay1Config/IrqFlexRay1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!//
[!ENDIF!][!//

/*
                     Container : PMU0 interrupt Configuration
*/
/* PMU0 interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqPMU0Config/*[1]/IrqPMU0CatConfig/*))"!][!//
#define IRQ_PMU0_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqPMU0Config/*[1]/IrqPMU0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//

/* PMU0 interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqPMU0Config/*[1]/IrqPMU0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqPMU0Config/*[1]/IrqPMU0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqPMU0Config/*[1]/IrqPMU0TosConfig/*[num:i($SrnId)]"!][!//
[!NOCODE!][!//
[!VAR "cont" = "'PMU0'"!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_PMU0_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqPMU0Config/*[1]/IrqPMU0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqPMU0Config/*[1]/IrqPMU0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqPMU0Config/*[1]/IrqPMU0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of PMU0 interrupt Priority Setting for loop */!][!//

/* PMU0 interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqPMU0Config/*[1]/IrqPMU0TosConfig/*))"!][!//
#define IRQ_PMU0_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqPMU0Config/*[1]/IrqPMU0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqPMU0Config/*[1]/IrqPMU0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqPMU0Config/*[1]/IrqPMU0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

[!NOCODE!][!//
[!VAR "IrqScuExist" = "'STD_OFF'"!][!//
[!ENDNOCODE!][!//
[!IF "num:i(count(IrqScuConfig/*)) = 1"!][!//
/*
                     Container : Scu interrupt Configuration
*/
[!NOCODE!][!//
[!VAR "IrqScuExist" = "'STD_ON'"!][!//	
[!ENDNOCODE!][!//
/* Scu interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqScuConfig/*[1]/IrqScuCatConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_SCU_DTS_BUSY_SR_CAT     (IRQ_[!"IrqScuConfig/*[1]/IrqScuCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_SCU_ERU_SR[!"num:i($SrnId - 2)"!]_CAT         (IRQ_[!"IrqScuConfig/*[1]/IrqScuCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* Scu interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqScuConfig/*[1]/IrqScuPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqScuConfig/*[1]/IrqScuPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqScuConfig/*[1]/IrqScuTosConfig/*[num:i($SrnId)]"!][!//
[!NOCODE!][!//
[!VAR "cont" = "'SCU'"!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_SCU_DTS_BUSY_SR_PRIO    [!"num:inttohex(IrqScuConfig/*[1]/IrqScuPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_SCU_ERU_SR[!"num:i($SrnId - 2)"!]_PRIO        [!"num:inttohex(IrqScuConfig/*[1]/IrqScuPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqScuConfig/*[1]/IrqScuPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqScuConfig/*[1]/IrqScuCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of Scu interrupt Priority Setting for loop */!][!//

/* Scu interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqScuConfig/*[1]/IrqScuTosConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_SCU_DTS_BUSY_SR_TOS     (IRQ_TOS_[!"IrqScuConfig/*[1]/IrqScuTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_SCU_ERU_SR[!"num:i($SrnId - 2)"!]_TOS         (IRQ_TOS_[!"IrqScuConfig/*[1]/IrqScuTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqScuConfig/*[1]/IrqScuPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqScuConfig/*[1]/IrqScuTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqGPSRGroupExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqGPSRGroupConfig/*)) = 1"!][!//
/*
                     Container : IrqGPSRGroupinterruptConfiguration
*/
[!VAR "IrqGPSRGroupExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr0' )"!][!//
/* GPSRGROUP0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0CatConfig/*))"!][!//
#define IRQ_GPSRGROUP0_SR[!"num:i($SrnId - 1)"!]_CAT      (IRQ_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GPSRGROUP0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GPSRGROUP0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GPSRGROUP0_SR[!"num:i($SrnId - 1)"!]_PRIO     [!"num:inttohex(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GPSRGROUP0 interrupt Priority Setting for loop */!][!//

/* GPSRGROUP0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0TosConfig/*))"!][!//
#define IRQ_GPSRGROUP0_SR[!"num:i($SrnId - 1)"!]_TOS      (IRQ_TOS_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup0Config/IrqGPSRGroup0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr1' )"!][!//
/* GPSRGROUP1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1CatConfig/*))"!][!//
#define IRQ_GPSRGROUP1_SR[!"num:i($SrnId - 1)"!]_CAT      (IRQ_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GPSRGROUP1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GPSRGROUP1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GPSRGROUP1_SR[!"num:i($SrnId - 1)"!]_PRIO     [!"num:inttohex(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GPSRGROUP1 interrupt Priority Setting for loop */!][!//

/* GPSRGROUP1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1TosConfig/*))"!][!//
#define IRQ_GPSRGROUP1_SR[!"num:i($SrnId - 1)"!]_TOS      (IRQ_TOS_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup1Config/IrqGPSRGroup1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr2' )"!][!//
/* GPSRGROUP2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2CatConfig/*))"!][!//
#define IRQ_GPSRGROUP2_SR[!"num:i($SrnId - 1)"!]_CAT      (IRQ_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GPSRGROUP2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GPSRGROUP2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GPSRGROUP2_SR[!"num:i($SrnId - 1)"!]_PRIO     [!"num:inttohex(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GPSRGROUP2 interrupt Priority Setting for loop */!][!//

/* GPSRGROUP2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2TosConfig/*))"!][!//
#define IRQ_GPSRGROUP2_SR[!"num:i($SrnId - 1)"!]_TOS      (IRQ_TOS_[!"IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGPSRGroupConfig/*[1]/IrqGPSRGroup2Config/IrqGPSRGroup2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!VAR "IrqGtmExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqGtmConfig/*)) = 1"!][!//
/*
                     Container : Irq GTM interruptConfiguration
*/
[!VAR "IrqGtmExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAei' )"!][!//
/* GTM AEI interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEICatConfig/*))"!][!//
#define IRQ_GTM_AEI_CAT             (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEICatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM AEI interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEIPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEIPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEITosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMAEI'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_AEI_PRIO            [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEIPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEIPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEICatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM AEI interrupt Priority Setting for loop */!][!//

/* GTM AEI interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEITosConfig/*))"!][!//
#define IRQ_GTM_AEI_TOS             (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEITosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEIPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmAEIConfig/IrqGtmAEITosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAru' )"!][!//
/* GTM ARU interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUCatConfig/*))"!][!//
#define IRQ_GTM_ARU_SR[!"num:i($SrnId - 1)"!]_CAT         (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ARU interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMARU'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ARU_SR[!"num:i($SrnId - 1)"!]_PRIO        [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ARU interrupt Priority Setting for loop */!][!//

/* GTM ARU interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUTosConfig/*))"!][!//
#define IRQ_GTM_ARU_SR[!"num:i($SrnId - 1)"!]_TOS         (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmARUConfig/IrqGtmARUTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
                                                                                                           
[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmBrc' )"!][!//
/* GTM BRC interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCCatConfig/*))"!][!//
#define IRQ_GTM_BRC_CAT             (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM BRC interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMBRC'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_BRC_PRIO            [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM BRC interrupt Priority Setting for loop */!][!//

/* GTM BRC interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCTosConfig/*))"!][!//
#define IRQ_GTM_BRC_TOS             (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmBRCConfig/IrqGtmBRCTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmCmp' )"!][!//
/* GTM CMP interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPCatConfig/*))"!][!//
#define IRQ_GTM_CMP_CAT             (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM CMP interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMCMP'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_CMP_PRIO            [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM CMP interrupt Priority Setting for loop */!][!//

/* GTM CMP interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPTosConfig/*))"!][!//
#define IRQ_GTM_CMP_TOS             (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmCMPConfig/IrqGtmCMPTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmSpe' )"!][!//
/* GTM SPE interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPECatConfig/*))"!][!//
#define IRQ_GTM_SPE[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPECatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM SPE interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPEPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPEPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPETosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMSPE'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_SPE[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPEPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPEPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPECatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM SPE interrupt Priority Setting for loop */!][!//

/* GTM SPE interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPETosConfig/*))"!][!//
#define IRQ_GTM_SPE[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPETosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPEPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmSPEConfig/IrqGtmSPETosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmPsm0' )"!][!//
/* GTM PSM0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0CatConfig/*))"!][!//
#define IRQ_GTM_PSM0_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM PSM0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMPSM0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_PSM0_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM PSM0 interrupt Priority Setting for loop */!][!//

/* GTM PSM0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0TosConfig/*))"!][!//
#define IRQ_GTM_PSM0_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmPSM0Config/IrqGtmPSM0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmPsm1' )"!][!//
/* GTM PSM1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1CatConfig/*))"!][!//
#define IRQ_GTM_PSM1_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM PSM1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMPSM1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_PSM1_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM PSM1 interrupt Priority Setting for loop */!][!//

/* GTM PSM1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1TosConfig/*))"!][!//
#define IRQ_GTM_PSM1_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmPSM1Config/IrqGtmPSM1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmDpll' )"!][!//
/* GTM DPLL interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM DPLL interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMDPLL'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM DPLL interrupt Priority Setting for loop */!][!//

/* GTM DPLL interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_GTM_DPLL_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmDPLLConfig/IrqGtmDPLLTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmErr' )"!][!//
/* GTM ERR interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRCatConfig/*))"!][!//
#define IRQ_GTM_ERR_SR_CAT          (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ERR interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMERR'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ERR_SR_PRIO         [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ERR interrupt Priority Setting for loop */!][!//

/* GTM ERR interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRTosConfig/*))"!][!//
#define IRQ_GTM_ERR_SR_TOS          (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmERRConfig/IrqGtmERRTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim0' )"!][!//
/* GTM TIM0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0CatConfig/*))"!][!//
#define IRQ_GTM_TIM0_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM0_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM0 interrupt Priority Setting for loop */!][!//

/* GTM TIM0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0TosConfig/*))"!][!//
#define IRQ_GTM_TIM0_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM0Config/IrqGtmTIM0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim1' )"!][!//
/* GTM TIM1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1CatConfig/*))"!][!//
#define IRQ_GTM_TIM1_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM1_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM1 interrupt Priority Setting for loop */!][!//

/* GTM TIM1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1TosConfig/*))"!][!//
#define IRQ_GTM_TIM1_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM1Config/IrqGtmTIM1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim2' )"!][!//
/* GTM TIM2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2CatConfig/*))"!][!//
#define IRQ_GTM_TIM2_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM2_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM2 interrupt Priority Setting for loop */!][!//

/* GTM TIM2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2TosConfig/*))"!][!//
#define IRQ_GTM_TIM2_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM2Config/IrqGtmTIM2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim3' )"!][!//
/* GTM TIM3 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3CatConfig/*))"!][!//
#define IRQ_GTM_TIM3_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM3 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM3'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM3_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM3 interrupt Priority Setting for loop */!][!//

/* GTM TIM3 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3TosConfig/*))"!][!//
#define IRQ_GTM_TIM3_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM3Config/IrqGtmTIM3TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim4' )"!][!//
/* GTM TIM4 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4CatConfig/*))"!][!//
#define IRQ_GTM_TIM4_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM4 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM4'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM4_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM4 interrupt Priority Setting for loop */!][!//

/* GTM TIM4 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4TosConfig/*))"!][!//
#define IRQ_GTM_TIM4_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM4Config/IrqGtmTIM4TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim5' )"!][!//
/* GTM TIM5 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5CatConfig/*))"!][!//
#define IRQ_GTM_TIM5_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TIM5 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTIM5'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TIM5_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TIM5 interrupt Priority Setting for loop */!][!//

/* GTM TIM5 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5TosConfig/*))"!][!//
#define IRQ_GTM_TIM5_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTIM5Config/IrqGtmTIM5TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs0' )"!][!//
/* GTM MCS0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0CatConfig/*))"!][!//
#define IRQ_GTM_MCS0_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS0_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS0 interrupt Priority Setting for loop */!][!//

/* GTM MCS0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0TosConfig/*))"!][!//
#define IRQ_GTM_MCS0_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS0Config/IrqGtmMCS0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs1' )"!][!//
/* GTM MCS1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1CatConfig/*))"!][!//
#define IRQ_GTM_MCS1_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS1_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS1 interrupt Priority Setting for loop */!][!//

/* GTM MCS1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1TosConfig/*))"!][!//
#define IRQ_GTM_MCS1_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS1Config/IrqGtmMCS1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs2' )"!][!//
/* GTM MCS2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2CatConfig/*))"!][!//
#define IRQ_GTM_MCS2_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS2_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS2 interrupt Priority Setting for loop */!][!//

/* GTM MCS2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2TosConfig/*))"!][!//
#define IRQ_GTM_MCS2_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS2Config/IrqGtmMCS2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs3' )"!][!//
/* GTM MCS3 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3CatConfig/*))"!][!//
#define IRQ_GTM_MCS3_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS3 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS3'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS3_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS3 interrupt Priority Setting for loop */!][!//

/* GTM MCS3 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3TosConfig/*))"!][!//
#define IRQ_GTM_MCS3_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS3Config/IrqGtmMCS3TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs4' )"!][!//
/* GTM MCS4 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4CatConfig/*))"!][!//
#define IRQ_GTM_MCS4_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS4 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS4'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS4_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS4 interrupt Priority Setting for loop */!][!//

/* GTM MCS4 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4TosConfig/*))"!][!//
#define IRQ_GTM_MCS4_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS4Config/IrqGtmMCS4TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs5' )"!][!//
/* GTM MCS5 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5CatConfig/*))"!][!//
#define IRQ_GTM_MCS5_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM MCS5 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMMCS5'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_MCS5_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM MCS5 interrupt Priority Setting for loop */!][!//

/* GTM MCS5 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5TosConfig/*))"!][!//
#define IRQ_GTM_MCS5_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmMCS5Config/IrqGtmMCS5TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom0' )"!][!//
/* GTM TOM0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0CatConfig/*))"!][!//
#define IRQ_GTM_TOM0_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TOM0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTOM0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TOM0_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TOM0 interrupt Priority Setting for loop */!][!//

/* GTM TOM0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0TosConfig/*))"!][!//
#define IRQ_GTM_TOM0_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM0Config/IrqGtmTOM0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom1' )"!][!//
/* GTM TOM1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1CatConfig/*))"!][!//
#define IRQ_GTM_TOM1_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TOM1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTOM1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TOM1_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TOM1 interrupt Priority Setting for loop */!][!//

/* GTM TOM1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1TosConfig/*))"!][!//
#define IRQ_GTM_TOM1_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM1Config/IrqGtmTOM1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom2' )"!][!//
/* GTM TOM2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2CatConfig/*))"!][!//
#define IRQ_GTM_TOM2_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TOM2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTOM2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TOM2_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TOM2 interrupt Priority Setting for loop */!][!//

/* GTM TOM2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2TosConfig/*))"!][!//
#define IRQ_GTM_TOM2_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM2Config/IrqGtmTOM2TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom3' )"!][!//
/* GTM TOM3 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3CatConfig/*))"!][!//
#define IRQ_GTM_TOM3_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TOM3 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTOM3'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TOM3_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TOM3 interrupt Priority Setting for loop */!][!//

/* GTM TOM3 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3TosConfig/*))"!][!//
#define IRQ_GTM_TOM3_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM3Config/IrqGtmTOM3TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom4' )"!][!//
/* GTM TOM4 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4CatConfig/*))"!][!//
#define IRQ_GTM_TOM4_SR[!"num:i($SrnId - 1)"!]_CAT        (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM TOM4 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMTOM4'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_TOM4_SR[!"num:i($SrnId - 1)"!]_PRIO       [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM TOM4 interrupt Priority Setting for loop */!][!//

/* GTM TOM4 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4TosConfig/*))"!][!//
#define IRQ_GTM_TOM4_SR[!"num:i($SrnId - 1)"!]_TOS        (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmTOM4Config/IrqGtmTOM4TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom0' )"!][!//
/* GTM ATOM0 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0CatConfig/*))"!][!//
#define IRQ_GTM_ATOM0_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM0 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM0_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM0 interrupt Priority Setting for loop */!][!//

/* GTM ATOM0 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0TosConfig/*))"!][!//
#define IRQ_GTM_ATOM0_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM0Config/IrqGtmATOM0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom1' )"!][!//
/* GTM ATOM1 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1CatConfig/*))"!][!//
#define IRQ_GTM_ATOM1_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM1 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM1_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM1 interrupt Priority Setting for loop */!][!//

/* GTM ATOM1 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1TosConfig/*))"!][!//
#define IRQ_GTM_ATOM1_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM1Config/IrqGtmATOM1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom2' )"!][!//
/* GTM ATOM2 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2CatConfig/*))"!][!//
#define IRQ_GTM_ATOM2_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM2 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM2'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM2_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM2 interrupt Priority Setting for loop */!][!//

/* GTM ATOM2 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2TosConfig/*))"!][!//
#define IRQ_GTM_ATOM2_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM2PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM2Config/IrqGtmATOM20TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom3' )"!][!//
/* GTM ATOM3 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3CatConfig/*))"!][!//
#define IRQ_GTM_ATOM3_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM3 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM3'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM3_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM3 interrupt Priority Setting for loop */!][!//

/* GTM ATOM3 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3TosConfig/*))"!][!//
#define IRQ_GTM_ATOM3_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM3Config/IrqGtmATOM3TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom4' )"!][!//
/* GTM ATOM4 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4CatConfig/*))"!][!//
#define IRQ_GTM_ATOM4_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM4 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM4'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM4_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM4 interrupt Priority Setting for loop */!][!//

/* GTM ATOM4 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4TosConfig/*))"!][!//
#define IRQ_GTM_ATOM4_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM4Config/IrqGtmATOM4TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom5' )"!][!//
/* GTM ATOM5 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5CatConfig/*))"!][!//
#define IRQ_GTM_ATOM5_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM5 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM5'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM5_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM5 interrupt Priority Setting for loop */!][!//

/* GTM ATOM5 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5TosConfig/*))"!][!//
#define IRQ_GTM_ATOM5_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM5Config/IrqGtmATOM5TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom6' )"!][!//
/* GTM ATOM6 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6CatConfig/*))"!][!//
#define IRQ_GTM_ATOM6_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM6 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM6'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM6_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM6 interrupt Priority Setting for loop */!][!//

/* GTM ATOM6 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6TosConfig/*))"!][!//
#define IRQ_GTM_ATOM6_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM6Config/IrqGtmATOM6TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom7' )"!][!//
/* GTM ATOM7 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7CatConfig/*))"!][!//
#define IRQ_GTM_ATOM7_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM7 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM7'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM7_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM7 interrupt Priority Setting for loop */!][!//

/* GTM ATOM7 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7TosConfig/*))"!][!//
#define IRQ_GTM_ATOM7_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM7Config/IrqGtmATOM7TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom8' )"!][!//
/* GTM ATOM8 interrupt Category Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8CatConfig/*))"!][!//
#define IRQ_GTM_ATOM8_SR[!"num:i($SrnId - 1)"!]_CAT       (IRQ_[!"IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDFOR!][!//
                                                                                                           
/* GTM ATOM8 interrupt Priority Setting */  
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'GTMATOM8'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_GTM_ATOM8_SR[!"num:i($SrnId - 1)"!]_PRIO      [!"num:inttohex(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!NOCODE!][!//

[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of GTM ATOM8 interrupt Priority Setting for loop */!][!//

/* GTM ATOM8 interrupt type of service Setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8TosConfig/*))"!][!//
#define IRQ_GTM_ATOM8_SR[!"num:i($SrnId - 1)"!]_TOS       (IRQ_TOS_[!"IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqGtmConfig/*[1]/IrqGtmATOM8Config/IrqGtmATOM8TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//


[!IF "num:i(count(IrqSentConfig/*)) = 1"!][!//
/*
                     Container : IrqSentInterruptConfiguration
*/
/* SENT Interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqSentConfig/*[1]/IrqSentCatConfig/*))"!][!//
[!IF "($SrnId <= 9)"!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_CAT            (IRQ_[!"IrqSentConfig/*[1]/IrqSentCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_CAT           (IRQ_[!"IrqSentConfig/*[1]/IrqSentCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/*  SENT Interrupt Priority setting  */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqSentConfig/*[1]/IrqSentPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqSentConfig/*[1]/IrqSentPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqSentConfig/*[1]/IrqSentTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'SENT'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!// 
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 9)"!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_PRIO           [!"num:inttohex(IrqSentConfig/*[1]/IrqSentPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_PRIO          [!"num:inttohex(IrqSentConfig/*[1]/IrqSentPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqSentConfig/*[1]/IrqSentPrioConfig/*[num:i($SrnId)])"!][!//    
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqSentConfig/*[1]/IrqSentCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//[!/* End of SENT Interrupt Priority Setting for loop */!]

/* SENT Interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqSentConfig/*[1]/IrqSentTosConfig/*))"!][!//
[!IF "($SrnId <= 9)"!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_TOS            (IRQ_TOS_[!"IrqSentConfig/*[1]/IrqSentTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_SENT_SR[!"num:i($SrnId - 1)"!]_TOS           (IRQ_TOS_[!"IrqSentConfig/*[1]/IrqSentTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqSentConfig/*[1]/IrqSentPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqSentConfig/*[1]/IrqSentTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqI2CExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqI2CConfig/*)) = 1"!][!//
/*
                     Container : IrqI2C interruptConfiguration
*/
[!VAR "IrqI2CExist" = "'STD_ON'"!][!//
[!IF "contains( ecu:get('Irq.I2CAvailable'), 'IrqI2C0' )"!][!//
/*I2C0 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C0_BREQ_CAT            (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C0_LBREQ_CAT           (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C0_SREQ_CAT            (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C0_LSREQ_CAT           (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C0_ERR_CAT             (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C0_P_CAT               (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
                                                                                                           
/*I2C0 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'I2C0'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C0_BREQ_PRIO           [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C0_LBREQ_PRIO          [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C0_SREQ_PRIO           [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C0_LSREQ_PRIO          [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C0_ERR_PRIO            [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C0_P_PRIO              [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of I2C0 interrupt Priority Setting for loop */!][!//

/*I2C0 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C0_BREQ_TOS            (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C0_LBREQ_TOS           (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C0_SREQ_TOS            (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C0_LSREQ_TOS           (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C0_ERR_TOS             (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C0_P_TOS               (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqI2CConfig/*[1]/IrqI2C0Config/IrqI2C0TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.I2CAvailable'), 'IrqI2C1' )"!][!//
/*I2C1 interrupt Category setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C1_BREQ_CAT            (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C1_LBREQ_CAT           (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C1_SREQ_CAT            (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C1_LSREQ_CAT           (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C1_ERR_CAT             (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C1_P_CAT               (IRQ_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
                                                                                                           
/*I2C1 interrupt Priority setting */ 
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'I2C1'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C1_BREQ_PRIO           [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C1_LBREQ_PRIO          [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C1_SREQ_PRIO           [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C1_LSREQ_PRIO          [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C1_ERR_PRIO            [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C1_P_PRIO              [!"num:inttohex(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//
[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1CatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of I2C1 interrupt Priority Setting for loop */!][!//

/*I2C1 interrupt type of service setting */
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*))"!][!//
[!IF "($SrnId = 1)"!][!//
#define IRQ_I2C1_BREQ_TOS            (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 2)"!][!//
#define IRQ_I2C1_LBREQ_TOS           (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 3)"!][!//
#define IRQ_I2C1_SREQ_TOS            (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 4)"!][!//
#define IRQ_I2C1_LSREQ_TOS           (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 5)"!][!//
#define IRQ_I2C1_ERR_TOS             (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSEIF "($SrnId = 6)"!][!//
#define IRQ_I2C1_P_TOS               (IRQ_TOS_[!"IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1PrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqI2CConfig/*[1]/IrqI2C1Config/IrqI2C1TosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IrqHsslExist" = "'STD_OFF'"!][!//
[!IF "num:i(count(IrqHsslConfig/*)) = 1"!][!//
/*
                     Container : IrqHssl interruptConfiguration
*/
[!VAR "IrqHsslExist" = "'STD_ON'"!][!//
/* HSSL Cok interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslCokCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_CAT          (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslCokCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_CAT         (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslCokCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* HSSL Cok interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslCokTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'HsslCok'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_PRIO         [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_PRIO        [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslCokCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
   [!IF "$TypeOfService != 'DMA'"!][!//   
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
    [!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!// 
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of HsslCok interrupt Priority Setting for loop */!][!//

/* HSSL Cok interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslCokTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_TOS          (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslCokTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_COK_TOS         (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslCokTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslCokPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslCokTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* HSSL Trg interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslTrgCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_CAT          (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslTrgCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_CAT         (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslTrgCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* HSSL Trg interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslTrgTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'HsslTrg'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_PRIO         [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_PRIO        [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslTrgCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
   [!IF "$TypeOfService != 'DMA'"!][!//   
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
    [!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!// 
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of HsslTrg interrupt Priority Setting for loop */!][!//

/* HSSL Trg interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslTrgTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_TOS          (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslTrgTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_TRG_TOS         (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslTrgTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslTrgPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslTrgTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* HSSL Rdi interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslRdiCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_CAT          (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslRdiCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_CAT         (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslRdiCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* HSSL Rdi interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslRdiTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'HsslRdi'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_PRIO         [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_PRIO        [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslRdiCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of HsslRdi interrupt Priority Setting for loop */!][!//

/* HSSL Rdi interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslRdiTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_TOS          (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslRdiTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_RDI_TOS         (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslRdiTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslRdiPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslRdiTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* HSSL Err interrupt Category Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslErrCatConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_CAT         (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslErrCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_CAT        (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslErrCatConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/* HSSL Err interrupt Priority Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*))"!][!//
[!VAR "Givenno" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslErrTosConfig/*[num:i($SrnId)]"!][!//
[!VAR "cont" = "'HsslERR'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_PRIO        [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_PRIO       [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*[num:i($SrnId)])"!][!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*[num:i($SrnId)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslErrCatConfig/*[num:i($SrnId)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
[!IF "$TypeOfService != 'DMA'"!][!//
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
[!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!//
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!/* End of HsslERR interrupt Priority Setting for loop */!][!//

/* HSSL Err interrupt type of service Setting*/
[!FOR "SrnId" ="num:i(1)" TO "num:i(count(IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslErrTosConfig/*))"!][!//
[!IF "($SrnId <= 10)"!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_TOS         (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslErrTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ELSE!][!//
#define IRQ_HSSL[!"num:i($SrnId - 1)"!]_ERR_TOS        (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslErrTosConfig/*[num:i($SrnId)]"!])[!CR!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslErrPrioConfig/*[num:i($SrnId)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslErrTosConfig/*[num:i($SrnId)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
	Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i($SrnId - 1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//

/* HSSL Exi interrupt Category Setting*/
#define IRQ_HSSL_EXI_CAT          (IRQ_[!"IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslExiCatConfig/*[num:i(1)]"!])[!CR!][!//

/* HSSL Exi interrupt Priority Setting*/
[!VAR "Givenno" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslExiPrioConfig/*[num:i(1)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslExiTosConfig/*[num:i(1)]"!][!//
[!VAR "cont" = "'HsslExi'"!][!//
[!NOCODE!][!//
[!IF "$TypeOfService != 'DMA'"!][!//
[!CALL "CG_PriorityCheck", "Givenno" = "$Givenno","cont" = "$cont"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define IRQ_HSSL_EXI_PRIO         [!"num:inttohex(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslExiPrioConfig/*[num:i(1)])"!][!CR!][!//
[!NOCODE!][!//
[!/* Following lines of code is used to test if Priority of Category 2 Interrupts 
     is Less than the lowest priority of Catagory 1 Interrupts  */!][!//
[!/* Check only if IRQ_OSEK_ENABLE is ON */!][!//
[!IF "(IrqGeneral/IrqOsekEnable = 'true')"!][!//

[!/* Assign current priority to variable "PRIORITY" */!][!//
[!VAR "PRIORITY" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslExiPrioConfig/*[num:i(1)])"!][!//  
 [!/* Assign current category to variable "CATEGORY" */!][!//
 [!VAR "CATEGORY" = "IrqHsslConfig/*[1]/IrqHsslCatConfig/IrqHsslExiCatConfig/*[num:i(1)]"!][!//
   [!/* Check if Priority value 1 and 2 are not used if IRQ_OSEK_ENABLE is ON */!][!//
   [!IF "((num:i($PRIORITY) = num:i(1))or (num:i($PRIORITY)= num:i(2)))"!][!//
     [!WARNING "Priority 1 and 2 of CPU Interrupts are used by OSEK for Task Switching!"!][!//
   [!ENDIF!][!//
      [!/* If TypeOfService is DMA then relax the checking of CAT1 and CAT23 */!][!//   
   [!IF "$TypeOfService != 'DMA'"!][!//   
[!/* Check if current category is "CAT1" */!][!//
   [!IF "($CATEGORY) = 'CAT1'"!][!//
    [!/* Check if priority is less than MIN_CAT1_LEVEL */!][!// 
    [!IF "((num:i($PRIORITY) < num:i($MIN_CAT1_LEVEL))and(num:i($PRIORITY)!= 0))"!][!//
      [!/* Reassign MIN_CAT1_LEVEL with current priority  */!][!// 
      [!VAR "MIN_CAT1_LEVEL" = "$PRIORITY"!][!//
    [!ENDIF!][!//
   [!/* Check if current category is "CAT23" */!][!//
   [!ELSEIF "($CATEGORY) ='CAT23'"!][!//
    [!/* Check if priority is greater than MAX_CAT2_LEVEL reassign MAX_CAT2_LEVEL with current priority  */!][!//
    [!IF "((num:i($PRIORITY) > num:i($MAX_CAT2_LEVEL))and(num:i($PRIORITY)!= num:i(0)))"!][!//
      [!/* Reassign MAX_CAT2_LEVEL with current priority  */!][!//
      [!VAR "MAX_CAT2_LEVEL" = "$PRIORITY "!][!//
    [!ENDIF!][!//
   [!ENDIF!][!//    
   [!ASSERT "num:i($MIN_CAT1_LEVEL)> num:i($MAX_CAT2_LEVEL)"!][!//
     Priority of Category 2 Interrupts should be Less than lowest priority of Catagory 1 Interrupts!
   [!ENDASSERT!][!//
    [!ENDIF!][!/* End of "TypeOfService is DMA then relax the checking of CAT1 and CAT23" */!][!// 
[!ENDIF!][!/* End of "Check only if IRQ_OSEK_ENABLE is ON " */!][!//
[!ENDNOCODE!][!//

/* HSSL Exi interrupt type of service Setting*/
#define IRQ_HSSL_EXI_TOS          (IRQ_TOS_[!"IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslExiTosConfig/*[num:i(1)]"!])[!CR!][!//
[!NOCODE!][!//
[!VAR "PrioVal" = "num:i(IrqHsslConfig/*[1]/IrqHsslPrioConfig/IrqHsslExiPrioConfig/*[num:i(1)])"!][!//
[!VAR "TypeOfService" = "IrqHsslConfig/*[1]/IrqHsslTosConfig/IrqHsslExiTosConfig/*[num:i(1)]"!][!//
[!IF "$TypeOfService = 'DMA'"!][!//
[!ASSERT "num:i($PrioVal) <= num:i($DmaMaxPrio)"!][!//
Type of service is selected as DMA for [!"$cont"!]_SR[!"num:i(1)"!] and the priority is configured as [!"num:i($PrioVal)"!]. Priority should not be more than [!"num:i($DmaMaxPrio)"!]!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/* Global macros that determines whether a module / SRN is in use or not
*/
[!VAR "LinAdded" = "'false'"!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!VAR "LinAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!VAR "UartAdded" = "'false'"!][!//
[!SELECT "as:modconf('Uart')[1]"!][!//
[!VAR "UartAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!VAR "StdLinAdded" = "'false'"!][!//
[!SELECT "as:modconf('StdLin')[1]"!][!//
[!VAR "StdLinAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!VAR "ModAdded" = "'false'"!][!//
[!IF "($LinAdded = 'true') or ($UartAdded = 'true') or ($StdLinAdded = 'true')"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDIF!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_ASCLIN_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_ASCLIN_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.AscLinSrnAvailable'), 'IrqAscLin0' )) and ($ModAdded = 'true')"!][!//
#define IRQ_ASCLIN0_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_ASCLIN0_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.AscLinSrnAvailable'), 'IrqAscLin1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ASCLIN1_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_ASCLIN1_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.AscLinSrnAvailable'), 'IrqAscLin2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ASCLIN2_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_ASCLIN2_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.AscLinSrnAvailable'), 'IrqAscLin3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ASCLIN3_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_ASCLIN3_EXIST           (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_QSPI_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI0_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI0_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI1_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI1_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI2_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI2_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI3_EXIST             (STD_ON)
[!ELSE!][!//													 
#define IRQ_QSPI3_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI4_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI4_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.QspiSrnAvailable'), 'IrqQspi5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_QSPI5_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_QSPI5_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "ecu:get('Irq.QspiHCSrnAvailable') = 'NO'"!][!//
#define IRQ_QSPI_HC_SRN_EXIST       (STD_OFF)
[!ELSE!][!//
#define IRQ_QSPI_HC_SRN_EXIST       (STD_ON)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Msc')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_MSC_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_MSC_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.MscAvailable'), 'IrqMsc0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_MSC0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_MSC0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.MscAvailable'), 'IrqMsc1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_MSC1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_MSC1_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.MscAvailable'), 'IrqMsc2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_MSC2_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_MSC2_EXIST              (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_CCU6_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CCU6_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CCU6Available'), 'IrqCCU60' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CCU60_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CCU60_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CCU6Available'), 'IrqCCU61' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CCU61_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CCU61_EXIST             (STD_OFF)
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.ModAvailable'), 'IrqGpt' )"!][!//
#define IRQ_GPT_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_GPT_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.GPT12Available'), 'IrqGPT120' )"!][!//
#define IRQ_GPT120_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_GPT120_EXIST            (STD_OFF)
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.ModAvailable'), 'IrqStm' )"!][!//
#define IRQ_STM_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_STM_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM0' )"!][!//
#define IRQ_STM0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_STM0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM1' )"!][!//
#define IRQ_STM1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_STM1_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.STMAvailable'), 'IrqSTM2' )"!][!//
#define IRQ_STM2_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_STM2_EXIST              (STD_OFF)
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.ModAvailable'), 'IrqDma' )"!][!//
#define IRQ_DMA_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_DMA_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.NoOfDmaChannels'), 'IrqDmaCh0To47' )"!][!//
#define IRQ_DMA_CH0TO47_EXIST       (STD_ON)
[!ELSE!][!//
#define IRQ_DMA_CH0TO47_EXIST       (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.NoOfDmaChannels'), 'IrqDmaCh48To63' )"!][!//
#define IRQ_DMA_CH48TO63_EXIST      (STD_ON)
[!ELSE!][!//
#define IRQ_DMA_CH48TO63_EXIST      (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.NoOfDmaChannels'), 'IrqDmaCh64To127' )"!][!//
#define IRQ_DMA_CH64TO127_EXIST     (STD_ON)
[!ELSE!][!//
#define IRQ_DMA_CH64TO127_EXIST     (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Eth')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_ETH_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_ETH_EXIST               (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_CAN_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_CAN_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN1_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN2_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN2_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN3_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN3_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN4_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN4_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN5_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN5_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN6_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN6_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN7_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN7_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN8_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN8_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn9' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN9_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_CAN9_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn10' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN10_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN10_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn11' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN11_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN11_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn12' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN12_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN12_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn13' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN13_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN13_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn14' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN14_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN14_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn15' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN15_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN15_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn16' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN16_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN16_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn17' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN17_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN17_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn18' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN18_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN18_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn19' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN19_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN19_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn20' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN20_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN20_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn21' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN21_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN21_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn22' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN22_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN22_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.CanSrnAvailable'), 'IrqCanSrn23' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_CAN23_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_CAN23_EXIST             (STD_OFF)
[!ENDIF!][!//


[!IF "(contains( ecu:get('Irq.HsmSrnAvailable'), 'IrqHsmSrn0' ))"!][!//
#define IRQ_HSM0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_HSM0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsmSrnAvailable'), 'IrqHsmSrn1' ))"!][!//
#define IRQ_HSM1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_HSM1_EXIST              (STD_OFF)
[!ENDIF!][!//


[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Adc')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_ADC_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_ADC_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC1_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC2_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC2_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC3_EXIST              (STD_ON)
[!ELSE!][!//													 
#define IRQ_ADC3_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC4_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC4_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC5_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC5_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC6_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC6_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC7_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC7_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC8_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC8_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC9' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC9_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_ADC9_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADC10' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADC10_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_ADC10_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADCCG0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADCCG0_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_ADCCG0_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.VAdcAvailable'), 'IrqVADCCG0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_ADCCG1_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_ADCCG1_EXIST            (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('DSAdc')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_DSADC_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M2_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M2_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A2_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A2_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M3_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M3_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A3_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A3_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M4_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M4_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A4_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A4_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M5_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M5_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A5_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A5_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M6_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M6_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A6_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A6_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M7_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M7_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A7_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A7_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M8_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M8_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A8_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A8_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrM9' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_M9_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_M9_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.DSAdcSrnAvailable'), 'IrqDSAdcSrA9' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_DSADC_A9_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_DSADC_A9_EXIST          (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Fr_AURIX')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_FLEXRAY_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_FLEXRAY_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.FlexRayAvailable'), 'IrqFlexRay0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_FLEXRAY0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_FLEXRAY0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.FlexRayAvailable'), 'IrqFlexRay1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_FLEXRAY1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_FLEXRAY1_EXIST          (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_PMU0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_PMU0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.PmuSrnAvailable'), 'IrqPmu0Sr0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_PMU0_SR0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_PMU0_SR0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.PmuSrnAvailable'), 'IrqPmu0Sr1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_PMU0_SR1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_PMU0_SR1_EXIST          (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_SCU_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_SCU_EXIST               (STD_OFF)
[!ENDIF!][!//

[!IF "contains( ecu:get('Irq.ModAvailable'), 'IrqGpsr' )"!][!//
#define IRQ_GPSRGROUP_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GPSRGROUP_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr0' )"!][!//
#define IRQ_GPSRGROUP0_EXIST        (STD_ON)
[!ELSE!][!//
#define IRQ_GPSRGROUP0_EXIST        (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr1' )"!][!//
#define IRQ_GPSRGROUP1_EXIST        (STD_ON)
[!ELSE!][!//
#define IRQ_GPSRGROUP1_EXIST        (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Irq.GpsrAvailable'), 'IrqGpsr2' )"!][!//
#define IRQ_GPSRGROUP2_EXIST        (STD_ON)
[!ELSE!][!//
#define IRQ_GPSRGROUP2_EXIST        (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!NOCODE!]
[!SELECT "as:modconf('Mcu')[1]"!]
[!VAR "McuSelect" = "'McuModuleConfiguration'"!]
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!]
[!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!]
[!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!]
[!IF "$Count > num:i(0)"!]		
[!VAR "ModAdded" = "'true'"!][!//
[!ENDIF!][!//
[!ENDFOR!]
[!ENDSELECT!][!//
[!ENDNOCODE!]
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_GTM_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAei' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_AEI_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_AEI_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAru' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ARU_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ARU_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmBrc' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_BRC_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_BRC_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmCmp' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_CMP_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_CMP_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmSpe' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_SPE_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_SPE_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GtmSpeSrnAvailable'), 'IrqGtmSpe0Sr' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_SPE0_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_SPE0_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GtmSpeSrnAvailable'), 'IrqGtmSpe1Sr' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_SPE1_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_SPE1_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GtmSpeSrnAvailable'), 'IrqGtmSpe2Sr' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_SPE2_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_SPE2_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GtmSpeSrnAvailable'), 'IrqGtmSpe3Sr' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_SPE3_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_SPE3_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmPsm0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_PSM0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_PSM0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmPsm1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_PSM1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_PSM1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmDpll' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_DPLL_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_DPLL_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmErr' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ERR_EXIST           (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ERR_EXIST           (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM2_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM2_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM3_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM3_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM4_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM4_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTim5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TIM5_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TIM5_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS2_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS2_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS3_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS3_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS4_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS4_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmMcs5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_MCS5_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_MCS5_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TOM0_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TOM0_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TOM1_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TOM1_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TOM2_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TOM2_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TOM3_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TOM3_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmTom4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_TOM4_EXIST          (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_TOM4_EXIST          (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM0_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM0_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM1_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM1_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM2_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM2_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM3_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM3_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM4_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM4_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM5_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM5_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM6_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM6_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM7_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM7_EXIST         (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.GTMAvailable'), 'IrqGtmAtom8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_GTM_ATOM8_EXIST         (STD_ON)
[!ELSE!][!//
#define IRQ_GTM_ATOM8_EXIST         (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Sent')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_SENT_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_SENT_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT0_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT0_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT1_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT1_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT2_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT2_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT3_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT3_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn4' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT4_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT4_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn5' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT5_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT5_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn6' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT6_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT6_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn7' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT7_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT7_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn8' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT8_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT8_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn9' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT9_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_SENT9_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn10' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT10_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_SENT10_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn11' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT11_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_SENT11_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn12' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT12_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_SENT12_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn13' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT13_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_SENT13_EXIST            (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.SentSrnAvailable'), 'IrqSentSrn14' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_SENT14_EXIST            (STD_ON)
[!ELSE!][!//
#define IRQ_SENT14_EXIST            (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('I2c')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_I2C_EXIST               (STD_ON)
[!ELSE!][!//
#define IRQ_I2C_EXIST               (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.I2CAvailable'), 'IrqI2C0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_I2C0_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_I2C0_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.I2CAvailable'), 'IrqI2C1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_I2C1_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_I2C1_EXIST              (STD_OFF)
[!ENDIF!][!//

[!VAR "ModAdded" = "'false'"!][!//
[!SELECT "as:modconf('Hssl')[1]"!][!//
[!VAR "ModAdded" = "'true'"!][!//
[!ENDSELECT!][!//
[!//
[!IF "($ModAdded = 'true')"!][!//
#define IRQ_HSSL_EXIST              (STD_ON)
[!ELSE!][!//
#define IRQ_HSSL_EXIST              (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsslSrnAvailable'), 'IrqHssl0' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_HSSL0_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_HSSL0_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsslSrnAvailable'), 'IrqHssl1' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_HSSL1_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_HSSL1_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsslSrnAvailable'), 'IrqHssl2' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_HSSL2_EXIST             (STD_ON)
[!ELSE!][!//
#define IRQ_HSSL2_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsslSrnAvailable'), 'IrqHssl3' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_HSSL3_EXIST             (STD_ON)
[!ELSE!][!//													 
#define IRQ_HSSL3_EXIST             (STD_OFF)
[!ENDIF!][!//
[!IF "(contains( ecu:get('Irq.HsslSrnAvailable'), 'IrqHssl' ))  and ($ModAdded = 'true')"!][!//
#define IRQ_HSSL_EXI_SRN_EXIST       (STD_ON)
[!ELSE!][!//
#define IRQ_HSSL_EXI_SRN_EXIST       (STD_OFF)
[!ENDIF!][!//
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//

/* IRQ_CFG_H */
#endif
