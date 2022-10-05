#include "file.h"

int main()
{
  int taille = 0;
  cout << "Quelle taille de file ? : ";
  cin >> taille;
  system("clear");

  cout << "Voici une file d'entiers : " << endl;
  File<int> file1(taille);
  for (int indice = 0; indice < taille; indice++)
    {
      file1.Enfiler(indice);
    }
  for (int indice = 0; indice < taille; indice++)
    {
      cout << file1.Defiler() << " ";
    }
  cout << endl;

  cout << endl << "Voici une file de caractères : " << endl;
  File<char> file2(taille);
  for (int indice = 0; indice < taille; indice++)
    {
      file2.Enfiler('A' + static_cast<char>(indice));
    }
  for (int indice = 0; indice < taille ;indice++)
    {
      cout << file2.Defiler() << " ";
    }
  cout << endl << endl;
  return 0;
}
