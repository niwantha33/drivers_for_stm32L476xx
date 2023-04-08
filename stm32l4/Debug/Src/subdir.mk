################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/test_led.c 

OBJS += \
./Src/test_led.o 

C_DEPS += \
./Src/test_led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L476RGTx -c -I"/media/algobel/EXT4/udemy_uC/git_drivers_stm32L4/drivers_for_stm32L476xx/stm32l4/drivers" -I"/media/algobel/EXT4/udemy_uC/git_drivers_stm32L4/drivers_for_stm32L476xx/stm32l4/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/test_led.cyclo ./Src/test_led.d ./Src/test_led.o ./Src/test_led.su

.PHONY: clean-Src

