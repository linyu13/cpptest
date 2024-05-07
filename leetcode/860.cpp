#include "leetcode.hpp"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int  i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) { // 5元不找零
                five++;
            }else if (bills[i] == 10) {
                if (five) { // 十元情况下若有五元则找零，没有直接错误
                    ten++;
                    five--;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (ten && five) { // 理想情况为各一张十元和五元
                    ten--;
                    five--;
                } else {
                    five -=3;
                }
            } // 针对 five -= 3 这一情况判断
            if (five < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills;
    bills.assign({10, 5});
    Solution sol;
    cout << sol.lemonadeChange(bills) << "\n";
}