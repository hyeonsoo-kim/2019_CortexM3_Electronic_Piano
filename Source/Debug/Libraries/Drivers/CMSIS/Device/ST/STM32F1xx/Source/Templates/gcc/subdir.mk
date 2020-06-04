################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f100xb.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f100xe.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101x6.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xb.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xe.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xg.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f102x6.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f102xb.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103x6.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xe.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xg.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f105xc.s \
../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f107xc.s 

OBJS += \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f100xb.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f100xe.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101x6.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xb.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xe.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f101xg.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f102x6.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f102xb.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103x6.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xe.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xg.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f105xc.o \
./Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f107xc.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/%.o: ../Libraries/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Assembler 5'
	armasm --cpu=cortex-m3 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


