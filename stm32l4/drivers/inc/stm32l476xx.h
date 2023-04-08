/*
 * stm32l476xx.h
 *
 *  Created on: Apr 8, 2023
 *      Author: algobel
 */

#ifndef INC_STM32L476XX_H_
#define INC_STM32L476XX_H_
#include "stdint.h"

// customized typedef

#define u32							uint32_t
#define u16							uint16_t
#define u8							uint8_t

// special qualifiers

#define __VO						volatile
#define __C							const
#define __VC						volatile const

/*|< 2.2.2 Memory map and register boundary addresses >| */

/* |<   >| */

/* |< Flash, system memory , or SRAM, depending on ,BOOT configuration  >| */

#define BOOT_CONFIG					0x0000000U

#define FLASH_BASE_ADDR				0x08000000U /* end: 0x0810 0000 */
#define SRAM1_BASE_ADDR				0x20000000U
#define SRAM2_BASE_ADDR				0x10000000U
#define SRAM						SRAM1_BASE_ADDR
#define ROM							0x1FFF0000U /* System Memory */

/*
 * @memory_map
 * +++++++++++++++++++
 * Advanced Peripheral Bus (APB) and Advanced High Performance Bus (AHB)
 * Peripherals : APB1, APB2, AHB1, AHB2
 */
#define PERIPHERAL_BASE_ADDR		0x40000000U

/*
 * @connected_peri
 * Connected peripherals:
 * TIM2-7, LCD, RTC, WWDG, IWDG, SPI2, SPI3, USART2, USART3, UART4,UART5
 * I2C1, I2C2,I2C3,CAN1,PWR,DAC1,OPAMP,LPTIM1, LPUART1, SWPM1, LPTIM2
 * AP1 : MAx 80MHz
 */

#define APB1_PERIPHRAL_BASE			PERIPHERAL_BASE_ADDR // end: - 0x4000 FFFF

// SYSCFG, VREFBUF, COMP, EXTI, FIREWALL, SDMMC1, TIM1, SPI1,TIM8, USART1, TIM15, TIM16, TIM17, SAI1, SAI2, DFSDM1
// AP2 : MAx 80MHz
#define APB2_PERIPHRAL_BASE			0x40010000U  // End : 0x4001 3FFF

// DMA1, DMA2, RCC, FLASH, CRC, TSC
#define AHB1_PERIPHRAL_BASE			0x40020000U

// GPIO(A) - (H), OTG_FS, ADC, AES, RNG
#define AHB2_PERIPHRAL_BASE			(u32)0x48000000U

/* Reset & Clock control register */

#define RCC_BASE_ADDR				(AHB1_PERIPHRAL_BASE + 0x1000U)


/*
 * @rcc_map
 * Page:278 Table 34. RCC register map and reset values
 *
 * added reserved 1 - 6
*/
typedef struct{

	__VO u32 CR;
	__VO u32 ICSCR;
	__VO u32 CFGR;
	__VO u32 PLLCFGR;
	__VO u32 PLLSAI1CFGR;
	__C	 u32 RESERVED0;
	__VO u32 PLLSAI2CFGR;
	__VO u32 CIER;
	__VO u32 CIFR;
	__VO u32 CICR;/// reserved
	__C	 u32 RESERVED1;
	__VO u32 AHB1RSTR;
	__VO u32 AHB2RSTR;
	__VO u32 AHB3RSTR;
	__VO u32 APB1RSTR1;
	__VO u32 APB1RSTR2;
	__VO u32 APB2RSTR;
	__C	 u32 RESERVED2;
	__VO u32 AHB1ENR; // FLASHEN,
	__VO u32 AHB2ENR; // AHB2 peripheral clock enable register (RCC_AHB2ENR)
	__VO u32 AHB3ENR;
	__C	 u32 RESERVED3;
	__VO u32 APB1ENR1; // I2C1-3, USART2-3, UART4-5, SPI3-2, CAN1EN, PWREN
	__VO u32 APB1ENR2; // I2C4, LPUART1
	__VO u32 APB2ENR; //  SAI1-2, USART1, SPI1, SYSCFEN
	__C	 u32 RESERVED4;
	__VO u32 AHB1SMENR;
	__VO u32 AHB2SMENR;
	__VO u32 AHB3SMENR;
	__C	 u32 RESERVED5;
	__VO u32 APB1SMENR5;
	__VO u32 APB1SMENR2;
	__VO u32 APB2SMENR;
	__C	 u32 RESERVED6;
	__VO u32 CCIPR;
	__VO u32 BDCR;
	__VO u32 CSR;

}RCC_RegDef_t;


