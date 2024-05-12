#include "leetcode.hpp"

class Solution
{
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int cnt = 0;
        int left = 0;
        int a = capacityA;
        int b = capacityB;
        int right = plants.size() - 1;
        while (left <= right) {
            if (capacityA < plants[left]) {
                capacityA = a;
                cnt++;
            }
            capacityA -= plants[left];
            left++;

            if (capacityB < plants[right]) {
                capacityB = b;
                cnt++;
            }
            capacityB -= plants[right];
            right--;

            if (left == right) {
                if (capacityA >= capacityB) {
                    if (capacityA < plants[left]) {
                        capacityA = a;
                        cnt++;
                    }
                    capacityA -= plants[left];
                    left++;
                }
                else {
                    if (capacityB < plants[right]) {
                        capacityB = b;
                        cnt++;
                    }
                    capacityB -= plants[right];
                    right--;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> plants;
    plants.assign({ 2, 2, 3, 3 });
    sol.minimumRefill(plants, 3, 3);
}
