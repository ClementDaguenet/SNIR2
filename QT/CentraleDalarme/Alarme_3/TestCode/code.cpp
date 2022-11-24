#include "code.h"

Code::Code(const int _tailleCode):
  tailleCode(_tailleCode)
{
  codeUsine = new quint8(tailleCode);
  codeUtilisateur = new quint8(tailleCode);
  for(int i = 0; i < tailleCode; i++)
    {
      codeUsine[i] = i + 1;
      codeUtilisateur[i] = 0;
    }
}

Code::~Code()
{
  delete[] codeUsine;
  delete[] codeUtilisateur;
}

bool Code::VerifierCode(const quint8 unCode[])
{
  bool retour = true;
  for(int i = 0; i < tailleCode; i++)
    {
      if(unCode[i] != codeUsine[i] && unCode[i] != codeUtilisateur[i])
        {
          retour = false;
        }
    }
  return retour;
}

void Code::Memoriser(const quint8 unCode[])
{
  for(int i = 0; i < tailleCode; i++)
    {
      codeUtilisateur[i] = unCode[i];
    }
}
