################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KSDK_Files/board.c \
../KSDK_Files/gpio_pins.c \
../KSDK_Files/pin_mux.c 

OBJS += \
./KSDK_Files/board.o \
./KSDK_Files/gpio_pins.o \
./KSDK_Files/pin_mux.o 

C_DEPS += \
./KSDK_Files/board.d \
./KSDK_Files/gpio_pins.d \
./KSDK_Files/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
KSDK_Files/%.o: ../KSDK_Files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DCPU_MK64FN1M0VMD12=1 -DFSL_RTOS_MQX=1 -D_AEABI_LC_CTYPE=C -D__STRICT_ANSI__=1 -D_DEBUG=1 -I"../Sources" -I../BSP_Files -I../Config_Files -I../Config_Files/Common -I../Debug_Console -I../KSDK_Files -IC:\Freescale\KSDK_1.2.0\platform\devices\MK64F12\startup -IC:\Freescale\KSDK_1.2.0\platform\devices\MK64F12\include -IC:\Freescale\KSDK_1.2.0\platform -IC:\Freescale\KSDK_1.2.0\platform\devices -IC:\Freescale\KSDK_1.2.0\platform\CMSIS\Include -IC:\Freescale\KSDK_1.2.0\platform\hal\inc -IC:\Freescale\KSDK_1.2.0\platform\drivers\inc -IC:\Freescale\KSDK_1.2.0\platform\drivers\src\mpu -IC:\Freescale\KSDK_1.2.0\platform\drivers\src\uart -IC:\Freescale\KSDK_1.2.0\platform\utilities\inc -IC:\Freescale\KSDK_1.2.0\platform\osa\inc -IC:\Freescale\KSDK_1.2.0\platform\system\inc -IC:\Freescale\KSDK_1.2.0\rtos\mqx\mqx\source\include -IC:\Freescale\KSDK_1.2.0\rtos\mqx\lib\frdmk64f.kds\debug\config -IC:\Freescale\KSDK_1.2.0\rtos\mqx\lib\frdmk64f.kds\debug\mqx -IC:\Freescale\KSDK_1.2.0\rtos\mqx\lib\frdmk64f.kds\debug\mqx_stdlib -std=gnu99 -fno-strict-aliasing -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


