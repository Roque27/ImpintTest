
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[10];
};
static struct sqlcxp sqlfpn =
{
    9,
    "impint.pc"
};


static unsigned int sqlctx = 38331;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[33];
   unsigned long  sqhstl[33];
            int   sqhsts[33];
            short *sqindv[33];
            int   sqinds[33];
   unsigned long  sqharm[33];
   unsigned long  *sqharc[33];
   unsigned short  sqadto[33];
   unsigned short  sqtdso[33];
} sqlstm = {12,33};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ unsigned char *, signed int * _*/);

 static char *sq0011 = 
"select o.trt_numero ,o.ord_numero ,o.srv_codigo ,o.cnt_numero ,nvl(o.tor_cod\
igo,'') ,to_char(o.ord_fecha_generacion,'dd/mm/yyyy') ,u.scf_codigo ,o.sec_cod\
igo_origen ,t.tor_grupo ,t.tor_descripcion ,o.prs_numero ,o.rowid   from orden\
ativos o ,tipos_ordenativo t ,usuarios u where (((((((((t.tor_codigo=:b0 and o\
.tor_codigo=t.tor_codigo) and u.usr_codigo=:b1) and o.scf_codigo_origen=:b2) a\
nd o.sec_codigo_origen=:b3) and o.ord_numero between :b4 and :b5) and o.crr_ti\
po=:b6) and o.crr_codigo=:b7) and o.ord_situacion='P') and o.ord_estado='D') o\
rder by o.ord_numero            ";

 static char *sq0025 = 
"select ENO.ENO_ORDEN ,ENO.ENO_TIPO ,ENO.ENO_TEXTO ,ENO.ENO_VAR_NOMBRE ,ENO.E\
NO_VAR_TIPO ,ENO.ENO_VAR_LONGITUD ,ENO.ENO_COL# ,ENO.ENO_TIPO_CAMPO  from ESTR\
UCTURA_NOTIFICACION ENO ,SERVICIOS SRV where (((ENO.NOT_CODIGO=:b0 and SRV.SRV\
_CODIGO=:b1) and NVL(ENO.SCF_CODIGO,SRV.SCF_CODIGO)=SRV.SCF_CODIGO) and ENO.EN\
O_ORDEN not  in (select distinct NVL(ENO_SUB_ORDEN,0)  from ESTRUCTURA_NOTIFIC\
ACION where (NOT_CODIGO=:b0 and SCF_CODIGO=SRV.SCF_CODIGO))) order by ENO.ENO_\
ORDEN            ";

 static char *sq0042 = 
"select U.URC_DESCRIPCION_ALT  from UNIDADES_REC_COBRO C ,UNIDADES_RECAUDADOR\
AS U where ((C.AGF_CODIGO=:b0 and C.UCO_TIPO='A') and U.URC_CODIGO=C.URC_CODIG\
O)           ";

 static char *sq0046 = 
"select DOC_NUMERO ,DOC_TIPO ,to_char(DOC_FECHA_EMISION,'dd/mm/yyyy') ,DOC_PE\
RIODO ,DOC_ANIO ,DOC_CUOTA ,DOC_TIPO_ORIGEN ,DOC_NUMERO_ORIGEN ,DOC_CONSUMO ,O\
RD_NUMERO ,URC_CODIGO ,ASI_NUMERO ,DOC_IMPORTE ,DOC_IMPORTE_BASICO ,nvl(DOC_SA\
LDO,DOC_IMPORTE) ,to_char(DOC_FECHA_VENC,'dd/mm/yy') ,to_char(DOC_FECHA_VENC_1\
,'dd/mm/yyyy') ,to_char(DOC_FECHA_VENC_2,'dd/mm/yyyy') ,DOC_RECARGO_VENC_2 ,to\
_char(DOC_FECHA_VENC_3,'dd/mm/yyyy') ,DOC_RECARGO_VENC_3 ,DOC_ESTADO ,decode(d\
oc_situacion,'X','(*)','C1','(*)','C2','(*)','C3','(*)','   ') LLAMADA_SIT_X  \
from DOCUMENTOS where ((TRT_NUMERO=:b0 and nvl(nvl(DOC_SALDO,DOC_IMPORTE),0)>0\
) and doc_situacion<>'X') order by DOC_FECHA_VENC_1            ";

 static char *sq0047 = 
"select d.DOC_NUMERO ,d.DOC_TIPO ,to_char(d.DOC_FECHA_EMISION,'dd/mm/yyyy') ,\
d.DOC_PERIODO ,d.DOC_ANIO ,d.DOC_CUOTA ,d.DOC_TIPO_ORIGEN ,d.DOC_NUMERO_ORIGEN\
 ,d.DOC_CONSUMO ,d.ORD_NUMERO ,d.URC_CODIGO ,d.ASI_NUMERO ,d.DOC_IMPORTE ,d.DO\
C_IMPORTE_BASICO ,nvl(d.DOC_SALDO,d.DOC_IMPORTE) ,to_char(d.DOC_FECHA_VENC,'dd\
/mm/yy') ,to_char(d.DOC_FECHA_VENC_1,'dd/mm/yyyy') ,to_char(d.DOC_FECHA_VENC_2\
,'dd/mm/yyyy') ,d.DOC_RECARGO_VENC_2 ,to_char(d.DOC_FECHA_VENC_3,'dd/mm/yyyy')\
 ,d.DOC_RECARGO_VENC_3 ,d.DOC_ESTADO ,decode(d.doc_situacion,'X','(*)','   ') \
LLAMADA_SIT_X  from documentos d ,documentos_estadistica_view de where ((((nvl\
(nvl(d.DOC_SALDO,d.DOC_IMPORTE),0)>0 and d.doc_tipo=de.doc_tipo) and d.doc_num\
ero=de.doc_numero) and de.ord_numero=:b0) and d.doc_situacion<>'X') order by D\
OC_FECHA_VENC_1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,31,0,0,
5,0,0,1,53,0,257,222,0,0,0,0,0,1,0,
20,0,0,2,67,0,260,225,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,3,62,0,260,236,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
62,0,0,4,75,0,260,245,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
85,0,0,5,79,0,260,256,0,0,1,0,0,1,0,2,4,0,0,
104,0,0,6,212,0,260,272,0,0,6,3,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
143,0,0,7,51,0,260,298,0,0,1,0,0,1,0,2,3,0,0,
162,0,0,8,58,0,262,327,0,0,1,1,0,1,0,2,9,0,0,
181,0,0,9,157,0,259,336,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,
208,0,0,10,0,0,285,349,0,0,0,0,0,1,0,
223,0,0,11,576,0,265,400,0,0,8,8,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,3,0,0,
1,3,0,0,1,9,0,0,1,9,0,0,
270,0,0,11,0,0,269,415,0,0,12,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
333,0,0,12,644,0,260,496,0,0,12,1,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,3,0,0,
396,0,0,13,747,0,260,527,0,0,13,2,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,3,0,0,1,3,0,0,
463,0,0,14,335,0,260,564,0,0,7,2,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1,3,0,0,1,3,0,0,
506,0,0,15,105,0,260,655,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,
533,0,0,16,54,0,261,718,0,0,2,2,0,1,0,1,3,0,0,1,9,0,0,
556,0,0,17,72,0,261,725,0,0,2,2,0,1,0,1,3,0,0,1,9,0,0,
579,0,0,18,145,0,261,737,0,0,2,2,0,1,0,1,3,0,0,1,9,0,0,
602,0,0,19,0,0,285,750,0,0,0,0,0,1,0,
617,0,0,11,0,0,271,759,0,0,0,0,0,1,0,
632,0,0,20,86,0,262,775,0,0,2,2,0,1,0,2,9,0,0,1,9,0,0,
655,0,0,21,64,0,261,784,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
678,0,0,22,0,0,285,787,0,0,0,0,0,1,0,
693,0,0,23,92,0,260,966,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
716,0,0,24,51,0,260,975,0,0,1,0,0,1,0,2,3,0,0,
735,0,0,26,93,0,260,1140,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,
762,0,0,25,483,0,265,1156,0,0,3,3,0,1,0,1,9,0,0,1,3,0,0,1,9,0,0,
789,0,0,25,0,0,269,1163,0,0,8,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,2,4,0,0,2,9,0,0,
836,0,0,27,72,0,260,1238,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,
863,0,0,25,0,0,271,1378,0,0,0,0,0,1,0,
878,0,0,28,605,0,260,1448,0,0,17,1,0,1,0,2,3,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,1,3,0,0,
961,0,0,29,89,0,260,1540,0,0,2,1,0,1,0,2,9,0,0,1,4,0,0,
984,0,0,30,89,0,260,1600,0,0,2,1,0,1,0,2,9,0,0,1,4,0,0,
1007,0,0,31,960,0,260,1730,0,0,33,2,0,1,0,2,3,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,3,0,0,1,3,0,0,
1154,0,0,32,552,0,260,1910,0,0,12,1,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,1,3,0,0,
1217,0,0,33,92,0,260,1946,0,0,2,1,0,1,0,2,9,0,0,1,3,0,0,
1240,0,0,34,92,0,260,2026,0,0,2,1,0,1,0,2,9,0,0,1,3,0,0,
1263,0,0,35,722,0,260,2177,0,0,24,1,0,1,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,
0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,3,0,0,
1374,0,0,36,92,0,260,2433,0,0,2,1,0,1,0,2,9,0,0,1,3,0,0,
1397,0,0,37,127,0,260,2523,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
1420,0,0,38,347,0,260,2564,0,0,9,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,3,0,0,1,3,0,0,
1471,0,0,39,290,0,260,2675,0,0,5,4,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,
1506,0,0,40,188,0,260,2718,0,0,3,1,0,1,0,2,4,0,0,2,9,0,0,1,3,0,0,
1533,0,0,41,91,0,260,2757,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,3,0,0,
1560,0,0,42,167,0,265,2805,0,0,1,1,0,1,0,1,3,0,0,
1579,0,0,42,0,0,269,2806,0,0,1,0,0,1,0,2,9,0,0,
1598,0,0,42,0,0,271,2808,0,0,0,0,0,1,0,
1613,0,0,43,291,0,260,2858,0,0,5,4,0,1,0,1,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,
1648,0,0,44,68,0,260,2897,0,0,2,1,0,1,0,2,9,0,0,1,3,0,0,
1671,0,0,45,66,0,260,2928,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1694,0,0,46,685,0,265,3088,0,0,1,1,0,1,0,1,3,0,0,
1713,0,0,47,805,0,265,3090,0,0,1,1,0,1,0,1,3,0,0,
1732,0,0,46,0,0,269,3104,0,0,23,0,0,1,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
1839,0,0,47,0,0,269,3131,0,0,23,0,0,1,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
1946,0,0,46,0,0,271,3289,0,0,0,0,0,1,0,
1961,0,0,47,0,0,271,3291,0,0,0,0,0,1,0,
1976,0,0,48,107,0,260,3319,0,0,4,1,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,1,3,0,0,
2007,0,0,49,120,0,260,3360,0,0,1,0,0,1,0,2,9,0,0,
2026,0,0,50,84,0,260,3387,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
2053,0,0,51,515,0,260,3464,0,0,16,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,1,9,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <olib.h>
#include <clib.h>
#include <oratype.h>
#include <rwwccnts.h>
#include <generic.h>
#include "gen_txt.h"
#include "depura.h"
/*
  Modificacion del 14-01-2001, para que imprima el codigo de barras
  requerido por SEND. Falta realizar pruebas de usuario, y pasar a
  produccion
*/
/* exec sql include sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/* exec sql include oraca;
 */ 
/*
 * $Header: oraca.h 24-apr-2003.12:50:59 mkandarp Exp $ oraca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  ORACA : Oracle Communications Area.
FUNCTION
  Contains no code. Provides supplementary communications to/from
  Oracle (in addition to standard SQLCA).
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  oracchf : Check cursor cache consistency flag. If set AND oradbgf
            is set, then directs SQLLIB to perform cursor cache
            consistency checks before every cursor operation
            (OPEN, FETCH, SELECT, INSERT, etc.).
  oradbgf : Master DEBUG flag. Used to turn all DEBUG options
            on or off.
  orahchf : Check Heap consistency flag. If set AND oradbgf is set,
            then directs SQLLIB to perform heap consistency checks
            everytime memory is dynamically allocated/free'd via
            sqlalc/sqlfre/sqlrlc. MUST BE SET BEFORE 1ST CONNECT
            and once set cannot be cleared (subsequent requests
            to change it are ignored).
  orastxtf: Save SQL stmt text flag. If set, then directs SQLLIB
            to save the text of the current SQL stmt in orastxt
            (in VARCHAR format).
  orastxt : Saved len and text of current SQL stmt (in VARCHAR
            format).
  orasfnm : Saved len and text of filename containing current SQL
            stmt (in VARCHAR format).
  oraslnr : Saved line nr within orasfnm of current SQL stmt.
 
  Cursor cache statistics. Set after COMMIT or ROLLBACK. Each
  CONNECT'd DATABASE has its own set of statistics.
 
  orahoc  : Highest Max Open OraCursors requested. Highest value
            for MAXOPENCURSORS by any CONNECT to this DATABASE.
  oramoc  : Max Open OraCursors required. Specifies the max nr
            of OraCursors required to run this pgm. Can be higher
            than orahoc if working set (MAXOPENCURSORS) was set
            too low, thus forcing the PCC to expand the cache.
  oracoc  : Current nr of OraCursors used.
  oranor  : Nr of OraCursor cache reassignments. Can show the
            degree of "thrashing" in the cache. Optimally, this
            nr should be kept as low as possible (time vs space
            optimization).
  oranpr  : Nr of SQL stmt "parses".
  oranex  : Nr of SQL stmt "executes". Optimally, the relation-
            ship of oranex to oranpr should be kept as high as
            possible.
 
 
  If the symbol ORACA_NONE is defined, then there will be no ORACA
  *variable*, although there will still be a struct defined.  This
  macro should not normally be defined in application code.

  If the symbol ORACA_INIT is defined, then the ORACA will be
  statically initialized. Although this is not necessary in order
  to use the ORACA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the ORACA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then ORACA_INIT should be left undefined --
  all others can define ORACA_INIT if they wish.
 
OWNER
  Clare
DATE
  10/19/85
MODIFIED
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for oraca
    pccint     10/03/96 -  Add IS_OSD for linting
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   09/04/92 -  Make oraca variable optional 
    Osborne    05/24/90 - Add ORACA_STORAGE_CLASS construct
  Clare      02/20/86 - PCC [10101l] Feature: Heap consistency check.
  Clare      03/04/86 - PCC [10101r] Port: ORACA init ifdef.
  Clare      03/12/86 - PCC [10101ab] Feature: ORACA cuc statistics.
*/
/* IS_OSD */ 
#ifndef  ORACA
#define  ORACA     1
 
struct   oraca
         {
    /* text */ char oracaid[8];      /* Reserved                            */
    /* ub4  */ int oracabc;          /* Reserved                            */
 
    /*       Flags which are setable by User. */
 
   /* ub4 */ int  oracchf;           /* <> 0 if "check cur cache consistncy"*/
   /* ub4 */ int  oradbgf;           /* <> 0 if "do DEBUG mode checking"    */
   /* ub4 */ int  orahchf;           /* <> 0 if "do Heap consistency check" */
   /* ub4 */ int  orastxtf;          /* SQL stmt text flag                  */
#define  ORASTFNON 0                 /* = don't save text of SQL stmt       */
#define  ORASTFERR 1                 /* = only save on SQLERROR             */
#define  ORASTFWRN 2                 /* = only save on SQLWARNING/SQLERROR  */
#define  ORASTFANY 3                 /* = always save                       */
         struct
           {
  /* ub2  */ unsigned short orastxtl;
  /* text */ char  orastxtc[70];
           } orastxt;                /* text of last SQL stmt               */
         struct
           {
  /* ub2  */   unsigned short orasfnml;
  /* text */   char       orasfnmc[70];
           } orasfnm;                /* name of file containing SQL stmt    */
  /* ub4 */ int   oraslnr;           /* line nr-within-file of SQL stmt     */

  /* ub4 */ int   orahoc;            /* highest max open OraCurs requested  */
  /* ub4 */ int   oramoc;            /* max open OraCursors required        */
  /* ub4 */ int   oracoc;            /* current OraCursors open             */
  /* ub4 */ int   oranor;            /* nr of OraCursor re-assignments      */
  /* ub4 */ int   oranpr;            /* nr of parses                        */
  /* ub4 */ int   oranex;            /* nr of executes                      */
         };

#ifndef ORACA_NONE

#ifdef ORACA_STORAGE_CLASS
ORACA_STORAGE_CLASS struct oraca oraca
#else
struct oraca oraca
#endif
#ifdef ORACA_INIT
         =
         {
         {'O','R','A','C','A',' ',' ',' '},
         sizeof(struct oraca),
         0,0,0,0,
         {0,{0}},
         {0,{0}},
         0,
         0,0,0,0,0,0
         }
#endif
         ;

#endif

#endif
/* end oraca.h */

/* exec sql whenever sqlerror do ErrorSql(__FILE__, __LINE__); */ 

/* exec sql whenever notfound continue; */ 

/* exec sql whenever sqlwarning continue; */ 

/* exec oracle option (oraca=yes); */ 


/* exec sql begin declare section; */ 

     long    l_trt_numero;short s_trt_numero;
     long    l_ord_numero;short s_ord_numero;
     long    l_srv_codigo;short s_srv_codigo;
     long    l_cnt_numero;short s_cnt_numero;
     long    l_prs_numero;short s_prs_numero;
     long    l_o_prs_numero;short s_o_prs_numero;
     long    l_Suc;
     long    l_Ord_Dsd;
     long    l_Ord_Hst;
     /* varchar l_Sec[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } l_Sec;

     /* varchar l_tor_codigo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_tor_codigo;
short s_tor_codigo;
     /* varchar l_HoraDelDia[17]; */ 
struct { unsigned short len; unsigned char arr[17]; } l_HoraDelDia;

     /* varchar l_rowid[26]; */ 
struct { unsigned short len; unsigned char arr[26]; } l_rowid;

     /* varchar l_usr_codigo[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } l_usr_codigo;

     /* varchar l_Tor_codigo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_Tor_codigo;

     /* varchar l_TipoCorreo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_TipoCorreo;

     /* varchar l_Correo[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } l_Correo;

     /* varchar l_crr_genera_planilla[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } l_crr_genera_planilla;
short s_crr_genera_planilla;
     /* varchar l_crr_archivo_lote[51]; */ 
struct { unsigned short len; unsigned char arr[51]; } l_crr_archivo_lote;
short s_crr_archivo_lote;
     /* varchar l_crr_archivo_lote_path[256]; */ 
struct { unsigned short len; unsigned char arr[256]; } l_crr_archivo_lote_path;
short s_crr_archivo_lote_path;
     long    l_scf_codigo;short s_scf_codigo;
     /* varchar l_prs_razon_social[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } l_prs_razon_social;

     /* varchar l_prs_direccion[46]; */ 
struct { unsigned short len; unsigned char arr[46]; } l_prs_direccion;

     /* varchar v_prs_bis[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_prs_bis;
short s_prs_bis;
     /* varchar v_prs_torre[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_prs_torre;
short s_prs_torre;
     /* varchar l_cll_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } l_cll_nombre;
short s_cll_nombre;
     /* varchar l_cll_nombre_completo[28]; */ 
struct { unsigned short len; unsigned char arr[28]; } l_cll_nombre_completo;
short s_cll_nombre_completo;
     /* varchar l_cnt_nro_pago[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } l_cnt_nro_pago;
short s_cnt_nro_pago;
     /* varchar l_cnt_bis[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } l_cnt_bis;
short s_cnt_bis;
     /* varchar l_cnt_piso_pago[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_cnt_piso_pago;
short s_cnt_piso_pago;
     /* varchar l_cnt_depto_pago[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } l_cnt_depto_pago;
short s_cnt_depto_pago;
     /* varchar l_cnt_c_postal_pago[8]; */ 
struct { unsigned short len; unsigned char arr[8]; } l_cnt_c_postal_pago;
short s_cnt_c_postal_pago;
     /* varchar l_cnt_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } l_cnt_agf_nombre;
short s_cnt_agf_nombre;
     /* varchar l_buffer[8192]; */ 
struct { unsigned short len; unsigned char arr[8192]; } l_buffer;

     /* varchar l_FechaDelDia[17]; */ 
struct { unsigned short len; unsigned char arr[17]; } l_FechaDelDia;

     /* varchar l_not_codigo[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } l_not_codigo;

     /* varchar l_cfc_codigo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_cfc_codigo;

     /* varchar l_sec_codigo[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } l_sec_codigo;
 short s_sec_codigo;
     /* varchar l_tor_grupo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } l_tor_grupo;
 short s_tor_grupo;
     /* varchar l_tor_descripcion[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } l_tor_descripcion;
 short s_tor_descripcion;
     /* varchar l_ord_fecha_generacion[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } l_ord_fecha_generacion;
short s_ord_fecha_generacion;
     /* varchar l_Impr[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } l_Impr;

     /* varchar l_File[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } l_File;

     /* varchar l_tim_codigo[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } l_tim_codigo;

     long    l_cpr_numero;
     /* varchar l_prc_codigo[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } l_prc_codigo;

     /* varchar l_est_codigo[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } l_est_codigo;

     /* varchar l_prox_est_codigo[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } l_prox_est_codigo;

     long    l_usr_numero;

     /* varchar ll_prs_calle[19]; */ 
struct { unsigned short len; unsigned char arr[19]; } ll_prs_calle;

     /* varchar ll_prs_nro[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } ll_prs_nro;

     /* varchar ll_prs_piso[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } ll_prs_piso;

     /* varchar ll_prs_depto[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } ll_prs_depto;

     /* varchar ll_prs_torre[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } ll_prs_torre;

     /* varchar ll_prs_c_postal[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } ll_prs_c_postal;

     /* varchar ll_prs_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } ll_prs_agf_nombre;

     long    ll_prs_agf_codigo;

/* exec sql end declare section; */ 


char *TiposOrdenativo (int largos[],char *v_columna,char *campo,long srv_cod,int cnt_num);
void   GeneraArchivo(void);
char   *pdepura;
char   *userid;
char   *Tor_codigo;
char   *Rep_codigo;
char   *Suc;
char   *Ord_Dsd;
char   *Ord_Hst;
char   *Sec;
char   *User;
char   *TipoCorreo;
char   *Correo;
char   *Impr;
char   *File;
char   l_bar_code[512];
double ImporteDelAviso;
int    CantidadDeFacturas;
char   sec_codigo[9];
char   tor_grupo[3];
int    pent, psal;
char   psalida[128];
int    Tiene_Comprobantes_Financiaciones;
int    Tiene_Otros_Comprobantes;
FILE   *lote;
/*
  Cambios del 24-9-2003: jinfante/cjazmin
*/
int Imputacion_Incobrables;

/* FAB 6/4/09 - Req. 2823
t_doc_saldo tiene el total del saldo de los documentos que se intiman, para controlarlo con el parámetro MININT
p_minint tiene el valor del parámetro
Esto de las variables globales está mal, pero todo el programa es un desastre, así que nada le hace una mancha mas al tigre
*/
double t_doc_saldo=0.0;
double p_minint=0.0;

