#!/bin/sh

Archivo=impint_doc
Login=lgas/taxi@sict2
Salida=${Archivo}.out.xml
Parametro=${Archivo}.param.xml
Ejecutable=${Archivo}.xml

> ${Salida}

cat > ${Archivo}.param.xml <<EOF
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

../Ora2Xml -user=lgas/taxi@sict2 -wenc=iso-8859-1 -ofile=${Salida} ${Ejecutable} ${Parametro}
cat ${Salida} | ./XMLD
echo ""