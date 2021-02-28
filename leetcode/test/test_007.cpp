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

class Solution07 {
public:
  int longestPalindromeSubseq(string s) {

      uint32_t strNum = s.size();
      vector<vector<int>> result(strNum, vector<int>(strNum, 0));
      int maxLen = 0;

      for (int i = 0; i < strNum; ++i) {
          result[i][i] = 1;
      }

      for (int i = (strNum - 1); i >= 0; i--) {
        for (int j = i + 1; j < strNum; ++j) {
            if (s[i] == s[j]) {
                result[i][j] = result[i+1][j-1] + 2;
            } else {
              result[i][j] = max(result[i][j-1], result[i+1][j]);
            }
        }
      }

      return result[0][strNum-1];
  }
};

class Solution07Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution07Test, test01)
{
  Solution07 solution;
  string s = "bbbab";
  EXPECT_EQ(4, solution.longestPalindromeSubseq(s));
}
