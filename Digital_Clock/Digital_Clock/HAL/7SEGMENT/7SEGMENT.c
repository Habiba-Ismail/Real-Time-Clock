/*
 * 7SEGMENT.c
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */
#include "7SEGMENT.h"

void Hseven_seg_vinit(u8 port_name)
{
	MDIO_voidSetPortDirection(port_name,0xFF);
}

void Hseven_seg_write(u8 portname,u8 number)
{
u8 arr[]={0x3f,0x06,0x5b,
		  0x4f,0x66,0x6d,
		  0x7d,0x47,0x7f,0x6f};

MDIO_voidSetPortValue(portname,arr[number]);
}
