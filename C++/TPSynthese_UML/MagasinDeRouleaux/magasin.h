#ifndef MAGASIN_H
#define MAGASIN_H

#include "libs.h"
#include "stock.h"
#include "chariot.h"

class Magasin
{
public:
  void EntrerRouleau();
  void SortirRouleaux();
  void Visualiser();
private:
  Stock leStock;
  Chariot leChariot;
  AlveolesLibres lesAlveolesLibres;
};

#endif // MAGASIN_H
