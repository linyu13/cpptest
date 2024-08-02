#include "leetcode.hpp"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool judge = true;
        int cnt = 0;
        int pre = nums[0];
        int m = nums.size();
        vector<int> index;
        for (int i = 0; i < m; i++) {
            int n = nums[i];
            if (n < pre) {
                cnt++;
                index.push_back(i);
            }
            if (cnt == 2) {
                judge = false;
            }
            pre = n;
        }
        return judge;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({4,2,1});
    cout << sol.checkPossibility(nums) << endl;
}