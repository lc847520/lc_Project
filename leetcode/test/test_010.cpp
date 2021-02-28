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
class Solution10 {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {

        if (sweetness.size() == 0) {
            return 0;
        }

        uint32_t sweetNum = sweetness.size();
        uint32_t blockNum = K + 1;

        vector<int > preSum(sweetNum + 1, 0);
        int sum = 0;
        for (int i = 0; i < sweetNum; ++i) {
            sum += sweetness[i];

            preSum[i+1] = sum;
        }

        if (K == 0) {
            return preSum[sweetNum];
        }

        int left = 0;
        int right = 1e9;
        int middle = 0;
        while (right - left > 1) {
            middle = (left + right) / 2;
            if (CanAlloc(preSum, middle, blockNum)) {
                right = middle;
            } else {
                left = middle;
            }
        }

        return left;
    }

    bool CanAlloc(vector<int> &preSum, int middle, uint32_t blockNum)
    {
        int count = 0;
        int preIndex = 0;
        int curSum = 0;
        for (int i = 1; i < preSum.size(); ++i) {
            curSum = preSum[i] - preSum[preIndex];
            if (curSum >= middle) {
                count++;
                preIndex = i;
            }
        }

        if (count < blockNum) {
            return true;
        }

        return false;
    }
};


class Solution10Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution10Test, test01)
{
  Solution10 solution;
  vector<int> sweetness = {87506,32090,9852,96263,52415,67669,10703,27,98672,48664};
  EXPECT_EQ(225735, solution.maximizeSweetness(sweetness, 1));

}
