#include "maze.h"

void Maze::StartParsingFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!IsCorrectFile(file, TypeOfParsing::kMaze)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      std::ifstream correct_file(path_file);
      ParsingColsAndRows(correct_file, this->rows_, this->cols_);
      CreateMaze(this->rows_, this->cols_);
      FillMatrix(correct_file, this->right_border_);
      FillMatrix(correct_file, this->bottom_border_);
      correct_file.close();
    }
  }
  file.close();
}

void Maze::GenerationMaze(const data_type &rows, const data_type &cols) {
  this->CreateMaze(rows, cols);
  this->generator_.SetMaze(this);
  this->generator_.GenerationMaze();
}

void Maze::SaveMazeInFile(const std::string &path_file) {
  std::ofstream file(path_file, std::ios::out);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    WriteRowsAndCols(file);
    WriteMatrixInFile(file, this->right_border_);
    WriteEmptyLine(file);
    WriteMatrixInFile(file, this->bottom_border_);
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

const Maze::path_type &Maze::GetPath() const { return this->solver_.GetPath(); }

void Maze::ClearMaze() {
  right_border_.clear();
  bottom_border_.clear();
  cols_ = 0;
  rows_ = 0;
}

void Maze::WriteRowsAndCols(std::ofstream &file) {
  file << rows_ << " " << cols_ << std::endl;
}

void Maze::WriteEmptyLine(std::ofstream &file) { file << std::endl; }

void Maze::WriteMatrixInFile(std::ofstream &file, const Matrix &matrix) {
  for (const auto &row : matrix) {
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

bool Maze::IsCorrectIndexForSolve(const pair_type &begin,
                                  const pair_type &finish) {
  if (begin.first >= rows_ || begin.second >= cols_ || finish.first >= rows_ ||
      finish.second >= cols_) {
    return false;
  }
  return true;
}

bool Maze::IsSolutionExist(const pair_type &begin, const pair_type &finish) {
  if (begin.first == 0 && begin.second == 0 && finish.first == 0 &&
      finish.second == 0) {
    return false;
  }
  return true;
}

bool Maze::IsMazeExist() {
  if (right_border_.empty() && bottom_border_.empty()) {
    return false;
  }
  return true;
}

void Maze::CreateMaze(const data_type &rows, const data_type &cols) {
  this->right_border_ = Matrix(rows, std::vector<data_type>(cols));
  this->bottom_border_ = Matrix(rows, std::vector<data_type>(cols));
  this->rows_ = rows;
  this->cols_ = cols;
}

void Maze::SolveMaze(const pair_type &from, const pair_type &to) {
  if (!IsMazeExist()) {
    throw std::logic_error("Maze doesn't exist, please generate it!");
  }
  if (!IsCorrectIndexForSolve(from, to)) {
    throw std::logic_error("Incorrect coordinate!");
  }
  if (!IsSolutionExist(from, to)) {
    throw std::logic_error("Coordinate 0, 0 ,0 ,0 this is the solution!");
  }
  solver_.SetMaze(this);
  solver_.SolveMaze(from, to);
}
