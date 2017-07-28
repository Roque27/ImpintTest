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
Archivo=
Reporte=
Incobrables=
Usuario=
Impresora=
TipoCorreo=
Correo=
TorCodigo=
Suc=
Sec=
OrdDesde=
OrdHasta=

cat > ${Fichero}.param.xml <<EOF
<?xml version="1.0" encoding="iso-8859-1" standalone="no" ?>
<IMPINT_PARAM>
    <NOMBREARCHIVO PARAMFILE="ALEATORIO_19688046"/>
    <REPORTE PARAMREPCODIGO="DEU_3401"/>
    <INCOBRABLES PARAMINCOBRABLES="S"/>
    <USER PARAMUSER="ASOSA"/>
    <PRINT PARAMIMPR="1"/>
    <TIPOCORREO PARAMCODTIPOCORREO="CO"/>
    <CORREO PARAMCODCORREO="SEND"/>
    <TOR_CODIGO PARAMTORCOD="I1"/>
    <SUC PARAMSUC="12"/>
    <SEC PARAMSEC="GESCOB"/>
    <ORD_DESDE PARAMORDDSD="11259135"/>
    <ORD_HASTA PARAMORDHST="11259135"/>
</IMPINT_PARAM>
EOF

#<ORD_HASTA PARAMORDHST="11260163"/>

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