#ifndef ROULEAU_H
#define ROULEAU_H

#include "libs.h"

class Rouleau
{
public:
  Rouleau(const string _reference, const int _diametre);
  Rouleau(){};
  void AffecterAlveole(const int _rangee, const int _colonne);
  void ObtenirLocalisation(int &_rangee, int &_colonne) const;
  bool operator< (const Rouleau &_autreRouleau) const;
  int operator- (const Rouleau &_autreRouleau) const;
  void Visualiser() const;
private:
  string reference;
  int diametre;
  int rangee;
  int colonne;
};

#endif // ROULEAU_H
