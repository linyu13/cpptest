#include "leetcode.hpp"

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) {
            return false;
        }

        if (x == 0 || y == 0) {
            return target == 0 || x + y == target;
        }

        return target % __gcd(x, y) == 0;
    }
};
int main() {
    Solution sol;
    cout << sol.canMeasureWater(3, 5, 4) << endl;
}