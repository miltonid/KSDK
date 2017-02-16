################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/milton/Freescale/KSDK1.3/platform/hal/src/osc/fsl_osc_hal.c 

OBJS += \
./SDK/platform/hal/src/osc/fsl_osc_hal.o 

C_DEPS += \
./SDK/platform/hal/src/osc/fsl_osc_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/osc/fsl_osc_hal.o: /home/milton/Freescale/KSDK1.3/platform/hal/src/osc/fsl_osc_hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_MQX" -D"PEX_MQX_KSDK" -I"/home/milton/Freescale/KSDK1.3/platform/hal/inc" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/sim/MKL25Z4" -I"/home/milton/Freescale/KSDK1.3/platform/system/src/clock/MKL25Z4" -I"/home/milton/Freescale/KSDK1.3/platform/system/inc" -I"/home/milton/Freescale/KSDK1.3/platform/osa/inc" -I"/home/milton/Freescale/KSDK1.3/platform/CMSIS/Include" -I"/home/milton/Freescale/KSDK1.3/platform/devices" -I"/home/milton/Freescale/KSDK1.3/platform/devices/MKL25Z4/include" -I"/home/milton/Freescale/KSDK1.3/platform/utilities/src" -I"/home/milton/Freescale/KSDK1.3/platform/utilities/inc" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/SDK/platform/devices/MKL25Z4/startup" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Sources" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/inc" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/cpu" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/config/common" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/bsp" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/src" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/fs" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_dummy" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_serial" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_tty" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx_stdlib/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx_stdlib/source/stdio" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/uart" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/src/uart" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/lpsci" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/src/lpsci" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/board" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/mcu" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


