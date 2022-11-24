#include "uiclienttcp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  UIClientTcp w;
  w.show();
  return a.exec();
}
