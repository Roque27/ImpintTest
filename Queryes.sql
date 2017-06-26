id=RCITTADI/PaSsWoRd 
Tipo=CO 
Correo=BR 
Suc=12 
Sec=GESCOB 
Tor_codigo=I1 
Ord_Dsd=10769681 
Ord_Hst=10769681 
User=RCITTADI 
file=ALEATORIO_18466713 
Reporte=DEU_3401

---------------------------------------------------------------
--MAIN---------------------------------------------------------
---------------------------------------------------------------
END
DECLARE section;
---------------------------------------------------------------
ALTER session
SET optimizer_features_enable = '8.1.7';
---------------------------------------------------------------
SELECT to_char(sysdate, 'dd/mm/yyyy hh:mi')
FROM sys.dual;
---------------------------------------------------------------
SELECT usr_numero --999
FROM usuarios
WHERE usr_codigo = :l_usr_codigo; --'RCITTADI'
---------------------------------------------------------------
SELECT tim_codigo --'LASER'
FROM impresoras
WHERE impresoras.prt_codigo = '1'
---------------------------------------------------------------
--No se usa
SELECT to_number(pgr_valor)
FROM param_gral
WHERE pgr_codigo = 'MININT';
---------------------------------------------------------------
SELECT crr_genera_planilla
	,crr_archivo_sql
	,crr_archivo_sql_path
FROM correos c
INNER JOIN usuarios u
	ON c.scf_codigo = u.scf_codigo
WHERE usr_codigo = :l_usr_codigo --'RCITTADI'
	AND crr_tipo = :l_TipoCorreo --'CO'
	AND crr_codigo = :l_Correo; --'BR'
---------------------------------------------------------------
SELECT cpr_numero.nextval
FROM sys.dual;
---------------------------------------------------------------
INSERT INTO control_procesos (
	cpr_numero
	,cpr_tipo_proceso
	,usr_numero_incorpora
	,prc_codigo
	,est_codigo
	,cpr_fecha_inicio
	)
	VALUES (
		:l_cpr_numero
		,'IN'
		,:l_usr_numero
		,'IN'
		,:l_est_codigo
		,sysdate
		);
---------------------------------------------------------------
--Aca hay que separar el scf_codigo en otra variable y mostrarla en la query como constante
SELECT o.trt_numero --'9625713'
	,o.ord_numero --'10769681'
	,o.srv_codigo --'218944'
	,o.cnt_numero --'1'
	,nvl(o.tor_codigo, '') --'I1'
	,to_char(o.ord_fecha_generacion, 'dd/mm/yyyy') --'30/01/2017'
	,u.scf_codigo --'12'
	,o.sec_codigo_origen --'GESCOB'
	,t.tor_grupo --'NT'
	,t.tor_descripcion --'AVISO DEUDA COMUN BAJO FIRMA'
	,o.prs_numero --'50'
	,o.rowid --'AAADDuAAjAAAWfKAAO'
FROM ordenativos o
INNER JOIN tipos_ordenativo t
      ON o.tor_codigo = t.tor_codigo
CROSS JOIN usuarios u
WHERE t.tor_codigo = :l_Tor_codigo --'I1'
	AND u.usr_codigo = :l_usr_codigo --'RCITTADI'
	AND o.scf_codigo_origen = :l_Suc --'12'
	AND o.sec_codigo_origen = :l_Sec --'GESCOB'
	AND o.ord_numero BETWEEN :l_Ord_Dsd AND :l_Ord_Hst  --10769681 - 10769681
	AND o.crr_tipo = :l_TipoCorreo --'CO'
	AND o.crr_codigo = :l_Correo --'BR' - Destildar esta para datos
	AND o.ord_situacion = 'P' --Destildar esta para datos
	AND o.ord_estado = 'D'
ORDER BY o.ord_numero;
---------------------------------------------------------------
whenever sqlerror do ErrorSql(__FILE__, __LINE__);
---------------------------------------------------------------
FETCH MiCursor
INTO :l_trt_numero :s_trt_numero
	,:l_ord_numero :s_ord_numero
	,:l_srv_codigo :s_srv_codigo
	,:l_cnt_numero :s_cnt_numero
	,:l_tor_codigo :s_tor_codigo
	,:l_ord_fecha_generacion :s_ord_fecha_generacion
	,:l_scf_codigo :s_scf_codigo
	,:l_sec_codigo :s_sec_codigo
	,:l_tor_grupo :s_tor_grupo
	,:l_tor_descripcion :s_tor_descripcion
	,:l_o_prs_numero :s_o_prs_numero
	,:l_rowid;

