################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F796_ADC_DMA_DAC.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F796_ADC_DMA_DAC.list \


# All Target
all: F796_ADC_DMA_DAC.elf secondary-outputs

# Tool invocations
F796_ADC_DMA_DAC.elf: $(OBJS) $(USER_OBJS) /Users/JuliusKramer/Documents/STM32CudeIDE/F796_ADC_DMA_DAC/STM32F769NIHX_FLASH.ld
	arm-none-eabi-gcc -o "F796_ADC_DMA_DAC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"/Users/JuliusKramer/Documents/STM32CudeIDE/F796_ADC_DMA_DAC/STM32F769NIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F796_ADC_DMA_DAC.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F796_ADC_DMA_DAC.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F796_ADC_DMA_DAC.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
