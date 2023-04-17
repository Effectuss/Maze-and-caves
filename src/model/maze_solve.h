#ifndef MAZE_AND_CAVES_MAZE_SOLVE_H_
#define MAZE_AND_CAVES_MAZE_SOLVE_H_

#include <vector>

class Maze;

class MazeSolve {
 public:
  using data_type = unsigned short;
  using pair_type = std::pair<data_type, data_type>;
  using path_type = std::vector<pair_type>;

  void SolveMaze(pair_type from, pair_type to);
  void SetMaze(Maze* const maze);
  const path_type& GetPath() const;

 private:
  Maze* maze_;
  path_type path_;

  void RecursiveSearch(pair_type from, pair_type to, pair_type& cell,
                       path_type& queue);
  bool CheckMoveUp(pair_type from, pair_type to, pair_type& cell,
                   path_type& queue, path_type::iterator& it);
  bool CheckMoveDown(pair_type from, pair_type to, pair_type& cell,
                     path_type& queue, path_type::iterator& it);
  bool CheckMoveLeft(pair_type from, pair_type to, pair_type& cell,
                     path_type& queue, path_type::iterator& it);
  bool CheckMoveRight(pair_type from, pair_type to, pair_type& cell,
                      path_type& queue, path_type::iterator& it);
};

#endif  // MAZE_AND_CAVES_MAZE_SOLVE_H_