---------------------------------------------------------------
SELECT personas.prs_numero --''
	,substr(personas.prs_razon_social, 1, 25) --''
	,nvl(personas.prs_direccion, ' ') --''
	,personas.cfc_codigo --''
	,substr(calles.cll_nombre, 1, 18) --''
	,substr(nvl(personas.prs_nro, '    '), 1, 4) --''
	,substr(nvl(personas.prs_piso, '  '), 1, 2) --''
	,substr(nvl(personas.prs_depto, '   '), 1, 3) --''
	,nvl(personas.prs_torre, ' ') --''
	,nvl(personas.prs_c_postal, ' ') --''
	,nvl(areas_geograficas.agf_nombre, ' ') --''
FROM areas_geograficas 
INNER JOIN personas 
	ON areas_geograficas.agf_codigo = personas.agf_codigo
INNER JOIN calles
	ON calles.cll_codigo = personas.cll_codigo AND calles.agf_codigo = personas.agf_codigo
WHERE personas.prs_numero = :l_o_prs_numero; --'50'
---------------------------------------------------------------
SELECT personas.prs_numero 							--'218944'
	,substr(personas.prs_razon_social, 1, 25) 		--'SOC.TIRO SUIZO ROSA'
	,nvl(personas.prs_direccion, ' ') 				--' '
	,personas.cfc_codigo 							--'AT'
	,substr(calles.cll_nombre, 1, 18) 				--'RAFFO PJ.'
	,substr(contratos.cnt_nro_pago, 1, 4) 			--'5120'
	,contratos.cnt_bis 								--'N'
	,substr(contratos.cnt_piso_pago, 1, 2) 			--''
	,substr(contratos.cnt_depto_pago, 1, 3) 		--''
	,nvl(contratos.cnt_c_postal_pago, ' ') 			--'2000'
	,nvl(areas_geograficas.agf_nombre, ' ') 		--'ROSARIO'
FROM areas_geograficas
INNER JOIN contratos
	ON areas_geograficas.agf_codigo = contratos.agf_codigo
INNER JOIN personas
	ON personas.prs_numero = contratos.prs_numero
INNER JOIN calles
	ON calles.agf_codigo = contratos.agf_codigo AND calles.cll_codigo = contratos.cll_codigo
WHERE contratos.srv_codigo = :l_srv_codigo --'218944'
	AND contratos.cnt_numero = :l_cnt_numero --'1'
---------------------------------------------------------------
SELECT personas.prs_numero 									--'218944'
	,substr(personas.prs_razon_social, 1, 25) 				--'SOC.TIRO SUIZO ROSA'
	,nvl(personas.prs_direccion, ' ') 						--' '
	,personas.cfc_codigo 									--'AT'
	,substr(nvl(contratos.cnt_direccion_pago, ' '), 1, 27) 	--' '
INTO :l_prs_numero
	,:l_prs_razon_social
	,:l_prs_direccion
	,:l_cfc_codigo
	,:l_cll_nombre_completo :s_cll_nombre_completo
FROM contratos
INNER JOIN personas
	ON personas.prs_numero = contratos.prs_numero
WHERE contratos.srv_codigo = :l_srv_codigo --'218944'
	AND contratos.cnt_numero = :l_cnt_numero --'1'
---------------------------------------------------------------
SELECT not_codigo --'I1'
INTO :l_not_codigo
FROM combinaciones_habilitadas_noti
WHERE tor_codigo = :l_tor_codigo --'I1'
	AND cfc_codigo = :l_cfc_codigo; --'AT'
---------------------------------------------------------------
UPDATE ordenativos
SET cpr_numero = :l_cpr_numero --Numero de proceso actual
WHERE rowid = :l_rowid; --'ID de la row actual del cursor'
---------------------------------------------------------------
UPDATE ordenativos
SET ord_situacion = 'I'
	,cpr_numero = :l_cpr_numero  --Numero de proceso actual
WHERE rowid = :l_rowid; --'ID de la row actual del cursor'
---------------------------------------------------------------
UPDATE ordenativos
SET ord_estado = 'A'
	,cpr_numero = :l_cpr_numero  --Numero de proceso actual
	,ord_datos_anula = 'Anulado Documentos ya pagados - Saldo 0 - No se imprime  '
WHERE rowid = :l_rowid; --'ID de la row actual del cursor'
---------------------------------------------------------------
COMMIT
---------------------------------------------------------------
CLOSE MiCursor
---------------------------------------------------------------
BEGIN
	:l_prox_est_codigo : = fun_proximo_estado('IN', :l_est_codigo, 'IM');
