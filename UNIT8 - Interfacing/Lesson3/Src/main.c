// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "lcd.h"
#include "keypad.h"
#include "stm32f103x6.h"
#include "Stm32_F103C6_EXTI.h"
#include "Stm32_F103C6_GPIO.h"
#include "Stm32_F103C6_USART.h"
void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

}



void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}


uint16_t ch;
int main(void)
{

	clock_init();
	USART_Config_t uart_config;
	uart_config.BaudRate = UART_BaudRate_115200;
	uart_config.HwFlowCtl = UART_HwFlowCtl_NONE;
	uart_config.IRQ_Enable = UART_IRQ_Enable_NONE;
	uart_config.Parity = UART_Parity_NONE;
	uart_config.Payload_Length = UART_Payload_Length_8B;
	uart_config.StopBits = UART_StopBits_1;
	uart_config.USART_Mode = UART_Mode_TX_RX;
	MCAL_UART_Init(USART1, &uart_config);


	MCAL_UART_GPIO_Set_Pins(USART1);


	while(1)
	{
		MCAL_UART_ReceiveData(USART1, &ch, enable);
		MCAL_UART_SendData(USART1, &ch, enable);
	}

}
