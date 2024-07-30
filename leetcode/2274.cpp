#include "leetcode.hpp"

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n = special.size();
        int bot_spe = special[0] - bottom;
        int spe_top = top - special[n - 1];
        int maxNum = max(bot_spe, spe_top);
        for (int i = 0; i < n - 1; i++) {
            maxNum = max(maxNum, special[i + 1] - special[i] - 1);
        }
        return maxNum;
    }
};

int main() {
    Solution sol;
    vector<int> special;
    special.assign({7,6,8});
    cout << sol.maxConsecutive(6, 8, special) << endl;
}