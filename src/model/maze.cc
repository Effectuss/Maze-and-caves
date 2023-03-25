#include "maze.h"

void Maze::StartParsingFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!ParsingFile::IsCorrectFile(file, TypeOfParsing::kMaze)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      file.close();
      std::ifstream file(path_file);
      ParsingFile::ParsingColsAndRows(file, this->rows_, this->cols_);
      this->ResizeMaze(this->rows_, this->cols_);
      ParsingFile::FillMatrix(file, this->right_border_);
      ParsingFile::FillMatrix(file, this->bottom_border_);
      file.close();
    }
  }
}

Maze::Matrix &Maze::GetRightBorderMatrix() { return this->right_border_; }

Maze::Matrix &Maze::GetBottomBorderMatrix() { return this->bottom_border_; }

unsigned short &Maze::GetRows() { return this->rows_; }

unsigned short &Maze::GetCols() { return this->cols_; }

bool Maze::CheckRightBorder(const unsigned short &i, const unsigned short &j) {
  if (i > this->rows_ || j > this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->right_border_.at(i).at(j);
}

bool Maze::CheckBottomBorder(const unsigned short &i, const unsigned short &j) {
  if (i > this->rows_ || j > this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->bottom_border_.at(i).at(j);
}

void Maze::ResizeMaze(const unsigned short &rows, const unsigned short &cols) {
  this->right_border_.resize(rows);
  this->bottom_border_.resize(rows);
  this->rows_ = rows;
  for (auto &el : right_border_) el.resize(cols);
  for (auto &el : bottom_border_) el.resize(cols);
  this->cols_ = cols;
}
