
/**
  *
  @	JX-STM32 ʾ������
 
  @	�汾�� V1.1.0
  **************  ��C��COPYRIGHT  2014 ������о�Ƽ����޹�˾   **************
  
  *@�ļ���     JX_I2C.c  
  *@����       ��о�з��Ŷ�
  *@�汾       V1.1.0
  *@����       ��о�Ƽ������з�������JX-STM32ʾ������ʹ��ST��׼��V3.5.0
  *			   uCGUI�汾Ϊ3.90a
  *@��ϵ����   www.beijingmcu.com
  *
  */




/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "bsp.h"
#include <stdio.h>


/*����EEPROM��GPIO����*/
#define I2CSoft_SCL_Pin GPIO_Pin_10
#define I2CSoft_SDA_Pin GPIO_Pin_11
#define I2CSoft_GPIO    GPIOB
#define I2CSoft_Periph  RCC_AHBPeriph_GPIOB


/*����һЩ������*/
#define I2CSoft_SDASet  GPIO_SetBits(GPIOB,I2CSoft_SDA_Pin) 
#define I2CSoft_SDAClr  GPIO_ResetBits(GPIOB,I2CSoft_SDA_Pin) 
#define I2CSoft_SCLSet  GPIO_SetBits(GPIOB,I2CSoft_SCL_Pin) 
#define I2CSoft_SCLClr  GPIO_ResetBits(GPIOB,I2CSoft_SCL_Pin) 
#define READ_SDA        GPIO_ReadInputDataBit(GPIOB,I2CSoft_SDA_Pin)


/**
  *@���� 	 ���ж��ݵ�NS����ʱ
  *@����	 Time��Ҫ����ʱʱ��
  *@����ֵ	 ��
  */
__inline static void I2CSoft_Delay(u16 Time)
{
	Time *=4;
	while(Time--);
}


/**
  *@���� 	 ����I2C��SDA����Ϊ�������
  *@����	 ��
  *@����ֵ	 ��
  */
__inline static void I2CSoft_SDAOPP(void)
{	

	GPIO_InitTypeDef GPIO_InitStructure;

	/*����SDAΪ�������*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);
}


/**
  *@���� 	 ����I2C��SDA����Ϊ��������
  *@����	 ��
  *@����ֵ	 ��
  */
__inline static void I2CSoft_SDAIPU(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����SDAΪ��������*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN ; 
	GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_UP;   
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);
}


/**
  *@���� 	 ��ʹ��IIC����Ҫ��������ص�GPIO����
  *@����	 ��
  *@����ֵ	 ��
  */
static void I2CSoft_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	/*ʹ��I2C����ʱ��*/
	RCC_AHBPeriphClockCmd(	I2CSoft_Periph, ENABLE );	
	
	/*����SCL��SDA����Ϊ�������*/
	GPIO_InitStructure.GPIO_Pin = I2CSoft_SCL_Pin|I2CSoft_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  
	GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_NOPULL; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(I2CSoft_GPIO, &GPIO_InitStructure);

	/*��SCL��SDA��������*/
	GPIO_SetBits(I2CSoft_GPIO,I2CSoft_SCL_Pin|I2CSoft_SDA_Pin); 
}


/**
  *@���� 	 ����һ��I2C��ʼ�ź�
  *@����	 ��
  *@����ֵ	 ��
  */
static void I2CSoft_Start(void)
{
	/*ģ��I2C����ʼ�ź�ʱ��*/
	I2CSoft_SDAOPP();     
	I2CSoft_SDASet;	  	  
	I2CSoft_SCLSet;
	I2CSoft_Delay(4);
	I2CSoft_SDAClr;
	I2CSoft_Delay(4);
	I2CSoft_SCLClr;
}	

  
/**
  *@���� 	 ����һ��I2Cֹͣ�ź�
  *@����	 ��
  *@����ֵ	 ��
  */
static void I2CSoft_Stop(void)
{
	/*ģ��I2C��ֹͣ�ź�ʱ��*/
	I2CSoft_SDAOPP();
	I2CSoft_SCLClr;
	I2CSoft_SDAClr;
 	I2CSoft_Delay(4);
	I2CSoft_SCLSet; 
	I2CSoft_SDASet;
	I2CSoft_Delay(4);							   	
}


/**
  *@���� 	 �ȴ�I2CӦ���ź�
  *@����	 ��
  *@����ֵ	 1������Ӧ���źųɹ�
  *@         0������Ӧ���ź�ʧ��			 
  */
