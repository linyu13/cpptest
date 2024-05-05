#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 1) {
            return;
        }
        for(int i = 0; i < n; i++) {
            int index = 0;
            index = i + n - k;
            if (index > n - 1) {
                index -= n;
            }
            while (index < 0) {
                index += n;
            }
            ans.push_back(nums[index]);
        }
        nums = ans;
        return;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    // for (int i = 1; i < 8; i++) {
    //     nums.push_back(i);
    // }
    // int a = -1;
    nums.push_back(-1);

    sol.rotate(nums,2);
}