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


class Solution1564 {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {

        priority_queue<int, vector<int>> boxesQueue;
        priority_queue<int, vector<int>> wareQueue;

        for (auto &box : boxes) {
            boxesQueue.push(box);
        }

        for (auto &ware : warehouse) {
            wareQueue.push(ware);
        }
    }
};
