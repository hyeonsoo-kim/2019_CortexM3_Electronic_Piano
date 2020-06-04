################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/CoreSupport/core_cm3.c 

OBJS += \
./CMSIS/CoreSupport/core_cm3.o 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/CoreSupport/%.o: ../CMSIS/CoreSupport/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\src" -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


