#ifndef MAZE_AND_CAVES_CONTROLLER_H_
#define MAZE_AND_CAVES_CONTROLLER_H_

#include <iostream>
#include <string>

#include "cave.h"
#include "maze.h"

class Controller {
 public:
  using Matrix = std::vector<std::vector<unsigned short> >;

  Controller(Maze* maze, Cave* cave);
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  void ParsingMazeFile(const std::string& path_file);
  Matrix& GetRightBorderMaze();
  Matrix& GetLeftBorderMaze();
  unsigned short& GetRowsMaze();
  unsigned short& GetColsMaze();

  void ParsingCaveFile(const std::string& path_file);
  Matrix& GetDataCave();
  unsigned short& GetRowsCave();
  unsigned short& GetColsCave();

 private:
  Maze* maze_;
  Cave* cave_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
