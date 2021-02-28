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

class Solution547 {

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        cityNum_ = isConnected.size();

        if (cityNum_ == 1) {
            return 1;
        }

        for (int j = 0; j < cityNum_; ++j) {
            cityLeft_.insert(j);
        }

        for (int i = 0; i < cityNum_; ++i) {

            ProcessOneCity(isConnected, i);
        }

        return priovceNum_;

    }

    void ProcessOneCity(vector<vector<int>>& isConnected, int cityNo)
    {
        if (cityLeft_.count(cityNo) == 0) {
            return;
        }

        deque<int> citysQ;
        citysQ.push_back(cityNo);
        cityLeft_.erase(cityNo);
        while (!citysQ.empty()) {
            int topCity = citysQ.front();
            citysQ.pop_front();
            for (auto iter = cityLeft_.begin(); iter != cityLeft_.end();) {
                if (isConnected[topCity][*iter]) {
                    citysQ.push_back(*iter);
                    iter = cityLeft_.erase(iter);
                } else {
                    ++iter;
                }
            }
        }

        priovceNum_++;
    }

private:
    int priovceNum_ = 0;
    int cityNum_ = 0;
    set<int> cityLeft_;
};

class Solution547Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution547Test, test01)
{
    Solution547 solution;
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};

    EXPECT_EQ(2, solution.findCircleNum(isConnected));

}

TEST_F(Solution547Test, test02)
{
    Solution547 solution;
    vector<vector<int>> isConnected = {{1,0,0}, {0,1,0}, {0,0,1}};

    EXPECT_EQ(3, solution.findCircleNum(isConnected));

}
TEST_F(Solution547Test, test03)
{
    Solution547 solution;
    vector<vector<int>> isConnected = {{1,0}, {0,1}};

    EXPECT_EQ(2, solution.findCircleNum(isConnected));

}
TEST_F(Solution547Test, test04)
{
    Solution547 solution;
    vector<vector<int>> isConnected = {{1,1,1}, {1,1,1}, {1,1,1}};

    EXPECT_EQ(1, solution.findCircleNum(isConnected));

}

TEST_F(Solution547Test, test05)
{
    Solution547 solution;
    vector<vector<int>> isConnected = {{1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1}};

    EXPECT_EQ(1, solution.findCircleNum(isConnected));

}
