#!/bin/sh

export NLS_LANG=AMERICAN_AMERICA.WE8ISO8859P1

# FICHEROS USADOS EN EL PROCESO
Fichero=${ALAMO_LST}/impint_doc$$
Parametro=${Fichero}.param.xml
Ejecutable=impint_doc.xml
Intermedia=${Fichero}.media.xml
Salida=${Fichero}.out.xml
QueryInsert=${Fichero}.insert.xml
QueryUpdate=${Fichero}.update.xml
QueryExecute=${Fichero}.execute.sql
SalidaExecute=0
QueryLog=${Fichero}.logsql.xml
XslAvisoDeuda=get_aviso_deuda.xsl
SalidaXalan=xalan.out.lst

> ${Salida}
> ${QueryInsert}
> ${QueryUpdate}
> ${QueryExecute}
> ${QueryLog}

# ARGUMENTOS DEL PROCESO

Id=" "
Archivo=" "
Reporte=" "
Incobrables="N"
Usuario=""
Impresora=" "
TipoCorreo=" "
Correo=" "
TorCodigo=" "
Suc=0
Sec=" "
OrdDesde=0
OrdHasta=0
FechaEmision=$(date +%d-%m-%Y)

# CARGA DE ARGUMENTOS VARIABLES

while [ "$1" != "" ]
do
	#echo PARAM: $1
	argumento=$(echo $1 | cut -d"=" -f1)
	valor=$(echo $1 | cut -d"=" -f2)

  case ${argumento} in
	id) #echo 'Id: ' ${valor};
		Id=${valor}
		;;
  file) #echo 'Archivo: ' ${valor};
		Archivo=${valor}
    ;;
	Reporte) #echo 'Reporte: ' ${valor};
		Reporte=${valor}
    ;;
	INCOBRABLES) #echo 'Incobrables: ' ${valor};
		Incobrables=${valor}
    ;;
	User) #echo 'Usuario: ' ${valor};
		Usuario=${valor}
    ;;
	impr) #echo 'Impresora: ' ${valor};
		Impresora=${valor}
    ;;
	Tipo) #echo 'TipoCorreo: ' ${valor};
		TipoCorreo=${valor}
    ;;
	Correo) #echo 'Correo: ' ${valor};
		Correo=${valor}
    ;;
	Tor_codigo) #echo 'TorCodigo: ' ${valor};
		TorCodigo=${valor}
    ;;
	Suc) #echo 'Suc: ' ${valor};
		Suc=${valor}
    ;;
	Sec) #echo 'Sec: ' ${valor};
		Sec=${valor}
    ;;
	Ord_Dsd) #echo 'OrdDesde: ' ${valor};
		OrdDesde=${valor}
		if [ ${OrdDesde} -gt ${OrdHasta} ]; then
		  OrdHasta=${OrdDesde}
		fi
    ;;
	Ord_Hst) #echo 'OrdHasta: ' ${valor};
		OrdHasta=${valor}
		if [ ${OrdDesde} -gt ${OrdHasta} ]; then
		  OrdDesde=${OrdHasta}
		fi
    ;;
	Fecha_Emision) #echo 'FechaEmision: ' ${valor};
		FechaEmision=${valor}
    ;;
  esac
  shift
done

cat > ${Parametro} <<EOF
<?xml version="1.0" encoding="iso-8859-1" standalone="no" ?>
<IMPINT_PARAM>
    <NOMBREARCHIVO PARAMFILE="${Archivo}"/>
    <REPORTE PARAMREPCODIGO="${Reporte}"/>
    <INCOBRABLES PARAMINCOBRABLES="${Incobrables}"/>
    <USER PARAMUSER="${Usuario}"/>
    <PRINT PARAMIMPR="${Impresora}"/>
    <TIPOCORREO PARAMCODTIPOCORREO="CO"/>
    <CORREO PARAMCODCORREO="${Correo}"/>
    <TOR_CODIGO PARAMTORCOD="${TorCodigo}"/>
    <SUC PARAMSUC="${Suc}"/>
    <SEC PARAMSEC="${Sec}"/>
    <ORD_DESDE PARAMORDDSD="${OrdDesde}"/>
    <ORD_HASTA PARAMORDHST="${OrdHasta}"/>
		<FECHA_EMISION PARAMFECEMI="${FechaEmision}"/>
</IMPINT_PARAM>
EOF

if [ ${TorCodigo} == 'I1' ] 
then

	$ALAMO_BIN/Ora2Xml -user=${Id} -wenc=iso-8859-1 -ofile=${Intermedia} ${Ejecutable} ${Parametro}
	if [ $? -ne 0 ] 
	then
		echo "ERROR EN PROCESO GENERACION DEL XML DE IMPINT"
		exit 2
	fi

	cat ${Intermedia} | ./XMLD > ${Salida}
	echo ""

	echo "BEGIN " >> ${QueryExecute}
	for key in `xalan -in ${Salida} -xsl get_command_list.xsl`
	do
		command=`echo ${key} | cut -d"|" -f1`
		id=`echo ${key} | cut -d"|" -f2`
		#echo ${command}
		#echo ${id}
		case ${command} in
			INSERT)
				echo "================= INSERT QUERY ==================================================="
				xalan -param id "'${id}'" -in ${Salida} -xsl get_command.xsl -out ${QueryInsert}
				cat ${QueryInsert} >> ${QueryExecute}
				echo ""
				;;
			UPDATE)
				echo "================= UPDATE QUERY ==================================================="
				xalan -param id "'${id}'" -in ${Salida} -xsl get_command.xsl -out ${QueryUpdate}
				cat ${QueryUpdate} >> ${QueryExecute}
				echo ""		
				;;
	    EXECUTESQL)
				echo "================= EXECUTESQL ====================================================="
				# ----------------------------------------------------------------------------------------
				echo "exception when others then ROLLBACK; dbms_output.put_line('ERROR en Exception'); end;" >> ${QueryExecute}

				sqlplus -s lgas/taxi@sict2 <<EOF >${QueryLog} 2>&1 
				set serveroutput on size 20000 
				whenever sqlerror exit 2; 
				whenever oserror exit 2; 

				@${QueryExecute}
				/
				quit