END;
---------------------------------------------------------------
UPDATE control_procesos
SET est_codigo = :l_prox_est_codigo
WHERE cpr_numero = :l_cpr_numero; --Numero de proceso actual
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--GrabaEnReportes----------------------------------------------
---------------------------------------------------------------
BEGIN DECLARE section;
	VARCHAR l_FechaDelDia [17];
	VARCHAR l_rep_codigo [9];
	VARCHAR l_rep_descripcion [31];
	long l_rep_prioridad;
	VARCHAR l_rep_borra_archivo [2];
	VARCHAR l_rep_condicion_impresion [2];
	VARCHAR l_rep_comando [51];
	VARCHAR l_cnr_comando [401];
	VARCHAR l_rep_tipo_comando [4];
	VARCHAR l_rep_orientacion [10];
	VARCHAR l_rep_destino [16];
	VARCHAR l_rep_archivo_default [101];
	VARCHAR l_prt_uname [31];
	VARCHAR l_cnr_uname [31];
	VARCHAR l_cnr_archivo [61];
	VARCHAR l_cnr_salida [2];
	VARCHAR l_prt_codigo [16];
	LONG l_cnr_numero;	
END DECLARE section
---------------------------------------------------------------
SELECT to_char(sysdate, 'dd/mm/yyyy') --No se usa
	,to_char(sysdate, 'hhmiss')
FROM sys.dual;
---------------------------------------------------------------
--No se usa
SELECT cnr_numero.nextval
FROM sys.dual;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Notifi-------------------------------------------------------
---------------------------------------------------------------
BEGIN DECLARE section;
	VARCHAR v_noti [4];
	VARCHAR v_doc_tipo [3];
	VARCHAR v_not_codigo [4];
	VARCHAR v_not_descripcion [61];
	INT v_eno_orden;
	VARCHAR v_eno_tipo [2];
	VARCHAR v_eno_texto [3072];
	SHORT s_eno_texto;
	VARCHAR v_eno_var_nombre [21];
	SHORT s_eno_var_nombre;
	VARCHAR v_eno_var_tipo [2];
	SHORT s_eno_var_tipo;
	INT v_eno_var_longitud;
	SHORT s_eno_var_longitud;
	DOUBLE v_eno_col;
	SHORT s_eno_col;
	VARCHAR v_eno_tipo_campo [2];
	SHORT s_eno_tipo_campo;
	VARCHAR v_tabla [31];
	VARCHAR v_columna [31];
END DECLARE section
---------------------------------------------------------------
DECLARE TEXTO CURSOR
FOR
SELECT ENO.ENO_ORDEN --'10'
  ,ENO.ENO_TIPO --'V'
  ,ENO.ENO_TEXTO --'<Long>'
  ,ENO.ENO_VAR_NOMBRE --' '
  ,ENO.ENO_VAR_TIPO --'C'
  ,ENO.ENO_VAR_LONGITUD --'30'
  ,ENO.ENO_COL# --'157'
  ,ENO.ENO_TIPO_CAMPO --'F'
FROM ESTRUCTURA_NOTIFICACION ENO
INNER JOIN SERVICIOS SRV
	ON NVL(ENO.SCF_CODIGO, SRV.SCF_CODIGO) = SRV.SCF_CODIGO
WHERE ENO.NOT_CODIGO = :v_not_codigo --'I1'
	AND SRV.SRV_CODIGO = :srv_cod --'218944'
	AND ENO.ENO_ORDEN NOT IN 
	(
		SELECT DISTINCT NVL(ENO_SUB_ORDEN, 0)
		FROM ESTRUCTURA_NOTIFICACION
		WHERE NOT_CODIGO = :v_not_codigo --'I1'
			AND SCF_CODIGO = SRV.SCF_CODIGO
	)
ORDER BY ENO.ENO_ORDEN;
---------------------------------------------------------------
SELECT NOT_CODIGO --I1
	,NOT_DESCRIPCION --'AVISO DE DEUDA COMUN BAJO FIRMA'
FROM TIPOS_NOTIFICACION
WHERE NOT_CODIGO = :v_noti; --'I1'
---------------------------------------------------------------
OPEN TEXTO
FETCH TEXTO INTO
         :v_eno_orden,
         :v_eno_tipo,
         :v_eno_texto:s_eno_texto,
         :v_eno_var_nombre:s_eno_var_nombre,
         :v_eno_var_tipo:s_eno_var_tipo,
         :v_eno_var_longitud:s_eno_var_longitud,
         :v_eno_col:s_eno_col,
         :v_eno_tipo_campo:s_eno_tipo_campo;
---------------------------------------------------------------
SELECT TABLA --'PERSONAS'
	  ,COLUMNA --'PRS_RAZON_SOCIAL'
