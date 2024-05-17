#include "leetcode.hpp"

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> judge;
        int n = nums.size();
        int max = nums[n - 1];
        for (int i = 1; i <= max; i++) {
            judge.push_back(i);
        }
        judge.push_back(max);
        int j = 0;
        for (int i = 0; i < n; i++, j++) {
            if (j >= max + 1){
                return false;
            }
            if (judge[i] != nums[i]) {
                return false;
            }
        }
        if (j != max + 1) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({1, 1, 1});
    cout << sol.isGood(nums) << endl;

}