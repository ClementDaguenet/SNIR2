#include "sirene.h"

Sirene::Sirene()
{
  son.setSource(QUrl::fromLocalFile("../CentraleDalarme/Son/ALARME.MP3"));
}

Sirene::~Sirene()
{

}

void Sirene::Enclencher()
{
  son.play();
}
