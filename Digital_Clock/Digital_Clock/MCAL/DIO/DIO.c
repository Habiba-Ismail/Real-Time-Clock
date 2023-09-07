/*
 * DIO.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hp
 */

#include "DIO.h"

void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir)
{
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		if(0 == Copy_u8Dir)
		{
			switch(Copy_u8Port)
			{
				case PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
				case PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
				case PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
				case PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
			}
		}
		else if(1 == Copy_u8Dir)
		{
			switch(Copy_u8Port)
			{
				case PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
				case PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
				case PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
				case PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
			}
		}
	}
}

void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val)
{
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		if(0 == Copy_u8Val)
		{
			switch(Copy_u8Port)
			{
				case PORTA: CLR_BIT(DIO_PORTA_REG,Copy_u8Pin); break;
				case PORTB: CLR_BIT(DIO_PORTB_REG,Copy_u8Pin); break;
				case PORTC: CLR_BIT(DIO_PORTC_REG,Copy_u8Pin); break;
				case PORTD: CLR_BIT(DIO_PORTD_REG,Copy_u8Pin); break;
			}
		}
		else if(1 == Copy_u8Val)
		{
			switch(Copy_u8Port)
			{
				case PORTA: SET_BIT(DIO_PORTA_REG,Copy_u8Pin); break;
				case PORTB: SET_BIT(DIO_PORTB_REG,Copy_u8Pin); break;
				case PORTC: SET_BIT(DIO_PORTC_REG,Copy_u8Pin); break;
				case PORTD: SET_BIT(DIO_PORTD_REG,Copy_u8Pin); break;
			}
		}
	}
}

u8 MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Ret_Value;

	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		switch(Copy_u8Port)
		{
			case PORTA: Ret_Value = GET_BIT(PINA,Copy_u8Pin); break;
			case PORTB: Ret_Value = GET_BIT(PINB,Copy_u8Pin); break;
			case PORTC: Ret_Value = GET_BIT(PINC,Copy_u8Pin); break;
			case PORTD: Ret_Value = GET_BIT(PIND,Copy_u8Pin); break;
		}
	}

	return Ret_Value;
}


void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case PORTA: DDRA = Copy_u8Val; break;
		case PORTB: DDRB = Copy_u8Val; break;
		case PORTC: DDRC = Copy_u8Val; break;
		case PORTD: DDRD = Copy_u8Val; break;
	}
}

void MDIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case PORTA: DIO_PORTA_REG = Copy_u8Val; break;
		case PORTB: DIO_PORTB_REG = Copy_u8Val; break;
		case PORTC: DIO_PORTC_REG = Copy_u8Val; break;
		case PORTD: DIO_PORTD_REG = Copy_u8Val; break;
	}
}



void Mwrite_low_nibble(u8 Copy_u8Port,u8 Copy_u8Val)
{
	Copy_u8Val&=0x0f;
	switch(Copy_u8Port)
	{
		case PORTA:
			DIO_PORTA_REG&=0xf0;
			DIO_PORTA_REG|=Copy_u8Val;break;
		case PORTB:
			DIO_PORTB_REG&=0xf0;
			DIO_PORTB_REG|=Copy_u8Val;break;
		case PORTC:
			DIO_PORTC_REG&=0xf0;
			DIO_PORTC_REG|=Copy_u8Val;break;
		case PORTD:
			DIO_PORTD_REG&=0xf0;
			DIO_PORTD_REG|=Copy_u8Val;break;
	}
}

void Mwrite_high_nibble(u8 Copy_u8Port,u8 Copy_u8Val)
{
	Copy_u8Val<<=4;
	switch(Copy_u8Port)
	{
		case PORTA:
			DIO_PORTA_REG&=0x0f;
			DIO_PORTA_REG|=Copy_u8Val;break;
		case PORTB:
			DIO_PORTB_REG&=0x0f;
			DIO_PORTB_REG|=Copy_u8Val;break;
		case PORTC:
			DIO_PORTC_REG&=0x0f;
			DIO_PORTC_REG|=Copy_u8Val;break;
		case PORTD:
			DIO_PORTD_REG&=0x0f;
			DIO_PORTD_REG|=Copy_u8Val;break;
	}
}
