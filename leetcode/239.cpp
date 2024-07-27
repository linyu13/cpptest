#include "leetcode.hpp"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // int max_num = INT_MIN;
        // int n = nums.size();
        // vector<int> ans;
        // map<int, int> maxNum;
        // for (int i = 0, j = 0; i < n; i++) {
        //     while (i - j + 1 > k) {
        //         j++;
        //         ans.emplace_back(max_num);
        //     }
        //     max_num = max(max_num, nums[i]);
        //     if (max_num != pre) {
        //         pre = max_num;
        //         max_index = i;
        //     }
        //     if (max_index + 1 == j && i - max_index == k) {
        //         int max_x = INT_MIN;
        //         int pre_x = INT_MIN;
        //         for (int x = max_index + 1; x <= i; x++) {
        //             max_x = max(max_x, nums[x]);
        //             if (max_x != pre_x) {
        //                 pre_x = max_x;
        //                 max_index = x;
        //             }
        //         }
        //         max_num = max_x;
        //         pre = max_num;
        //     }
        // }
        // for (int i = n - k; i < n; i++) {
        //     int max_x = INT_MIN;
        //     max_x = max(max_x, nums[i]);
        // }
        // ans.emplace_back(max_num);
        // return ans;

        // int maxIndex = 0;
        // for (int i = 1; i < k; i++) {
        //     if (nums[i] > nums[i - 1]) {
        //         maxIndex = i;
        //     }
        // }
        // ans.push_back(nums[maxIndex]);
        // for (int left = 1, right = k; right < n; left++) {
        //     if (nums[right] >= nums[maxIndex]) {
        //         maxIndex = right;
        //         ans.push_back(nums[maxIndex]);
        //         right++;
        //     }
        //     else {
        //         for (int i = left; i <= k + left - 1; i++) {
        //             if (nums[i] > nums[i - 1]) {
        //                 maxIndex = i;
        //                 ans.push_back(nums[maxIndex]);
        //                 right++;
        //             }
        //         }
        //     }
        // }

        // return ans;

        // 优先队列的方法 第一个元素是 数据 第二个元素是 下标
        // 目的为 数据大的数字永远在最前面
        priority_queue<pair<int, int>> p;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            p.emplace(nums[i], i);
        }
        ans.push_back(p.top().first);
        for (int i = k; i < n; i++) {
            p.emplace(nums[i], i);
            // 目的是 判断队列首元素是否为已经离开窗口的元素
            // 即 窗口左边界左端第一个元素
            // 如果是 弹出首个元素
            while (p.top().second <= i - k) {
                p.pop();
            }
            ans.push_back(p.top().first);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums.assign({ 1, 3, -1, -3, 5, 3, 6, 7 });
    vector<int> ans = sol.maxSlidingWindow(nums, 3);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
}
