################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32WG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ADC_MADRE.axf

# Tool invocations
ADC_MADRE.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "ADC_MADRE.ld" -Xlinker --gc-sections -Xlinker -Map="ADC_MADRE.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o ADC_MADRE.axf "./CMSIS/EFM32WG/startup_efm32wg.o" "./CMSIS/EFM32WG/system_efm32wg.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_int.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./src/epsilometer_CMU_init.o" "./src/epsilometer_GPIO_init.o" "./src/epsilometer_TIMER_init.o" "./src/epsilometer_analog.o" "./src/epsilometer_main.o" "./src/epsilometer_menu.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: ADC_MADRE.hex'
	arm-none-eabi-objcopy -O ihex "ADC_MADRE.axf" "ADC_MADRE.hex"
	@echo ' '

	@echo 'Building bin file: ADC_MADRE.bin'
	arm-none-eabi-objcopy -O binary "ADC_MADRE.axf" "ADC_MADRE.bin"
	@echo ' '

	@echo 'Building s37 file: ADC_MADRE.s37'
	arm-none-eabi-objcopy -O srec "ADC_MADRE.axf" "ADC_MADRE.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "ADC_MADRE.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ADC_MADRE.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
