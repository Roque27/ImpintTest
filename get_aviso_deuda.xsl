<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE xsl:stylesheet
[
<!ENTITY fl "<xsl:text>
</xsl:text>">
<!ENTITY sp "<xsl:text> </xsl:text>">
<!ENTITY deg "&#176;">
<!ENTITY lowb "&#95;">
<!ENTITY acute "&#225;">
<!ENTITY icute "&#237;">
<!ENTITY uicute "&#205;">
<!ENTITY ocute "&#243;">
]>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output
		method="text"
		encoding="iso-8859-1"
		omit-xml-declaration="yes"
		indent="no"/>

<xsl:param name="lote"/>		

<xsl:preserve-space elements="*"/>

<xsl:template match="/">
&fl;
	<xsl:apply-templates select="Impint/Reporte[@tipo = 'I1']"/>
</xsl:template>

<!--
I1 = AVISO DEUDA COMUN BAJO FIRMA
I4 = AVISO DEUDA COMUN BAJO FIRMA
C2 = Cierre c/dispositivo seguridad (cepo) p/gestión deuda
C3 = Corte c/retiro de medidor p/gestión deuda
D2 = Rechazo cobranza por débito automático
G1 = Intimación Grandes Clientes 48 horas
-->
<xsl:template match="Reporte">
LITORAL GAS S.A.&fl;
AVISO DE DEUDA COMUN BAJO FIRMA&fl;
<xsl:value-of select="//ordenativo/@descripcion"/>&fl;
Razon Social:   
<xsl:value-of select="notificacion/persona/@razon_social"/>&fl;
N&deg; AVISO:&fl;
<xsl:value-of select="//ordenativo/@nro_ord"/>&fl;
Domic.Contrato:  
<xsl:value-of select="//contrato/srv_direccion/@calle"/>&sp;<xsl:value-of select="//contrato/srv_direccion/@nro_pago"/>&sp;(<xsl:value-of select="//contrato/srv_direccion/@cod_postal_pago"/>)&sp;<xsl:value-of select="//contrato/srv_direccion/@area_geografica"/>&fl;
FECHA EMISION:  
<xsl:value-of select="@fecha_emision"/>&fl;
Domic.Suministro:&sp;<xsl:value-of select="//servicio/srv_direccion/@calle"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@nro"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@depto"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@piso"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@torre"/>&sp;(<xsl:value-of select="//servicio/srv_direccion/@cod_postal"/>)&sp;<xsl:value-of select="//servicio/srv_direccion/@area_geografica"/>&fl;
CONTRATO:   
<xsl:value-of select="//contrato/@srv_cod"/>&fl;

Texto 1 [4 lineas maximo]:
Sr. Cliente: Le comunicamos que a la fecha del presente Aviso, registra deuda vencida con esta
Distribuidora de acuerdo al siguiente detalle, el cual incluye cobranzas en entidades recauda-
doras hasta el XX/XX/XXXX (inclusive). Si Ud. cancel&ocute; su deuda hasta el d&icute;a h&acute;bil anterior
(inclusive) a la fecha de recepci&ocute;n de este Aviso, le rogamos desestimarlo.&fl;

Items [30 lineas maximo]:
COMPROBANTE &sp;&sp;&sp;&sp;&sp;&sp;&sp;&sp;&sp; FECHA VTO. &sp;&sp;&sp;&sp; SALDO DEUDOR
<xsl:apply-templates select="notificacion/documento/item"/>
<!--
<xsl:for-each select="notificacion/documento/item">
  <xsl:value-of select="@tipo"/>&sp;&sp;&sp;<xsl:value-of select="@numero"/>&sp;&sp;&sp;&sp;<xsl:value-of select="@fecha_venc_1"/>&sp;&sp;&sp;&sp;<xsl:value-of select="@saldo"/>&fl;
</xsl:for-each>-->

TOTAL A PAGAR HASTA EL XX/XX/XXXX

Saldo:	
<xsl:value-of select="notificacion/documento/@saldo_total"/>&fl;

Codigo de barras Litoral:   
<xsl:value-of select="codigoBarras/@barras_litoral"/>&fl;
<xsl:value-of select="codigoBarras/@barras_litoral_codigo"/>&fl;
Aviso: <xsl:value-of select="//ordenativo/@nro_ord"/>&fl;
Contrato: <xsl:value-of select="//contrato/@srv_cod"/>&fl;
Emisor: <xsl:value-of select="//servicio/@scf_codigo"/>- <xsl:value-of select="notificacion/sucursal/@descripcion"/>&fl;
Fecha: <xsl:value-of select="@fecha_emision"/>&fl;

TALON DE CONTROL
Codigo de barras correo:   
<xsl:value-of select="codigoBarras/@barras_correo"/>&fl;
<xsl:value-of select="codigoBarras/@barras_correo_codigo"/>&fl;
Texto 2 [25 lineas maximo]:
<xsl:value-of select="notificacion/texto_notificacion[1]/@eno_texto"/>

<xsl:value-of select="notificacion/texto_notificacion[2]/@eno_texto"/>&fl;

<xsl:variable
name="Texto2_1_lineas"
select="(string-length(notificacion/texto_notificacion[1]/@eno_texto) - string-length(translate(notificacion/texto_notificacion[1]/@eno_texto, '&#xD;&#xA;', ''))) + 1"/>

<xsl:variable
name="Texto2_2_lineas"
select="(string-length(notificacion/texto_notificacion[2]/@eno_texto) - string-length(translate(notificacion/texto_notificacion[2]/@eno_texto, '&#xD;&#xA;', ''))) + 1"/>

<xsl:for-each select="(//node())[(26 - ($Texto2_1_lineas + $Texto2_2_lineas)) >= position()]">
&fl;
</xsl:for-each>

LowBar:
&lowb;&lowb;

Corchetes:
[&sp;&sp;]

INCIDENCIA
No Recibe
Desconocido
Mud&ocute;se
Firma disuelta
Ausente, bajo puerta
Fallecido

FECHA:
HORA:
CAMINANTE:
FIRMA:

TRES CARACTER&uicute;STICAS DE LA VIVIENDA
1.
2.
3.

^
</xsl:template>

<xsl:template match="item">
<xsl:value-of select="@tipo"/>&sp;&sp;&sp;<xsl:value-of select="@numero"/>&sp;&sp;&sp;<xsl:value-of select="@fecha_venc_1"/>&sp;&sp;&sp;<xsl:value-of select="@saldo"/>&fl;
</xsl:template>

</xsl:stylesheet>