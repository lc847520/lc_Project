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

//struct cmp{
//    bool operator(const vector<int> &lval, const vector<int> &rval) {
//
//    }
//};

class Solution06 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        if (envelopes.size() == 0) {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &l, const vector<int> &r) {
            if (l[0] < r[0]) {
                return true;
            } else if (l[0] == r[0]) {
                return l[1] < r[1];
            }

            return false;
        });

        uint32_t enveNum = envelopes.size();
        vector<int> result(enveNum, 0);
        result[0] = 1;
        int maxNum = 0;
        int resultMax = 1;
        for (int i = 1; i < envelopes.size(); ++i) {
            maxNum = 0;
          for (int j = 0; j < i ; ++j) {
              if (envelopes[i][0] == envelopes[j][0]) {
                continue;
              }

              if (envelopes[i][1] > envelopes[j][1]) {
                  maxNum = max(maxNum, result[j]);
              }
          }

          result[i] = maxNum + 1;
          resultMax = max(resultMax, result[i]);
        }

        return resultMax;
    }
};



class Solution06Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution06Test, test01)
{
    Solution06 solution;
    vector<vector<int>> vnvelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    EXPECT_EQ(3, solution.maxEnvelopes(vnvelopes));
}