main(int argc, char **argv)
 {
  /* BF:
   * DF:
   * EF: */

  FILE *out_file;
  char l_out_file[133];
  char l_out_lote[133];
  long SQLCODE=0;
  char Cmd[512];
  long OrdenDesde, OrdenHasta;
  char MiTerminal[64];
  int i;
  long Escribi=0;
  char UsuarioContra[10] ;

  oraca.orastxtf=ORASTFERR;

  /*
   * Lectura y verificacion de parametros.
   */

/* //fb 21.12.2006 - Si agrega el if, porque en linux da error sino se indico el parámetro
  GetParamString(argc,argv, "depura", &pdepura) ;
  NivelDepuracion= atoi (pdepura) ;
*/

  if(GetParamString(argc,argv, "depura", &pdepura))
  {
     NivelDepuracion = atoi (pdepura);
  }
  else
  {
  	 NivelDepuracion = 0;
  }

  GetParamString(argc,argv,"id",&userid);
  GetParamString(argc,argv,"User",&User);
  Str2Varchar(User, l_usr_codigo);
  GetParamString(argc,argv,"Tipo",&TipoCorreo);
  Str2Varchar(TipoCorreo, l_TipoCorreo);
  GetParamString(argc,argv,"Correo",&Correo);
  Str2Varchar(Correo, l_Correo);
  /* Parametros agregados el 6-6-2000 */
  GetParamString(argc,argv,"Suc",&Suc);
  l_Suc=atol(Suc);
  GetParamString(argc,argv,"Ord_Dsd",&Ord_Dsd);
  l_Ord_Dsd=atol(Ord_Dsd);
  GetParamString(argc,argv,"Ord_Hst",&Ord_Hst);
  l_Ord_Hst=atol(Ord_Hst);
  GetParamString(argc,argv,"Tor_codigo",&Tor_codigo);
  Str2Varchar(Tor_codigo, l_Tor_codigo);
  GetParamString(argc,argv,"Reporte",&Rep_codigo);
  GetParamString(argc,argv,"Sec",&Sec);

  /*
    Cambios del 24-9-2003: jinfante/cjazmin
  */
  Imputacion_Incobrables=0;
  for(i=1; i<argc; i++)
   {
    fprintf(stderr, "parametro %i = (%s)\n", i, argv[i]);
    if(!strcmp(argv[i], "INCOBRABLES=S"))
     {
      Imputacion_Incobrables=1;
      break;
     }
   }

  Str2Varchar(Sec, l_Sec);
  /* */
  if(!GetParamString(argc,argv,"impresora",&Impr))
  {
    Abortar("Error en parametro 'impresora'",argv[0]);
  }
  Str2Varchar(Impr, l_Impr);

  GetParamString(argc,argv,"file",&File);
  Str2Varchar(File, l_File);

  sprintf(l_out_file, "%s/%s", getenv("ALAMO_LST"), File);
  out_file=fopen(l_out_file, "w");

  /*
   * Depurar (1, "id=%s\n", userid);
   * Depurar (1, "l_TipoCorreo=%s\n", l_TipoCorreo.arr);
   * Depurar (1, "Correo=%s\n", l_Correo.arr);
   * Depurar (1, "l_out_file=%s\n", l_out_file);
   * Depurar (1, "User=%s\n", l_usr_codigo.arr);
   * Depurar (1, "impresora=%s\n", l_Impr.arr);
   */

  /*
   * Se conecta a la base y obtiene la fecha, usuario y tipo de impresora.
   */

  Connect(userid,DISPCONNECT);
  
  /* exec sql alter session set optimizer_features_enable = '8.1.7'; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 0;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "alter session set optimizer_features_enable = '8.1.7'";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



  ClearVarchar(l_FechaDelDia);
  /* exec sql select to_char(sysdate,'dd/mm/yyyy hh:mi')
  	into :l_FechaDelDia
  	from sys.dual; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(sysdate,'dd/mm/yyyy hh:mi') into :b0  from s\
ys.dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )20;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_FechaDelDia;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  AddNullVarchar(l_FechaDelDia);
  OrdenDesde=9999999;
  OrdenHasta=0;
  bzero(sec_codigo, sizeof(sec_codigo));
  bzero(tor_grupo, sizeof(tor_grupo));

  Depurar (0, "l_FechaDelDia=%s\n", l_FechaDelDia.arr);
  
  /* exec sql
     select usr_numero
     into :l_usr_numero
     from usuarios
     where usr_codigo = :l_usr_codigo; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select usr_numero into :b0  from usuarios where usr_codigo=\
:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )39;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_usr_numero;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_usr_codigo;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



  Depurar (0, "l_usr_numero=%i\n", l_usr_numero);
	 
  ClearVarchar(l_tim_codigo);
  /* exec sql select tim_codigo
  	into :l_tim_codigo
  	from impresoras
    where impresoras.prt_codigo = :l_Impr; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select tim_codigo into :b0  from impresoras where impresora\
s.prt_codigo=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )62;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_tim_codigo;
  sqlstm.sqhstl[0] = (unsigned long )8;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_Impr;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  AddNullVarchar(l_tim_codigo);

  Depurar (0, "l_tim_codigo=%s\n", l_tim_codigo.arr);
  
   /* FAB 6/4/09 - Req. 2823
   Busca el parámetro MININT
   */
   /* exec sql
		select to_number(pgr_valor)
		into :p_minint
		from param_gral
		where pgr_codigo = 'MININT'; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select to_number(pgr_valor) into :b0  from param_gral wher\
e pgr_codigo='MININT'";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )85;
   sqlstm.selerr = (unsigned short)0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&p_minint;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   SQLCODE = sqlca.sqlcode;
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   Depurar (0, "p_minint=%lf\n", p_minint);
		
  /*
   * Obtiene datos sobre los formatos de
   * salida para el correo especificado.
   */

  ClearVarchar(l_crr_genera_planilla);
  ClearVarchar(l_crr_archivo_lote);
  ClearVarchar(l_crr_archivo_lote_path);
  /* exec sql
       SELECT crr_genera_planilla,
              crr_archivo_sql,
              crr_archivo_sql_path
       INTO :l_crr_genera_planilla:s_crr_genera_planilla,
            :l_crr_archivo_lote:s_crr_archivo_lote,
            :l_crr_archivo_lote_path:s_crr_archivo_lote_path
       FROM  correos c, usuarios u
       WHERE usr_codigo = :l_usr_codigo AND
             c.scf_codigo = u.scf_codigo AND
	         crr_tipo = :l_TipoCorreo AND
             crr_codigo = :l_Correo; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select crr_genera_planilla ,crr_archivo_sql ,crr_archivo_sq\
l_path into :b0:b1,:b2:b3,:b4:b5  from correos c ,usuarios u where (((usr_codi\
go=:b6 and c.scf_codigo=u.scf_codigo) and crr_tipo=:b7) and crr_codigo=:b8)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )104;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_crr_genera_planilla;
  sqlstm.sqhstl[0] = (unsigned long )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&s_crr_genera_planilla;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_crr_archivo_lote;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&s_crr_archivo_lote;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&l_crr_archivo_lote_path;
  sqlstm.sqhstl[2] = (unsigned long )258;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&s_crr_archivo_lote_path;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&l_usr_codigo;
  sqlstm.sqhstl[3] = (unsigned long )11;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&l_TipoCorreo;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&l_Correo;
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  if(SQLCODE==1403)
   {
    Depurar (0, "%s:Error leyendo registro de correos\n", argv[0]);
    exit(-1);
   }

   Depurar (0, "l_crr_genera_planilla=%s\n", l_crr_genera_planilla.arr);
   Depurar (0, "l_crr_archivo_lote=%s\n", l_crr_archivo_lote.arr);
   Depurar (0, "l_crr_archivo_lote_path=%s\n", l_crr_archivo_lote_path.arr);
   
  /*
   * Obtiene un numero de secuencia  (???)
   */

  /* exec sql select cpr_numero.nextval
       into :l_cpr_numero
       from sys.dual; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select cpr_numero.nextval  into :b0  from sys.dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )143;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_cpr_numero;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  Depurar (0, "El numero es %d\n", l_cpr_numero);
  
  if(s_crr_genera_planilla==-1)
  {
    Str2Varchar("N", l_crr_genera_planilla);
  }
  else
  {
    AddNullVarchar(l_crr_genera_planilla);
  }

  /* Le agrego un pid al nombre para hacerlo unico */
    sprintf(l_out_lote, "%s/%s%05d", getenv("ALAMO_LST"), "err", getpid());

  Depurar (0, "Generando lote en archivo %s\n", l_out_lote);
  lote=fopen(l_out_lote, "w");

  /*
   * Obtiene el fun_estado_inicial('IN')
   * e inserta el registro correspondiente en control_procesos.
   */

  ClearVarchar(l_est_codigo);

  Depurar(0, "Ejecuto PL/SQL fun_estado_inicial\n");

  /* exec sql execute
     begin
       :l_est_codigo:=fun_estado_inicial('IN');
     end;
  end-exec; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :l_est_codigo := fun_estado_inicial ( 'IN' ) ; end ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )162;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_est_codigo;
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  AddNullVarchar(l_est_codigo);
  Depurar (0, "Fin de PL/SQL fun_estado_inicial\n");

  Depurar (0, "Inserto en control_procesos\n");
  /* exec sql insert into control_procesos
           (cpr_numero,
            cpr_tipo_proceso,
            usr_numero_incorpora,
            prc_codigo,
            est_codigo,
            cpr_fecha_inicio)
       values(:l_cpr_numero,
              'IN',
              :l_usr_numero,
              'IN',
              :l_est_codigo,
              sysdate); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into control_procesos (cpr_numero,cpr_tipo_proceso,u\
sr_numero_incorpora,prc_codigo,est_codigo,cpr_fecha_inicio) values (:b0,'IN',:\
b1,'IN',:b2,sysdate)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )181;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_cpr_numero;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_usr_numero;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&l_est_codigo;
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  /* exec sql commit; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )208;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



  /*
   * Cursor principal (MiCursor)
   *
   * Consulta la tabla de ordenativos de grupos NT y CD
   * del usuario y sucursal predeterminados,
   * para el tipo y codigo de correo especificado,
   * y trae: numeros de ordenativo, tramite,
   *         servicio y contrato,
   *         tipo de ordenativo, grupo del tipo,
   *         fecha de generacion,
   *         sucursal y sector de origen. (???)
   */
  /* exec sql declare MiCursor cursor for
       select o.trt_numero,
              o.ord_numero,
              o.srv_codigo,
              o.cnt_numero,
              nvl(o.tor_codigo,''),
              to_char(o.ord_fecha_generacion,'dd/mm/yyyy'),
              u.scf_codigo,
              o.sec_codigo_origen,
              t.tor_grupo,
              t.tor_descripcion,
              o.prs_numero,
              o.rowid
       from ordenativos o,
            tipos_ordenativo t,
            usuarios u
       where t.tor_codigo = :l_Tor_codigo and
       -- (t.tor_grupo = 'NT' or t.tor_grupo = 'CD' or t.tor_grupo = 'CO') and
             o.tor_codigo = t.tor_codigo and
             u.usr_codigo = :l_usr_codigo and
             o.scf_codigo_origen = :l_Suc and
             o.sec_codigo_origen = :l_Sec and
             o.ord_numero between :l_Ord_Dsd and :l_Ord_Hst and
             o.crr_tipo = :l_TipoCorreo and
             o.crr_codigo = :l_Correo and
             o.ord_situacion = 'P' and
             o.ord_estado = 'D'
       order by o.ord_numero; */ 



  /*
   * ------------------ Inicio del bucle principal -----------------------
   */

  Depurar (1, "Abro cursor\n");
  bzero(sec_codigo, sizeof sec_codigo);
  bzero(tor_grupo, sizeof tor_grupo);
  /* exec sql open MiCursor; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0011;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )223;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_Tor_codigo;
  sqlstm.sqhstl[0] = (unsigned long )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_usr_codigo;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&l_Suc;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&l_Sec;
  sqlstm.sqhstl[3] = (unsigned long )11;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&l_Ord_Dsd;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&l_Ord_Hst;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&l_TipoCorreo;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&l_Correo;
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  for(;;)
  {
    /*
      Blanqueo el contador de comprobantes de financiaciones internas
    */
    Tiene_Comprobantes_Financiaciones=0;
    Tiene_Otros_Comprobantes=0;
    /*
     * Toma un registro del cursor principal (ordenativos).
     */
    ClearVarchar(l_tor_codigo);
    ClearVarchar(l_sec_codigo);
    ClearVarchar(l_tor_grupo);
    /* exec sql whenever sqlerror do ErrorSql(__FILE__, __LINE__); */ 

    /* exec sql fetch MiCursor into :l_trt_numero:s_trt_numero,
                                 :l_ord_numero:s_ord_numero,
                                 :l_srv_codigo:s_srv_codigo,
                                 :l_cnt_numero:s_cnt_numero,
                                 :l_tor_codigo:s_tor_codigo,
                                 :l_ord_fecha_generacion:s_ord_fecha_generacion,
                                 :l_scf_codigo:s_scf_codigo,
                                 :l_sec_codigo:s_sec_codigo,
                                 :l_tor_grupo:s_tor_grupo,
                                 :l_tor_descripcion:s_tor_descripcion,
                                 :l_o_prs_numero:s_o_prs_numero,
                                 :l_rowid; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )270;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&l_trt_numero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)&s_trt_numero;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&l_ord_numero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)&s_ord_numero;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&l_srv_codigo;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)&s_srv_codigo;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&l_cnt_numero;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)&s_cnt_numero;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&l_tor_codigo;
    sqlstm.sqhstl[4] = (unsigned long )5;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)&s_tor_codigo;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&l_ord_fecha_generacion;
    sqlstm.sqhstl[5] = (unsigned long )13;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)&s_ord_fecha_generacion;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&l_scf_codigo;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)&s_scf_codigo;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&l_sec_codigo;
    sqlstm.sqhstl[7] = (unsigned long )11;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)&s_sec_codigo;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&l_tor_grupo;
    sqlstm.sqhstl[8] = (unsigned long )5;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)&s_tor_grupo;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&l_tor_descripcion;
    sqlstm.sqhstl[9] = (unsigned long )63;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)&s_tor_descripcion;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&l_o_prs_numero;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)&s_o_prs_numero;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&l_rowid;
    sqlstm.sqhstl[11] = (unsigned long )28;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    SQLCODE = sqlca.sqlcode;
    if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


    /* Si no hay mas registros, fin del bucle principal */
    if (SQLCODE==1403)
      break;

    if(s_o_prs_numero==-1)
      l_o_prs_numero=0;
    if(l_ord_numero<OrdenDesde)
      OrdenDesde=l_ord_numero;
    if(l_ord_numero>OrdenHasta)
      OrdenHasta=l_ord_numero;

    /*
     * Para el primer fetch (???) toma sector
     * de origen del ordenativo y grupo del tipo
     * de ordenativo.  (???)
     */

    AddNullVarchar(l_tor_codigo);
    AddNullVarchar(l_tor_descripcion);
    if(strlen(sec_codigo)==0)
      if(s_sec_codigo==-1)
        l_sec_codigo.len=l_sec_codigo.arr[0]=0;
      else
       {
        AddNullVarchar(l_sec_codigo);
        strcpy(sec_codigo, l_sec_codigo.arr);
       }
    if(strlen(tor_grupo)==0)
      if(s_tor_grupo==-1)
        l_tor_grupo.len=l_tor_grupo.arr[0]=0;
      else
       {
        AddNullVarchar(l_tor_grupo);
        strcpy(tor_grupo, l_tor_grupo.arr);
       }

    /*
     * Busca la persona referenciada por
     * el suministro y contador (contrato).
     * del ordenativo.
     *
     * Primero intenta obtener la direccion
     * detallada, si no existe, la entera
     * (cnt_direccion_pago).
     */
    ClearVarchar(l_prs_razon_social);
    ClearVarchar(l_prs_direccion);
    ClearVarchar(l_cfc_codigo);
    ClearVarchar(l_cll_nombre);
    ClearVarchar(l_cnt_nro_pago);
    ClearVarchar(l_cnt_bis);
    ClearVarchar(l_cnt_piso_pago);
    ClearVarchar(l_cnt_depto_pago);
    ClearVarchar(l_cnt_c_postal_pago);
    ClearVarchar(l_cnt_agf_nombre);
    ClearVarchar(ll_prs_calle);
    ClearVarchar(ll_prs_nro);
    ClearVarchar(ll_prs_piso);
    ClearVarchar(ll_prs_depto);
    ClearVarchar(ll_prs_torre);
    ClearVarchar(ll_prs_c_postal);
    ClearVarchar(ll_prs_agf_nombre);
    /* Depurar (1, "busco en personas\n"); */
    if(l_srv_codigo==0)
     {
/*
   Cambio del 22-12-2003: czero
   Para que imprima el domicilio de la persona
*/
      /* exec sql
       select personas.prs_numero,
              substr(personas.prs_razon_social,1,25),
              nvl(personas.prs_direccion, ' '),
              personas.cfc_codigo,
              substr(calles.cll_nombre,1,18),
              substr(nvl(personas.prs_nro, '    '),1,4),
              substr(nvl(personas.prs_piso, '  '),1,2),
              substr(nvl(personas.prs_depto, '   '),1,3),
              nvl(personas.prs_torre, ' '),
              nvl(personas.prs_c_postal, ' '),
              nvl(areas_geograficas.agf_nombre, ' ')
       into :l_prs_numero,
            :l_prs_razon_social,
            :l_prs_direccion,
            :l_cfc_codigo,
            :ll_prs_calle,
            :ll_prs_nro,
            :ll_prs_piso,
            :ll_prs_depto,
            :ll_prs_torre,
            :ll_prs_c_postal,
            :ll_prs_agf_nombre
       from areas_geograficas, personas, calles
       where areas_geograficas.agf_codigo = personas.agf_codigo
         and calles.cll_codigo = personas.cll_codigo
         and calles.agf_codigo = personas.agf_codigo
         and personas.prs_numero = :l_o_prs_numero; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 12;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select personas.prs_numero ,substr(personas.prs_razon_s\
ocial,1,25) ,nvl(personas.prs_direccion,' ') ,personas.cfc_codigo ,substr(call\
es.cll_nombre,1,18) ,substr(nvl(personas.prs_nro,'    '),1,4) ,substr(nvl(pers\
onas.prs_piso,'  '),1,2) ,substr(nvl(personas.prs_depto,'   '),1,3) ,nvl(perso\
nas.prs_torre,' ') ,nvl(personas.prs_c_postal,' ') ,nvl(areas_geograficas.agf_\
nombre,' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10  from areas_geog\
raficas ,personas ,calles where (((areas_geograficas.agf_codigo=personas.agf_c\
odigo and calles.cll_codigo=personas.cll_codigo) and calles.agf_codigo=persona\
s.agf_codigo) and personas.prs_numero=:b11)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )333;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&l_prs_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&l_prs_razon_social;
      sqlstm.sqhstl[1] = (unsigned long )63;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&l_prs_direccion;
      sqlstm.sqhstl[2] = (unsigned long )48;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&l_cfc_codigo;
      sqlstm.sqhstl[3] = (unsigned long )5;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&ll_prs_calle;
      sqlstm.sqhstl[4] = (unsigned long )21;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&ll_prs_nro;
      sqlstm.sqhstl[5] = (unsigned long )7;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&ll_prs_piso;
      sqlstm.sqhstl[6] = (unsigned long )5;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&ll_prs_depto;
      sqlstm.sqhstl[7] = (unsigned long )6;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&ll_prs_torre;
      sqlstm.sqhstl[8] = (unsigned long )6;
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&ll_prs_c_postal;
      sqlstm.sqhstl[9] = (unsigned long )11;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&ll_prs_agf_nombre;
      sqlstm.sqhstl[10] = (unsigned long )33;
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&l_o_prs_numero;
      sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      SQLCODE = sqlca.sqlcode;
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


     }
    else
     {
      /* exec sql
       select personas.prs_numero,
              substr(personas.prs_razon_social,1,25),
              nvl(personas.prs_direccion, ' '),
              personas.cfc_codigo,
              substr(calles.cll_nombre,1,18),
              substr(contratos.cnt_nro_pago,1,4),
              contratos.cnt_bis,
              substr(contratos.cnt_piso_pago,1,2),
              substr(contratos.cnt_depto_pago,1,3),
              nvl(contratos.cnt_c_postal_pago, ' '),
              nvl(areas_geograficas.agf_nombre, ' ')
       into :l_prs_numero,
            :l_prs_razon_social,
            :l_prs_direccion,
            :l_cfc_codigo,
            :l_cll_nombre:s_cll_nombre,
            :l_cnt_nro_pago:s_cnt_nro_pago,
            :l_cnt_bis:s_cnt_bis,
            :l_cnt_piso_pago:s_cnt_piso_pago,
            :l_cnt_depto_pago:s_cnt_depto_pago,
            :l_cnt_c_postal_pago:s_cnt_c_postal_pago,
            :l_cnt_agf_nombre:s_cnt_agf_nombre
       from areas_geograficas,
            contratos,
            personas,
            calles
       where areas_geograficas.agf_codigo =
             contratos.agf_codigo and
             contratos.srv_codigo = :l_srv_codigo and
             contratos.cnt_numero = :l_cnt_numero and
             personas.prs_numero = contratos.prs_numero and
             calles.agf_codigo = contratos.agf_codigo and
             calles.cll_codigo = contratos.cll_codigo; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 13;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select personas.prs_numero ,substr(personas.prs_razon_s\
ocial,1,25) ,nvl(personas.prs_direccion,' ') ,personas.cfc_codigo ,substr(call\
es.cll_nombre,1,18) ,substr(contratos.cnt_nro_pago,1,4) ,contratos.cnt_bis ,su\
bstr(contratos.cnt_piso_pago,1,2) ,substr(contratos.cnt_depto_pago,1,3) ,nvl(c\
ontratos.cnt_c_postal_pago,' ') ,nvl(areas_geograficas.agf_nombre,' ') into :b\
0,:b1,:b2,:b3,:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17  from a\
reas_geograficas ,contratos ,personas ,calles where (((((areas_geograficas.agf\
_codigo=contratos.agf_codigo and contratos.srv_codigo=:b18) and contratos.cnt_\
numero=:b19) and personas.prs_numero=contratos.prs_numero) and calles.agf_codi\
go=contratos.agf_codigo) and calles.cll_codigo=contratos.cll_codigo)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )396;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&l_prs_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&l_prs_razon_social;
      sqlstm.sqhstl[1] = (unsigned long )63;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&l_prs_direccion;
      sqlstm.sqhstl[2] = (unsigned long )48;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&l_cfc_codigo;
      sqlstm.sqhstl[3] = (unsigned long )5;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&l_cll_nombre;
      sqlstm.sqhstl[4] = (unsigned long )33;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_cll_nombre;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&l_cnt_nro_pago;
      sqlstm.sqhstl[5] = (unsigned long )8;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_cnt_nro_pago;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&l_cnt_bis;
      sqlstm.sqhstl[6] = (unsigned long )4;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_cnt_bis;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&l_cnt_piso_pago;
      sqlstm.sqhstl[7] = (unsigned long )5;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)&s_cnt_piso_pago;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&l_cnt_depto_pago;
      sqlstm.sqhstl[8] = (unsigned long )6;
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)&s_cnt_depto_pago;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&l_cnt_c_postal_pago;
      sqlstm.sqhstl[9] = (unsigned long )10;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)&s_cnt_c_postal_pago;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&l_cnt_agf_nombre;
      sqlstm.sqhstl[10] = (unsigned long )33;
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)&s_cnt_agf_nombre;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&l_srv_codigo;
      sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&l_cnt_numero;
      sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[12] = (         int  )0;
      sqlstm.sqindv[12] = (         short *)0;
      sqlstm.sqinds[12] = (         int  )0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqadto[12] = (unsigned short )0;
      sqlstm.sqtdso[12] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      SQLCODE = sqlca.sqlcode;
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


     }
    if(SQLCODE==1403)
    {
      /* exec sql
         select personas.prs_numero,
                substr(personas.prs_razon_social,1,25),
                nvl(personas.prs_direccion, ' '),
                personas.cfc_codigo,
                substr(nvl(contratos.cnt_direccion_pago, ' '),1,27)
         into :l_prs_numero,
              :l_prs_razon_social,
              :l_prs_direccion,
              :l_cfc_codigo,
              :l_cll_nombre_completo:s_cll_nombre_completo
         from contratos,
              personas
         where contratos.srv_codigo = :l_srv_codigo and
               contratos.cnt_numero = :l_cnt_numero and
               personas.prs_numero = contratos.prs_numero; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 13;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select personas.prs_numero ,substr(personas.prs_razon_s\
ocial,1,25) ,nvl(personas.prs_direccion,' ') ,personas.cfc_codigo ,substr(nvl(\
contratos.cnt_direccion_pago,' '),1,27) into :b0,:b1,:b2,:b3,:b4:b5  from cont\
ratos ,personas where ((contratos.srv_codigo=:b6 and contratos.cnt_numero=:b7)\
 and personas.prs_numero=contratos.prs_numero)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )463;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&l_prs_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&l_prs_razon_social;
      sqlstm.sqhstl[1] = (unsigned long )63;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&l_prs_direccion;
      sqlstm.sqhstl[2] = (unsigned long )48;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&l_cfc_codigo;
      sqlstm.sqhstl[3] = (unsigned long )5;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&l_cll_nombre_completo;
      sqlstm.sqhstl[4] = (unsigned long )30;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_cll_nombre_completo;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&l_srv_codigo;
      sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&l_cnt_numero;
      sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      SQLCODE = sqlca.sqlcode;
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      if(SQLCODE==1403)
       {
        Depurar (0, "no encontre la persona\n");
        l_prs_numero=0;
       }
      else
       {
        if(s_cll_nombre_completo==-1)
          l_cll_nombre_completo.arr[0]=l_cll_nombre_completo.len=0;
        else
         {
          psal=0;
          if(strlen(l_cll_nombre_completo.arr)!=0)
           {
            for(pent=0; pent<strlen(l_cll_nombre_completo.arr); pent++)
              if((l_cll_nombre_completo.arr[pent]==' ')&&(l_cll_nombre_completo.arr[pent+1]==' '))
                pent=pent;
              else
                psalida[psal++]=l_cll_nombre_completo.arr[pent];
           }
          psalida[psal]=0;
          psalida[27]=0;
          ClearVarchar(l_cll_nombre_completo);
          Str2Varchar(psalida, l_cll_nombre_completo);
          AddNullVarchar(l_cll_nombre_completo);
         }
       }
     }
	AddNullVarchar(l_cfc_codigo);
    if(s_cll_nombre==-1)
      l_cll_nombre.arr[0]=l_cll_nombre.len=0;
    else
     {
      AddNullVarchar(l_cll_nombre);
     }
    if(s_cnt_nro_pago==-1)
      l_cnt_nro_pago.arr[0]=l_cnt_nro_pago.len=0;
    else
     {
      AddNullVarchar(l_cnt_nro_pago);
     }
    if(s_cnt_bis==-1)
      l_cnt_bis.arr[0]=l_cnt_bis.len=0;
    else
     {
      AddNullVarchar(l_cnt_bis);
     }
    if(s_cnt_piso_pago==-1)
      l_cnt_piso_pago.arr[0]=l_cnt_piso_pago.len=0;
    else
     {
      AddNullVarchar(l_cnt_piso_pago);
     }
    if(s_cnt_depto_pago==-1)
      l_cnt_depto_pago.arr[0]=l_cnt_depto_pago.len=0;
    else
     {
      AddNullVarchar(l_cnt_depto_pago);
     }
    if(s_cnt_c_postal_pago==-1)
      l_cnt_c_postal_pago.arr[0]=l_cnt_c_postal_pago.len=0;
    else
     {
      AddNullVarchar(l_cnt_c_postal_pago);
     }
    if(s_cnt_agf_nombre==-1)
      l_cnt_agf_nombre.arr[0]=l_cnt_agf_nombre.len=0;
    else
     {
      AddNullVarchar(l_cnt_agf_nombre);
     }

    ClearVarchar(l_not_codigo);

    /* Depurar (1, "busco en combinaciones habilitadas\n");*/
    /* exec sql
       select not_codigo
       into :l_not_codigo
       from combinaciones_habilitadas_noti
       where tor_codigo = :l_tor_codigo and
             cfc_codigo = :l_cfc_codigo; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select not_codigo into :b0  from combinaciones_habilitada\
s_noti where (tor_codigo=:b1 and cfc_codigo=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )506;
    sqlstm.selerr = (unsigned short)0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&l_not_codigo;
    sqlstm.sqhstl[0] = (unsigned long )6;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&l_tor_codigo;
    sqlstm.sqhstl[1] = (unsigned long )5;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&l_cfc_codigo;
    sqlstm.sqhstl[2] = (unsigned long )5;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    SQLCODE = sqlca.sqlcode;
    if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


	AddNullVarchar(l_not_codigo);
    /* Depurar (2, "tor_codigo=%s cfc_codigo=%s not_codigo=%s\n",
                    l_tor_codigo.arr, l_cfc_codigo.arr, l_not_codigo.arr); */
    if(SQLCODE==1403)
     {
      Depurar (0, "No se encontro tipo de intimacion para persona # %d\n",
                      l_prs_numero);
     }
    else
     {
      ClearVarchar(l_buffer);
      l_bar_code[0]=0;
      ImporteDelAviso=0;
      CantidadDeFacturas=0;
      Notifi((char *)l_not_codigo.arr,
             l_prs_numero,
             l_srv_codigo,
             l_cnt_numero,
             l_trt_numero,
             l_ord_numero,
             (char *)l_buffer.arr,
             (char *)l_tim_codigo.arr,
             l_bar_code);

      /* En l_buffer.arr esta TODA la notificacion, correctamente
       * formateada. Ahora vamos a imprimirla.
       */


/* DAM 05-11-2002 req.1285  imprimir solo cuando tiene doc.    */

/*
fprintf(stderr, "--[SRV:%ld - fact:%d]--\n", l_srv_codigo, CantidadDeFacturas );  
*/

/* FAB 6/4/09 - Req. 2823
Agrego la condición para que no emita la intimación si el saldo total de la deuda (t_doc_saldo) es menor que el parámetro MININT
*/
      /* FAB 30/04/2015 - Req. 3463
      if(CantidadDeFacturas>0 && t_doc_saldo >= p_minint)
      */

      if(CantidadDeFacturas>0)      
       {

 	      l_buffer.len=strlen(l_buffer.arr);
          fprintf(out_file, "%s", (char *)l_buffer.arr);
          Escribi++;

          GeneraArchivo();
          Depurar (1, "Genere archivo\n");
          Depurar (1, "l_tor_grupo=(%s)\n", l_tor_grupo.arr);


          if(strcmp(l_tor_grupo.arr, "CD")==0)
           {
            Depurar (2, "antes del update\n");
            /* exec sql update ordenativos
                 set cpr_numero = :l_cpr_numero
                  where rowid = :l_rowid; */ 

{
            struct sqlexd sqlstm;
            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 13;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update ordenativos  set cpr_numero=:b0 where rowi\
d=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )533;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&l_cpr_numero;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&l_rowid;
            sqlstm.sqhstl[1] = (unsigned long )28;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            SQLCODE = sqlca.sqlcode;
            if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


           }
          else
           {
             Depurar (2, "antes del update I\n");
             /* exec sql update ordenativos
             set ord_situacion = 'I',
                 cpr_numero = :l_cpr_numero
                 where rowid = :l_rowid; */ 

{
             struct sqlexd sqlstm;
             sqlorat((void **)0, &sqlctx, &oraca);
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 13;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "update ordenativos  set ord_situacion='I',cpr_nu\
mero=:b0 where rowid=:b1";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )556;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (unsigned char  *)&l_cpr_numero;
             sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         short *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned long )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (unsigned char  *)&l_rowid;
             sqlstm.sqhstl[1] = (unsigned long )28;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         short *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned long )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqphsv = sqlstm.sqhstv;
             sqlstm.sqphsl = sqlstm.sqhstl;
             sqlstm.sqphss = sqlstm.sqhsts;
             sqlstm.sqpind = sqlstm.sqindv;
             sqlstm.sqpins = sqlstm.sqinds;
             sqlstm.sqparm = sqlstm.sqharm;
             sqlstm.sqparc = sqlstm.sqharc;
             sqlstm.sqpadto = sqlstm.sqadto;
             sqlstm.sqptdso = sqlstm.sqtdso;
             sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
             SQLCODE = sqlca.sqlcode;
             if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


           }

        }
       else
        {
         if(Imputacion_Incobrables!=1)
          {
             Depurar (2, "antes de anulacion ordenativo update I\n");
             /* exec sql update ordenativos
             set ord_estado = 'A',
                 cpr_numero = :l_cpr_numero,
                 ord_datos_anula = 'Anulado Documentos ya pagados - Saldo 0 - No se imprime  '
                 where rowid = :l_rowid; */ 

{
             struct sqlexd sqlstm;
             sqlorat((void **)0, &sqlctx, &oraca);
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 13;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "update ordenativos  set ord_estado='A',cpr_numer\
o=:b0,ord_datos_anula='Anulado Documentos ya pagados - Saldo 0 - No se imprime\
  ' where rowid=:b1";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )579;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (unsigned char  *)&l_cpr_numero;
             sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         short *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned long )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (unsigned char  *)&l_rowid;
             sqlstm.sqhstl[1] = (unsigned long )28;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         short *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned long )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqphsv = sqlstm.sqhstv;
             sqlstm.sqphsl = sqlstm.sqhstl;
             sqlstm.sqphss = sqlstm.sqhsts;
             sqlstm.sqpind = sqlstm.sqindv;
             sqlstm.sqpins = sqlstm.sqinds;
             sqlstm.sqparm = sqlstm.sqharm;
             sqlstm.sqparc = sqlstm.sqharc;
             sqlstm.sqpadto = sqlstm.sqadto;
             sqlstm.sqptdso = sqlstm.sqtdso;
             sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
             SQLCODE = sqlca.sqlcode;
             if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


          }
        }


