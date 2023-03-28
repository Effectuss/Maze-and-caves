#ifndef MAZE_AND_CAVES_MAZE_GENERATOR_H_
#define MAZE_AND_CAVES_MAZE_GENERATOR_H_

#include <vector>

class Maze;

class MazeGenerator {
 public:
  void CreateCurrentLine(const unsigned short& cols);

 private:
  std::vector<unsigned int> current_line_;
};

#endif  // MAZE_AND_CAVES_MAZE_GENERATOR_H_
