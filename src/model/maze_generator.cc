#include "maze_generator.h"

#include "maze.h"

void MazeGenerator::GenerationMaze(Maze* const maze) {
  this->maze_ = maze;
  CreateCurrentLine(maze->GetCols());
  for (int j = 0; j < maze_->GetRows() - 1; ++j) {
    AssignUniqueValues();
    AddingVerticalWalls(j);
    AddingHorizontalWalls(j);
    CheckedHorizontalWalls(j);
    PreparingNewLine(j);
  }
  AddingEndLine();
  ClearGenerator();
}

void MazeGenerator::CreateCurrentLine(const data_type& cols) {
  for (int i = 0; i < cols; ++i) {
    current_line_.push_back(kEmpty);
  }
}

void MazeGenerator::AssignUniqueValues() {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (current_line_.at(i) == MazeGenerator::kEmpty) {
      current_line_.at(i) = counter_;
      ++counter_;
    }
  }
}

void MazeGenerator::AddingVerticalWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols() - 1; ++i) {
    bool choice = RandomBool();
    if (choice == true || current_line_.at(i) == current_line_.at(i + 1)) {
      maze_->GetRightBorderMatrix().at(row).at(i) = true;
    } else {
      MergeSet(i, current_line_.at(i));
    }
  }
  maze_->GetRightBorderMatrix().at(row).at(maze_->GetCols() - 1) = true;
}

void MazeGenerator::MergeSet(const data_type& index, const data_type& element) {
  for (int j = 0; j < maze_->GetCols(); ++j) {
    if (current_line_.at(j) == current_line_.at(index + 1)) {
      current_line_.at(j) = element;
    }
  }
}

void MazeGenerator::AddingEndLine() {
  AssignUniqueValues();
  AddingVerticalWalls(maze_->GetRows() - 1);
  CheckedEndLine();
}

void MazeGenerator::CheckedEndLine() {
  for (int i = 0; i < maze_->GetCols() - 1; ++i) {
    if (current_line_.at(i) != current_line_.at(i + 1)) {
      maze_->GetRightBorderMatrix().at(maze_->GetRows() - 1).at(i) = false;
      MergeSet(i, current_line_.at(i));
    }
    maze_->GetBottomBorderMatrix().at(maze_->GetRows() - 1).at(i) = true;
  }
  maze_->GetBottomBorderMatrix()
      .at(maze_->GetRows() - 1)
      .at(maze_->GetCols() - 1) = true;
}

void MazeGenerator::AddingHorizontalWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    bool choice = RandomBool();
    if (CalculateUniqueSet(current_line_.at(i)) != 1 && choice == true) {
      maze_->GetBottomBorderMatrix().at(row).at(i) = true;
    }
  }
}

MazeGenerator::data_type MazeGenerator::CalculateUniqueSet(const int& element) {
  data_type count_uniq_set = 0;
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (current_line_.at(i) == element) {
      ++count_uniq_set;
    }
  }
  return count_uniq_set;
}

void MazeGenerator::CheckedHorizontalWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (CalculateHorizontalWalls(current_line_.at(i), row) == 0) {
      maze_->GetBottomBorderMatrix().at(row).at(i) = false;
    }
  }
}

MazeGenerator::data_type MazeGenerator::CalculateHorizontalWalls(
    const data_type& element, const data_type& row) {
  data_type count_horizont_line = 0;
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (current_line_.at(i) == element &&
        maze_->GetBottomBorderMatrix().at(row).at(i) == false) {
      ++count_horizont_line;
    }
  }
  return count_horizont_line;
}

void MazeGenerator::PreparingNewLine(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (maze_->GetBottomBorderMatrix().at(row).at(i) == true) {
      current_line_.at(i) = MazeGenerator::kEmpty;
    }
  }
}

bool MazeGenerator::RandomBool() {
  static auto gen = std::bind(std::uniform_int_distribution<>(0, 1),
                              std::default_random_engine());
  return gen();
}

void MazeGenerator::ClearGenerator() {
  current_line_.clear();
  counter_ = 1;
}