/* DAM 05-11-2002 req.1285 hasta aqui  imprimir solo cuando tiene doc.    */


      Depurar (2, "antes del commit\n");
      /* exec sql commit; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 13;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )602;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      SQLCODE = sqlca.sqlcode;
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      Depurar (2, "despues del commit\n");
     }
  }
  /* --                                                                 --
   * -------------------- Fin del bucle principal ------------------------
   */

TratamientoDelError:
  /* exec sql close MiCursor; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )617;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  fclose(lote);
  fclose(out_file);

  if(Escribi!=0)
   {
    bzero(Cmd, sizeof Cmd);
    sprintf(Cmd, "Imprime %s list=%s est=\"*HLD\" id=%s dest=%s desc=\"P%d_Notificaciones_%s\"", l_out_file, Rep_codigo, l_usr_codigo.arr, l_Impr.arr, l_cpr_numero, l_not_codigo.arr);
    Depurar (0, "Ejecutando: %s\n", Cmd);
    system(Cmd);
    sprintf(Cmd, "rm %s", l_out_file);
    Depurar (0, "Ejecutando: %s\n", Cmd);
    system(Cmd);
   }
  ClearVarchar(l_prox_est_codigo);
  Depurar (0, "Ejecuto PL/SQL fun_proximo_estado\n");
  /* exec sql execute
     begin
       :l_prox_est_codigo:=fun_proximo_estado('IN', :l_est_codigo, 'IM');
     end;
  end-exec; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :l_prox_est_codigo := fun_proximo_estado ( 'IN' , :l_\
est_codigo , 'IM' ) ; end ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )632;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_prox_est_codigo;
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_est_codigo;
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  Depurar (0, "Fin de PL/SQL fun_proximo_estado\n");
  AddNullVarchar(l_prox_est_codigo);

  Depurar (0, "Antes del update control_procesos\n");
  /* exec sql update control_procesos
       set est_codigo = :l_prox_est_codigo
       where cpr_numero = :l_cpr_numero; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update control_procesos  set est_codigo=:b0 where cpr_numer\
o=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )655;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_prox_est_codigo;
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_cpr_numero;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  /* exec sql commit; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )678;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  Depurar (0, "Despues del commit\n");


  /*
    Cambios del 24-9-2003: jinfante/cjazmin
  */
/* 25/10/2006 kalave - czero se generan siempre los archivos - planillas (decision d.molinari)
  if(Imputacion_Incobrables==0)
   { */
    /*
       S - Planilla ; N - Archivo ; A - Ambos
    */

    if(l_crr_genera_planilla.arr[0]=='S')
      GrabaEnReportes();
    else
      if(l_crr_genera_planilla.arr[0]=='A')
       {
        GrabaEnReportes();
        bzero(Cmd, sizeof Cmd);
          sprintf(Cmd, "Imprime %s list=IMPINT id=%s dest=%s desc=\"P%d_IMPINT_%s\"", l_out_lote, l_usr_codigo.arr, l_Impr.arr, l_cpr_numero, l_not_codigo.arr);
        Depurar (0, "Ejecutando: %s\n", Cmd);
        system(Cmd);
       }
      else
       {
         bzero(Cmd, sizeof Cmd);
         sprintf(Cmd, "Imprime %s list=IMPINT id=%s dest=%s desc=\"P%d_IMPINT_%s\"", l_out_lote, l_usr_codigo.arr, l_Impr.arr, l_cpr_numero, l_not_codigo.arr);
         Depurar (0, "Ejecutando: %s\n", Cmd);
         system(Cmd);
        }
 /* } */
/*
  if(strcmp(l_tor_grupo.arr, "CD")==0)
   {
*/
    fprintf(stderr, "l_tor_grupo=(%s)\n", l_tor_grupo.arr);

    bzero(UsuarioContra, sizeof UsuarioContra);
    sprintf (UsuarioContra, "CONTRA%02ld", l_scf_codigo) ;
    fprintf (stderr, "UsuarioContra: {%s}\n", UsuarioContra) ;
    bzero(MiTerminal, sizeof MiTerminal);
    /* sprintf(MiTerminal, "TERM=%s", getenv("TERM")); */
    sprintf(MiTerminal, " ");
    bzero(Cmd, sizeof Cmd);
    sprintf(Cmd, "$ALAMO_BIN/print r25run $ALAMO_RDF/ORD_0004.rdf userid=%s %s destype=file desname=$ALAMO_LST/ORD_0004_%s batch=yes formulario=ORD_0004 copias=1 cantidad=1 cuadrante=GAS desde=%d hasta=%d usr=%s sec_codigo_origen=%s tipo=%s impresora=%s crr_tipo=%s crr_codigo=%s", userid, MiTerminal, l_HoraDelDia.arr, OrdenDesde, OrdenHasta, UsuarioContra, "%", l_Tor_codigo.arr, l_Impr.arr,l_TipoCorreo.arr,l_Correo.arr);
    Depurar (0, "Ejecutando: %s\n", Cmd);
    system(Cmd);
/*
  } */
 exit(0);
}


void GeneraArchivo(void)
{
  /* BF: -
   * DF: Genera el archivo para entregar al correo que distribuye las intimaciones.
   *
   *     El formato del archivo generado para correo es:
   *
   *     Campo        Descripcion                                 Longitud    Inicio
   *    -----------------------------------------------------------------------------
   *     TIPREG       Tipo de Registro (1=aviso)                      1          1
   *     CODTREA      A=aviso simple    B=carta documento             1          2
   *     ORD_NUMERO   Numero de Ordenativo                            8          3
   *     SUC          Sucursal                                        2         11
   *     CPR_NUMERO   Numero de Proceso                               6         13
   *     IPTE         Importe del aviso                               9         19
   *     CPR_FECHA    Fecha de Proceso ("YYYYMMDD")                   8         28
   *     AYN          Apellido y Nombre del Titular del servicio     25         36
   *     NOMCLL       Nombre Calle                                   18         61
   *     PTA          Numero de Puerta                                4         79
   *     PISO         Piso                                            2         83
   *     DTO          Departamento                                    3         85
   *     CRR_TIPO     Tipo de Correo                                  2         88
   *     CRR_CODIGO   Codigo de Correo                                8         90
   *     FILLER                                                       8         98
   *     CANFAC       Cantidad de Facturas                            5        106
   *     TITTREA      Titulo de Aviso                                30        111
   *     ZNACA        Cod. de zona (uso del distribuidor)             3        141
   *     INCIDENCIA   Codigo de Incidencia (uso del distribuidor)     2        144
   *                  Codigo postal                                   7        144
   *                  Descripcion de la localidad                    30        144
   *
   * EF: -
   */

  fprintf(lote, "1");                            /* Tipo de registro */
  fprintf(lote, "A");                            /* A=Aviso simple */
  fprintf(lote, "%08d", l_ord_numero);           /* Numero de ordenativo */
  fprintf(lote, "%02d", l_scf_codigo);           /* Sucursal */
  fprintf(lote, "%06d", l_cpr_numero);           /* Numero de proceso */
  fprintf(lote, "%09.0f", ImporteDelAviso*100);  /* Importe del aviso */
  fprintf(lote, "%c%c%c%c", l_ord_fecha_generacion.arr[6],
                            l_ord_fecha_generacion.arr[7],
                            l_ord_fecha_generacion.arr[8],
                            l_ord_fecha_generacion.arr[9]);
  fprintf(lote, "%c%c", l_ord_fecha_generacion.arr[3],
                        l_ord_fecha_generacion.arr[4]);
  fprintf(lote, "%c%c", l_ord_fecha_generacion.arr[0],
                        l_ord_fecha_generacion.arr[1]);
  fprintf(lote, "%-25s", l_prs_razon_social.arr);/* Razon social */

/*
  Modificacion del 22-12-2003: czero
  Si no hay un domicilio, imprimo el domicilio de la persona
*/
  if(ll_prs_calle.arr[0]!=0)
   {
    fprintf(lote, "%-18s", ll_prs_calle.arr);
    fprintf(lote, "%-4s", ll_prs_nro.arr);
    fprintf(lote, "%-2s", ll_prs_piso.arr);
    fprintf(lote, "%-3s", ll_prs_depto.arr);
    /* fprintf(lote, "%-3s", ll_prs_torre.arr);    */
   }
  else
    if(l_cll_nombre.arr[0]==0)
      fprintf(lote, "%-27s", l_cll_nombre_completo.arr);
    else
     {
      fprintf(lote, "%-18s", l_cll_nombre.arr);      /* Nombre de la calle */
      fprintf(lote, "%-4s", l_cnt_nro_pago.arr);     /* Numero de puerta */
      fprintf(lote, "%-2s", l_cnt_piso_pago.arr);    /* Piso */
      fprintf(lote, "%-3s", l_cnt_depto_pago.arr);   /* Departamento */
     }
  fprintf(lote, "%-2s", l_TipoCorreo.arr);       /* Tipo de correo */
  fprintf(lote, "%-8s", l_Correo.arr);           /* Codigo de correo */
  fprintf(lote, "%-8s", " ");
  fprintf(lote, "%05d", CantidadDeFacturas);     /* Cantidad de facturas */
  fprintf(lote, "%-30s", " ");                   /* Titulo del aviso */
  fprintf(lote, "%-3s", " ");                    /* Codigo de zona */
  fprintf(lote, "%-2s", "00");                   /* Codigo de incidencia */
  if(ll_prs_calle.arr[0]!=0)
   {
    fprintf(lote, "%-7s", ll_prs_c_postal.arr); /* Codigo postal */
    fprintf(lote, "%-30s", ll_prs_agf_nombre.arr);  /* Localidad */
   }
  else
   {
    fprintf(lote, "%-7s", l_cnt_c_postal_pago.arr); /* Codigo postal */
    fprintf(lote, "%-30s", l_cnt_agf_nombre.arr);  /* Localidad */
   }
  fprintf(lote, "%c%c", 13, 10);
}

GrabaEnReportes()
{
  /* BF:
   * DF:
   * EF: */

  /* exec sql begin declare section; */ 

       /* varchar l_FechaDelDia[17]; */ 
struct { unsigned short len; unsigned char arr[17]; } l_FechaDelDia;

       /* varchar l_rep_codigo[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } l_rep_codigo;

       /* varchar l_rep_descripcion[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } l_rep_descripcion;

       long l_rep_prioridad;
       /* varchar l_rep_borra_archivo[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } l_rep_borra_archivo;

       /* varchar l_rep_condicion_impresion[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } l_rep_condicion_impresion;

       /* varchar l_rep_comando[51]; */ 
struct { unsigned short len; unsigned char arr[51]; } l_rep_comando;

       /* varchar l_cnr_comando[401]; */ 
struct { unsigned short len; unsigned char arr[401]; } l_cnr_comando;

       /* varchar l_rep_tipo_comando[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } l_rep_tipo_comando;

       /* varchar l_rep_orientacion[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } l_rep_orientacion;

       /* varchar l_rep_destino[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } l_rep_destino;

       /* varchar l_rep_archivo_default[101]; */ 
struct { unsigned short len; unsigned char arr[101]; } l_rep_archivo_default;

       /* varchar l_prt_uname[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } l_prt_uname;

       /* varchar l_cnr_uname[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } l_cnr_uname;

       /* varchar l_cnr_archivo[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } l_cnr_archivo;

       /* varchar l_cnr_salida[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } l_cnr_salida;

       /* varchar l_prt_codigo[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } l_prt_codigo;

       long l_cnr_numero;
  /* exec sql end declare section; */ 


  long SQLCODE=0;

  ClearVarchar(l_FechaDelDia);
  ClearVarchar(l_HoraDelDia);
  Depurar (0, "Antes del select de sysdate\n");
  /* exec sql select to_char(sysdate,'dd/mm/yyyy'),
                  to_char(sysdate,'hhmiss')
  	into :l_FechaDelDia,
         :l_HoraDelDia
  	from sys.dual; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(sysdate,'dd/mm/yyyy') ,to_char(sysdate,'hhmi\
ss') into :b0,:b1  from sys.dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )693;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_FechaDelDia;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&l_HoraDelDia;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


  AddNullVarchar(l_FechaDelDia);
  AddNullVarchar(l_HoraDelDia);

  Depurar (0, "Antes del select de cnr_numero\n");
  /* exec sql
     select cnr_numero.nextval
     into :l_cnr_numero
     from sys.dual; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select cnr_numero.nextval  into :b0  from sys.dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )716;
  sqlstm.selerr = (unsigned short)0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&l_cnr_numero;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  SQLCODE = sqlca.sqlcode;
  if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



  Str2Varchar("I", l_cnr_salida);

  Depurar (0, "Antes del sprintf a l_cnr_archivo\n");
  sprintf(l_cnr_archivo.arr, "IMPINT_%s", l_HoraDelDia.arr);
  l_cnr_archivo.len=strlen(l_cnr_archivo.arr);
  sprintf(l_cnr_comando.arr, "%s/imp2 id=%s User=%s Tipo=%s Correo=%s Tramite=%d impr=%s file=%s",
  getenv("ALAMO_BIN"), userid, l_usr_codigo.arr, l_TipoCorreo.arr, l_Correo.arr,
  l_cpr_numero, Impr, l_cnr_archivo.arr);
  l_cnr_comando.len=strlen(l_cnr_comando.arr);

  Depurar (0, "l_cnr_comando=%s\n", l_cnr_comando.arr);
  system(l_cnr_comando.arr);
}

char *Notifi(char   *noti,
             long   prs_num,
             long   srv_cod,
             int    cnt_num,
             long   trt_num,
             long   nro_ord,
             char   *salida,
             char   *tim_codigo,
             char   *bar_code)
{

  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      /* varchar v_noti[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_noti;

      /* varchar v_doc_tipo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_doc_tipo;

      /* varchar v_not_codigo[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_not_codigo;

      /* varchar v_not_descripcion[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } v_not_descripcion;

      int     v_eno_orden;
      /* varchar v_eno_tipo[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_eno_tipo;

      /* varchar v_eno_texto[3072]; */ 
struct { unsigned short len; unsigned char arr[3072]; } v_eno_texto;

      short s_eno_texto;
      /* varchar v_eno_var_nombre[21]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_eno_var_nombre;

      short s_eno_var_nombre;
      /* varchar v_eno_var_tipo[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_eno_var_tipo;

      short s_eno_var_tipo;
      int     v_eno_var_longitud;short s_eno_var_longitud;
      double  v_eno_col;short s_eno_col;
      /* varchar v_eno_tipo_campo[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_eno_tipo_campo;

      short s_eno_tipo_campo;
      /* varchar v_tabla[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_tabla;

      /* varchar v_columna[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_columna;

   /* EXEC SQL END DECLARE SECTION; */ 

   long scf_cod;
   long agf_cod;
   int  ivv_cod;
   char ord_fec[11];
   char tcl_cod[5];
   char columnas[20][31];
   int largos[20];
   char tabla[31];
   int i, q;
   int ban;
   long srv_cod_ori;
   long cnt_num_ori;
   long trt_num_ori;
   long prs_num_ori;
   int aux,r;
   char tim_codigo_control_1[31];
   char tim_codigo_control_2[31];
   char tim_codigo_control_3[31];
   char tim_codigo_control_4[31];
   char tim_codigo_control_5[31];
   char tim_codigo_control_6[31];
   char tim_codigo_control_7[31];
   char tim_codigo_control_8[31];
   char tim_codigo_control_9[31];
   char tim_codigo_control_10[31];
   char tim_codigo_control_11[31];
   char tim_codigo_control_12[31];
   char tim_codigo_control_13[31];
   char tim_codigo_control_14[31];
   char tim_codigo_control_15[31];
   char campo[5120];
   char p_barras[255],nrobarra[512];
   char campito[80];

   tabla[0]='\0';
   v_tabla.arr[0]=v_tabla.len=0;
   v_columna.arr[0]=v_columna.len=0;
   
   /* EXEC SQL DECLARE TEXTO CURSOR FOR
      SELECT ENO.ENO_ORDEN,
             ENO.ENO_TIPO,
             ENO.ENO_TEXTO,
             ENO.ENO_VAR_NOMBRE,
             ENO.ENO_VAR_TIPO,
             ENO.ENO_VAR_LONGITUD,
             ENO.ENO_COL#,
             ENO.ENO_TIPO_CAMPO
      FROM   ESTRUCTURA_NOTIFICACION ENO,
             SERVICIOS SRV
      WHERE  ENO.NOT_CODIGO = :v_not_codigo
      	AND  SRV.SRV_CODIGO = :srv_cod
        AND  NVL(ENO.SCF_CODIGO, SRV.SCF_CODIGO) = SRV.SCF_CODIGO
        AND  ENO.ENO_ORDEN NOT IN (
        	SELECT DISTINCT NVL(ENO_SUB_ORDEN, 0)
        	FROM ESTRUCTURA_NOTIFICACION 
        	WHERE NOT_CODIGO = :v_not_codigo
        	AND SCF_CODIGO = SRV.SCF_CODIGO
        )
      ORDER BY ENO.ENO_ORDEN; */ 


   Str2Varchar(noti,v_noti);
   salida[0]=0;
   campo[0]=0;
/*
   Buscar_Codigos_Control(tim_codigo_control_1,
                          tim_codigo_control_2,
                          tim_codigo_control_3,
                          tim_codigo_control_4,
                          tim_codigo_control_5,
                          tim_codigo_control_6,
                          tim_codigo_control_7,
                          tim_codigo_control_8,
                          tim_codigo_control_9,
                          tim_codigo_control_10,
                          tim_codigo_control_11,
                          tim_codigo_control_12,
                          tim_codigo_control_13,
                          tim_codigo_control_14,
                          tim_codigo_control_15,
                          tim_codigo);
*/
/* Selecciono orientacion e impresion en una cara */
   sprintf(campito, "%c&l0O%c&l0S", 27, 27);
   strcat(salida, campito);
   SelectCodigoBarras(srv_cod,cnt_num,nro_ord,p_barras,nrobarra);
   if((!strcmp(noti, "I1"))||(!strcmp(noti, "I4"))||(!strcmp(noti, "IP")))
    {
     strcat(salida,p_barras);
     strcat(salida,"\n");
    }
   else
     strcat(salida,"\n");

/* Selecciono el font para el resto de la hoja */
/* sprintf(campito, "\n%c(19U%c(s0p12h9v0s0b0T%c&a15L\n\n", 27, 27, 27);
   strcat(salida, campito);
   strcpy(bar_code,nrobarra);
*/


/* Selecciono el font para el resto de la hoja */
   if(strcmp(noti, "I7")!=0)
     sprintf(campito, "\n%c(19U%c(s0p12h9v0s0b0T%c&a15L\n\n", 27, 27, 27);
   else
     sprintf(campito, "\n%c(19U%c(s0p12h9v0s0b0T%c&a0L\n\n", 27, 27, 27);

   strcat(salida, campito);
   strcpy(bar_code,nrobarra);


/* Depurar (2, "SELECT FROM TIPOS_NOTIFICACION\n"); */
   /* EXEC SQL SELECT NOT_CODIGO,
                   NOT_DESCRIPCION
   INTO           :v_not_codigo,
                  :v_not_descripcion
   FROM            TIPOS_NOTIFICACION
   WHERE           NOT_CODIGO=:v_noti; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select NOT_CODIGO ,NOT_DESCRIPCION into :b0,:b1  from TIPO\
S_NOTIFICACION where NOT_CODIGO=:b2";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )735;
   sqlstm.selerr = (unsigned short)0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_not_codigo;
   sqlstm.sqhstl[0] = (unsigned long )6;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_not_descripcion;
   sqlstm.sqhstl[1] = (unsigned long )63;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_noti;
   sqlstm.sqhstl[2] = (unsigned long )6;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   if(COUNTHITS==0)
      Abortar("Tipo de notificacion inexistente.","Error: ");

   AddNullVarchar(v_not_codigo);
   AddNullVarchar(v_not_descripcion);
/*
   Depurar (3, "v_not_codigo=%s\n", v_not_codigo.arr);
   Depurar (3, "v_noti=%s\n", v_noti.arr);
*/
   /* EXEC SQL OPEN TEXTO; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0025;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )762;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_not_codigo;
   sqlstm.sqhstl[0] = (unsigned long )6;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&srv_cod;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_not_codigo;
   sqlstm.sqhstl[2] = (unsigned long )6;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   r=0;
   i=0;ban=0;aux=0;
   do{
      r=aux;
      /* Depurar (2, "FETCH TEXTO\n"); */
      /* EXEC SQL FETCH TEXTO INTO
         :v_eno_orden,
         :v_eno_tipo,
         :v_eno_texto:s_eno_texto,
         :v_eno_var_nombre:s_eno_var_nombre,
         :v_eno_var_tipo:s_eno_var_tipo,
         :v_eno_var_longitud:s_eno_var_longitud,
         :v_eno_col:s_eno_col,
         :v_eno_tipo_campo:s_eno_tipo_campo; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 13;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )789;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (         int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_eno_orden;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_eno_tipo;
      sqlstm.sqhstl[1] = (unsigned long )4;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_eno_texto;
      sqlstm.sqhstl[2] = (unsigned long )3074;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)&s_eno_texto;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&v_eno_var_nombre;
      sqlstm.sqhstl[3] = (unsigned long )23;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)&s_eno_var_nombre;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&v_eno_var_tipo;
      sqlstm.sqhstl[4] = (unsigned long )4;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_eno_var_tipo;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&v_eno_var_longitud;
      sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_eno_var_longitud;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&v_eno_col;
      sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_eno_col;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&v_eno_tipo_campo;
      sqlstm.sqhstl[7] = (unsigned long )4;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)&s_eno_tipo_campo;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      AddNullVarchar(v_eno_var_nombre);
      /*
       * Depurar (2,"v_eno_var_nombre=%s len=%ld\n", v_eno_var_nombre.arr, v_eno_var_longitud);
       * Depurar (2,"COUNTHITS=%d\n", COUNTHITS);
       * Depurar (2,"r=%d\n", r);
       */

      aux=COUNTHITS;
      AddNullVarchar(v_eno_tipo);
      if(s_eno_texto!=-1) AddNullVarchar(v_eno_texto);
      if(s_eno_var_nombre!=-1) AddNullVarchar(v_eno_var_nombre);
      if(s_eno_var_tipo!=-1) AddNullVarchar(v_eno_var_tipo);
      if(s_eno_var_longitud==-1) v_eno_var_longitud=0;
      if(s_eno_col==-1) v_eno_col=0;
      if(s_eno_tipo_campo!=-1) AddNullVarchar(v_eno_tipo_campo);

      if(strcmp(tabla, "DOCUMENTOS")!=0)
        largos[0]=v_eno_var_longitud;

      if(aux!=r)
      {
         if(v_eno_tipo.arr[0]=='T')
         {
         /*
          * Leyenda de texto fijo.
          */
              /*
			  fprintf (stderr, "Fixed {%d}: {%s}{%s}\n", ban,
                                   v_tabla.arr, (char *)v_columna.arr) ;
              */

            if(ban==1){
               v_eno_texto.arr[0]=v_eno_texto.len=0;
               if((strcmp(tabla,"DOCUMENTOS"))==0){
                  /*
                     Cambio del 10-9-2003. Paso numero de ordenativo, para
                     la nueva consulta en documentos
                  */
                  Documentos(largos,&columnas[0][0],campo,srv_cod,
                             cnt_num,trt_num,i,31, nro_ord);
               }else if((strcmp(tabla,"DOCUMENTOS_GAR"))==0){
                  Ordenativos(largos,(char*)v_columna.arr,campo,nro_ord,&srv_cod_ori,
                              &cnt_num_ori,&trt_num_ori,ord_fec);
                  /*
                     Cambio del 10-9-2003. Paso numero de ordenativo, para
                     la nueva consulta en documentos
                  */
                  Documentos(largos,&columnas[0][0],campo,srv_cod_ori,
                             cnt_num_ori,
                             trt_num_ori,i,31, nro_ord);

               }
               strcat(salida,campo);
               i=0;
               ban=0;
               campo[0]=0;
            }
            strcat(salida,(char *)v_eno_texto.arr);
         }
         else
         {
         /*
          * Campo de texto variable.
          */
            /* Depurar (2, "SELECT FROM COL_NOTIFICACION\n"); */
            /* EXEC SQL SELECT TABLA,
                            COLUMNA
            INTO           :v_tabla,
                           :v_columna
            FROM COL_NOTIFICACION
            WHERE COL#=:v_eno_col; */ 

{
            struct sqlexd sqlstm;
            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 13;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select TABLA ,COLUMNA into :b0,:b1  from COL_NOTI\
FICACION where COL#=:b2";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )836;
            sqlstm.selerr = (unsigned short)0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&v_tabla;
            sqlstm.sqhstl[0] = (unsigned long )33;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&v_columna;
            sqlstm.sqhstl[1] = (unsigned long )33;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&v_eno_col;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


		
            campo[0]=0;
            if(COUNTHITS>0){
               AddNullVarchar(v_tabla);
               AddNullVarchar(v_columna);

				/*
				fprintf (stderr, "Variable {%d}: {%s}{%s}\n", ban,
								   v_tabla.arr, (char *)v_columna.arr) ;
				*/

               if(v_eno_tipo_campo.arr[0]=='F'){
                  if(ban==1)
                  {
                     v_eno_texto.arr[0]=v_eno_texto.len=0;
                     if((strcmp(tabla,"DOCUMENTOS"))==0){
                     /*
                        Cambio del 10-9-2003. Paso numero de ordenativo, para
                        la nueva consulta en documentos
                     */
                        Documentos(largos,&columnas[0][0],campo,
                                   srv_cod,cnt_num,
                                   trt_num,i,31, nro_ord);

                     }else if((strcmp(tabla,"DOCUMENTOS_GAR"))==0){
                        Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                    &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                     /*
                        Cambio del 10-9-2003. Paso numero de ordenativo, para
                        la nueva consulta en documentos
                     */
                        Documentos(largos,&columnas[0][0],campo,srv_cod_ori,
                                   cnt_num_ori,trt_num_ori,i,31, nro_ord);
                     }
                     strcat(salida,campo);
                     i=0;
                     ban=0;
                     campo[0]=0;
                  }

                  /* Por las dudas, otra vez.    (d.molina - 31/ago/1999)  */
                  largos[0]=v_eno_var_longitud;

				  /*
                  fprintf (stderr, "Checkpoint: {%s}{%s}\n",
                                   v_tabla.arr, (char *)v_columna.arr) ;
				  */
								   
                  if((strcmp((char*)v_tabla.arr,"PERSONAS"))==0){
                     Personas(largos,(char*)v_columna.arr,campo,prs_num);
                  }else if((strcmp((char*)v_tabla.arr,"PERSONAS_GAR"))==0){
                     Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                 &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                     Prs_Num_Ori(srv_cod_ori,cnt_num_ori,&prs_num_ori);
                     Personas(largos,(char*)v_columna.arr,campo,prs_num_ori);
                  }else if((strcmp((char *)v_tabla.arr,"CONTRATOS"))==0){
                     Contratos(largos,(char *)v_columna.arr,campo,srv_cod,cnt_num,
                               &ivv_cod,tcl_cod);
                  }else if((strcmp((char *)v_tabla.arr,"CONTRATOS_GAR"))==0){
                     Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                 &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                     Contratos(largos,(char *)v_columna.arr,campo,srv_cod_ori,
				cnt_num_ori,&ivv_cod,tcl_cod);
                  }else if((strcmp((char *)v_tabla.arr,"SERVICIOS"))==0){
                     Servicios(largos,(char *)v_columna.arr,campo,srv_cod,&scf_cod,&agf_cod);
                  }else if((strcmp((char *)v_tabla.arr,"SERVICIOS_GAR"))==0){
                     Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                 &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                     Servicios(largos,(char *)v_columna.arr,campo,srv_cod_ori,
                               &scf_cod,&agf_cod);
                  }else if((strcmp((char *)v_tabla.arr,"LECTURAS"))==0){
                     Lecturas(largos,(char *)v_columna.arr,campo,srv_cod);
                  }else if((strcmp((char *)v_tabla.arr,"ORDENATIVOS"))==0){
                     Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                 &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                  }else if((strcmp((char *)v_tabla.arr,"TIPOS_ORDENATIVO"))==0){
                     TiposOrdenativo(largos,(char *)v_columna.arr,campo,srv_cod,cnt_num);
                  }else if((strcmp((char *)v_tabla.arr,"POTENCIAS"))==0){
                     Potencias(largos,(char *)v_columna.arr,campo,srv_cod,cnt_num);
                  }else if((strcmp((char *)v_tabla.arr,"STOCK_EQUIPOS"))==0){
                     Stock_Equipos(largos,(char *)v_columna.arr,campo,srv_cod);
                  }else if((strcmp((char *)v_tabla.arr,"SUCURSALES"))==0){
                     Sucursales(largos,(char *)v_columna.arr,campo,scf_cod);
                  }else if((strcmp((char *)v_tabla.arr,"CARGOS"))==0){
                     Cargos(largos,(char *)v_columna.arr,campo,ord_fec);
                  }else if((strcmp((char *)v_tabla.arr,"BANCOS"))==0){
                     Bancos(largos,(char *)v_columna.arr,campo,agf_cod);
                  }else if((strcmp((char *)v_tabla.arr,"TIPOS_IVA"))==0){
                     Tipos_IVA(largos,(char *)v_columna.arr,campo,ivv_cod);
                  }else if((strcmp((char *)v_tabla.arr,
                                "TIPOS_NOTIFICACION"))==0){
                     strcat(campo,(char *)v_not_descripcion.arr);
                  }else if((strcmp((char *)v_tabla.arr,"TARIFAS"))==0){
                     Tarifas(largos,(char *)v_columna.arr,campo,tcl_cod);
                  }else if((strcmp((char *)v_tabla.arr,"TOTALES_TRAMITE"))==0){
                     Totales_Tramite(largos,(char *)v_columna.arr,campo,trt_num);
                  }else if((strcmp((char *)v_tabla.arr,"TOTALES_TRAMITE_GAR"))==0){
                     Ordenativos(largos,(char *)v_columna.arr,campo,nro_ord,
                                 &srv_cod_ori,&cnt_num_ori,&trt_num_ori,ord_fec);
                     Totales_Tramite(largos,(char *)v_columna.arr,campo,trt_num_ori);
                  }else if((strcmp((char *)v_tabla.arr,"USUARIOS"))==0){
                     Usuarios(largos,(char *)v_columna.arr,campo);
                  }
               }else{
                  if(ban==0){
                     Varchar2Str(v_tabla,tabla);
                     ban=1;
                  }
                  if((strcmp((char *)v_tabla.arr,"DOCUMENTOS"))==0
                      || (strcmp((char *)v_tabla.arr,"DOCUMENTOS_GAR"))==0){
                     Varchar2Str(v_columna,columnas[i]);
                     largos[i]=v_eno_var_longitud;
                     i++;
                  }
               }
               if((strcmp((char *)v_tabla.arr,"BANCOS"))==0)
                {
                 if(Tiene_Comprobantes_Financiaciones!=0)
                   if(Tiene_Otros_Comprobantes!=0)
                    {
                     for(q=strlen(campo); q<110; q++)
                       strcat(campo, " ");
                     campo[110]=0;
                     strcat(campo, "Cuotas vencidas financ. instalaciones internas unicamen-te podran abonarse en Of.Comerciales Litoral Gas.");
                    }
                   else
                     bzero(campo, sizeof campo);
                }
               strcat(salida,campo);
               campo[0]=0;
            }
         }
      }
   }while(aux!=r);
   /* EXEC SQL CLOSE TEXTO; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )863;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


/*
   if(strcmp(tim_codigo,"LASER")==0 || strcmp(tim_codigo,"LAS2")==0){
      strcat(salida,"\n");
      strcat(salida,tim_codigo_control_13);
   }
*/
   /* Depurar (3, "(%s)\n", salida); */
   strcat(salida,"\n");
   strcat(salida,"");
   return salida;
}

