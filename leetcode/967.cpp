#include "leetcode.hpp"

class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<string> ans_string;
        vector<int> re;
        string j = "0";
        int flag = 1;
        for (; j <= "9"; j[0]++) {
            string temp = j;
            for (int i = 0; i < n - 1; i++) {
                if (j[i] - '0' + k >= 10) {
                    if (('0' + (j[i] - '0' - k)) >= '0') {
                        j += ('0' + (j[i] - '0' - k));
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
                else {
                    j += ('0' + (j[i] - '0' + k));
                }
            }
            if (flag) {
                ans_string.push_back(j);
            }
            flag = 1;
            j = temp;
        }
        for (auto st : ans_string) {
            if (st[0] == '0') {
                continue;
            }
            int num = stoi(st);
            re.push_back(num);
        }

        return re;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.numsSameConsecDiff(3, 7);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}
