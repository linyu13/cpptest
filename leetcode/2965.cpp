#include "leetcode.hpp"

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        map<int, int> num;
        int more = 0;
        int lost = 0;
        int n = grid.size();
        // 遍历 找到多出来的数字
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                num[grid[i][j]]++;
                if (num[grid[i][j]] == 2) {
                    more = grid[i][j];
                }
            }
        };
        // 遍历找出缺少的数字
        for (auto it = num.begin(); it != num.end(); it++) {
            if (it->first + 1 != (++it)->first) {
                // cout << (it--)->first << endl;
                lost = (--it)->first + 1;
                break;
            }
            it--;
        }
        if (lost > n * n) {
            lost = 1;
        }
        vector<int> ans;
        ans.push_back(more);
        ans.push_back(lost);
        return ans;
    }
};



int main()
{
    Solution sol;
    vector<vector<int>> grid = { {2,2},{3,4} };
    vector<int> ans = sol.findMissingAndRepeatedValues(grid);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
}
