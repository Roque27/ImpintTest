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

	<xsl:preserve-space elements="*"/>

  <xsl:template match="/">
    <xsl:apply-templates select="raiz/Main"/>


  </xsl:template>

  <xsl:template match="Main">
  LITORAL GAS S.A.
  AVISO DE DEUDA COMUN BAJO FIRMA
  <xsl:value-of select="notificacion/persona/@prs_numero"/>&fl;

  </xsl:template>

</xsl:stylesheet>