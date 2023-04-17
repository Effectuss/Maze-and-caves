#ifndef MAZE_AND_CAVES_MAZE_H_
#define MAZE_AND_CAVES_MAZE_H_

#include "maze_generator.h"
#include "maze_solve.h"
#include "parsing_file.h"

class Maze : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;
  using data_type = unsigned short;
  using pair_type = std::pair<data_type, data_type>;
  using path_type = std::vector<pair_type>;

  void StartParsingFile(const std::string& path_file) override;
  void GenerationMaze(const data_type& rows, const data_type& cols);
  void SolveMaze(const pair_type& from, const pair_type& to);
  void SaveMazeInFile(const std::string& path_file);

  const Matrix& GetRightBorderMatrix();
  const Matrix& GetBottomBorderMatrix();
  void SetBottomBorder(const data_type& i, const data_type& j);
  void SetRightBorder(const data_type& i, const data_type& j);
  const data_type& GetRows();
  const data_type& GetCols();
  const data_type& CheckRightBorder(const data_type& i, const data_type& j);
  const data_type& CheckBottomBorder(const data_type& i, const data_type& j);
  void DeleteBottomBorder(const data_type& i, const data_type& j);
  void DeleteRightBorder(const data_type& i, const data_type& j);
  const path_type& GetPath() const;
  void ClearMaze();

 private:
  // additional methods for save in file
  void WriteRowsAndCols(std::ofstream& file);
  void WriteEmptyLine(std::ofstream& file);
  void WriteMatrixInFile(std::ofstream& file, const Matrix& matrix);

  bool IsCorrectIndexForSolve(const pair_type& begin, const pair_type& finish);
  bool IsSolutionExist(const pair_type& begin, const pair_type& finish);
  bool IsMazeExist();

  void CreateMaze(const data_type& rows, const data_type& cols);
  unsigned short rows_, cols_;
  Matrix right_border_, bottom_border_;
  MazeGenerator generator_;
  MazeSolve solver_;
};

#endif  // MAZE_AND_CAVES_MAZE_H_
