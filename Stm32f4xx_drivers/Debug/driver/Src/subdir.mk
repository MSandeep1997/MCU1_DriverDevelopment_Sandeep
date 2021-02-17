################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/stm32f407xx_gpio_driver.c \
../driver/Src/stm32f407xx_spi_driver.c 

OBJS += \
./driver/Src/stm32f407xx_gpio_driver.o \
./driver/Src/stm32f407xx_spi_driver.o 

C_DEPS += \
./driver/Src/stm32f407xx_gpio_driver.d \
./driver/Src/stm32f407xx_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/stm32f407xx_gpio_driver.o: ../driver/Src/stm32f407xx_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/sande/Documents/Documents/documents/iitk/MCU1_Course/MCU1_COURSE/MCU1/Stm32f4xx_drivers/driver/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/Src/stm32f407xx_spi_driver.o: ../driver/Src/stm32f407xx_spi_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/sande/Documents/Documents/documents/iitk/MCU1_Course/MCU1_COURSE/MCU1/Stm32f4xx_drivers/driver/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_spi_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

