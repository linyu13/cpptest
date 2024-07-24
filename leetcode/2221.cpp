#include "leetcode.hpp"

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({1,2,3,4,5});
    cout << sol.triangularSum(nums) << endl;
}