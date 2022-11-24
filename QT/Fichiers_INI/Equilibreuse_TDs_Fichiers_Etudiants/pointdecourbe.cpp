#include "pointdecourbe.h"

/**
 * @brief PointDeCourbe::PointDeCourbe
 * @param x
 * @param y
 * @details Constructeur de la classe avec paramètres
 */
PointDeCourbe::PointDeCourbe(qreal x, qreal y):
    QPointF(x,y)
{

}

/**
 * @brief PointDeCourbe::PointDeCourbe
 * @details Constructeur de la classe sans paramètre
 */
PointDeCourbe::PointDeCourbe():QPointF()
{

}

/**
 * @brief PointDeCourbe::operator <
 * @param point
 * @return booléen VRAI si P1 < P2 sinon FAUX
 * @details surcharge de l'opérateur < pour la recherche dans la QList
 */
bool PointDeCourbe::operator <(const QPointF &point)
{
    return y() < point.y();
}
