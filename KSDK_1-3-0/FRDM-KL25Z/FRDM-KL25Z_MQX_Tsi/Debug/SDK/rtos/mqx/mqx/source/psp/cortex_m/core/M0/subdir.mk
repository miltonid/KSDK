################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0/boot.S \
/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0/dispatch.S 

OBJS += \
./SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/boot.o \
./SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/dispatch.o 

S_UPPER_DEPS += \
./SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/boot.d \
./SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/dispatch.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/boot.o: /home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0/boot.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -D"FSL_RTOS_MQX" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/config/common" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/mcu" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/rtos/mqx/mqx/source/psp/cortex_m/core/M0/dispatch.o: /home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0/dispatch.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -D"FSL_RTOS_MQX" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/core/M0" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/config/common" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/mcu" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


