#include "leetcode.hpp"

class Solution {
public:
    int minimumTime(string s) {
        /*
            推导过程可以说是不一般的逆天
            可以视为把左边的一部分移除 把右边的一部分移除 保留中间的一部分并且从当中抽离 '1'
            ps : 此处的 i 与 j 均为代指较靠前的部分的分界 和靠后的分界 并无具体变量
            该过程消耗        i      +       (n - j + 1)     +         cnt([i, j]) * 2
                     抽调前面所有的消耗     抽调后面所有的消耗         抽调中间的消耗
            cnt([i, j]) 是区间 [i, j] 当中的 '1' 的数量 可以写作 pre[j] - pre [i]
            化简为 (i - pre[i] * 2) + (pre[j] * 2 - j) + (n + 1)
            使用 presum 统计前 x 个数据中 '1' 的个数参与计算
        */
        int ans = INT_MAX;
        int n = s.size();
        int presum = 0;
        int premin = 0;
        // presum 表示前缀中的 '1' 的数量
        // premax 表示前缀当中最小的i - 2 * presum
        for (int j = 0; j < n; ++j) {
            // j 可以说是又当爹又当妈的
            // 在 premax 当中 j 视为推导过程当中的 i 来计算最小可能的 前缀和
            // 在获取最小的前缀和的同时 同步获取 presum 的值计算该种情况下的前后缀需要消耗的时间
            // 同时为下一次计算 premax 做准备
            premin = min(premin, j - presum * 2);
            presum += (s[j] - '0');
            ans = min(ans, premin + 2 * presum - j);
        }
        // 进行最后一次比较 观察使用前缀和的情况和直接把所有都移除的情况哪一个更小
        return min(ans + n - 1, n);
    }
};

int main() {
    Solution sol;
    cout << sol.minimumTime("1100101") << endl;
}