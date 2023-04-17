#include <gtest/gtest.h>

#include "../model/cave.h"

Cave cave;

TEST(OpenFile, Exception) {
  EXPECT_THROW(cave.StartParsingFile("./FAKE.txt"), std::exception);
  EXPECT_THROW(
      cave.StartParsingFile(
          "./resources/incorrect files/Cave/incorrect_amount_lines1.txt"),
      std::exception);
  EXPECT_THROW(
      cave.StartParsingFile(
          "./resources/incorrect files/Cave/incorrect_amount_lines2.txt"),
      std::exception);
  EXPECT_THROW(
      cave.StartParsingFile(
          "./resources/incorrect files/Cave/incorrect_first_line1.txt"),
      std::exception);
  EXPECT_THROW(
      cave.StartParsingFile(
          "./resources/incorrect files/Cave/incorrect_first_line2.txt"),
      std::exception);
  EXPECT_THROW(
      cave.StartParsingFile(
          "./resources/incorrect files/Cave/incorrect_first_line3.txt"),
      std::exception);
  EXPECT_THROW(cave.StartParsingFile(
                   "./resources/incorrect files/Cave/incorrect_value.txt"),
               std::exception);
  EXPECT_THROW(cave.StartParsingFile(
                   "./resources/incorrect files/Cave/incorrect_value1.txt"),
               std::exception);
}

TEST(OpenFile, CorrectFile1) {
  cave.StartParsingFile("./resources/correct files/cave_1.txt");
  EXPECT_EQ(cave.GetRows(), 10);
  EXPECT_EQ(cave.GetCols(), 10);
  short unsigned v[10][10] = {
      {1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
      {0, 0, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
      {1, 0, 0, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 1, 0, 0, 0}};

  for (auto i = 0; i < 10; ++i)
    for (auto j = 0; j < 10; ++j) EXPECT_EQ(v[i][j], cave.GetCaveData()[i][j]);
}

TEST(OpenFile, CorrectFile2) {
  cave.StartParsingFile("./resources/correct files/cave_2.txt");
  EXPECT_EQ(cave.GetRows(), 20);
  EXPECT_EQ(cave.GetCols(), 20);
  EXPECT_EQ(cave.GetCaveData()[0][0], 1);
  EXPECT_EQ(cave.GetCaveData()[5][5], 1);
  EXPECT_EQ(cave.GetCaveData()[10][10], 1);
  EXPECT_EQ(cave.GetCaveData()[15][15], 1);
  EXPECT_EQ(cave.GetCaveData()[19][19], 1);
}

TEST(OpenFile, CorrectFile3) {
  cave.StartParsingFile("./resources/correct files/cave_3.txt");
  EXPECT_EQ(cave.GetRows(), 50);
  EXPECT_EQ(cave.GetCols(), 50);
  EXPECT_EQ(cave.GetCaveData()[0][0], 1);
  EXPECT_EQ(cave.GetCaveData()[0][49], 0);
  EXPECT_EQ(cave.GetCaveData()[49][0], 1);
  EXPECT_EQ(cave.GetCaveData()[49][49], 0);
}

TEST(Simulation, CorrectFile) {
  cave.StartParsingFile("./resources/correct files/cave_1.txt");
  cave.UpdateCave(4, 4);
  short unsigned v[10][10] = {
      {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
      {0, 0, 1, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 0, 1, 1, 1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, {1, 1, 1, 0, 1, 1, 1, 1, 0, 1}};
  for (auto i = 0; i < 10; ++i)
    for (auto j = 0; j < 10; ++j) EXPECT_EQ(v[i][j], cave.GetCaveData()[i][j]);
}

TEST(GenerateCave, CorrectFile) {
  cave.GenerateCave(25, 40);
  cave.CheckCell(0, 0);
  EXPECT_EQ(cave.GetRows(), 25);
  EXPECT_EQ(cave.GetCols(), 40);
}
