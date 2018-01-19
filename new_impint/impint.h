/* Sistema       :Oracle*PowerSys. ORACLE ARGENTINA S.A.
 * Modulo        :Cobranza.
 * Programa      :Impresion de Intimaciones 
 * Version       :Version 1.0
 * Fecha         :28-NOV-95.
*/


#define	ERRPARAMIMP	"userid=... file=... cpr_numero_desde=... cpr_numero_hasta=... ord_numero_desde=... ord_numero_hasta=... grf_codigo_desde=... grf_codigo_hasta=... impr=..."


#define	SI 	1
#define	NO 	0

/* Tipos de error */
#define	ABORT	"A"
#define WARNING	"W"

/* Constantes generales */
#define	NULLSTRING	""

/* Tipos de intimacion */
#define	INTIMACION_ORIGINAL	"ICC"
#define	INTIMACION_COPIA	"ICD"
#define NOTIFICACION		"NPJ"
#define	INTIMACION_G_ORIGINAL	"ICG"
#define	INTIMACION_G_COPIA	"IGD"
#define	INTIMACION_NBG		"IBO"
#define	INTIMACION_NBG_C	"IBD"

int
ChqParametros(int , char **);

/* --------------------------------------------------------------------	*/
/* Generacion del archivo de impresion de intimaciones.			*/
/* --------------------------------------------------------------------	*/

int
Generar_Impresiones();

int
notifi(	char *,
	long ,
	long , 
	long ,
	long ,
	long ,
	char *,
	char *);

void 
Busco_Tim(void);
