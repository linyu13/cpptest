#include "leetcode.hpp"

class Solution
{
public:
    int reverse(int x)
    {
        string s = to_string(x);
        int n = s.size();
        int re = 0;
        if (s[0] == '-') {
            for (int i = n - 1; i > 0; i--) {
                if (re < INT_MIN / 10 || re > INT_MAX / 10) {
                    return 0;
                }
                int a = s[i] - '0';
                re = re * 10 + a;
            }
            re = -re;
        }
        else {
            for (int i = n - 1; i > -1; i--) {
                if (re < INT_MIN / 10 || re > INT_MAX / 10) {
                    return 0;
                }
                int a = s[i] - '0';
                re = re * 10 + a;
            }
        }
        return re;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverse(1534236469) << endl;
}
