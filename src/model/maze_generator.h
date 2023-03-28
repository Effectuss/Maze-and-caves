#ifndef MAZE_AND_CAVES_MAZE_GENERATOR_H_
#define MAZE_AND_CAVES_MAZE_GENERATOR_H_

#include <map>
#include <random>
#include <vector>

class Maze;

class MazeGenerator {
 public:
  using data_type = unsigned short;
  static constexpr int kEmpty = 0;
  void GenerationMaze(Maze* const maze);

 private:
  void CreateCurrentLine(const data_type& cols);
  void AssignUniqueValues();
  void AddingVerticalWalls(const data_type& row);
  void AddingHorizontalWalls(const data_type& row);
  data_type CalculateUniqueSet(const int& element);
  void CheckedHorizontalWalls(const data_type& row);
  data_type CalculateHorizontalWalls(const data_type& element,
                                     const data_type& row);
  void PreparingNewLine(const data_type& row);
  void MergeSet(const data_type& index, const data_type& element);
  void AddingEndLine();
  void CheckedEndLine();
  bool RandomBool();
  void ClearGenerator();

  std::vector<unsigned int> current_line_;
  int counter_{1};
  Maze* maze_;
};

#endif  // MAZE_AND_CAVES_MAZE_GENERATOR_H_
