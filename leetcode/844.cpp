#include "leetcode.hpp"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int num_s = s.size();
        int num_t = t.size();
        string ans_s = "";
        string ans_t = "";
        for (int i = 0; i < num_s; i++) {
            if (i <= 1 && s[i] == '#') {
                ans_s = "";
            }
            if (s[i] != '#') {
                ans_s += s[i];
            } else if (!ans_s.empty()){
                ans_s.pop_back();
            }
        }
        for (int i = 0; i < num_t; i++) {
            if (i <= 1 && t[i] == '#') {
                ans_t = "";
            }
            if (t[i] != '#') {
                ans_t += t[i];
            } else if (!ans_t.empty()){
                ans_t.pop_back();
            }
        }

        return ans_s == ans_t;
    }
};