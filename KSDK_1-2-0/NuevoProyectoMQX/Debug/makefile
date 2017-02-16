################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/subdir.mk
-include KSDK_Files/subdir.mk
-include Debug_Console/subdir.mk
-include BSP_Files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: NuevoProyectoMQX.elf secondary-outputs

# Tool invocations
NuevoProyectoMQX.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "C:\Freescale\KSDK_1.2.0\platform\devices\MK64F12\linker\gcc\MK64FN1M0xxx12_flash.ld" -nostartfiles -nodefaultlibs -Xlinker --gc-sections -LC:\Freescale\KSDK_1.2.0\lib\ksdk_mqx_lib\kds\K64F12\debug -LC:\Freescale\KSDK_1.2.0\rtos\mqx\lib\frdmk64f.kds\debug\mqx_stdlib -LC:\Freescale\KSDK_1.2.0\rtos\mqx\lib\frdmk64f.kds\debug\mqx -Wl,-Map,"NuevoProyectoMQX.map" -Xlinker --cref -Xlinker -static  -Xlinker -z -Xlinker muldefs  -Xlinker --undefined=__isr_vector  -Xlinker --defsym=__stack_size__=0x400  -Xlinker --defsym=__heap_size__=0x200 -o "NuevoProyectoMQX.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(S_UPPER_DEPS) NuevoProyectoMQX.elf
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
