// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "lcd.h"
#include "keypad.h"
#include "stm32f103x6.h"
#include "Stm32_F103C6_EXTI.h"
#include "Stm32_F103C6_GPIO.h"
#include "Stm32_F103C6_USART.h"
#include "Stm32_F103C6_SPI.h"


#define MASTER
uint16_t ch;
void USART1_CallBack(void)
{
#ifdef MASTER
	MCAL_UART_ReceiveData(USART1, &ch, enable);
	MCAL_UART_SendData(USART1, &ch, disable);

	/* ========= Send Data To SPI1 =========== */

	/* Slave Selection (Low), to listen  */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	/* Send & Receive data */
	MCAL_SPI_TX_RX(SPI1, &ch, SPI_enable);

	/* Slave Selection (High) idle mode */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}
void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}



void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}



int main(void)
{

	clock_init();

	/* Configuration of USART1 */
	USART_Config_t USART1_Config;

	USART1_Config.BaudRate = UART_BaudRate_115200;
	USART1_Config.HwFlowCtl = UART_HwFlowCtl_NONE;
	USART1_Config.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	USART1_Config.P_IRQ_CallBack = USART1_CallBack;
	USART1_Config.Parity = UART_Parity_NONE;
	USART1_Config.Payload_Length = UART_Payload_Length_8B;
	USART1_Config.StopBits = UART_StopBits_1;
	USART1_Config.USART_Mode = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &USART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/* Configuration of SPI1 */
	SPI_Config_t SPI1_Config;

	/* Common Configuration */
	SPI1_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_8;
	SPI1_Config.CLK_Phase = CLK_PHASE_SECOND;
	SPI1_Config.CLK_Polarity = CLK_POLARITY_IDLE_HIGH;
	SPI1_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;
	SPI1_Config.Frame_Size = FRAME_SIZE_8BIT;
	SPI1_Config.Communication_Mode = COMMUNICATION_MODE_2LINE_FULL_DUPLEX;

#ifdef MASTER
	SPI1_Config.SPI_Mode = SPI_MODE_MASTER;
	SPI1_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI1_Config.P_IRQ_CallBack = NULL;
	SPI1_Config.NSS = NSS_SW_SSI_SET;	/* To Control when open & when close, Set as Active High */

	/* Configuration of SS */
	GPIO_PinConfig_t SS_Config;

	/* Configure SS at PA4 by GPIO */
	SS_Config.GPIO_PinNumber = GPIO_PIN_4;
	SS_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	SS_Config.GPIO_Speed = GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, &SS_Config);

#endif

	MCAL_SPI_Init(SPI1, &SPI1_Config);

	GPIO_PinConfig_t SPI_GPIO_Config;
	SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_5;
	SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
	SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
	//MCAL_SPI_GPIO_Set_Pins(SPI1);

	/* Force the slave select (High) idle mode */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);


	/* Loop For Ever */
	while(1){}

}
