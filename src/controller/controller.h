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
  Matrix& GetBottomBorderMaze();
  unsigned short& GetRowsMaze();
  unsigned short& GetColsMaze();
  bool CheckRightBorderMaze(const unsigned short& i, const unsigned short& j);
  bool CheckBottomBorderMaze(const unsigned short& i, const unsigned short& j);
  void GenerationMaze(const unsigned short& i, const unsigned short& j);

  void ParsingCaveFile(const std::string& path_file);
  Matrix& GetDataCave();
  unsigned short& GetRowsCave();
  unsigned short& GetColsCave();
  bool CheckCellCave(const unsigned short& i, const unsigned short& j);

 private:
  Maze* maze_;
  Cave* cave_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
