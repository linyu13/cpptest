#include "leetcode.hpp"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int re = 0;
        for (int i = 0, j = 0; i < n; i++ ) {
            while (nums[i] - nums[j] > 2 * k) {
                j++;
            }
            re = max(re, i - j + 1);
        }
        return re;
    }
};