################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32l476_gpio_drivers.c 

OBJS += \
./drivers/src/stm32l476_gpio_drivers.o 

C_DEPS += \
./drivers/src/stm32l476_gpio_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L476RGTx -c -I../Inc -I"/media/algobel/EXT4/udemy_uC/git_drivers_stm32L4/drivers_for_stm32L476xx/stm32l4/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32l476_gpio_drivers.cyclo ./drivers/src/stm32l476_gpio_drivers.d ./drivers/src/stm32l476_gpio_drivers.o ./drivers/src/stm32l476_gpio_drivers.su

.PHONY: clean-drivers-2f-src

