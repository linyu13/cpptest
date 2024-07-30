#include "leetcode.hpp"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60] = {}, res = 0;
        for(int i = 0; i < time.size(); i++) {
            // 多了一个 % 60 的意义为处理 time[i] % 60 == 0 的导致数组越界的情况
            // 核心思路为 记录每一个情况还差多少就满 60 的数量
            // 在遍历的过程中实现每一个组合
            res += count[(60 - time[i] % 60) % 60];
            count[time[i] % 60]++;
        }
        return res;
    }
};