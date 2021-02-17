################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/004led_button_interrupt.c 

OBJS += \
./Src/004led_button_interrupt.o 

C_DEPS += \
./Src/004led_button_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Src/004led_button_interrupt.o: ../Src/004led_button_interrupt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/sande/Documents/Documents/documents/iitk/MCU1_Course/MCU1_COURSE/MCU1/Stm32f4xx_drivers/driver/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/004led_button_interrupt.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

