
/**
  *
  @	JX-STM32 示例工程
 
  @	版本号 V1.1.0
  **************  （C）COPYRIGHT  2014 北京京芯科技有限公司   **************
  
  *@文件名     JX_I2C.c  
  *@作者       京芯研发团队
  *@版本       V1.1.0
  *@描述       京芯科技自主研发开发板JX-STM32示例程序，使用ST标准库V3.5.0
  *			   uCGUI版本为3.90a
  *@联系我们   www.beijingmcu.com
  *
  */




/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "bsp.h"
#include <stdio.h>


/*定义EEPROM的GPIO引脚*/
#define I2CSoft_SCL_Pin GPIO_Pin_10
#define I2CSoft_SDA_Pin GPIO_Pin_11
#define I2CSoft_GPIO    GPIOB
#define I2CSoft_Periph  RCC_AHBPeriph_GPIOB


/*定义一些操作宏*/
#define I2CSoft_SDASet  GPIO_SetBits(GPIOB,I2CSoft_SDA_Pin) 
#define I2CSoft_SDAClr  GPIO_ResetBits(GPIOB,I2CSoft_SDA_Pin) 
#define I2CSoft_SCLSet  GPIO_SetBits(GPIOB,I2CSoft_SCL_Pin) 
#define I2CSoft_SCLClr  GPIO_ResetBits(GPIOB,I2CSoft_SCL_Pin) 
#define READ_SDA        GPIO_ReadInputDataBit(GPIOB,I2CSoft_SDA_Pin)


/**
  *@描述 	 进行短暂的NS级延时
  *@参数	 Time需要的延时时间
  *@返回值	 无
  */
__inline static void I2CSoft_Delay(u16 Time)
{
	Time *=4;
	while(Time--);
}


/**
  *@描述 	 设置I2C的SDA引脚为推挽输出
  *@参数	 无
  *@返回值	 无
  */
__inline static void I2CSoft_SDAOPP(void)
{	

	GPIO_InitTypeDef GPIO_InitStructure;

	/*设置SDA为推挽输出*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);
}


/**
  *@描述 	 设置I2C的SDA引脚为上拉输入
  *@参数	 无
  *@返回值	 无
  */
__inline static void I2CSoft_SDAIPU(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*设置SDA为上拉输入*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN ; 
	GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_UP;   
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);
}


/**
  *@描述 	 初使化IIC，主要是设置相关的GPIO引脚
  *@参数	 无
  *@返回值	 无
  */
static void I2CSoft_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	/*使能I2C引脚时钟*/
	RCC_AHBPeriphClockCmd(	I2CSoft_Periph, ENABLE );	
	
	/*设置SCL、SDA引脚为推挽输出*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SCL_Pin|I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  
	GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_NOPULL; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);

	/*将SCL、SDA引脚拉高*/
	GPIO_SetBits(I2CSoft_GPIO,I2CSoft_SCL_Pin|I2CSoft_SDA_Pin); 
}


/**
  *@描述 	 产生一个I2C起始信号
  *@参数	 无
  *@返回值	 无
  */
static void I2CSoft_Start(void)
{
	/*模拟I2C的起始信号时序*/
	I2CSoft_SDAOPP();     
	I2CSoft_SDASet;	  	  
	I2CSoft_SCLSet;
	I2CSoft_Delay(4);
	I2CSoft_SDAClr;
	I2CSoft_Delay(4);
	I2CSoft_SCLClr;
}	

  
/**
  *@描述 	 产生一个I2C停止信号
  *@参数	 无
  *@返回值	 无
  */
static void I2CSoft_Stop(void)
{
	/*模拟I2C的停止信号时序*/
	I2CSoft_SDAOPP();
	I2CSoft_SCLClr;
	I2CSoft_SDAClr;
 	I2CSoft_Delay(4);
	I2CSoft_SCLSet; 
	I2CSoft_SDASet;
	I2CSoft_Delay(4);							   	
}


/**
  *@描述 	 等待I2C应答信号
  *@参数	 无
  *@返回值	 1、接收应答信号成功
  *@         0、接收应答信号失败			 
  */