FROM COL_NOTIFICACION
WHERE COL# = :v_eno_col; --'157'
---------------------------------------------------------------
CLOSE TEXTO
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Personas-----------------------------------------------------
---------------------------------------------------------------
BEGIN DECLARE SECTION;

	STATIC long v_prs_numero = - 1;
	STATIC VARCHAR v_prs_razon_social [31];
	STATIC DOUBLE v_prs_cuit;
	STATIC short s_prs_cuit;
	STATIC VARCHAR v_tipo_doc [4];
	STATIC short s_tipo_doc;
	STATIC DOUBLE v_prs_documento;
	STATIC short s_prs_documento;
	STATIC VARCHAR v_prs_direccion [46];
	STATIC short s_prs_direccion;
	STATIC VARCHAR v_prs_nro [6];
	STATIC short s_prs_nro;
	STATIC VARCHAR v_prs_depto [3];
	STATIC short s_prs_depto;
	STATIC DOUBLE v_agf_codigo;
	STATIC VARCHAR v_prs_categoria [4];
	STATIC short s_prs_categoria;
	STATIC VARCHAR v_prs_calle [26];
	STATIC short s_prs_calle;
	STATIC VARCHAR v_prs_c_postal [9];
	STATIC short s_prs_c_postal;
	STATIC VARCHAR v_prs_telefonos [41];
	STATIC short s_prs_telefonos;
	STATIC VARCHAR v_prs_fax [11];
	STATIC short s_prs_fax;
	STATIC VARCHAR v_prs_estado [2];
	STATIC short s_prs_estado;
	STATIC VARCHAR v_prs_piso [3];
	STATIC short s_prs_piso;
	STATIC DOUBLE v_prs_numero_registro;
	STATIC short s_prs_numero_registro;
	STATIC VARCHAR v_agf_nombre [31];
	
END DECLARE SECTION;
---------------------------------------------------------------
SELECT P.PRS_NUMERO --'218944'
  ,P.PRS_RAZON_SOCIAL --'SOC.TIRO SUIZO ROSA'
  ,COALESCE(NVL(P.PRS_CUIT, 0), 0) AS --'30555955428'
  ,COALESCE(NVL(P.PRS_TIPO_DOC, ''), '0') AS --'DNI'
  ,COALESCE(NVL(P.PRS_DOCUMENTO, 0), 0) AS --'0'
  ,COALESCE(NVL(P.PRS_NRO, 0), '0') AS --'5120'
  ,COALESCE(NVL(P.PRS_DEPTO, ''), '0') AS --' '
  ,NVL(P.AGF_CODIGO, 0) --'12'
  ,COALESCE(NVL(P.PRS_C_POSTAL, ''), '0') AS --'2000'
  ,COALESCE(NVL(P.PRS_TELEFONOS, 0), '0') AS --'0'
  ,COALESCE(NVL(P.PRS_FAX, 0), '0') AS --'0'
  ,COALESCE(NVL(P.PRS_ESTADO, ''), '0') AS --'A'
  ,COALESCE(NVL(P.PRS_PISO, 0), '0') AS --'0'
  ,COALESCE(NVL(C.CLL_NOMBRE, ''), '0') AS PRS_DIRECCION --'RAFFO PJ.'
  ,NVL(DECODE(P.PRS_BIS, 'N', ' ', P.PRS_BIS), ' ') --' '
  ,NVL(P.PRS_TORRE, ' ') --' '
FROM PERSONAS P
INNER JOIN CALLES C
	ON (C.AGF_CODIGO = P.AGF_CODIGO AND C.CLL_CODIGO = P.CLL_CODIGO)
WHERE P.PRS_NUMERO = :prs_num --'218944'
---------------------------------------------------------------
SELECT AGF_NOMBRE --'ROSARIO'
FROM AREAS_GEOGRAFICAS
WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo; --'12'
---------------------------------------------------------------
SELECT AGF_NOMBRE
FROM AREAS_GEOGRAFICAS
WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Contratos----------------------------------------------------
---------------------------------------------------------------
SELECT T.PRS_NUMERO --'218944'
	,COALESCE(T.PRS_NUMERO_APODERADO, 0) AS --''
	,T.TCL_CODIGO --'P'
	,T.CLA_CODIGO --'P31SC1'
	,T.TEN_CODIGO --'01'
	,T.CAT_CODIGO --'U'
	,T.CNT_PROPIETARIO --''
	,to_char(T.CNT_FECHA_INICIO, 'dd/mm/yy') --'31/07/98'
	,T.IVV_CODIGO --'1'
	,to_char(T.CNT_FECHA_FIN, 'dd/mm/yy') --''
	,T.CNT_TIPO --'DE'
	,T.CNT_DIRECCION_PAGO --''
	,T.CNT_NRO_PAGO --'5120'
	,T.CNT_PISO_PAGO --''
	,T.CNT_DEPTO_PAGO --''
	,T.CNT_C_POSTAL_PAGO --'2000'
	,T.MIN_CODIGO --''
	,T.CNT_ANIO --'2017'
	,T.CNT_PERIODO --'3'
	,T.CNT_LEGAJO --''
	,T.CNT_CIIU --'5713'
	,T.URC_CODIGO --'0'
	,T.MPA_TIPO_MEDIO_PAGO --'PA'
	,T.CNT_NUMERO_CUENTA --''
	,T.CNT_OBSERVACIONES --''
	,T.OIM_TIPO --'NO'
	,T.CNT_ESTADO --'V'
	,T.AGF_CODIGO --''
	,C.CLL_NOMBRE --'12'
	,COALESCE(T.CNT_BIS, '0') AS CNT_BIS --'RAFFO PJ.'
	,COALESCE(T.CNT_TORRE_PAGO, '0') AS --''
