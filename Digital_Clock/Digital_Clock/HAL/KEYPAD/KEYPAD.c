/*
 * KEYPAD.c
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */
#include "KEYPAD.h"

void Hkeypad_Init()
 {
	 MDIO_voidSetPortDirection(PORTD,0x0f);
	 MDIO_voidSetPortValue(PORTD,0xff);

 }
 u8 Hkeypad_u8check_press()
 {
	 u8 arr[4][4]={{'7','8','9','/'},
			       {'4','5','6','*'},
			       {'1','2','3','-'},
			       {'A','0','=','+'}};
	 u8 row,coloumn,x;
	 u8 returnval=NOTPRESSED;
	 for(row=0;row<4;row++)
	 {

		MDIO_voidSetPinValue(PORTD,row,0);

		for(coloumn=0;coloumn<4;coloumn++)
		{
			x=MDIO_u8GetPinValue(PORTD,(coloumn+4));
			if(x==0)
			 {
				 returnval=arr[row][coloumn];
				 break;
			 }
		}
		MDIO_voidSetPinValue(PORTD,row,1);
	}
	 return returnval ;
 }
