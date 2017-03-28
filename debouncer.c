/*
 * DEBOUNCER.c
 * 
 * The code included in this file and the debouncer.h file offer a software 
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

/*int debounce_init(void)
{
    int i;
    bool ret;
    uint32_t freq;
    uint32_t divider;
    
    for (i = 0; i < SW_COUNT; i++) {
        debo.changed[i] = false;
        debo.rawpress[i] = false;
        debo.debounced[i] = false;
        debo.count[i] = RELEASE_MSEC/CHECK_MSEC;
        resp.sw[i] = false;
    }
    
    debo.tmr_debounce = DRV_TMR_Open(DRV_TMR_INDEX_3, DRV_IO_INTENT_EXCLUSIVE);
    freq = DRV_TMR_CounterFrequencyGet(debo.tmr_debounce);
    divider = (uint32_t) ( (float) freq*(CHECK_MSEC*0.001));
    ret = DRV_TMR_AlarmRegister(debo.tmr_debounce, divider, true, 0, ISR_debounce);
    if (!ret) {
        return ERR_NO_DEBOUNCE;
    }
    
    ret = DRV_TMR_Start(debo.tmr_debounce);
    if (!ret) {
        return ERR_NO_DEBOUNCE;
    } else if (DBG) {
        SYS_CONSOLE_PRINT("%s >> Debouncer started...\n\r", __func__);
    }
    
    return SUCCESS;
}*/

void debounce(uintptr_t context, uint32_t alarmCount)
{
    int i;
    
    if (debo.rawpress[i] == debo.debounced[i]) {
        if (debo.debounced[i]) {
            debo.count[i] = RELEASE_MSEC/CHECK_MSEC;
        } else {
            debo.count[i] = PRESS_MSEC/CHECK_MSEC;
        }
    } else {
        if (--debo.count[i] == 0) {
            debo.debounced[i] = debo.rawpress[i];
                debo.changed[i] = true;
                resp.sw[i] = debo.debounced[i];
                if (debo.debounced[i]) {
                    debo.count[i] = RELEASE_MSEC/CHECK_MSEC;
                } else {
                    debo.count[i] = PRESS_MSEC/CHECK_MSEC;
                }
            }
        } 
}