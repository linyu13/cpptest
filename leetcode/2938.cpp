#include "leetcode.hpp"

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long cnt = 0;
        int n = s.size();
        map<int, int> blackCnt;
        auto last = blackCnt.rbegin();
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && flag) {
                blackCnt[i] = 0;
                for (int j = i; j < n; j++) {
                    if (s[j] == '0') {
                        blackCnt[i]++;
                    }
                }
                flag = 0;
            }
            else if (s[i] == '1') {
                last = blackCnt.rbegin();
                pair<const int, int> lastpair = *last;
                int t = 0;
                t = lastpair.second - (i - lastpair.first) + 1;
                blackCnt[i] = t;
            }
        }

        for (auto p : blackCnt) {
            cnt += p.second;
        }

        return cnt;
    }
    // 方法类似于将所有的 1 集中并一起移动
    // 例 100100 识别到第一个 1 之后移动这一个 1 每遇到一个 0 计数器便增加 1 个 1
    // 当遇到第二个 1 时  增加需要移动的 1 的个数  并在后续的移动中一起移动  也就是增加 2
    // 个黑球的移动个数
    // long long minimumSteps(string s)
    // {
    //     long long count = 0;
    //     int cnt = 0;
    //     for (char c : s) {
    //         if (c == '1') {
    //             cnt++;
    //         }
    //         else {
    //             count += cnt;
    //         }
    //     }
    //     return count;
    // }
};

int main()
{
    Solution sol;
    cout << sol.minimumSteps("011") << endl;
}
