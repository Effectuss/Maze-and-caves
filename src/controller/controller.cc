#include "controller.h"

Controller::Controller(Maze *maze) : maze_(maze) {}

void Controller::ParsingFileMaze(const std::string &path_file) {
  this->maze_->ParsingMazeFile(path_file);
}

Controller::Matrix &Controller::GetRightBorderMaze() {
  return this->maze_->GetRightBorderMatrix();
}

Controller::Matrix &Controller::GetLeftBorderMaze() {
  return this->maze_->GetLeftBorderMatrix();
}

unsigned short &Controller::GetRowsMaze() { return this->GetRowsMaze(); }

unsigned short &Controller::GetColsMaze() { return this->GetColsMaze(); }
