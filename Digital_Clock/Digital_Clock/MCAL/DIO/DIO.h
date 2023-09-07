/*
 * DIO.h
 *
 *  Created on: Sep 1, 2023
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

#define INPUT	0
#define OUTPUT	1

#define HIGH	1
#define LOW		0

#define DIO_PORTA_REG	*((volatile u8*)0x3B)
#define DDRA	        *((volatile u8*)0x3A)
#define PINA	        *((volatile u8*)0x39)

#define DIO_PORTB_REG	*((volatile u8*)0x38)
#define DDRB	        *((volatile u8*)0x37)
#define PINB	        *((volatile u8*)0x36)

#define DIO_PORTC_REG	*((volatile u8*)0x35)
#define DDRC	        *((volatile u8*)0x34)
#define PINC	        *((volatile u8*)0x33)

#define DIO_PORTD_REG	*((volatile u8*)0x32)
#define DDRD	        *((volatile u8*)0x31)
#define PIND	        *((volatile u8*)0x30)


void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir);
void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val);
u8   MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Val);
void MDIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Val);
void Mwrite_low_nibble(u8 Copy_u8Port,u8 Copy_u8Val);
void Mwrite_high_nibble(u8 Copy_u8Port,u8 Copy_u8Val);


#endif /* MCAL_DIO_DIO_H_ */
