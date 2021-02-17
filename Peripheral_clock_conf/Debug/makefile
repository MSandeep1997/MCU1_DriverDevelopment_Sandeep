################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
Peripheral_clock_conf.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Peripheral_clock_conf.list \

OBJCOPY_BIN += \
Peripheral_clock_conf.bin \


# All Target
all: Peripheral_clock_conf.elf secondary-outputs

# Tool invocations
Peripheral_clock_conf.elf: $(OBJS) $(USER_OBJS) C:\Users\sande\Documents\Documents\documents\iitk\MCU1_Course\MCU1_COURSE\MCU1\Peripheral_clock_conf\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "Peripheral_clock_conf.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\sande\Documents\Documents\documents\iitk\MCU1_Course\MCU1_COURSE\MCU1\Peripheral_clock_conf\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Peripheral_clock_conf.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Peripheral_clock_conf.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Peripheral_clock_conf.list"
	@echo 'Finished building: $@'
	@echo ' '

Peripheral_clock_conf.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Peripheral_clock_conf.bin"
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
