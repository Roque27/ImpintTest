#!/bin/sh

. /home/app_sicp_exe/vars/vars_sic.include

ALAMO_LST=.
ALAMO_BIN=..
login=lgas/taxi@sict2

./launch.sh id=${login} Tipo=CO Correo=SEND Suc=89 Sec=GESCOB Tor_codigo=I1 Ord_Dsd=11533576 Ord_Hst=11533577 User=JFANCHOV file=ALEATORIO_20183456 Reporte=DEU_3401
echo ""