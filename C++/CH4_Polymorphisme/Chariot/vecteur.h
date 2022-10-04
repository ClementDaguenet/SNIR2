#ifndef VECTEUR_H
#define VECTEUR_H

#include "libs.h"

class Vecteur
{
public:
    Vecteur(const double _x, const double _y);
    Vecteur operator+ (const Vecteur & _autre);
    Vecteur operator- (const Vecteur & _autre);
    void Afficher();
    double getX() const;
    void setX(double newX);
    double getY() const;
    void setY(double newY);
protected :
    double x ;
    double y ;
};

#endif // VECTEUR_H
