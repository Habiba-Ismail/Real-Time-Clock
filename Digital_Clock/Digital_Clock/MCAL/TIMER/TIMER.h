/*
 * TIMER.h
 *
 *  Created on: Sep 3, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_
#include "TIMER_private.h"

void Mtimer_overflow_init_interrupt(void);

void Mtimer_CTC_init_interrupt(void);

void Mtimer_wave_nonPWM(void);

void Mtimer_wave_fastPWM(void);

void Mtimer_wave_phasecorrectPWM(void);

#endif /* MCAL_TIMER_TIMER_H_ */
