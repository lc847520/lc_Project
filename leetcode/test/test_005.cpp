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

class Solution05 {
public:
    int minDistance(string word1, string word2) {

        uint32_t word1Size = word1.size();
        uint32_t word2Size = word2.size();
        
        if (word1Size == 0 || word2Size == 0) {
            return std::max(word1Size, word2Size);
        }
        
        vector<vector<uint32_t >> result(word1Size + 1, vector<uint32_t >(word2Size + 1, 0));

        for (int i = 0; i <= word1Size; ++i) {
            result[i][0] = i;
        }

        for (int j = 0; j <= word2Size; ++j) {
            result[0][j] = j;
        }

        for (int i = 1; i <= word1Size ; ++i) {
          for (int j = 1; j <= word2Size ; ++j) {
              if (word1[i-1] != word2[j-1]) {
                  result[i][j] = min(min(result[i][j-1], result[i - 1][j]), result[i-1][j-1]) + 1;
              } else {
                  result[i][j] = result[i - 1][j - 1];
              }

          }
        }

        return result[word1Size][word2Size];
    }

};



class Solution05Test : public testing::Test {

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

};

TEST_F(Solution05Test, test01)
{
    string word1 = "horse";
    string word2 = "ros";

    Solution05 solution;
    EXPECT_EQ(3, solution.minDistance(word1, word2));
}
