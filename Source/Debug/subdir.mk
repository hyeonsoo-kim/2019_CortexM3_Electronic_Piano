################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd_test2.c \
../main.c 

OBJS += \
./lcd_test2.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -DSTM32F107xC -DDEBUG -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\LCD" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32_My_API" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\src" --c99 -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


