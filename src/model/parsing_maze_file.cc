#include "parsing_maze_file.h"

std::pair<std::vector<std::vector<unsigned>>,
          std::vector<std::vector<unsigned>>>&
ParsingMazeFile::ParsingFileMaze(const std::string& path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!this->IsCorrectFile(file)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      file.seekg(0, file.beg);
      this->TakeDataFromFile(file);
    }
  }
  return this->maze_data_;
}

bool ParsingMazeFile::IsCorrectFile(std::ifstream& file) {
  std::string buffer_line;
  unsigned index_rows_first = 0, index_rows_second = 0, count_line = 0,
           check_rows, check_cols;
  while (std::getline(file, buffer_line)) {
    std::stringstream stream_line(buffer_line);
    if (!count_line) {
      if (!this->IsCorrectFirstLineFile(stream_line, check_rows, check_cols))
        return false;
    } else if (buffer_line == "") {
    } else {
      if (index_rows_first == check_rows - 1) {
        if (!IsValidMatrix(stream_line, check_cols, index_rows_second))
          return false;
      } else if (index_rows_first != check_rows - 1) {
        if (!IsValidMatrix(stream_line, check_cols, index_rows_first))
          return false;
      }
    }
    ++count_line;
  }
  if (count_line != (check_rows * 2) + 2) return false;
  return true;
}

bool ParsingMazeFile::IsCorrectFirstLineFile(std::stringstream& stream_line,
                                             unsigned& check_rows,
                                             unsigned& check_cols) {
  stream_line >> check_rows >> check_cols;
  stream_line.get();
  if (stream_line) {
    return false;
  } else if (check_rows > 50 || check_cols > 50 || check_cols == 0 ||
             check_rows == 0) {
    return false;
  }
  return true;
}

bool ParsingMazeFile::IsValidMatrix(std::stringstream& stream_line,
                                    const unsigned& check_cols,
                                    unsigned& index_rows) {
  for (int i = 0; i < check_cols; ++i) {
    unsigned tmp;
    stream_line >> tmp;
    if (tmp != 0 && tmp != 1) return false;
  }
  stream_line.get();
  if (stream_line) return false;
  ++index_rows;
  return true;
}

void ParsingMazeFile::TakeDataFromFile(std::ifstream& file) {
  this->ResizeVectors(file);
  this->FillMatrix(file);
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

void ParsingMazeFile::FillMatrix(std::ifstream& file) {}
