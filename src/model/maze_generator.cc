#include "maze_generator.h"

#include "maze.h"

void MazeGenerator::GenerationMaze(Maze* const maze) {
  SetMaze(maze);
  set_ = std::move(std::vector<data_type>(maze->GetCols()));
  for (int j = 0; j < maze_->GetRows() - 1; ++j) {
    SetUniqueValues();
    AddRightWalls(j);
    AddBottomWalls(j);
    CheckedBottomWalls(j);
    PrepareNewLine(j);
  }
  FinishMazeGeneration();
}

void MazeGenerator::SetUniqueValues() {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (!set_.at(i)) {
      ++counter_;
      set_.at(i) = counter_;
    }
  }
}

void MazeGenerator::AddRightWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols() - 1; ++i) {
    bool choice = RandomBool();
    if ((choice == true) || (set_.at(i) == set_.at(i + 1))) {
      maze_->GetRightBorderMatrix().at(row).at(i) = true;
    } else {
      UnionSet(i, set_.at(i));
    }
  }
  maze_->GetRightBorderMatrix().at(row).at(maze_->GetCols() - 1) = true;
}

void MazeGenerator::UnionSet(const data_type& index, const data_type& element) {
  int mutable_set = set_.at(index + 1);
  for (int j = 0; j < maze_->GetCols(); ++j) {
    if (set_.at(j) == mutable_set) {
      set_.at(j) = element;
    }
  }
}

void MazeGenerator::AddBottomWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    bool choice = RandomBool();
    if (FindAmountUniqueSet(set_.at(i)) != 1 && choice == true) {
      maze_->GetBottomBorderMatrix().at(row).at(i) = true;
    }
  }
}

MazeGenerator::data_type MazeGenerator::FindAmountUniqueSet(
    const int& element) {
  data_type count_uniq_set = 0;
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (set_.at(i) == element) {
      ++count_uniq_set;
    }
  }
  return count_uniq_set;
}

void MazeGenerator::CheckedBottomWalls(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (FindAmountBottomWalls(set_.at(i), row) == 0) {
      maze_->GetBottomBorderMatrix().at(row).at(i) = false;
    }
  }
}

MazeGenerator::data_type MazeGenerator::FindAmountBottomWalls(
    const data_type& element, const data_type& row) {
  data_type count_horizont_line = 0;
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (set_.at(i) == element &&
        maze_->GetBottomBorderMatrix().at(row).at(i) == false) {
      ++count_horizont_line;
    }
  }
  return count_horizont_line;
}

void MazeGenerator::PrepareNewLine(const data_type& row) {
  for (int i = 0; i < maze_->GetCols(); ++i) {
    if (maze_->GetBottomBorderMatrix().at(row).at(i) == true) {
      set_.at(i) = 0;
    }
  }
}

void MazeGenerator::FinishMazeGeneration() {
  SetUniqueValues();
  AddRightWalls(maze_->GetRows() - 1);
  for (int i = 0; i < maze_->GetCols() - 1; ++i) {
    if (set_.at(i) != set_.at(i + 1)) {
      maze_->GetRightBorderMatrix().at(maze_->GetRows() - 1).at(i) = false;
      UnionSet(i, set_.at(i));
    }
    maze_->GetBottomBorderMatrix().at(maze_->GetRows() - 1).at(i) = true;
  }
  maze_->GetBottomBorderMatrix()
      .at(maze_->GetRows() - 1)
      .at(maze_->GetCols() - 1) = true;
}

bool MazeGenerator::RandomBool() {
  static auto gen = std::bind(std::uniform_int_distribution<>(0, 1),
                              std::default_random_engine());
  return gen();
}

void MazeGenerator::SetMaze(Maze* const maze) { this->maze_ = maze; }
