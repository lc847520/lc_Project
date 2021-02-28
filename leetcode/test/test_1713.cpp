//
// Created by hou on 2021-01-10.
//

#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include <gtest/gtest.h>
#include "common.h"

using namespace std;


class Solution1713 {
public:
    int respace(vector<string>& dictionary, string sentence) {

        num_ = sentence.length();
        if (num_ == 0) {
            return 0;
        }

        Init(dictionary);

        for (int i = 1; i <= num_; ++i) {
            leftNum_[i] = GetLestCharNum(sentence, i);
        }

        return leftNum_[num_];

    }

    int GetLestCharNum(const string& sentence, int pos)
    {
        int minLeftChar = num_ + 1;
        if (lastCharStr_.count(sentence[pos -1]) == 0) {
            return leftNum_[pos - 1] + 1;
        }

        auto strs = lastCharStr_.at(sentence[pos - 1]);
        for (auto &str : strs) {
            if (str.length() > pos || str != sentence.substr(pos - str.length(), str.length())) {
                minLeftChar = std::min(minLeftChar, leftNum_[pos -1] + 1);
            } else {
                minLeftChar = std::min(minLeftChar, leftNum_[pos - str.length()]);
            }
        }

        return minLeftChar;
    }

    void Init(const vector<string>& dictionary)
    {
        leftNum_.resize(num_ + 1, 0);
        for (auto &str : dictionary) {
            char lastChar = str[str.length() -1];
            if (lastCharStr_.count(lastChar) == 0) {
                lastCharStr_[lastChar] = vector<string>(1, str);
            } else {
                lastCharStr_[lastChar].emplace_back(str);
            }
        }
    }

private:
    int32_t num_;
    std::vector<int> leftNum_;
    std::map<char, std::vector<std::string>> lastCharStr_;
};