char *Personas(int largos[],char *v_columna,char *campo,long prs_num)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long    v_prs_numero=-1;
      static /* varchar v_prs_razon_social[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_prs_razon_social;

      static double  v_prs_cuit;
      static short   s_prs_cuit;
      static /* varchar v_tipo_doc[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_tipo_doc;

      static short   s_tipo_doc;
      static double  v_prs_documento;
      static short   s_prs_documento;
      static /* varchar v_prs_direccion[46]; */ 
struct { unsigned short len; unsigned char arr[46]; } v_prs_direccion;

      static short   s_prs_direccion;
      static /* varchar v_prs_nro[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_prs_nro;

      static short   s_prs_nro;
      static /* varchar v_prs_depto[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_prs_depto;

      static short   s_prs_depto;

   /* Esto puede ser peligroso          */
   /* static double  v_agf_codigo[7];   */
      static double  v_agf_codigo;

      static /* varchar v_prs_categoria[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_prs_categoria;

      static short   s_prs_categoria;
      static /* varchar v_prs_calle[26]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_prs_calle;

      static short   s_prs_calle;
/*
   Modificacion del 14-11-2001. jinfante. El codigo postal es varchar
      static double  v_prs_c_postal;
*/
      static /* varchar v_prs_c_postal[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_prs_c_postal;

      static short   s_prs_c_postal;
      static /* varchar v_prs_telefonos[41]; */ 
