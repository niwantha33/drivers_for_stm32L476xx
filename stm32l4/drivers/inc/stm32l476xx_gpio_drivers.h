/*
 * stm32l476xx_gpio_drivers.h
 *
 *  Created on: Apr 8, 2023
 *  Author: Niwantha Meepage
 */

#ifndef INC_STM32L476XX_GPIO_DRIVERS_H_
#define INC_STM32L476XX_GPIO_DRIVERS_H_

#include "stm32l476xx.h"

/* GPIO_x characteristics */

typedef struct{

	uint8_t GPIO_PinNumber; /* pin numbers from @GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode; /* possible values from @GPIO_PIN_MODE */
	uint8_t GPIO_PinSpeed;	/* possible values from @GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;



// GPIO register map and reset values
typedef struct{
	__VO u32	MODER;
	__VO u32	OTYPER;
	__VO u32	OSPEEDR;
	__VO u32	PUPDR;
	__C  u32	IDR;
	__VO u32	ODR;
	__VO u32	BSRR;
	__VO u32	LCKR;
	__VO u32	AFRL;
	__VO u32	AFRH;
	__VO u32	BRR;
	__VO u32	ASCR;
}GPIO_RegDef_t;


// GPIO USER API Handler
typedef struct{

	GPIO_RegDef_t *pGPIOx; /*|< hold the base address of the GPIO >|*/
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;


// GPIO_X SPECIFIC MACROS

/*
 * @gpio_pin_numbers
 *
 */

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15


/*
 * @gpio_modes
 * @gpio_exti_interrupts
 *
 */

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ADC		3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

/*
 * @gpio_ot
 *
 */

#define GPIO_OP_TYPE_PP		0 // if this OT use  : @gpio_pullUD = GPIO_NO_PUPD
#define GPIO_OP_TYPE_OD		1

/*
 * @gpio_speed
 *
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*
 * @gpio_pullUD
 *
 */
#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/* |< API Designs >| */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx , uint8_t En_or_Di);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle);

// Data read and write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx );
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx ,  uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber);


// IRQ Configuration

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t En_or_Di);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32L476XX_GPIO_DRIVERS_H_ */
