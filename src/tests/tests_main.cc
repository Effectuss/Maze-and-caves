#include <gtest/gtest.h>

#include "./cave_tests.cc"
#include "./maze_solve_tests.cc"
#include "./maze_tests.cc"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