#define RCC							((RCC_RegDef_t *)RCC_BASE_ADDR)

#define GPIOA_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x0000U)
#define GPIOB_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x0400U)
#define GPIOC_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x0800U)
#define GPIOD_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x0C00U)
#define GPIOE_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x1000U)
#define GPIOF_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x1400U)
#define GPIOG_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x1800U)
#define GPIOH_BASE_ADDR				(AHB2_PERIPHRAL_BASE + 0x1C00U)

/* Enable clock - RCC */
#define GPIOA_PCLK_EN()		(RCC->AHB2ENR |= (1U << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB2ENR |= (1U << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB2ENR |= (1U << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB2ENR |= (1U << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB2ENR |= (1U << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB2ENR |= (1U << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB2ENR |= (1U << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB2ENR |= (1U << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB2ENR |= (1U << 8))

// GPIO_X
#define GPIOA					((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t *)GPIOD_BASE_ADDR)
#define GPIOE					((GPIO_RegDef_t *)GPIOE_BASE_ADDR)
#define GPIOF					((GPIO_RegDef_t *)GPIOF_BASE_ADDR)
#define GPIOG					((GPIO_RegDef_t *)GPIOG_BASE_ADDR)
#define GPIOH					((GPIO_RegDef_t *)GPIOH_BASE_ADDR)
#define GPIOI					((GPIO_RegDef_t *)GPIOI_BASE_ADDR)


/* |<  bit to 1 and then immediately clearing it to 0 >|*/
#define GPIOA_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 0); RCC->AHB2RSRTR &= (~(0b1 << 0));}while(0)})
#define GPIOB_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 1); RCC->AHB2RSRTR &= (~(0b1 << 1));}while(0)})
#define GPIOC_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 2); RCC->AHB2RSRTR &= (~(0b1 << 2));}while(0)})
#define GPIOD_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 3); RCC->AHB2RSRTR &= (~(0b1 << 3));}while(0)})
#define GPIOE_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 4); RCC->AHB2RSRTR &= (~(0b1 << 4));}while(0)})
#define GPIOF_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 5); RCC->AHB2RSRTR &= (~(0b1 << 5));}while(0)})
#define GPIOG_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 6); RCC->AHB2RSRTR &= (~(0b1 << 6));}while(0)})
#define GPIOH_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 7); RCC->AHB2RSRTR &= (~(0b1 << 7));}while(0)})
#define GPIOI_RESET_PIN		(do{RCC->AHB2RSTR |= (1U << 8); RCC->AHB2RSRTR &= (~(0b1 << 8));}while(0)})





// APB1 - I2C
#define I2C1_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x5400U)
#define I2C2_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x5800U)
#define I2C3_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x5C00U)

#define SPI1_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x3800U)
#define SPI2_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x3C00U)

#define USART2_BASE_ADDR			(APB1_PERIPHRAL_BASE + 0x4400U)
#define USART3_BASE_ADDR			(APB1_PERIPHRAL_BASE + 0x4800U)
#define UART4_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x4C00U)
#define UART5_BASE_ADDR				(APB1_PERIPHRAL_BASE + 0x5000U)

// APB2
#define	SYSCFG_BASE_ADDR			(APB2_PERIPHRAL_BASE + 0x0000U)
#define	EXTI_BASE_ADDR				(APB2_PERIPHRAL_BASE + 0x0400U)
#define	SP11_BASE_ADDR				(APB2_PERIPHRAL_BASE + 0x3000U)
#define	USART1_BASE_ADDR			(APB2_PERIPHRAL_BASE + 0x3800U)

/* common MACROS* */
#define ENABLE						1
#define DISABLE						0
#define SET							ENABLE
#define RESET						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET

#include "stm32l476xx_gpio_drivers.h"
#endif /* INC_STM32L476XX_H_ */
