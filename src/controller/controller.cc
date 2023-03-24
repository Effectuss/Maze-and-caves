#include "controller.h"

Controller::Controller(Maze *maze, Cave *cave) : maze_(maze), cave_(cave) {}

void Controller::ParsingMazeFile(const std::string &path_file) {
  this->maze_->ParsingMazeFile(path_file);
}

Controller::Matrix &Controller::GetRightBorderMaze() {
  return this->maze_->GetRightBorderMatrix();
}

Controller::Matrix &Controller::GetLeftBorderMaze() {
  return this->maze_->GetLeftBorderMatrix();
}

unsigned short &Controller::GetRowsMaze() { return this->maze_->GetRows(); }

unsigned short &Controller::GetColsMaze() { return this->maze_->GetCols(); }

void Controller::ParsingCaveFile(const std::string &path_file) {
  this->cave_->ParsingCaveFile(path_file);
}

Controller::Matrix &Controller::GetDataCave() {
  return this->cave_->GetCaveData();
}

unsigned short &Controller::GetRowsCave() { return this->cave_->GetRows(); }

unsigned short &Controller::GetColsCave() { return this->cave_->GetCols(); }
