#ifndef MAZE_AND_CAVES_CAVE_H_
#define MAZE_AND_CAVES_CAVE_H_

#include "parsing_file.h"

class Cave : public ParsingFile {
 public:
  using Matrix = std::vector<std::vector<unsigned short>>;

  void StartParsingFile(const std::string& path_file) override;

  Matrix& GetCaveData();
  void ResizeCave(const unsigned short& rows, const unsigned short& cols);
  unsigned short& GetRows();
  unsigned short& GetCols();
  bool CheckCell(const unsigned short& i, const unsigned short& j);

 private:
  unsigned short rows_, cols_;
  Matrix cave_data_;
};

#endif  // MAZE_AND_CAVES_CAVE_H_