struct { unsigned short len; unsigned char arr[41]; } v_prs_telefonos;

      static short   s_prs_telefonos;
      static /* varchar v_prs_fax[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_prs_fax;

      static short   s_prs_fax;
      static /* varchar v_prs_estado[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_prs_estado;

      static short   s_prs_estado;
      static /* varchar v_prs_piso[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_prs_piso;

      static short   s_prs_piso;
      static double  v_prs_numero_registro;
      static short   s_prs_numero_registro;
      static /* varchar v_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_agf_nombre;

/* bbbb */
      /* static double  v_agf_codigo; */

   /* EXEC SQL END DECLARE SECTION; */ 


   char campo1[60];

   /* Depurar (1, "Busco en PERSONAS por %s\n", v_columna); */
   if(v_prs_numero!=prs_num){
      v_prs_numero=prs_num;
      /* EXEC SQL SELECT P.PRS_NUMERO,
                      P.PRS_RAZON_SOCIAL,
                      NVL(P.PRS_CUIT,0),
                      NVL(P.PRS_TIPO_DOC,''),
                      NVL(P.PRS_DOCUMENTO,0),
                      NVL(P.PRS_NRO,0),
                      NVL(P.PRS_DEPTO,''),
                      NVL(P.AGF_CODIGO,0),
                      NVL(P.PRS_C_POSTAL,''),
                      NVL(P.PRS_TELEFONOS,0),
                      NVL(P.PRS_FAX,0),
                      NVL(P.PRS_ESTADO,''),
                      NVL(P.PRS_PISO,0),
                      NVL(C.CLL_NOMBRE,''),
                      NVL(DECODE(P.PRS_BIS, 'N', ' ', P.PRS_BIS), ' '),
                      NVL(P.PRS_TORRE, ' ')
      INTO           :v_prs_numero,
                     :v_prs_razon_social,
                     :v_prs_cuit:s_prs_cuit,
                     :v_tipo_doc:s_tipo_doc,
                     :v_prs_documento:s_prs_documento,
                     :v_prs_nro:s_prs_nro,
                     :v_prs_depto:s_prs_depto,
                     :v_agf_codigo,
                     :v_prs_c_postal:s_prs_c_postal,
                     :v_prs_telefonos:s_prs_telefonos,
                     :v_prs_fax:s_prs_fax,
                     :v_prs_estado:s_prs_estado,
                     :v_prs_piso:s_prs_piso,
                     :v_prs_direccion:s_prs_direccion,
                     :v_prs_bis:s_prs_bis,
                     :v_prs_torre:s_prs_torre
      FROM PERSONAS P, CALLES C
      WHERE P.PRS_NUMERO=:prs_num AND
        C.AGF_CODIGO = P.AGF_CODIGO AND
        C.CLL_CODIGO = P.CLL_CODIGO; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 17;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select P.PRS_NUMERO ,P.PRS_RAZON_SOCIAL ,NVL(P.PRS_CUIT\
,0) ,NVL(P.PRS_TIPO_DOC,'') ,NVL(P.PRS_DOCUMENTO,0) ,NVL(P.PRS_NRO,0) ,NVL(P.P\
RS_DEPTO,'') ,NVL(P.AGF_CODIGO,0) ,NVL(P.PRS_C_POSTAL,'') ,NVL(P.PRS_TELEFONOS\
,0) ,NVL(P.PRS_FAX,0) ,NVL(P.PRS_ESTADO,'') ,NVL(P.PRS_PISO,0) ,NVL(C.CLL_NOMB\
RE,'') ,NVL(DECODE(P.PRS_BIS,'N',' ',P.PRS_BIS),' ') ,NVL(P.PRS_TORRE,' ') int\
o :b0,:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12,:b13:b14,:b15:b16,:b17:b18\
,:b19:b20,:b21:b22,:b23:b24,:b25:b26,:b27:b28  from PERSONAS P ,CALLES C where\
 ((P.PRS_NUMERO=:b29 and C.AGF_CODIGO=P.AGF_CODIGO) and C.CLL_CODIGO=P.CLL_COD\
IGO)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )878;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_prs_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_prs_razon_social;
      sqlstm.sqhstl[1] = (unsigned long )33;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_prs_cuit;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)&s_prs_cuit;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&v_tipo_doc;
      sqlstm.sqhstl[3] = (unsigned long )6;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)&s_tipo_doc;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&v_prs_documento;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_prs_documento;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&v_prs_nro;
      sqlstm.sqhstl[5] = (unsigned long )8;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_prs_nro;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&v_prs_depto;
      sqlstm.sqhstl[6] = (unsigned long )5;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_prs_depto;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&v_agf_codigo;
      sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&v_prs_c_postal;
      sqlstm.sqhstl[8] = (unsigned long )11;
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)&s_prs_c_postal;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&v_prs_telefonos;
      sqlstm.sqhstl[9] = (unsigned long )43;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)&s_prs_telefonos;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&v_prs_fax;
      sqlstm.sqhstl[10] = (unsigned long )13;
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)&s_prs_fax;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&v_prs_estado;
      sqlstm.sqhstl[11] = (unsigned long )4;
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)&s_prs_estado;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&v_prs_piso;
      sqlstm.sqhstl[12] = (unsigned long )5;
      sqlstm.sqhsts[12] = (         int  )0;
      sqlstm.sqindv[12] = (         short *)&s_prs_piso;
      sqlstm.sqinds[12] = (         int  )0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqadto[12] = (unsigned short )0;
      sqlstm.sqtdso[12] = (unsigned short )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&v_prs_direccion;
      sqlstm.sqhstl[13] = (unsigned long )48;
      sqlstm.sqhsts[13] = (         int  )0;
      sqlstm.sqindv[13] = (         short *)&s_prs_direccion;
      sqlstm.sqinds[13] = (         int  )0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqadto[13] = (unsigned short )0;
      sqlstm.sqtdso[13] = (unsigned short )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&v_prs_bis;
      sqlstm.sqhstl[14] = (unsigned long )4;
      sqlstm.sqhsts[14] = (         int  )0;
      sqlstm.sqindv[14] = (         short *)&s_prs_bis;
      sqlstm.sqinds[14] = (         int  )0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqadto[14] = (unsigned short )0;
      sqlstm.sqtdso[14] = (unsigned short )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&v_prs_torre;
      sqlstm.sqhstl[15] = (unsigned long )6;
      sqlstm.sqhsts[15] = (         int  )0;
      sqlstm.sqindv[15] = (         short *)&s_prs_torre;
      sqlstm.sqinds[15] = (         int  )0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqadto[15] = (unsigned short )0;
      sqlstm.sqtdso[15] = (unsigned short )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&prs_num;
      sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[16] = (         int  )0;
      sqlstm.sqindv[16] = (         short *)0;
      sqlstm.sqinds[16] = (         int  )0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqadto[16] = (unsigned short )0;
      sqlstm.sqtdso[16] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      /* if(COUNTHITS==0)
         Abortar("No hay datos personales.","Error: "); */
      if(s_prs_cuit==-1) v_prs_cuit=0;
      if(s_tipo_doc==-1) v_tipo_doc.arr[0]=v_tipo_doc.len=0;
      if(s_prs_documento==-1) v_prs_documento=0;
      if(s_prs_direccion==-1) v_prs_direccion.arr[0]=v_prs_direccion.len=0;
      if(s_prs_nro==-1) v_prs_nro.arr[0]=v_prs_nro.len=0;
      if(s_prs_depto==-1) v_prs_depto.arr[0]=v_prs_depto.len=0;
      if(s_prs_categoria==-1) v_prs_categoria.arr[0]=v_prs_categoria.len=0;
      if(s_prs_calle==-1) v_prs_calle.arr[0]=v_prs_calle.len=0;
      if(s_prs_c_postal==-1) v_prs_c_postal.arr[0]=v_prs_c_postal.len=0;
      if(s_prs_telefonos==-1) v_prs_telefonos.arr[0]=v_prs_telefonos.len=0;
      if(s_prs_fax==-1) v_prs_fax.arr[0]=v_prs_fax.len=0;
      if(s_prs_estado==-1) v_prs_estado.arr[0]=v_prs_estado.len=0;
      if(s_prs_piso==-1) v_prs_piso.arr[0]=v_prs_piso.len=0;
      if(s_prs_numero_registro==-1) v_prs_numero_registro=0;
   }

   if((strcmp(v_columna,"PRS_NUMERO")==0)){
      if(v_prs_numero>0){sprintf(campo,"%ld",v_prs_numero);}
   }else if((strcmp(v_columna,"PRS_RAZON_SOCIAL")==0)){
      Varchar2Str(v_prs_razon_social,campo);
   }else if((strcmp(v_columna,"PRS_CUIT")==0)){
      if(v_prs_cuit>0){sprintf(campo,"%.0lf",v_prs_cuit);}
   }else if((strcmp(v_columna,"PRS_TIPO_DOC")==0)){
      Varchar2Str(v_tipo_doc,campo);
   }else if((strcmp(v_columna,"PRS_DOCUMENTO")==0)){
      if(v_prs_documento>0){sprintf(campo,"%.0lf",v_prs_documento);}
   }else if((strcmp(v_columna,"PRS_NRO")==0)){
      Varchar2Str(v_prs_nro,campo);
   }else if((strcmp(v_columna,"PRS_DEPTO")==0)){
      Varchar2Str(v_prs_depto,campo);
   }else if((strcmp(v_columna,"AGF_CODIGO")==0)){
/*    if(strlen(v_agf_codigo)>0){sprintf(campo,"%.0lf",v_agf_codigo);}  */
      if(v_agf_codigo>0){sprintf(campo,"%.0lf",v_agf_codigo);}
   }else if((strcmp(v_columna,"PRS_CATEGORIA")==0)){
      Varchar2Str(v_prs_categoria,campo);
   }else if((strcmp(v_columna,"CLL_NOMBRE")==0)){
      Varchar2Str(v_prs_direccion,campo);
   }else if((strcmp(v_columna,"PRS_C_POSTAL")==0)){
/* Modificacion del cpostal jinfante
      if(v_prs_c_postal>0){sprintf(campo,"%.0lf",v_prs_c_postal);}
*/
      if(v_prs_c_postal.len>0){sprintf(campo,"%s",v_prs_c_postal.arr);}
   }else if((strcmp(v_columna,"PRS_TELEFONOS")==0)){
      Varchar2Str(v_prs_telefonos,campo);
   }else if((strcmp(v_columna,"PRS_FAX")==0)){
      Varchar2Str(v_prs_fax,campo);
   }else if((strcmp(v_columna,"PRS_ESTADO")==0)){
      Varchar2Str(v_prs_estado,campo);
   }else if((strcmp(v_columna,"PRS_PISO")==0)){
      Varchar2Str(v_prs_piso,campo);
   }else if((strcmp(v_columna,"PRS_NUMERO_REGISTRO")==0)){
      if(v_prs_numero_registro>0){sprintf(campo,"%.0lf",v_prs_numero_registro);}
   }else if((strcmp(v_columna,"PRS_LOCALIDAD")==0)){
      /* EXEC SQL SELECT AGF_NOMBRE
           INTO :v_agf_nombre
           FROM AREAS_GEOGRAFICAS
           WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 17;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select AGF_NOMBRE into :b0  from AREAS_GEOGRAFICAS wher\
e AREAS_GEOGRAFICAS.AGF_CODIGO=:b1";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )961;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_agf_nombre;
      sqlstm.sqhstl[0] = (unsigned long )33;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_agf_codigo;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      Varchar2Str(v_agf_nombre,campo);
   }else if((strcmp(v_columna,"PRS_DIRECCION")==0)){
    Varchar2Str(v_prs_direccion, campo1);
    if(strlen(campo1)!=0)
      for(;campo1[strlen(campo1)-1]==' ';)
       {
        if(strlen(campo1)==0)
          break;
        else
         {
          campo1[strlen(campo1)-1]=0;
          Depurar (3, "(%s)\n", campo1);
         }
       }
    strcpy(campo, campo1);
    if((v_prs_bis.len>0)&&(v_prs_bis.arr[0]!='N'))
     {
      AddNullVarchar(v_prs_bis);
      strcat(campo, " ");
      strcat(campo, v_prs_bis.arr);
     }
    if(v_prs_nro.len>0)
     {
      AddNullVarchar(v_prs_nro);
      strcat(campo, " ");
      strcat(campo, v_prs_nro.arr);
     }
    if(v_prs_torre.len>0)
     {
      AddNullVarchar(v_prs_torre);
      strcat(campo, " ");
      strcat(campo, v_prs_torre.arr);
     }
    if(v_prs_piso.len>0)
     {
      AddNullVarchar(v_prs_piso);
      strcat(campo, " ");
      strcat(campo, v_prs_piso.arr);
     }
    if(v_prs_depto.len>0)
     {
      AddNullVarchar(v_prs_depto);
      strcat(campo, " ");
      strcat(campo, v_prs_depto.arr);
     }
/* modificacion del cpostal - jinfante
    if(v_prs_c_postal>0)
*/
    if(v_prs_c_postal.len>0)
     {
      bzero(campo1, sizeof(campo1));
/*
      sprintf(campo1, " %04d ", v_prs_c_postal);
*/
      sprintf(campo1, " %s ", v_prs_c_postal.arr);
      strcat(campo, campo1);
      /* EXEC SQL SELECT AGF_NOMBRE
           INTO :v_agf_nombre
           FROM AREAS_GEOGRAFICAS
           WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 17;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select AGF_NOMBRE into :b0  from AREAS_GEOGRAFICAS wher\
e AREAS_GEOGRAFICAS.AGF_CODIGO=:b1";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )984;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_agf_nombre;
      sqlstm.sqhstl[0] = (unsigned long )33;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_agf_codigo;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      AddNullVarchar(v_agf_nombre);
      strcat(campo, v_agf_nombre.arr);
     }
   }
   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Contratos(int largos[],
                char *v_columna,
                char *campo,
                long srv_cod,
                int cnt_num,
                int *ivv_codigo,
                char *tcl_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long    v_srv_cod=-1;
      static long    v_prs_numero;
      static double  v_prs_numero_apoderado;
      static short   s_prs_numero_apoderado;
      static /* varchar v_tcl_codigo[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_tcl_codigo;

      static /* varchar v_cla_codigo[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cla_codigo;
 /* kalave 23/10/2008 de 4 a 11 */
      static /* varchar v_ten_codigo[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_ten_codigo;

      static /* varchar v_cat_codigo[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_cat_codigo;

      static /* varchar v_cnt_propietario[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_propietario;

      static short   s_cnt_propietario;
      static /* varchar v_cnt_fecha_inicio[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cnt_fecha_inicio;

      static int     v_ivv_codigo;
      static /* varchar v_cnt_fecha_fin[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cnt_fecha_fin;

      static short   s_cnt_fecha_fin;
      static double  v_cnt_tension;
      static short   s_cnt_tension;
      static /* varchar v_cnt_tipo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_cnt_tipo;

      static /* varchar v_cnt_cond_corte[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_cond_corte;

      static /* varchar v_cnt_cond_intimacion[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_cond_intimacion;

      static /* varchar v_cnt_cond_retiro[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_cond_retiro;

      static /* varchar v_cnt_direccion_pago[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } v_cnt_direccion_pago;

      static short   s_cnt_direccion_pago;
      static /* varchar v_cnt_calle_pago[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_cnt_calle_pago;

      static short   s_cnt_calle_pago;
      static /* varchar v_cnt_nro_pago[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_cnt_nro_pago;

      static short   s_cnt_nro_pago;
      static /* varchar v_cnt_piso_pago[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cnt_piso_pago;

      static short   s_cnt_piso_pago;
      static /* varchar v_cnt_depto_pago[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cnt_depto_pago;

      static short   s_cnt_depto_pago;
      static /* varchar v_cnt_c_postal_pago[8]; */ 
struct { unsigned short len; unsigned char arr[8]; } v_cnt_c_postal_pago;

      static short   s_cnt_c_postal_pago;
      static double  v_agf_codigo_pago;
      static /* varchar v_min_codigo[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_min_codigo;

      static short   s_min_codigo;
      static int     v_cnt_anio;
      static short   s_cnt_anio;
      static int     v_cnt_periodo;
      static short   s_cnt_periodo;
      static /* varchar v_cnt_tasa[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_tasa;

      static short   s_cnt_tasa;
      static double  v_cnt_consumo_promedio_anual;
      static short   s_consumo_promedio_anual;
      static /* varchar v_cnt_numero_sobre[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_cnt_numero_sobre;

      static short   s_cnt_numero_sobre;
      static double  v_cnt_consumo_promedio_verano;
      static short   s_consumo_promedio_verano;
      static /* varchar v_cnt_numero_reparto[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_cnt_numero_reparto;

      static short   s_cnt_numero_reparto;
      static double  v_cnt_consumo_promedio_invierno;
      static short   s_consumo_promedio_invierno;
      static /* varchar v_cnt_legajo[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_cnt_legajo;

      static short   s_cnt_legajo;
      static double  v_cnt_consumo_maximo;
      static short   s_cnt_consumo_maximo;
      static /* varchar v_cnt_contribucion[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_contribucion;

      static short   s_cnt_contribucion;
      static int     v_cnt_ciiu;
      static short   s_cnt_ciiu;
      static double  v_urc_codigo;
      static short   s_urc_codigo;
      static /* varchar v_mpa_tipo_medio_pago[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_mpa_tipo_medio_pago;

      static short   s_mpa_tipo_medio_pago;
      static /* varchar v_cnt_numero_cuenta[21]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_cnt_numero_cuenta;

      static short   s_cnt_numero_cuenta;
      static /* varchar v_cnt_observaciones[251]; */ 
struct { unsigned short len; unsigned char arr[251]; } v_cnt_observaciones;

      static short   s_cnt_observaciones;
      static /* varchar v_oim_tipo[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_oim_tipo;

      static /* varchar v_cnt_estado[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_cnt_estado;

      static /* varchar v_cll_nombre[60]; */ 
struct { unsigned short len; unsigned char arr[60]; } v_cll_nombre;
short s_cll_nombre;
      static long v_cnt_agf_codigo;
      static /* varchar v_cnt_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_cnt_agf_nombre;
short s_cnt_agf_nombre;

      static short s_prs_numero;
      static short s_cnt_tipo;
      static short s_ivv_codigo;
      static short s_cnt_fecha_inicio;
      static short s_tcl_codigo;
      static short s_cla_codigo;
      static short s_ten_codigo;
      static short s_cat_codigo;
      static short s_oim_tipo;
      static short s_cnt_estado;
      static short s_cnt_agf_codigo;

      static /* varchar v_cnt_bis[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_bis;

      static /* varchar v_cnt_torre_pago[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cnt_torre_pago;

      static short s_cnt_bis;
      static short s_cnt_torre_pago;

      static /* varchar v_srv_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_srv_agf_nombre;

      static short   s_srv_agf_nombre;
      static double  v_agf_codigo;
      static int     v_srv_c_postal;
      static short   s_srv_c_postal;

   /* EXEC SQL END DECLARE SECTION; */ 


   char campo1[60];

   /* Depurar (1, "Busco en CONTRATOS por %s\n", v_columna); */
   if(v_srv_cod!=srv_cod){
      v_srv_cod=srv_cod;
      /* EXEC SQL SELECT T.PRS_NUMERO,
                      T.PRS_NUMERO_APODERADO,
                      T.TCL_CODIGO,
                      T.CLA_CODIGO,
                      T.TEN_CODIGO,
                      T.CAT_CODIGO,
                      T.CNT_PROPIETARIO,
                      to_char(T.CNT_FECHA_INICIO,'dd/mm/yy'),
                      T.IVV_CODIGO,
                      to_char(T.CNT_FECHA_FIN,'dd/mm/yy'),
                      T.CNT_TIPO,
                      T.CNT_DIRECCION_PAGO,
                      T.CNT_NRO_PAGO,
                      T.CNT_PISO_PAGO,
                      T.CNT_DEPTO_PAGO,
                      T.CNT_C_POSTAL_PAGO,
                      T.MIN_CODIGO,
                      T.CNT_ANIO,
                      T.CNT_PERIODO,
                      T.CNT_LEGAJO,
                      T.CNT_CIIU,
                      T.URC_CODIGO,
                      T.MPA_TIPO_MEDIO_PAGO,
                      T.CNT_NUMERO_CUENTA,
                      T.CNT_OBSERVACIONES,
                      T.OIM_TIPO,
                      T.CNT_ESTADO,
                      T.AGF_CODIGO,
                      C.CLL_NOMBRE,
                      T.CNT_BIS,
                      T.CNT_TORRE_PAGO
      INTO           :v_prs_numero:s_prs_numero,
                     :v_prs_numero_apoderado:s_prs_numero_apoderado,
                     :v_tcl_codigo:s_tcl_codigo,
                     :v_cla_codigo:s_cla_codigo,
                     :v_ten_codigo:s_ten_codigo,
                     :v_cat_codigo:s_cat_codigo,
                     :v_cnt_propietario:s_cnt_propietario,
                     :v_cnt_fecha_inicio:s_cnt_fecha_inicio,
                     :v_ivv_codigo:s_ivv_codigo,
                     :v_cnt_fecha_fin:s_cnt_fecha_fin,
                     :v_cnt_tipo:s_cnt_tipo,
                     :v_cnt_direccion_pago:s_cnt_direccion_pago,
                     :v_cnt_nro_pago:s_cnt_nro_pago,
                     :v_cnt_piso_pago:s_cnt_piso_pago,
                     :v_cnt_depto_pago:s_cnt_depto_pago,
                     :v_cnt_c_postal_pago:s_cnt_c_postal_pago,
                     :v_min_codigo:s_min_codigo,
                     :v_cnt_anio:s_cnt_anio,
                     :v_cnt_periodo:s_cnt_periodo,
                     :v_cnt_legajo:s_cnt_legajo,
                     :v_cnt_ciiu:s_cnt_ciiu,
                     :v_urc_codigo:s_urc_codigo,
                     :v_mpa_tipo_medio_pago:s_mpa_tipo_medio_pago,
                     :v_cnt_numero_cuenta:s_cnt_numero_cuenta,
                     :v_cnt_observaciones:s_cnt_observaciones,
                     :v_oim_tipo:s_oim_tipo,
                     :v_cnt_estado:s_cnt_estado,
                     :v_cnt_agf_codigo:s_cnt_agf_codigo,
                     :v_cll_nombre:s_cll_nombre,
                     :v_cnt_bis:s_cnt_bis,
                     :v_cnt_torre_pago:s_cnt_torre_pago
      FROM CONTRATOS T, CALLES C
      WHERE SRV_CODIGO=:srv_cod
      AND   CNT_NUMERO=:cnt_num
      AND   T.AGF_CODIGO=C.AGF_CODIGO (+)
      AND   T.CLL_CODIGO=C.CLL_CODIGO (+); */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select T.PRS_NUMERO ,T.PRS_NUMERO_APODERADO ,T.TCL_CODI\
GO ,T.CLA_CODIGO ,T.TEN_CODIGO ,T.CAT_CODIGO ,T.CNT_PROPIETARIO ,to_char(T.CNT\
_FECHA_INICIO,'dd/mm/yy') ,T.IVV_CODIGO ,to_char(T.CNT_FECHA_FIN,'dd/mm/yy') ,\
T.CNT_TIPO ,T.CNT_DIRECCION_PAGO ,T.CNT_NRO_PAGO ,T.CNT_PISO_PAGO ,T.CNT_DEPTO\
_PAGO ,T.CNT_C_POSTAL_PAGO ,T.MIN_CODIGO ,T.CNT_ANIO ,T.CNT_PERIODO ,T.CNT_LEG\
AJO ,T.CNT_CIIU ,T.URC_CODIGO ,T.MPA_TIPO_MEDIO_PAGO ,T.CNT_NUMERO_CUENTA ,T.C\
NT_OBSERVACIONES ,T.OIM_TIPO ,T.CNT_ESTADO ,T.AGF_CODIGO ,C.CLL_NOMBRE ,T.CNT_\
BIS ,T.CNT_TORRE_PAGO into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b1\
3,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:b26:b27,:b28:b29,:b30\
:b31,:b32:b33,:b34:b35,:b36:b37,:b38:b39,:b40:b41,:b42:b43,:b44:b45,:b46:b47,:\
b48:b49,:b50:b51,:b52:b53,:b54:b55,:b56:b57,:b58:b59,:b60:b61  from CONTRATOS \
T ,CALLES C where (((SRV_CODIGO=:b62 and CNT_NUMERO=:b63) and T.AGF_CODIGO=C.A\
GF_CODIGO(+)) and T.CLL_CODIGO=C.CLL_CODIGO(+))";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1007;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_prs_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)&s_prs_numero;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_prs_numero_apoderado;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)&s_prs_numero_apoderado;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_tcl_codigo;
      sqlstm.sqhstl[2] = (unsigned long )7;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)&s_tcl_codigo;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&v_cla_codigo;
      sqlstm.sqhstl[3] = (unsigned long )13;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)&s_cla_codigo;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&v_ten_codigo;
      sqlstm.sqhstl[4] = (unsigned long )8;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_ten_codigo;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&v_cat_codigo;
      sqlstm.sqhstl[5] = (unsigned long )6;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_cat_codigo;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&v_cnt_propietario;
      sqlstm.sqhstl[6] = (unsigned long )4;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_cnt_propietario;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&v_cnt_fecha_inicio;
      sqlstm.sqhstl[7] = (unsigned long )11;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)&s_cnt_fecha_inicio;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&v_ivv_codigo;
      sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)&s_ivv_codigo;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&v_cnt_fecha_fin;
      sqlstm.sqhstl[9] = (unsigned long )11;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)&s_cnt_fecha_fin;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&v_cnt_tipo;
      sqlstm.sqhstl[10] = (unsigned long )5;
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)&s_cnt_tipo;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&v_cnt_direccion_pago;
      sqlstm.sqhstl[11] = (unsigned long )63;
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)&s_cnt_direccion_pago;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&v_cnt_nro_pago;
      sqlstm.sqhstl[12] = (unsigned long )7;
      sqlstm.sqhsts[12] = (         int  )0;
      sqlstm.sqindv[12] = (         short *)&s_cnt_nro_pago;
      sqlstm.sqinds[12] = (         int  )0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqadto[12] = (unsigned short )0;
      sqlstm.sqtdso[12] = (unsigned short )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&v_cnt_piso_pago;
      sqlstm.sqhstl[13] = (unsigned long )11;
      sqlstm.sqhsts[13] = (         int  )0;
      sqlstm.sqindv[13] = (         short *)&s_cnt_piso_pago;
      sqlstm.sqinds[13] = (         int  )0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqadto[13] = (unsigned short )0;
      sqlstm.sqtdso[13] = (unsigned short )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&v_cnt_depto_pago;
      sqlstm.sqhstl[14] = (unsigned long )11;
      sqlstm.sqhsts[14] = (         int  )0;
      sqlstm.sqindv[14] = (         short *)&s_cnt_depto_pago;
      sqlstm.sqinds[14] = (         int  )0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqadto[14] = (unsigned short )0;
      sqlstm.sqtdso[14] = (unsigned short )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&v_cnt_c_postal_pago;
      sqlstm.sqhstl[15] = (unsigned long )10;
      sqlstm.sqhsts[15] = (         int  )0;
      sqlstm.sqindv[15] = (         short *)&s_cnt_c_postal_pago;
      sqlstm.sqinds[15] = (         int  )0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqadto[15] = (unsigned short )0;
      sqlstm.sqtdso[15] = (unsigned short )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&v_min_codigo;
      sqlstm.sqhstl[16] = (unsigned long )6;
      sqlstm.sqhsts[16] = (         int  )0;
      sqlstm.sqindv[16] = (         short *)&s_min_codigo;
      sqlstm.sqinds[16] = (         int  )0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqadto[16] = (unsigned short )0;
      sqlstm.sqtdso[16] = (unsigned short )0;
      sqlstm.sqhstv[17] = (unsigned char  *)&v_cnt_anio;
      sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[17] = (         int  )0;
      sqlstm.sqindv[17] = (         short *)&s_cnt_anio;
      sqlstm.sqinds[17] = (         int  )0;
      sqlstm.sqharm[17] = (unsigned long )0;
      sqlstm.sqadto[17] = (unsigned short )0;
      sqlstm.sqtdso[17] = (unsigned short )0;
      sqlstm.sqhstv[18] = (unsigned char  *)&v_cnt_periodo;
      sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[18] = (         int  )0;
      sqlstm.sqindv[18] = (         short *)&s_cnt_periodo;
      sqlstm.sqinds[18] = (         int  )0;
      sqlstm.sqharm[18] = (unsigned long )0;
      sqlstm.sqadto[18] = (unsigned short )0;
      sqlstm.sqtdso[18] = (unsigned short )0;
      sqlstm.sqhstv[19] = (unsigned char  *)&v_cnt_legajo;
      sqlstm.sqhstl[19] = (unsigned long )18;
      sqlstm.sqhsts[19] = (         int  )0;
      sqlstm.sqindv[19] = (         short *)&s_cnt_legajo;
      sqlstm.sqinds[19] = (         int  )0;
      sqlstm.sqharm[19] = (unsigned long )0;
      sqlstm.sqadto[19] = (unsigned short )0;
      sqlstm.sqtdso[19] = (unsigned short )0;
      sqlstm.sqhstv[20] = (unsigned char  *)&v_cnt_ciiu;
      sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[20] = (         int  )0;
      sqlstm.sqindv[20] = (         short *)&s_cnt_ciiu;
      sqlstm.sqinds[20] = (         int  )0;
      sqlstm.sqharm[20] = (unsigned long )0;
      sqlstm.sqadto[20] = (unsigned short )0;
      sqlstm.sqtdso[20] = (unsigned short )0;
      sqlstm.sqhstv[21] = (unsigned char  *)&v_urc_codigo;
      sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[21] = (         int  )0;
      sqlstm.sqindv[21] = (         short *)&s_urc_codigo;
      sqlstm.sqinds[21] = (         int  )0;
      sqlstm.sqharm[21] = (unsigned long )0;
      sqlstm.sqadto[21] = (unsigned short )0;
      sqlstm.sqtdso[21] = (unsigned short )0;
      sqlstm.sqhstv[22] = (unsigned char  *)&v_mpa_tipo_medio_pago;
      sqlstm.sqhstl[22] = (unsigned long )7;
      sqlstm.sqhsts[22] = (         int  )0;
      sqlstm.sqindv[22] = (         short *)&s_mpa_tipo_medio_pago;
      sqlstm.sqinds[22] = (         int  )0;
      sqlstm.sqharm[22] = (unsigned long )0;
      sqlstm.sqadto[22] = (unsigned short )0;
      sqlstm.sqtdso[22] = (unsigned short )0;
      sqlstm.sqhstv[23] = (unsigned char  *)&v_cnt_numero_cuenta;
      sqlstm.sqhstl[23] = (unsigned long )23;
      sqlstm.sqhsts[23] = (         int  )0;
      sqlstm.sqindv[23] = (         short *)&s_cnt_numero_cuenta;
      sqlstm.sqinds[23] = (         int  )0;
      sqlstm.sqharm[23] = (unsigned long )0;
      sqlstm.sqadto[23] = (unsigned short )0;
      sqlstm.sqtdso[23] = (unsigned short )0;
      sqlstm.sqhstv[24] = (unsigned char  *)&v_cnt_observaciones;
      sqlstm.sqhstl[24] = (unsigned long )253;
      sqlstm.sqhsts[24] = (         int  )0;
      sqlstm.sqindv[24] = (         short *)&s_cnt_observaciones;
      sqlstm.sqinds[24] = (         int  )0;
      sqlstm.sqharm[24] = (unsigned long )0;
      sqlstm.sqadto[24] = (unsigned short )0;
      sqlstm.sqtdso[24] = (unsigned short )0;
      sqlstm.sqhstv[25] = (unsigned char  *)&v_oim_tipo;
      sqlstm.sqhstl[25] = (unsigned long )6;
      sqlstm.sqhsts[25] = (         int  )0;
      sqlstm.sqindv[25] = (         short *)&s_oim_tipo;
      sqlstm.sqinds[25] = (         int  )0;
      sqlstm.sqharm[25] = (unsigned long )0;
      sqlstm.sqadto[25] = (unsigned short )0;
      sqlstm.sqtdso[25] = (unsigned short )0;
      sqlstm.sqhstv[26] = (unsigned char  *)&v_cnt_estado;
      sqlstm.sqhstl[26] = (unsigned long )7;
      sqlstm.sqhsts[26] = (         int  )0;
      sqlstm.sqindv[26] = (         short *)&s_cnt_estado;
      sqlstm.sqinds[26] = (         int  )0;
      sqlstm.sqharm[26] = (unsigned long )0;
      sqlstm.sqadto[26] = (unsigned short )0;
      sqlstm.sqtdso[26] = (unsigned short )0;
      sqlstm.sqhstv[27] = (unsigned char  *)&v_cnt_agf_codigo;
      sqlstm.sqhstl[27] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[27] = (         int  )0;
      sqlstm.sqindv[27] = (         short *)&s_cnt_agf_codigo;
      sqlstm.sqinds[27] = (         int  )0;
      sqlstm.sqharm[27] = (unsigned long )0;
      sqlstm.sqadto[27] = (unsigned short )0;
      sqlstm.sqtdso[27] = (unsigned short )0;
      sqlstm.sqhstv[28] = (unsigned char  *)&v_cll_nombre;
      sqlstm.sqhstl[28] = (unsigned long )62;
      sqlstm.sqhsts[28] = (         int  )0;
      sqlstm.sqindv[28] = (         short *)&s_cll_nombre;
      sqlstm.sqinds[28] = (         int  )0;
      sqlstm.sqharm[28] = (unsigned long )0;
      sqlstm.sqadto[28] = (unsigned short )0;
      sqlstm.sqtdso[28] = (unsigned short )0;
      sqlstm.sqhstv[29] = (unsigned char  *)&v_cnt_bis;
      sqlstm.sqhstl[29] = (unsigned long )4;
      sqlstm.sqhsts[29] = (         int  )0;
      sqlstm.sqindv[29] = (         short *)&s_cnt_bis;
      sqlstm.sqinds[29] = (         int  )0;
      sqlstm.sqharm[29] = (unsigned long )0;
      sqlstm.sqadto[29] = (unsigned short )0;
      sqlstm.sqtdso[29] = (unsigned short )0;
      sqlstm.sqhstv[30] = (unsigned char  *)&v_cnt_torre_pago;
      sqlstm.sqhstl[30] = (unsigned long )4;
      sqlstm.sqhsts[30] = (         int  )0;
      sqlstm.sqindv[30] = (         short *)&s_cnt_torre_pago;
      sqlstm.sqinds[30] = (         int  )0;
      sqlstm.sqharm[30] = (unsigned long )0;
      sqlstm.sqadto[30] = (unsigned short )0;
      sqlstm.sqtdso[30] = (unsigned short )0;
      sqlstm.sqhstv[31] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[31] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[31] = (         int  )0;
      sqlstm.sqindv[31] = (         short *)0;
      sqlstm.sqinds[31] = (         int  )0;
      sqlstm.sqharm[31] = (unsigned long )0;
      sqlstm.sqadto[31] = (unsigned short )0;
      sqlstm.sqtdso[31] = (unsigned short )0;
      sqlstm.sqhstv[32] = (unsigned char  *)&cnt_num;
      sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[32] = (         int  )0;
      sqlstm.sqindv[32] = (         short *)0;
      sqlstm.sqinds[32] = (         int  )0;
      sqlstm.sqharm[32] = (unsigned long )0;
      sqlstm.sqadto[32] = (unsigned short )0;
      sqlstm.sqtdso[32] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      if(COUNTHITS==0)
         Abortar("No hay datos del contrato.","Error: ");

      if(s_cnt_bis==-1)
        v_cnt_bis.arr[0]=v_cnt_bis.len=0;
      else
        AddNullVarchar(v_cnt_bis);

      if(s_cnt_torre_pago==-1)
        v_cnt_torre_pago.arr[0]=v_cnt_torre_pago.len=0;
      else
        AddNullVarchar(v_cnt_torre_pago);

      *ivv_codigo=v_ivv_codigo;
      Varchar2Str(v_tcl_codigo,tcl_cod);
      if(s_prs_numero_apoderado==-1) v_prs_numero_apoderado=0;
      if(s_cnt_propietario==-1)
                     v_cnt_propietario.arr[0]=v_cnt_propietario.len=0;
      if(s_cnt_fecha_fin==-1) v_cnt_fecha_fin.arr[0]=v_cnt_fecha_fin.len=0;
      if(s_cnt_tension==-1) v_cnt_tension=0;
      if(s_cnt_direccion_pago==-1)
                     v_cnt_direccion_pago.arr[0]=v_cnt_direccion_pago.len=0;
      if(s_cll_nombre==-1)
        v_cll_nombre.arr[0]=v_cll_nombre.len=0;
      else
        AddNullVarchar(v_cll_nombre);
      if(s_cnt_calle_pago==-1) v_cnt_calle_pago.arr[0]=v_cnt_calle_pago.len=0;
      if(s_cnt_nro_pago==-1) v_cnt_nro_pago.arr[0]=v_cnt_nro_pago.len=0;
      if(s_cnt_piso_pago==-1) v_cnt_piso_pago.arr[0]=v_cnt_piso_pago.len=0;
      if(s_cnt_depto_pago==-1) v_cnt_depto_pago.arr[0]=v_cnt_depto_pago.len=0;
      if(s_cnt_c_postal_pago==-1) v_cnt_c_postal_pago.arr[0]=v_cnt_c_postal_pago.len=0;
      if(s_min_codigo==-1) v_min_codigo.arr[0]=v_min_codigo.len=0;
      if(s_cnt_anio==-1) v_cnt_anio=0;
      if(s_cnt_periodo==-1) v_cnt_periodo=0;
      if(s_cnt_tasa==-1) v_cnt_tasa.arr[0]=v_cnt_tasa.len=0;
      if(s_consumo_promedio_anual==-1) v_cnt_consumo_promedio_anual=0;
      if(s_cnt_numero_sobre==-1)
                     v_cnt_numero_sobre.arr[0]=v_cnt_numero_sobre.len=0;
      if(s_consumo_promedio_verano==-1) v_cnt_consumo_promedio_verano=0;
      if(s_cnt_numero_reparto==-1)
                     v_cnt_numero_reparto.arr[0]=v_cnt_numero_reparto.len=0;
      if(s_consumo_promedio_invierno==-1) v_cnt_consumo_promedio_invierno=0;
      if(s_cnt_legajo==-1) v_cnt_legajo.arr[0]=v_cnt_legajo.len=0;
      if(s_cnt_consumo_maximo==-1) v_cnt_consumo_maximo=0;
      if(s_cnt_contribucion==-1)
                     v_cnt_contribucion.arr[0]=v_cnt_contribucion.len=0;
      if(s_cnt_ciiu==-1) v_cnt_ciiu=0;
      if(s_urc_codigo==-1) v_urc_codigo=0;
      if(s_mpa_tipo_medio_pago==-1)
                     v_mpa_tipo_medio_pago.arr[0]=v_mpa_tipo_medio_pago.len=0;
      if(s_cnt_numero_cuenta==-1)
                     v_cnt_numero_cuenta.arr[0]=v_cnt_numero_cuenta.len=0;
      if(s_cnt_observaciones==-1)
                     v_cnt_observaciones.arr[0]=v_cnt_observaciones.len=0;
   }

   if((strcmp(v_columna,"SRV_CODIGO")==0)){
      if(srv_cod>0){sprintf(campo,"%ld",srv_cod);}
   }else if((strcmp(v_columna,"CNT_NUMERO")==0)){
      if(cnt_num>0){sprintf(campo,"%d",cnt_num);}
   }else if((strcmp(v_columna,"PRS_NUMERO")==0)){
      if(v_prs_numero>0){sprintf(campo,"%ld",v_prs_numero);}
   }else if((strcmp(v_columna,"PRS_NUMERO_APODERADO")==0)){
      if(v_prs_numero_apoderado>0){sprintf(campo,"%.0lf",v_prs_numero_apoderado);}
   }else if((strcmp(v_columna,"TCL_CODIGO")==0)){
      Varchar2Str(v_tcl_codigo,campo);
   }else if((strcmp(v_columna,"CLA_CODIGO")==0)){
      Varchar2Str(v_cla_codigo,campo);
   }else if((strcmp(v_columna,"TEN_CODIGO")==0)){
      Varchar2Str(v_ten_codigo,campo);
   }else if((strcmp(v_columna,"CAT_CODIGO")==0)){
      Varchar2Str(v_cat_codigo,campo);
   }else if((strcmp(v_columna,"OBT_PROPIETARIO")==0)){
      Varchar2Str(v_cnt_propietario,campo);
   }else if((strcmp(v_columna,"CNT_FECHA_INICIO")==0)){
      Varchar2Str(v_cnt_fecha_inicio,campo);
   }else if((strcmp(v_columna,"IVV_CODIGO")==0)){
      if(v_ivv_codigo>0){sprintf(campo,"%.0lf",v_ivv_codigo);}
   }else if((strcmp(v_columna,"CNT_FECHA_FIN")==0)){
      Varchar2Str(v_cnt_fecha_fin,campo);
   }else if((strcmp(v_columna,"CNT_TENSION")==0)){
      if(v_cnt_tension>0){sprintf(campo,"%.0lf",v_cnt_tension);}
   }else if((strcmp(v_columna,"CNT_TIPO")==0)){
      Varchar2Str(v_cnt_tipo,campo);
   }else if((strcmp(v_columna,"CNT_COND_CORTE")==0)){
      Varchar2Str(v_cnt_cond_corte,campo);
   }else if((strcmp(v_columna,"CNT_COND_INTIMACION")==0)){
      Varchar2Str(v_cnt_cond_intimacion,campo);
   }else if((strcmp(v_columna,"CNT_COND_RETIRO")==0)){
      Varchar2Str(v_cnt_cond_retiro,campo);
   }else if((strcmp(v_columna,"CNT_DIRECCION_PAGO")==0))
    {
     /*
      * Estan pidiendo el domicilio postal.
      *
      * Vieja logica: si no hay nombre de calle, dar
      *               cnt_direccion_pago
      * Nueva logica: si cnt_direccion_pago no esta
      *               vacio, darla.
      */
     /* if(s_cll_nombre==-1) */
     if(srv_cod==0)
      {
        ClearVarchar(l_prs_razon_social);
        ClearVarchar(l_prs_direccion);
        ClearVarchar(l_cfc_codigo);
        ClearVarchar(ll_prs_calle);
        ClearVarchar(ll_prs_nro);
        ClearVarchar(ll_prs_piso);
        ClearVarchar(ll_prs_depto);
        ClearVarchar(ll_prs_torre);
        ClearVarchar(ll_prs_c_postal);
        /* exec sql
          select personas.prs_numero,
              substr(personas.prs_razon_social,1,25),
              nvl(personas.prs_direccion, ' '),
              personas.cfc_codigo,
              substr(calles.cll_nombre,1,18),
              substr(nvl(personas.prs_nro, '    '),1,4),
              substr(nvl(personas.prs_piso, '  '),1,2),
              substr(nvl(personas.prs_depto, '   '),1,3),
              nvl(personas.prs_torre, ' '),
              nvl(personas.prs_c_postal, ' '),
              personas.agf_codigo
          into :l_prs_numero,
              :l_prs_razon_social,
              :l_prs_direccion,
              :l_cfc_codigo,
              :ll_prs_calle,
              :ll_prs_nro,
              :ll_prs_piso,
              :ll_prs_depto,
              :ll_prs_torre,
              :ll_prs_c_postal,
              :ll_prs_agf_codigo
         from personas, calles
         where calles.cll_codigo = personas.cll_codigo
           and calles.agf_codigo = personas.agf_codigo
           and personas.prs_numero = :l_o_prs_numero; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 33;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select personas.prs_numero ,substr(personas.prs_razon\
_social,1,25) ,nvl(personas.prs_direccion,' ') ,personas.cfc_codigo ,substr(ca\
lles.cll_nombre,1,18) ,substr(nvl(personas.prs_nro,'    '),1,4) ,substr(nvl(pe\
rsonas.prs_piso,'  '),1,2) ,substr(nvl(personas.prs_depto,'   '),1,3) ,nvl(per\
sonas.prs_torre,' ') ,nvl(personas.prs_c_postal,' ') ,personas.agf_codigo into\
 :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10  from personas ,calles where ((c\
alles.cll_codigo=personas.cll_codigo and calles.agf_codigo=personas.agf_codigo\
) and personas.prs_numero=:b11)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1154;
        sqlstm.selerr = (unsigned short)0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&l_prs_numero;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&l_prs_razon_social;
        sqlstm.sqhstl[1] = (unsigned long )63;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&l_prs_direccion;
        sqlstm.sqhstl[2] = (unsigned long )48;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&l_cfc_codigo;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&ll_prs_calle;
        sqlstm.sqhstl[4] = (unsigned long )21;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&ll_prs_nro;
        sqlstm.sqhstl[5] = (unsigned long )7;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&ll_prs_piso;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&ll_prs_depto;
        sqlstm.sqhstl[7] = (unsigned long )6;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&ll_prs_torre;
        sqlstm.sqhstl[8] = (unsigned long )6;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&ll_prs_c_postal;
        sqlstm.sqhstl[9] = (unsigned long )11;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&ll_prs_agf_codigo;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&l_o_prs_numero;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


         bzero(campo, sizeof(campo));
         sprintf(campo, "%-18s%-4s%-2s%-3s%-3s", ll_prs_calle.arr,
           ll_prs_nro.arr, ll_prs_piso.arr, ll_prs_depto.arr,
           ll_prs_torre.arr);
         if(ll_prs_c_postal.arr[0]!=0)
          {
           bzero(campo1, sizeof(campo1));
           sprintf(campo1, " %s ", ll_prs_c_postal.arr);
           strcat(campo, campo1);
           /* EXEC SQL SELECT AGF_NOMBRE
             INTO :v_srv_agf_nombre:s_srv_agf_nombre
             FROM AREAS_GEOGRAFICAS
             WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :ll_prs_agf_codigo; */ 

{
           struct sqlexd sqlstm;
           sqlorat((void **)0, &sqlctx, &oraca);
           sqlstm.sqlvsn = 12;
           sqlstm.arrsiz = 33;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "select AGF_NOMBRE into :b0:b1  from AREAS_GEOGRAFI\
CAS where AREAS_GEOGRAFICAS.AGF_CODIGO=:b2";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )1217;
           sqlstm.selerr = (unsigned short)0;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (unsigned char  *)&v_srv_agf_nombre;
           sqlstm.sqhstl[0] = (unsigned long )33;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)&s_srv_agf_nombre;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned long )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (unsigned char  *)&ll_prs_agf_codigo;
           sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         short *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned long )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


           if(s_srv_agf_nombre!=-1)
            {
             AddNullVarchar(v_srv_agf_nombre);
             strcat(campo, v_srv_agf_nombre.arr);
            }
          }
      }
     else
     if(strlen(v_cnt_direccion_pago.arr)!=0)
     {
       psal=0;
       /* Con la nueva logica, este if es redundante... (d.molina 24/ago/99) */
       /* if(strlen(v_cnt_direccion_pago.arr)!=0) */
       {
         for(pent=0; pent<strlen(v_cnt_direccion_pago.arr); pent++)
           if((v_cnt_direccion_pago.arr[pent]==' ')
           &&(v_cnt_direccion_pago.arr[pent+1]==' '))
             pent=pent;
           else
             psalida[psal++]=v_cnt_direccion_pago.arr[pent];
       }
       psalida[psal]=0;
       strcpy(campo, psalida);
     }
     else
     {
       Depurar (3, "Antes del Varchar2Str\n");
       Varchar2Str(v_cll_nombre, campo1);
       Depurar (3, "Despues del Varchar2Str\n");
       if(strlen(campo1)!=0)
         for(;campo1[strlen(campo1)-1]==' ';)
         {
           if(strlen(campo1)==0)
             break;
           else
           {
             campo1[strlen(campo1)-1]=0;
             Depurar (3, "(%s)\n", campo1);
           }
         }
       strcpy(campo, campo1);
       if((v_cnt_bis.len>0)&&(v_cnt_bis.arr[0]!='N'))
        {
         AddNullVarchar(v_cnt_bis);
         strcat(campo, " ");
         strcat(campo, v_cnt_bis.arr);
        }
       if(v_cnt_nro_pago.len>0)
        {
         AddNullVarchar(v_cnt_nro_pago);
         strcat(campo, " ");
         strcat(campo, v_cnt_nro_pago.arr);
        }
       if(v_cnt_torre_pago.len>0)
        {
         AddNullVarchar(v_cnt_torre_pago);
         strcat(campo, " ");
         strcat(campo, v_cnt_torre_pago.arr);
        }
       if(v_cnt_piso_pago.len>0)
        {
         AddNullVarchar(v_cnt_piso_pago);
         strcat(campo, " ");
         strcat(campo, v_cnt_piso_pago.arr);
        }
       if(v_cnt_depto_pago.len>0)
        {
         AddNullVarchar(v_cnt_depto_pago);
         strcat(campo, " ");
         strcat(campo, v_cnt_depto_pago.arr);
        }
       if(v_cnt_c_postal_pago.len>0)
        {
         bzero(campo1, sizeof(campo1));
         sprintf(campo1, " (%s) ", v_cnt_c_postal_pago.arr);
         strcat(campo, campo1);
         /* EXEC SQL SELECT AGF_NOMBRE
           INTO :v_cnt_agf_nombre:s_cnt_agf_nombre
           FROM AREAS_GEOGRAFICAS
           WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_cnt_agf_codigo; */ 

{
         struct sqlexd sqlstm;
         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 33;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select AGF_NOMBRE into :b0:b1  from AREAS_GEOGRAFICA\
S where AREAS_GEOGRAFICAS.AGF_CODIGO=:b2";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1240;
         sqlstm.selerr = (unsigned short)0;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt_agf_nombre;
         sqlstm.sqhstl[0] = (unsigned long )33;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&s_cnt_agf_nombre;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cnt_agf_codigo;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


         if(s_cnt_agf_nombre!=-1)
          {
           AddNullVarchar(v_cnt_agf_nombre);
           strcat(campo, v_cnt_agf_nombre.arr);
          }
        }
      }
   }else if((strcmp(v_columna,"CNT_CALLE_PAGO")==0)){
      Varchar2Str(v_cnt_calle_pago,campo);
   }else if((strcmp(v_columna,"CNT_NRO_PAGO")==0)){
      Varchar2Str(v_cnt_nro_pago,campo);
   }else if((strcmp(v_columna,"CNT_PISO_PAGO")==0)){
      Varchar2Str(v_cnt_piso_pago,campo);
   }else if((strcmp(v_columna,"CNT_DEPTO_PAGO")==0)){
      Varchar2Str(v_cnt_depto_pago,campo);
   }else if((strcmp(v_columna,"CNT_C_POSTAL_PAGO")==0)){
      if(v_cnt_c_postal_pago.len>0){sprintf(campo,"(%s)",v_cnt_c_postal_pago.arr);}
   }else if((strcmp(v_columna,"AGF_CODIGO_PAGO")==0)){
      if(v_agf_codigo_pago>0){sprintf(campo,"%.0lf",v_agf_codigo_pago);}
   }else if((strcmp(v_columna,"MIN_CODIGO")==0)){
      Varchar2Str(v_min_codigo,campo);
   }else if((strcmp(v_columna,"CNT_ANIO")==0)){
      if(v_cnt_anio>0){sprintf(campo,"%.0lf",v_cnt_anio);}
   }else if((strcmp(v_columna,"CNT_PERIODO")==0)){
      if(v_cnt_periodo>0){sprintf(campo,"%.0lf",v_cnt_periodo);}
   }else if((strcmp(v_columna,"CNT_TASA")==0)){
      Varchar2Str(v_cnt_tasa,campo);
   }else if((strcmp(v_columna,"CNT_CONSUMO_PROMEDIO_ANUAL")==0)){
      if(v_cnt_consumo_promedio_anual>0){sprintf(campo,"%.0lf",v_cnt_consumo_promedio_anual);}
   }else if((strcmp(v_columna,"CNT_NUMERO_SOBRE")==0)){
      Varchar2Str(v_cnt_numero_sobre,campo);
   }else if((strcmp(v_columna,"CNT_CONSUMO_PROMEDIO_VERANO")==0)){
      if(v_cnt_consumo_promedio_verano>0){sprintf(campo,"%.0lf",v_cnt_consumo_promedio_verano);}
   }else if((strcmp(v_columna,"CNT_NUMERO_REPARTO")==0)){
      Varchar2Str(v_cnt_numero_reparto,campo);
   }else
      if((strcmp(v_columna,"CNT_CONSUMO_PROMEDIO_INVIERNO")==0)){
      if(v_cnt_consumo_promedio_invierno>0){sprintf(campo,"%.0lf",v_cnt_consumo_promedio_invierno);}
   }else if((strcmp(v_columna,"CNT_LEGAJO")==0)){
      Varchar2Str(v_cnt_legajo,campo);
   }else if((strcmp(v_columna,"CNT_CONSUMO_MAXIMO")==0)){
      if(v_cnt_consumo_maximo>0){sprintf(campo,"%.0lf",v_cnt_consumo_maximo);}
   }else if((strcmp(v_columna,"CNT_CONTRIBUCION")==0)){
      Varchar2Str(v_cnt_contribucion,campo);
   }else if((strcmp(v_columna,"CNT_CIIU")==0)){
      if(v_cnt_ciiu>0){sprintf(campo,"%.0lf",v_cnt_ciiu);}
   }else if((strcmp(v_columna,"URC_CODIGO")==0)){
      if(v_urc_codigo>0){sprintf(campo,"%.0lf",v_urc_codigo);}
   } if((strcmp(v_columna,"MPA_TIPO_MEDIO_PAGO")==0)){
      Varchar2Str(v_mpa_tipo_medio_pago,campo);
   }else if((strcmp(v_columna,"CNT_NUMERO_CUENTA")==0)){
      Varchar2Str(v_cnt_numero_cuenta,campo);
   }else if((strcmp(v_columna,"CNT_OBSERVACIONES")==0)){
      Varchar2Str(v_cnt_observaciones,campo);
   }else if((strcmp(v_columna,"OIM_TIPO")==0)){
      Varchar2Str(v_oim_tipo,campo);
   }else if((strcmp(v_columna,"CNT_ESTADO")==0)){
      Varchar2Str(v_cnt_estado,campo);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Servicios(int largos[],char *v_columna,char *campo,long srv_cod,long *scf_cod, long *agf_cod)
{
  /* BF:
   * DF:
   * EF: */

   char campo1[60];

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long    v_srv_cod=-1;
      static long    v_scf_codigo;
      static /* varchar v_age_codigo[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_age_codigo;

      static short   s_age_codigo;
      static long    v_rta_codigo;
      static long    v_srv_orden_lectura;
      static short   s_srv_orden_lectura;
      static /* varchar v_srv_direccion[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } v_srv_direccion;

      static short   s_srv_direccion;
      static /* varchar v_srv_calle[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_srv_calle;

      static short   s_srv_calle;
      static /* varchar v_srv_bis[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_srv_bis;

      static short   s_srv_bis;
      static long    v_srv_nro;
      static short   s_srv_nro;
      static /* varchar v_srv_torre[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_srv_torre;

      static short   s_srv_torre;
      static /* varchar v_srv_piso[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_srv_piso;

      static short   s_srv_piso;
      static /* varchar v_srv_depto[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_srv_depto;

      static short   s_srv_depto;
      static int     v_srv_c_postal;
      static short   s_srv_c_postal;
      static long    v_agf_codigo;
      static /* varchar v_srv_fecha_instal[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_srv_fecha_instal;

      static short   s_srv_fecha_instal;
      static /* varchar v_srv_fecha_baja[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_srv_fecha_baja;

      static short   s_srv_fecha_baja;
      static /* varchar v_srv_motivo_baja[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_srv_motivo_baja;

      static short   s_srv_motivo_baja;
      static int     v_srv_plan_original;
      static short   s_srv_plan_original;
      static int     v_srv_zona_original;
      static short   s_srv_zona_original;
      static int     v_srv_localidad_original;
      static short   s_srv_localidad_original;
      static int     v_srv_ruta_original;
      static short   s_srv_ruta_original;
      static int     v_srv_suministro_original;
      static short   s_srv_suministro_original;
      static long    v_srv_promedio_verano;
      static short   s_srv_promedio_verano;
      static long    v_srv_promedio_invierno;
      static short   s_srv_promedio_invierno;
      static long    v_srv_promedio_anual;
      static short   s_srv_promedio_anual;
      static /* varchar v_srv_tipo_suministro[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_srv_tipo_suministro;

      static short   s_srv_tipo_suministro;
      static long    v_edi_numero;
      static short   s_edi_numero;
      static long    v_erd_codigo;
      static short   s_erd_codigo;
      static /* varchar v_srv_distrito_cat[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_srv_distrito_cat;

      static short   s_srv_distrito_cat;
      static /* varchar v_srv_zona_cat[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_srv_zona_cat;

      static short   s_srv_zona_cat;
      static /* varchar v_srv_manzana_cat[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_srv_manzana_cat;

      static short   s_srv_manzana_cat;
      static /* varchar v_srv_lote_cat[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_srv_lote_cat;

      static short   s_srv_lote_cat;
      static /* varchar v_srv_estado[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_srv_estado;

      static /* varchar v_srv_observaciones[241]; */ 
struct { unsigned short len; unsigned char arr[241]; } v_srv_observaciones;

      static short   s_srv_observaciones;
      static /* varchar v_cll_nombre[60]; */ 
struct { unsigned short len; unsigned char arr[60]; } v_cll_nombre;

      static short   s_cll_nombre;
      static /* varchar v_srv_agf_nombre[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_srv_agf_nombre;

      static short   s_srv_agf_nombre;
   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en SERVICIOS por %s\n", v_columna); */
   if(v_srv_cod!=srv_cod){
      v_srv_cod=srv_cod;
      /* EXEC SQL SELECT S.SCF_CODIGO,
                      S.AGE_CODIGO,
                      S.RTA_CODIGO,
                      S.SRV_ORDEN_LECTURA,
                      S.SRV_DIRECCION,
                      S.SRV_BIS,
                      S.SRV_NRO,
                      S.SRV_TORRE,
                      S.SRV_PISO,
                      S.SRV_DEPTO,
                      S.SRV_C_POSTAL,
                      S.AGF_CODIGO,
                      to_char(S.SRV_FECHA_INSTAL,'dd/mm/yy'),
                      to_char(S.SRV_FECHA_BAJA,'dd/mm/yy'),
                      S.SRV_MOTIVO_BAJA,
                      S.SRV_SUMINISTRO_ORIGINAL,
                      S.EDI_NUMERO,
                      S.SRV_ZONA_CATA,
                      S.SRV_MANZANA_CATA,
                      S.SRV_LOTE_CATA,
                      S.SRV_ESTADO,
                      S.SRV_OBSERVACIONES,
                      C.CLL_NOMBRE
      INTO           :v_scf_codigo,
                     :v_age_codigo:s_age_codigo,
                     :v_rta_codigo,
                     :v_srv_orden_lectura:s_srv_orden_lectura,
                     :v_srv_direccion:s_srv_direccion,
                     :v_srv_bis:s_srv_bis,
                     :v_srv_nro:s_srv_nro,
                     :v_srv_torre:s_srv_torre,
                     :v_srv_piso:s_srv_piso,
                     :v_srv_depto:s_srv_depto,
                     :v_srv_c_postal:s_srv_c_postal,
                     :v_agf_codigo,
                     :v_srv_fecha_instal:s_srv_fecha_instal,
                     :v_srv_fecha_baja:s_srv_fecha_baja,
                     :v_srv_motivo_baja:s_srv_motivo_baja,
                     :v_srv_suministro_original:s_srv_suministro_original,
                     :v_edi_numero:s_edi_numero,
                     :v_srv_zona_cat:s_srv_zona_cat,
                     :v_srv_manzana_cat:s_srv_manzana_cat,
                     :v_srv_lote_cat:s_srv_lote_cat,
                     :v_srv_estado,
                     :v_srv_observaciones:s_srv_observaciones,
                     :v_cll_nombre:s_cll_nombre
      FROM SERVICIOS S, CALLES C
      WHERE SRV_CODIGO=:srv_cod
      -- AND   CNT_NUMERO=:cnt_num
      AND   S.AGF_CODIGO=C.AGF_CODIGO (+)
      AND   S.CLL_CODIGO=C.CLL_CODIGO (+); */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select S.SCF_CODIGO ,S.AGE_CODIGO ,S.RTA_CODIGO ,S.SRV_\
ORDEN_LECTURA ,S.SRV_DIRECCION ,S.SRV_BIS ,S.SRV_NRO ,S.SRV_TORRE ,S.SRV_PISO \
,S.SRV_DEPTO ,S.SRV_C_POSTAL ,S.AGF_CODIGO ,to_char(S.SRV_FECHA_INSTAL,'dd/mm/\
yy') ,to_char(S.SRV_FECHA_BAJA,'dd/mm/yy') ,S.SRV_MOTIVO_BAJA ,S.SRV_SUMINISTR\
O_ORIGINAL ,S.EDI_NUMERO ,S.SRV_ZONA_CATA ,S.SRV_MANZANA_CATA ,S.SRV_LOTE_CATA\
 ,S.SRV_ESTADO ,S.SRV_OBSERVACIONES ,C.CLL_NOMBRE into :b0,:b1:b2,:b3,:b4:b5,:\
b6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20,:b21:b22,:b23:b\
24,:b25:b26,:b27:b28,:b29:b30,:b31:b32,:b33:b34,:b35:b36,:b37,:b38:b39,:b40:b4\
1  from SERVICIOS S ,CALLES C where ((SRV_CODIGO=:b42 and S.AGF_CODIGO=C.AGF_C\
ODIGO(+)) and S.CLL_CODIGO=C.CLL_CODIGO(+))";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1263;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_scf_codigo;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_age_codigo;
      sqlstm.sqhstl[1] = (unsigned long )4;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)&s_age_codigo;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_rta_codigo;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&v_srv_orden_lectura;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)&s_srv_orden_lectura;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&v_srv_direccion;
      sqlstm.sqhstl[4] = (unsigned long )63;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_srv_direccion;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&v_srv_bis;
      sqlstm.sqhstl[5] = (unsigned long )4;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_srv_bis;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&v_srv_nro;
      sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_srv_nro;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&v_srv_torre;
      sqlstm.sqhstl[7] = (unsigned long )4;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)&s_srv_torre;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&v_srv_piso;
      sqlstm.sqhstl[8] = (unsigned long )5;
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)&s_srv_piso;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&v_srv_depto;
      sqlstm.sqhstl[9] = (unsigned long )6;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)&s_srv_depto;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&v_srv_c_postal;
      sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)&s_srv_c_postal;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&v_agf_codigo;
      sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&v_srv_fecha_instal;
      sqlstm.sqhstl[12] = (unsigned long )11;
      sqlstm.sqhsts[12] = (         int  )0;
      sqlstm.sqindv[12] = (         short *)&s_srv_fecha_instal;
      sqlstm.sqinds[12] = (         int  )0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqadto[12] = (unsigned short )0;
      sqlstm.sqtdso[12] = (unsigned short )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&v_srv_fecha_baja;
      sqlstm.sqhstl[13] = (unsigned long )11;
      sqlstm.sqhsts[13] = (         int  )0;
      sqlstm.sqindv[13] = (         short *)&s_srv_fecha_baja;
      sqlstm.sqinds[13] = (         int  )0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqadto[13] = (unsigned short )0;
      sqlstm.sqtdso[13] = (unsigned short )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&v_srv_motivo_baja;
      sqlstm.sqhstl[14] = (unsigned long )5;
      sqlstm.sqhsts[14] = (         int  )0;
      sqlstm.sqindv[14] = (         short *)&s_srv_motivo_baja;
      sqlstm.sqinds[14] = (         int  )0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqadto[14] = (unsigned short )0;
      sqlstm.sqtdso[14] = (unsigned short )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&v_srv_suministro_original;
      sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[15] = (         int  )0;
      sqlstm.sqindv[15] = (         short *)&s_srv_suministro_original;
      sqlstm.sqinds[15] = (         int  )0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqadto[15] = (unsigned short )0;
      sqlstm.sqtdso[15] = (unsigned short )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&v_edi_numero;
      sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[16] = (         int  )0;
      sqlstm.sqindv[16] = (         short *)&s_edi_numero;
      sqlstm.sqinds[16] = (         int  )0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqadto[16] = (unsigned short )0;
      sqlstm.sqtdso[16] = (unsigned short )0;
      sqlstm.sqhstv[17] = (unsigned char  *)&v_srv_zona_cat;
      sqlstm.sqhstl[17] = (unsigned long )6;
      sqlstm.sqhsts[17] = (         int  )0;
      sqlstm.sqindv[17] = (         short *)&s_srv_zona_cat;
      sqlstm.sqinds[17] = (         int  )0;
      sqlstm.sqharm[17] = (unsigned long )0;
      sqlstm.sqadto[17] = (unsigned short )0;
      sqlstm.sqtdso[17] = (unsigned short )0;
      sqlstm.sqhstv[18] = (unsigned char  *)&v_srv_manzana_cat;
      sqlstm.sqhstl[18] = (unsigned long )7;
      sqlstm.sqhsts[18] = (         int  )0;
      sqlstm.sqindv[18] = (         short *)&s_srv_manzana_cat;
      sqlstm.sqinds[18] = (         int  )0;
      sqlstm.sqharm[18] = (unsigned long )0;
      sqlstm.sqadto[18] = (unsigned short )0;
      sqlstm.sqtdso[18] = (unsigned short )0;
      sqlstm.sqhstv[19] = (unsigned char  *)&v_srv_lote_cat;
      sqlstm.sqhstl[19] = (unsigned long )7;
      sqlstm.sqhsts[19] = (         int  )0;
      sqlstm.sqindv[19] = (         short *)&s_srv_lote_cat;
      sqlstm.sqinds[19] = (         int  )0;
      sqlstm.sqharm[19] = (unsigned long )0;
      sqlstm.sqadto[19] = (unsigned short )0;
      sqlstm.sqtdso[19] = (unsigned short )0;
      sqlstm.sqhstv[20] = (unsigned char  *)&v_srv_estado;
      sqlstm.sqhstl[20] = (unsigned long )6;
      sqlstm.sqhsts[20] = (         int  )0;
      sqlstm.sqindv[20] = (         short *)0;
      sqlstm.sqinds[20] = (         int  )0;
      sqlstm.sqharm[20] = (unsigned long )0;
      sqlstm.sqadto[20] = (unsigned short )0;
      sqlstm.sqtdso[20] = (unsigned short )0;
      sqlstm.sqhstv[21] = (unsigned char  *)&v_srv_observaciones;
      sqlstm.sqhstl[21] = (unsigned long )243;
      sqlstm.sqhsts[21] = (         int  )0;
      sqlstm.sqindv[21] = (         short *)&s_srv_observaciones;
      sqlstm.sqinds[21] = (         int  )0;
      sqlstm.sqharm[21] = (unsigned long )0;
      sqlstm.sqadto[21] = (unsigned short )0;
      sqlstm.sqtdso[21] = (unsigned short )0;
      sqlstm.sqhstv[22] = (unsigned char  *)&v_cll_nombre;
      sqlstm.sqhstl[22] = (unsigned long )62;
      sqlstm.sqhsts[22] = (         int  )0;
      sqlstm.sqindv[22] = (         short *)&s_cll_nombre;
      sqlstm.sqinds[22] = (         int  )0;
      sqlstm.sqharm[22] = (unsigned long )0;
      sqlstm.sqadto[22] = (unsigned short )0;
      sqlstm.sqtdso[22] = (unsigned short )0;
      sqlstm.sqhstv[23] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[23] = (         int  )0;
      sqlstm.sqindv[23] = (         short *)0;
      sqlstm.sqinds[23] = (         int  )0;
      sqlstm.sqharm[23] = (unsigned long )0;
      sqlstm.sqadto[23] = (unsigned short )0;
      sqlstm.sqtdso[23] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      if(COUNTHITS==0)
         Abortar("No hay datos de servicios.","Error: ");


      *scf_cod=v_scf_codigo;
      *agf_cod=v_agf_codigo;
      if(s_srv_orden_lectura==-1) v_srv_orden_lectura=0;
      if(s_age_codigo==-1) v_age_codigo.arr[0]=v_age_codigo.len=0;
      if(s_srv_direccion==-1) v_srv_direccion.arr[0]=v_srv_direccion.len=0;
