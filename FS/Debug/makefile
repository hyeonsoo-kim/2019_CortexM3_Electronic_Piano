################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include STM32_USB-FS-Device_Driver/src/subdir.mk
-include STM32F10x_StdPeriph_Driver_v3.5/src/subdir.mk
-include CMSIS/DeviceSupport/Startup/subdir.mk
-include CMSIS/DeviceSupport/subdir.mk
-include CMSIS/CoreSupport/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FS.axf

# Tool invocations
FS.axf: $(OBJS)  $(USER_OBJS) $(LIBS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker 5'
	armlink --info=sizes -o "FS.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS) $(EXECUTABLES) FS.axf 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
