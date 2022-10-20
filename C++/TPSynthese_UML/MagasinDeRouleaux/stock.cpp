#include "stock.h"

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
  insert(_nouveau);
}

int Stock::RechercherSerie(POSITION_STOCK &_positionDebut)
{
  POSITION_STOCK itDebut = begin();
  POSITION_STOCK itFin = begin();
  _positionDebut = itDebut;
  int retour = size();
  if (retour >=6)
    {
      retour = 6;
      for(int i = 0; i < 6; i++)
        {
          itFin++;
        }
      int difference = *itFin - *itDebut;
      while (itFin != end())
        {
          itDebut++;
          itFin++;
          int difference2 = *itFin - *itDebut;
          if (difference2 < difference)
            {
              _positionDebut = itDebut;
              difference = difference2;
            }
        }
    }
  return retour;
}

void Stock::SortirRouleau(const POSITION_STOCK _positionRouleau)
{
  erase(_positionRouleau);
}

void Stock::Visualiser() const
{
  POSITION_STOCK it;
  for (it = begin(); it != end(); it++)
    {
      it->Visualiser();
    }
}
