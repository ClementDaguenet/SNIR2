#include "file.h"

int main()
{
  int tailleE = 0;
  int tailleC = 0;
  cout << "Quelle taille de file d'entiers ? : ";
  cin >> tailleE;
  cout << "Quelle taille de file de caractères ? : ";
  cin >> tailleC;
  system("clear");

  cout << "Voici une file d'entiers : " << endl;
  File<int> file1(tailleE);
  for (int indice = 0; indice < tailleE; indice++)
    {
      file1.Enfiler(indice);
    }
  for (int indice = 0; indice < tailleE; indice++)
    {
      cout << file1.Defiler() << " ";
    }
  cout << endl;

  cout << endl << "Voici une file de caractères : " << endl;
  File<char> file2(tailleC);
  for (int indice = 0; indice < tailleC; indice++)
    {
      file2.Enfiler('A' + static_cast<char>(indice));
    }
  for (int indice = 0; indice < tailleC ;indice++)
    {
      cout << file2.Defiler() << " ";
    }
  cout << endl << endl;
  return 0;
}
