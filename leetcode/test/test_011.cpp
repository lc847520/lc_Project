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


class Solution11 {
public:
    int trap(vector<int>& height) {

        if (height.size() <= 2) {
            return 0;
        }

        std::stack<int> indexStack;
        int preIndex = 0;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            preIndex = !indexStack.empty() ? indexStack.top() : i;
            while (!indexStack.empty() && height[i] > height[indexStack.top()]) {
                int topIndex = indexStack.top();
                indexStack.pop();
                sum += (height[topIndex] - height[preIndex]) * (i - topIndex - 1);
//                printf("[trap]: (i, topIndex, preIndex, sum) = (%d, %d, %d, %d) \n.", i, topIndex, preIndex, sum);
                preIndex = topIndex;
            }

            if (!indexStack.empty()) {
                sum += (height[i] - height[preIndex]) * (i - indexStack.top() - 1);
//                printf("[trap]: (i, topIndex, preIndex, sum) = (%d, %d, %d, %d) \n.", i, indexStack.top(), preIndex, sum);
            }
            indexStack.push(i);
        }

        if (indexStack.empty()) {
            return sum;
        }

        preIndex = indexStack.top();
        while (indexStack.empty()) {
           int topIndex = indexStack.top();
           indexStack.top();
           sum += (height[topIndex] - height[preIndex]) * (topIndex - preIndex - 1);
           preIndex = topIndex;
        }

        return sum;
    }
};

class Solution11Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution11Test, test01)
{
    Solution11 solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(6, solution.trap(height));

}

TEST_F(Solution11Test, test02)
{
    Solution11 solution;
    vector<int> height = {4,2,0,3,2,5};
    EXPECT_EQ(9, solution.trap(height));

}
