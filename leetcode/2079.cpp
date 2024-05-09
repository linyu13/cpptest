#include "leetcode.hpp"

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int index = 0;
        int sum = 0;
        int max = capacity;
        for (int i = 0; i < plants.size(); ) {
            if (capacity >= plants[i]) {
                capacity -= plants[i];
                index++;
                sum++;
                i++;
            } else {
                capacity = max;
                sum = sum + (index * 2);
            }
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    vector<int> plants;
    plants.assign({2, 2, 3, 3});
    cout << sol.wateringPlants(plants, 5) << "\n";
}