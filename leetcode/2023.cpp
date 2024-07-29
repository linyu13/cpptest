#include "leetcode.hpp"

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int tarSize = target.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int strSize = nums[i].size();
            string newStr = target.substr(0, strSize);
            if (newStr == nums[i]) {
                for (int j = 0; j < n; j++) {
                    if (nums[i] + nums[j] == target && i != j) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};