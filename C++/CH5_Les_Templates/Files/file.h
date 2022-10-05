#ifndef FILE_H
#define FILE_H

#include <iostream>
using namespace std;

template <typename T>
class File // Définition de la classe
{
public:
  File(const int _taille = 10);
  ~File();
  void Enfiler(const T element);
  T Defiler();
  bool FileVide();
  bool FilePleine();
private:
  int taille;
  int debut;
  int fin;
  int nbElements;
  T *laFile;
};

template<typename T>
File<T>::File(const int _taille):
  taille(_taille),
  debut(0),
  fin(0),
  nbElements(0)
{
  laFile = new T[taille];
}

template<typename T>
File<T>::~File()
{
  delete [] laFile;
}

template<typename T>
void File<T>::Enfiler(const T element)
{
  if(nbElements < taille)
    {
      laFile[debut++] = element;
      nbElements++;
    }
}

template<typename T>
T File<T>::Defiler()
{
  T retour;
  if(!FileVide())
    {
      retour = laFile[fin++];
      nbElements--;
    }
  return retour;
}

template<typename T>
bool File<T>::FileVide()
{
  bool retour = false;
  if(nbElements == 0)
    {
      retour = true;
    }
  return retour;
}

template<typename T>
bool File<T>::FilePleine()
{
  bool retour = false;
  if(nbElements == taille)
    {
      retour = true;
    }
  return retour;
}

#endif // FILE_H
