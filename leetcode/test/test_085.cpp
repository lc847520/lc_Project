//
// Created by hou on 2020-12-27.
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

class Solution085 {

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        row_ = matrix.size();
        if (row_ != 0) {
            col_ = matrix[0].size();
        }

        if (row_ == 0 || col_ == 0) {

        }

        vector<vector<int>> seqNumMat(row_, vector<int>(col_, 0));
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {
                if (matrix[i][j] == '1') {
                    seqNumMat[i][j] = ((j == 0) ? 0 : seqNumMat[i][j - 1]) + 1;
                    printf("seq num mat: [%d, %d] = %d\n", i,j, seqNumMat[i][j]);
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {
                int area = seqNumMat[i][j];
                int width = seqNumMat[i][j];
                int height = 1;

                for (int k = i - 1; k >= 0; --k) {
                    width = min(width, seqNumMat[k][j]);
                    area = max(area, width * (++height));

                    if (width == 0) {
                        break;
                    }
                }

                maxArea = max(maxArea, area);
                printf("max area: [%d, %d] = %d\n", i, j, maxArea);
            }
        }

        return maxArea;
    }

private:
    int row_;
    int col_;
};

class Solution085Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution085Test, test01)
{
    Solution085 solution;
    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'},
                                  {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    EXPECT_EQ(6, solution.maximalRectangle(matrix));

}

TEST_F(Solution085Test, test02)
{
    Solution085 solution;
    vector<vector<char>> matrix;

    EXPECT_EQ(0, solution.maximalRectangle(matrix));

}
TEST_F(Solution085Test, test03)
{
    Solution085 solution;
    vector<vector<char>> matrix = {{'1'}};

    EXPECT_EQ(1, solution.maximalRectangle(matrix));

}

TEST_F(Solution085Test, test04)
{
    Solution085 solution;
    vector<vector<char>> matrix = {{'0', '0'}};

    EXPECT_EQ(0, solution.maximalRectangle(matrix));

}