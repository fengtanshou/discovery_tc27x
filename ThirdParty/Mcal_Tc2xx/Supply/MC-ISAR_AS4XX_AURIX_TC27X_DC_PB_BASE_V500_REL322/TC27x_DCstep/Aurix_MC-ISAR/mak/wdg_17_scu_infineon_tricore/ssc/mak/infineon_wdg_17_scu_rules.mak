#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2012)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_wdg_17_scu_rules.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2012.11.02                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the WDG driver             **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* AD          Abhishek Dwivedi                                              ** 
#* RS          Roopa Sirur                                                   **
#* MK          Mundhra Karan                                                 **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.4 : 2012.11.02, MK  : Multi compiler support changes
#*  V0.0.3 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.2 : 2007.09.19, RS  : Only SSC based files should be compiled in this mak
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(WDG_DEP_HEADERS)
WDG_INC_PATHS_FILE = wdg_include_paths.ifx


build_wdg_driver : info wdgincpaths $(WDG_SSC_OBJECTS) 
$(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu.$(OBJ_FILE_SUFFIX) : $(WDG_BASE_PATH)\ssc\src\Wdg_17_Scu.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_WDG) $(OUTPUT) $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(WDG_INC_PATHS_FILE)  $(OBJ_CREATION)  $(WDG_BASE_PATH)\ssc\src\Wdg_17_Scu.c  $(ERROR_REPORT) 
	@-rm -f $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu.ers 
 
$(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu_Safe.$(OBJ_FILE_SUFFIX) : $(WDG_BASE_PATH)\ssc\src\Wdg_17_Scu_Safe.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_WDG) $(OUTPUT) $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu_Safe.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(WDG_INC_PATHS_FILE)  $(OBJ_CREATION)  $(WDG_BASE_PATH)\ssc\src\Wdg_17_Scu_Safe.c  $(ERROR_REPORT) 
	@-rm -f $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu_Safe.ers 
  
 

print:
	@echo $(WDG_SSC_OBJECTS) 
	
wdgincpaths:
	@echo $(STANDARD_INCLUDE) > $(WDG_INC_PATHS_FILE)
	@echo $(WDG_INCLUDE_PATH) >> $(WDG_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(WDG_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(WDG_INC_PATHS_FILE)	
info: 
	@echo -------------Compiling WDG Module---------------

