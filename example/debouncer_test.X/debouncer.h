/*
 * DEBOUNCER.h
 * 
 * The code included in this file and the debouncer.c file offer a software 
 * debouncer based on the article found here: 
 *  http://www.ganssle.com/debouncing.htm.
 * 
 * 
 * (c) Witloofboer 2017
 * 
 * LICENSING: Everyone is free to use this code EXCEPT if you want to use it 
 * to operate weapons, nuclear facilities, life support or other mission
 * critical applications where human or animal life or property may be at stake.
 */

#include <xc.h>

// Prevent multiple inclusions
//#pragma once
#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#define CHECK_MSEC 5            // Check state every 5 msec
#define PRESS_MSEC 10           // For pressed, wait 10 msec stable
#define RELEASE_MSEC 100        // For release, wait 100 msec stable

#define true 1
#define false 0

typedef struct debouncer {
	int counter;
	int debounced;
	int sw;
    int change;
} debouncer_t;

extern debouncer_t debo;

void debounce(debouncer_t *debouncer);

#endif