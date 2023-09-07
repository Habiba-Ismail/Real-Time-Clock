/*
 * TIMER_private.h
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TIMSK			*((volatile u8*)0X59)
#define TCCR0			*((volatile u8*)0X53)
#define TCCR2			*((volatile u8*)0X45)
#define OCR0            *((volatile u8*)(0x5C))

#define CS20  0
#define CS22  2
#define CS00  0
#define CS02  2

#define COM00 4
#define COM01 5
#define OCIE0 1

#define ASSR            *((volatile u8*)0X42)
#define AS2             3
#define TOIE2		    6
#define TOIE0		    0

#define TCNT0		    *((volatile u8*)0X52)

#define WGM01  3
#define WGM00  6



#define TIMSK_OCIE0		1
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02      2
#define TCCR0_CS00		0



#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
