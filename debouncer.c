/*
 * DEBOUNCER.c
 * 
 * The code included in this file and the debouncer.h file offer a software
 * debouncer based on the article found here:
 * http://www.ganssle.com/debouncing.htm.
 * 
 */

#include "debouncer.h"


void debounce(debouncer_t *debouncer)
{
	debouncer->sw = debouncer->getKey();

	if (debouncer->sw == debouncer->debounced) {
		if (debouncer->debounced) {
			debouncer->counter = RELEASE_MSEC/CHECK_MSEC;
		} else {
			debouncer->counter = PRESS_MSEC/CHECK_MSEC;
		}
	} else {
		if (--debouncer->counter == 0) {
			debouncer->debounced = debouncer->sw;
			debouncer->change = true;
			if (debouncer->debounced) {
				debouncer->counter = RELEASE_MSEC/CHECK_MSEC;
			} else {
				debouncer->counter = PRESS_MSEC/CHECK_MSEC;
			}
		}
	}
}
