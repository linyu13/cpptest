#include "leetcode.hpp"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int cnt = 0;
        int left = 0;
        int right = n - 1;
        // 一轻一重搭配
        while (left <= right) {
            if (people[left] + people[right] > limit) {
                // 重的单独一条船
                right--;
            } else {
                // 两人一船
                right--;
                left++;
            }
            cnt++;
        }
        return cnt;
    }
};