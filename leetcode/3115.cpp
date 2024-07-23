#include "leetcode.hpp"

class Solution
{
public:
    bool isPrime(int a)
    {
        int flag = 1;
        if (a < 2) {
            return 0;
        }
        for (int i = 2; i <= pow(a, 0.5); i++) {
            if (a % i == 0) {
                flag = 0;
                break;
            }
        }
        return flag ? 1 : 0;
    }

    int maximumPrimeDifference(vector<int>& nums)
    {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int flag_left = 0;
        int flag_right = 0;
        while (!flag_left || !flag_right) {
            if (!flag_left) {
                if (isPrime(nums[left])) {
                    flag_left = 1;
                }
                else {
                    left++;
                }
            }
            if (!flag_right) {
                if (isPrime(nums[right])) {
                    flag_right = 1;
                }
                else {
                    right--;
                }
            }
        }

        return right - left;
    }
};

int main()
{
    Solution sol;
    vector<int> pro;
    pro.assign({3,6,6});
    cout << sol.maximumPrimeDifference(pro) << endl;
}
