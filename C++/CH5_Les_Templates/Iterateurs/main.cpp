#include "libs.h"

int main()
{
  int taille = 0;
  cout << "Quelle taille de tableau ? : ";
  cin >> taille;
  vector <char> tableau(taille);
  for (int i = 0; i < taille; i++)
    {
      tableau[static_cast<size_t>(i)] = '!' + i;
    }
  vector<char>::iterator it;
  for (it = tableau.begin(); it != tableau.end(); it++)
    {
      cout << *it << " ";
    }
  cout << endl;
  return 0;
}
