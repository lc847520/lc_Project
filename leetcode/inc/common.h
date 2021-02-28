//
// Created by hou on 2020-10-01.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename  T>
bool CmpVector(const vector<T> &src, const vector<T> &dst)
{
    if (src.size() != dst.size()) {
        return false;
    }

    for (int i = 0; i < src.size(); ++i) {
        if (src[i] != dst[i]) {
            return false;
        }
    }

    return true;
}

#endif //LEETCODE_COMMON_H