/*
      Cambio a pedido de rcittadi del 6-11-2003
*/
      v_srv_direccion.arr[0]=0;
      v_srv_direccion.len=0;
/*
      Fin del cambio
*/
      if(s_srv_calle==-1) v_srv_calle.arr[0]=v_srv_calle.len=0;
      if(s_srv_bis==-1) v_srv_bis.arr[0]=v_srv_bis.len=0;
      if(s_srv_nro==-1) v_srv_nro=0;
      if(s_srv_torre==-1) v_srv_torre.arr[0]=v_srv_torre.len=0;
      if(s_srv_piso==-1) v_srv_piso.arr[0]=v_srv_piso.len=0;
      if(s_srv_depto==-1) v_srv_depto.arr[0]=v_srv_depto.len=0;
      if(s_srv_c_postal==-1) v_srv_c_postal=0;
      if(s_srv_fecha_instal==-1)
                     v_srv_fecha_instal.arr[0]=v_srv_fecha_instal.len=0;
      if(s_srv_fecha_baja==-1)
                     v_srv_fecha_baja.arr[0]=v_srv_fecha_baja.len=0;
      if(s_srv_motivo_baja==-1)
                     v_srv_motivo_baja.arr[0]=v_srv_motivo_baja.len=0;
      if(s_srv_plan_original==-1) v_srv_plan_original=0;
      if(s_srv_zona_original==-1) v_srv_zona_original=0;
      if(s_srv_localidad_original==-1) v_srv_localidad_original=0;
      if(s_srv_ruta_original==-1) v_srv_ruta_original=0;
      if(s_srv_suministro_original==-1) v_srv_suministro_original=0;
      if(s_srv_promedio_verano==-1) v_srv_promedio_verano=0;
      if(s_srv_promedio_invierno==-1) v_srv_promedio_invierno=0;
      if(s_srv_promedio_anual==-1) v_srv_promedio_anual=0;
      if(s_srv_tipo_suministro==-1)
                     v_srv_tipo_suministro.arr[0]=v_srv_tipo_suministro.len=0;
      if(s_edi_numero==-1) v_edi_numero=0;
      if(s_erd_codigo==-1) v_erd_codigo=0;
      if(s_srv_distrito_cat==-1)
                     v_srv_distrito_cat.arr[0]=v_srv_distrito_cat.len=0;
      if(s_srv_zona_cat==-1) v_srv_zona_cat.arr[0]=v_srv_zona_cat.len=0;
      if(s_srv_manzana_cat==-1)
                     v_srv_manzana_cat.arr[0]=v_srv_manzana_cat.len=0;
      if(s_srv_lote_cat==-1) v_srv_lote_cat.arr[0]=v_srv_lote_cat.len=0;
      if(s_srv_observaciones==-1)
                     v_srv_observaciones.arr[0]=v_srv_observaciones.len=0;
      if(s_cll_nombre==-1)
                     v_cll_nombre.arr[0]=v_cll_nombre.len=0;
   }
   if((strcmp(v_columna,"SRV_CODIGO")==0)){
       if(srv_cod>0){sprintf(campo,"%ld",srv_cod);}
   }else if((strcmp(v_columna,"SCF_CODIGO")==0)){
       if(v_scf_codigo>0){sprintf(campo,"%ld",v_scf_codigo);}
   }else if((strcmp(v_columna,"AGE_CODIGO")==0)){
       Varchar2Str(v_age_codigo,campo);
   }else if((strcmp(v_columna,"RTA_CODIGO")==0)){
       if(v_rta_codigo>0){sprintf(campo,"%ld",v_rta_codigo);}
   }else if((strcmp(v_columna,"SRV_ORDEN_LECTURA")==0)){
       if(v_srv_orden_lectura>0){sprintf(campo,"%ld",v_srv_orden_lectura);}
   }else if((strcmp(v_columna,"SRV_DIRECCION")==0)){
     /*
      * Estan pidiendo el domicilio del suministro.
      * Si srv_direccion no esta vacio, darlo.
      */
/*
   Cambio del 22-12-2003: czero
   Para que imprima el domicilio de la persona
*/
/*
      if(srv_cod==0)
       {
        ClearVarchar(l_prs_razon_social);
        ClearVarchar(l_prs_direccion);
        ClearVarchar(l_cfc_codigo);
        ClearVarchar(ll_prs_calle);
        ClearVarchar(ll_prs_nro);
        ClearVarchar(ll_prs_piso);
        ClearVarchar(ll_prs_depto);
        ClearVarchar(ll_prs_torre);
        exec sql
          select personas.prs_numero,
              substr(personas.prs_razon_social,1,25),
              nvl(personas.prs_direccion, ' '),
              personas.cfc_codigo,
              substr(calles.cll_nombre,1,18),
              substr(personas.prs_nro,1,4),
              substr(personas.prs_piso,1,2),
              substr(personas.prs_depto,1,3),
              personas.prs_torre
          into :l_prs_numero,
              :l_prs_razon_social,
              :l_prs_direccion,
              :l_cfc_codigo,
              :ll_prs_calle,
              :ll_prs_nro,
              :ll_prs_piso,
              :ll_prs_depto,
              :ll_prs_torre
         from personas, calles
         where calles.cll_codigo = personas.cll_codigo
           and calles.agf_codigo = personas.agf_codigo
           and personas.prs_numero = :l_o_prs_numero;
         bzero(campo, sizeof(campo));
         sprintf(campo, "%-18s%-4s%-2s%-3s%-3s", ll_prs_calle.arr,
           ll_prs_nro.arr, ll_prs_piso.arr, ll_prs_depto.arr,
           ll_prs_torre.arr);
         if(v_srv_c_postal>0)
          {
           bzero(campo1, sizeof(campo1));
           sprintf(campo1, " %04d ", v_srv_c_postal);
           strcat(campo, campo1);
           EXEC SQL SELECT AGF_NOMBRE
             INTO :v_srv_agf_nombre:s_srv_agf_nombre
             FROM AREAS_GEOGRAFICAS
             WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo;
           if(s_srv_agf_nombre!=-1)
            {
             AddNullVarchar(v_srv_agf_nombre);
             strcat(campo, v_srv_agf_nombre.arr);
            }
          }
       }
*/
      if(srv_cod==0)
       {
        strcpy(campo, " ");
       }
     else
       if(strlen(v_srv_direccion.arr)!=0)
        {
         /* Depurar (3, "Hay SRV_DIRECCION !!!\n"); */
            psal=0;
         for(pent=0; pent<strlen(v_srv_direccion.arr); pent++)
           if((v_srv_direccion.arr[pent]==' ')
           &&(v_srv_direccion.arr[pent+1]==' '))
             pent=pent;
           else
             psalida[psal++]=v_srv_direccion.arr[pent];
         psalida[psal]=0;
         strcpy(campo, psalida);
        }
       else
        {
         /* Depurar (3, "No hay SRV_DIRECCION - Construyendo.\n"); */
         Varchar2Str(v_cll_nombre, campo1);
         /* Una forma rebuscada de eliminar los espacios al final */
         if(strlen(campo1)!=0)
           for(;campo1[strlen(campo1)-1]==' ';)
            {
             if(strlen(campo1)==0)
               break;
             else
              {
               campo1[strlen(campo1)-1]=0;
               Depurar (3, "(%s)\n", campo1);
              }
            }
         strcpy(campo, campo1);
         if((v_srv_bis.len>0)&&(v_srv_bis.arr[0]!='N'))
          {
           AddNullVarchar(v_srv_bis);
           strcat(campo, " ");
           strcat(campo, v_srv_bis.arr);
          }
         if(v_srv_nro>0)
          {
           sprintf(campo1, " %ld", v_srv_nro);
           strcat(campo, campo1);
          }
         /* ------------------ No es varchar!!!
         if(v_srv_nro.len>0)
          {
           AddNullVarchar(v_srv_nro);
           strcat(campo, " ");
           strcat(campo, v_srv_nro.arr);
          }
         --------------------*/
         if(v_srv_torre.len>0)
          {
           AddNullVarchar(v_srv_torre);
           strcat(campo, " ");
           strcat(campo, v_srv_torre.arr);
          }
         if(v_srv_piso.len>0)
          {
           AddNullVarchar(v_srv_piso);
           strcat(campo, " ");
           strcat(campo, v_srv_piso.arr);
          }
         if(v_srv_depto.len>0)
          {
           AddNullVarchar(v_srv_depto);
           strcat(campo, " ");
           strcat(campo, v_srv_depto.arr);
          }
         if(v_srv_c_postal>0)
          {
           bzero(campo1, sizeof(campo1));
           sprintf(campo1, " %04d ", v_srv_c_postal);
           strcat(campo, campo1);
           /* EXEC SQL SELECT AGF_NOMBRE
             INTO :v_srv_agf_nombre:s_srv_agf_nombre
             FROM AREAS_GEOGRAFICAS
             WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo; */ 

{
           struct sqlexd sqlstm;
           sqlorat((void **)0, &sqlctx, &oraca);
           sqlstm.sqlvsn = 12;
           sqlstm.arrsiz = 33;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "select AGF_NOMBRE into :b0:b1  from AREAS_GEOGRAFI\
CAS where AREAS_GEOGRAFICAS.AGF_CODIGO=:b2";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )1374;
           sqlstm.selerr = (unsigned short)0;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (unsigned char  *)&v_srv_agf_nombre;
           sqlstm.sqhstl[0] = (unsigned long )33;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)&s_srv_agf_nombre;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned long )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (unsigned char  *)&v_agf_codigo;
           sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         short *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned long )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


           if(s_srv_agf_nombre!=-1)
            {
             AddNullVarchar(v_srv_agf_nombre);
             strcat(campo, v_srv_agf_nombre.arr);
            }
          }
       }
     /*  Antes: solo retornar svr_direccion ---- */
     /*   Varchar2Str(v_srv_direccion,campo);    */
	/* Fin de composicion del domicilio */
   }else if((strcmp(v_columna,"SRV_CALLE")==0)){
       Varchar2Str(v_srv_calle,campo);
   }else if((strcmp(v_columna,"SRV_NRO")==0)){
      if(v_srv_nro>0){sprintf(campo,"%ld",v_srv_nro);}
   }else if((strcmp(v_columna,"SRV_PISO")==0)){
       Varchar2Str(v_srv_piso,campo);
   }else if((strcmp(v_columna,"SRV_DEPTO")==0)){
       Varchar2Str(v_srv_depto,campo);
   }else if((strcmp(v_columna,"SRV_C_POSTAL")==0)){
       if(v_srv_c_postal>0){sprintf(campo,"%d",v_srv_c_postal);}
   }else if((strcmp(v_columna,"AGF_CODIGO")==0)){
       if(v_agf_codigo>0){sprintf(campo,"%ld",v_agf_codigo);}
   }else if((strcmp(v_columna,"SRV_FECHA_INSTAL")==0)){
       Varchar2Str(v_srv_fecha_instal,campo);
   }else if((strcmp(v_columna,"SRV_FECHA_BAJA")==0)){
       Varchar2Str(v_srv_fecha_baja,campo);
   }else if((strcmp(v_columna,"SRV_MOTIVO_BAJA")==0)){
       Varchar2Str(v_srv_motivo_baja,campo);
   }else if((strcmp(v_columna,"SRV_PLAN_ORIGINAL")==0)){
       if(v_srv_plan_original>0){sprintf(campo,"%d",v_srv_plan_original);}
   }else if((strcmp(v_columna,"SRV_ZONA_ORIGINAL")==0)){
       if(v_srv_zona_original>0){sprintf(campo,"%d",v_srv_zona_original);}
   }else if((strcmp(v_columna,"SRV_LOCALIDAD_ORIGINAL")==0)){
       if(v_srv_localidad_original>0){sprintf(campo,"%d",v_srv_localidad_original);}
   }else if((strcmp(v_columna,"SRV_RUTA_ORIGINAL")==0)){
       if(v_srv_ruta_original>0){sprintf(campo,"%d",v_srv_ruta_original);}
   }else if((strcmp(v_columna,"SRV_SUMINISTRO_ORIGINAL")==0)){
       if(v_srv_suministro_original>0){sprintf(campo,"%d",v_srv_suministro_original);}
   }else if((strcmp(v_columna,"SRV_PROMEDIO_VERANO")==0)){
       if(v_srv_promedio_verano>0){sprintf(campo,"%ld",v_srv_promedio_verano);}
   }else if((strcmp(v_columna,"SRV_PROMEDIO_INVIERNO")==0)){
       if(v_srv_promedio_invierno>0){sprintf(campo,"%ld",v_srv_promedio_invierno);}
   }else if((strcmp(v_columna,"SRV_PROMEDIO_ANUAL")==0)){
       if(v_srv_promedio_anual>0){sprintf(campo,"%ld",v_srv_promedio_anual);}
   }else if((strcmp(v_columna,"SRV_TIPO_SUMINISTRO")==0)){
       Varchar2Str(v_srv_tipo_suministro,campo);
   }else if((strcmp(v_columna,"EDI_NUMERO")==0)){
       if(v_edi_numero>0){sprintf(campo,"%ld",v_edi_numero);}
   }else if((strcmp(v_columna,"ERD_CODIGO")==0)){
       if(v_erd_codigo>0){sprintf(campo,"%ld",v_erd_codigo);}
   }else if((strcmp(v_columna,"SRV_DISTRITO_CAT")==0)){
       Varchar2Str(v_srv_distrito_cat,campo);
   }else if((strcmp(v_columna,"SRV_ZONA_CAT")==0)){
       Varchar2Str(v_srv_zona_cat,campo);
   }else if((strcmp(v_columna,"SRV_MANZANA_CAT")==0)){
       Varchar2Str(v_srv_manzana_cat,campo);
   }else if((strcmp(v_columna,"SRV_LOTE_CAT")==0)){
       Varchar2Str(v_srv_lote_cat,campo);
   }else if((strcmp(v_columna,"SRV_ESTADO")==0)){
       Varchar2Str(v_srv_estado,campo);
   }else if((strcmp(v_columna,"SRV_OBSERVACIONES")==0)){
       Varchar2Str(v_srv_observaciones,campo);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;

   /* Depurar (3, "Servicios(\"%s\", %ld) -> {%s}\n", v_columna, largos[0], campo); */
   return campo;
}

