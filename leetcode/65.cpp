#include "leetcode.hpp"

class Solution
{
private:
    regex re;
public:
    Solution()
        : re("^[+-]?(\\d+|\\d+\\.\\d*|\\.\\d+)([eE][+-]?\\d+)?$")
    {
    }
    bool isNumber(string s) { return regex_match(s, re); }
};
