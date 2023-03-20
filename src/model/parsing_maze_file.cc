#include "parsing_maze_file.h"

std::pair<std::vector<std::vector<unsigned>>,
          std::vector<std::vector<unsigned>>>&
ParsingMazeFile::ParsingFileMaze(const std::string& path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (this->IsCorrectFile(file)) {
      file.seekg(0, file.beg);
      this->TakeDataFromFile(file);
    } else {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    }
  }
  return this->maze_data_;
}

void ParsingMazeFile::TakeDataFromFile(std::ifstream& file) {
  this->ResizeVectors(file);
}

bool ParsingMazeFile::IsCorrectFile(std::ifstream& file) {
  std::string buffer_line;
  unsigned check_rows, check_cols;
  unsigned count_line = 0;
  while (std::getline(file, buffer_line)) {
    std::stringstream stream_line(buffer_line);
    if (count_line == 0) {
      stream_line >> check_rows >> check_cols;
      stream_line.get();
      if (stream_line) {
        return false;
      } else if (check_rows > 50 || check_cols > 50) {
        return false;
      }
    }
    ++count_line;
  }
  if (count_line != (check_rows * 2) + 2) {
    return false;
  }
  return true;
}

void ParsingMazeFile::ResizeVectors(std::ifstream& file) {
  unsigned tmp_rows, tmp_cols;
  file >> tmp_rows >> tmp_cols;
  file.get();
  maze_data_.first.resize(tmp_rows);
  for (auto& vec : maze_data_.first) {
    vec.resize(tmp_cols);
  }
  maze_data_.second.resize(tmp_rows);
  for (auto& vec : maze_data_.second) {
    vec.resize(tmp_cols);
  }
}
