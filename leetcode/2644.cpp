#include "leetcode.hpp"

class Solution
{
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors)
    {
        int num_div = divisors.size();
        int num_nums = nums.size();
        vector<pair<int, int>> map;
        // 将每一对整数和相对的可整除得分写进对中
        for (int div : divisors) {
            int cnt = 0;
            for (int num : nums) {
                if (num % div == 0) {
                    cnt++;
                }
            }
            map.push_back(make_pair(cnt, div));
        }
        //倒叙排序
        sort(map.begin(), map.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        int i = 0;
        int min_num = map[0].second;
        // 寻找最小整数
        for (i = 0; i < num_div - 1; i++) {
            if (map[i].first == map[i + 1].first) {
                min_num = min(min_num, map[i + 1].second);
            } else {
                break;
            }
        }
        return min_num;
    }
};

int main()
{
    vector<int> nums;
    vector<int> divisors;
    Solution sol;
    nums.assign({ 31,91,47,6,37,62,72,42,85 });
    divisors.assign({ 95,10,8,43,21,63,26,45,23,69,16,99,92,5,97,69,33,44,8 });
    cout << sol.maxDivScore(nums, divisors) << endl;
}
