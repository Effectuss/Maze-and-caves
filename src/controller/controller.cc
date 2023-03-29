#include "controller.h"

Controller::Controller(Maze *maze, Cave *cave) : maze_(maze), cave_(cave) {}

void Controller::ParsingMazeFile(const std::string &path_file) {
  this->maze_->StartParsingFile(path_file);
}

const Controller::Matrix &Controller::GetRightBorderMaze() {
  return this->maze_->GetRightBorderMatrix();
}

const Controller::Matrix &Controller::GetBottomBorderMaze() {
  return this->maze_->GetBottomBorderMatrix();
}

const Controller::data_type &Controller::GetRowsMaze() {
  return this->maze_->GetRows();
}

const Controller::data_type &Controller::GetColsMaze() {
  return this->maze_->GetCols();
}

const Controller::data_type &Controller::CheckRightBorderMaze(
    const data_type &i, const data_type &j) {
  return this->maze_->CheckRightBorder(i, j);
}

const Controller::data_type &Controller::CheckBottomBorderMaze(
    const data_type &i, const data_type &j) {
  return this->maze_->CheckBottomBorder(i, j);
}

void Controller::GenerationMaze(const data_type &i, const data_type &j) {
  this->maze_->GenerationMaze(i, j);
}

void Controller::SaveMazeInFile(const std::string &file_name) {
  this->maze_->SaveMazeInFile(file_name);
}

void Controller::ParsingCaveFile(const std::string &path_file) {
  this->cave_->StartParsingFile(path_file);
}

Controller::Matrix &Controller::GetDataCave() {
  return this->cave_->GetCaveData();
}

const Controller::data_type &Controller::GetRowsCave() {
  return this->cave_->GetRows();
}

const Controller::data_type &Controller::GetColsCave() {
  return this->cave_->GetCols();
}

bool Controller::CheckCellCave(const data_type &i, const data_type &j) {
  return this->cave_->CheckCell(i, j);
}
