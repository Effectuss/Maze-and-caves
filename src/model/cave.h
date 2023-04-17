#ifndef MAZE_AND_CAVES_CAVE_H_
#define MAZE_AND_CAVES_CAVE_H_

#include <functional>
#include <random>

#include "cave_automaton.h"
#include "parsing_file.h"

class Cave : public ParsingFile {
 public:
  using data_type = unsigned short;
  using Matrix = std::vector<std::vector<data_type>>;
  using reference = unsigned short&;
  using const_reference = const unsigned short&;

  void StartParsingFile(const std::string& path_file) override;

  Matrix& GetCaveData();
  void SetCave(Matrix&& matrix);
  reference GetRows();
  reference GetCols();
  bool CheckCell(const_reference i, const_reference j);
  void GenerateCave(const data_type rows, const data_type cols);
  void UpdateCave(const_reference birth, const_reference death);
  void SaveCaveInFile(const std::string& path_file);
  void ClearCave();

 private:
  data_type rows_, cols_;
  Matrix cave_data_;
  CaveAutomaton automate_;

  // additional methods for save in file
  void WriteRowsAndCols(std::ofstream& file);
  void WriteCaveMatrix(std::ofstream& file);

  void CreateCave(const_reference rows, const_reference cols);
  bool RandomBool();
};

#endif  // MAZE_AND_CAVES_CAVE_H_
