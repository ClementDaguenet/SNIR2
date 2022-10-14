#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H

#include "libs.h"

class AlveolesLibres : public vector<int>
{
public:
  AlveolesLibres(const int _nbRangees = 10, const int _nbColonnes = 20);
  bool Reserver(int &_rangee, int &_colonne);
  bool Liberer(const int _rangee, const int _colonne);
  void Visualiser();
private:
  int nbRangees;
  int nbColonnes;
};

#endif // ALVEOLESLIBRES_H
