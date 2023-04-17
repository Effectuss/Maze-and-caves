#ifndef MAZE_AND_CAVES_CAVE_SIMULATION_H_
#define MAZE_AND_CAVES_CAVE_SIMULATION_H_

#include <vector>

class Cave;

enum CellState { kDead, kLive };

class CaveAutomaton {
 public:
  using data_type = unsigned short;
  using Matrix = std::vector<std::vector<data_type>>;
  using reference = unsigned short&;
  using const_reference = const unsigned short&;

  void Update(const_reference birth, const_reference death);
  void SetCave(Cave* cave);

 private:
  Cave* cave_;

  data_type NeighboursCount(const_reference row, const_reference col);
};

#endif  // MAZE_AND_CAVES_CAVE_SIMULATION_H_
