#include "leetcode.hpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (k <= n / 2) {
            for(int i = n - 1; i >= n / 2; i--) {
                if (k == n - i) {
                    return nums[i];
                }
            }
        } else {
            for (int i = 0; i <= n / 2; i++) {
                if (k == n - i) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums.assign({1});
    cout << sol.findKthLargest(nums, 1) << endl;
}