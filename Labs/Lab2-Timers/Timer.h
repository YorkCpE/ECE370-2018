/*
 * Timer.h
 *
 *  Created on: Jun 7, 2017
 *      Author: Jason Forsyth
 *
 *      Modified June 5, 2018
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include <em_timer.h>

#include <stdint.h>
#include <stdbool.h>

#include "Helper.h"

///Useful location for #define statement to help with masks
/// #define here
///////

/**
 * Below are suggested functions to help you organize your code. You DO NOT have to use
 * these functions but they were helpful for my implementation. Encapsulating repeated and high-level
 * functionality here will make the main.cpp file earlier to debug and understand.
 */

/**
 * Start a specified timer
 * @param timer A pointer to TIMER_TypeDef object for the timer you wish to modify. Example: TIMER0, TIMER1...etc.
 */
inline void startTimer(TIMER_TypeDef* timer);

/**
 * Stop a specified timer
 * @param timer A pointer to TIMER_TypeDef object for the timer you wish to modify. Example: TIMER0, TIMER1...etc.
 */
inline void stopTimer(TIMER_TypeDef* timer);

#endif /* SRC_TIMER_H_ */
