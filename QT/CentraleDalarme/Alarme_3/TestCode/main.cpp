#include "code.h"

#define TAILLE_CODE 4

int main()
{
  quint8 code[TAILLE_CODE];
  Code leCode(TAILLE_CODE);
  cout << "Code ? : ";
  for(int i = 0; i < TAILLE_CODE; i ++)
    {
      cin >> code[i];
      code[i] -= '0';
    }
  if(leCode.VerifierCode(code) == true)
    {
      cout << "Bon code !" << endl;
    }
  cout << "Nouveau code ? : ";
  for(int i = 0; i < TAILLE_CODE; i ++)
    {
      cin >> code[i];
      code[i] -= '0';
    }
  leCode.Memoriser(code);
  cout << "Code ? : ";
  for(int i = 0; i < TAILLE_CODE; i ++)
    {
      cin >> code[i];
      code[i] -= '0';
    }
  if(leCode.VerifierCode(code) == true)
    {
      cout << "Bon code !" << endl;
    }
  return 0;
}
