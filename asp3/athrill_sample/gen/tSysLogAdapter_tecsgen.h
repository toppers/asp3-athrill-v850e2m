/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tSysLogAdapter_TECSGEN_H
#define tSysLogAdapter_TECSGEN_H

/*
 * celltype          :  tSysLogAdapter
 * global name       :  tSysLogAdapter
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  false
 * has_INIB          :  0
 * rom               :  yes
 * CB initializer    :  yes
 */

/* global header #_IGH_# */
#include "global_tecsgen.h"

/* signature header #_ISH_# */
#include "sSysLog_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell INIB type definition #_CIP_# */
typedef const struct tag_tSysLogAdapter_INIB {
    /* call port #_TCP_# */
}  tSysLogAdapter_INIB;

/* CB not exist. CB corresponding to INIB #_DCI_# */
#define tSysLogAdapter_CB_tab           tSysLogAdapter_INIB_tab
#define tSysLogAdapter_SINGLE_CELL_CB   tSysLogAdapter_SINGLE_CELL_INIB
#define tSysLogAdapter_CB               tSysLogAdapter_INIB
#define tag_tSysLogAdapter_CB           tag_tSysLogAdapter_INIB

/* singleton cell CB prototype declaration #_SCP_# */
extern  tSysLogAdapter_INIB  tSysLogAdapter_SINGLE_CELL_INIB;


/* celltype IDX type #_CTIX_# */
typedef const struct tag_tSysLogAdapter_INIB *tSysLogAdapter_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSysLogAdapter_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSysLog_tecsgen.h"
#ifdef  tSysLogAdapter_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSysLogAdapter_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY


/* celll CB macro #_GCB_# */
#define tSysLogAdapter_GET_CELLCB(idx) ((void *)0)
 /* call port function macro #_CPM_# */
#define tSysLogAdapter_cSysLog_write( priority, p_syslog ) \
	  tSysLog_eSysLog_write( \
	    (priority), (p_syslog) )
#define tSysLogAdapter_cSysLog_read( p_syslog ) \
	  tSysLog_eSysLog_read( \
	    (p_syslog) )
#define tSysLogAdapter_cSysLog_mask( logMask, lowMask ) \
	  tSysLog_eSysLog_mask( \
	    (logMask), (lowMask) )
#define tSysLogAdapter_cSysLog_refer( pk_rlog ) \
	  tSysLog_eSysLog_refer( \
	    (pk_rlog) )
#define tSysLogAdapter_cSysLog_flush( ) \
	  tSysLog_eSysLog_flush( \
	    )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tSysLogAdapter_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tSysLogAdapter_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tSysLogAdapter_IDX

/* call port function macro (abbrev) #_CPMA_# */
#define cSysLog_write( priority, p_syslog ) \
          tSysLogAdapter_cSysLog_write( priority, p_syslog )
#define cSysLog_read( p_syslog ) \
          tSysLogAdapter_cSysLog_read( p_syslog )
#define cSysLog_mask( logMask, lowMask ) \
          tSysLogAdapter_cSysLog_mask( logMask, lowMask )
#define cSysLog_refer( pk_rlog ) \
          tSysLogAdapter_cSysLog_refer( pk_rlog )
#define cSysLog_flush( ) \
          tSysLogAdapter_cSysLog_flush( )



/* CB initialize macro #_CIM_# */
#define INITIALIZE_CB()
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSysLogAdapter_TECSGENH */