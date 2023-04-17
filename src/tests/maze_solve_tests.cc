#include <gtest/gtest.h>

#include "../model/maze.h"

TEST(SolveMaze, CorrectFile) {
  Maze maze_solve;
  maze_solve.StartParsingFile("./resources/correct files/maze_1.txt");
  maze_solve.SolveMaze(std::make_pair(0, 0), std::make_pair(9, 9));
  short unsigned v[49][2] = {
      {9, 9}, {9, 8}, {9, 7}, {9, 6}, {8, 6}, {7, 6}, {7, 5}, {6, 5}, {6, 6},
      {6, 7}, {5, 7}, {5, 8}, {6, 8}, {6, 9}, {5, 9}, {4, 9}, {3, 9}, {2, 9},
      {1, 9}, {0, 9}, {0, 8}, {1, 8}, {2, 8}, {3, 8}, {3, 7}, {2, 7}, {1, 7},
      {1, 6}, {1, 5}, {1, 4}, {0, 4}, {0, 3}, {1, 3}, {2, 3}, {2, 4}, {2, 5},
      {3, 5}, {3, 4}, {4, 4}, {4, 3}, {3, 3}, {3, 2}, {3, 1}, {2, 1}, {2, 2},
      {1, 2}, {0, 2}, {0, 1}, {0, 0}};
  for (int i = 0; i < static_cast<int>(maze_solve.GetPath().size()); ++i) {
    EXPECT_EQ(maze_solve.GetPath()[i].first, v[i][0]);
    EXPECT_EQ(maze_solve.GetPath()[i].second, v[i][1]);
  }
}
