#include "serveurmultiwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ServeurMultiWidget w;
  w.show();
  return a.exec();
}
