#include "parsing_file.h"

ParsingFile::~ParsingFile() {}

bool ParsingFile::IsCorrectFile(std::ifstream& file,
                                TypeOfParsing type_parsing) {
  std::string buffer_line;
  value_type amount_lines = 0, rows = 0, cols = 0;
  while (std::getline(file, buffer_line)) {
    std::stringstream stream_line(buffer_line);
    if (!amount_lines) {
      if (!IsCorrectFirstLineFile(stream_line, rows, cols)) return false;
    } else if (buffer_line != "") {
      if (!IsValidMatrix(stream_line, cols)) return false;
    }
    ++amount_lines;
  }
  if (type_parsing == TypeOfParsing::kMaze) {
    if (amount_lines != (rows * 2 + 2)) return false;
  } else if (type_parsing == TypeOfParsing::kCave) {
    if (amount_lines != (rows + 1)) return false;
  }
  return true;
}

bool ParsingFile::IsCorrectFirstLineFile(std::stringstream& stream_line,
                                         reference rows, reference cols) {
  stream_line >> rows >> cols;
  stream_line.get();
  if (stream_line) {
    return false;
  } else if (rows > 50 || cols > 50 || cols == 0 || rows == 0) {
    return false;
  }
  return true;
}

bool ParsingFile::IsValidMatrix(std::stringstream& stream_line,
                                const_reference cols) {
  for (int i = 0; i < cols; ++i) {
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
    for (long unsigned int j = 0; j < vec.at(index_i).size(); ++j) {
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
