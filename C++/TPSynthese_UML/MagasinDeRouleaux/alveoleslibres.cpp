#include "alveoleslibres.h"

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
  nbRangees(_nbRangees),
  nbColonnes(_nbColonnes)
{
  for(int i = 1; i <= nbRangees * nbColonnes; i++)
    {
      push_back(i);
    }
}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{
  bool retour = true;
  if (empty())
    {
      retour = false;
    }
  else
    {
      int numAlveole = back();
      _rangee = ((numAlveole-1) / nbColonnes)+1;
      _colonne = ((numAlveole-1) % nbColonnes)+1;
      pop_back();
    }
  return retour;
}

bool AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
  bool retour = true;
  if (_rangee < nbRangees && _colonne < nbColonnes)
    {
      retour = false;
    }
  else
    {
      if(find(begin(),end(), (_rangee-1) * nbColonnes + _colonne) != end())
        {
          retour = false;
        }
      else
        {
          push_back((_rangee-1) * nbColonnes + _colonne);
        }
    }
  return retour;
}

void AlveolesLibres::Visualiser()
{
  vector<int>::iterator it;
  cout << " |";
  for (it = begin(); it != end(); it++)
    {
      cout << setw(3) << *it << " |";
    }
  cout << endl;
}
