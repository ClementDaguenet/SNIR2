<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>

    <xsl:template match="tableau">
        <html>
            <head>
                <title>Top 10 JO2016</title>
                <link href="jo2016.css" type="text/css" rel="stylesheet"/>
            </head>
            <body>
                <table>
                    <tr>
                        <th>Pays</th>
                        <th>Or</th>
                        <th>Argent</th>
                        <th>Bronze</th>
                    </tr>
                    <xsl:apply-templates/>
                </table>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="ligne">
        <xsl:apply-templates/>
    </xsl:template>
    <xsl:template match="pays">
        <tr>
            <td>
                <xsl:value-of select="@nomDePays"/>
            </td>
            <xsl:apply-templates/>
        </tr>
    </xsl:template>

    <xsl:template match="medailles">
        <tr>
            <td>
                <xsl:value-of match="."/>
            </td>
            <xsl:apply-templates/>
        </tr>
    </xsl:template>

</xsl:stylesheet>