FROM CONTRATOS T
LEFT JOIN CALLES C
	ON (C.AGF_CODIGO = T.AGF_CODIGO AND C.CLL_CODIGO = T.CLL_CODIGO)
WHERE SRV_CODIGO = :srv_cod --'218944'
	AND CNT_NUMERO = :cnt_num --'1'
---------------------------------------------------------------
SELECT personas.prs_numero --'50'
	,substr(personas.prs_razon_social, 1, 25) --'LITORAL GAS.S.A.'
	,nvl(personas.prs_direccion, ' ') --' '
	,personas.cfc_codigo --'N'
	,substr(calles.cll_nombre, 1, 18) --'VEINTICUATRO DE SE'
	,substr(nvl(personas.prs_nro, '    '), 1, 4) --'248'
	,substr(nvl(personas.prs_piso, '  '), 1, 2) --' '
	,substr(nvl(personas.prs_depto, '   '), 1, 3) --' '
	,nvl(personas.prs_torre, ' ') --' '
	,nvl(personas.prs_c_postal, ' ') --'2000'
	,personas.agf_codigo --'12'
FROM personas
INNER JOIN calles
	ON (calles.cll_codigo = personas.cll_codigo AND calles.agf_codigo = personas.agf_codigo)
WHERE personas.prs_numero = :l_o_prs_numero; --'50'
---------------------------------------------------------------
SELECT AGF_NOMBRE
FROM AREAS_GEOGRAFICAS
WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :ll_prs_agf_codigo; --'12'
---------------------------------------------------------------
SELECT AGF_NOMBRE
FROM AREAS_GEOGRAFICAS
WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_cnt_agf_codigo;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Servicios----------------------------------------------------
---------------------------------------------------------------
SELECT S.SCF_CODIGO --'12'
  ,COALESCE(S.AGE_CODIGO, '0') AS AGE_CODIGO --'0'
  ,S.RTA_CODIGO --'5038'
  ,COALESCE(S.SRV_ORDEN_LECTURA, 0) AS SRV_ORDEN_LECTURA --'91'
  ,COALESCE(S.SRV_DIRECCION, '0') AS SRV_DIRECCION --' '
  ,COALESCE(S.SRV_BIS, '0') AS SRV_BIS --'N'
  ,COALESCE(S.SRV_NRO, 0) AS SRV_NRO --'5120'
  ,COALESCE(S.SRV_TORRE, '0') AS SRV_TORRE --' '
  ,COALESCE(S.SRV_PISO, '0') AS SRV_PISO --' '
  ,COALESCE(S.SRV_DEPTO, '0') AS SRV_DEPTO --' '
  ,COALESCE(S.SRV_C_POSTAL, '0') AS SRV_C_POSTAL --'2000'
  ,S.AGF_CODIGO --'12'
  ,COALESCE(to_char(S.SRV_FECHA_INSTAL, 'dd/mm/yy'), '0') AS SRV_FECHA_INSTAL --'19/09/97'
  ,COALESCE(to_char(S.SRV_FECHA_BAJA, 'dd/mm/yy'), '0') AS SRV_FECHA_BAJA --''
  ,COALESCE(S.SRV_MOTIVO_BAJA, '0') AS SRV_MOTIVO_BAJA --''
  ,COALESCE(S.SRV_SUMINISTRO_ORIGINAL, 0) AS SRV_SUMINISTRO_ORIGINAL --''
  ,COALESCE(S.EDI_NUMERO, 0) AS EDI_NUMERO --''
  ,COALESCE(S.SRV_ZONA_CATA, 0) AS SRV_ZONA_CATA --''
  ,COALESCE(S.SRV_MANZANA_CATA, 0) AS SRV_MANZANA_CATA --''
  ,COALESCE(S.SRV_LOTE_CATA, 0) AS SRV_LOTE_CATA --''
  ,S.SRV_ESTADO --'SN'
  ,COALESCE(S.SRV_OBSERVACIONES, '0') AS SRV_OBSERVACIONES --'                                    0000'
  ,COALESCE(C.CLL_NOMBRE, '0') AS CLL_NOMBRE --'RAFFO PJ.'
FROM SERVICIOS S
LEFT JOIN CALLES C 
	ON (C.AGF_CODIGO = S.AGF_CODIGO AND C.CLL_CODIGO = S.CLL_CODIGO)
