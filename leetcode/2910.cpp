#include "leetcode.hpp"

class Solution
{
public:
    int minGroupsForValidAssignment(vector<int>& balls)
    {
        map<int, int> map_ball;
        int n = balls.size();
        int min_num = INT_MAX;
        for (int i = 0; i < n; i++) {
            map_ball[balls[i]]++;
        }
        for (auto piar : map_ball) {
            min_num = min(min_num, piar.second);
        }
        int sum = 0;
        for (auto piar : map_ball) {
            if (piar.second % min_num == 0) {
                if (piar.second = min_num + 1) {
                    sum = sum + piar.second / (min_num + 1);
                } else {
                    sum = sum + piar.second / (min_num + 1) + 1;
                }
            }
            else if (piar.second % min_num == 1) {
                sum = sum + piar.second / min_num;
            }
            else {
                sum = sum + piar.second / min_num + 1;
            }
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> balls;
    balls.assign({ 10, 10, 10, 3, 1, 1 });
    cout << sol.minGroupsForValidAssignment(balls) << endl;
}
