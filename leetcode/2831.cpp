#include "leetcode.hpp"

class Solution
{
public:
    int longestEqualSubarray(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].emplace_back(i);
        }
        // 以上操作目的为将数字相同的下标写入对应数组，方便后续对数组大小差值进行判断
        int max_num = 0;
        // 挨个遍历
        for (auto& [_, vec] : map) {
            for (int i = 0, j = 0; i < vec.size(); i++) {
                // 当 右指针指向的下标 与 左指针指向的下标 的差 与 左右指针 的差 大于k 时移动左指针
                // 倘若上述条件成立 意味着 这样的窗口不足以满足条件：即在k次操作内实现 等值子数组
                while (vec[i] - vec[j] - (i - j) > k) {
                    j++;
                }
                // max_num记录最大值
                max_num = max(max_num, (i - j + 1));
            }
        }

        return max_num;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums.assign({ 1, 3, 2, 3, 1, 7, 4, 5, 3 });
    cout << sol.longestEqualSubarray(nums, 3) << endl;
}