WHERE SRV_CODIGO = :srv_cod --'218944'
---------------------------------------------------------------
SELECT AGF_NOMBRE
FROM AREAS_GEOGRAFICAS
WHERE AREAS_GEOGRAFICAS.AGF_CODIGO = :v_agf_codigo; --'12'
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Lecturas-----------------------------------------------------
---------------------------------------------------------------
SELECT LCT_VALOR_LEIDO --'769648,000'
FROM LECTURAS
WHERE LCT_CODIGO IN (
		SELECT max(LCT_CODIGO)
		FROM LECTURAS
		WHERE SRV_CODIGO = :srv_cod --'218944'
		);
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Ordenativos--------------------------------------------------
---------------------------------------------------------------
SELECT to_char(ORD_FECHA_GENERACION, 'dd/mm/yyyy') --'30/01/2017'
  ,to_char(fun_habil_anterior(1, ORD_FECHA_GENERACION), 'dd/mm/yyyy') --'29/01/2017'
  ,to_char(ORD_FECHA_VENCIMIENTO, 'dd/mm/yyyy') --'06/02/2017'
  ,SRV_CODIGO_ORIGEN --''
  ,CNT_NUMERO_ORIGEN --''
  ,TRT_NUMERO_ORIGEN --''
  ,ORD_DATOS_ADICIONALES --'Gestion Individual'
  ,SRV_CODIGO --'218944'
FROM ORDENATIVOS
WHERE ORD_NUMERO = :nro_ord; --'10769681'
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--TiposOrdenativo----------------------------------------------
---------------------------------------------------------------

--Contiene logica backend solamente

---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Potencias----------------------------------------------------
---------------------------------------------------------------
SELECT POT_VALOR
FROM POTENCIAS
WHERE SRV_CODIGO = :srv_cod  --'218944'
	AND CNT_NUMERO = :cnt_num --'1'
	AND CDR_UNIDAD IN ('DA')
	AND POT_ORIGEN IN ('C')
	AND POT_FECHA IN (
		SELECT max(POT_FECHA)
		FROM POTENCIAS
		WHERE SRV_CODIGO = :srv_cod  --'218944'
			AND CNT_NUMERO = :cnt_num --'1'
			AND CDR_UNIDAD IN ('DA')
			AND POT_ORIGEN IN ('C')
		);
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Stock_Equipos------------------------------------------------
---------------------------------------------------------------
SELECT S.STE_NUMERO --'94010238'
	,S.STE_TIPO --'M'
INTO :v_ste_numero
	,:v_ste_tipo
FROM STOCK_EQUIPOS S
INNER JOIN EQUIPOS E
	ON (S.STE_NUMERO = E.STE_NUMERO AND S.STE_TIPO = E.STE_TIPO)
WHERE E.SRV_CODIGO = :srv_cod --'218944'
	AND E.EQP_ESTADO IS NULL;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Sucursales---------------------------------------------------
---------------------------------------------------------------
SELECT SCF_DESCRIPCION --'Rosario'
	,SCF_DIRECCION --'Mitre 635'
INTO :v_scf_descripcion
	,:v_scf_direccion :s_scf_direccion
FROM SUCURSALES
WHERE SCF_CODIGO = :scf_cod; --'12'
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Bancos-------------------------------------------------------
---------------------------------------------------------------
DECLARE CURC CURSOR
FOR
SELECT U.URC_DESCRIPCION_ALT
FROM UNIDADES_REC_COBRO C
INNER JOIN UNIDADES_RECAUDADORAS U 
	ON U.URC_CODIGO = C.URC_CODIGO
WHERE C.UCO_TIPO = 'A'
	AND C.AGF_CODIGO = :v_agf_cod; --'12'

OPEN CURC;

FETCH CURC
INTO :ha_urc_descripcion :s_urc_descripcion;

CLOSE CURC;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Cargos-------------------------------------------------------
---------------------------------------------------------------

