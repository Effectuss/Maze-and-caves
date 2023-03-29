#ifndef MAZE_AND_CAVES_MAZE_H_
#define MAZE_AND_CAVES_MAZE_H_

#include "maze_generator.h"
#include "parsing_file.h"

class Maze : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;
  using data_type = unsigned short;

  void ParsingMazeFile(const std::string& path_file);
  void StartParsingFile(const std::string& path_file) override;
  void GenerationMaze(const data_type& rows, const data_type& cols);
  void SaveMazeInFile(const std::string& file_name);

  const Matrix& GetRightBorderMatrix();
  const Matrix& GetBottomBorderMatrix();
  void SetBottomBorder(const data_type& i, const data_type& j);
  void SetRightBorder(const data_type& i, const data_type& j);
  const data_type& GetRows();
  const data_type& GetCols();
  const unsigned short& CheckRightBorder(const data_type& i,
                                         const data_type& j);
  const unsigned short& CheckBottomBorder(const data_type& i,
                                          const data_type& j);
  void DeleteBottomBorder(const data_type& i, const data_type& j);
  void DeleteRightBorder(const data_type& i, const data_type& j);

 private:
  void CreateMaze(const data_type& rows, const data_type& cols);
  unsigned short rows_, cols_;
  Matrix right_border_, bottom_border_;
  MazeGenerator generator_;
};

#endif  // MAZE_AND_CAVES_MAZE_H_
