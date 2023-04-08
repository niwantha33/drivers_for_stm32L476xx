/*
 * stm32l476_gpio_drivers.c
 *
 *  Created on: Apr 8, 2023
 *      Author: algobel
 */

#include "stm32l476xx.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, const u8 state) {
	if (state == ENABLE) {

		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_EN();
		}

	}

}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ADC) {
		u32 temp = 0;
		/* |< MODE SETTING >| */
		temp =
				~((u32) 0b11 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		pGPIOHandle->pGPIOx->MODER &= temp; // Example: clear PA5

		// SET
		pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode
				<< (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		/* |< MODE SETTING >| */

		temp = 0;

		temp = ~((u32) 0b1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		pGPIOHandle->pGPIOx->OTYPER &= temp; // Example: clear PA5

		// SET
		pGPIOHandle->pGPIOx->OTYPER |=
				(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType
						<< (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		temp = 0;

		temp = ~((u32) 0b11 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		pGPIOHandle->pGPIOx->OSPEEDR &= temp; // Example: clear PA5

		// SET
		pGPIOHandle->pGPIOx->OSPEEDR |=
				(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed
						<< (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		temp = 0;

		temp = ~((u32) 0b11 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		pGPIOHandle->pGPIOx->PUPDR &= temp; // Example: clear PA5

		// SET
		pGPIOHandle->pGPIOx->PUPDR |=
				(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl
						<< (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

//		temp = 0;
//
//		temp = ~((u32) 0b1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
//
//		pGPIOHandle->pGPIOx->ODR &= temp; // Example: clear PA5
//
//		// SET
//		pGPIOHandle->pGPIOx->ODR |=
//				(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType
//						<< (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	}
}
void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle) {

}

// Data read and write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	u8 temp;

	temp = (u8) ((pGPIOx->IDR >> PinNumber) & 0b1);

	return temp;

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) {

}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t value) {

	if (value == GPIO_PIN_SET) {

		pGPIOx->ODR |=  (1U << PinNumber);

	} else {

		pGPIOx->ODR &= ~(1U << PinNumber);

	}



}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value) {

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	pGPIOx->ODR ^=  (1U << PinNumber);

}

// IRQ Configuration

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t En_or_Di) {

}
void GPIO_IRQHandling(uint8_t PinNumber) {

}

#include "stm32l476xx_gpio_drivers.h"
