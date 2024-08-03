#include "leetcode.hpp"
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        // 题面并未要求矩形边框的起始点是坐标之一 且并未规定 y 的具体范围 所以只需思考横坐标即可
        // 故只需要考虑极限情况即可
        int ans = 0;
        int index = -1;
        for (auto vec : points) {
            // 这里更新 index 为极限情况 过滤处于 index 以内的坐标
            if (vec[0] > index) {
                index = vec[0] + w;
                ans++;
            }
        }
        return ans;
    }
};