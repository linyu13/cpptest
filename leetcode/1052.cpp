#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int total = 0;
        int n = customers.size();
        // 计算一般情况下满意的顾客数量
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                total += customers[i];
            }
        }
        int increase = 0;
        // 计算前minutes倘若使用秘密技巧时所增加的满意的顾客数量
        for (int i = 0; i < minutes; i++)
        {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = minutes; i < n; i++)
        {
            // 滑动窗口的理念  减去目前窗口中的第一个，加上目前窗口的下一个实现滑动窗口
            increase = increase - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
            // 与所记录的最大增长两进行比较
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};

int main()
{
    vector<int> customers;
    customers.assign({1, 0, 1, 2, 1, 1, 7, 5});
    vector<int> grumpy;
    grumpy.assign({0, 1, 0, 1, 0, 1, 0, 1});
    Solution sol;
    sol.maxSatisfied(customers, grumpy, 3);
}