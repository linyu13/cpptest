#include "leetcode.hpp"

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());
        int pre = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int num = candyType[i];
            if (num != pre) {
                cnt++;
                pre = num;
            }
            if (cnt == n / 2) {
                break;
            }
        }

        return cnt;
    }
};