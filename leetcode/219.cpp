#include "leetcode.hpp"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) {
        //             if (abs(i - j) <= k) {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};
int main()
{
    vector<int> nums;
    Solution sol;
    nums.assign({ 1, 2, 3, 1, 2, 3 });
    cout << sol.containsNearbyDuplicate(nums, 2) << endl;
}
