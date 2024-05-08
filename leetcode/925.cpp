#include "leetcode.hpp"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        int i = 0;
        for (int j = 0; j < m; ) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == n;
    }
};
int main() {
    Solution sol;
    string name = "alex";
    string typed = "aaleex";
    cout << sol.isLongPressedName(name, typed) << "\n";
}