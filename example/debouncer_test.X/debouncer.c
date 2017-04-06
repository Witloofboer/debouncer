/*
 * DEBOUNCER.c
 * 
 * The code included in this file and the debouncer.h file offer a software 
 * debouncer based on the article found here: 
 * http://www.ganssle.com/debouncing.htm.
 * 
 * 
 * (c) Witloofboer 2017
 * 
 * LICENSING: Everyone is free to use this code EXCEPT if you want to use it
 * to operate weapons, nuclear facilities, life support or other mission
 * critical applications where human or animal life or property may be at stake.
 */

#include "debouncer.h"
#include "mcc_generated_files/pin_manager.h"

//extern uint8_t getKey(void);

void debounce(debouncer_t *debouncer)
{
	debouncer->sw = Button_GetValue();

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