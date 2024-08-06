#include "leetcode.hpp"

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int left = 1;
        int right = 0;
        for (auto vec : meetings) {
            // 起始天大于原先记录的结束天
            if (vec[0] > right) {
                // 更新 days 
                days = days - (right - left + 1);
                // 当更新左值 合并
                left = vec[0];
            }
            // 更新右值 合并
            right = max(right, vec[1]);
        }
        // 对最后一组进行计算
        days = days - (right - left + 1);
        return days;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> meetings;
    meetings.assign({{5,7},{1,3},{9,10}});
    cout << sol.countDays(10, meetings) << endl;
}