#include "leetcode.hpp"

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int sum = 0;
        int line = 0;
        vector<int> costMap;
        int totalOfOnePeople = 0;
        int diffOfOnePeople = 0;
        int pre = 0;
        int diff = 0;
        for (auto row : costs) {
            int flag = 1;
            for (auto cost : row) {
                if (flag) {
                    pre = cost;
                    flag = 0;
                }
                else {
                    diff = cost;
                    totalOfOnePeople += cost;
                }
            }
            diffOfOnePeople = pre - diff;
            costMap.push_back(diffOfOnePeople);
            line++;
        }
        sort(costMap.begin(), costMap.end());
        int n = ((line + 1) / 2);
        for (auto it : costMap ) {
            if (n > 0) {
                totalOfOnePeople += it;
                n--;
            } else {
                break;
            }
        }

        return totalOfOnePeople;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> costs = { { 945, 563 }, { 598, 753 }, { 558, 341 }, { 372, 54 },
                                  { 39, 522 },  { 249, 459 }, { 536, 264 }, { 491, 125 },
                                  { 367, 118 }, { 34, 665 },  { 472, 410 }, { 109, 995 },
                                  { 147, 436 }, { 814, 112 }, { 45, 545 },  { 561, 308 },
                                  { 491, 504 }, { 113, 548 }, { 626, 104 }, { 556, 206 },
                                  { 538, 592 }, { 250, 460 }, { 718, 134 }, { 809, 221 },
                                  { 893, 641 }, { 404, 964 }, { 980, 751 }, { 111, 935 } };
    cout << sol.twoCitySchedCost(costs) << endl;
}
