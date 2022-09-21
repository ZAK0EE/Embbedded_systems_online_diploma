################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/Keypad/keypad.c 

OBJS += \
./Stm32_F103C6_Drivers/Keypad/keypad.o 

C_DEPS += \
./Stm32_F103C6_Drivers/Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/Keypad/%.o Stm32_F103C6_Drivers/Keypad/%.su: ../Stm32_F103C6_Drivers/Keypad/%.c Stm32_F103C6_Drivers/Keypad/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"E:/!Embedded/!STM/WriteDriver/Stm32_F103C6_Drivers/Keypad" -I"E:/!Embedded/!STM/WriteDriver/Stm32_F103C6_Drivers/LCD" -I"E:/!Embedded/!STM/WriteDriver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Stm32_F103C6_Drivers-2f-Keypad

clean-Stm32_F103C6_Drivers-2f-Keypad:
	-$(RM) ./Stm32_F103C6_Drivers/Keypad/keypad.d ./Stm32_F103C6_Drivers/Keypad/keypad.o ./Stm32_F103C6_Drivers/Keypad/keypad.su

.PHONY: clean-Stm32_F103C6_Drivers-2f-Keypad