--Cargo por aviso de deuda: $    1.76 más IVA
SELECT 'Cargo por ' || :v_txt [i] || ': $' || TO_CHAR(PPR_PRECIO, '9990.00') || ' más IVA' --'aviso de deuda'
FROM PRECIOS_PRESTACION
WHERE TIT_CLAVE = :v_tit_clave [i] --'ND1'
  AND PPR_FECHA_VIGENCIA = (
    SELECT MAX(PPR_FECHA_VIGENCIA)
    FROM PRECIOS_PRESTACION
    WHERE TIT_CLAVE = :v_tit_clave [i] --'ND1'
      AND PPR_FECHA_VIGENCIA <= TO_DATE(:v_ord_fec, 'DD/MM/YYYY') --'30/01/2017'
    );
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Tipos_IVA----------------------------------------------------
---------------------------------------------------------------
SELECT IVV_DESCRIPCION --'Resp.Inscr.C/Ret.27%'
FROM TIPOS_IVA
WHERE IVV_CODIGO = :ivv_cod; --'1'
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Tarifas------------------------------------------------------
---------------------------------------------------------------
SELECT TCL_DESCRIPCION --'Servicio General P'
FROM TARIFAS
WHERE TCL_CODIGO = 'P'
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Documentos---------------------------------------------------
---------------------------------------------------------------
DECLARE DOC_D2 CURSOR
FOR
SELECT DOC_NUMERO --'21707155'
	,DOC_TIPO --'FI'
	,to_char(DOC_FECHA_EMISION, 'dd/mm/yyyy') --'01/12/1992'
	,DOC_PERIODO --'11'
	,DOC_ANIO --'1992'
	,DOC_CUOTA --'0'
	,DOC_TIPO_ORIGEN --''
	,DOC_NUMERO_ORIGEN --''
	,DOC_CONSUMO --''
	,ORD_NUMERO --''
	,URC_CODIGO --''
	,ASI_NUMERO --'84345'
	,DOC_IMPORTE --'341,57'
	,DOC_IMPORTE_BASICO --'0,00'
	,nvl(DOC_SALDO, DOC_IMPORTE) --'341,57'
	,to_char(DOC_FECHA_VENC, 'dd/mm/yy') --'15/12/92'
	,to_char(DOC_FECHA_VENC_1, 'dd/mm/yyyy') --'15/12/1992'
	,to_char(DOC_FECHA_VENC_2, 'dd/mm/yyyy') --''
	,DOC_RECARGO_VENC_2 --'0,00'
	,to_char(DOC_FECHA_VENC_3, 'dd/mm/yyyy') --''
	,DOC_RECARGO_VENC_3 --'0,00'
	,DOC_ESTADO --'D'
	,decode(doc_situacion, 'X', '(*)', 'C1', '(*)', 'C2', '(*)', 'C3', '(*)', '   ') LLAMADA_SIT_X --''
FROM DOCUMENTOS
WHERE TRT_NUMERO = :trt_num --'2801281'
	AND nvl(nvl(DOC_SALDO, DOC_IMPORTE), 0) > 0
	AND doc_situacion <> 'X'
ORDER BY DOC_FECHA_VENC_1

---------------------------------------------------------------
DECLARE DOC CURSOR
FOR
SELECT d.DOC_NUMERO --'233121261'
	,d.DOC_TIPO --'F'
	,to_char(d.DOC_FECHA_EMISION, 'dd/mm/yyyy') --'25/08/2010'
	,d.DOC_PERIODO --'8'
	,d.DOC_ANIO --'2010'
	,d.DOC_CUOTA --''
	,d.DOC_TIPO_ORIGEN --''
	,d.DOC_NUMERO_ORIGEN --''
	,d.DOC_CONSUMO --'17285,10'
	,d.ORD_NUMERO --''
	,d.URC_CODIGO --''
	,d.ASI_NUMERO --'220468'
	,d.DOC_IMPORTE --'8655,10'
	,d.DOC_IMPORTE_BASICO --'3457,34'
	,nvl(d.DOC_SALDO, d.DOC_IMPORTE) --'3724,94'
	,to_char(d.DOC_FECHA_VENC, 'dd/mm/yy') --'07/09/10'
	,to_char(d.DOC_FECHA_VENC_1, 'dd/mm/yyyy') --'07/09/2010'
  ,to_char(d.DOC_FECHA_VENC_2, 'dd/mm/yyyy') --''
  ,d.DOC_RECARGO_VENC_2 --''
  ,to_char(d.DOC_FECHA_VENC_3, 'dd/mm/yyyy') --''
  ,d.DOC_RECARGO_VENC_3 --''
  ,d.DOC_ESTADO --'D'
  ,decode(d.doc_situacion, 'X', '(*)', '   ') LLAMADA_SIT_X --''
FROM documentos d
INNER JOIN documentos_estadistica_view de 
	ON (d.doc_tipo = de.doc_tipo AND d.doc_numero = de.doc_numero)
WHERE nvl(nvl(d.DOC_SALDO, d.DOC_IMPORTE), 0) > 0
	AND de.ord_numero = :p_nro_ord --'10769681'
	AND d.doc_situacion <> 'X'
