<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>
    <xsl:template match="bibliotheque">
        <html>
            <head>
                <title>Bibliothèque</title>
                <link href="bibliotheque.css" type="text/css" rel="stylesheet"/>
            </head>
            <body>
                <xsl:apply-templates/>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="allee">
        <hr/>
        <h1>Allée
            <xsl:value-of select="@numeroAllee"/>
        </h1>
        <hr/>
        <xsl:apply-templates/>
    </xsl:template>
    <xsl:template match="rayon">
        <h3>Rayon
            <xsl:value-of select="@numeroRayon"/>
        </h3>
        <table>
            <tr>
                <th>Catégorie de l'ouvrage</th>
                <th>Titre</th>
                <th>Auteur</th>
                <th>Numéro</th>
            </tr>
            <xsl:apply-templates/>
        </table>
    </xsl:template>
    <xsl:template match="ouvrage">
        <tr>
            <td>
                <xsl:value-of select="@typeOuvrage"/>
            </td>
            <xsl:apply-templates/>
        </tr>
    </xsl:template>

    <xsl:template match="titre">
        <td class="titre">
            <xsl:value-of select="."/>
        </td>
        <xsl:if test="../auteur = false()">
            <td class="noauthor"></td>
            <xsl:if test="../numeroOuvrage = false()">
                <td class="nonum"></td>
            </xsl:if>
        </xsl:if>
    </xsl:template>

    <xsl:template match="auteur">
        <td class="auteur">
            <xsl:value-of select="."/>
        </td>
        <xsl:if test="../numeroOuvrage = false()">
            <td class="nonum"></td>
        </xsl:if>
    </xsl:template>

    <xsl:template match="numeroOuvrage">
        <td class="numeroOuvrage">
            <xsl:value-of select="."/>
        </td>
    </xsl:template>

</xsl:stylesheet>