static u8 I2CSoft_WaitAck(void)
{
	u8 ucErrTime=0;
	/*����SDA����Ϊ����*/
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
  *@���� 	 ����һ��ACKӦ��
  *@����	 ��
  *@����ֵ	 ��			 
  */
static void I2CSoft_Ack(void)
{
	/*ģ��I2C��Ӧ���ź�ʱ��*/
	I2CSoft_SCLClr;
	I2CSoft_SDAOPP();
	I2CSoft_SDAClr;
	I2CSoft_Delay(2);
	I2CSoft_SCLSet;
	I2CSoft_Delay(2);
	I2CSoft_SCLClr;
}


/**
  *@���� 	 ����һ��NACK��Ӧ���ź�
  *@����	 ��
  *@����ֵ	 ��			 
  */	    
static void I2CSoft_NAck(void)
{
	/*ģ��I2C�ķ�Ӧ���ź�ʱ��*/
	I2CSoft_SCLClr;
	I2CSoft_SDAOPP();
	I2CSoft_SDASet;
	I2CSoft_Delay(2);
	I2CSoft_SCLSet;
	I2CSoft_Delay(2);
	I2CSoft_SCLClr;
}					 				     


/**
  *@���� 	 I2C����һ���ֽ�����
  *@����	 ��Ҫ���͵�һ���ֽ�����
  *@����ֵ	 ��			 
  */		  
static void I2CSoft_SendByte(u8 TransmitData)
{                        
    u8 t;  
	/*����ʱ����׼����ʼ��������*/ 
	I2CSoft_SDAOPP(); 	    
    I2CSoft_SCLClr;

	/*һλһλ�ķ�������*/
    for(t=0;t<8;t++)
    {              
		if((TransmitData&0x80)>>7)
			I2CSoft_SDASet;
		else
			I2CSoft_SDAClr;
		TransmitData<<=1;
		/*����оƬ��I2Cʱ���Ҫ��*/ 	  
		I2CSoft_Delay(2);   
		I2CSoft_SCLSet;
		I2CSoft_Delay(2); 
		I2CSoft_SCLClr;	
		I2CSoft_Delay(2);
    }	 
} 	    


/**
  *@���� 	 I2C��ȡһ���ֽ�����
  *@����	 Signal��ȡ��ɺ��Ӧһ��ACK�źŻ���NACK�ź�
  *@               >0����ACK�ź�
  *@               0����NACK�ź�
  *@����ֵ	 ��ȡ����һ���ֽ�����		 
  */
static u8 I2CSoft_ReadByte(u8 Signal)
{
	u8 i,ReceiveData=0;
	
	/*��SDA��������Ϊ����*/
	I2CSoft_SDAIPU();
	/*һλһλ��ȡ����*/
	for(i=0;i<8;i++ )
	{
		I2CSoft_SCLClr; 
		I2CSoft_Delay(2);
		I2CSoft_SCLSet;
		ReceiveData<<=1;
		if(READ_SDA)ReceiveData++;   
		I2CSoft_Delay(1); 
	}	
	
	/*���������ȷ����ӦACK�źŻ���NACK�ź�*/					 
	if (!Signal)
	I2CSoft_NAck();
	else
	I2CSoft_Ack(); 
	return ReceiveData;
}


/**
  *@���� 	 ��ȡEEPROMһ���ֽڵ�����
  *@����	 ��
  *@����ֵ	 ��		 
  */
u8 EEPROM_ReadByte(u16 ReadAddr)
{				  
	u8 TempData=0;



	
	/*����һ��I2C��ʼ�ź�*/		  	    																 
	I2CSoft_Start();  

	I2CSoft_SendByte(0X1E);
	I2CSoft_WaitAck();

	
	/*���Ͷ������ĵ�ַ*/
	I2CSoft_SendByte(ReadAddr/256);    
	I2CSoft_WaitAck(); 
	I2CSoft_SendByte(ReadAddr%256);  
	I2CSoft_WaitAck();	   
	
	/*��ʼ�ȴ�����*/ 
	I2CSoft_Start();  	 	   
	I2CSoft_SendByte(0X1F);          		   
	I2CSoft_WaitAck();	 
	
	/*��������*/
	TempData=I2CSoft_ReadByte(0);		   
	I2CSoft_Stop();    
	return TempData;
}


/**
  *@���� 	 ��EEPROMд��һ���ֽڵ�����
  *@����	 WriteAddrд��ĵ�ַ
  *@         DataWrite��д������� 
  *@����ֵ	 ��		 
  */
void EEPROM_WriteByte(u16 WriteAddr,u16 DataWrite)
{		
    I2CSoft_Start();  

	I2CSoft_SendByte(0X1E);
	I2CSoft_WaitAck();

	/*����д�����ĵ�ַ*/
	I2CSoft_SendByte(WriteAddr/256);   	 
	I2CSoft_WaitAck();	   
    I2CSoft_SendByte(WriteAddr%256);   
	I2CSoft_WaitAck(); 	 
	
	/*����Ҫд�������*/										  		   
	I2CSoft_SendByte((u8)(DataWrite%256));     //�����ֽ�							   
	I2CSoft_WaitAck(); 
	/*����Ҫд�������*/										  		   
	I2CSoft_SendByte((u8)(DataWrite/256));     //�����ֽ�							   
	I2CSoft_WaitAck(); 

	
	/*д����ɲ�����ֹͣ�ź�*/ 		    	   
    I2CSoft_Stop();
	I2CSoft_Delay(10);	 
}


/**
  *@���� 	 EEPROM��ʹ��
  *@����	 ��
  *@����ֵ	 ��		 
  */
void EEPROM_Init(void)
{
	/*��ʹ��I2C����*/
	I2CSoft_Init();
}







/**
  *@���� 	 ��EEPROM��ȡָ�����ȵ�����
  *@����	 ReadAddr��ȡ�ĵ�ַ
  *@         DataBuf���ݻ�����������ָ�� 
  *@		 DataLen��д������ݵĳ���
  *@����ֵ	 ��		 
  */
void EEPROM_ReadData(u32 ReadAddr,u32 *DataBuf,u16 DataLen)
{
	int i;
	u32 dtmp;
	u8  dd;
	/*һ���ֽ�һ���ֽڵĶ�ȡ���ݵ�������*/
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
  *@���� 	 ��EEPROMд��ָ�����ȵ�����
  *@����	 WriteAddrд��ĵ�ַ
  *@         DataBuf��д�������ָ�� 
  *@		 DataLen��д������ݵĳ���
  *@����ֵ	 ��		 
  */
void EEPROM_WriteData(u16 WriteAddr,u16* DataBuf,u16 DataLen)
{	
	/*һ���ֽ�һ���ֽڵ�д������*/
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








