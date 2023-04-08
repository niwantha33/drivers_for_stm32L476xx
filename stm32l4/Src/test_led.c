/*
 * test_led.c
 *
 *  Created on: Apr 8, 2023
 *      Author: algobel
 */

#include "stm32l476xx.h"

u8 button(u8 buttonNumber) {

}

int main(void) {
	GPIO_Handle_t builtLED = { 0 };

	// LED ic connected to PA5
	builtLED.pGPIOx = GPIOA;
	builtLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	builtLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&builtLED);
	GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, ENABLE);

	/*
	 * Button
	 *
	 *
	 */

	GPIO_Handle_t button = { 0 };
	button.pGPIOx = GPIOC;

	button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&button);

	while (1) {
//		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

//		for (uint32_t i = 0; i < 50000; i++);
		// Black button
		u8 b = GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13);
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, b);


	}

	return 0;
}
