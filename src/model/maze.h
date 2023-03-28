#ifndef MAZE_AND_CAVES_MAZE_H_
#define MAZE_AND_CAVES_MAZE_H_

#include "maze_generator.h"
#include "parsing_file.h"

class Maze : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;

  void ParsingMazeFile(const std::string& path_file);
  void StartParsingFile(const std::string& path_file) override;
  void GenerationMaze(const unsigned short& rows, const unsigned short& cols);

  Matrix& GetRightBorderMatrix();
  Matrix& GetBottomBorderMatrix();
  void CreateMaze(const unsigned short& rows, const unsigned short& cols);
  unsigned short& GetRows();
  unsigned short& GetCols();
  unsigned short CheckRightBorder(const unsigned short& i,
                                  const unsigned short& j);
  unsigned short CheckBottomBorder(const unsigned short& i,
                                   const unsigned short& j);

 private:
  unsigned short rows_, cols_;
  Matrix right_border_, bottom_border_;
  MazeGenerator generator_;
};

#endif  // MAZE_AND_CAVES_MAZE_H_
