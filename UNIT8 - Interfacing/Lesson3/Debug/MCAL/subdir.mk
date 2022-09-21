################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32_F103C6_EXTI.c \
../MCAL/Stm32_F103C6_GPIO.c \
../MCAL/Stm32_F103C6_RCC.c \
../MCAL/Stm32_F103C6_USART.c 

OBJS += \
./MCAL/Stm32_F103C6_EXTI.o \
./MCAL/Stm32_F103C6_GPIO.o \
./MCAL/Stm32_F103C6_RCC.o \
./MCAL/Stm32_F103C6_USART.o 

C_DEPS += \
./MCAL/Stm32_F103C6_EXTI.d \
./MCAL/Stm32_F103C6_GPIO.d \
./MCAL/Stm32_F103C6_RCC.d \
./MCAL/Stm32_F103C6_USART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"E:/!Embedded/!STM/WriteDriver/HAL/inc" -I../Inc -I"E:/!Embedded/!STM/WriteDriver/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/Stm32_F103C6_EXTI.d ./MCAL/Stm32_F103C6_EXTI.o ./MCAL/Stm32_F103C6_EXTI.su ./MCAL/Stm32_F103C6_GPIO.d ./MCAL/Stm32_F103C6_GPIO.o ./MCAL/Stm32_F103C6_GPIO.su ./MCAL/Stm32_F103C6_RCC.d ./MCAL/Stm32_F103C6_RCC.o ./MCAL/Stm32_F103C6_RCC.su ./MCAL/Stm32_F103C6_USART.d ./MCAL/Stm32_F103C6_USART.o ./MCAL/Stm32_F103C6_USART.su

.PHONY: clean-MCAL

