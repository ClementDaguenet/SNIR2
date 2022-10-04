#include "element.h"

Element::Element(const int _vitesse):
    numero(1),
    vitesse(_vitesse)
{

}

Element::~Element()
{

}

void Element::Afficher()
{

}

int Element::getNumero() const
{
    return numero;
}

void Element::setNumero(int newNumero)
{
    numero = newNumero;
}
