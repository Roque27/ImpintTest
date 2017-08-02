#!/bin/sh

. /home/app_sicp_exe/vars/vars_sic.include

# FICHEROS USADOS EN EL PROCESO
Fichero=impint_doc
Login=lgas/taxi@sict2
Parametro=${Fichero}.param.xml
Ejecutable=${Fichero}.xml
Salida=${Fichero}.out.xml
QueryInsert=${Fichero}.insert.xml
QueryUpdate=${Fichero}.update.xml
QueryExecute=${Fichero}.execute.xml

> ${Salida}
> ${QueryInsert}
> ${QueryUpdate}
> ${QueryExecute}

# ARGUMENTOS DEL PROCESO

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

# CARGA DE ARGUMENTOS VARIABLES

while [ "$1" != "" ]
do
	#echo PARAM: $1
	argumento=$(echo $1 | cut -d"=" -f1)
	valor=$(echo $1 | cut -d"=" -f2)

  case ${argumento} in
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
  esac
  shift
done

cat > ${Fichero}.param.xml <<EOF
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
</IMPINT_PARAM>
EOF

../Ora2Xml -user=lgas/taxi@sict2 -wenc=iso-8859-1 -ofile=${Salida} ${Ejecutable} ${Parametro}
#cat ${Salida} | ./XMLD
echo ""

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
			echo quit >> ${QueryExecute}
			cat ${QueryExecute}
			#echo exit | sqlplus -s lgas/taxi@sict2 @${QueryExecute}
			;;
		*)
			echo "ERROR NO SE PUDO DETERMINAR EL TIPO DE COMANDO"
 			exit 1
			;;
	esac
done

echo ""