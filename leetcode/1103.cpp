#include "leetcode.hpp"

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int index = 0;
        vector<int> ans(num_people);
        int cnt = 1;
        while(candies) {
            ans[index] += cnt;
            candies -= cnt;
            if (candies < cnt + 1) {
                cnt = candies;
            } else {
                cnt++;
            }
            if (index == num_people - 1) {
                index = 0;
            } else {
                index++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> ans = sol.distributeCandies(10, 3);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}