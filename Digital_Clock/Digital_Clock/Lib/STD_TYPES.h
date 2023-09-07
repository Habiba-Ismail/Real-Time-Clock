/*
 * STD_TYPES.h
 *
 *  Created on: Aug 17, 2023
 *      Author: hp
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_
typedef unsigned char        u8; //256      //1B
typedef unsigned short int   u16;			//2B
typedef unsigned int         u32;			//4B
typedef unsigned long long   u64;			//8B

typedef signed char          s8; //127
typedef signed short int     s16;
typedef signed int           s32;
typedef signed long long     s64;

typedef float                f32;			//4B
typedef double               f64;			//8B
#define IDLE 			0
#define BUSY			1
#define BUSY_STATE	 	3
#define NULL            0
#define OK           	0
#define NOK          	1
#define NULL_POINTER 	2

#endif /* LIB_STD_TYPES_H_ */
