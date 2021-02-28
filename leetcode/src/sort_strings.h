//
// Created by hou on 2020-08-09.
//
/**
 *  给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 *  换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * */

#include <string>

using namespace std;

class SortStrings {
public:
    bool checkInclusion(std::string s1, std::string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        if (s1.empty() || s2.empty()) {
            return true;
        }

        for (int i = 0; i < s1.size(); ++i) {

            std::string s1Sub = s1.erase(s1[i], 1);

            int pos = 0;
            while (pos != std::string::npos) {

                pos = s2.find_first_of(s1[i]);
                if (pos == std::string::npos) {
                    return false;
                }

                if (pos == s2.size() - 1 && (i != s1.size() -1)) {
                    return false;
                }

                if (checkInclusion(s1Sub, s2.substr(pos+1))) {
                    return true;
                }
            }
        }
    }

};
