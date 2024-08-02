#include "leetcode.hpp"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // 排序 把原二维数组的顺序按照第一个数进行排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int begin = intervals[0][0];
        int end = intervals[0][1];
        for (auto vec : intervals) {
            if (vec[1] > end && vec[0] > end) {
                vector<int> temp;
                temp.push_back(begin);
                temp.push_back(end);
                ans.push_back(temp);
                begin = vec[0];
                end = vec[1];
            }
            else if (vec[1] > end && vec[0] <= end) {
                end = vec[1];
            }
        }
        vector<int> temp;
        temp.push_back(begin);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals;
    intervals.assign({ { 1, 4 }, { 4, 5 } });
    sol.merge(intervals);
}
