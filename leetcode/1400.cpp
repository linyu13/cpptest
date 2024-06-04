#include "leetcode.hpp"

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) {
            return 0;
        }
        map<char, int> ch;
        for (int i = 0; i < n; i++) {
            ch[s[i]-'a']++;
        }
        int sig_cnt = 0;
        for (auto c : ch) {
            if (c.second % 2 == 1) {
                sig_cnt++;
            }
        }
        return sig_cnt <= k;
    }
};

int main() {
    Solution sol;
    cout << sol.canConstruct("jsautfnlcmwqpzycehdulmdencthhlzsnijd", 35) << endl;
}