[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Gtm.m $                                                    **
**                                                                           **
**  $CC VERSION : \main\54 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Gtm.m file                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Gtm.m                                                        **
**                                                                           **
**  $CC VERSION : \main\54 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file (Mcu.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/
[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('GTM_M'))"!][!//
[!VAR "GTM_M"="'true'"!][!//
[!/*
MACRO: Gtm_PortConfig 
Macro to generate configuration switch Values ON/OFF based on configuration
true/false
*/!][!/*
*/!][!VAR "ToutSel0Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel1Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel2Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel3Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel4Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel5Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel6Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel7Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel8Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel9Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel10Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel11Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel12Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel13Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel14Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel15Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel16Check" = "num:i(0)"!][!/*
*/!][!MACRO "Gtm_PortConfig", "PortVal" = "", "ModuleUsage" = ""!][!//
[!VAR "ToutVal" = "text:split($PortVal, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "ToutVal" = "text:split($ToutVal, 'UT')[position()-1 = 1]"!][!/*
*/!][!VAR "PortSelect" = "text:split($PortVal, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "PortSelect" = "text:split($PortSelect, 'EL')[position()-1 = 1]"!][!/*
*/!][!IF "$PortSelect = 'A'"!][!/*
*/!][!VAR "PortSelect" = "'0'"!][!/*
*/!][!ELSEIF "$PortSelect = 'B'"!][!/*
*/!][!VAR "PortSelect" = "'1'"!][!/*
*/!][!ELSEIF "$PortSelect = 'C'"!][!/*
*/!][!VAR "PortSelect" = "'2'"!][!/*
*/!][!ELSEIF "$PortSelect = 'D'"!][!/*
*/!][!VAR "PortSelect" = "'3'"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$ModuleUsage = num:i(1)"!][!/* if used for PWM thn check for the TOUT clashes.
*/!][!VAR "Position" = "num:i(2 * ($ToutVal mod 16))"!][!/*
*/!][!IF "$ToutVal < 16"!][!/*
*/!][!ASSERT "bit:and($ToutSel0Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel0Check" = "bit:or($ToutSel0Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel0" = "bit:or($ToutSel0, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 32"!][!/*
*/!][!ASSERT "bit:and($ToutSel1Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel1Check" = "bit:or($ToutSel1Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel1" = "bit:or($ToutSel1, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 48"!][!/*
*/!][!ASSERT "bit:and($ToutSel2Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel2Check" = "bit:or($ToutSel2Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel2" = "bit:or($ToutSel2, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 64"!][!/*
*/!][!ASSERT "bit:and($ToutSel3Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel3Check" = "bit:or($ToutSel3Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel3" = "bit:or($ToutSel3, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 80"!][!/*
*/!][!ASSERT "bit:and($ToutSel4Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel4Check" = "bit:or($ToutSel4Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel4" = "bit:or($ToutSel4, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 96"!][!/*
*/!][!ASSERT "bit:and($ToutSel5Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel5Check" = "bit:or($ToutSel5Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel5" = "bit:or($ToutSel5, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 112"!][!/*
*/!][!ASSERT "bit:and($ToutSel6Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel6Check" = "bit:or($ToutSel6Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel6" = "bit:or($ToutSel6, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 128"!][!/*
*/!][!ASSERT "bit:and($ToutSel7Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel7Check" = "bit:or($ToutSel7Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel7" = "bit:or($ToutSel7, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 144"!][!/*
*/!][!ASSERT "bit:and($ToutSel8Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel8Check" = "bit:or($ToutSel8Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel8" = "bit:or($ToutSel8, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 160"!][!/*
*/!][!ASSERT "bit:and($ToutSel9Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel9Check" = "bit:or($ToutSel9Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel9" = "bit:or($ToutSel9, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 176"!][!/*
*/!][!ASSERT "bit:and($ToutSel10Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel10Check" = "bit:or($ToutSel10Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel10" = "bit:or($ToutSel10, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 192"!][!/*
*/!][!ASSERT "bit:and($ToutSel11Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel11Check" = "bit:or($ToutSel11Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel11" = "bit:or($ToutSel11, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 208"!][!/*
*/!][!ASSERT "bit:and($ToutSel12Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel12Check" = "bit:or($ToutSel12Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel12" = "bit:or($ToutSel12, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 224"!][!/*
*/!][!ASSERT "bit:and($ToutSel13Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel13Check" = "bit:or($ToutSel13Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel13" = "bit:or($ToutSel13, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 240"!][!/*
*/!][!ASSERT "bit:and($ToutSel14Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel14Check" = "bit:or($ToutSel14Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel14" = "bit:or($ToutSel14, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 256"!][!/*
*/!][!ASSERT "bit:and($ToutSel15Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel15Check" = "bit:or($ToutSel15Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel15" = "bit:or($ToutSel15, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 272"!][!/*
*/!][!ASSERT "bit:and($ToutSel16Check, bit:shl(1, $Position)) = 0"!][!/*
*/!]ERROR: GTM: TOUT[!"$ToutVal"!] is configured more than once .[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ToutSel16Check" = "bit:or($ToutSel16Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel16" = "bit:or($ToutSel16, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleUsage = num:i(3)"!][!/* if configured for GTM complex driver, TOUT clash check is not required as planned.
*/!][!VAR "Position" = "num:i(2 * ($ToutVal mod 16))"!][!/*
*/!][!IF "$ToutVal < 16"!][!/*
*/!][!VAR "ToutSel0Check" = "bit:or($ToutSel0Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel0" = "bit:or($ToutSel0, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 32"!][!/*
*/!][!VAR "ToutSel1Check" = "bit:or($ToutSel1Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel1" = "bit:or($ToutSel1, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 48"!][!/*
*/!][!VAR "ToutSel2Check" = "bit:or($ToutSel2Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel2" = "bit:or($ToutSel2, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 64"!][!/*
*/!][!VAR "ToutSel3Check" = "bit:or($ToutSel3Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel3" = "bit:or($ToutSel3, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 80"!][!/*
*/!][!VAR "ToutSel4Check" = "bit:or($ToutSel4Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel4" = "bit:or($ToutSel4, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 96"!][!/*
*/!][!VAR "ToutSel5Check" = "bit:or($ToutSel5Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel5" = "bit:or($ToutSel5, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 112"!][!/*
*/!][!VAR "ToutSel6Check" = "bit:or($ToutSel6Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel6" = "bit:or($ToutSel6, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 128"!][!/*
*/!][!VAR "ToutSel7Check" = "bit:or($ToutSel7Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel7" = "bit:or($ToutSel7, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 144"!][!/*
*/!][!VAR "ToutSel8Check" = "bit:or($ToutSel8Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel8" = "bit:or($ToutSel8, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 160"!][!/*
*/!][!VAR "ToutSel9Check" = "bit:or($ToutSel9Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel9" = "bit:or($ToutSel9, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 176"!][!/*
*/!][!VAR "ToutSel10Check" = "bit:or($ToutSel10Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel10" = "bit:or($ToutSel10, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 192"!][!/*
*/!][!VAR "ToutSel11Check" = "bit:or($ToutSel11Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel11" = "bit:or($ToutSel11, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 208"!][!/*
*/!][!VAR "ToutSel12Check" = "bit:or($ToutSel12Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel12" = "bit:or($ToutSel12, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 224"!][!/*
*/!][!VAR "ToutSel13Check" = "bit:or($ToutSel13Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel13" = "bit:or($ToutSel13, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 240"!][!/*
*/!][!VAR "ToutSel14Check" = "bit:or($ToutSel14Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel14" = "bit:or($ToutSel14, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 256"!][!/*
*/!][!VAR "ToutSel15Check" = "bit:or($ToutSel15Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel15" = "bit:or($ToutSel15, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ELSEIF "$ToutVal < 272"!][!/*
*/!][!VAR "ToutSel16Check" = "bit:or($ToutSel16Check, bit:shl(1, $Position))"!][!/*
*/!][!VAR "ToutSel16" = "bit:or($ToutSel16, bit:shl($PortSelect, $Position))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*[!IF "$ModuleUsage = num:i(1)"!]
*/!][!ENDMACRO!][!//
[!/*
MACRO: Gtm_TimPortConfig 
Macro to generate configuration switch Values ON/OFF based on configuration
true/false
*/!][!//
[!MACRO "Gtm_TimPortConfig", "TimModule" = "", "TimChannel" = "", "PortSelect" = ""!][!//
[!/*
*/!][!VAR "PortVal" = "text:split($PortSelect, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "PortVal" = "text:split($PortVal, 'L')[position()-1 = 1]"!][!/*
*/!][!IF "num:i($TimModule) = '0'"!][!/*
*/!][!VAR "TimSel0" = "bit:or($TimSel0, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ELSEIF "num:i($TimModule) = '1'"!][!/*
*/!][!VAR "TimSel1" = "bit:or($TimSel1, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ELSEIF "num:i($TimModule) = '2'"!][!/*
*/!][!VAR "TimSel2" = "bit:or($TimSel2, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ELSEIF "num:i($TimModule) = '3'"!][!/*
*/!][!VAR "TimSel3" = "bit:or($TimSel3, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ELSEIF "num:i($TimModule) = '4'"!][!/*
*/!][!VAR "TimSel4" = "bit:or($TimSel4, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ELSEIF "num:i($TimModule) = '5'"!][!/*
*/!][!VAR "TimSel5" = "bit:or($TimSel5, bit:shl($PortVal, ($TimChannel * 4)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDMACRO!][!//
[!MACRO "Gtm_ClearToutSelCheck"!][!/*
*/!][!VAR "ToutSel0Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel1Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel2Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel3Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel4Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel5Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel6Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel7Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel8Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel9Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel10Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel11Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel12Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel13Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel14Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel15Check" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel16Check" = "num:i(0)"!][!/*
*/!][!ENDMACRO!][!//
[!/* Macro for generating the TGC structure 

*/!][!MACRO "Gtm_TgcConfigure", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "TGCConfigured" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "15"!][!/* Loop through the 16 bits of TomModuleLookUpx
*/!][!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!][!/* Check for Complex Driver Configs
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "TGCNumber" = "num:i($LoopCountTemp div 8)"!][!/*
*/!][!/*TOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_TGC[!"$TGCNumber"!][!/*
*/!][!IF "bit:and($TGCConfigured, bit:shl(1, ($ModuleNumber * 2) + $TGCNumber)) = 0"!][!/*  To check if this TGC is already Configured  
*/!][!VAR "TGCConfigured" = "bit:bitset($TGCConfigured, (($ModuleNumber * 2) + $TGCNumber))"!][!/*
*/!][!VAR "TGCBitCodedInfo" = "bit:bitset($TGCBitCodedInfo, (($ModuleNumber * 2) + $TGCNumber))"!][!/*
*/!][!VAR "FupdAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "UpEnAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "EndisCtrlAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "EndisStatAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "OutEnCtrlAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "OutEnStatAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "TGCCount" = "bit:shl($TGCNumber, 3)"!][!/*
*/!][!FOR "Count" = "num:i($TGCCount)" TO "num:i(7 + $TGCCount)"!][!/*
*/!][!VAR "ChannelName" = "concat('TomChannel_',$Count)"!][!/*
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChEnableForceUpdate) = 'true'"!][!/*
*/!][!VAR "FupdAccumulate" = "bit:or($FupdAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChResetCn0OnForceUpdate)  = 'true'"!][!/*	
*/!][!VAR "FupdAccumulate" = "bit:or($FupdAccumulate, bit:shl(2, 16 + ($Count * 2)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChUpdateEnableOnCn0Reset)  = 'true'"!][!/*	
*/!][!VAR "UpEnAccumulate" = "bit:or($UpEnAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelEnable/TomChannelEnable)  = 'ON_GLOBAL_TRIGGER'"!][!/*	
*/!][!VAR "EndisCtrlAccumulate" = "bit:or($EndisCtrlAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelEnable/TomChannelEnable) = 'AT_START'"!][!/*
*/!][!IF "node:value(./TomChannelEnable/TomChDisableOnTgcTrigger)  = 'true'"!][!/*	
*/!][!VAR "EndisCtrlAccumulate" = "bit:or($EndisCtrlAccumulate, bit:shl(1, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./TomChannelEnable/TomChannelEnable)  = 'AT_START'"!][!/*	
*/!][!VAR "EndisStatAccumulate" = "bit:or($EndisStatAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./TomChannelOutput/TomChannelOutputControl)  = 'ENABLE_OUTPUT_ON_GLOBAL_TRIGGER'"!][!/*	
*/!][!VAR "OutEnCtrlAccumulate" = "bit:or($OutEnCtrlAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelOutput/TomChannelOutputControl) = 'ENABLE_OUTPUT_AT_START'"!][!/*
*/!][!IF "node:value(./TomChannelOutput/TomChOutputDisableOnTgcTrig)  = 'true'"!][!/*	
*/!][!VAR "OutEnCtrlAccumulate" = "bit:or($OutEnCtrlAccumulate, bit:shl(1, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./TomChannelOutput/TomChannelOutputControl)  = 'ENABLE_OUTPUT_AT_START'"!][!/*	
*/!][!VAR "OutEnStatAccumulate" = "bit:or($OutEnStatAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/* IF "./TomChannelUsage = 'USED_BY_GTM_DRIVER'"
*/!][!ENDSELECT!][!/*	SELECT "./Tom/*['$ModuleNumber']/TomChannel/*[$Count]"
*/!][!ENDFOR!][!/* FOR "Count" = "($TGCNumber * 8)" TO "($TGCNumber * 8) + 7"
*/!]  {
[!IF "$Count = 7"!][!/* Lower 16 bits of the variables are filled
*/!]
      [!"num:inttohex($UpEnAccumulate,4)"!]U,
      [!"num:inttohex($EndisCtrlAccumulate,4)"!]U,
      [!"num:inttohex($EndisStatAccumulate,4)"!]U,
      [!"num:inttohex($OutEnCtrlAccumulate,4)"!]U,
      [!"num:inttohex($OutEnStatAccumulate,4)"!]U,
      [!"num:inttohex($FupdAccumulate,8)"!]U,      
[!ELSE!][!//      
      [!"num:inttohex(bit:shr($UpEnAccumulate,16),4)"!]U,
      [!"num:inttohex(bit:shr($EndisCtrlAccumulate,16),4)"!]U,
      [!"num:inttohex(bit:shr($EndisStatAccumulate,16),4)"!]U,
      [!"num:inttohex(bit:shr($OutEnCtrlAccumulate,16),4)"!]U,
      [!"num:inttohex(bit:shr($OutEnStatAccumulate,16),4)"!]U,      
      [!"num:inttohex(bit:shr($FupdAccumulate,16),8)"!]U,
[!ENDIF!][!/*      
*/!]  },
[!ENDIF!][!/* IF "bit:and($TGCConfigured, bit:shl(1, ($ModuleNumber * 2) + $TGCNumber)) = 0"
*/!][!ENDIF!][!/* IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)) > 0
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*



*/!][!MACRO "Gtm_TomChannelConfig", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "15"!][!/*
 Loop through the 32 bits of TomModuleLookUp
*/!][!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!][!/* Check for Complex Driver Configs
*/!]  {
[!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!/*TOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]
*/!][!VAR "ChannelName" = "concat('TomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!][!//
[!VAR "BuildReg" = "num:i(0)"!][!/*    
*/!][!VAR "BuildRegTemp" = "node:value(./TomChannelInterrupt/TomIntEnableOnPeriodMatchCcu0)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*	        
*/!][!VAR "BuildRegTemp" = "node:value(./TomChannelInterrupt/TomIntEnableOnDutyCycleMatchCcu1)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/* 
*/!]    [!"num:inttohex($BuildReg)"!]U,
    [!"num:inttohex(./TomChannelTimerParameters/TomChannelCounterValCn0)"!]U,
    [!"num:inttohex(./TomChannelTimerParameters/TomChannelPeriodCompareValCm0)"!]U,
    [!"num:inttohex(./TomChannelTimerParameters/TomChannelDutyCycleCompareValCm1)"!]U,
    [!"num:inttohex(./TomChannelTimerParameters/TomChPeriodCompareShadowValSr0)"!]U,
    [!"num:inttohex(./TomChannelTimerParameters/TomChDCycCompareShadowValSr1)"!]U,
  },     
[!ENDSELECT!]
[!VAR "ChannelName" = "concat('TomChannel_',$Count)"!][!/*
*/!][!/* SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]
*/!][!ENDIF!][!/* IF "bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*

Macro for TOM Notification configuration from LCfg file

*/!][!MACRO "Gtm_TomNotifConfig", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "15"!][!/*
 Loop through the 32 bits of TomModuleLookUp
*/!][!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3) "!][!/* Check for GTM Complex Driver Configs
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('TomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "TomEnable" = "node:value(./TomChannelUsage/TomChannelUsage)"!][!/*
*/!][!IF "$TomEnable = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./TomChannelInterrupt/TomIntEnableOnPeriodMatchCcu0)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./TomChannelInterrupt/TomIntEnableOnDutyCycleMatchCcu1)"!][!/*
*/!][!VAR "Notification" = "node:value(./TomChannelInterrupt/TomNotification)"!][!/*
*/!][!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!][!/*
*/!][!ASSERT "$Notification != 'NULL_PTR'"!][!/*
*/!]Configuration Error: TOM [!"$ModuleNumber"!] channel [!"$ChannelNumber"!] TomNotification cannot be NULL_PTR when TomIntEnableOnPeriodMatchCcu0 or TomIntEnableOnDutyCycleMatchCcu1 is enabled[!/*
*/!][!ENDASSERT!][!/*
*/!]
  &[!"$Notification"!],[!/*
*/!][!ENDIF!][!/*[!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!]
*/!][!ENDIF!][!/*[!IF $TomEnable = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDSELECT!][!/*
*/!][!ENDIF!][!/*[!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!]
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*[!MACRO "Gtm_TomNotifConfig", "TomModuleLookUp"="", "ModuleNumber"=""!]
*/!][!/*




Macro for ATOM CCU Notification configuration from LCfg file

*/!][!MACRO "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="", "ModuleNumber"="", "CcuNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/*
 Loop through the 32 bits of AtomModuleLookUp
*/!][!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3) "!][!/* Check for GTM Complex Driver Configs
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('AtomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "AtomEnable" = "node:value(./AtomChannelUsage/AtomChannelUsage)"!][!/*
*/!][!IF "$AtomEnable = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "GlobalCcu" = "node:value(./AtomChannelInterrupt/AtomGlobalCcuSel)"!][!/*	
*/!][!IF "$GlobalCcu = 'false'"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger)"!][!/*
*/!][!VAR "Notification" = "node:value(./AtomChannelInterrupt/AtomNotification)"!][!/*
*/!][!IF "$CcuNumber = num:i(0)"!][!/*
*/!][!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!][!/*
*/!][!ASSERT "$Notification != 'NULL_PTR'"!][!/*
*/!]Configuration Error: Atom[!"$ModuleNumber"!] Channel [!"@index"!]AtomNotification cannot be NULL_PTR when AtomIntEnableOnPeriodMatchCcu0 or AtomIntEnableOnDutyCycleMatchCcu1 is enabled[!/*
*/!][!ENDASSERT!][!/*
*/!]
  &[!"$Notification"!],[!/*
*/!][!ENDIF!][!/*[!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!]
*/!][!ENDIF!][!/*[!IF "$CcuNumber = num:i(1)"!]
*/!][!ELSE!][!/*
*/!][!VAR "NotifCcu0" = "node:value(./AtomChannelInterrupt/AtomCcu0Notification)"!][!/*
*/!][!VAR "NotifCcu1" = "node:value(./AtomChannelInterrupt/AtomCcu1Notification)"!][!/*
*/!][!IF "$NotifCcu0 != 'NULL_PTR' and $NotifCcu1 != 'NULL_PTR'"!][!/*
*/!][!IF "$CcuNumber = num:i(0)"!][!/*
*/!]
  &[!"$NotifCcu0"!],[!/*
*/!][!ELSE!][!/*
*/!]
  &[!"$NotifCcu1"!],[!/*[!IF "$CcuNumber = num:i(0)"!]
*/!][!ENDIF!][!/*[!IF "$CcuNumber = num:i(0)"!]
*/!][!ENDIF!][!/*[!IF "$NotifCcu0 = 'NULL_PTR' or $NotifCcu1 = 'NULL_PTR'"!]
*/!][!ENDIF!][!/*[!IF "$GlobalCcu = 'false'"!]
*/!][!ENDIF!][!/*[!IF $AtomEnable = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDSELECT!][!/*
*/!][!ENDIF!][!/*[!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!]
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*[!MACRO "Gtm_AtomNotifConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!]
*/!][!/*







Macro for ATOM Notification configuration from LCfg file

*/!][!MACRO "Gtm_AtomNotifConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/*
 Loop through the 32 bits of AtomModuleLookUp
*/!][!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3) "!][!/* Check for GTM Complex Driver Configs
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('AtomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "AtomEnable" = "node:value(./AtomChannelUsage/AtomChannelUsage)"!][!/*
*/!][!IF "$AtomEnable = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger)"!][!/*
*/!][!VAR "Notification" = "node:value(./AtomChannelInterrupt/AtomNotification)"!][!/*
*/!][!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!][!/*
*/!][!ASSERT "$Notification != 'NULL_PTR'"!][!/*
*/!]Configuration Error: Atom[!"$ModuleNumber"!] Channel [!"@index"!]AtomNotification cannot be NULL_PTR when AtomIntEnableOnPeriodMatchCcu0 or AtomIntEnableOnDutyCycleMatchCcu1 is enabled[!/*
*/!][!ENDASSERT!][!/*
*/!]
  &[!"$Notification"!],[!/*
*/!][!ENDIF!][!/*[!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!]
*/!][!ENDIF!][!/*[!IF $AtomEnable = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDSELECT!][!/*
*/!][!ENDIF!][!/*[!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!]
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*[!MACRO "Gtm_AtomNotifConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!]
*/!][!/*

*/!][!MACRO "Gtm_TimNotifConfig", "TimModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
[!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/*
 Loop through the 32 bits of TimModuleLookUp
*/!][!IF "(bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 2) "!][!/* Check for GTM Complex Driver Configs
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('TimChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "TimEnable" = "node:value(./TimChannelGeneral/TimChannelUsage)"!][!/*
*/!][!IF "$TimEnable = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "NewVal" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnNewVal)"!][!/*
*/!][!VAR "EcntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnEcntOfl)"!][!/*
*/!][!VAR "CntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnCntOfl)"!][!/*
*/!][!VAR "GprxOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGprxOfl)"!][!/*
*/!][!VAR "ToDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnToDet)"!][!/*
*/!][!VAR "GlitchDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGlitchDet)"!][!/*
*/!][!VAR "Notification" = "node:value(./TimChannelInterrupt/TimNotification)"!][!/*
*/!][!IF "$Notification = 'NULL_PTR'"!][!/*
*/!][!ASSERT "($NewVal = 'false' and $EcntOfl = 'false' and $CntOfl = 'false' and $GprxOfl = 'false' and $ToDet = 'false' and $GlitchDet = 'false')"!][!/*
*/!] Configuration Error: [!"@index"!]TimNotification cannot be NULL_PTR if atleast one TimChannelInterrupt param is configured,
[!ENDASSERT!][!/*
*/!][!ELSEIF "($NewVal = 'true' or $EcntOfl = 'true' or $CntOfl = 'true' or $GprxOfl = 'true' or $ToDet = 'true' or $GlitchDet = 'true')"!]
  &[!"$Notification"!],[!/*
*/!][!ENDIF!][!/*[!IF "$Notification = 'NULL_PTR'"!]
*/!][!ENDIF!][!/*[!IF "$TimEnable = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDSELECT!][!/*[!SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@name=$ChannelName]"!]
*/!][!ENDIF!][!/*[!IF "(bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!]
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "15"
*/!][!ENDMACRO!][!/*[!MACRO "Gtm_TimNotifConfig", "TimModuleLookUp"="", "ModuleNumber"=""!]
*/!][!/*


*/!][!MACRO "Gtm_TomTgcConfig", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "TGCConfigured" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "15"!][!/* Loop through the 32 bits of TomModuleLookUp
*/!][!IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)) != 0"!][!/* Check for Configured TOM Channels
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "TGCNumber" = "num:i($LoopCountTemp div 8)"!][!/*
[!TOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_TGC[!"$TGCNumber"!][!/*
*/!][!IF "bit:and($TGCConfigured, bit:shl(1, ($ModuleNumber * 2) + $TGCNumber)) = 0"!][!/*  To check if this TGC is already Configured  
*/!][!VAR "TGCConfigured" = "bit:bitset($TGCConfigured, (($ModuleNumber * 2) + $TGCNumber))"!][!/*
*/!]  {
[!/* TOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_TGC[!"$TGCNumber"!]	
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomTriggersForTgc/*[@index=$TGCNumber]"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel0) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel1) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel2) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel3) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel4) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel5) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel6) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcInternalTriggerSelect/TomTgcIntTriggerFromChannel7) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex($BuildReg)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "node:value(./TomTgcTriggerByTimebase/TomTgcTimebaseMatchValue)"!][!/*
*/!][!IF "node:value(./TomTgcTriggerByTimebase/TomTgcTimeBaseTriggerEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomTgcTriggerByTimebase/TomTgcTbuTimebaseSelect) = 'TBU_TS1_TIMEBASE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*
*/!][!ELSEIF "node:value(./TomTgcTriggerByTimebase/TomTgcTbuTimebaseSelect) = 'TBU_TS2_TIMEBASE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex($BuildReg)"!]U,
[!IF "bit:getbit($TGCBitCodedInfo, (($ModuleNumber * 2) + $TGCNumber)) = '1'"!][!/* Check for Complex Driver Configs
*/!]    &Gtm_kTomTgcConfigGroup[!"$ModuleId"!][[!"num:i($TGCConfigureCount)"!]]
[!VAR "TGCConfigureCount" = "$TGCConfigureCount + 1"!][!/*
*/!][!ELSE!][!/*
*/!]    NULL_PTR	
[!ENDIF!][!/*
*/!]  },
[!ENDSELECT!][!/*
*/!][!ENDIF!][!/* IF "bit:and($TGCConfigured, bit:shl(1, ($ModuleNumber * 2) + $TGCNumber)) = 0
*/!][!ENDIF!][!/* !IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount))  > 0"
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* [!FOR "LoopCountTemp" = "0" TO "31"!]
*/!][!ENDMACRO!][!/*

Macro to generate the TOM Channel module usage by other drivers.

*/!][!MACRO "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCountTemp" = "num:i(0)"!][!/*
*/!]    {[!/*
*/!][!FOR "LoopCount" = "0" TO "15"!][!/*
*/!][!VAR "LoopCountTemp" = "num:i($LoopCount * 2)"!][!/*
*/!][!IF "bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 1"!][!/* Check if channel is configured for PWM
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "PWMModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($PWMModuleNumber) = num:i($ModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Tom'"!]
      [!"num:inttohex(./PwmChannelId)"!]U,/*PWM channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Tom'"!]
*/!][!ENDLOOP!][!/*[!LOOP "PwmChannel/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Pwm')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 2"!][!/* Check if channel is configured for GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "GptModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($GptModuleNumber) = num:i($ModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Tom'"!]
      [!"num:inttohex(./GptChannelId)"!]U, /*GPT channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Tom'"!]
*/!][!ENDLOOP!][!/*[!LOOP "GptChannelConfiguration/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Gpt')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 3"!][!/* Check if channel is configured for GTM complex driver
*/!][!VAR "ChannelNumber" = "num:i($LoopCount)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('TomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "Notification" = "node:value(./TomChannelInterrupt/TomNotification)"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./TomChannelInterrupt/TomIntEnableOnPeriodMatchCcu0)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./TomChannelInterrupt/TomIntEnableOnDutyCycleMatchCcu1)"!][!/*
*/!][!IF "($TempCcu0 = 'true' or $TempCcu1 = 'true') and $Notification != 'NULL_PTR'"!][!/*
*/!][!VAR "TotalGtmTomConf" = "num:i($TotalGtmTomConf + 1)"!]
      [!"num:inttohex($TotalGtmTomConf, 2)"!]U, /* GTM configured channel*/[!/*
*/!][!ELSE!][!/*
*/!]
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*[!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!]
*/!][!ENDSELECT!][!/*[!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!]
*/!][!ELSE!]
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*[!IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)) != 1"!]
*/!][!ENDFOR!][!/*[!FOR "LoopCount" = "0" TO "15"!]
*/!]
    }[!ENDMACRO!][!/*


*/!][!MACRO "Gtm_TomConfig", "TomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "15"!][!/* Loop through the 64 bits of TomModuleLookUp
*/!][!IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)) != 0"!][!/* Check for Configured TOM channels
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "TGCNumber" = "num:i($LoopCountTemp div 8)"!][!/*
*/!][!VAR "ModuleUsage" = "num:i(0)"!][!/*
*/!][!/*TOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_TGC[!"$TGCNumber"!][!/*
*/!][!VAR "ChannelName" = "concat('TomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]"!][!/*	
*/!]  {
[!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 2)"!][!/* If Channel is used for GPT */
*/!]    GTM_DRIVER_GPT,
[!VAR "ModuleUsage" = "num:i(2)"!][!/*
*/!][!ELSEIF "bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 1"!][!/* If Channel is used for PWM */    	
*/!]    GTM_DRIVER_PWM,
[!VAR "ModuleUsage" = "num:i(1)"!][!/*
*/!][!ELSE!][!/* If Channel is used for Complex */    	
*/!]    GTM_DRIVER_COMPLEX,
[!VAR "ModuleUsage" = "num:i(3)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"./TomChannelInterrupt/TomInterruptMode"!],
[!/*  Output Port Pin Selection. Output will be selected only if PWM is chosen or Complex is chosen with 
Output enabled
*/!][!IF "./TomChannelOutput/TomChannelPortPinSelect != 'PARAMETER_NOT_AVAILABLE'"!][!/* To identify if BMD or XDM used for Configuation
TomChannelPortPinSelect is not applicable in case of BMD. Instead GTM connections have to be configured.
*/!][!IF "$ModuleUsage = num:i(1)"!][!/* 
*/!][!IF "./TomChannelOutput/TomChannelPortPinSelect != 'NO_PORT_PIN_MAPPED'"!][!/* To identify if BMD or XDM used for Configuation
*/!][!CALL "Gtm_PortConfig","PortVal" = "./TomChannelOutput/TomChannelPortPinSelect", "ModuleUsage" = "$ModuleUsage"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ELSEIF "($ModuleUsage = num:i(3)) and (node:value(./TomChannelOutput/TomChannelOutputControl) != 'DONT_ENABLE_CHANNEL_OUTPUT')"!][!/*
*/!][!IF "./TomChannelOutput/TomChannelPortPinSelect != 'NO_PORT_PIN_MAPPED'"!][!/* To identify if BMD or XDM used for Configuation
*/!][!CALL "Gtm_PortConfig","PortVal" = "./TomChannelOutput/TomChannelPortPinSelect", "ModuleUsage" = "$ModuleUsage"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/*	
*/!][!ELSE!][!/*
*/!][!VAR "IsBmdUsed" = "'true'"!][!/*
*/!][!ENDIF!][!/*	"./TomChannelOutput/TomChannelPortPinSelect" = 'PARAMETER_NOT AVAILABLE'
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
The following will be executed only if the channel is used by GTM Driver 
*/!][!IF "$ModuleUsage = num:i(3)"!][!/*     
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./TomChannelOutput/TomChannelOutputSignalLevel) = 'HIGH'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*	  
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelCounterCn0Reset) = 'ON_TRIGGER_FROM_PREV_CHANNEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelTriggerOutput) = 'CCU0_TRIG_OF_CHANNEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelOneShotMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$ChannelNumber != num:i(15)"!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelSpeMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 28)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelGatedCounterMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 29)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*
*/!][!IF "node:value(./TomChannelTimerParameters/TomChannelBitReversalMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 27)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!]    Gtm_lTimerCtrlValue([!"num:inttohex($BuildReg)"!]U,[!"./TomChannelTimerParameters/TomChannelClockSelect"!]),[!/*
*/!][!IF "(bit:shr(bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 3)"!][!/* If Channel is used as Complex */    
*/!][!VAR "TomConfigureCount" = "$TomConfigureCount + 1"!]
    &Gtm_kTomChannelConfig[!"$ModuleId"!][[!"num:i($TomConfigureCount)"!]][!/*
*/!][!ELSE!]
    NULL_PTR
[!ENDIF!]
  },
[!ENDSELECT!]

[!VAR "ChannelName" = "concat('TomChannel_',$ChannelNumber)"!][!/*
*/!][!/*	SELECT "./Tom/*[@index=$ModuleNumber]/TomChannel/*[@name=$ChannelName]
*/!][!ENDIF!][!/* IF "bit:and($TomModuleLookUp, bit:shl(3, $LoopCount)) > 0
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "31"
*/!][!ENDMACRO!][!/*


*/!][!MACRO "Gtm_AgcConfigure", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "AGCConfigured" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of AtomModuleLookUp
*/!][!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!][!/* Check for Complex Driver Configs
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "AGCNumber" = "num:i(0)"!][!/*
*/!][!/*ATOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_AGC[!"$AGCNumber"!][!/*
*/!][!IF "bit:and($AGCConfigured, bit:shl(1, $ModuleNumber + $AGCNumber)) = 0"!][!/*  To check if this AGC is already Configured  
*/!][!VAR "AGCConfigured" = "bit:bitset($AGCConfigured, ($ModuleNumber + $AGCNumber))"!][!/*
*/!][!VAR "AGCBitCodedInfo" = "bit:bitset($AGCBitCodedInfo, ($ModuleNumber + $AGCNumber))"!][!/*
*/!][!VAR "FupdAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "UpEnAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "EndisCtrlAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "EndisStatAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "OutEnCtrlAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "OutEnStatAccumulate" = "num:i(0)"!][!/*
*/!][!VAR "AGCCount" = "bit:shl($AGCNumber, 3)"!][!/*
*/!][!FOR "Count" = "num:i($AGCCount)" TO "num:i(7 + $AGCCount)"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@index=$Count]"!][!/*
*/!][!IF "node:value(./AtomChannelUsage/AtomChannelUsage) = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChEnableForceUpdate)  = 'true'"!][!/*	
*/!][!VAR "FupdAccumulate" = "bit:or($FupdAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChResetCn0OnForceUpdate)  = 'true'"!][!/*	
*/!][!VAR "FupdAccumulate" = "bit:or($FupdAccumulate, bit:shl(2, 16 + ($Count * 2)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChUpdateEnableOnCn0Reset)  = 'true'"!][!/*	
*/!][!VAR "UpEnAccumulate" = "bit:or($UpEnAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelEnable/AtomChannelEnable)  = 'ON_GLOBAL_TRIGGER'"!][!/*	
*/!][!VAR "EndisCtrlAccumulate" = "bit:or($EndisCtrlAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelEnable/AtomChannelEnable) = 'AT_START'"!][!/*
*/!][!IF "node:value(./AtomChannelEnable/AtomChDisableOnAgcTrigger)  = 'true'"!][!/*	
*/!][!VAR "EndisCtrlAccumulate" = "bit:or($EndisCtrlAccumulate, bit:shl(1, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./AtomChannelEnable/AtomChannelEnable)  = 'AT_START'"!][!/*	
*/!][!VAR "EndisStatAccumulate" = "bit:or($EndisStatAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./AtomChannelOutput/AtomChannelOutputControl)  = 'ENABLE_OUTPUT_ON_GLOBAL_TRIGGER'"!][!/*	
*/!][!VAR "OutEnCtrlAccumulate" = "bit:or($OutEnCtrlAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelOutput/AtomChannelOutputControl) != 'ENABLE_OUTPUT_ON_GLOBAL_TRIGGER'"!][!/*
*/!][!IF "node:value(./AtomChannelOutput/AtomChOutputDisableOnAgcTrig)  = 'true'"!][!/*	
*/!][!VAR "OutEnCtrlAccumulate" = "bit:or($OutEnCtrlAccumulate, bit:shl(1, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*	
*/!][!IF "node:value(./AtomChannelOutput/AtomChannelOutputControl)  = 'ENABLE_OUTPUT_AT_START'"!][!/*	
*/!][!VAR "OutEnStatAccumulate" = "bit:or($OutEnStatAccumulate, bit:shl(2, $Count * 2))"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/* IF "./AtomChannelUsage = 'USED_BY_GTM_DRIVER'"
*/!][!ENDSELECT!][!/*	SELECT "./Atom/*['$ModuleNumber']/AtomChannel/*[$Count]"
*/!][!ENDFOR!][!/* FOR "Count" = "($AGCNumber * 8)" TO "($AGCNumber * 8) + 7"
*/!]  {
      [!"num:inttohex($UpEnAccumulate,4)"!]U,
      [!"num:inttohex($EndisCtrlAccumulate,4)"!]U,
      [!"num:inttohex($EndisStatAccumulate,4)"!]U,
      [!"num:inttohex($OutEnCtrlAccumulate,4)"!]U,
      [!"num:inttohex($OutEnStatAccumulate,4)"!]U,
      [!"num:inttohex($FupdAccumulate,8)"!]U,

  },
[!ENDIF!][!/* IF "bit:and($AGCConfigured, bit:shl(1, $ModuleNumber + $AGCNumber)) = 0"
*/!][!ENDIF!][!/* IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) > 0
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "7"
*/!][!ENDMACRO!][!/*


*/!][!MACRO "Gtm_AtomChannelConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of AtomModuleLookUp
*/!][!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)  = 3)"!][!/* Check for Complex Driver Configs
*/!]  {
[!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
ATOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@index=$ChannelNumber]"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!VAR "GlobalCcu" = "node:value(./AtomChannelInterrupt/AtomGlobalCcuSel)"!][!/*
*/!][!IF "$GlobalCcu = 'false'"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*        
*/!][!VAR "BuildRegTemp" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/* [!IF "$BuildRegTemp = 'true'"!]
*/!][!ELSE!][!/* if AtomGlobalCcuSel enable both the interrupt
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/* [!IF "$GlobalCcu = 'false'"!]

*/!]    [!"num:inttohex($BuildReg)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "node:value(./AtomChannelAruConfiguration/AtomChAruReadAddress0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./AtomChannelAruConfiguration/AtomChAruReadAddress1)"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($BuildRegTemp,16))"!][!/*
*/!]    [!"num:inttohex($BuildReg)"!]U,
    [!"num:inttohex(./AtomChannelTimerParameters/AtomChannelCounterValCn0)"!]U,
    [!"num:inttohex(./AtomChannelTimerParameters/AtomChannelCompareValueCm0)"!]U, 
    [!"num:inttohex(./AtomChannelTimerParameters/AtomChannelCompareValueCm1)"!]U,
    [!"num:inttohex(./AtomChannelTimerParameters/AtomChShadowCompareValSr0)"!]U,
    [!"num:inttohex(./AtomChannelTimerParameters/AtomChShadowCompareValSr1)"!]U

  },     
[!ENDSELECT!][!/* SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@index=$Count]
*/!][!ENDIF!][!/* IF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "7"
*/!][!ENDMACRO!][!/*



*/!][!MACRO "Gtm_AtomAgcConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "AGCConfigured" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of AtomModuleLookUp
*/!][!IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) != 0"!][!/* Check for Configured ATOM Channels
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "AGCNumber" = "num:i(0)"!][!/*
[!ATOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_AGC[!"$AGCNumber"!]
*/!][!IF "bit:and($AGCConfigured, bit:shl(1, $ModuleNumber + $AGCNumber)) = 0"!][!/*  To check if this AGC is already Configured  
*/!][!VAR "AGCConfigured" = "bit:bitset($AGCConfigured, ($ModuleNumber + $AGCNumber))"!][!/*
*/!]  {
[!/*ATOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_AGC[!"$AGCNumber"!]	
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomTriggerForAgc"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel0) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel1) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel2) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel3) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel4) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel5) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel6) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcInternalTriggerSelect/AtomAgcIntTriggerFromChannel7) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex($BuildReg)"!]U,
[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "node:value(./AtomAgcTriggerByTimebase/AtomAgcTimebaseMatchValue)"!][!/*
*/!][!IF "node:value(./AtomAgcTriggerByTimebase/AtomAgcTimeBaseTriggerEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomAgcTriggerByTimebase/AtomAgcTbuTimebaseSelect) = 'TBU_TS1_TIMEBASE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*
*/!][!ELSEIF "node:value(./AtomAgcTriggerByTimebase/AtomAgcTbuTimebaseSelect) = 'TBU_TS2_TIMEBASE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex($BuildReg)"!]U,
[!IF "bit:getbit($AGCBitCodedInfo, ($ModuleNumber + $AGCNumber)) = '1'"!][!/* Check for Complex Driver Configs
*/!]    &Gtm_kAtomAgcConfigGroup[!"$ModuleId"!][[!"num:i($AGCConfigureCount)"!]]
[!VAR "AGCConfigureCount" = "$AGCConfigureCount + 1"!][!/*
*/!][!ELSE!][!/*
*/!]    NULL_PTR	
[!ENDIF!][!/*
*/!]  },
[!ENDSELECT!][!/*
*/!][!ENDIF!][!/* IF "bit:and($AGCConfigured, bit:shl(1, $ModuleNumber + $AGCNumber)) = 0
*/!][!ENDIF!][!/* !IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount))  > 0"
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* [!FOR "LoopCountTemp" = "0" TO "7"!]
*/!][!ENDMACRO!][!/*




*/!][!MACRO "Gtm_AtomConfig", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount"	= "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of AtomModuleLookUp
*/!][!IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) != 0"!][!/* Check for Configured ATOM channels
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "AGCNumber" = "num:i(0)"!][!/*
*/!][!VAR "ModuleUsage" = "num:i(0)"!][!/*
*/!][!/*ATOM[!"$ModuleNumber"!]_Channel[!"$ChannelNumber"!]_AGC[!"$AGCNumber"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@index=$ChannelNumber]"!][!/*	
*/!]  {
[!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 2)"!][!/* If Channel is used for GPT */
*/!]    GTM_DRIVER_GPT,
[!VAR "ModuleUsage" = "num:i(2)"!][!/*
*/!][!ELSEIF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 1"!][!/* If Channel is used for PWM */    	
*/!]    GTM_DRIVER_PWM,
[!VAR "ModuleUsage" = "num:i(1)"!][!/*
*/!][!ELSE!][!/* If Channel is used for Complex */
*/!]    GTM_DRIVER_COMPLEX,
[!VAR "ModuleUsage" = "num:i(3)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"./AtomChannelInterrupt/AtomInterruptMode"!],
[!/*
*/!][!/*  Output Port Pin Selection. Output will be selected only if PWM is chosen or Complex is chosen with 
Output enabled
*/!][!IF "./AtomChannelOutput/AtomChannelPortPinSelect != 'PARAMETER_NOT_AVAILABLE'"!][!/* To identify if BMD or XDM used for Configuation
TomChannelPortPinSelect is not applicable in case of BMD. Instead GTM connections have to be configured.
*/!][!IF "$ModuleUsage = num:i(1)"!][!/* 
*/!][!IF "./AtomChannelOutput/AtomChannelPortPinSelect != 'NO_PORT_PIN_MAPPED'"!][!/* To identify if BMD or XDM used for Configuation
*/!][!CALL "Gtm_PortConfig","PortVal" = "./AtomChannelOutput/AtomChannelPortPinSelect", "ModuleUsage" = "$ModuleUsage"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ELSEIF "($ModuleUsage = num:i(3)) and (node:value(./AtomChannelOutput/AtomChannelOutputControl) != 'DONT_ENABLE_CHANNEL_OUTPUT')"!][!/*
*/!][!IF "./AtomChannelOutput/AtomChannelPortPinSelect != 'NO_PORT_PIN_MAPPED'"!][!/* To identify if BMD or XDM used for Configuation
*/!][!CALL "Gtm_PortConfig","PortVal" = "./AtomChannelOutput/AtomChannelPortPinSelect", "ModuleUsage" = "$ModuleUsage"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/*	
*/!][!ELSE!][!/*
*/!][!VAR "IsBmdUsed" = "'true'"!][!/*
*/!][!ENDIF!][!/*	"./AtomChannelOutput/AtomChannelPortPinSelect != 'PARAMETER_NOT_AVAILABLE'"
*/!][!VAR "BuildReg" = "num:i(2)"!][!/* If PWM or GPT, Mode must be set to TPWM 
The following will be executed only if the channel is used by GTM Driver 
*/!][!IF "$ModuleUsage = num:i(3)"!][!/*   
*/!][!VAR "BuildReg" = "num:i(0)"!][!/* 	
*/!][!IF "node:value(./AtomChannelOutput/AtomChannelOutputSignalLevel) = 'HIGH'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*	  
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChannelCounterCn0Reset) = 'ON_TRIGGER_FROM_PREV_CHANNEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChannelTriggerOutput) = 'CCU0_TRIG_OF_CHANNEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChannelModeSelect) = 'ATOM_SIG_OUTPUT_MODE_COMPARE'"!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomServeLastAruCommStrategy) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChannelOneShotMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelAruConfiguration/AtomChAruBlockingMode) = 'GTM_ABM_ENABLED'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 27)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelAruConfiguration/AtomChannelCpuWriteRequest) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChSomcCompareStrategy) = 'TIMEBASE_LESSER_EQUAL_TO_CMx'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelAruConfiguration/AtomChannelAruEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChSomcTimebaseForComparison) = 'TBU_TS2'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(node:value(./AtomChannelTimerParameters/AtomModeControlBits), 4))"!][!/*
*/!][!IF "node:value(./AtomChannelTimerParameters/AtomChannelModeSelect) = 'ATOM_SIG_OUTPUT_MODE_COMPARE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ELSEIF "node:value(./AtomChannelTimerParameters/AtomChannelModeSelect) = 'ATOM_SIG_OUTPUT_MODE_PWM'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ELSEIF "node:value(./AtomChannelTimerParameters/AtomChannelModeSelect) = 'ATOM_SIG_OUTPUT_MODE_SERIAL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!]    Gtm_lTimerCtrlValue([!"num:inttohex($BuildReg)"!]U,[!"./AtomChannelTimerParameters/AtomChannelClockSelect"!]),
[!IF "(bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount) = 3)"!][!/* If Channel is used for Complex */
*/!][!VAR "AtomConfigureCount" = "$AtomConfigureCount + 1"!][!/*
*/!]    &Gtm_kAtomChannelConfig[!"$ModuleId"!][[!"num:i($AtomConfigureCount)"!]],
[!ELSE!][!/*
*/!]    NULL_PTR,
[!ENDIF!]
  },