char *Lecturas(int largos[],char *v_columna,char *campo,long srv_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

     static long   v_srv_cod=-1;
     static double v_lct_valor_leido;
   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en LECTURAS por %s\n", v_columna); */
   if(v_srv_cod!=srv_cod){
      v_srv_cod=srv_cod;
      /* EXEC SQL SELECT LCT_VALOR_LEIDO
      INTO           :v_lct_valor_leido
      FROM LECTURAS
      WHERE LCT_CODIGO IN (SELECT max(LCT_CODIGO)
                           FROM LECTURAS
                           WHERE SRV_CODIGO=:srv_cod); */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select LCT_VALOR_LEIDO into :b0  from LECTURAS where LC\
T_CODIGO in (select max(LCT_CODIGO)  from LECTURAS where SRV_CODIGO=:b1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1397;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_lct_valor_leido;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }
   if((strcmp(v_columna,"LCT_VALOR_LEIDO"))==0){
      if(v_lct_valor_leido>0){sprintf(campo,"%.3lf",v_lct_valor_leido);}
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Ordenativos(int largos[],char *v_columna,char *campo,long nro_ord,long *srv_cod_ori,
                  long *cnt_num_ori,long *trt_num_ori, char *ord_fec)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static /* varchar v_ord_fecha_generacion[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_ord_fecha_generacion;

      static /* varchar v_ord_fecha_gen_habil_ant[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_ord_fecha_gen_habil_ant;

      static /* varchar v_ord_fecha_vencimiento[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_ord_fecha_vencimiento;

      short  s_fecha_vencimiento;
      static /* varchar v_ord_datos_adicionales[250]; */ 
struct { unsigned short len; unsigned char arr[250]; } v_ord_datos_adicionales;

      short  s_ord_datos_adicionales;
      static long    v_nro_ord=-1;
      static long    v_srv_codigo_origen;short s_srv_codigo_origen;
      static long    v_cnt_numero_origen;short s_cnt_numero_origen;
      static long    v_trt_numero_origen;short s_trt_numero_origen;
      static long    v_srv_codigo;
   /* EXEC SQL END DECLARE SECTION; */ 


   Depurar (1, "Busco en ORDENATIVOS por %s\n", v_columna);
   if(v_nro_ord!=nro_ord){
      v_nro_ord=nro_ord;
      /* EXEC SQL SELECT to_char(ORD_FECHA_GENERACION,'dd/mm/yyyy'),
                      to_char(fun_habil_anterior(1,ORD_FECHA_GENERACION),'dd/mm/yyyy'),
                      to_char(ORD_FECHA_VENCIMIENTO,'dd/mm/yyyy'),
                      SRV_CODIGO_ORIGEN,
                      CNT_NUMERO_ORIGEN,
                      TRT_NUMERO_ORIGEN,
                      ORD_DATOS_ADICIONALES,
                      SRV_CODIGO
      INTO           :v_ord_fecha_generacion,
                     :v_ord_fecha_gen_habil_ant,
                     :v_ord_fecha_vencimiento:s_fecha_vencimiento,
                     :v_srv_codigo_origen:s_srv_codigo_origen,
                     :v_cnt_numero_origen:s_cnt_numero_origen,
                     :v_trt_numero_origen:s_trt_numero_origen,
                     :v_ord_datos_adicionales:s_ord_datos_adicionales,
                     :v_srv_codigo
      FROM ORDENATIVOS
      WHERE ORD_NUMERO=:nro_ord; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select to_char(ORD_FECHA_GENERACION,'dd/mm/yyyy') ,to_c\
har(fun_habil_anterior(1,ORD_FECHA_GENERACION),'dd/mm/yyyy') ,to_char(ORD_FECH\
A_VENCIMIENTO,'dd/mm/yyyy') ,SRV_CODIGO_ORIGEN ,CNT_NUMERO_ORIGEN ,TRT_NUMERO_\
ORIGEN ,ORD_DATOS_ADICIONALES ,SRV_CODIGO into :b0,:b1,:b2:b3,:b4:b5,:b6:b7,:b\
8:b9,:b10:b11,:b12  from ORDENATIVOS where ORD_NUMERO=:b13";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1420;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_ord_fecha_generacion;
      sqlstm.sqhstl[0] = (unsigned long )12;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_ord_fecha_gen_habil_ant;
      sqlstm.sqhstl[1] = (unsigned long )12;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_ord_fecha_vencimiento;
      sqlstm.sqhstl[2] = (unsigned long )12;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)&s_fecha_vencimiento;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&v_srv_codigo_origen;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)&s_srv_codigo_origen;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&v_cnt_numero_origen;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)&s_cnt_numero_origen;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&v_trt_numero_origen;
      sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)&s_trt_numero_origen;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&v_ord_datos_adicionales;
      sqlstm.sqhstl[6] = (unsigned long )252;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&s_ord_datos_adicionales;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&v_srv_codigo;
      sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&nro_ord;
      sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      Varchar2Str(v_ord_fecha_generacion,ord_fec);
      AddNullVarchar(v_ord_fecha_gen_habil_ant);

      if(s_fecha_vencimiento==-1){
         v_ord_fecha_vencimiento.arr[0]=v_ord_fecha_vencimiento.len=0;
      }else{
         AddNullVarchar(v_ord_fecha_vencimiento);
      }

      if(s_srv_codigo_origen==-1){
         v_srv_codigo_origen=0;
      }else{
         *srv_cod_ori=v_srv_codigo_origen;
      }
      if(s_cnt_numero_origen==-1){
         v_cnt_numero_origen=0;
      }else{
         *cnt_num_ori=v_cnt_numero_origen;
      }
      if(s_trt_numero_origen==-1){
         v_trt_numero_origen=0;
      }else{
         *trt_num_ori=v_trt_numero_origen;
      }

      if(s_ord_datos_adicionales==-1){
         v_ord_datos_adicionales.arr[0]=v_ord_datos_adicionales.len=0;
      }else{
         AddNullVarchar(v_ord_datos_adicionales);
      }
   }
   if((strcmp(v_columna,"ORD_NUMERO"))==0){
      if(nro_ord>0){sprintf(campo,"%ld",nro_ord);}
   }else if((strcmp(v_columna,"ORD_FECHA_GENERACION"))==0){
      /* Varchar2Str(v_ord_fecha_generacion,campo); */
      /* Cambio de 11-04-2012. jinfante */
      strcpy(campo, v_ord_fecha_generacion.arr);
   }else if((strcmp(v_columna,"ORD_FECHA_GEN_HABIL_ANT"))==0){
      Varchar2Str(v_ord_fecha_gen_habil_ant,campo);
   }else if((strcmp(v_columna,"ORD_FECHA_VENCIMIENTO"))==0){
      Varchar2Str(v_ord_fecha_vencimiento,campo);
   }else if((strcmp(v_columna,"ORD_DATOS_ADICIONALES"))==0){
      fprintf (stderr, "Piden DATOS_ADICIONALES {%d}{%s}\n",
                        s_ord_datos_adicionales ,
                        v_ord_datos_adicionales.arr ) ;
      Varchar2Str(v_ord_datos_adicionales, campo);
   }else if((strcmp(v_columna,"SRV_CODIGO"))==0){
      if(v_srv_codigo>0){sprintf(campo,"%ld",v_srv_codigo);}
   }else { fprintf (stderr, "ORDENATIVOS: ERROR: parametro %s no soportado\n", v_columna) ; }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *TiposOrdenativo (int largos[],char *v_columna,char *campo,long srv_cod,int cnt_num)
{
  /* BF:
   * DF: Esta funcion obtiene la descripcion asociada al tipo de ordenativo
   *     que generalmente se imprime en el encabezado.
   *     No se hace consulta porque las columnas ya estan en el cursor
   *     principal.
   *
   * EF: */

   /* Depurar (1, "Busco en TIPOS_ORDENATIVO por %s\n", v_columna); */

   if((strcmp(v_columna,"TOR_DESCRIPCION"))==0){
      sprintf(campo,"%s",l_tor_descripcion.arr);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Potencias(int largos[],char *v_columna,char *campo,long srv_cod,int cnt_num)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long   v_srv_cod=-1;
      static double v_pot_valor;
   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en POTENCIAS por %s\n", v_columna); */
   if(v_srv_cod!=srv_cod){
      v_srv_cod=srv_cod;
      /* EXEC SQL SELECT POT_VALOR
      INTO           :v_pot_valor
      FROM POTENCIAS
      WHERE SRV_CODIGO=:srv_cod
      AND CNT_NUMERO=:cnt_num
      AND CDR_UNIDAD IN ('DA')
      AND POT_ORIGEN IN ('C')
      AND POT_FECHA IN (SELECT max(POT_FECHA)
                        FROM POTENCIAS
                        WHERE SRV_CODIGO=:srv_cod
                        AND CNT_NUMERO=:cnt_num
                        AND CDR_UNIDAD IN ('DA')
                        AND POT_ORIGEN IN ('C')); */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select POT_VALOR into :b0  from POTENCIAS where ((((SRV\
_CODIGO=:b1 and CNT_NUMERO=:b2) and CDR_UNIDAD in ('DA')) and POT_ORIGEN in ('\
C')) and POT_FECHA in (select max(POT_FECHA)  from POTENCIAS where (((SRV_CODI\
GO=:b1 and CNT_NUMERO=:b2) and CDR_UNIDAD in ('DA')) and POT_ORIGEN in ('C')))\
)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1471;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_pot_valor;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&cnt_num;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&cnt_num;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

   if((strcmp(v_columna,"POT_VALOR"))==0){
      sprintf(campo,"%.2lf",v_pot_valor);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Stock_Equipos(int largos[],char *v_columna,char *campo,long srv_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long   v_srv_cod=-1;
      static double v_ste_numero;
      static /* varchar v_ste_tipo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ste_tipo;

   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en STOCK_EQUIPOS por %s\n", v_columna); */
   /* Cambio del 6-6-2000: Para que no muestre ste_numero de la intimacion
                           anterior */
   v_ste_numero=v_ste_tipo.arr[0]=v_ste_tipo.len=0;
   if(v_srv_cod!=srv_cod){
      v_srv_cod=srv_cod;
      /* EXEC SQL SELECT S.STE_NUMERO,
                      S.STE_TIPO
      INTO           :v_ste_numero,
                     :v_ste_tipo
      FROM STOCK_EQUIPOS S,EQUIPOS E
      WHERE S.STE_NUMERO=E.STE_NUMERO
      AND   S.STE_TIPO=E.STE_TIPO
      AND   E.SRV_CODIGO=:srv_cod
      AND   E.EQP_ESTADO IS NULL; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select S.STE_NUMERO ,S.STE_TIPO into :b0,:b1  from STOC\
K_EQUIPOS S ,EQUIPOS E where (((S.STE_NUMERO=E.STE_NUMERO and S.STE_TIPO=E.STE\
_TIPO) and E.SRV_CODIGO=:b2) and E.EQP_ESTADO is null )";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1506;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_ste_numero;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_ste_tipo;
      sqlstm.sqhstl[1] = (unsigned long )5;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&srv_cod;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

   if((strcmp(v_columna,"STE_NUMERO"))==0){
      if(v_ste_numero>0){sprintf(campo,"%.0lf",v_ste_numero);}
   if((strcmp(v_columna,"STE_TIPO"))==0){
      strcpy(campo, v_ste_tipo.arr);}
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Sucursales(int largos[],char *v_columna,char *campo,long scf_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long    v_scf_cod=-1;
      static /* varchar v_scf_descripcion[41]; */ 
struct { unsigned short len; unsigned char arr[41]; } v_scf_descripcion;

      static /* varchar v_scf_direccion[41]; */ 
struct { unsigned short len; unsigned char arr[41]; } v_scf_direccion;

      short s_scf_direccion;
   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en SUCURSALES por %s\n", v_columna); */
   if(v_scf_cod!=scf_cod){
      v_scf_cod=scf_cod;
      /* EXEC SQL SELECT SCF_DESCRIPCION,
                      SCF_DIRECCION
      INTO           :v_scf_descripcion,
                     :v_scf_direccion:s_scf_direccion
      FROM SUCURSALES
      WHERE SCF_CODIGO=:scf_cod; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select SCF_DESCRIPCION ,SCF_DIRECCION into :b0,:b1:b2  \
from SUCURSALES where SCF_CODIGO=:b3";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1533;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_scf_descripcion;
      sqlstm.sqhstl[0] = (unsigned long )43;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_scf_direccion;
      sqlstm.sqhstl[1] = (unsigned long )43;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)&s_scf_direccion;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&scf_cod;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

   if(s_scf_direccion==-1) v_scf_direccion.arr[0]=v_scf_direccion.len=0;
   if((strcmp(v_columna,"SCF_DESCRIPCION"))==0){
      Varchar2Str(v_scf_descripcion,campo);
   }else if((strcmp(v_columna,"SCF_DIRECCION"))==0){
      Varchar2Str(v_scf_direccion,campo);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}
/*-----------------------------------------------------------------*/
char *Bancos(int largos[],char *v_columna,char *campo, long agf_cod)
{
  /* BF:
   * DF:
   * EF: */

 int i;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static long    v_agf_cod=-1;
    static /* varchar ha_urc_descripcion[20][41]; */ 
struct { unsigned short len; unsigned char arr[42]; } ha_urc_descripcion[20];
short s_urc_descripcion[50];
  /* EXEC SQL END DECLARE SECTION; */ 


  if(v_agf_cod!=agf_cod){
      v_agf_cod=agf_cod;

  	  for(i=0; i<19; i++)
	   {
    	ClearVarchar(ha_urc_descripcion[i]);
	   }
	  /* EXEC SQL DECLARE CURC CURSOR FOR
	       SELECT U.URC_DESCRIPCION_ALT
	              FROM UNIDADES_REC_COBRO C,
	                   UNIDADES_RECAUDADORAS U
	              WHERE C.AGF_CODIGO = :v_agf_cod
	                AND C.UCO_TIPO = 'A'
	                AND U.URC_CODIGO = C.URC_CODIGO; */ 

	  /* EXEC SQL OPEN CURC; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0042;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1560;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_agf_cod;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


	  /* EXEC SQL FETCH CURC INTO
	           :ha_urc_descripcion:s_urc_descripcion; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )20;
   sqlstm.offset = (unsigned int  )1579;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)ha_urc_descripcion;
   sqlstm.sqhstl[0] = (unsigned long )43;
   sqlstm.sqhsts[0] = (         int  )44;
   sqlstm.sqindv[0] = (         short *)s_urc_descripcion;
   sqlstm.sqinds[0] = (         int  )sizeof(short);
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqharc[0] = (unsigned long  *)0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


	  /* EXEC SQL CLOSE CURC; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1598;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      for(i=0; i<19; i++)
	   {
	    AddNullVarchar(ha_urc_descripcion[i]);
	   }
   }
  for(i=0; i<19; i++)
    if((s_urc_descripcion[i]==-1)||(ha_urc_descripcion[i].len==0))
      i=i;
    else
     {
      if(strlen(campo)!=0)
        strcat(campo, " - ");
      strcat(campo,ha_urc_descripcion[i].arr);
     }

}

/*-----------------------------------------------------------------*/
char *Cargos(int largos[],char *v_columna,char *campo, char *ord_fec)
{
  /* BF:
   * DF:
   * EF: */

   int i;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static /* varchar v_ord_fec[11] = {0,""}; */ 
struct { unsigned short len; unsigned char arr[11]; } v_ord_fec
 = {0,""};

	  static /* varchar v_descripcion[3][61]; */ 
struct { unsigned short len; unsigned char arr[62]; } v_descripcion[3];

	  /* varchar v_tit_clave[3][4]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_tit_clave[3];

	  /* varchar v_txt[3][27]; */ 
struct { unsigned short len; unsigned char arr[30]; } v_txt[3];

      short s_scf_direccion;
   /* EXEC SQL END DECLARE SECTION; */ 


   strcpy(v_tit_clave[0].arr,"ND1");
   strcpy(v_tit_clave[1].arr,"ND2");
   strcpy(v_tit_clave[2].arr,"TR1");
   v_tit_clave[0].len=v_tit_clave[1].len=v_tit_clave[2].len=3;

   strcpy(v_txt[0].arr,"aviso de deuda             ");
   strcpy(v_txt[1].arr,"carta documento o telegrama");
   strcpy(v_txt[2].arr,"reconexión                 ");
   v_txt[0].len=27;
   v_txt[1].len=27;
   v_txt[2].len=27;
   if(strcmp(v_ord_fec.arr,ord_fec)){
      Str2Varchar(ord_fec,v_ord_fec);
	  for(i=0; i<3; i++)
   	  {
      	/* EXEC SQL SELECT 'Cargo por '||:v_txt[i]||': $'||TO_CHAR(PPR_PRECIO,'9990.00')||' más IVA'
	    INTO   :v_descripcion[i]
	    FROM PRECIOS_PRESTACION
	    WHERE TIT_CLAVE = :v_tit_clave[i]
	    AND PPR_FECHA_VIGENCIA = (SELECT MAX(PPR_FECHA_VIGENCIA)
	    FROM PRECIOS_PRESTACION WHERE TIT_CLAVE = :v_tit_clave[i] AND PPR_FECHA_VIGENCIA <= TO_DATE(:v_ord_fec,'DD/MM/YYYY')); */ 

{
       struct sqlexd sqlstm;
       sqlorat((void **)0, &sqlctx, &oraca);
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 33;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "select (((('Cargo por '||:b0)||': $')||TO_CHAR(PPR_PRE\
CIO,'9990.00'))||' más IVA') into :b1  from PRECIOS_PRESTACION where (TIT_CLAV\
E=:b2 and PPR_FECHA_VIGENCIA=(select max(PPR_FECHA_VIGENCIA)  from PRECIOS_PRE\
STACION where (TIT_CLAVE=:b2 and PPR_FECHA_VIGENCIA<=TO_DATE(:b4,'DD/MM/YYYY')\
)))";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )1613;
       sqlstm.selerr = (unsigned short)0;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&v_txt[i];
       sqlstm.sqhstl[0] = (unsigned long )29;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&v_descripcion[i];
       sqlstm.sqhstl[1] = (unsigned long )63;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&v_tit_clave[i];
       sqlstm.sqhstl[2] = (unsigned long )6;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&v_tit_clave[i];
       sqlstm.sqhstl[3] = (unsigned long )6;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&v_ord_fec;
       sqlstm.sqhstl[4] = (unsigned long )13;
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


		AddNullVarchar(v_descripcion[i]);
	  }
   }

   if((strcmp(v_columna,"CARGO_AVISO"))==0){
      Varchar2Str(v_descripcion[0],campo);
   }else if((strcmp(v_columna,"CARGO_TELEGRAMA"))==0){
      Varchar2Str(v_descripcion[1],campo);
   }else if((strcmp(v_columna,"CARGO_RECONEXION"))==0){
      Varchar2Str(v_descripcion[2],campo);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}


char *Tipos_IVA(int largos[],char *v_columna,char *campo,int ivv_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static int     v_ivv_cod=-1;
      static /* varchar v_ivv_descripcion[61]; */ 
struct { unsigned short len; unsigned char arr[61]; } v_ivv_descripcion;

   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en TIPOS_IVA por %s\n", v_columna); */
   if(v_ivv_cod!=ivv_cod){
      v_ivv_cod=ivv_cod;
      /* EXEC SQL SELECT IVV_DESCRIPCION
      INTO           :v_ivv_descripcion
      FROM TIPOS_IVA
      WHERE IVV_CODIGO=:ivv_cod; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select IVV_DESCRIPCION into :b0  from TIPOS_IVA where I\
VV_CODIGO=:b1";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1648;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_ivv_descripcion;
      sqlstm.sqhstl[0] = (unsigned long )63;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&ivv_cod;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

   if((strcmp(v_columna,"TCL_DESCRIPCION"))==0){
       Varchar2Str(v_ivv_descripcion,campo);
   }
   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Tarifas(int largos[],char *v_columna,char *campo,char *tcl_cod)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static char    v_tcl_codb[5];
      static /* varchar v_tcl_cod[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_tcl_cod;

      static /* varchar v_tcl_descripcion[41]; */ 
struct { unsigned short len; unsigned char arr[41]; } v_tcl_descripcion;

   /* EXEC SQL END DECLARE SECTION; */ 


   /* Depurar (1, "Busco en TARIFAS por %s\n", v_columna); */
   Str2Varchar(tcl_cod,v_tcl_cod);
   if(strcmp(v_tcl_codb,tcl_cod)!=0){
      strcpy(v_tcl_codb,tcl_cod);
      /* EXEC SQL SELECT TCL_DESCRIPCION
      INTO           :v_tcl_descripcion
      FROM TARIFAS
      WHERE TCL_CODIGO=:v_tcl_cod; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select TCL_DESCRIPCION into :b0  from TARIFAS where TCL\
_CODIGO=:b1";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1671;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_tcl_descripcion;
      sqlstm.sqhstl[0] = (unsigned long )43;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_tcl_cod;
      sqlstm.sqhstl[1] = (unsigned long )7;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

/* Corregimos TCL_DESCRIPICION x TCL_DESCRIPCION (lsantos 24-2-2003) */

   if((strcmp(v_columna,"TCL_DESCRIPCION"))==0){
      Varchar2Str(v_tcl_descripcion,campo);
   }
   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

char *Documentos(int largos[],char *columnas,char *campo,long srv_cod,
                 int cnt_num,
                 long trt_num,int i,int ancho, long p_nro_ord)

{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      double  hv_doc_numero;
      /* varchar hv_doc_tipo[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_doc_tipo;

      /* varchar hv_doc_fecha_emision[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_doc_fecha_emision;

      int     hv_doc_periodo;short s_doc_periodo;
      int     hv_doc_anio;short s_doc_anio;
      int     hv_doc_cuota;short s_doc_cuota;
      /* varchar hv_doc_tipo_origen[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_doc_tipo_origen;

      short s_doc_tipo_origen;
      double  hv_doc_numero_origen;short s_doc_numero_origen;
      long    hv_doc_consumo;short s_doc_consumo;
      double  hv_doc_potencia;short s_doc_potencia;
      long    hv_tab_numero;short s_tab_numero;
      long    hv_ord_numero;short s_ord_numero;
      long    hv_urc_codigo;short s_urc_codigo;
      long    hv_asi_numero;short s_asi_numero;
      double  hv_doc_importe;
      double  hv_doc_importe_basico;short s_doc_importe_basico;
      double  hv_doc_saldo;
      /* varchar hv_doc_fecha_venc[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_doc_fecha_venc;

      short s_doc_fecha_venc;
      /* varchar hv_doc_fecha_venc_1[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_doc_fecha_venc_1;

      short s_doc_fecha_venc_1;
      /* varchar hv_doc_fecha_venc_2[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_doc_fecha_venc_2;

      short s_doc_fecha_venc_2;
      double  hv_doc_recargo_venc_2;short s_doc_recargo_venc_2;
      /* varchar hv_doc_fecha_venc_3[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_doc_fecha_venc_3;

      short s_doc_fecha_venc_3;
      double  hv_doc_recargo_venc_3;short s_doc_recargo_venc_3;
      /* varchar hv_doc_estado[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_doc_estado;

      /* fab 21.10.2009 req.2927 */
      /* varchar hv_llamada_sit_x[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_llamada_sit_x;

   /* EXEC SQL END DECLARE SECTION; */ 

   int r,aux;
   int f,sumar=0;
   char campoaux[1024];

   /* Depurar (1, "Busco en DOCUMENTOS\n");
    * Depurar (2, "Busco todos los documentos cuyo tramite sea %d\n", trt_num);
    * Depurar (3, "i=%d ancho=%d\n", i, ancho);
    * Depurar (3, "campo=%s\n", campo);
    */

   /*
      Cambio del 10-9-2003, para que se acceda a la nueva vista
      documentos_estadistica_view, donde esta la relacion ordenativos/docs
      a partir de ahora, no se accede a los documentos via el numero de
      tramite


      KALAVE - 20/10/2003 a pedido de C.Zero / Leticia Santos porque las notificaciones D2
                          no se generan por no tener documentos_estadistica_extra */

   /* EXEC SQL DECLARE DOC_D2 CURSOR FOR
      SELECT DOC_NUMERO,
             DOC_TIPO,
             to_char(DOC_FECHA_EMISION,'dd/mm/yyyy'),
             DOC_PERIODO,
             DOC_ANIO,
             DOC_CUOTA,
             DOC_TIPO_ORIGEN,
             DOC_NUMERO_ORIGEN,
             DOC_CONSUMO,
             -- TAB_NUMERO,
             ORD_NUMERO,
             URC_CODIGO,
             ASI_NUMERO,
             DOC_IMPORTE,
             DOC_IMPORTE_BASICO,
             -- A pedido de leticia: si existe el saldo, debe aparecer
             -- donde aparecia el importe total.  (d.molina - 25/ago/99)
             -- DOC_SALDO,
             nvl(DOC_SALDO, DOC_IMPORTE),
             to_char(DOC_FECHA_VENC,'dd/mm/yy'),
             to_char(DOC_FECHA_VENC_1,'dd/mm/yyyy'),
             to_char(DOC_FECHA_VENC_2,'dd/mm/yyyy'),
             DOC_RECARGO_VENC_2,
             to_char(DOC_FECHA_VENC_3,'dd/mm/yyyy'),
             DOC_RECARGO_VENC_3,
             DOC_ESTADO,
             /o fab 21.10.2009 req.2927 o/
             decode(doc_situacion, 
                'X', '(*)', 
                'C1', '(*)', 
                'C2', '(*)', 
                'C3', '(*)', 
                '   ') LLAMADA_SIT_X
      FROM DOCUMENTOS
      WHERE TRT_NUMERO=:trt_num
        AND nvl(nvl(DOC_SALDO, DOC_IMPORTE),0) > 0
		AND doc_situacion <> 'X'
     ORDER BY DOC_FECHA_VENC_1; */ 



   /* EXEC SQL DECLARE DOC CURSOR FOR
   SELECT d.DOC_NUMERO,
       d.DOC_TIPO,
       to_char(d.DOC_FECHA_EMISION,'dd/mm/yyyy'),
       d.DOC_PERIODO,
       d.DOC_ANIO,
       d.DOC_CUOTA,
       d.DOC_TIPO_ORIGEN,
       d.DOC_NUMERO_ORIGEN,
       d.DOC_CONSUMO,
       -- TAB_NUMERO,
       d.ORD_NUMERO,
       d.URC_CODIGO,
       d.ASI_NUMERO,
       d.DOC_IMPORTE,
       d.DOC_IMPORTE_BASICO,
       -- A pedido de leticia: si existe el saldo, debe aparecer
       -- donde aparecia el importe total.  (d.molina - 25/ago/99)
       -- DOC_SALDO,
       nvl(d.DOC_SALDO, d.DOC_IMPORTE),
       to_char(d.DOC_FECHA_VENC,'dd/mm/yy'),
       to_char(d.DOC_FECHA_VENC_1,'dd/mm/yyyy'),
       to_char(d.DOC_FECHA_VENC_2,'dd/mm/yyyy'),
       d.DOC_RECARGO_VENC_2,
       to_char(d.DOC_FECHA_VENC_3,'dd/mm/yyyy'),
	   d.DOC_RECARGO_VENC_3,
       d.DOC_ESTADO,
       /o fab 21.10.2009 req.2927 o/
       decode(d.doc_situacion, 'X', '(*)', '   ') LLAMADA_SIT_X
   from documentos d, documentos_estadistica_view de
   where nvl(nvl(d.DOC_SALDO, d.DOC_IMPORTE),0) > 0 and
   d.doc_tipo = de.doc_tipo and
   d.doc_numero = de.doc_numero and
   de.ord_numero = :p_nro_ord and
   d.doc_situacion <> 'X'
   ORDER BY DOC_FECHA_VENC_1; */ 




   if(!strcmp(Tor_codigo, "D2"))
     /* EXEC SQL OPEN DOC_D2; */ 

{
     struct sqlexd sqlstm;
     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 33;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0046;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1694;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&trt_num;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   else
     /* EXEC SQL OPEN DOC; */ 

{
     struct sqlexd sqlstm;
     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 33;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0047;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1713;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&p_nro_ord;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



/*
FAB 6/4/09 - Req. 2823
inicio la variable global t_doc_saldo
*/
   t_doc_saldo=0.0;

   aux=0;
   do{
      r=aux;


      if(!strcmp(Tor_codigo, "D2"))
        /* EXEC SQL FETCH DOC_D2 INTO
           :hv_doc_numero,
           :hv_doc_tipo,
           :hv_doc_fecha_emision,
           :hv_doc_periodo:s_doc_periodo,
           :hv_doc_anio:s_doc_anio,
           :hv_doc_cuota:s_doc_cuota,
           :hv_doc_tipo_origen:s_doc_tipo_origen,
           :hv_doc_numero_origen:s_doc_numero_origen,
           :hv_doc_consumo:s_doc_consumo,
           -- :hv_tab_numero:s_tab_numero,
           :hv_ord_numero:s_ord_numero,
           :hv_urc_codigo:s_urc_codigo,
           :hv_asi_numero:s_asi_numero,
           :hv_doc_importe,
           :hv_doc_importe_basico:s_doc_importe_basico,
           :hv_doc_saldo,
           :hv_doc_fecha_venc:s_doc_fecha_venc,
           :hv_doc_fecha_venc_1:s_doc_fecha_venc_1,
           :hv_doc_fecha_venc_2:s_doc_fecha_venc_2,
           :hv_doc_recargo_venc_2:s_doc_recargo_venc_2,
           :hv_doc_fecha_venc_3:s_doc_fecha_venc_3,
           :hv_doc_recargo_venc_3:s_doc_recargo_venc_3,
           :hv_doc_estado,
           /o fab 21.10.2009 req.2927 o/
           :hv_llamada_sit_x; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 33;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1732;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_doc_numero;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_doc_tipo;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_doc_fecha_emision;
        sqlstm.sqhstl[2] = (unsigned long )14;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_doc_periodo;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&s_doc_periodo;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_doc_anio;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&s_doc_anio;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_doc_cuota;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&s_doc_cuota;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_doc_tipo_origen;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&s_doc_tipo_origen;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_doc_numero_origen;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&s_doc_numero_origen;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_doc_consumo;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&s_doc_consumo;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_ord_numero;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&s_ord_numero;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_urc_codigo;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&s_urc_codigo;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_asi_numero;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&s_asi_numero;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_doc_importe;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_doc_importe_basico;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&s_doc_importe_basico;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_doc_saldo;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_doc_fecha_venc;
        sqlstm.sqhstl[15] = (unsigned long )14;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&s_doc_fecha_venc;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_doc_fecha_venc_1;
        sqlstm.sqhstl[16] = (unsigned long )14;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&s_doc_fecha_venc_1;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_doc_fecha_venc_2;
        sqlstm.sqhstl[17] = (unsigned long )14;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&s_doc_fecha_venc_2;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_doc_recargo_venc_2;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&s_doc_recargo_venc_2;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_doc_fecha_venc_3;
        sqlstm.sqhstl[19] = (unsigned long )14;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&s_doc_fecha_venc_3;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_doc_recargo_venc_3;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&s_doc_recargo_venc_3;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_doc_estado;
        sqlstm.sqhstl[21] = (unsigned long )7;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_llamada_sit_x;
        sqlstm.sqhstl[22] = (unsigned long )6;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


      else
        /* EXEC SQL FETCH DOC INTO
           :hv_doc_numero,
           :hv_doc_tipo,
           :hv_doc_fecha_emision,
           :hv_doc_periodo:s_doc_periodo,
           :hv_doc_anio:s_doc_anio,
           :hv_doc_cuota:s_doc_cuota,
           :hv_doc_tipo_origen:s_doc_tipo_origen,
           :hv_doc_numero_origen:s_doc_numero_origen,
           :hv_doc_consumo:s_doc_consumo,
           -- :hv_tab_numero:s_tab_numero,
           :hv_ord_numero:s_ord_numero,
           :hv_urc_codigo:s_urc_codigo,
           :hv_asi_numero:s_asi_numero,
           :hv_doc_importe,
           :hv_doc_importe_basico:s_doc_importe_basico,
           :hv_doc_saldo,
           :hv_doc_fecha_venc:s_doc_fecha_venc,
           :hv_doc_fecha_venc_1:s_doc_fecha_venc_1,
           :hv_doc_fecha_venc_2:s_doc_fecha_venc_2,
           :hv_doc_recargo_venc_2:s_doc_recargo_venc_2,
           :hv_doc_fecha_venc_3:s_doc_fecha_venc_3,
           :hv_doc_recargo_venc_3:s_doc_recargo_venc_3,
           :hv_doc_estado,
           /o fab 21.10.2009 req.2927 o/
           :hv_llamada_sit_x; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 33;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1839;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_doc_numero;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_doc_tipo;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_doc_fecha_emision;
        sqlstm.sqhstl[2] = (unsigned long )14;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_doc_periodo;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&s_doc_periodo;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_doc_anio;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&s_doc_anio;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_doc_cuota;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&s_doc_cuota;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_doc_tipo_origen;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&s_doc_tipo_origen;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_doc_numero_origen;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&s_doc_numero_origen;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_doc_consumo;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&s_doc_consumo;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_ord_numero;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&s_ord_numero;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_urc_codigo;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&s_urc_codigo;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_asi_numero;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&s_asi_numero;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_doc_importe;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_doc_importe_basico;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&s_doc_importe_basico;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_doc_saldo;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_doc_fecha_venc;
        sqlstm.sqhstl[15] = (unsigned long )14;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&s_doc_fecha_venc;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_doc_fecha_venc_1;
        sqlstm.sqhstl[16] = (unsigned long )14;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&s_doc_fecha_venc_1;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_doc_fecha_venc_2;
        sqlstm.sqhstl[17] = (unsigned long )14;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&s_doc_fecha_venc_2;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_doc_recargo_venc_2;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&s_doc_recargo_venc_2;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_doc_fecha_venc_3;
        sqlstm.sqhstl[19] = (unsigned long )14;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&s_doc_fecha_venc_3;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_doc_recargo_venc_3;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&s_doc_recargo_venc_3;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_doc_estado;
        sqlstm.sqhstl[21] = (unsigned long )7;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_llamada_sit_x;
        sqlstm.sqhstl[22] = (unsigned long )6;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



      /*
      FAB 6/4/09 - Req. 2823
      sumo el saldo de los documentos en la variable global t_doc_saldo
      */
      t_doc_saldo += hv_doc_saldo;

      aux=COUNTHITS;
      if(aux!=r){
         AddNullVarchar(hv_doc_tipo);
         AddNullVarchar(hv_doc_fecha_emision);
         if(s_doc_periodo==-1) hv_doc_periodo=0;
         if(s_doc_anio==-1) hv_doc_anio=0;
         if(s_doc_cuota==-1) hv_doc_cuota=0;
         if(s_doc_tipo_origen==-1)
            hv_doc_tipo_origen.arr[0]=hv_doc_tipo_origen.len=0;
         else AddNullVarchar(hv_doc_tipo_origen);
         if(s_doc_numero_origen==-1) hv_doc_numero_origen=0;
         if(s_doc_consumo==-1) hv_doc_consumo=0;
         if(s_doc_potencia==-1) hv_doc_potencia=0;
         /* if(s_tab_numero==-1) hv_tab_numero=0; */
         hv_tab_numero=0;
         if(s_ord_numero==-1) hv_ord_numero=0;
         if(s_urc_codigo==-1) hv_urc_codigo=0;
         if(s_asi_numero==-1) hv_asi_numero=0;
         if(s_doc_importe_basico==-1) hv_doc_importe_basico=0;
         if(s_doc_fecha_venc==-1)
            hv_doc_fecha_venc.arr[0]=hv_doc_fecha_venc.len=0;
         if(s_doc_fecha_venc_1==-1)
            hv_doc_fecha_venc_1.arr[0]=hv_doc_fecha_venc.len=0;
         if(s_doc_fecha_venc_2==-1)
            hv_doc_fecha_venc_2.arr[0]=hv_doc_fecha_venc.len=0;
         if(s_doc_recargo_venc_2==-1) hv_doc_recargo_venc_2=0;
         if(s_doc_fecha_venc_3==-1)
            hv_doc_fecha_venc_3.arr[0]=hv_doc_fecha_venc.len=0;
         if(s_doc_recargo_venc_3==-1) hv_doc_recargo_venc_3=0;
         AddNullVarchar(hv_doc_estado);
         /* fab 21.10.2009 req.2927 */
         AddNullVarchar(hv_llamada_sit_x);
      }

      f=0;
      campoaux[0]=0;
      while(f<i && aux!=r){
         /* Es asi: *(columnas+(f*ancho)+c) */
         /* Depurar (3, "[%s]\n", *(columnas+(f*ancho))); */
         if((strcmp((columnas+(f*ancho)),"SRV_CODIGO"))==0){
            if(srv_cod>0){sprintf(campoaux,"%ld",srv_cod);}
         }else if((strcmp((columnas+(f*ancho)),"CNT_NUMERO"))==0){
            if(cnt_num>0){sprintf(campoaux,"%d",cnt_num);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_TIPO"))==0){
            sprintf(campoaux,"%-5s",hv_doc_tipo.arr);
            if(!strcmp(hv_doc_tipo.arr, "FN")||
               !strcmp(hv_doc_tipo.arr, "DN"))
              Tiene_Comprobantes_Financiaciones++;
            else
              Tiene_Otros_Comprobantes++;
         }else if((strcmp((columnas+(f*ancho)),"DOC_NUMERO"))==0){
            if(hv_doc_numero>0){sprintf(campoaux,"%.0lf",hv_doc_numero);
                                                   CantidadDeFacturas++;
                                                                  }
         }else if((strcmp((columnas+(f*ancho)),"DOC_FECHA_EMISION"))==0){
            Varchar2Str(hv_doc_fecha_emision,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_PERIODO"))==0){
            if(hv_doc_periodo>0){sprintf(campoaux,"%02d/%04d",hv_doc_periodo,
                                                              hv_doc_anio);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_ANIO"))==0){
            if(hv_doc_anio>0){sprintf(campoaux,"%d",hv_doc_anio);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_CUOTA"))==0){
            if(hv_doc_cuota>0){sprintf(campoaux,"%d",hv_doc_cuota);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_TIPO_ORIGEN"))==0){
            Varchar2Str(hv_doc_tipo_origen,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_NUMERO_ORIGEN"))==0){
            if(hv_doc_numero_origen>0){sprintf(campoaux,"%-12.0lf",hv_doc_numero_origen);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_CONSUMO"))==0){
            if(hv_doc_consumo>0){sprintf(campoaux,"%ld",hv_doc_consumo);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_POTENCIA"))==0){
            sprintf(campoaux,"%.0lf",hv_doc_potencia);
         }else if((strcmp((columnas+(f*ancho)),"TAB_NUMERO"))==0){
            if(hv_tab_numero>0){sprintf(campoaux,"%ld",hv_tab_numero);}
         }else if((strcmp((columnas+(f*ancho)),"ORD_NUMERO"))==0){
            if(hv_ord_numero>0){sprintf(campoaux,"%ld",hv_ord_numero);}
         }else if((strcmp((columnas+(f*ancho)),"URC_CODIGO"))==0){
            sprintf(campoaux,"%ld",hv_urc_codigo);
         }else if((strcmp((columnas+(f*ancho)),"ASI_NUMERO"))==0){
            if(hv_asi_numero>0){sprintf(campoaux,"%ld",hv_asi_numero);}
         }else if((strcmp((columnas+(f*ancho)),"DOC_IMPORTE"))==0){
            sprintf(campoaux,"%12.2lf",hv_doc_importe);
            ImporteDelAviso+=hv_doc_importe_basico;
/*            CantidadDeFacturas++;  pasada esta sentencia al if del doc_numero aca no funca por parametriz  */
         }else if((strcmp((columnas+(f*ancho)),"DOC_IMPORTE_BASICO"))==0)
          {
           sprintf(campoaux,"%12.2lf",hv_doc_importe_basico);
          }
          else if((strcmp((columnas+(f*ancho)),"DOC_SALDO"))==0){
            sprintf(campoaux,"%12.2lf",hv_doc_saldo);
         }else if((strcmp((columnas+(f*ancho)),"DOC_FECHA_VENC"))==0){
            Varchar2Str(hv_doc_fecha_venc,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_FECHA_VENC_1"))==0){
            Varchar2Str(hv_doc_fecha_venc_1,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_FECHA_VENC_2"))==0){
            Varchar2Str(hv_doc_fecha_venc_2,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_RECARGO_VENC_2"))==0){
            sprintf(campoaux,"%.2lf",hv_doc_recargo_venc_2);
         }else if((strcmp((columnas+(f*ancho)),"DOC_FECHA_VENC_3"))==0){
            Varchar2Str(hv_doc_fecha_venc_3,campoaux);
         }else if((strcmp((columnas+(f*ancho)),"DOC_RECARGO_VENC_3"))==0){
            sprintf(campoaux,"%.2lf",hv_doc_recargo_venc_3);
         }else if((strcmp((columnas+(f*ancho)),"DOC_ESTADO"))==0){
            Varchar2Str(hv_doc_estado,campoaux);
         /* fab 21.10.2009 req.2927 */
         }else if((strcmp((columnas+(f*ancho)),"LLAMADA_SIT_X"))==0){
            Varchar2Str(hv_llamada_sit_x,campoaux);
         }
         
         for(;strlen(campoaux)<largos[f];)
           strcat(campoaux," ");
         campoaux[largos[f]]=0;
         strcat(campo,campoaux);
         f++;
         campoaux[0]=0;
      }
      if(f>0) sumar++;
      strcat(campo,"\n");
   /* }while(aux!=r && sumar<9); */
   /*
      Cambio del 21-1-2003 (czero/jinfante)
      Para que imprima 18 lineas en lugar de 8/9
   */
   }while(aux!=r && sumar<19);

   if(!strcmp(Tor_codigo, "D2"))
     /* EXEC SQL CLOSE DOC_D2; */ 

{
     struct sqlexd sqlstm;
     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 33;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1946;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   else
     /* EXEC SQL CLOSE DOC; */ 

{
     struct sqlexd sqlstm;
     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 33;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1961;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   if(sumar<19){
      while(sumar<=19){
         strcat(campo,"\n");
         sumar++;
      }
   }else{
      strcat(campo,"...\n");
   }
   /* Depurar (3, "documentos(): Campo=%s\n", campo); */
   return campo;
}

char *Totales_Tramite(int largos[],char *v_columna,char *campo,long trt_num)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static long   v_trt_num=-1;
      static double v_cant_doc;
      static double v_suma_doc;
      static double v_suma_dec;
   /* EXEC SQL END DECLARE SECTION; */ 


   if(v_trt_num!=trt_num){
      v_trt_num=trt_num;
      /* EXEC SQL SELECT TTR_CANT_DOC,
                      TTR_SUMA_DOC,
                      TTR_SUMA_DEC
      INTO           :v_cant_doc,
                     :v_suma_doc,
                     :v_suma_dec
      FROM TOTALES_TRAMITE
      WHERE TRT_NUMERO=:trt_num; */ 

{
      struct sqlexd sqlstm;
      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 33;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select TTR_CANT_DOC ,TTR_SUMA_DOC ,TTR_SUMA_DEC into :b\
0,:b1,:b2  from TOTALES_TRAMITE where TRT_NUMERO=:b3";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1976;
      sqlstm.selerr = (unsigned short)0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_cant_doc;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_suma_doc;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&v_suma_dec;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&trt_num;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}


   }

   if((strcmp(v_columna,"TTR_CANT_DOC"))==0){
      sprintf(campo,"%.0lf",v_cant_doc);
   }else if((strcmp(v_columna,"TTR_SUMA_DOC"))==0){
      sprintf(campo,"%.2lf",v_suma_doc);
   }else if((strcmp(v_columna,"TTR_SUMA_DEC"))==0){
      if(v_suma_dec!=0) {
		sprintf(campo,"Deuda Cargo Decreto Nº. 2067/08: %.2lf (*)\n", v_suma_dec);
		largos[0]=strlen(campo);
	  } else {
		sprintf(campo,"\n");
		largos[0]=strlen(campo);	  
	  }
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}


char *Usuarios(int largos[],char *v_columna,char *campo)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      static /* varchar v_scf_descripcion[41]; */ 
struct { unsigned short len; unsigned char arr[41]; } v_scf_descripcion;

   /* EXEC SQL END DECLARE SECTION; */ 


   /* EXEC SQL SELECT S.SCF_DESCRIPCION
   INTO           :v_scf_descripcion
   FROM SUCURSALES S, USUARIOS U
   WHERE U.USR_CODIGO=USER
   AND   U.SCF_CODIGO=S.SCF_CODIGO; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select S.SCF_DESCRIPCION into :b0  from SUCURSALES S ,USUA\
RIOS U where (U.USR_CODIGO=USER and U.SCF_CODIGO=S.SCF_CODIGO)";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2007;
   sqlstm.selerr = (unsigned short)0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_scf_descripcion;
   sqlstm.sqhstl[0] = (unsigned long )43;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   AddNullVarchar(v_scf_descripcion);
   if((strcmp(v_columna,"SCF_CODIGO"))==0){
      sprintf(campo,"%s",v_scf_descripcion.arr);
   }

   for(;strlen(campo)<largos[0];)
     strcat(campo, " ");
   campo[largos[0]]=0;
   return campo;
}

void Prs_Num_Ori(long srv_cod_ori,long cnt_num_ori,long *prs_num_ori)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      long v_prs_num_ori;
   /* EXEC SQL END DECLARE SECTION; */ 


   /* EXEC SQL SELECT PRS_NUMERO
   INTO    :v_prs_num_ori
   FROM CONTRATOS
   WHERE CNT_NUMERO=:cnt_num_ori
   AND SRV_CODIGO=:srv_cod_ori; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select PRS_NUMERO into :b0  from CONTRATOS where (CNT_NUME\
RO=:b1 and SRV_CODIGO=:b2)";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2026;
   sqlstm.selerr = (unsigned short)0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_prs_num_ori;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&cnt_num_ori;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&srv_cod_ori;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   *prs_num_ori=v_prs_num_ori;
}

void SelectCodigoBarras(long srv_cod,
                        int  cnt_num,
                        long nro_ord,
			char *p_barras,
			char *nrobarra)
{
  /* BF:
   * DF:
   * EF: */

   int i=0;
   char barras[512],string_barras[255];
   char digito_verific[3];
   while(i<512){barras[i]=0;i++;}
/*
   sprintf(string_barras,"%1d%09ld%02d%012ld",
            2,srv_cod,cnt_num,nro_ord);
   GenerarDigitoVerificador(string_barras,digito_verific);
   sprintf(string_barras,"%s%s",string_barras,digito_verific);
*/
   sprintf(string_barras,"%010d", nro_ord);
   num2bar(string_barras,barras,sizeof(barras));
   sprintf(p_barras,"%c%s%c",'<',barras,'>');
   strcpy(nrobarra,string_barras);
}

void Buscar_Codigos_Control(char *tim_codigo_control_1,
                            char *tim_codigo_control_2,
                            char *tim_codigo_control_3,
                            char *tim_codigo_control_4,
                            char *tim_codigo_control_5,
                            char *tim_codigo_control_6,
                            char *tim_codigo_control_7,
                            char *tim_codigo_control_8,
                            char *tim_codigo_control_9,
                            char *tim_codigo_control_10,
                            char *tim_codigo_control_11,
                            char *tim_codigo_control_12,
                            char *tim_codigo_control_13,
                            char *tim_codigo_control_14,
                            char *tim_codigo_control_15,
                            char *tim_codigo)
{
  /* BF:
   * DF:
   * EF: */

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      /* varchar v_codigo_control_1[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_1;
short s_1;
      /* varchar v_codigo_control_2[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_2;
short s_2;
      /* varchar v_codigo_control_3[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_3;
short s_3;
      /* varchar v_codigo_control_4[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_4;
short s_4;
      /* varchar v_codigo_control_5[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_5;
short s_5;
      /* varchar v_codigo_control_6[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_6;
short s_6;
      /* varchar v_codigo_control_7[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_7;
short s_7;
      /* varchar v_codigo_control_8[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_8;
short s_8;
      /* varchar v_codigo_control_9[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_9;
short s_9;
      /* varchar v_codigo_control_10[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_10;
short s_10;
      /* varchar v_codigo_control_11[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_11;
short s_11;
      /* varchar v_codigo_control_12[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_12;
short s_12;
      /* varchar v_codigo_control_13[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_13;
short s_13;
      /* varchar v_codigo_control_14[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_14;
short s_14;
      /* varchar v_codigo_control_15[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_codigo_control_15;
short s_15;
      /* varchar v_tim_codigo[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_tim_codigo;

   /* EXEC SQL END DECLARE SECTION; */ 


   Str2Varchar(tim_codigo,v_tim_codigo);

   /* EXEC SQL SELECT TIM_CODIGO_CONTROL_1,
                   TIM_CODIGO_CONTROL_2,
                   TIM_CODIGO_CONTROL_3,
                   TIM_CODIGO_CONTROL_4,
                   TIM_CODIGO_CONTROL_5,
                   TIM_CODIGO_CONTROL_6,
                   TIM_CODIGO_CONTROL_7,
                   TIM_CODIGO_CONTROL_8,
                   TIM_CODIGO_CONTROL_9,
                   TIM_CODIGO_CONTROL_10,
                   TIM_CODIGO_CONTROL_11,
                   TIM_CODIGO_CONTROL_12,
                   TIM_CODIGO_CONTROL_13,
                   TIM_CODIGO_CONTROL_14,
                   TIM_CODIGO_CONTROL_15
            INTO  :v_codigo_control_1:s_1,
                  :v_codigo_control_2:s_2,
                  :v_codigo_control_3:s_3,
                  :v_codigo_control_4:s_4,
                  :v_codigo_control_5:s_5,
                  :v_codigo_control_6:s_6,
                  :v_codigo_control_7:s_7,
                  :v_codigo_control_8:s_8,
                  :v_codigo_control_9:s_9,
                  :v_codigo_control_10:s_10,
                  :v_codigo_control_11:s_11,
                  :v_codigo_control_12:s_12,
                  :v_codigo_control_13:s_13,
                  :v_codigo_control_14:s_14,
                  :v_codigo_control_15:s_15
            FROM TIPOS_IMPRESORA
            WHERE TIM_CODIGO=:v_tim_codigo; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 33;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select TIM_CODIGO_CONTROL_1 ,TIM_CODIGO_CONTROL_2 ,TIM_COD\
IGO_CONTROL_3 ,TIM_CODIGO_CONTROL_4 ,TIM_CODIGO_CONTROL_5 ,TIM_CODIGO_CONTROL_\
6 ,TIM_CODIGO_CONTROL_7 ,TIM_CODIGO_CONTROL_8 ,TIM_CODIGO_CONTROL_9 ,TIM_CODIG\
O_CONTROL_10 ,TIM_CODIGO_CONTROL_11 ,TIM_CODIGO_CONTROL_12 ,TIM_CODIGO_CONTROL\
_13 ,TIM_CODIGO_CONTROL_14 ,TIM_CODIGO_CONTROL_15 into :b0:b1,:b2:b3,:b4:b5,:b\
6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b2\
4:b25,:b26:b27,:b28:b29  from TIPOS_IMPRESORA where TIM_CODIGO=:b30";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2053;
   sqlstm.selerr = (unsigned short)0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_codigo_control_1;
   sqlstm.sqhstl[0] = (unsigned long )33;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&s_1;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_codigo_control_2;
   sqlstm.sqhstl[1] = (unsigned long )33;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&s_2;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_codigo_control_3;
   sqlstm.sqhstl[2] = (unsigned long )33;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&s_3;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_codigo_control_4;
   sqlstm.sqhstl[3] = (unsigned long )33;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&s_4;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_codigo_control_5;
   sqlstm.sqhstl[4] = (unsigned long )33;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&s_5;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_codigo_control_6;
   sqlstm.sqhstl[5] = (unsigned long )33;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&s_6;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_codigo_control_7;
   sqlstm.sqhstl[6] = (unsigned long )33;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&s_7;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_codigo_control_8;
   sqlstm.sqhstl[7] = (unsigned long )33;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&s_8;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_codigo_control_9;
   sqlstm.sqhstl[8] = (unsigned long )33;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&s_9;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_codigo_control_10;
   sqlstm.sqhstl[9] = (unsigned long )33;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&s_10;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_codigo_control_11;
   sqlstm.sqhstl[10] = (unsigned long )33;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&s_11;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_codigo_control_12;
   sqlstm.sqhstl[11] = (unsigned long )33;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&s_12;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_codigo_control_13;
   sqlstm.sqhstl[12] = (unsigned long )33;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&s_13;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_codigo_control_14;
   sqlstm.sqhstl[13] = (unsigned long )33;
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&s_14;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_codigo_control_15;
   sqlstm.sqhstl[14] = (unsigned long )33;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&s_15;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_tim_codigo;
   sqlstm.sqhstl[15] = (unsigned long )8;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)0;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) ErrorSql(__FILE__,__LINE__);
}



   if(s_1==-1) tim_codigo_control_1[0]=0;
   else Varchar2Str(v_codigo_control_1,tim_codigo_control_1);
   if(s_2==-1) tim_codigo_control_2[0]=0;
   else Varchar2Str(v_codigo_control_2,tim_codigo_control_2);
   if(s_3==-1) tim_codigo_control_3[0]=0;
   else Varchar2Str(v_codigo_control_3,tim_codigo_control_3);
   if(s_4==-1) tim_codigo_control_4[0]=0;
   else Varchar2Str(v_codigo_control_4,tim_codigo_control_4);
   if(s_5==-1) tim_codigo_control_5[0]=0;
   else Varchar2Str(v_codigo_control_5,tim_codigo_control_5);
   if(s_6==-1) tim_codigo_control_6[0]=0;
   else Varchar2Str(v_codigo_control_6,tim_codigo_control_6);
   if(s_7==-1) tim_codigo_control_7[0]=0;
   else Varchar2Str(v_codigo_control_7,tim_codigo_control_7);
   if(s_8==-1) tim_codigo_control_8[0]=0;
   else Varchar2Str(v_codigo_control_8,tim_codigo_control_8);
   if(s_9==-1) tim_codigo_control_9[0]=0;
   else Varchar2Str(v_codigo_control_9,tim_codigo_control_9);
   if(s_10==-1) tim_codigo_control_10[0]=0;
   else Varchar2Str(v_codigo_control_10,tim_codigo_control_10);
   if(s_9==-1) tim_codigo_control_11[0]=0;
   else Varchar2Str(v_codigo_control_11,tim_codigo_control_11);
   if(s_12==-1) tim_codigo_control_12[0]=0;
   else Varchar2Str(v_codigo_control_12,tim_codigo_control_12);
   if(s_13==-1) tim_codigo_control_13[0]=0;
   else Varchar2Str(v_codigo_control_13,tim_codigo_control_13);
   if(s_14==-1) tim_codigo_control_14[0]=0;
   else Varchar2Str(v_codigo_control_14,tim_codigo_control_14);
   if(s_15==-1) tim_codigo_control_15[0]=0;
   else Varchar2Str(v_codigo_control_15,tim_codigo_control_15);
}
