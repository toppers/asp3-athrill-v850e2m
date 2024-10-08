/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#include "tISR_tecsgen.h"
#include "tISR_factory.h"


/* entry port descriptor referenced by call port (differ from actual definition) #_CPEPD_# */
extern struct tag_siHandlerBody_VDES SIOPortTarget1_SCIF_eiRxISR_des;

extern struct tag_siHandlerBody_VDES SIOPortTarget1_SCIF_eiTxISR_des;

/* call port array #_CPA_# */


/* array of attr/var #_AVAI_# */
/* cell INIB #_INIB_# */
tISR_INIB tISR_INIB_tab[] = {
    /* cell: tISR_CB_tab[0]:  SIOPortTarget1_RxISRInstance id=1 */
    {
        /* call port (INIB) #_CP_# */ 
        &SIOPortTarget1_SCIF_eiRxISR_des,        /* ciISRBody #_CCP1_# */
        /* attribute(RO) */ 
        ISRID_tISR_SIOPortTarget1_RxISRInstance, /* id */
    },
    /* cell: tISR_CB_tab[1]:  SIOPortTarget1_TxISRInstance id=2 */
    {
        /* call port (INIB) #_CP_# */ 
        &SIOPortTarget1_SCIF_eiTxISR_des,        /* ciISRBody #_CCP1_# */
        /* attribute(RO) */ 
        ISRID_tISR_SIOPortTarget1_TxISRInstance, /* id */
    },
};

/* entry port descriptor #_EPD_# */
/* CB initialize code #_CIC_# */
void
tISR_CB_initialize()
{
    tISR_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
