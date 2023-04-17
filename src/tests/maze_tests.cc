#include <gtest/gtest.h>

#include "../model/maze.h"

Maze maze;

TEST(MazeOpenFile, Exception) {
  EXPECT_THROW(maze.StartParsingFile("./FAKE.txt"), std::exception);
  EXPECT_THROW(maze.StartParsingFile(
                   "./resources/incorrect files/Maze/incorrect_cols.txt"),
               std::exception);
  EXPECT_THROW(maze.StartParsingFile(
                   "./resources/incorrect files/Maze/incorrect_data1.txt"),
               std::exception);
  EXPECT_THROW(maze.StartParsingFile(
                   "./resources/incorrect files/Maze/incorrect_data2.txt"),
               std::exception);
  EXPECT_THROW(maze.StartParsingFile(
                   "./resources/incorrect files/Maze/incorrect_data3.txt"),
               std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/incorrect_first_line1.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/incorrect_first_line2.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/incorrect_first_line3.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/incorrect_numbers_cols.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/incorrect_numbers_line2.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/maze_incorrect_number_rows.txt"),
      std::exception);
  EXPECT_THROW(
      maze.StartParsingFile(
          "./resources/incorrect files/Maze/maze_incorrect_numbers_line.txt"),
      std::exception);
  EXPECT_THROW(maze.StartParsingFile(
                   "./resources/incorrect files/Maze/maze_incorrect_rows.txt"),
               std::exception);
}

TEST(MazeOpenFile, CorrectFile1) {
  maze.StartParsingFile("./resources/correct files/maze_1.txt");
  EXPECT_EQ(maze.GetRows(), 10);
  EXPECT_EQ(maze.GetCols(), 10);
  short unsigned right[10][10] = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
      {1, 0, 1, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
      {0, 0, 1, 0, 1, 0, 1, 0, 1, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 1, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
      {1, 0, 0, 0, 1, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 1, 0, 0, 0, 1}};

  short unsigned bottom[10][10] = {
      {0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
      {1, 0, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 0, 0, 1, 0, 1, 1}, {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

  for (auto i = 0; i < 10; ++i)
    for (auto j = 0; j < 10; ++j)
      EXPECT_EQ(right[i][j], maze.GetRightBorderMatrix()[i][j]);

  for (auto i = 0; i < 10; ++i)
    for (auto j = 0; j < 10; ++j)
      EXPECT_EQ(bottom[i][j], maze.GetBottomBorderMatrix()[i][j]);
}

TEST(MazeOpenFile, CorrectFile2) {
  maze.StartParsingFile("./resources/correct files/maze_2.txt");
  EXPECT_EQ(maze.GetRows(), 10);
  EXPECT_EQ(maze.GetCols(), 10);
  EXPECT_EQ(maze.GetRightBorderMatrix()[0][0], 1);
  EXPECT_EQ(maze.GetRightBorderMatrix()[5][5], 0);
  EXPECT_EQ(maze.GetRightBorderMatrix()[9][9], 1);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[0][0], 0);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[5][5], 0);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[9][9], 1);
}

TEST(MazeOpenFile, CorrectFile3) {
  maze.StartParsingFile("./resources/correct files/maze_3.txt");
  EXPECT_EQ(maze.GetRows(), 20);
  EXPECT_EQ(maze.GetCols(), 20);
  EXPECT_EQ(maze.GetRightBorderMatrix()[0][0], 0);
  EXPECT_EQ(maze.GetRightBorderMatrix()[10][10], 0);
  EXPECT_EQ(maze.GetRightBorderMatrix()[19][19], 1);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[0][0], 0);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[10][10], 1);
  EXPECT_EQ(maze.GetBottomBorderMatrix()[19][19], 1);
}

TEST(MazeGeneration, CorrectFile) {
  maze.GenerationMaze(25, 40);
  EXPECT_EQ(maze.GetRows(), 25);
  EXPECT_EQ(maze.GetCols(), 40);
  maze.CheckRightBorder(0, 39);
  maze.CheckBottomBorder(24, 0);
  maze.ClearMaze();
}