ORDER BY DOC_FECHA_VENC_1
---------------------------------------------------------------
FETCH DOC_D2
INTO :hv_doc_numero
	,:hv_doc_tipo
	,:hv_doc_fecha_emision
	,:hv_doc_periodo :s_doc_periodo
	,:hv_doc_anio :s_doc_anio
	,:hv_doc_cuota :s_doc_cuota
	,:hv_doc_tipo_origen :s_doc_tipo_origen
	,:hv_doc_numero_origen :s_doc_numero_origen
	,:hv_doc_consumo :s_doc_consumo
	,:hv_ord_numero :s_ord_numero
	,:hv_urc_codigo :s_urc_codigo
	,:hv_asi_numero :s_asi_numero
	,:hv_doc_importe
	,:hv_doc_importe_basico :s_doc_importe_basico
	,:hv_doc_saldo
	,:hv_doc_fecha_venc :s_doc_fecha_venc
	,:hv_doc_fecha_venc_1 :s_doc_fecha_venc_1
	,:hv_doc_fecha_venc_2 :s_doc_fecha_venc_2
	,:hv_doc_recargo_venc_2 :s_doc_recargo_venc_2
	,:hv_doc_fecha_venc_3 :s_doc_fecha_venc_3
	,:hv_doc_recargo_venc_3 :s_doc_recargo_venc_3
	,:hv_doc_estado
	,:hv_llamada_sit_x;
---------------------------------------------------------------
FETCH DOC
INTO :hv_doc_numero
	,:hv_doc_tipo
	,:hv_doc_fecha_emision
	,:hv_doc_periodo :s_doc_periodo
	,:hv_doc_anio :s_doc_anio
	,:hv_doc_cuota :s_doc_cuota
	,:hv_doc_tipo_origen :s_doc_tipo_origen
	,:hv_doc_numero_origen :s_doc_numero_origen
	,:hv_doc_consumo :s_doc_consumo
	,:hv_ord_numero :s_ord_numero
	,:hv_urc_codigo :s_urc_codigo
	,:hv_asi_numero :s_asi_numero
	,:hv_doc_importe
	,:hv_doc_importe_basico :s_doc_importe_basico
	,:hv_doc_saldo
	,:hv_doc_fecha_venc :s_doc_fecha_venc
	,:hv_doc_fecha_venc_1 :s_doc_fecha_venc_1
	,:hv_doc_fecha_venc_2 :s_doc_fecha_venc_2
	,:hv_doc_recargo_venc_2 :s_doc_recargo_venc_2
	,:hv_doc_fecha_venc_3 :s_doc_fecha_venc_3
	,:hv_doc_recargo_venc_3 :s_doc_recargo_venc_3
	,:hv_doc_estado
	,:hv_llamada_sit_x;
---------------------------------------------------------------
CLOSE DOC_D2
CLOSE DOC;
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Totales_Tramite----------------------------------------------
---------------------------------------------------------------
SELECT TTR_CANT_DOC --'1'
	,TTR_SUMA_DOC --'0'
	,TTR_SUMA_DEC --'0'
FROM TOTALES_TRAMITE
WHERE TRT_NUMERO = :trt_num; --'9625713' --'9740641'
---------------------------------------------------------------
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Usuarios-----------------------------------------------------
---------------------------------------------------------------
SELECT S.SCF_DESCRIPCION
FROM SUCURSALES S, USUARIOS U
WHERE U.USR_CODIGO=USER
AND   U.SCF_CODIGO=S.SCF_CODIGO
---------------------------------------------------------------   
SELECT S.SCF_DESCRIPCION --'Rosario'
FROM SUCURSALES S
INNER JOIN USUARIOS U
  ON U.SCF_CODIGO = S.SCF_CODIGO
WHERE U.USR_CODIGO = USER
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Prs_Num_Ori--------------------------------------------------
---------------------------------------------------------------
SELECT PRS_NUMERO --''
FROM CONTRATOS
WHERE CNT_NUMERO = :cnt_num_ori --''
	AND SRV_CODIGO = :srv_cod_ori --''
---------------------------------------------------------------
---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--SelectCodigoBarras-------------------------------------------
---------------------------------------------------------------

--Contiene logica backend solamente

---------------------------------------------------------------



/* ********************************************************** */



---------------------------------------------------------------
--Buscar_Codigos_Control---------------------------------------
---------------------------------------------------------------

--Esta funcion no se llama en ningun lado

SELECT TIM_CODIGO_CONTROL_1
	,TIM_CODIGO_CONTROL_2
	,TIM_CODIGO_CONTROL_3
	,TIM_CODIGO_CONTROL_4
	,TIM_CODIGO_CONTROL_5
	,TIM_CODIGO_CONTROL_6
	,TIM_CODIGO_CONTROL_7
	,TIM_CODIGO_CONTROL_8
	,TIM_CODIGO_CONTROL_9
	,TIM_CODIGO_CONTROL_10
	,TIM_CODIGO_CONTROL_11
	,TIM_CODIGO_CONTROL_12
	,TIM_CODIGO_CONTROL_13
	,TIM_CODIGO_CONTROL_14
	,TIM_CODIGO_CONTROL_15
FROM TIPOS_IMPRESORA
WHERE TIM_CODIGO = :v_tim_codigo; --'LASER'
---------------------------------------------------------------