<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE xsl:stylesheet [
<!ENTITY fl "<xsl:text>
</xsl:text>">
<!ENTITY sp "<xsl:text> </xsl:text>">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

    <xsl:output method="xml" indent="yes" omit-xml-declaration="yes"/>

	<xsl:param name="id"/>		

	<xsl:preserve-space elements="*"/>

    <xsl:template match="/">
        <xsl:copy-of select="//SqlCommand[@id=$id]/node()"/>
    </xsl:template>
</xsl:stylesheet>

