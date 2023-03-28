#include "controller.h"

Controller::Controller(Maze *maze, Cave *cave) : maze_(maze), cave_(cave) {}

void Controller::ParsingMazeFile(const std::string &path_file) {
  this->maze_->StartParsingFile(path_file);
}

Controller::Matrix &Controller::GetRightBorderMaze() {
  return this->maze_->GetRightBorderMatrix();
}

Controller::Matrix &Controller::GetBottomBorderMaze() {
  return this->maze_->GetBottomBorderMatrix();
}

unsigned short &Controller::GetRowsMaze() { return this->maze_->GetRows(); }

unsigned short &Controller::GetColsMaze() { return this->maze_->GetCols(); }

bool Controller::CheckRightBorderMaze(const unsigned short &i,
                                      const unsigned short &j) {
  return this->maze_->CheckRightBorder(i, j);
}

bool Controller::CheckBottomBorderMaze(const unsigned short &i,
                                       const unsigned short &j) {
  return this->maze_->CheckBottomBorder(i, j);
}

void Controller::GenerationMaze(const unsigned short &i,
                                const unsigned short &j) {
  this->maze_->GenerationMaze(i, j);
}

void Controller::ParsingCaveFile(const std::string &path_file) {
  this->cave_->StartParsingFile(path_file);
}

Controller::Matrix &Controller::GetDataCave() {
  return this->cave_->GetCaveData();
}

unsigned short &Controller::GetRowsCave() { return this->cave_->GetRows(); }

unsigned short &Controller::GetColsCave() { return this->cave_->GetCols(); }

bool Controller::CheckCellCave(const unsigned short &i,
                               const unsigned short &j) {
  return this->cave_->CheckCell(i, j);
}
