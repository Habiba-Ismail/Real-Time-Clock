/*
 * GIE.c
 *
 *  Created on: Sep 7, 2023
 *      Author: hp
 */

#include "GIE.h"

#define SREG_REG  *((volatile u8 *)0x5F)

void MGIE_Enable()
{
	SET_BIT(SREG_REG,7);
}
void MGIE_disable()
{
	SET_BIT(SREG_REG,7);
}


