<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE xsl:stylesheet
[
<!ENTITY fl "<xsl:text>
</xsl:text>">
<!ENTITY sp "<xsl:text> </xsl:text>">
]>

<xsl:stylesheet version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output
		method="text"
		encoding="iso-8859-1"
		omit-xml-declaration="yes"
		indent="no"/>

	<xsl:param name="lote"/>		

	<xsl:preserve-space elements="*"/>

  <xsl:template match="/">

  <xsl:for-each select="//Reporte">

  LITORAL GAS S.A.&fl;
  AVISO DE DEUDA COMUN BAJO FIRMA&fl;
  Razon Social:   <xsl:value-of select="codigoBarras/@barras"/>

    <xsl:for-each select="//Reporte">

    

    </xsl:for-each>

  Codigo de barras:  <xsl:value-of select="codigoBarras/@barras"/>

  </xsl:for-each>

  </xsl:template>

</xsl:stylesheet>

