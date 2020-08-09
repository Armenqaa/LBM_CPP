//
// Created by thear on 03.04.2020.
//

#include "../point.h"
#include <iostream>
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(GridConstructor__Test, MAX_MIN_Test) {
  std::vector<std::pair<int, int>> indata = {{2, 4}, {0, 5}, {1, 5}, {1, 3},
                                             {0, 0}, {2, 3}, {5, 4}, {5, 5},
                                             {7, 5}, {7, 0}};
  Grid A(indata);
  EXPECT_EQ(A.grid.size(), 8);
  EXPECT_EQ(A.grid[0].size(), 6);
}
TEST(GridBoundaries__Test, Boundaries_Test) {
  std::vector<std::pair<int, int>> indata;
  for (size_t j = 0; j < 6; ++j) {
    indata.emplace_back(0, j);
    indata.emplace_back(1, j);
    indata.emplace_back(5, j);
    indata.emplace_back(6, j);
    indata.emplace_back(7, j);
  }
  for (size_t j = 0; j < 5; ++j) {
    indata.emplace_back(2, j);
    indata.emplace_back(3, j);
    indata.emplace_back(4, j);
  }
  Grid A(indata);
  A.boundaries();
  EXPECT_EQ(A.grid[7][5].exist, 0);
  EXPECT_EQ(A.grid[4][5].bound, 0);
  EXPECT_EQ(A.grid[0][5].bound, 1);
  EXPECT_EQ(A.grid[6][0].bound, 1);
  EXPECT_EQ(A.grid[1][3].bound, 0);
}

TEST(GridTransfer__Test, Transfer_Test) {
  e[0] = {0., 0.};
  e[1] = {1., 0.};
  e[2] = {0., 1.};
  e[3] = {-1., 0.};
  e[4] = {0., -1.};
  e[5] = {1., 1.};
  e[6] = {-1., 1.};
  e[7] = {-1., -1.};
  e[8] = {1., -1.};
  // i did initialization here because main functions are conflicting TODO: fix
  // this later
  std::vector<std::pair<int, int>> indata;
  for (size_t j = 0; j < 6; ++j) {
    indata.emplace_back(0, j);
    indata.emplace_back(1, j);
    indata.emplace_back(5, j);
    indata.emplace_back(6, j);
    indata.emplace_back(7, j);
  }
  for (size_t j = 0; j < 5; ++j) {
    indata.emplace_back(2, j);
    indata.emplace_back(3, j);
    indata.emplace_back(4, j);
  }
  Grid A(indata);
  A.boundaries();
  A.grid[2][2].f[1] = 1.;
  A.transfer(2, 2);
  EXPECT_EQ(A.grid[3][2].f_temp[1], 1); // simple move
  A.grid[6][3].f[5] = 0;
  A.grid[7][4].f_eq[7] = 2.;
  A.transfer(6, 3);
  EXPECT_EQ(A.grid[6][3].f_temp[7], 2); // double bound
  A.grid[7][4].f_eq[6] = 6;
  A.grid[7][2].f_eq[6] = 0;
  A.grid[6][2].f[5] = 0;
  A.transfer(6, 2);
  EXPECT_EQ(A.grid[6][4].f_temp[6], 3); // simple bound left wall
  A.grid[6][4].f[6] = 0;
  A.grid[5][5].f_eq[8] = 4;
  A.transfer(6, 4);
  EXPECT_EQ(A.grid[6][4].f_temp[8], 4); // concave corner
  A.grid[6][3].f[6] = 0;
  A.grid[5][4].f_eq[8] = 5;
  A.transfer(6, 3);
  EXPECT_EQ(A.grid[6][3].f_temp[8], 5); // convex corner
}
