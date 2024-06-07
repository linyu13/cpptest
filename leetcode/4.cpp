#include "leetcode.hpp"

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int num1 = nums1.size();
        int num2 = nums2.size();
        int index = (num1 + num2) / 2;
        int flag = 0;
        if (index % 2 == 0) {
            flag = 1;
        }
        double re = 0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        if (flag) {
            re = (nums1[index] + nums1[index - 1]) / 2.0;
        }
        else {
            re = nums1[index] * 1.0;
        }

        return re;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1, nums2;
    nums1.assign({});
    nums2.assign({ 3 });
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}
