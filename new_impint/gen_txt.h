char *Notifi(char   *noti,
             long   prs_num,
             long   srv_cod,
             int    cnt_num, 
             long   trt_num,
             long   nro_ord,
             char   *salida,
             char   *tim_codigo,
             char   *bar_code);
char *Personas(int[],char *,char *,long);
char *Contratos(int[],char *,char *,long,int,int *,char *);
char *Servicios(int[],char *,char *,long,long *,long *);
char *Documentos(int[],char *,char *,long,int,long,int,int,long);
char *Lecturas(int[],char *,char *,long);
char *Ordenativos(int[],char *,char *,long,long *,long *,long *,char *);
char *Potencias(int[],char *,char *,long,int);
char *Stock_Equipos(int[],char *,char *,long);
char *Sucursales(int[],char *,char *,long);
char *Bancos(int[],char *,char *,long);
char *Cargos(int[],char *,char *,char *);
char *Tipos_IVA(int[],char *,char *,int);
char *Tarifas(int[],char *,char *,char *);
char *Totales_Tramite(int[],char *,char *,long);
char *Usuarios(int[],char *,char *);
void  Prs_Num_Ori(long,long,long *);
void  SelectCodigoBarras(long,int,long,char *,char *);
void  Buscar_Codigos_Control(char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *);

