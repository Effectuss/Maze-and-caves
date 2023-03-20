#ifndef MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
#define MAZE_AND_CAVES_PARSING_MAZE_FILE_H_

#include <exception>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

class ParsingMazeFile {
 public:
  std::pair<std::vector<std::vector<unsigned>>,
            std::vector<std::vector<unsigned>>>&
  ParsingFileMaze(const std::string& path_file);

  void TakeDataFromFile(std::ifstream& file);

  void ResizeVectors(std::ifstream& file);

  bool IsCorrectFile(std::ifstream& file);

  bool IsCorrectFirstLineFile(std::stringstream& stream_line,
                              unsigned& check_rows, unsigned& check_cols);

  bool IsValidMatrix(std::stringstream& stream_line, const unsigned& check_cols,
                     unsigned& index_rows);

  void FillMatrix(std::ifstream& file);

 private:
  std::pair<std::vector<std::vector<unsigned>>,
            std::vector<std::vector<unsigned>>>
      maze_data_;
};

#endif  // MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
