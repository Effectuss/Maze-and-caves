#ifndef MAZE_AND_CAVES_MAZE_H_
#define MAZE_AND_CAVES_MAZE_H_

#include "maze_generator.h"
#include "parsing_file.h"

class Maze : public ParsingFile, public MazeGenerator {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;

  void ParsingMazeFile(const std::string& path_file);
  void StartParsingFile(const std::string& path_file) override;
  void GenerationMaze();

  Matrix& GetRightBorderMatrix();
  Matrix& GetBottomBorderMatrix();
  void ResizeMaze(const unsigned short& rows, const unsigned short& cols);
  unsigned short& GetRows();
  unsigned short& GetCols();
  bool CheckRightBorder(const unsigned short& i, const unsigned short& j);
  bool CheckBottomBorder(const unsigned short& i, const unsigned short& j);

 private:
  unsigned short rows_, cols_;
  Matrix right_border_, bottom_border_;
};

#endif  // MAZE_AND_CAVES_MAZE_H_
