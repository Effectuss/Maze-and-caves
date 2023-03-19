#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ParsingMazeFile parsing_maze_file;
  Controller controller(&parsing_maze_file);
  View main_window(&controller);
  main_window.show();
  return a.exec();
}
