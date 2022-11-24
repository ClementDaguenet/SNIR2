#ifndef SIRENE_H
#define SIRENE_H

#include <QMediaPlayer>

class Sirene
{
public:
  Sirene();
  ~Sirene();
  void Enclencher();
private:
  QMediaPlayer son;
};

#endif // SIRENE_H
