################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../asw/dataclasses/CDTMHandler/src/cdtmhandler.cpp 

CPP_DEPS += \
./asw/dataclasses/CDTMHandler/src/cdtmhandler.d 

OBJS += \
./asw/dataclasses/CDTMHandler/src/cdtmhandler.o 


# Each subdirectory must supply rules for building sources it contributes
asw/dataclasses/CDTMHandler/src/%.o: ../asw/dataclasses/CDTMHandler/src/%.cpp asw/dataclasses/CDTMHandler/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/config/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/emu_hw_timecode_drv/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/components/cchk_fdirmng/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/components/ccbkgtcexec/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/components/ccepdmanager/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/components/cctm_channelctrl/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/components/icuasw/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl_types/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/rtems_osswr/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEventList/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEvAction/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTCHandler/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMList/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/service_libraries/icuasw_pus_services/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/atcsol/git/OBDH-FIE-2024-IVA/asw_pus_19_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-asw-2f-dataclasses-2f-CDTMHandler-2f-src

clean-asw-2f-dataclasses-2f-CDTMHandler-2f-src:
	-$(RM) ./asw/dataclasses/CDTMHandler/src/cdtmhandler.d ./asw/dataclasses/CDTMHandler/src/cdtmhandler.o

.PHONY: clean-asw-2f-dataclasses-2f-CDTMHandler-2f-src