EOF

				if [ $? -ne 0 ]     # codigo de retorno del sqlplus 
	 				then 
	   				echo "ERROR en Proceso" >> ${QueryLog}
				fi 
				# ----------------------------------------------------------------------------------------

				SalidaExecute=`grep ERROR ${QueryLog} | wc -l`

				if [ ${SalidaExecute} -gt 0 ]
				then
					SalidaExecute=`expr $SalidaExecute - 1`
				fi

				if [ ${SalidaExecute} -eq 0 ]
				then
					SalidaExecute=`grep unknown ${QueryLog} | wc -l`
				fi
				;;
			*)
				echo "ERROR NO SE PUDO DETERMINAR EL TIPO DE COMANDO"
	 			exit 2
				;;
		esac
	done

	#echo ""
	#echo "Codigo Analizado de salida 2: "	
	#echo ${SalidaExecute}
	#echo ""
	#echo "Codigo de salida 2: "	
	#echo $?
	#echo ""
	#echo ""
fi
	if [ ${SalidaExecute} != 0 ]
	then
		echo ""
		echo "Ha ocurrido un error en el proceso"
		echo "Log del proceso: "
		echo ""
		cat ${QueryLog} | head -1
		echo ""

		exit 2
	else
		# I1 = AVISO DEUDA COMUN BAJO FIRMA
		# I4 = AVISO DEUDA COMUN BAJO FIRMA
		# C2 = Cierre c/dispositivo seguridad (cepo) p/gestión deuda
		# C3 = Corte c/retiro de medidor p/gestión deuda
		# D2 = Rechazo cobranza por débito automático
		# G1 = Intimación Grandes Clientes 48 horas

		case ${TorCodigo} in
			I1)
				echo "============== Aviso Deuda comun bajo firma =============="
				xalan -in ${Salida} -xsl ${XslAvisoDeuda} | tr "~" "\033" | tr "^" "\014" > ${SalidaXalan}
				echo "Finalizo correctamente"
				echo ""
				;;

			#Esto no va aca va mas arriba!!	
			I4)
				echo "============== Aviso Deuda comun bajo firma =============="
				impint id=${Id} Tipo=${TipoCorreo} Correo=${Correo} Suc=${Suc} Sec=${Sec} Tor_codigo=${TorCodigo} Ord_Dsd=${OrdDesde} Ord_Hst=${OrdHasta} User=${Usuario} file=${Archivo} Reporte=${Reporte} impresora=${Impresora}
				;;
		  C2)
				echo "============== Cierre c/dispositivo seguridad (cepo) p/gestión deuda =============="
				impint.exe id=${Id} Tipo=${TipoCorreo} Correo=${Correo} Suc=${Suc} Sec=${Sec} Tor_codigo=${TorCodigo} Ord_Dsd=${OrdDesde} Ord_Hst=${OrdHasta} User=${Usuario} file=${Archivo} Reporte=${Reporte} impresora=${Impresora}
				;;
			C3)
				echo "============== Corte c/retiro de medidor p/gestión deuda =============="
				impint.exe id=${Id}Tipo=${TipoCorreo}CN Correo=${Correo} Suc=${Suc} Sec=${Sec} Tor_codigo=${TorCodigo} Ord_Dsd=${OrdDesde} Ord_Hst=${OrdHasta} User=${Usuario} file=${Archivo} Reporte=${Reporte} impresora=${Impresora}
				;;
			D2)
				echo "============== Rechazo cobranza por débito automático =============="
				impint.exe id=${Id} Tipo=${TipoCorreo} Correo=${Correo} Suc=${Suc} Sec=${Sec} Tor_codigo=${TorCodigo} Ord_Dsd=${OrdDesde} Ord_Hst=${OrdHasta} User=${Usuario} file=${Archivo} Reporte=${Reporte} impresora=${Impresora}
				;;
			G1)
				echo "============== Intimación Grandes Clientes 48 horas =============="
				impint.exe id=${Id} Tipo=${TipoCorreo} Correo=${Correo} Suc=${Suc} Sec=${Sec} Tor_codigo=${TorCodigo} Ord_Dsd=${OrdDesde} Ord_Hst=${OrdHasta} User=${Usuario} file=${Archivo} Reporte=${Reporte} impresora=${Impresora}
				;;
			*)
				echo "ERROR NO SE PUDO DETERMINAR EL TIPO DE REPORTE A IMPRIMIR"
		 		exit 2
				;;
		esac
	fi
