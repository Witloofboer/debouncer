/*
 * File:   main.c
 * Author: cedric.busschots
 *
 * Created on 29 maart 2017, 11:49
 */


#include <xc.h>
#include "debouncer.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"

debouncer_t debo;

void main(void) {
    
    //uint8_t sw;
    
    // Initialize the microcontroller
    SYSTEM_Initialize();
    PIN_MANAGER_Initialize();
    
    // Enable interrupts from timer (Global instead of Peripheral, was tested)
    INTERRUPT_GlobalInterruptEnable();
    
    while ( 1 ) {
        //sw = Button_GetValue();
        if ( debo.sw ) {
            LED_SetLow();
        } else {
            LED_SetHigh();
        }
        
    }
}
