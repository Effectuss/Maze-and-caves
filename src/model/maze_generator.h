#ifndef MAZE_AND_CAVES_MAZE_GENERATOR_H_
#define MAZE_AND_CAVES_MAZE_GENERATOR_H_

#include <map>
#include <random>
#include <vector>

class Maze;

class MazeGenerator {
 public:
  using data_type = unsigned short;
  void GenerationMaze(Maze* const maze);
  void SetMaze(Maze* const maze);

 private:
  void SetUniqueValues();
  void AddRightWalls(const data_type& row);
  void AddBottomWalls(const data_type& row);
  void CheckedBottomWalls(const data_type& row);
  void PrepareNewLine(const data_type& row);
  void UnionSet(const data_type& index, const data_type& element);
  void FinishMazeGeneration();
  bool RandomBool();

  data_type FindAmountUniqueSet(const int& element);
  data_type FindAmountBottomWalls(const data_type& element,
                                  const data_type& row);

  std::vector<data_type> set_;
  int counter_{0};
  Maze* maze_;
};

#endif  // MAZE_AND_CAVES_MAZE_GENERATOR_H_
