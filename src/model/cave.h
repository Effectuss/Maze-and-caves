#ifndef MAZE_AND_CAVES_CAVE_H_
#define MAZE_AND_CAVES_CAVE_H_

#include "parsing_file.h"

class Cave : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;

  void ParsingCaveFile(const std::string& path_file);

  Matrix& GetCaveData();
  void ResizeCave(const unsigned short& rows, const unsigned short& cols);
  unsigned short& GetRows();
  unsigned short& GetCols();

 private:
  unsigned short rows_, cols_;
  Matrix cave_data_;
};

#endif  // MAZE_AND_CAVES_CAVE_H_