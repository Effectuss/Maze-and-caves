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
  using pair_type = std::pair<data_type, data_type>;
  using path_type = std::vector<pair_type>;

  Controller(Maze* maze, Cave* cave);
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  // maze methods
  void ParsingMazeFile(const std::string& path_file);
  const Matrix& GetRightBorderMaze();
  const Matrix& GetBottomBorderMaze();
  const data_type& GetRowsMaze() const;
  const data_type& GetColsMaze() const;
  const data_type& CheckRightBorderMaze(const data_type& i,
                                        const data_type& j) const;
  const data_type& CheckBottomBorderMaze(const data_type& i,
                                         const data_type& j) const;
  void GenerationMaze(const data_type& i, const data_type& j);
  void SaveMazeInFile(const std::string& file_path);
  void SolveMaze(const pair_type& begin, const pair_type& end);
  const path_type& GetPath() const;
  void ClearMaze();

  // cave methods
  void ParsingCaveFile(const std::string& file_path);
  Matrix& GetDataCave();
  const data_type& GetRowsCave() const;
  const data_type& GetColsCave() const;
  bool CheckCellCave(const data_type& i, const data_type& j) const;
  void GenerateCave(const data_type& i, const data_type& j);
  void UpdateCave(const data_type& i, const data_type& j);
  void SaveCaveInFile(const std::string& file_path);
  void ClearCave();

 private:
  Maze* maze_;
  Cave* cave_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
