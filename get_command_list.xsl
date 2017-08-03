<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE xsl:stylesheet [
<!ENTITY fl "<xsl:text>
</xsl:text>">
<!ENTITY sp "<xsl:text> </xsl:text>">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

	<xsl:output method="text" encoding="iso-8859-1" omit-xml-declaration="yes" indent="no"/>

	<xsl:param name="lote"/>		

	<xsl:preserve-space elements="*"/>

	<xsl:template match="/">
		<xsl:apply-templates select="//SqlCommand"/>
	</xsl:template>
	
	<xsl:template match="SqlCommand">
		<xsl:value-of select="@type"/><xsl:text>|</xsl:text><xsl:value-of select="@id"/>&fl;
	</xsl:template>

</xsl:stylesheet>
