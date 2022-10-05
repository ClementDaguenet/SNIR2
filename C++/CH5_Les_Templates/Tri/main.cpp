#include "libs.h"

void AfficherValeur(int val);

int main()
{
  int val1 = 0;
  cout << "Val 1 ? : ";
  cin >> val1;
  int val2 = 0;
  cout << "Val 2 ? : ";
  cin >> val2;
  int val3 = 0;
  cout << "Val 3 ? : ";
  cin >> val3;
  int val4 = 0;
  cout << "Val 4 ? : ";
  cin >> val4;
  int val5 = 0;
  cout << "Val 5 ? : ";
  cin >> val5;
  system("clear");

  array <int, 5> tableau1 = {val1, val2, val3, val4, val5};
  cout << "Tableau d'origine : ";
  for_each (tableau1.begin(), tableau1.end(), AfficherValeur);
  cout << endl;

  cout << "Tableau trié      : ";
  sort(tableau1.begin(), tableau1.end());
  for_each (tableau1.begin(), tableau1.end(), AfficherValeur);
  cout << endl;
  return 0;
}
void AfficherValeur(int val)
{
  cout << setw(3) << val;
}
