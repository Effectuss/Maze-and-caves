#ifndef MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
#define MAZE_AND_CAVES_PARSING_MAZE_FILE_H_

#include <exception>
#include <fstream>
#include <istream>
#include <sstream>
#include <utility>
#include <vector>

class ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;
  using value_type = unsigned short;
  using reference = unsigned short&;
  using const_reference = const unsigned short&;

  enum TypeOfParsing { kMaze = 1, kCave = 2 };

  virtual ~ParsingFile() = 0;
  virtual void StartParsingFile(const std::string& path_file) = 0;

 protected:
  void FillMatrix(std::ifstream& file, Matrix& vec);
  void ParsingColsAndRows(std::ifstream& file, reference rows, reference cols);

  bool IsCorrectFile(std::ifstream& file, TypeOfParsing);
  bool IsCorrectFirstLineFile(std::stringstream& stream_line, reference rows,
                              reference cols);
  bool IsValidMatrix(std::stringstream& stream_line, const_reference cols);
};

#endif  // MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
