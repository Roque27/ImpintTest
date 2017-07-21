#
# IMPINT:
#
# Para convocar batch
#
# Para Oracle
#
export NLS_LANG=AMERICAN_AMERICA.WE8ISO8859P1
#
Login=lgas/taxi@sict2
Archivo=impint_doc
Ejecutable=impint.xml

cat > ${Archivo}.param.xml <<EOF
<?xml version="1.0" encoding="iso-8859-1" standalone="no" ?>
<IMPINT_PARAM>
    <NOMBREARCHIVO PARAMFILE="">
    <REPORTE PARAMREPCODIGO="">
    <INCOBRABLES PARAMINCOBRABLES="S">
    <USER PARAMUSER="RCITTADI">
    <PRINT PARAMIMPR="1">
    <TIPOCORREO PARAMCODTIPOCORREO="CO">
    <CORREO PARAMCODCORREO="BR">
    <TOR_CODIGO PARAMTORCOD="I1">
    <SUC PARAMSUC="12">
    <SEC PARAMSEC="GESCOB">
    <ORD_DESDE PARAMORDDSD="10769681">
    <ORD_HASTA PARAMORDHST="10769681">
</IMPINT_PARAM>
EOF

../Ora2Xml -user=${login} -wenc=iso-8859-1 -ofile=${Archivo}.out.xml ${Ejecutable} ${Archivo}.param.xml
cat ${Archivo}.out.xml | ./XMLD
 echo ""