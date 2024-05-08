#include "leetcode.hpp"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int index = -1;
        int ret = 0;

        unordered_set<char> hash;
        // i为左指针
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                // 删除第一个字符
                hash.erase(s[i - 1]);
            }
            while (!hash.count(s[index + 1]) && index + 1 < n) {
                // 当即将新加入的字符在hash中出现次数为0  且index在合理范围内时进入
                hash.insert(s[index + 1]); // 写入hash
                index++;                   // 右指针指向下一个
            }
            // 比较二者大小 index - i + 1为当前符合题意的字符串的的长度
            ret = max(ret, index - i + 1);
        }
        return ret;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << "\n";
}

