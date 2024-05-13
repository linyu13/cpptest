#include "leetcode.hpp"

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < batteryPercentages.size(); i++) {
            if ((batteryPercentages[i] -= cnt) > 0) {
                sum++;
                cnt++;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> batteryPercentages;
    batteryPercentages.assign({1, 1, 2, 1, 3});
    Solution sol;
    sol.countTestedDevices(batteryPercentages);
}