################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.c 

OBJS += \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/%.o: ../Libraries/Drivers/CMSIS/DSP/Source/StatisticsFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -DSTM32F107xC -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\arm" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Lib" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Core\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc\Legacy" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Middlewares\Third_Party\FatFs\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\STM32_SPI_SDCARD\Old_STM32F1\MDK-ARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\LCD" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32_My_API" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\src" --c99 -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


