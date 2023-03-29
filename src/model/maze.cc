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

void Maze::GenerationMaze(const data_type &rows, const data_type &cols) {
  this->CreateMaze(rows, cols);
  this->generator_.GenerationMaze(this);
}

void Maze::SaveMazeInFile(const std::string &path_file) {
  std::ofstream file(path_file, std::ios::out);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    WriteRowsAndCols(file);
    WriteRightBorderMatrix(file);
    WriteEmptyLine(file);
    WriteBottomBorderMatrix(file);
  }
  file.close();
}

const Maze::Matrix &Maze::GetRightBorderMatrix() { return this->right_border_; }

const Maze::Matrix &Maze::GetBottomBorderMatrix() {
  return this->bottom_border_;
}

void Maze::SetBottomBorder(const data_type &i, const data_type &j) {
  this->bottom_border_.at(i).at(j) = 1;
}

void Maze::SetRightBorder(const data_type &i, const data_type &j) {
  this->right_border_.at(i).at(j) = 1;
}

const Maze::data_type &Maze::GetRows() { return this->rows_; }

const Maze::data_type &Maze::GetCols() { return this->cols_; }

const Maze::data_type &Maze::CheckRightBorder(const data_type &i,
                                              const data_type &j) {
  if (i >= this->rows_ || j >= this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->right_border_.at(i).at(j);
}

const Maze::data_type &Maze::CheckBottomBorder(const data_type &i,
                                               const data_type &j) {
  if (i >= this->rows_ || j >= this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->bottom_border_.at(i).at(j);
}

void Maze::DeleteBottomBorder(const data_type &i, const data_type &j) {
  this->bottom_border_.at(i).at(j) = 0;
}

void Maze::DeleteRightBorder(const data_type &i, const data_type &j) {
  this->right_border_.at(i).at(j) = 0;
}

void Maze::WriteRowsAndCols(std::ofstream &file) {
  file << rows_ << " " << cols_ << std::endl;
}

void Maze::WriteRightBorderMatrix(std::ofstream &file) {
  for (const auto &row : right_border_) {
    for (const auto &el : row) {
      if (&el != &row.back()) {
        file << el << " ";
      } else {
        file << el;
      }
    }
    file << std::endl;
  }
}

void Maze::WriteEmptyLine(std::ofstream &file) { file << std::endl; }

void Maze::WriteBottomBorderMatrix(std::ofstream &file) {
  for (const auto &row : bottom_border_) {
    for (const auto &el : row) {
      if (&el != &row.back()) {
        file << el << " ";
      } else {
        file << el;
      }
    }
    file << std::endl;
  }
}

void Maze::CreateMaze(const data_type &rows, const data_type &cols) {
  this->right_border_ = Matrix(rows, std::vector<data_type>(cols));
  this->bottom_border_ = Matrix(rows, std::vector<data_type>(cols));
  this->rows_ = rows;
  this->cols_ = cols;
}
