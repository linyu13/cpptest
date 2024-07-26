#include "leetcode.hpp"

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        // 暴力超时是这样的
        // vector<int> ans;
        // int n = people.size();
        // for (int i = 0; i < n; i++) {
        //     int day = people[i];
        //     int cnt = 0;
        //     for (auto vec : flowers) {
        //         if (day <= vec[1] && day >= vec[0]) {
        //             cnt++;
        //         }
        //     }

        //     ans.push_back(cnt);
        // }

        // return ans;

        // 创建有序图
        map<int, int> cnt;
        // 记录 花开花谢的端点 根据端点的增减判断区间的开花数
        for (auto vec : flowers) {
            cnt[vec[0]]++;
            cnt[vec[1] + 1]--;
        }

        // 绝赞的 独特的 标新立异的 满是破绽的方法 笑(
        // map<int, int> indexOfPeople;
        // int n = 0;
        // for (auto peo : people) {
        //     indexOfPeople[peo] = n;
        //     n++;
        // }
        int n = people.size();
        // 单开一个数组来记录 people 数组中从大到小排序的 原先的 下标
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        // 根据 people 数组中的大小进行排序
        // 目的是使下标与内容有机统一
        sort(indices.begin(), indices.end(), 
        [&](int a, int b) { 
            return people[a] < people[b]; 
        });
        vector<int> ans(n);
        int cntt = 0;
        auto it = cnt.begin();
        // auto itOfIndex = indexOfPeople.begin();
        // 遍历 people 数组 当 cnt 中的第一位大于它 或 cnt 走到末尾时 结束 while 循环
        // 并复用 cntt 变量计算下一情况的数值
        // 这里用到原先的下标来使 ans 数组与原先 people 数组能够一一对应
        for (auto x : indices) {
            while (it != cnt.end() && it->first <= people[x]) {
                cntt += it->second;
                it++;
            }
            ans[x] = cntt;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> flowers;
    vector<int> people;
    flowers.assign({ { 1, 10 }, { 3, 3 } });
    people.assign({ 3, 3, 2 });
    vector<int> ans;
    ans = sol.fullBloomFlowers(flowers, people);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
}
