#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Maze maze;
  Cave cave;
  Controller controller(&maze, &cave);
  View main_window(&controller);
  main_window.show();
  return a.exec();
}
