#include "cave.h"

void Cave::ParsingCaveFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!ParsingFile::IsCorrectFile(file, TypeOfParsing::kCave)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      file.close();
      std::ifstream file(path_file);
      ParsingFile::ParsingColsAndRows(file, this->rows_, this->cols_);
      this->ResizeCave(this->rows_, this->cols_);
      ParsingFile::FillMatrix(file, this->cave_data_);
      file.close();
    }
  }
}

void Cave::ResizeCave(const unsigned short &rows, const unsigned short &cols) {
  this->cave_data_.resize(rows);
  for (auto &el : this->cave_data_) el.resize(cols);
}

Cave::Matrix &Cave::GetCaveData() { return this->cave_data_; }

unsigned short &Cave::GetRows() { return this->rows_; }

unsigned short &Cave::GetCols() { return this->cols_; }
