#include "leetcode.hpp"

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cnt = 0;
        int n = rungs.size();
        for (int i = 0; i < n; i++) {
            int dif = 0;
            if (i == 0) {
                dif = rungs[0] - 0;
            } else {
                dif = rungs[i] - rungs[i - 1];
            }
            if (dif > dist) {
                int a = (dif - dist) / dist;
                int b = (dif - dist) % dist ? 1 : 0;
                // cout << a << '\t' << b << endl;
                cnt += a + b; 
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> rungs;
    rungs.assign({3});
    cout << sol.addRungs(rungs, 1) << endl;
    return 0;
}