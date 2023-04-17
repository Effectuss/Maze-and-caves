#include "cave.h"

void Cave::StartParsingFile(const std::string &path_file) {
  std::ifstream file(path_file);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    if (!IsCorrectFile(file, TypeOfParsing::kCave)) {
      file.close();
      throw std::invalid_argument("The file content is invalid");
    } else {
      std::ifstream correct_file(path_file);
      ParsingColsAndRows(correct_file, rows_, cols_);
      CreateCave(rows_, cols_);
      FillMatrix(correct_file, cave_data_);
      correct_file.close();
    }
  }
  file.close();
}

void Cave::CreateCave(const_reference rows, const_reference cols) {
  cave_data_ = Matrix(rows, std::vector<data_type>(cols));
  cols_ = cols;
  rows_ = rows;
}

bool Cave::RandomBool() {
  static auto gen = std::bind(std::uniform_int_distribution<>(0, 1),
                              std::default_random_engine());
  return gen();
}

Cave::Matrix &Cave::GetCaveData() { return cave_data_; }

void Cave::SetCave(Matrix &&matrix) { cave_data_.swap(matrix); }

Cave::reference Cave::GetRows() { return rows_; }

Cave::reference Cave::GetCols() { return cols_; }

bool Cave::CheckCell(const_reference i, const_reference j) {
  if (i >= rows_ or j >= cols_) {
    throw std::invalid_argument("Incorrect index");
  }
  return cave_data_.at(i).at(j);
}

void Cave::GenerateCave(const data_type rows, const data_type cols) {
  CreateCave(rows, cols);
  for (auto i = 0; i < GetRows(); ++i) {
    for (auto j = 0; j < GetCols(); ++j) {
      cave_data_[i][j] = RandomBool();
    }
  }
}

void Cave::UpdateCave(const_reference birth, const_reference death) {
  automate_.SetCave(this);
  automate_.Update(birth, death);
}

void Cave::SaveCaveInFile(const std::string &path_file) {
  std::ofstream file(path_file, std::ios::out);
  if (!file.is_open()) {
    throw std::logic_error("Can't open file");
  } else {
    WriteRowsAndCols(file);
    WriteCaveMatrix(file);
  }
  file.close();
}

void Cave::ClearCave() {
  cave_data_.clear();
  rows_ = 0;
  cols_ = 0;
}

void Cave::WriteRowsAndCols(std::ofstream &file) {
  file << rows_ << " " << cols_ << std::endl;
}

void Cave::WriteCaveMatrix(std::ofstream &file) {
  for (const auto &row : cave_data_) {
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
