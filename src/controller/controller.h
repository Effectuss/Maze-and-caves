#ifndef MAZE_AND_CAVES_CONTROLLER_H_
#define MAZE_AND_CAVES_CONTROLLER_H_

#include <iostream>
#include <string>

#include "parsing_maze_file.h"

class Controller {
 public:
  Controller(ParsingMazeFile* parsingn_maze_file);
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  std::pair<std::vector<std::vector<unsigned>>,
            std::vector<std::vector<unsigned>>>&
  ParsingFileMaze(const std::string& path_file);

 private:
  ParsingMazeFile* parsing_maze_file_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
