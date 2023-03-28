#include "maze.h"

void Maze::StartParsingFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!this->IsCorrectFile(file, TypeOfParsing::kMaze)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      file.close();
      std::ifstream file(path_file);
      this->ParsingColsAndRows(file, this->rows_, this->cols_);
      this->CreateMaze(this->rows_, this->cols_);
      this->FillMatrix(file, this->right_border_);
      this->FillMatrix(file, this->bottom_border_);
      file.close();
    }
  }
}

void Maze::GenerationMaze(const unsigned short &rows,
                          const unsigned short &cols) {
  this->CreateMaze(rows, cols);
  this->generator_.GenerationMaze(this);
}

Maze::Matrix &Maze::GetRightBorderMatrix() { return this->right_border_; }

Maze::Matrix &Maze::GetBottomBorderMatrix() { return this->bottom_border_; }

unsigned short &Maze::GetRows() { return this->rows_; }

unsigned short &Maze::GetCols() { return this->cols_; }

unsigned short Maze::CheckRightBorder(const unsigned short &i,
                                      const unsigned short &j) {
  if (i >= this->rows_ || j >= this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->right_border_.at(i).at(j);
}

unsigned short Maze::CheckBottomBorder(const unsigned short &i,
                                       const unsigned short &j) {
  if (i > this->rows_ || j > this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->bottom_border_.at(i).at(j);
}

void Maze::CreateMaze(const unsigned short &rows, const unsigned short &cols) {
  this->right_border_ = Matrix(rows, std::vector<unsigned short>(cols));
  this->bottom_border_ = Matrix(rows, std::vector<unsigned short>(cols));
  this->rows_ = rows;
  this->cols_ = cols;
}
