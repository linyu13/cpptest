#include "leetcode.hpp"

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && cnt < k) {
                nums[i] = -nums[i];
                cnt++;
            }
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());
        if ((k - cnt) % 2 == 0) {
            return sum;
        }

        sum = sum - 2 * nums[0];
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({5,6,9,-3,3});
    cout << sol.largestSumAfterKNegations(nums, 2) << endl;
}