#include "leetcode.hpp"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<string, int> st;
        vector<string> ans;
        if (n <= 10) {
            return ans;
        }
        for (int left = 0; left <= n - 10; left++) {
            string str = s.substr(left, 10);
            st[str]++;
        }
        for (auto p : st) {
            if (p.second >= 2) {
                string a = p.first;
                ans.push_back(a);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> ans = sol.findRepeatedDnaSequences("AAAAAAAAAAA");
    return 0;
}