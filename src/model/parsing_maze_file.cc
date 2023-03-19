#include "parsing_maze_file.h"

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>&
ParsingMazeFile::ParsingFileMaze(const std::string& path_file) {
  maze_data_.first.clear();
  maze_data_.second.clear();
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("File could not be opened");
  } else {
    this->FillDataFromFile(file);
  }
  file.close();
  return this->maze_data_;
}

void ParsingMazeFile::FillDataFromFile(std::ifstream& file) {
  int rows, cols;
  while (!file.eof()) {
  }
}
