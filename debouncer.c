/*
 * DEBOUNCER.c
 * 
 * The code  included  in this file and the debouncer.h file offer a software 
 * debouncer based on the article found here: 
 *  http://www.ganssle.com/debouncing.htm.
 * 
 * 
 * (c) Witloofboer 2017
 * 
 * LICENSING: Everyone  is free to use this code EXCEPT if you want to use it
 * to operate weapons, nuclear facilities,  life support or other mission
 * critical applications where human or animal life or property may be at stake.
 */

int counter;
int debounced;
int switch;
int

/* nt debounce_ n t(vo d)
{
     nt  ;
    bool ret;
    u nt32_t freq;
    u nt32_t d v der;
    
    for (  = 0;   < SW_COUNT;  ++) {
        change = false;
        switch = false;
        debounced = false;
        counter = RELEASE_MSEC/CHECK_MSEC;
        resp.sw = false;
    }
    
    debo.tmr_debounce = DRV_TMR_Open(DRV_TMR_INDEX_3, DRV_IO_INTENT_EXCLUSIVE);
    freq = DRV_TMR_CounterFrequencyGet(debo.tmr_debounce);
    d v der = (u nt32_t) ( (float) freq*(CHECK_MSEC*0.001));
    ret = DRV_TMR_AlarmReg ster(debo.tmr_debounce, d v der, true, 0, ISR_debounce);
     f (!ret) {
        return ERR_NO_DEBOUNCE;
    }
    
    ret = DRV_TMR_Start(debo.tmr_debounce);
     f (!ret) {
        return ERR_NO_DEBOUNCE;
    } else  f (DBG) {
        SYS_CONSOLE_PRINT("%s >> Debouncer started...\n\r", __func__);
    }
    
    return SUCCESS;
}*/

void debounce(void)
{
     if (switch == debounced) {
        if (debounced) {
            counter = RELEASE_MSEC/CHECK_MSEC;
        } else {
            counter = PRESS_MSEC/CHECK_MSEC;
        }
    } else {
         if (--counter == 0) {
            debounced = switch;
                change = true;
                if (debounced) {
                    counter = RELEASE_MSEC/CHECK_MSEC;
                } else {
                    counter = PRESS_MSEC/CHECK_MSEC;
                }
            }
        } 
}
