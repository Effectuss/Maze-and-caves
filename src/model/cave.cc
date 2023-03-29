#include "cave.h"

void Cave::StartParsingFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!this->IsCorrectFile(file, TypeOfParsing::kCave)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      file.close();
      std::ifstream file(path_file);
      this->ParsingColsAndRows(file, this->rows_, this->cols_);
      this->CreateCave(this->rows_, this->cols_);
      this->FillMatrix(file, this->cave_data_);
      file.close();
    }
  }
}

void Cave::CreateCave(const unsigned short &rows, const unsigned short &cols) {
  this->cave_data_ = std::move(Matrix(rows, std::vector<unsigned short>(cols)));
  this->rows_ = rows;
  this->cols_ = cols;
}

Cave::Matrix &Cave::GetCaveData() { return this->cave_data_; }

unsigned short &Cave::GetRows() { return this->rows_; }

unsigned short &Cave::GetCols() { return this->cols_; }

bool Cave::CheckCell(const unsigned short &i, const unsigned short &j) {
  if (i >= this->rows_ || j >= this->cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return this->cave_data_.at(i).at(j);
}
