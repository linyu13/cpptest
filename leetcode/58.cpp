#include "leetcode.hpp"

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int i = n - 1;
        int cnt = 0;
        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            i--;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLastWord("a ") << endl;
}
