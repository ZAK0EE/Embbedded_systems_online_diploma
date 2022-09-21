################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.c 

OBJS += \
./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.o 

C_DEPS += \
./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/GPIO/%.o Stm32_F103C6_Drivers/GPIO/%.su: ../Stm32_F103C6_Drivers/GPIO/%.c Stm32_F103C6_Drivers/GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"E:/!Embedded/!STM/WriteDriver/HAL/inc" -I../Inc -I"E:/!Embedded/!STM/WriteDriver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Stm32_F103C6_Drivers-2f-GPIO

clean-Stm32_F103C6_Drivers-2f-GPIO:
	-$(RM) ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.d ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.o ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_gpio.su

.PHONY: clean-Stm32_F103C6_Drivers-2f-GPIO

