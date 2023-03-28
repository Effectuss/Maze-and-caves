#include "maze_generator.h"

void MazeGenerator::CreateCurrentLine(const unsigned short& cols) {
  this->current_line_ = std::move(std::vector<unsigned int>(cols));
}
