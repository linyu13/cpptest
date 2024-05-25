#include "leetcode.hpp"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int max_num = INT_MIN;
        int n = nums.size();
        int max_index = -1;
        vector<int> ans;
        int pre = max_num;
        for (int i = 0, j = 0; i < n; i++) {
            while (i - j + 1 > k) {
                j++;
                ans.emplace_back(max_num);
            }
            max_num = max(max_num, nums[i]);
            if (max_num != pre) {
                pre = max_num;
                max_index = i;
            }
            if (max_index + 1 == j && i - max_index == k) {
                int max_x = INT_MIN;
                int pre_x = INT_MIN;
                for (int x = max_index + 1; x <= i; x++) {
                    max_x = max(max_x, nums[x]);
                    if (max_x != pre_x) {
                        pre_x = max_x;
                        max_index = x;
                    }
                }
                max_num = max_x;
                pre = max_num;
            }
        }
        for (int i = n - k; i < n; i++) {
            int max_x = INT_MIN;
            max_x = max(max_x, nums[i]);
        }
        ans.emplace_back(max_num);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums.assign({ -6, -10, -7, -1, -9, 9, -8, -4, 10, -5, 2, 9, 0, -7, 7, 4, -2, -10, 8, 7 });
    vector<int> ans = sol.maxSlidingWindow(nums, 7);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
}
