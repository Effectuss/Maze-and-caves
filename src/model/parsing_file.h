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

 protected:
  static void FillMatrix(std::ifstream& file, Matrix& vec);
  static void ParsingColsAndRows(std::ifstream& file, reference rows,
                                 reference cols);

  static bool IsCorrectFile(std::ifstream& file, TypeOfParsing);
  static bool IsCorrectFirstLineFile(std::stringstream& stream_line,
                                     reference check_rows,
                                     reference check_cols);
  static bool IsValidMatrix(std::stringstream& stream_line,
                            const_reference check_cols);
};

#endif  // MAZE_AND_CAVES_PARSING_MAZE_FILE_H_
