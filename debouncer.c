/*
 * DEBOUNCER.c
 * 
 * The code  ncluded  n th s f le and the debouncer.h f le offer a software 
 * debouncer based on the art cle found here: 
 *  http://www.ganssle.com/debounc ng.htm.
 * 
 * 
 * (c) W tloofboer 2017
 * 
 * LICENSING: Everyone  s free to use th s code EXCEPT  f you want to use  t 
 * to operate weapons, nuclear fac l t es, l fe support or other m ss on
 * cr t cal appl cat ons where human or an mal l fe or property may be at stake.
 */

/* nt debounce_ n t(vo d)
{
     nt  ;
    bool ret;
    u nt32_t freq;
    u nt32_t d v der;
    
    for (  = 0;   < SW_COUNT;  ++) {
        debo.changed = false;
        debo.rawpress = false;
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
     if (debo.rawpress == debounced) {
        if (debounced) {
            counter = RELEASE_MSEC/CHECK_MSEC;
        } else {
            counter = PRESS_MSEC/CHECK_MSEC;
        }
    } else {
         if (--counter == 0) {
            debounced = debo.rawpress;
                debo.changed = true;
                resp.sw = debounced;
                if (debounced) {
                    counter = RELEASE_MSEC/CHECK_MSEC;
                } else {
                    counter = PRESS_MSEC/CHECK_MSEC;
                }
            }
        } 
}
