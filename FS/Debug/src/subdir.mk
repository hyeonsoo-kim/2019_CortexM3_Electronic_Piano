################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/at24c02.c \
../src/buzzer.c \
../src/can.c \
../src/dac.c \
../src/diskio.c \
../src/ds1302.c \
../src/ds18b20.c \
../src/ff.c \
../src/font.c \
../src/hw_config.c \
../src/icon.c \
../src/iic.c \
../src/ili93xx.c \
../src/key.c \
../src/lcd.c \
../src/lcd12864.c \
../src/lcd1602.c \
../src/lcd28.c \
../src/lcd32.c \
../src/lcd43.c \
../src/lcd70.c \
../src/led.c \
../src/main.c \
../src/mmc_sd.c \
../src/nrf24l01.c \
../src/queue.c \
../src/rs485.c \
../src/rtc.c \
../src/sccb.c \
../src/spi.c \
../src/stm32f10x_it.c \
../src/timer.c \
../src/touch.c \
../src/usart.c \
../src/usb_desc.c \
../src/usb_istr.c \
../src/usb_prop.c \
../src/usb_pwr.c \
../src/vs1003b.c 

OBJS += \
./src/adc.o \
./src/at24c02.o \
./src/buzzer.o \
./src/can.o \
./src/dac.o \
./src/diskio.o \
./src/ds1302.o \
./src/ds18b20.o \
./src/ff.o \
./src/font.o \
./src/hw_config.o \
./src/icon.o \
./src/iic.o \
./src/ili93xx.o \
./src/key.o \
./src/lcd.o \
./src/lcd12864.o \
./src/lcd1602.o \
./src/lcd28.o \
./src/lcd32.o \
./src/lcd43.o \
./src/lcd70.o \
./src/led.o \
./src/main.o \
./src/mmc_sd.o \
./src/nrf24l01.o \
./src/queue.o \
./src/rs485.o \
./src/rtc.o \
./src/sccb.o \
./src/spi.o \
./src/stm32f10x_it.o \
./src/timer.o \
./src/touch.o \
./src/usart.o \
./src/usb_desc.o \
./src/usb_istr.o \
./src/usb_prop.o \
./src/usb_pwr.o \
./src/vs1003b.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\src" -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


