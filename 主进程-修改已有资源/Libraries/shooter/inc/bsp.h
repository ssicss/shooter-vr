#ifndef __BSP_H
#define __BSP_H
#include "main.h"


enum HANDLE_STATE {
	BSP_FAIL = 0,
	BSP_SUCCES = !BSP_FAIL,
};

void SystemClock_Config(void);

void BSP_Usart1Init(void);

void BSP_TC358870Init(void);

u8 TS751_ReadReg(u8 RegName);

void EEPROM_Init(void);
void EEPROM_ReadData(u32 ReadAddr,u32 *DataBuf,u16 DataLen);
void EEPROM_WriteData(u16 WriteAddr,u16* DataBuf,u16 DataLen);



void i2c1_uh2d_write16(u16 WriteAddr,u16 Date);
void i2c1_uh2d_write32(u16 WriteAddr,u32 Date);
void i2c1_uh2d_write8(u16 WriteAddr,u8 Date);

void Waitx1ms(u32 t);
void Waitx1us(u32 t);
u8 i2c1_uh2d_read8(u16 ReadAddr);

void Tc358Write(void);




#endif






