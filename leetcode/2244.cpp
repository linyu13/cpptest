#include "leetcode.hpp"

class Solution
{
public:
    // unordered_map<int, int> hash;
    // int minimumRounds(vector<int>& tasks)
    // {
    //     int re = 0;
    //     for (int i = 0; i < tasks.size(); i++) {
    //         if (hash.find(tasks[i]) != hash.end()) {
    //             hash[tasks[i]]++;
    //         }
    //         else {
    //             hash[tasks[i]] = 0;
    //             hash[tasks[i]]++;
    //         }
    //     }
    //     for (auto it = hash.begin(); it != hash.end(); it++) {
    //         if (it->second == 1) {
    //             return -1;
    //         }
    //         else if (it->second % 3 == 0) {
    //             re += it->second / 3;
    //         }
    //         else {
    //             re += it->second / 3 + 1;
    //         }
    //     }
    //     return re;
    // }
    int minimumRounds(vector<int>& tasks)
    {
        sort(tasks.begin(), tasks.end());
        int flag = 0;
        int re = 0;
        int pre = 0;
        for (int i = 0; i < tasks.size(); i++) {
            if (i == 0 || !flag) {
                pre = tasks[i];
                flag++;
                continue;
            }
            if (pre == tasks[i]) {
                flag++;
            }
            else {
                if (flag == 1) {
                    return -1;
                }
                else if (flag % 3 == 0) {
                    pre = tasks[i];
                    re += flag / 3;
                    flag = 1;
                }
                else {
                    pre = tasks[i];
                    re += flag / 3 + 1;
                    flag = 1;
                }
            }
        }
        if (flag == 1) {
            return -1;
        }
        else if (flag % 3 == 0) {
            re += flag / 3;
            flag = 1;
        }
        else {
            re += flag / 3 + 1;
            flag = 1;
        }
        return re;
    }
};

int main()
{
    Solution sol;
    vector<int> tasks;
    tasks.assign({ 2, 2, 3, 3, 2, 4, 4, 4, 4, 4 });
    cout << sol.minimumRounds(tasks) << "\n";
}
