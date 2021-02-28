//
// Created by hou on 2020-10-01.
//

#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <gtest/gtest.h>
#include "common.h"

using namespace std;

class Solution02 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> result(nums.size(), -1);
        vector<bool> posUse(nums.size(), false);
        stack<int> posStack;

        if (nums.size() <= 1) {
            return result;
        }

        posStack.push(0);
        int pos = 1;
        posUse[0] = true;
        while (true) {
            while (!posStack.empty() && (nums[posStack.top()] < nums[pos])) {
                result[posStack.top()] = nums[pos];
                int topPos = posStack.top();
                posStack.pop();
                posUse[topPos] = false;
            }

            if (posStack.empty()) {
                posStack.push(pos);
                posUse[pos] = true;
                pos = (pos + 1) % nums.size();
                continue;
            }

            if (posStack.top() == pos) {
                break;
            }

            if (posUse[pos]) {
                break;
            }

            posStack.push(pos);
            posUse[pos] = true;
            pos = (pos + 1) % nums.size();
        }

        return result;
    }
};

class Solution02Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution02Test, test01)
{

    Solution02 solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = {2, -1, 2};

    ASSERT_TRUE(CmpVector(result, solution.nextGreaterElements(nums)));
}

TEST_F(Solution02Test, test02)
{

    Solution02 solution;
    vector<int> nums = {1, 2, 2, 6, 5, 1};
    vector<int> result = {2, 6, 6, -1, 6, 2};

    ASSERT_TRUE(CmpVector(result, solution.nextGreaterElements(nums)));
}


TEST_F(Solution02Test, test03)
{

    Solution02 solution;
    vector<int> nums = {1, 1, 1, 1, 1, 1};
    vector<int> result = {-1, -1, -1, -1, -1, -1};

    ASSERT_TRUE(CmpVector(result, solution.nextGreaterElements(nums)));
}
