#ifndef VUEGRAPHIQUE_H
#define VUEGRAPHIQUE_H

#include <QtCharts>
#include "experience.h"

class VueGraphique : public QChart
{

public:
    explicit VueGraphique(Experience *_ptrExperience, QChart *parent = nullptr);
    ~VueGraphique();
    QChart   *DessinerCourbes();

private:
    QSplineSeries *courbeA;     /// Pointeur sur la courbe A  (coté graphique)
    QSplineSeries *courbeO;     /// Pointeur sur la courbe O  (coté graphique)
    QList<QPointF> *pointsDeA;  /// Liste des points de la courbes A
    QList<QPointF> *pointsDeO;  /// Liste des points de la courbes O
    Experience *experience;  /// Pointeur sur l'expérience courante
    bool newton; /// Indique si la courbe est en Newton(VRAI) ou en Volt(FAUX)
    bool degre;  /// Indique si la courbe est fonction de la position angulaire(VRAI) ou points du codeur(FAUX)
};

#endif // VUEGRAPHIQUE_H
