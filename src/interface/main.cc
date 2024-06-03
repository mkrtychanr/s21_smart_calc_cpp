#include <QApplication>

#include "calculator.h"
#include "graphic.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Calculator w;
  w.show();
  return a.exec();
}
