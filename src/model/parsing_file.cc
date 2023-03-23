#include "parsing_file.h"

ParsingFile::~ParsingFile() {}

bool ParsingFile::IsCorrectFile(std::ifstream& file,
                                TypeOfParsing type_parsing) {
  std::string buffer_line;
  value_type count_line = 0, check_rows = 0, check_cols = 0;
  while (std::getline(file, buffer_line)) {
    std::stringstream stream_line(buffer_line);
    if (!count_line) {
      if (!IsCorrectFirstLineFile(stream_line, check_rows, check_cols))
        return false;
    } else if (buffer_line != "") {
      if (!IsValidMatrix(stream_line, check_cols)) return false;
    }
    ++count_line;
  }
  if (type_parsing == TypeOfParsing::kMaze) {
    if (count_line != (check_rows * 2 + 2)) return false;
  } else if (type_parsing == TypeOfParsing::kCave) {
    if (count_line != (check_rows + 1)) return false;
  }
  return true;
}

bool ParsingFile::IsCorrectFirstLineFile(std::stringstream& stream_line,
                                         reference check_rows,
                                         reference check_cols) {
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

bool ParsingFile::IsValidMatrix(std::stringstream& stream_line,
                                const_reference check_cols) {
  for (int i = 0; i < check_cols; ++i) {
    unsigned tmp;
    stream_line >> tmp;
    if (stream_line.fail()) return false;
    if (tmp != 0 && tmp != 1) return false;
  }
  stream_line.get();
  if (stream_line) return false;
  return true;
}

void ParsingFile::FillMatrix(std::ifstream& file, Matrix& vec) {
  std::string line;
  unsigned index_i = 0;
  while (std::getline(file, line) && index_i < vec.size()) {
    std::stringstream stream(line);
    for (int j = 0; j < vec.at(index_i).size(); ++j) {
      unsigned tmp;
      stream >> tmp;
      vec.at(index_i).at(j) = tmp;
    }
    ++index_i;
  }
}

void ParsingFile::ParsingColsAndRows(std::ifstream& file, reference rows,
                                     reference cols) {
  file >> rows >> cols;
  file.get();
}
