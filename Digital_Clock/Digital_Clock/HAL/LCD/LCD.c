/*
 * LCD.c
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */
#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

void HLCD_Init(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	MDIO_VidSetPinDirection(PORTA,0,1);
	MDIO_VidSetPinDirection(PORTA,1,1);
	MDIO_VidSetPinDirection(PORTA,2,1);
	MDIO_VidSetPinDirection(PORTA,3,1);
	MDIO_VidSetPinDirection(PORTA,4,1);
	MDIO_VidSetPinDirection(PORTA,5,1);
	MDIO_VidSetPinDirection(PORTA,6,1);
	MDIO_VidSetPinDirection(PORTA,7,1);
	MDIO_VidSetPinDirection(PORTB,EN,1);
	MDIO_VidSetPinDirection(PORTB,RW,1);
	MDIO_VidSetPinDirection(PORTB,RS,1);
	MDIO_VidSetPinValue(PORTB,RW,0);
	HLCD_Send_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	HLCD_Send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	HLCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	HLCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);

	#elif defined four_bits_mode
	MDIO_voidSetPinDirection(PORTA,4,1);
	MDIO_voidSetPinDirection(PORTA,5,1);
	MDIO_voidSetPinDirection(PORTA,6,1);
	MDIO_voidSetPinDirection(PORTA,7,1);
	MDIO_voidSetPinDirection(PORTA,EN,1);
	MDIO_voidSetPinDirection(PORTA,RW,1);
	MDIO_voidSetPinDirection(PORTA,RS,1);
   	MDIO_voidSetPinValue(PORTA,RW,0);
	HLCD_Send_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	HLCD_Send_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	HLCD_Send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	HLCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	HLCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}


void Hsend_falling_edge(void)
{
	MDIO_voidSetPinValue(PORTA,EN,1);
	_delay_ms(2);
	MDIO_voidSetPinValue(PORTA,EN,0);
	_delay_ms(2);
}
void HLCD_Send_cmd(u8 cmd)
{
	#if defined eight_bits_mode
	MDIO_voidSetPortValue(PORTA,cmd);
	MDIO_voidSetPinValue(PORTB,RS,0);
	Hsend_falling_edge();

	#elif defined four_bits_mode
	Mwrite_high_nibble(PORTA,cmd>>4);
	MDIO_voidSetPinValue(PORTA,RS,0);
	Hsend_falling_edge();
	Mwrite_high_nibble(PORTA,cmd);
	MDIO_voidSetPinValue(PORTA,RS,0);
	Hsend_falling_edge();
	#endif
	_delay_ms(1);
}

void HLCD_Send_char(u8 data) // HLCD_vSend_Data(u8 data)
{
	#if defined eight_bits_mode
	MDIO_voidSetPortValue(PORTA,data);
	MDIO_voidSetPinValue(PORTB,RS,1);
	Hsend_falling_edge();

	#elif defined four_bits_mode
	Mwrite_high_nibble(PORTA,data>>4);
	MDIO_voidSetPinValue(PORTA,RS,1);
	Hsend_falling_edge();
	Mwrite_high_nibble(PORTA,data);
	MDIO_voidSetPinValue(PORTA,RS,1);
	Hsend_falling_edge();
	#endif
	_delay_ms(1);
}


void HLCD_Send_string(u8 *data)
{
	while((*data)!='\0')
	{
		HLCD_Send_char(*data);
		data++;
	}
}
void HLCD_clearscreen()
{
	HLCD_Send_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void HLCD_movecursor(u8 row,u8 coloumn)
{
	u8 data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	HLCD_Send_cmd(data);
	_delay_ms(1);
}