static u8 I2CSoft_WaitAck(void)
{
	u8 ucErrTime=0;
	/*设置SDA引脚为输入*/
	I2CSoft_SDAIPU();     
	I2CSoft_SDASet;I2CSoft_Delay(1);	   
	I2CSoft_SCLSet;I2CSoft_Delay(1);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
		I2CSoft_Stop();
		return 1;
		}
	}
	I2CSoft_SCLClr;   
	return 0;  
} 


/**
  *@描述 	 产生一个ACK应答
  *@参数	 无
  *@返回值	 无			 
  */
static void I2CSoft_Ack(void)
{
	/*模拟I2C的应答信号时序*/
	I2CSoft_SCLClr;
	I2CSoft_SDAOPP();
	I2CSoft_SDAClr;
	I2CSoft_Delay(2);
	I2CSoft_SCLSet;
	I2CSoft_Delay(2);
	I2CSoft_SCLClr;
}


/**
  *@描述 	 产生一个NACK非应答信号
  *@参数	 无
  *@返回值	 无			 
  */	    
static void I2CSoft_NAck(void)
{
	/*模拟I2C的非应答信号时序*/
	I2CSoft_SCLClr;
	I2CSoft_SDAOPP();
	I2CSoft_SDASet;
	I2CSoft_Delay(2);
	I2CSoft_SCLSet;
	I2CSoft_Delay(2);
	I2CSoft_SCLClr;
}					 				     


/**
  *@描述 	 I2C发送一个字节数据
  *@参数	 将要发送的一个字节数据
  *@返回值	 无			 
  */		  
static void I2CSoft_SendByte(u8 TransmitData)
{                        
    u8 t;  
	/*拉低时钟线准备开始传输数据*/ 
	I2CSoft_SDAOPP(); 	    
    I2CSoft_SCLClr;

	/*一位一位的发送数据*/
    for(t=0;t<8;t++)
    {              
		if((TransmitData&0x80)>>7)
			I2CSoft_SDASet;
		else
			I2CSoft_SDAClr;
		TransmitData<<=1;
		/*满足芯片对I2C时序的要求*/ 	  
		I2CSoft_Delay(2);   
		I2CSoft_SCLSet;
		I2CSoft_Delay(2); 
		I2CSoft_SCLClr;	
		I2CSoft_Delay(2);
    }	 
} 	    


/**
  *@描述 	 I2C读取一个字节数据
  *@参数	 Signal读取完成后回应一个ACK信号还是NACK信号
  *@               >0发送ACK信号
  *@               0发送NACK信号
  *@返回值	 读取到的一个字节数据		 
  */
static u8 I2CSoft_ReadByte(u8 Signal)
{
	u8 i,ReceiveData=0;
	
	/*将SDA引脚设置为输入*/
	I2CSoft_SDAIPU();
	/*一位一位读取数据*/
	for(i=0;i<8;i++ )
	{
		I2CSoft_SCLClr; 
		I2CSoft_Delay(2);
		I2CSoft_SCLSet;
		ReceiveData<<=1;
		if(READ_SDA)ReceiveData++;   
		I2CSoft_Delay(1); 
	}	
	
	/*由输入参数确定回应ACK信号还是NACK信号*/					 
	if (!Signal)
	I2CSoft_NAck();
	else
	I2CSoft_Ack(); 
	return ReceiveData;
}


/**
  *@描述 	 读取EEPROM一个字节的数据
  *@参数	 无
  *@返回值	 无		 
  */
u8 EEPROM_ReadByte(u16 ReadAddr)
{				  
	u8 TempData=0;



	
	/*产生一个I2C起始信号*/		  	    																 
	I2CSoft_Start();  

	I2CSoft_SendByte(0X1E);
	I2CSoft_WaitAck();

	
	/*发送读器件的地址*/
	I2CSoft_SendByte(ReadAddr/256);    
	I2CSoft_WaitAck(); 
	I2CSoft_SendByte(ReadAddr%256);  
	I2CSoft_WaitAck();	   
	
	/*开始等待接收*/ 
	I2CSoft_Start();  	 	   
	I2CSoft_SendByte(0X1F);          		   
	I2CSoft_WaitAck();	 
	
	/*接收数据*/
	TempData=I2CSoft_ReadByte(0);		   
	I2CSoft_Stop();    
	return TempData;
}


