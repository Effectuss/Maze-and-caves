#ifndef MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
#define MAZE_AND_CAVES_PARSING_MAZE_FILE_H_

#include <exception>
#include <fstream>
#include <utility>
#include <vector>

class ParsingMazeFile {
 public:
  std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>&
  ParsingFileMaze(const std::string& path_file);
  void FillDataFromFile(std::ifstream& file);

 private:
  std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
      maze_data_;
};

#endif  // MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
