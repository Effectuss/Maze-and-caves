#include "maze_solve.h"

#include "maze.h"

void MazeSolve::SetMaze(Maze* const maze) { this->maze_ = maze; }

const MazeSolve::path_type& MazeSolve::GetPath() const { return this->path_; }

void MazeSolve::SolveMaze(pair_type from, pair_type to) {
  path_.clear();
  path_type queue;
  queue.push_back(from);
  pair_type cell = from;
  RecursiveSearch(from, to, cell, queue);
  for (int i = queue.size() - 1; queue[i + 1] != from; --i) {
    path_.push_back(queue[i]);
  }
}

void MazeSolve::RecursiveSearch(pair_type from, pair_type to, pair_type& cell,
                                path_type& queue) {
  path_type::iterator it;
  if (queue.size() > 1) {
    it = queue.end() - 2;
  } else {
    it = queue.begin();
  }
  if (CheckMoveUp(from, to, cell, queue, it)) return;
  if (CheckMoveDown(from, to, cell, queue, it)) return;
  if (CheckMoveLeft(from, to, cell, queue, it)) return;
  if (CheckMoveRight(from, to, cell, queue, it)) return;

  if (queue.size() > 1) {
    queue.pop_back();
  }
  it = queue.end() - 1;
  cell = *it;
}

bool MazeSolve::CheckMoveUp(pair_type from, pair_type to, pair_type& cell,
                            path_type& queue, path_type::iterator& it) {
  if (cell.first != 0 and
      maze_->GetBottomBorderMatrix()[cell.first - 1][cell.second] == 0 and
      std::make_pair((data_type)(cell.first - 1), cell.second) != *it) {
    if (cell != to) {
      cell = std::make_pair(cell.first - 1, cell.second);
      queue.push_back(cell);
    }
    if (cell != to) {
      RecursiveSearch(from, to, cell, queue);
    } else {
      return true;
    }
  }
  if (cell == to) return true;
  return false;
}

bool MazeSolve::CheckMoveDown(pair_type from, pair_type to, pair_type& cell,
                              path_type& queue, path_type::iterator& it) {
  if (cell.first != maze_->GetRows() - 1 and
      maze_->GetBottomBorderMatrix()[cell.first][cell.second] == 0 and
      std::make_pair((data_type)(cell.first + 1), cell.second) != *it) {
    if (cell != to) {
      cell = std::make_pair(cell.first + 1, cell.second);
      queue.push_back(cell);
    }
    if (cell != to) {
      RecursiveSearch(from, to, cell, queue);
    } else {
      return true;
    }
  }
  if (cell == to) return true;
  return false;
}

bool MazeSolve::CheckMoveLeft(pair_type from, pair_type to, pair_type& cell,
                              path_type& queue, path_type::iterator& it) {
  if (cell.second != 0 and
      maze_->GetRightBorderMatrix()[cell.first][cell.second - 1] == 0 and
      std::make_pair(cell.first, (data_type)(cell.second - 1)) != *it) {
    if (cell != to) {
      cell = std::make_pair(cell.first, cell.second - 1);
      queue.push_back(cell);
    }
    if (cell != to) {
      RecursiveSearch(from, to, cell, queue);
    } else {
      return true;
    }
  }
  if (cell == to) return true;
  return false;
}

bool MazeSolve::CheckMoveRight(pair_type from, pair_type to, pair_type& cell,
                               path_type& queue, path_type::iterator& it) {
  if (cell.second != maze_->GetCols() - 1 and
      maze_->GetRightBorderMatrix()[cell.first][cell.second] == 0 and
      std::make_pair(cell.first, (data_type)(cell.second + 1)) != *it) {
    if (cell != to) {
      cell = std::make_pair(cell.first, cell.second + 1);
      queue.push_back(cell);
    }
    if (cell != to) {
      RecursiveSearch(from, to, cell, queue);
    } else {
      return true;
    }
  }
  if (cell == to) return true;
  return false;
}
