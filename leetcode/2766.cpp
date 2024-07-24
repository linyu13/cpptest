#include "leetcode.hpp"

class Solution
{
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo)
    {
        map<int, int> index_num;
        for (auto p : nums) {
            index_num[p]++;
        }
        int n = moveFrom.size();
        for (int i = 0; i < n; i++) {
            if (moveFrom[i] != moveTo[i]) {
                index_num[moveTo[i]] += index_num[moveFrom[i]];
                index_num[moveFrom[i]] = 0;
            }
        }
        vector<int> ans;
        for (auto p : index_num) {
            if (p.second) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
