/*
 * BIT_MATH.h
 *
 *  Created on: Aug 17, 2023
 *      Author: hp
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(reg,bitnum)    reg|=1<<bitnum
#define CLR_BIT(reg,bitnum)    reg&=~(1<<bitnum)
#define toggle_bit(reg,bitnum) reg^=1<<bitnum
#define GET_BIT(reg,bitnum)    (reg>>bitnum)&0x01
#define set_byte(reg,val)      (reg=val)


#endif /* LIB_BIT_MATH_H_ */
