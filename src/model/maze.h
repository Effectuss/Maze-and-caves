#ifndef MAZE_AND_CAVES_MAZE_H_
#define MAZE_AND_CAVES_MAZE_H_

#include "maze_generator.h"
#include "parsing_file.h"

class Maze : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;

  void ParsingMazeFile(const std::string& path_file);

  Matrix& GetRightBorderMatrix();
  Matrix& GetLeftBorderMatrix();
  void ResizeMaze(const unsigned short& rows, const unsigned short& cols);
  unsigned short& GetRows();
  unsigned short& GetCols();

 private:
  unsigned short rows_, cols_;
  Matrix right_border_, bottom_border_;
  MazeGenerator maze_generation_;
};

#endif  // MAZE_AND_CAVES_MAZE_H_
