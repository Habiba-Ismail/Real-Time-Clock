/*
 * main.c
 *
 *  Created on: Sep 7, 2023
 *      Author: hp
 */
#include "../MCAL/DIO/DIO.h"
#include "../HAL/7SEGMENT/7SEGMENT.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../Lib/BIT_MATH.h"
#include "../MCAL/TIMER/TIMER.h"
#include <util/delay.h>

u8 seconds_counter=0,
   minutes_counter=0,
     hours_counter=0;
		;
u8 value,first_digit,second_digit;
int main(void)
{
	Hkeypad_Init();
	HLCD_Init();
	Hseven_seg_vinit(PORTB);
	MDIO_voidSetPortDirection(PORTC,0xff);
	HLCD_Send_string("press 1 to");
	HLCD_movecursor(2,1);
	HLCD_Send_string("set clock");
	Mtimer_overflow_init_interrupt();

	while(1)
	{
	value=Hkeypad_u8check_press();
	if (value!=NOTPRESSED)
	{
		if (value=='1')
		{

			HLCD_clearscreen();
			HLCD_Send_string("hours=--");
			HLCD_movecursor(1,7);
			_delay_ms(500);
			do
			{
				first_digit=Hkeypad_u8check_press();

			} while (first_digit==NOTPRESSED);
			HLCD_Send_char(first_digit);
			_delay_ms(300);
			do
			{
				second_digit=Hkeypad_u8check_press();

			} while (second_digit==NOTPRESSED);
			HLCD_Send_char(second_digit);
			_delay_ms(300);
			hours_counter=(second_digit-48)
						  +10*(first_digit-48);
			HLCD_clearscreen();

			HLCD_Send_string("minutes=--");
			HLCD_movecursor(1,9);
			do
			{
				first_digit=Hkeypad_u8check_press();

			} while (first_digit==NOTPRESSED);
			HLCD_Send_char(first_digit);
			_delay_ms(300);
			do
			{
				second_digit=Hkeypad_u8check_press();

			} while (second_digit==NOTPRESSED);
			HLCD_Send_char(second_digit);
			_delay_ms(300);
			minutes_counter=(second_digit-48)
						  +10*(first_digit-48);
			HLCD_clearscreen();

			HLCD_Send_string("seconds=--");
			HLCD_movecursor(1,9);

			do
			{
				first_digit=Hkeypad_u8check_press();

			} while (first_digit==NOTPRESSED);
			HLCD_Send_char(first_digit);
			_delay_ms(300);
			do
			{
				second_digit=Hkeypad_u8check_press();

			} while (second_digit==NOTPRESSED);
			HLCD_Send_char(second_digit);
			_delay_ms(300);
			seconds_counter=(second_digit-48)
						  +10*(first_digit-48);
			HLCD_clearscreen();
			HLCD_Send_string("press 1 to");
			HLCD_movecursor(2,1);
			HLCD_Send_string("set clock");
		}
		else
		{
			HLCD_clearscreen();
			HLCD_Send_string("wrong choice");
			_delay_ms(1000);
			HLCD_clearscreen();
			HLCD_Send_string("press 1 to");
			HLCD_movecursor(2,1);
			HLCD_Send_string("set clock");
		}
		}

		SET_BIT(DIO_PORTC_REG,1);
		SET_BIT(DIO_PORTC_REG,2);
		SET_BIT(DIO_PORTC_REG,3);
		SET_BIT(DIO_PORTC_REG,4);
		SET_BIT(DIO_PORTC_REG,5);
		CLR_BIT(DIO_PORTC_REG,0);
		Hseven_seg_write(PORTB,seconds_counter%10);
		_delay_ms(5);

        SET_BIT(DIO_PORTC_REG,0);
		SET_BIT(DIO_PORTC_REG,2);
		SET_BIT(DIO_PORTC_REG,3);
		SET_BIT(DIO_PORTC_REG,4);
		SET_BIT(DIO_PORTC_REG,5);
		CLR_BIT(DIO_PORTC_REG,1);
		Hseven_seg_write(PORTB,seconds_counter/10);
		_delay_ms(5);

		SET_BIT(DIO_PORTC_REG,0);
		SET_BIT(DIO_PORTC_REG,1);
		SET_BIT(DIO_PORTC_REG,3);
		SET_BIT(DIO_PORTC_REG,4);
		SET_BIT(DIO_PORTC_REG,5);
		CLR_BIT(DIO_PORTC_REG,2);
		Hseven_seg_write(PORTB,minutes_counter%10);
		_delay_ms(5);

		SET_BIT(DIO_PORTC_REG,0);
		SET_BIT(DIO_PORTC_REG,1);
		SET_BIT(DIO_PORTC_REG,2);
		SET_BIT(DIO_PORTC_REG,4);
		SET_BIT(DIO_PORTC_REG,5);
		CLR_BIT(DIO_PORTC_REG,3);
		Hseven_seg_write(PORTB,minutes_counter/10);
		_delay_ms(5);

		SET_BIT(DIO_PORTC_REG,0);
		SET_BIT(DIO_PORTC_REG,1);
		SET_BIT(DIO_PORTC_REG,2);
		SET_BIT(DIO_PORTC_REG,3);
		SET_BIT(DIO_PORTC_REG,5);
		CLR_BIT(DIO_PORTC_REG,4);
		Hseven_seg_write(PORTB,hours_counter%10);
		_delay_ms(5);

		SET_BIT(DIO_PORTC_REG,0);
		SET_BIT(DIO_PORTC_REG,1);
		SET_BIT(DIO_PORTC_REG,2);
		SET_BIT(DIO_PORTC_REG,3);
		SET_BIT(DIO_PORTC_REG,4);
		CLR_BIT(DIO_PORTC_REG,5);
		Hseven_seg_write(PORTB,hours_counter/10);
		_delay_ms(5);

		if (seconds_counter==60)
		{
			seconds_counter=0;
			minutes_counter++;
		}
		if (minutes_counter==60)
		{
			minutes_counter=0;
			hours_counter++;
		}
		if (hours_counter==24)
		{
			hours_counter=0;
		}
	}

}

void __vector_11 (void) __attribute__ ((signal));

void __vector_11 (void)
{
	  static u32 A_u32_counter = 0;

	  A_u32_counter ++;

	if(A_u32_counter == 123)
	{
	A_u32_counter =0;
	TCNT0 = 238;
	seconds_counter++;
	}
}



