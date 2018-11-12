#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2007)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_crc_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.09.13                                                    **
#*                                                                            **
#*                                                                            **                                                                            
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the CRC driver             **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* KP           Kaushal Purohit                                              **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1:  2012.09.13, KP  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_defs.mak


#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(CRC_DEP_HEADERS) 
CRC_INC_PATHS_FILE = crc_include_paths.ifx 

build_crc_driver : info incpaths $(CRC_SSC_OBJECTS)


$(CRC_BASE_PATH)/ssc/obj/Crc.$(OBJ_FILE_SUFFIX) : $(CRC_BASE_PATH)\ssc\src\Crc.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(CRC_BASE_PATH)\ssc\inc\Crc_Protect.h
	@$(COMPILE_CRC) $(OUTPUT) $(CRC_BASE_PATH)/ssc/obj/Crc.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(CRC_INC_PATHS_FILE) $(OBJ_CREATION) $(CRC_BASE_PATH)\ssc\src\Crc.c  $(ERROR_REPORT)
	@-rm -f $(CRC_BASE_PATH)/ssc/obj/Crc.ers


#.PHONY: clean
#clean:
#	@-rm -f $(CRC_OBJECTS)

#.PHONY: wipe
#wipe:
#	@-rm -f *.src
#	@-rm -f *.err

print:
	@echo $(CRC_OBJECTS)
incpaths:
	@echo $(STANDARD_INCLUDE) > $(CRC_INC_PATHS_FILE)
	@echo $(CRC_INCLUDE_PATH) >> $(CRC_INC_PATHS_FILE)
	
info: 
	@echo -------------Compiling CRC Module---------------
