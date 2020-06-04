################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_USB-FS-Device_Driver/src/otgd_fs_cal.c \
../STM32_USB-FS-Device_Driver/src/otgd_fs_dev.c \
../STM32_USB-FS-Device_Driver/src/otgd_fs_int.c \
../STM32_USB-FS-Device_Driver/src/otgd_fs_pcd.c \
../STM32_USB-FS-Device_Driver/src/usb_core.c \
../STM32_USB-FS-Device_Driver/src/usb_init.c \
../STM32_USB-FS-Device_Driver/src/usb_int.c \
../STM32_USB-FS-Device_Driver/src/usb_mem.c \
../STM32_USB-FS-Device_Driver/src/usb_regs.c \
../STM32_USB-FS-Device_Driver/src/usb_sil.c 

OBJS += \
./STM32_USB-FS-Device_Driver/src/otgd_fs_cal.o \
./STM32_USB-FS-Device_Driver/src/otgd_fs_dev.o \
./STM32_USB-FS-Device_Driver/src/otgd_fs_int.o \
./STM32_USB-FS-Device_Driver/src/otgd_fs_pcd.o \
./STM32_USB-FS-Device_Driver/src/usb_core.o \
./STM32_USB-FS-Device_Driver/src/usb_init.o \
./STM32_USB-FS-Device_Driver/src/usb_int.o \
./STM32_USB-FS-Device_Driver/src/usb_mem.o \
./STM32_USB-FS-Device_Driver/src/usb_regs.o \
./STM32_USB-FS-Device_Driver/src/usb_sil.o 


# Each subdirectory must supply rules for building sources it contributes
STM32_USB-FS-Device_Driver/src/%.o: ../STM32_USB-FS-Device_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32_USB-FS-Device_Driver\src" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\CoreSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\CMSIS\DeviceSupport\Startup" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\inc" -I"C:\Users\Team03\Desktop\2019_Embeded_System_Design_and_Experiment\Term\FS\STM32F10x_StdPeriph_Driver_v3.5\src" -O2 --cpu=cortex-m3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


