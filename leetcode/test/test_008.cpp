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

class Solution08 {
public:
    int longestCommonSubsequence(string text1, string text2) {

        uint32_t text1Len = text1.length();
        uint32_t text2Len = text2.length();
        if (text1Len == 0 || text2Len == 0) {
            return 0;
        }

        vector<vector<int >> result(text1Len+1, vector<int >(text2Len+1, 0));
        for (int i = 0; i < text1Len+1 ; ++i) {
           result[i][0] = 0;
        }

        for (int j = 0; j < text2Len+1; ++j) {
            result[0][j] = 0;
        }

        for (int i = 1; i <= text1Len; ++i) {
          for (int j = 1; j <= text2Len; ++j) {
              if (text1[i-1] == text2[j-1]) {
                  result[i][j] = result[i-1][j-1] + 1;
              } else {
                  result[i][j] = max(result[i][j-1], result[i-1][j]);
              }
          }
        }

        return result[text1Len][text2Len];
    }
};

class Solution08Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution08Test, test01)
{
  Solution08 solution;

}
