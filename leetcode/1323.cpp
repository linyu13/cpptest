#include "leetcode.hpp"

class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int cnt = 0;
        while (n > 0) {
            n /= 10;
            cnt++;
        }
        n = num;
        int x = num;
        while(n > 0) {
            int a = n / pow(10, cnt - 1);
            if (a == 6) {
                x = 9 * pow(10, cnt - 1) + n % (10, cnt - 1);
                break;
            }
            cnt--;
        }
        return x;
    }
};

int main() {
    Solution sol;
    cout << sol.maximum69Number(9669) << endl;
}