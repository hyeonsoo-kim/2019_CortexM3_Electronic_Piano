################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F10x_StdPeriph_Driver_v3.5/src/misc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_adc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_bkp.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_can.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_cec.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_crc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dac.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dbgmcu.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dma.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_exti.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_flash.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_fsmc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_gpio.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_i2c.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_iwdg.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_pwr.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_rcc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_rtc.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_sdio.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_spi.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_tim.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_usart.c \
../STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_wwdg.c 

OBJS += \
./STM32F10x_StdPeriph_Driver_v3.5/src/misc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_adc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_bkp.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_can.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_cec.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_crc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dac.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dbgmcu.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_dma.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_exti.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_flash.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_fsmc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_gpio.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_i2c.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_iwdg.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_pwr.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_rcc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_rtc.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_sdio.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_spi.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_tim.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_usart.o \
./STM32F10x_StdPeriph_Driver_v3.5/src/stm32f10x_wwdg.o 


# Each subdirectory must supply rules for building sources it contributes
STM32F10x_StdPeriph_Driver_v3.5/src/%.o: ../STM32F10x_StdPeriph_Driver_v3.5/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\src" -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


