################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/abs_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/add_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/basic_math_test_common_data.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/basic_math_test_group.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/dot_prod_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/mult_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/negate_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/offset_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/scale_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/shift_tests.c \
../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/sub_tests.c 

OBJS += \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/abs_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/add_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/basic_math_test_common_data.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/basic_math_test_group.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/dot_prod_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/mult_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/negate_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/offset_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/scale_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/shift_tests.o \
./Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/sub_tests.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/%.o: ../Libraries/Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/basic_math_tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -DSTM32F107xC -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\arm" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Lib" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Core\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc\Legacy" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Middlewares\Third_Party\FatFs\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\STM32_SPI_SDCARD\Old_STM32F1\MDK-ARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\LCD" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32_My_API" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\src" --c99 -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


