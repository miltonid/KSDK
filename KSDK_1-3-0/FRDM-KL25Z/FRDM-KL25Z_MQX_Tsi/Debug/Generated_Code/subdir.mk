################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/MainTask.c \
../Generated_Code/Task1.c \
../Generated_Code/clockMan1.c \
../Generated_Code/fsl_hwtimer1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/mqx_ksdk.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c \
../Generated_Code/tsi1.c \
../Generated_Code/uart1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/MainTask.o \
./Generated_Code/Task1.o \
./Generated_Code/clockMan1.o \
./Generated_Code/fsl_hwtimer1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/mqx_ksdk.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o \
./Generated_Code/tsi1.o \
./Generated_Code/uart1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/MainTask.d \
./Generated_Code/Task1.d \
./Generated_Code/clockMan1.d \
./Generated_Code/fsl_hwtimer1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/mqx_ksdk.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d \
./Generated_Code/tsi1.d \
./Generated_Code/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_MQX" -D"PEX_MQX_KSDK" -I"/home/milton/Freescale/KSDK1.3/platform/hal/inc" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/sim/MKL25Z4" -I"/home/milton/Freescale/KSDK1.3/platform/system/src/clock/MKL25Z4" -I"/home/milton/Freescale/KSDK1.3/platform/system/inc" -I"/home/milton/Freescale/KSDK1.3/platform/osa/inc" -I"/home/milton/Freescale/KSDK1.3/platform/CMSIS/Include" -I"/home/milton/Freescale/KSDK1.3/platform/devices" -I"/home/milton/Freescale/KSDK1.3/platform/devices/MKL25Z4/include" -I"/home/milton/Freescale/KSDK1.3/platform/utilities/src" -I"/home/milton/Freescale/KSDK1.3/platform/utilities/inc" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/SDK/platform/devices/MKL25Z4/startup" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Sources" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/inc" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/cpu" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/config/common" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/bsp" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/src" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/fs" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_dummy" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_serial" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx/source/nio/drivers/nio_tty" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx_stdlib/source/include" -I"/home/milton/Freescale/KSDK1.3/rtos/mqx/mqx_stdlib/source/stdio" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/uart" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/src/uart" -I"/home/milton/Freescale/KSDK1.3/platform/hal/src/lpsci" -I"/home/milton/Freescale/KSDK1.3/platform/drivers/src/lpsci" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/board" -I"/home/milton/Documents/GitHub/KSDK/KSDK_1-3-0/FRDM-KL25Z/FRDM-KL25Z_MQX_Tsi/Generated_Code/SDK/rtos/mqx/config/mcu" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


