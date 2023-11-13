################################################################################
# Automatically-generated file. Do not edit!
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
MCAL/Stm32_F103C6_EXTI.o: ../MCAL/Stm32_F103C6_EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/HAL/inc" -I../Inc -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_GPIO.o: ../MCAL/Stm32_F103C6_GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/HAL/inc" -I../Inc -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_RCC.o: ../MCAL/Stm32_F103C6_RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/HAL/inc" -I../Inc -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_USART.o: ../MCAL/Stm32_F103C6_USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/HAL/inc" -I../Inc -I"D:/Embedded course/Embedded_system_online_diploma/UNIT14 - ARM/Lesson1/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

