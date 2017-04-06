/*
 * File:   main.c
 * Author: Witloofboer
 *
 * Created on 29 maart 2017, 11:49
 */


#include <xc.h>
#include "debouncer.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"


// Button_GetValue() is a define, not a function, so no function pointers were 
// available
int button(void) {
    return Button_GetValue();
}

debouncer_t debo;

void main(void) {
    
    debo.getKey = (*button);
    
    // Initialize the microcontroller
    SYSTEM_Initialize();
    PIN_MANAGER_Initialize();
    
    // Enable interrupts from timer (Global instead of Peripheral, was tested)
    INTERRUPT_GlobalInterruptEnable();
    
    while ( 1 ) {
        if ( debo.sw ) {
            LED_SetLow();
        } else {
            LED_SetHigh();
        }
        
    }
}
