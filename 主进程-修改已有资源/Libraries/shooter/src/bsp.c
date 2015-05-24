
#include "main.h"
#include "bsp.h"

#include <stdio.h>


void BSP_Usart1Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;


	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;



	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOE, ENABLE);

	/* Enable USART clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); 

	/* Connect PXx to USARTx_Tx */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource4, GPIO_AF_7);

	/* Connect PXx to USARTx_Rx */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_7);

	/* Configure USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	  
	/* Configure USART Rx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* USART configuration */
	USART_Init(USART1, &USART_InitStructure);
	  
	/* Enable USART */
	USART_Cmd(USART1, ENABLE);


}



#ifdef __GNUC__ 
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf 
     set to 'Yes') calls __io_putchar() */ 
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch) 
#else 
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f) 
#endif /* __GNUC__ */ 
PUTCHAR_PROTOTYPE 
{

	if(ch == 0x0a)
	{
		USART_SendData(USART1, 0x0d);	
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	}

	USART_SendData(USART1, ch);	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	
	return ch;
}










#define sEE_I2C                          I2C2
#define sEE_I2C_CLK                      RCC_APB1Periph_I2C2
   
#define sEE_I2C_SCL_PIN                  GPIO_Pin_6                  /* PF.06 */
#define sEE_I2C_SCL_GPIO_PORT            GPIOF                       /* GPIOF */
#define sEE_I2C_SCL_GPIO_CLK             RCC_AHBPeriph_GPIOF
#define sEE_I2C_SCL_SOURCE               GPIO_PinSource6
#define sEE_I2C_SCL_AF                   GPIO_AF_4

#define sEE_I2C_SDA_PIN                  GPIO_Pin_10                  /* PA.10 */
#define sEE_I2C_SDA_GPIO_PORT            GPIOA                       /* GPIOA */
#define sEE_I2C_SDA_GPIO_CLK             RCC_AHBPeriph_GPIOA
#define sEE_I2C_SDA_SOURCE               GPIO_PinSource10
#define sEE_I2C_SDA_AF                   GPIO_AF_4

void BSP_IIClowlevelInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	/* Configure the I2C clock source. The clock is derived from the SYSCLK */
	RCC_I2CCLKConfig(RCC_I2C2CLK_SYSCLK);
	  
	/* sEE_I2C_SCL_GPIO_CLK and sEE_I2C_SDA_GPIO_CLK Periph clock enable */
	RCC_AHBPeriphClockCmd(sEE_I2C_SCL_GPIO_CLK | sEE_I2C_SDA_GPIO_CLK, ENABLE);
	
	/* sEE_I2C Periph clock enable */
	RCC_APB1PeriphClockCmd(sEE_I2C_CLK, ENABLE);
	
	/* Connect PXx to I2C_SCL*/
	GPIO_PinAFConfig(sEE_I2C_SCL_GPIO_PORT, sEE_I2C_SCL_SOURCE, sEE_I2C_SCL_AF);
	
	/* Connect PXx to I2C_SDA*/
	GPIO_PinAFConfig(sEE_I2C_SDA_GPIO_PORT, sEE_I2C_SDA_SOURCE, sEE_I2C_SDA_AF);
	
	/* GPIO configuration */  
	/* Configure sEE_I2C pins: SCL */
	GPIO_InitStructure.GPIO_Pin = sEE_I2C_SCL_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_Init(sEE_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);
	
	/* Configure sEE_I2C pins: SDA */
	GPIO_InitStructure.GPIO_Pin = sEE_I2C_SDA_PIN;
	GPIO_Init(sEE_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);	

}



__IO uint16_t  sEEAddress = 0; 
#define sEE_I2C_TIMING             0xC062121F

void BSP_TC358870Init(void)
{
  I2C_InitTypeDef  I2C_InitStructure;
  
  BSP_IIClowlevelInit();
  
  /*!< I2C configuration */
  /* sEE_I2C configuration */
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
  I2C_InitStructure.I2C_DigitalFilter = 0x00;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_Timing = sEE_I2C_TIMING;
  
  /* Apply sEE_I2C configuration after enabling it */
  I2C_Init(sEE_I2C, &I2C_InitStructure);
  
  /* sEE_I2C Peripheral Enable */
  I2C_Cmd(sEE_I2C, ENABLE);
  
  /*!< Select the EEPROM address */
  sEEAddress = 0X0F; 
		
}






#define TS751_ADDR           0X0F   /*!< TS751 address */


#define TS751_I2C                        I2C2


#define TS751_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define TS751_LONG_TIMEOUT         ((uint32_t)(10 * TS751_FLAG_TIMEOUT))   
__IO uint32_t  TS751_Timeout = TS751_LONG_TIMEOUT; 

uint8_t TS751_TIMEOUT_UserCallback(void)
{
	printf("time out \n");

	return 0;
}

uint8_t TS751_ReadReg(uint8_t RegName)
{   
  uint8_t TS751_BufferRX[1] ={0}; 
  
  /* Test on BUSY Flag */
  TS751_Timeout = TS751_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(TS751_I2C, I2C_ISR_BUSY) != RESET)
  {
    if((TS751_Timeout--) == 0) return TS751_TIMEOUT_UserCallback();
  }  
  printf("I2C_ISR_BUSY is clear\n");


  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(TS751_I2C, TS751_ADDR, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);
  
  /* Wait until TXIS flag is set */
  TS751_Timeout = TS751_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(TS751_I2C, I2C_ISR_TXIS) == RESET)
  {  
    if((TS751_Timeout--) == 0) return TS751_TIMEOUT_UserCallback();
  }
  printf("I2C_ISR_TXIS is set\n");



  
  /* Send Register address */
  I2C_SendData(TS751_I2C, (uint8_t)RegName);
  
  /* Wait until TC flag is set */
  TS751_Timeout = TS751_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(TS751_I2C, I2C_ISR_TC) == RESET)
  {
    if((TS751_Timeout--) == 0) return TS751_TIMEOUT_UserCallback();
  }  
  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(TS751_I2C, TS751_ADDR, 1, I2C_AutoEnd_Mode, I2C_Generate_Start_Read);
  
  /* Wait until RXNE flag is set */
  TS751_Timeout = TS751_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(TS751_I2C, I2C_ISR_RXNE) == RESET)    
  {
    if((TS751_Timeout--) == 0) return TS751_TIMEOUT_UserCallback();
  }
  
  /* Read data from RXDR */
  TS751_BufferRX[0]= I2C_ReceiveData(TS751_I2C);
  
  /* Wait until STOPF flag is set */
  TS751_Timeout = TS751_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(TS751_I2C, I2C_ISR_STOPF) == RESET)   
  {
    if((TS751_Timeout--) == 0) return TS751_TIMEOUT_UserCallback();
  }
  
  /* Clear STOPF flag */
  I2C_ClearFlag(TS751_I2C, I2C_ICR_STOPCF);
  
  /* return a Reg value */
  return TS751_BufferRX[0];  
}



