#include "leetcode.hpp"
#include <map>
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        vector<vector<int>> ans;
        map<int, int> judge;
        // 遍历matches
        for (int j = 0; j < matches[0].size(); j++) {
            for (int i = 0; i < matches.size(); i++) {
                int num = matches[i][j];
                // 第一种 先遍历 赢的情况
                if (j == 0) {
                    auto it = judge.find(num);
                    if (it == judge.end()) {
                        judge.insert(make_pair(num, 0));
                    }
                }
                // 输的情况
                else {
                    auto it = judge.find(num);
                    if (it == judge.end()) {
                        judge.insert(make_pair(num, 1));
                    }
                    // 当找得到输的数字时直接操作对应的值
                    else {
                        it->second++;
                    }
                }
            }
        }
        // 添加空行
        ans.push_back({});
        ans.push_back({});
        for (const auto& it : judge) {
            // 数字输的情况对应为0时加到第一行
            if (it.second == 0) {
                ans[0].push_back(it.first);
            }
            // 数字输的情况对应为1时加到第二行
            else if (it.second == 1) {
                ans[1].push_back(it.first);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matches;
    matches.assign({ { 1, 3 },
                     { 2, 3 },
                     { 3, 6 },
                     { 5, 6 },
                     { 5, 7 },
                     { 4, 5 },
                     { 4, 8 },
                     { 4, 9 },
                     { 10, 4 },
                     { 10, 9 } });
    vector<vector<int>> ans = sol.findWinners(matches);
    for (const auto& row : ans) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl; // 每输出完一行，换行
    }
}
