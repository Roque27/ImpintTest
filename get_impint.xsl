<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE xsl:stylesheet
[
<!ENTITY fl "<xsl:text>
</xsl:text>">
<!ENTITY sp "<xsl:text> </xsl:text>">
<!ENTITY deg "&#176;">
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

<xsl:for-each select="//Reporte">

<!--
I1 = AVISO DEUDA COMUN BAJO FIRMA
I4 = AVISO DEUDA COMUN BAJO FIRMA
C2 = Cierre c/dispositivo seguridad (cepo) p/gestión deuda
C3 = Corte c/retiro de medidor p/gestión deuda
D2 = Rechazo cobranza por débito automático
G1 = Intimación Grandes Clientes 48 horas
-->

<xsl:if test="@tipo = 'I1'"><xsl:apply-templates select="[@tipo = 'I1']"/></xsl:if>

<xsl:template match="Informe">

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
<xsl:value-of select="//ordenativo/@fecha_generacion"/>&fl;
Domic.Suministro:   
<xsl:value-of select="//servicio/srv_direccion/@calle"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@nro"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@depto"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@piso"/>&sp;<xsl:value-of select="//servicio/srv_direccion/@torre"/>&sp;(<xsl:value-of select="//servicio/srv_direccion/@cod_postal"/>)&sp;<xsl:value-of select="//servicio/srv_direccion/@area_geografica"/>&fl;
CONTRATO:   
<xsl:value-of select="//contrato/@srv_cod"/>&fl;

COMPROBANTE &sp;&sp;&sp;&sp;&sp;&sp;&sp;&sp;&sp; FECHA VTO. &sp;&sp;&sp;&sp; SALDO DEUDOR
<xsl:for-each select="notificacion/documento/item">
  <xsl:value-of select="@tipo"/>&sp;&sp;&sp;<xsl:value-of select="@numero"/>&sp;&sp;&sp;&sp;<xsl:value-of select="@fecha_venc_1"/>&sp;&sp;&sp;&sp;<xsl:value-of select="@saldo"/>&fl;
</xsl:for-each>

TOTAL A PAGAR HASTA EL XX/XX/XXXX

Saldo:	
<xsl:value-of select="notificacion/documento/@saldo_total"/>&fl;

Codigo de barras Litoral:   
<xsl:value-of select="codigoBarras/@barras_litoral"/>&fl;

Texto 2:  
<xsl:value-of select="notificacion/@eno_texto"/>&fl;

Emisor: 
<xsl:value-of select="//servicio/@scf_codigo"/>- <xsl:value-of select="notificacion/sucursal/@descripcion"/>&fl;

Codigo de barras correo:   
<xsl:value-of select="codigoBarras/@barras_correo"/>&fl;

</xsl:for-each>

</xsl:template>

</xsl:template>

</xsl:stylesheet>