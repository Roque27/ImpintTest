#define	DISPCONNECT	1	/* Display mensajes durante la conexion */
#define	CONNECTED	1	/* Connect ok */

#define	TRAP		1	/* Display Msg Error */

#define	COUNTHITS	sqlca.sqlerrd[2]	/* Count Selected Rows */

int	Connect(char *user, int accion);
void	DispSqlError();
int	TestError(int accion);
int	TestErrorN(int accion,int posicion);
void    Cuenta_Fila(void);
/* FAB 23/09/2009
void    ErrorSql(void);
*/
void    ErrorSql(char *archivo, int linea);
#define NO_DATA_FOUND sqlca.sqlcode==1403
#define DATA_FOUND sqlca.sqlcode!=1403
