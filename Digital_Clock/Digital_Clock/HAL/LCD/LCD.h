/*
 * LCD.h
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD_confg.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN 0
#define RW 1
#define RS 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void HLCD_Init(void);
void Hsend_falling_edge(void);
void HLCD_Send_cmd(u8 cmd);
void HLCD_Send_char(u8 data);
void HLCD_Send_string(u8 *data);
void HLCD_clearscreen();
void HLCD_movecursor(u8 row,u8 coloumn);




#endif /* HAL_LCD_LCD_H_ */
