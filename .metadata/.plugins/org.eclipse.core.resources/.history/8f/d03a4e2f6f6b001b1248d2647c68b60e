/*
 * 001led_toggling.c
 *
 *  Created on: 10-Feb-2021
 *      Author: sande
 */
#include"stm32f407xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000/4; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	//enable clock initialization

	GPIO_PeriClockControl(GPIOD, ENABLE);

	//Call the API

	GPIO_Init(&GpioLed);

	while(1)
	{

		//toggle coomand

		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();

	}

	return 0;
}
