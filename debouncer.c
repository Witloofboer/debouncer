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

int counter;
uint8_t debounced = 0;
uint8_t sw;

extern uint8_t getKey(void);

void debounce(uint8_t *changed, uint8_t *pressed)
{
	sw = getKey();

	if (sw == debounced) {
		if (debounced) {
			counter = RELEASE_MSEC/CHECK_MSEC;
		} else {
			counter = PRESS_MSEC/CHECK_MSEC;
		}
	} else {
		if (--counter == 0) {
			debounced = sw;
			change = true;
			if (debounced) {
				counter = RELEASE_MSEC/CHECK_MSEC;
			} else {
				counter = PRESS_MSEC/CHECK_MSEC;
			}
		}
	} 
}
