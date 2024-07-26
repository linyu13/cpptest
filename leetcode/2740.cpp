#include "leetcode.hpp"

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 2) {
            return abs(nums[1] - nums[0]);
        }
        int ans = nums[1];
        // 最佳方案 : 找到最小的差值 将其中的较大数单独为一组 其余数为另一组
        // 此时只需要找到整个数组的最小差值即可
        for (int i = 1; i < n; i++) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};