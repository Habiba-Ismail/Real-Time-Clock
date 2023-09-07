/*
 * KEYPAD.h
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

#define NOTPRESSED 0xff
void Hkeypad_Init();
u8   Hkeypad_u8check_press();

#endif /* HAL_KEYPAD_KEYPAD_H_ */
