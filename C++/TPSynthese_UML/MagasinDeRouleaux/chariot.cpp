#include "chariot.h"

void Chariot::DeplacerChariot(const bool _sens, const int _rangee, const int _colonne)
{
if (_sens==true)
  {
    cout << "Le chariot va vers le magasin et apporte le rouleau rangée n°" << _rangee << ", colonne n°" << _colonne << endl << endl;
  }
else
  {
    cout << "Le chariot va vers le stock et renvoie le rouleau rangée n°" << _rangee << ", colonne n°" << _colonne << endl << endl;
  }
}