[!ENDSELECT!][!/*	SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@index=$ChannelNumber]
*/!][!ENDIF!][!/* IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) > 0
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "7"
*/!][!ENDMACRO!][!/* 

Macro to generate the AtOM Channel module usage by other drivers.

*/!][!MACRO "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
[!VAR "LoopCountTemp" = "num:i(0)"!][!/*
*/!]   {[!/*
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!VAR "LoopCountTemp" = "num:i($LoopCount * 2)"!][!/*
*/!][!IF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 1"!][!/* Check if channel is configured for PWM
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "PwmGtmModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($PwmGtmModuleNumber) = num:i($ModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Atom'"!]
      [!"num:inttohex(./PwmChannelId)"!]U, /*PWM channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Atom'"!]
*/!][!ENDLOOP!][!/*[!LOOP "PwmChannel/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Pwm')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 2"!][!/* Check if channel is configured for GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!VAR "GptChannelNo" = "num:i(0)"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "GptGtmModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($ModuleNumber) = num:i($GptGtmModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Atom'"!]
      [!"num:inttohex(./GptChannelId)"!]U, /*GPT channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Atom'"!]
*/!][!VAR "GptChannelNo" = "num:i($GptChannelNo + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "GptChannelConfiguration/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Gpt')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 3"!][!/* Check if channel is configured for GTM complex driver
*/!][!VAR "ChannelNumber" = "num:i($LoopCount)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('AtomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@name=$ChannelName]"!][!/*
*/!][!IF "./AtomChannelInterrupt/AtomGlobalCcuSel = 'false'"!][!/*
*/!][!VAR "Notification" = "node:value(./AtomChannelInterrupt/AtomNotification)"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger)"!][!/*
*/!][!IF "($TempCcu0 = 'true' or $TempCcu1 = 'true') and $Notification != 'NULL_PTR'"!][!/*
*/!][!VAR "TotalGtmCCU0AtomConf" = "num:i($TotalGtmCCU0AtomConf + 1)"!]
      [!"num:inttohex($TotalGtmCCU0AtomConf, 4)"!]U, /*GTM configured channel */[!/*
*/!][!ELSE!][!/*
*/!]
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*IF "$Notification = 'NULL_PTR'"
*/!][!ELSE!][!/*
*/!][!VAR "Ccu0Notif" = "node:value(./AtomChannelInterrupt/AtomCcu0Notification)"!][!/*
*/!][!VAR "Ccu1Notif" = "node:value(./AtomChannelInterrupt/AtomCcu1Notification)"!][!/*
*/!][!IF "($Ccu0Notif != 'NULL_PTR' and $Ccu1Notif != 'NULL_PTR')"!][!/*
*/!][!VAR "TotalGtmCCU0AtomConf" = "num:i($TotalGtmCCU0AtomConf + 1)"!][!/*
*/!][!VAR "TotalGtmCCU1AtomConf" = "num:i($TotalGtmCCU1AtomConf + 1)"!][!/*
*/!][!VAR "TotalGtmCCU1AtomConf" = "bit:bitset($TotalGtmCCU1AtomConf, 7)"!][!/*
*/!]
      Gtm_lMoveCcuTo8Bit([!"num:inttohex($TotalGtmCCU1AtomConf)"!]U,[!"num:inttohex($TotalGtmCCU0AtomConf)"!]U),[!//
[!ENDIF!][!/*[!IF "($Ccu0Notif != 'NULL_PTR' and $Ccu1Notif != 'NULL_PTR')"!]
*/!][!ENDIF!][!/*[!IF "./AtomChannelInterrupt/AtomGlobalCcuSel = 'false'"!]
*/!][!ENDSELECT!][!/*
*/!][!ELSE!]
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*[!IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) != 1"!]
*/!][!ENDFOR!][!/*[!FOR "LoopCount" = "0" TO "15"!]
*/!]
    }[!ENDMACRO!][!/*



Macro to generate the AtOM Channel module usage by other drivers.

*/!][!MACRO "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="", "ModuleNumber"=""!][!/*
[!VAR "LoopCountTemp" = "num:i(0)"!][!/*
*/!]   {[!/*
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!VAR "LoopCountTemp" = "num:i($LoopCount * 2)"!][!/*
*/!][!IF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 1"!][!/* Check if channel is configured for PWM
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "PwmGtmModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($PwmGtmModuleNumber) = num:i($ModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Atom'"!]
      [!"num:inttohex(./PwmChannelId)"!]U, /*PWM channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Atom'"!]
*/!][!ENDLOOP!][!/*[!LOOP "PwmChannel/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Pwm')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 2"!][!/* Check if channel is configured for GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!VAR "GptChannelNo" = "num:i(0)"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "GptGtmModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "num:i($ModuleNumber) = num:i($GptGtmModuleNumber) and num:i($ChannelNumber) = num:i($LoopCount) and $ModuleType = 'Atom'"!]
      [!"num:inttohex(./GptChannelId)"!]U, /*GPT channel no*/[!/*
*/!][!ENDIF!][!/*[!IF "$ModuleNumber = num:i($ModuleNumber) and $ChannelNumber = num:i($LoopCount) and $ModuleType = 'Atom'"!]
*/!][!VAR "GptChannelNo" = "num:i($GptChannelNo + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "GptChannelConfiguration/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!]
*/!][!ENDSELECT!][!/* [!SELECT "as:modconf('Gpt')[1]"!]
*/!][!ELSEIF "bit:shr(bit:and($AtomModuleLookUp, bit:shl(3, $LoopCountTemp)),$LoopCountTemp) = 3"!][!/* Check if channel is configured for GTM complex driver
*/!][!VAR "ChannelNumber" = "num:i($LoopCount)"!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelName" = "concat('AtomChannel_',$ChannelNumber)"!][!/*
*/!][!SELECT "./Atom/*[@index=$ModuleNumber]/AtomChannel/*[@name=$ChannelName]"!][!/*
*/!][!VAR "Notification" = "node:value(./AtomChannelInterrupt/AtomNotification)"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger)"!][!/*
*/!][!IF "($TempCcu0 = 'true' or $TempCcu1 = 'true') and $Notification != 'NULL_PTR'"!][!/*
*/!][!VAR "TotalGtmAtomConf" = "num:i($TotalGtmAtomConf + 1)"!]
      [!"num:inttohex($TotalGtmAtomConf, 2)"!]U, /*GTM configured channel */[!/*
*/!][!ELSE!][!/*
*/!]
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*IF "$Notification = 'NULL_PTR'"
*/!][!ENDSELECT!][!/*
*/!][!ELSE!]
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,[!/*
*/!][!ENDIF!][!/*[!IF "bit:and($AtomModuleLookUp, bit:shl(3, $LoopCount)) != 1"!]
*/!][!ENDFOR!][!/*[!FOR "LoopCount" = "0" TO "15"!]
*/!]
    }[!ENDMACRO!][!/*

*/!][!MACRO "Gtm_TimFltConfig", "TimModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 8 bits of TimModuleLookUp1
*/!][!IF "bit:and($TimModuleLookUp, bit:shl(3, $LoopCount))	!= 0"!][!/* Check for TIM Usage
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]"!][!/*
*/!][!IF "(./TimChannelFilterConfig/TimChannelFilterEnable = 'false') and 
      (./TimChannelFilterConfig/TimChFilterCounterFreqSelect = 'GTM_CONFIGURABLE_CLOCK_0') and 
      (./TimChannelFilterConfig/TimChFilterModeForRisingEdge = 'IMMEDIATE_EDGE_PROPAGATION_MODE') and
      (./TimChannelFilterConfig/TimChFilterModeForFallingEdge = 'IMMEDIATE_EDGE_PROPAGATION_MODE') and
      (./TimChannelFilterConfig/TimChFilterTimeForRisingEdge = '0') and
      (./TimChannelFilterConfig/TimChFilterTimeForFallingEdge = '0')"!][!/*
*/!][!/* Do Nothing
*/!][!ELSE!][!/*
*/!][!IF "$TimFltFirstTime = num:i(0)"!][!/*
*/!]
static const Gtm_TimFltType Gtm_kTimFlt[!"$ModuleId"!][] = 
{
[!VAR "TimFltFirstTime" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/* IF "$TimFltFirstTime = num:i(0)
*/!]  {
    [!"num:inttohex(node:value(./TimChannelFilterConfig/TimChFilterTimeForRisingEdge),8)"!]U,
    [!"num:inttohex(node:value(./TimChannelFilterConfig/TimChFilterTimeForFallingEdge), 8)"!]U
  },
[!ENDIF!][!/* IF "(./TimChannelFilterConfig/TimChannelFilterEnable = 'false') and 
*/!][!ENDSELECT!][!/* SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]
*/!][!ENDIF!][!/* IF "bit:and($TimModuleLookUp1, bit:shl(3, $LoopCount))	!= 0
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "7"
*/!][!ENDMACRO!][!/*


*/!][!MACRO "Gtm_TimConfig", "TimModuleLookUp"="", "TimTimeStampLookup"="", "ModuleNumber"=""!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of TimModuleLookUp
*/!][!IF "bit:and($TimModuleLookUp, bit:shl(3, $LoopCount))	!= 0"!][!/* Check for TIM Usage
*/!]  {
[!IF "(bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)	= 2)"!][!/* Check for Complex Driver Configs
*/!]    GTM_DRIVER_COMPLEX,
[!ELSEIF "bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)	= 1"!][!/* Check for ICU usage
*/!]    GTM_DRIVER_ICU,
[!ENDIF!][!/*
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/* Set the Bit for Channel Enable
*/!][!VAR "BuildModValReg" = "num:i(0)"!][!/* Set the Bit for IN_SRC register (sets up input source mode)
*/!][!VAR "BuildAuxInReg" = "num:i(0)"!][!/* Set the Bit for AUX_IN_SRC register (sets up Auxilary input source (TOM,ATOM))
*/!][!SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]"!][!/*
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnNewVal) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnEcntOfl) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnCntOfl) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnGprxOfl) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnToDet) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelInterrupt/TimInterruptEnableOnGlitchDet) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!]    Gtm_lIncludeIntMode8Bit([!"num:inttohex($BuildReg)"!]U,[!"node:value(./TimChannelInterrupt/TimInterruptMode)"!]),[!/*
*/!][!VAR "BuildErrReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnNewValErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnEcntOflErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnCntOflErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnGprxOflErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnToDetErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelErrorInterrupt/TimInterruptEnableOnGlitchDetErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!]
    [!"num:inttohex($BuildErrReg,2)"!]U,[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*    
*/!][!IF "./TimChannelGeneral/TimChannelInputSelect = 'INPUT_OF_PREVIOUS_TIM_CHANNEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,6)"!][!/*
*/!][!ELSEIF "./TimChannelGeneral/TimChannelInputSelect = 'INPUT_OF_AUX_IN_TOM'"!][!/*
*/!][!VAR "BuildModValReg" = "bit:bitset($BuildModValReg,(4 * ( $ChannelNumber + 1 ) - 2))"!][!/*
*/!][!ELSEIF "./TimChannelGeneral/TimChannelInputSelect = 'INPUT_OF_AUX_IN_ATOM'"!][!/*
*/!][!VAR "BuildModValReg" = "bit:bitset($BuildModValReg,(4 * ( $ChannelNumber + 1 ) - 2))"!][!/*
*/!][!VAR "BuildAuxInReg" = "bit:bitset($BuildAuxInReg,$ChannelNumber)"!][!/*
*/!][!ELSEIF "./TimChannelGeneral/TimChannelInputSelect = 'INPUT_OF_VAL'"!][!/*
*/!][!VAR "BuildModValReg" = "bit:bitset($BuildModValReg,(4 * ( $ChannelNumber + 1 ) - 1))"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelValInitSignal = 'VAL_LOW'"!][!/*
*/!][!VAR "BuildModValReg" = "bit:bitset($BuildModValReg,(4 *  $ChannelNumber ))"!][!/*
*/!][!ELSE!][!/*
*/!][!VAR "BuildModValReg" = "bit:bitset($BuildModValReg,((4 *  $ChannelNumber) + 1 ))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "bit:and($TimTimeStampLookup, bit:shl(3, $LoopCount))	> 0"!][!/* If Channel is used for ICU and is in TimeStamp Mode   
*/!][!ASSERT "./TimChannelGeneral/TimChannelGpr0InputSelect  != 'CNTS_VALUE'"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured for TimeStamp Mode. This should not have GPR0 Input configured to CNTS_VALUE[!/*
*/!][!ENDASSERT!][!/*	
*/!][!ASSERT "node:exists(../../../../Tbu/*[1])"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] requires TBU for Timestamp as it is configured for Timestamp Mode. Include TBU Container[!/*
*/!][!ENDASSERT!][!/*	
*/!][!ENDIF!][!/*
*/!][!/* Port Configuration for TIM Channel 
*/!][!CALL "Gtm_TimPortConfig","TimModule" = "$ModuleNumber", "TimChannel" = "$ChannelNumber","PortSelect" = "./TimChannelGeneral/TimChannelPortPinSelect"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelGpr0InputSelect = 'CNT_VALUE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!/* Gpr0_sel
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/* Gpr0_sel
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr0InputSelect = 'ECNT_VALUE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 28)"!][!/* EGPR0_SEL
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr0InputSelect = 'TIMEBASE_TBU_TS2'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/* Gpr0_sel
*/!][!VAR "TbuUsageInTim" = "bit:bitset($TbuUsageInTim, 2)"!][!/* 
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr0InputSelect = 'TIMEBASE_TBU_TS1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!/* Gpr0_sel
*/!][!VAR "TbuUsageInTim" = "bit:bitset($TbuUsageInTim, 1)"!][!/* 
*/!][!ELSE!][!/*
*/!][!VAR "TbuUsageInTim" = "bit:bitset($TbuUsageInTim, 0)"!][!/* 
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelFilterConfig/TimChannelFilterEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelFilterConfig/TimChFilterCounterFreqSelect = 'GTM_CONFIGURABLE_CLOCK_1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/* FLT_CNT_FRQ
*/!][!ELSEIF "./TimChannelFilterConfig/TimChFilterCounterFreqSelect = 'GTM_CONFIGURABLE_CLOCK_6'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/* FLT_CNT_FRQ
*/!][!ELSEIF "./TimChannelFilterConfig/TimChFilterCounterFreqSelect = 'GTM_CONFIGURABLE_CLOCK_7'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/* FLT_CNT_FRQ
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/* FLT_CNT_FRQ
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelFilterConfig/TimChFilterModeForRisingEdge = 'DEGLITCH_WITH_HOLD_COUNTER'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/* FLT_MOD_RE
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!/* FLT_CTR_RE
*/!][!ELSEIF "./TimChannelFilterConfig/TimChFilterModeForRisingEdge = 'DEGLITCH_WITH_UPDOWN_COUNTER'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/* FLT_MOD_RE
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelFilterConfig/TimChFilterModeForFallingEdge = 'DEGLITCH_WITH_HOLD_COUNTER'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!/* FLT_MOD_FE
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 23)"!][!/* FLT_CTR_FE
*/!][!ELSEIF "./TimChannelFilterConfig/TimChFilterModeForFallingEdge = 'DEGLITCH_WITH_UPDOWN_COUNTER'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!/* FLT_MOD_FE
*/!][!ENDIF!][!/*

Configuration from now on is applicable only if the Channel is configured by complex driver
*/!][!IF "(bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)	= 2)"!][!/* Check for Complex Driver Configs
*/!][!IF "node:value(./TimChannelGeneral/TimChannelEnable)  = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/* TIM_EN
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelSignalEdgeSelect  = 'BOTH_EDGES'"!][!/*
*/!][!IF "$ModuleNumber = 0"!][!/*
*/!][!ASSERT "((./TimChannelGeneral/TimChannelModeSelect  = 'INPUT_EVENT_MODE_TIEM') or (./TimChannelGeneral/TimChannelModeSelect  = 'INPUT_PRESCALER_MODE_TIPM'))"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured for Both Edges. This is applicable only when Channel Mode is TIEM or TIPM[!/*
*/!][!ENDASSERT!][!/*	
*/!][!ELSE!][!/*
*/!][!ASSERT "./TimChannelGeneral/TimChannelModeSelect  = 'INPUT_EVENT_MODE_TIEM'"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured for Both Edges. This is applicable only when Channel Mode is TIEM[!/*
*/!][!ENDASSERT!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 14)"!][!/* ISL
*/!][!ELSEIF "./TimChannelGeneral/TimChannelSignalEdgeSelect  = 'RISING_EDGE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/* DSL
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelGpr1InputSelect = 'CNTS_VALUE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/* Gpr1_sel
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/* Gpr1_sel
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr1InputSelect = 'ECNT_VALUE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 29)"!][!/* EGPR1_SEL
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr1InputSelect = 'TIMEBASE_TBU_TS2'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/* Gpr1_sel
*/!][!ELSEIF "./TimChannelGeneral/TimChannelGpr1InputSelect = 'TIMEBASE_TBU_TS1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/* Gpr1_sel
*/!][!ELSE!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelCntsInputSelect = 'TIMEBASE_TBU_TS0'"!][!/*
*/!][!ASSERT "(./TimChannelGeneral/TimChannelModeSelect  != 'BIT_COMPRESSION_MODE_TBCM') and (./TimChannelGeneral/TimChannelModeSelect  != 'INPUT_PRESCALER_MODE_TIPM')"!][!/*
*/!]ERROR: TimChannelCntsInputSelect is configured for TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!]. This is not applicable when Channel Mode is TBCM or TIPM[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/* cnts_sel
*/!][!ENDIF!][!/*
*/!][!IF "$ModuleNumber = 0"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelTbu0Ts0BitsSelect = 'BITS_3_TO_26'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/* tbu0x_Sel
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelModeSelect = 'PULSE_INTEGRATION_MODE_TPIM'"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(1,1))"!][!/* Tim_mode
*/!][!ELSEIF "./TimChannelGeneral/TimChannelModeSelect = 'INPUT_EVENT_MODE_TIEM'"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(2,1))"!][!/* Tim_mode
*/!][!ELSEIF "./TimChannelGeneral/TimChannelModeSelect = 'INPUT_PRESCALER_MODE_TIPM'"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(3,1))"!][!/* Tim_mode
*/!][!ELSEIF "./TimChannelGeneral/TimChannelModeSelect = 'BIT_COMPRESSION_MODE_TBCM'"!][!/*
*/!][!ASSERT "$ChannelNumber = 0"!][!/*
*/!]ERROR: TBCM Mode is configured for TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!]. This is applicable only for Tim Channel 0[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(4,1))"!][!/* Tim_mode
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelGeneral/TimChannelOneShotMode) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/* Osm
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelGeneral/TimChannelAruEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/* Aru_en
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./TimChannelGeneral/TimChannelExtCaptureModeEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 19)"!][!/* EXT_CAP_EN
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelEcntResetSetting = 'SEL1_ECNT_PERIODIC_SAMPLING_MODE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!/* ECNT_RESET
*/!][!ENDIF!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelEcntOvflwSetting = 'SEL1_OVRFLOW_SIG_ON_EECNT_BITWIDTH'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 27)"!][!/* FR_ECNT_OFL
*/!][!ENDIF!][!/*
*/!][!VAR "TempReg" = "text:split(./TimChannelTimeoutDetection/TimChTimeoutDetectionEnable, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TempReg" = "text:split($TempReg, 'EL')[position()-1 = 1]"!][!/*
*/!][!IF "$TempReg = '1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,30)"!][!/*
*/!][!ELSEIF "$TempReg = '2'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,31)"!][!/*
*/!][!ELSEIF "$TempReg = '3'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,30)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,31)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!]
    [!"num:inttohex($BuildAuxInReg,2)"!]U,
[!VAR "TempReg" = "text:split(./TimChannelGeneral/TimChannelExtCaptureSrc, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TempReg" = "text:split($TempReg, 'EL')[position()-1 = 1]"!][!/*
*/!]    [!"num:inttohex($TempReg,1)"!]U,[!/* External Capture source
*/!]
    Gtm_TimbuildReg([!"num:inttohex($BuildReg)"!]U, [!"node:value(./TimChannelGeneral/TimChannelClockSelect)"!]),
[!IF "(./TimChannelFilterConfig/TimChannelFilterEnable = 'false') and
      (./TimChannelFilterConfig/TimChFilterCounterFreqSelect = 'GTM_CONFIGURABLE_CLOCK_0') and 
      (./TimChannelFilterConfig/TimChFilterModeForRisingEdge = 'IMMEDIATE_EDGE_PROPAGATION_MODE') and
      (./TimChannelFilterConfig/TimChFilterModeForFallingEdge = 'IMMEDIATE_EDGE_PROPAGATION_MODE') and
      (./TimChannelFilterConfig/TimChFilterTimeForRisingEdge = '0') and
      (./TimChannelFilterConfig/TimChFilterTimeForFallingEdge = '0')"!][!/*
*/!]    NULL_PTR,
[!ELSE!][!/*
*/!]    &Gtm_kTimFlt[!"$ModuleId"!][[!"$TimFltCount"!]],
[!VAR "TimFltCount" = "num:i($TimFltCount + 1)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex(./TimChannelGeneral/TimChannelCntsValue, 8)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(node:value(./TimChannelTimeoutDetection/TimChTimeoutDuration),0)) "!][!/*
*/!]    Gtm_TimTduBuildReg([!"num:inttohex($BuildReg)"!]U,[!"node:value(./TimChannelTimeoutDetection/TimChTimeoutClockSelect)"!]),  
    [!"num:inttohex($BuildModValReg,8)"!]U
[!ENDSELECT!][!/*	SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]"
*/!]    
},
[!ENDIF!][!/* IF "bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)  "
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "31"
*/!][!ENDMACRO!][!/*

Macro to generate TimUsage GTM and by other Drivers(ICU)
*/!][!MACRO "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="", "ModuleNumber"=""!][!/*
*/!]   {[!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!FOR "LoopCountTemp" = "0" TO "7"!][!/* Loop through the 16 bits of TimModuleLookUp
*/!][!VAR "LoopCount" = "num:i($LoopCountTemp * 2)"!][!/*
*/!][!IF "bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)	= 1"!][!/* Check if ICU has configured TIM channel
*/!][!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "TimChannel") = 'true'"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./IcuAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "IcuGtmModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!IF "num:i($IcuGtmModuleNumber) = num:i($ModuleNumber) and num:i($ChannelNumber) = num:i($LoopCountTemp)"!][!/*
*/!]
      [!"num:inttohex(./IcuChannelId)"!]U, /*ICU channel no*/[!/*
*/!][!ENDIF!][!/* IF "num:i($IcuGtmModuleNumber)=num:i($ModuleNumber) and num:i($ChannelNumber)=num:i($LoopCountTemp)"
*/!][!ENDIF!][!/* IF "contains($ChannelLocation, "TimChannel") = 'true'"
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ELSEIF "bit:shr(bit:and($TimModuleLookUp, bit:shl(3, $LoopCount)),$LoopCount)	= 2"!][!/* Check for GTM complex driver usage
*/!][!VAR "ModuleNumber" = "num:i($ModuleNumber)"!][!/*
*/!][!VAR "ChannelNumber" = "num:i($LoopCountTemp)"!][!/*
*/!][!SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]"!][!/*
*/!][!VAR "NewVal" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnNewVal)"!][!/*
*/!][!VAR "EcntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnEcntOfl)"!][!/*
*/!][!VAR "CntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnCntOfl)"!][!/*
*/!][!VAR "GprxOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGprxOfl)"!][!/*
*/!][!VAR "ToDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnToDet)"!][!/*
*/!][!VAR "GlitchDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGlitchDet)"!][!/*
*/!][!VAR "Notification" = "node:value(./TimChannelInterrupt/TimNotification)"!][!/*
*/!][!IF "($NewVal = 'true' or $EcntOfl = 'true' or $CntOfl = 'true' or $GprxOfl = 'true' or $ToDet = 'true' or $GlitchDet = 'true') and $Notification != 'NULL_PTR'"!][!/*
*/!][!VAR "TotalGtmTimConf" = "num:i($TotalGtmTimConf + 1)"!][!/*
*/!]
      [!"num:inttohex($TotalGtmTimConf,2)"!]U, /*GTM Configured channel*/[!/*
*/!][!ELSE!] 
      GTM_TIM_CH_NOT_USEDBY_ICU,[!/*
*/!][!ENDIF!][!/* IF "bit:and($TimModuleLookUp, bit:shl(3, $LoopCount))	= 1"
*/!][!ENDSELECT!][!/*	SELECT "./Tim/*[@index=$ModuleNumber]/TimChannel/*[@index=$ChannelNumber]"
*/!][!ELSE!][!/* Channel not configured for GTM and ICU both
*/!]
      GTM_TIM_CH_NOT_USEDBY_ICU,[!/*
*/!][!ENDIF!][!/* IF "bit:and($TimModuleLookUp, bit:shl(3, $LoopCount))	= 1"
*/!][!ENDFOR!][!/* FOR "LoopCountTemp" = "0" TO "7"!]
*/!]
   }[!ENDMACRO!][!/*
Macro to generate the Externs for the Notification functions
*/!][!MACRO "IsMultiNotifUsed"!][!/*
*/!][!LOOP "Atom/*"!][!/*
*/!][!LOOP "AtomChannel/*"!][!/*
*/!][!IF "./AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "GlobalCcuSel" = "node:value(./AtomChannelInterrupt/AtomGlobalCcuSel)"!][!/*
*/!][!IF "$GlobalCcuSel = 'true'"!][!//
[!VAR "MutiNotifUsed" = "num:i(1)"!][!//
[!ENDIF!][!/*[!IF "$GlobalCcuSel = 'false'"!]
*/!][!ENDIF!][!/*/AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'
*/!][!ENDLOOP!][!/*LOOP "AtomChannel/*
*/!][!ENDLOOP!][!/*LOOP "Atom/*"
*/!][!ENDMACRO!][!/*
Macro to generate the Externs for the Notification functions

*/!][!MACRO "Gtm_GenNotifExterns"!][!/*

This has 2 steps:
1) Detect if GPT, ICU and PWM needs GTM. If yes, then the corresponding Isr's should be extern'ed
2) Parse through all the GTM configurations and list the Notification functions
This whole process is needed only if PB Selectable configuration is used


*/!][!VAR "GptPresent" = "num:i(0)"!][!/*
*/!][!VAR "PwmPresent" = "num:i(0)"!][!/*
*/!][!VAR "IcuPresent" = "num:i(0)"!][!/*
Complex Driver Evaluation starts
Evaluation of TOM Channels
*/!][!LOOP "McuModuleConfiguration/*/GtmConfiguration/*[1]/Tom/*/TomChannel/*"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!IF "(./TomChannelInterrupt/TomNotification != 'NULL_PTR') and ((./TomChannelInterrupt/TomIntEnableOnPeriodMatchCcu0 = 'true') or (./TomChannelInterrupt/TomIntEnableOnDutyCycleMatchCcu1 = 'true') )"!][!/*
*/!]extern void [!"./TomChannelInterrupt/TomNotification"!]
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
[!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
Evaluation of Atom Channels 
*/!][!LOOP "McuModuleConfiguration/*/GtmConfiguration/*[1]/Atom/*/AtomChannel/*"!][!/*
*/!][!IF "./AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!IF "./AtomChannelInterrupt/AtomGlobalCcuSel = 'false'"!][!/*
*/!][!IF "(./AtomChannelInterrupt/AtomNotification != 'NULL_PTR') and ((./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger = 'true') or (./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger = 'true') )"!][!/*
*/!]extern void [!"./AtomChannelInterrupt/AtomNotification"!]            \
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
[!ENDIF!][!/*[!IF "(./AtomChannelInterrupt/AtomNotification != 'NULL_PTR') and ((./AtomChannelInterrupt/AtomIntEnableOnCcu0Trigger = 'true') or (./AtomChannelInterrupt/AtomIntEnableOnCcu1Trigger = 'true') )"!]

*/!][!ELSE!][!/*
*/!]extern void [!"./AtomChannelInterrupt/AtomCcu0Notification"!]            \
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void [!"./AtomChannelInterrupt/AtomCcu1Notification"!]            \
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
[!/*	
*/!][!ENDIF!][!/*[!IF "./AtomChannelInterrupt/AtomGlobalCcuSel = 'true'"!]
*/!][!ENDIF!][!/*[!IF "./AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDLOOP!][!/*
Evaluation of Tim Channels 
*/!][!LOOP "McuModuleConfiguration/*/GtmConfiguration/*[1]/Tim/*/TimChannel/*"!][!/*
*/!][!VAR "NewValStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnNewVal)"!][!/*
*/!][!VAR "EcntOflStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnEcntOfl)"!][!/*
*/!][!VAR "CntOflStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnCntOfl)"!][!/*
*/!][!VAR "GprxOflStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGprxOfl)"!][!/*
*/!][!VAR "ToDetStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnToDet)"!][!/*
*/!][!VAR "GlitchDetStatus" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGlitchDet)"!][!/*
*/!][!VAR "TimEnable" = "node:value(./TimChannelGeneral/TimChannelUsage)"!][!/*
*/!][!IF "$TimEnable = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!IF "(./TimChannelInterrupt/TimNotification != 'NULL_PTR') and (($NewValStatus = 'true') or ($EcntOflStatus = 'true') or ($CntOflStatus = 'true') or ($GprxOflStatus = 'true') or ($ToDetStatus = 'true') or ($GlitchDetStatus = 'true'))"!][!/*
*/!]extern void [!"./TimChannelInterrupt/TimNotification"!]
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
[!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDMACRO!][!//
[!ENDIF!][!// IF "not(var:defined('GTM_M'))

