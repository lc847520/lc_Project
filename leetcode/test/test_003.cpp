//
// Created by hou on 2020-10-24.
//

#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <iostream>
#include <gtest/gtest.h>
#include "common.h"

using namespace std;

class Solution03 {
public:
    int numIslands(vector<vector<char>>& grid) {

        rows_ = grid.size();
        cols_ = grid[0].size();
        InitVisit(rows_, cols_, grid);

        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (!IsCanVisit(i, j)) {
                    continue;
                }

                FindLand(i, j);
//                std::cout << "find iland end." << std::endl;
                landNums_++;
            }
        }

//        std::cout << "numbs = " << landNums_ << std::endl;
        return landNums_;
    }

    void FindLand(uint32_t row, uint32_t col)
    {
        visitFlags_[row][col] = true;
//        std::cout << "visit" << "row = " << row << "col = " << col << std::endl;
        if (IsCanVisit(row, col + 1)) {
            FindLand(row, col + 1);
        }

        if (IsCanVisit(row + 1, col)) {
            FindLand(row + 1, col);
        }

        if (IsCanVisit(row, col - 1)) {
            FindLand(row, col - 1);
        }

        if (IsCanVisit(row - 1, col)) {
            FindLand(row - 1, col);
        }
    }

    bool IsCanVisit(uint32_t row, uint32_t col)
    {
        if (row >= rows_ || col >= cols_) {
            return false;
        }

        return !visitFlags_[row][col];
    }

    void InitVisit(uint32_t rows, uint32_t cols, vector<vector<char>>& grid)
    {
        for (int i = 0; i < rows; ++i) {
            vector<bool> visit;
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '0') {
                    visit.push_back(true);
                } else {
                    visit.push_back(false);
                }
            }
            visitFlags_.emplace_back(visit);
        }
    }

private:
    vector<vector<bool>> visitFlags_;
    uint32_t rows_;
    uint32_t cols_;
    int landNums_ = {0};
};



class Solution03Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution03Test, test01)
{

    Solution03 solution;
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };

    ASSERT_EQ(solution.numIslands(grid), 1);
}


TEST_F(Solution03Test, test02)
{

    Solution03 solution;
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
    };

    ASSERT_EQ(solution.numIslands(grid), 3);
}