/**
  *@描述 	 向EEPROM写入一个字节的数据
  *@参数	 WriteAddr写入的地址
  *@         DataWrite将写入的数据 
  *@返回值	 无		 
  */
void EEPROM_WriteByte(u16 WriteAddr,u16 DataWrite)
{		
    I2CSoft_Start();  

	I2CSoft_SendByte(0X1E);
	I2CSoft_WaitAck();

	/*发送写器件的地址*/
	I2CSoft_SendByte(WriteAddr/256);   	 
	I2CSoft_WaitAck();	   
    I2CSoft_SendByte(WriteAddr%256);   
	I2CSoft_WaitAck(); 	 
	
	/*发送要写入的数据*/										  		   
	I2CSoft_SendByte((u8)(DataWrite%256));     //发送字节							   
	I2CSoft_WaitAck(); 
	/*发送要写入的数据*/										  		   
	I2CSoft_SendByte((u8)(DataWrite/256));     //发送字节							   
	I2CSoft_WaitAck(); 

	
	/*写入完成产生个停止信号*/ 		    	   
    I2CSoft_Stop();
	I2CSoft_Delay(10);	 
}


/**
  *@描述 	 EEPROM初使化
  *@参数	 无
  *@返回值	 无		 
  */
void EEPROM_Init(void)
{
	/*初使化I2C引脚*/
	I2CSoft_Init();
}







/**
  *@描述 	 从EEPROM读取指定长度的数据
  *@参数	 ReadAddr读取的地址
  *@         DataBuf数据缓冲区的数据指针 
  *@		 DataLen将写入的数据的长度
  *@返回值	 无		 
  */
void EEPROM_ReadData(u32 ReadAddr,u32 *DataBuf,u16 DataLen)
{
	int i;
	u32 dtmp;
	u8  dd;
	/*一个字节一个字节的读取数据到缓冲区*/
	while(DataLen)
	{
		dtmp = 0;
		for(i=0; i<4; i++)
		{
			dd = EEPROM_ReadByte(ReadAddr++);
			dtmp |= ((dd) << (i * 8));
		}
		
		
		*DataBuf++= dtmp;	
		DataLen-=4;
	}
}  


/**
  *@描述 	 向EEPROM写入指定长度的数据
  *@参数	 WriteAddr写入的地址
  *@         DataBuf将写入的数据指针 
  *@		 DataLen将写入的数据的长度
  *@返回值	 无		 
  */
void EEPROM_WriteData(u16 WriteAddr,u16* DataBuf,u16 DataLen)
{	
	/*一个字节一个字节的写入数据*/
	while(DataLen)
	{
		EEPROM_WriteByte(WriteAddr,*DataBuf);
		I2CSoft_Delay(5000);
		WriteAddr+=2;
		DataBuf++;
		DataLen-=2;
	}
}










void i2c1_uh2d_write16(u16 WriteAddr,u16 Date)
{
	EEPROM_WriteByte(WriteAddr,Date);
	Waitx1ms(10);
}


void i2c1_uh2d_write32(u16 WriteAddr,u32 Date)
{

	EEPROM_WriteByte(WriteAddr,(u16)(Date%65536));
	Waitx1ms(10);
	EEPROM_WriteByte(WriteAddr+2,(u16)(Date/65536));
	Waitx1ms(10);	

	
}


void i2c1_uh2d_write8(u16 WriteAddr,u8 Date)
{

	u16 dtmp;
	dtmp = EEPROM_ReadByte(WriteAddr+1);
	EEPROM_WriteByte(WriteAddr,Date|(dtmp<<8));
	Waitx1ms(10);

}


void Waitx1ms(u32 t)
{
	u32 i,j;
	for(i=t; i>0; i--)
	{
		for(j=1100; j>0; j--)
		I2CSoft_Delay(1);

	}
}

void Waitx1us(u32 t)
{
	I2CSoft_Delay(t);
}



u8 i2c1_uh2d_read8(u16 ReadAddr)
{	
	return EEPROM_ReadByte(ReadAddr);

}








