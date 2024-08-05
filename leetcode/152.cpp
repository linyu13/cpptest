#include "leetcode.hpp"


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int sum = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0){
                sum = nums[i];
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] <= 0) {
                        break;
                    }
                    sum *=nums[j];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({-2,0, -1});
    cout << sol.maxProduct(nums) << endl;
}