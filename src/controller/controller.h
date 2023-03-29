#ifndef MAZE_AND_CAVES_CONTROLLER_H_
#define MAZE_AND_CAVES_CONTROLLER_H_

#include <iostream>
#include <string>

#include "cave.h"
#include "maze.h"

class Controller {
 public:
  using Matrix = std::vector<std::vector<unsigned short> >;
  using data_type = unsigned short;

  Controller(Maze* maze, Cave* cave);
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  // maze methods
  void ParsingMazeFile(const std::string& path_file);
  const Matrix& GetRightBorderMaze();
  const Matrix& GetBottomBorderMaze();
  const data_type& GetRowsMaze();
  const data_type& GetColsMaze();
  const data_type& CheckRightBorderMaze(const data_type& i, const data_type& j);
  const data_type& CheckBottomBorderMaze(const data_type& i,
                                         const data_type& j);
  void GenerationMaze(const data_type& i, const data_type& j);
  void SaveMazeInFile(const std::string& file_name);

  // cave methods
  void ParsingCaveFile(const std::string& path_file);
  Matrix& GetDataCave();
  const data_type& GetRowsCave();
  const data_type& GetColsCave();
  bool CheckCellCave(const data_type& i, const data_type& j);

 private:
  Maze* maze_;
  Cave* cave_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
