#include "leetcode.hpp"

class Solution
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int los = (n + rolls.size()) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> ans;
        // 当丢失的数据比极限值大或小的时候直接返回
        if (los > 6 * n || los < n) {
            return ans;
        }

        // 这里 ind 记录平均数 m 记录需要几个比平均数大 1 的数字来满足最后的和为丢失的数据
        // 简而言之 丢失的所有数据确定的基础为平均数 但因为直接除是整数
        // 所以需要一个数来确定有几个丢失的数大于平均数
        int ind = los / n;
        int m = los % n;
        int cnt = 0;
        while (cnt < n) {
            // cnt 记录数据的数量 此处也可为 (cnt < m ? 1 : 0)
            int num = ind + (cnt >= m ? 0 : 1);
            ans.push_back(num);
            cnt++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         int m = rolls.size();
//         int sum = mean * (n + m);
//         int missingSum = sum;
//         for (int & roll : rolls) {
//             missingSum -= roll;
//         }
//         if (missingSum < n || missingSum > 6 * n) {
//             return {};
//         }
//         int quotient = missingSum / n, remainder = missingSum % n;
//         vector<int> missing(n);
//         for (int i = 0; i < n; i++) {
//             missing[i] = quotient + (i < remainder ? 1 : 0);
//         }
//         return missing;
//     }
// };

int main()
{
    Solution sol;
    vector<int> rolls;
    rolls.assign({ 3, 2, 4, 3 });
    vector<int> ans = sol.missingRolls(rolls, 4, 2);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
}
