################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/%.o: ../Libraries/Drivers/CMSIS/DSP/Source/ComplexMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -DSTM32F107xC -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\arm" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Lib" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Core\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc\Legacy" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Middlewares\Third_Party\FatFs\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\STM32_SPI_SDCARD\Old_STM32F1\MDK-ARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\LCD" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32_My_API" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\src" --c99 -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


