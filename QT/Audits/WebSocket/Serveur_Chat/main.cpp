#include "interfaceserveurchat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  InterfaceServeurChat w;
  w.show();
  return a.exec();
}
