#include "leetcode.hpp"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; ; j++) {
                if (j == n) {
                    j = 0;
                }
                if (nums[i] < nums[j]) {
                    ans.push_back(nums[j]);
                    break;
                }
                if (j == i) {
                    ans.push_back(-1);
                    break;
                }
            }
        }
        return ans;
    }
};