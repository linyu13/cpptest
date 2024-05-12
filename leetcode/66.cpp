#include "leetcode.hpp"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int flag = 0;
        digits[n - 1]++;
        vector<int> ret;
        for (int i = n - 1; i >= 0; i--) {
            if (flag == 1) {
                flag = 0;
                digits[i]++;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                flag = 1;
            }
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        ret = digits;
        return ret;
    }
};

int main() {
    vector<int> digits;
    digits.assign({9, 9, 9});
    Solution sol;
    vector<int> vec = sol.plusOne(digits);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}