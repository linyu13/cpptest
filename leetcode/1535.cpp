#include "leetcode.hpp"

class Solution
{
public:
    int getWinner(vector<int>& arr, int k)
    {
        // int max = std::max(arr[0], arr[1]);
        // int pre = max;
        // int flag =0;
        // while (1) {
        //     int del = 0;
        //     if (std::max(arr[0], arr[1]) > max) {
        //         max = std::max(arr[0], arr[1]);
        //         flag = 1;
        //     } else {
        //         flag++;
        //     }
        //     if (arr[0] > arr[1]) {
        //         del = arr[1];
        //         arr.erase(arr.begin() + 1);
        //     } else {
        //         del = arr[0];
        //         arr.erase(arr.begin());
        //     }
        //     arr.push_back(del);

        //     if (flag == k) {
        //         break;
        //     }
        //     if (flag > arr.size() + 1) {
        //         break;
        //     }
        // }

        // return arr[0];
        int n = arr.size();
        int index = 0;
        int cnt = 0;
        // 该方法实现比前一个方法更快的原因在于不需要来回操作容器位置，大大减小了时间复杂度
        for (int i = 1; i < n && cnt < k; i++) {
            if (arr[index] > arr[i]) {
                cnt++;
            }
            else {
                index = i;
                cnt = 1;
            }
        }
        return arr[index];
    }
};

int main()
{
    Solution sol;
    vector<int> arr;
    arr.assign({ 2, 1, 3, 5, 4, 6, 7 });
    cout << sol.getWinner(arr, 2) << endl;
}
