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

class Solution09 {
public:
    double minmaxGasDist(vector<int>& stations, int K) {

        int32_t stationNum = stations.size();
        vector<double> distances(stationNum - 1, 0);

        for (int i = 1; i < stationNum; ++i) {
           distances[i - 1] = stations[i] - stations[i - 1];
        }

        double left = 0;
        double right = 1e8;
        double middle = 0;
        while (left <= right) {
           middle = (left + right) / 2;
           if (IsValidDistance(distances, middle, K)) {
               right = middle;
           } else {
               left = middle;
           }

           if (right - left <= 1e-6) {
               break;
           }
        }

        return left;
    }

    bool IsValidDistance(vector<double> &distance, double middle, int K)
    {
        int count = 0;
        for (int i = 0; i < distance.size(); ++i) {
            count += static_cast<int>(distance[i] / middle);
        }

        if (count <= K) {
            return true;
        }

        return false;
    }
};

class Solution09Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution09Test, test01)
{
  Solution09 solution;
  vector<int> stations = {1,2,3,4,5,6,7,8,9,10};
//  EXPECT_DOUBLE_EQ(0.5, (solution.minmaxGasDist(stations, 9) - 0.5));

}
