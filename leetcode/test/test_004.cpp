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

class Solution04 {
public:
    int equalSubstring(string s, string t, int maxCost) {

        InitCost(s, t);

        uint32_t start = 0;
        uint32_t end = 0;
        uint32_t len = s.length();
        int32_t totalCost = 0;

        while (true) {

            if (start >= len || end >= len) {
                break;
            }

            uint32_t curCost = GetCost(start, end);
            if (curCost <= maxCost) {
                CalcMaxNum(start, end);
                end++;
            } else {
                if (start >= end) {
                    end++;
                }

                start++;
            }
        }

        return maxNum_;
    }

    void CalcMaxNum(uint32_t start, uint32_t end)
    {
        int nums = end - start + 1;
        maxNum_ = nums > maxNum_ ? nums : maxNum_;
    }

    uint32_t GetCost(uint32_t start, uint32_t end)
    {
        if (start == 0 && end == 0) {
            return diffCost_[0];
        }

        if (start == 0) {
            return diffCost_[end];
        }

        return diffCost_[end] - diffCost_[start - 1];
    }

    void InitCost(string &src, string &dst)
    {
        uint32_t len = src.length();
        uint32_t cost = 0;

        for (int i = 0; i < len; ++i) {
            cost += abs(src[i] - dst[i]);
            diffCost_.push_back(cost);
        }
    }

private:
    vector<int> diffCost_;
    uint32_t maxNum_ = {0};
};



class Solution04Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution04Test, test01)
{
    Solution04 solution;
    string s = "abcd";
    string t = "bcdf";
    uint32_t cost = 3;

    ASSERT_EQ(solution.equalSubstring(s, t, cost), 3);
}

TEST_F(Solution04Test, test02)
{
    Solution04 solution;
    string s = "abcd";
    string t = "cdef";
    uint32_t cost = 3;

    ASSERT_EQ(solution.equalSubstring(s, t, cost), 1);
}
TEST_F(Solution04Test, test03)
{
    Solution04 solution;
    string s = "abcd";
    string t = "acde";
    uint32_t cost = 0;

    ASSERT_EQ(solution.equalSubstring(s, t, cost), 1);
}
