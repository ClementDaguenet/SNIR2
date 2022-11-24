#include "dabclientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  DabClientWidget w;
  w.show();
  return a.exec();
}
