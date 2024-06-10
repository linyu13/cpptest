#include "leetcode.hpp"

class Solution
{
    // map 暴力
public:
    int maximumLength(string s)
    {
        map<char, int> map_s;
        int n = s.size();
        int maxStrNum = -1;
        map<char, int> map_count;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         // 排除不连续的字符串
        //         if (s[i] != s[j]) {
        //             break;
        //         }
        //         // 切割
        //         string st = s.substr(i, j - i + 1);
        //         // 计数并判断
        //         map_s[st]++;
        //         if (map_s[st] >= 3) {
        //             maxStrNum = max(maxStrNum, (int)st.size());
        //         }
        //     }
        // }

        // 此处原为单独计数判断，但是可以挪到两层循环中直接判断  :(
        // for (auto pair : map_s) {
        //     if (pair.second >= 3) {
        //         int x = pair.first.size();
        //         if (x > maxStrNum) {
        //             maxStrNum = x;
        //         }
        //     }
        // }

        int j = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    break;
                }
                cnt++;
            }
            if (map_s.find(s[i]) == map_s.end()) {
                map_s[s[i]] = cnt;
                map_count[s[i]] = j - i;
            }
            else {
                map_s[s[i]] = max(map_s[s[i]], cnt);
                map_count[s[i]] += j - i;
            }
            i = j - 1;
        }
        auto p_s = map_s.begin();
        auto p_count = map_count.begin();
        while (p_count != map_count.end() && p_s != map_s.end()) {
            if (p_s->second >= 3) {
                int x = p_s->second - 2;
                if (x > maxStrNum) {
                    maxStrNum = x;
                }
            } else {
                if (p_count->second >= 3) {
                    maxStrNum = max(maxStrNum, 1);
                }
            }
            p_count++;
            p_s++;
        }
        return maxStrNum;
    }
};

int main()
{
    Solution sol;
    cout << sol.maximumLength("bbc") << endl;
    return 0;
}
