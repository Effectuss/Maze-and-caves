#ifndef MAZE_AND_CAVES_CONTROLLER_H_
#define MAZE_AND_CAVES_CONTROLLER_H_

#include <iostream>
#include <string>

#include "maze.h"

class Controller {
 public:
  using Matrix = std::vector<std::vector<unsigned short> >;

  Controller(Maze* maze);
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  void ParsingFileMaze(const std::string& path_file);
  Matrix& GetRightBorderMaze();
  Matrix& GetLeftBorderMaze();
  unsigned short& GetRowsMaze();
  unsigned short& GetColsMaze();

 private:
  Maze* maze_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
