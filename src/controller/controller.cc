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

const Controller::data_type &Controller::GetRowsMaze() const {
  return this->maze_->GetRows();
}

const Controller::data_type &Controller::GetColsMaze() const {
  return this->maze_->GetCols();
}

const Controller::data_type &Controller::CheckRightBorderMaze(
    const data_type &i, const data_type &j) const {
  return this->maze_->CheckRightBorder(i, j);
}

const Controller::data_type &Controller::CheckBottomBorderMaze(
    const data_type &i, const data_type &j) const {
  return this->maze_->CheckBottomBorder(i, j);
}

void Controller::GenerationMaze(const data_type &i, const data_type &j) {
  this->maze_->GenerationMaze(i, j);
}

void Controller::SaveMazeInFile(const std::string &file_path) {
  this->maze_->SaveMazeInFile(file_path);
}

void Controller::SolveMaze(const pair_type &begin, const pair_type &end) {
  this->maze_->SolveMaze(begin, end);
}

const Controller::path_type &Controller::GetPath() const {
  return this->maze_->GetPath();
}

void Controller::ClearMaze() { this->maze_->ClearMaze(); }

void Controller::ParsingCaveFile(const std::string &file_path) {
  this->cave_->StartParsingFile(file_path);
}

Controller::Matrix &Controller::GetDataCave() {
  return this->cave_->GetCaveData();
}

const Controller::data_type &Controller::GetRowsCave() const {
  return this->cave_->GetRows();
}

const Controller::data_type &Controller::GetColsCave() const {
  return this->cave_->GetCols();
}

bool Controller::CheckCellCave(const data_type &i, const data_type &j) const {
  return this->cave_->CheckCell(i, j);
}

void Controller::GenerateCave(const data_type &i, const data_type &j) {
  this->cave_->GenerateCave(i, j);
}

void Controller::UpdateCave(const data_type &i, const data_type &j) {
  this->cave_->UpdateCave(i, j);
}

void Controller::SaveCaveInFile(const std::string &file_path) {
  this->cave_->SaveCaveInFile(file_path);
}

void Controller::ClearCave() { this->cave_->ClearCave(); }
