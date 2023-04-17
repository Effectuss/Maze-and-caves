#include "cave_automaton.h"

#include "cave.h"

void CaveAutomaton::SetCave(Cave* cave) { cave_ = cave; }

void CaveAutomaton::Update(const_reference birth, const_reference death) {
  data_type rows = cave_->GetRows();
  data_type cols = cave_->GetCols();
  Matrix new_cave = Matrix(rows, std::vector<data_type>(cols));
  for (data_type i = 0; i < rows; ++i) {
    for (data_type j = 0; j < cols; ++j) {
      data_type n_cnt = NeighboursCount(i, j);
      if (cave_->GetCaveData()[i][j] == kLive) {
        if (n_cnt < death) {
          new_cave[i][j] = kDead;
        } else {
          new_cave[i][j] = kLive;
        }
      } else if (cave_->GetCaveData()[i][j] == kDead) {
        if (n_cnt > birth) {
          new_cave[i][j] = kLive;
        } else {
          new_cave[i][j] = kDead;
        }
      }
    }
  }
  cave_->SetCave(std::move(new_cave));
}

CaveAutomaton::data_type CaveAutomaton::NeighboursCount(const_reference row,
                                                        const_reference col) {
  data_type cnt = 0;
  data_type rows = cave_->GetRows();
  data_type cols = cave_->GetCols();
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (i == 0 and j == 0) continue;
      if ((row + i) < 0 or (col + j) < 0 or (row + i) >= rows or
          (col + j) >= cols)
        ++cnt;
      else if (cave_->GetCaveData()[row + i][col + j] == kLive)
        ++cnt;
    }
  }
  return cnt;
}
