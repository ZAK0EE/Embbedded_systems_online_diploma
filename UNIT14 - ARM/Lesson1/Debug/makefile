################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
WriteDriver.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
WriteDriver.list \

OBJCOPY_BIN += \
WriteDriver.bin \


# All Target
all: WriteDriver.axf secondary-outputs

# Tool invocations
WriteDriver.axf: $(OBJS) $(USER_OBJS) D:\Embedded\ course\Embedded_system_online_diploma\UNIT14\ -\ ARM\Lesson1\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "WriteDriver.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Embedded course\Embedded_system_online_diploma\UNIT14 - ARM\Lesson1\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="WriteDriver.map" -Wl,--gc-sections -static -gdwarf-2 --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	arm-none-eabi-objdump -D WriteDriver.axf > ARMASM.s
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

WriteDriver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "WriteDriver.list"
	@echo 'Finished building: $@'
	@echo ' '

WriteDriver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "WriteDriver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
