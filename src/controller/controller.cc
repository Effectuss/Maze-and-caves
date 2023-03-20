#include "controller.h"

Controller::Controller(ParsingMazeFile* parsingn_maze_file)
    : parsing_maze_file_(parsingn_maze_file) {}

std::pair<std::vector<std::vector<unsigned>>,
          std::vector<std::vector<unsigned>>>&
Controller::ParsingFileMaze(const std::string& path_file) {
  return this->parsing_maze_file_->ParsingFileMaze(path_file);
}
