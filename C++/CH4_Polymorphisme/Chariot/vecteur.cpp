#include "vecteur.h"

Vecteur::Vecteur(const double _x, const double _y):
    x(_x),
    y(_y)
{

}

Vecteur Vecteur::operator+(const Vecteur &_autre)
{
    Vecteur plus(x+_autre.x,y+_autre.y);
    return plus;
}

Vecteur Vecteur::operator-(const Vecteur &_autre)
{
    Vecteur moins(x-_autre.x,y-_autre.y);
    return moins;
}

void Vecteur::Afficher()
{
    cout << "Vecteur en (" << x << ", " << y << ")" << endl ;
}

double Vecteur::getX() const
{
    return x;
}

void Vecteur::setX(double newX)
{
    x = newX;
}

double Vecteur::getY() const
{
    return y;
}

void Vecteur::setY(double newY)
{
    y = newY;
}
