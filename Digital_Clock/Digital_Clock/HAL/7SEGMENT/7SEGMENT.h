/*
 * 7SEGMENT.h
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */

#ifndef HAL_7SEGMENT_7SEGMENT_H_
#define HAL_7SEGMENT_7SEGMENT_H_
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

void Hseven_seg_vinit(u8 Copy_u8Port);
void Hseven_seg_write(u8 Copy_u8Port,u8 number);

#endif /* HAL_7SEGMENT_7SEGMENT_H_ */
