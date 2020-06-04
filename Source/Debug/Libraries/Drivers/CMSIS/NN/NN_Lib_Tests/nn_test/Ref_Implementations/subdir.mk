################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q15_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q15_ref_nonsquare.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q7_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q7_ref_nonsquare.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_depthwise_separable_conv_HWC_q7_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_depthwise_separable_conv_HWC_q7_ref_nonsquare.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_mat_q7_vec_q15_opt_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_mat_q7_vec_q15_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q15_opt_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q15_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q7_opt_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q7_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_nn_mult_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_pool_ref.c \
../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_relu_ref.c 

OBJS += \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q15_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q15_ref_nonsquare.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q7_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_convolve_HWC_q7_ref_nonsquare.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_depthwise_separable_conv_HWC_q7_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_depthwise_separable_conv_HWC_q7_ref_nonsquare.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_mat_q7_vec_q15_opt_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_mat_q7_vec_q15_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q15_opt_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q15_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q7_opt_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_fully_connected_q7_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_nn_mult_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_pool_ref.o \
./Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/arm_relu_ref.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/%.o: ../Libraries/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/Ref_Implementations/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -DSTM32F107xC -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\arm" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Lib" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\CMSIS\Core\Include" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Inc\Legacy" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Drivers\STM32F1xx_HAL_Driver\Src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\EWARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\Middlewares\Third_Party\FatFs\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\STM32_SPI_SDCARD\Old_STM32F1\MDK-ARM" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\LCD" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32_My_API" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\Source\Libraries\STM32F10x_StdPeriph_Driver_v3.5\src" --c99 -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


