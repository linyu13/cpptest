#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum)
    {
        // 已经记录的数据个数加上剩余的数的个数小于需要的个数时返回（此时一定不满足要求
        // 已经记录的的数的个数大于k时返回（不符合题意
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        // 满足题意的数据写入ans
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        // 当以上两步都未返回到上一层时为temp添加cur，再次调用dfs判断是否符合条件
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        // 到这一步时有两种情况
        // 1. 上一次dfs未符合题目，删除temp最顶上的数字，dfs下一个
        // 2.
        // 上一次dfs符合题目，删除temp最顶上的数字，dfs下一个（这里有一个疑惑，此时在不管倒数第二个数的情况下后面的情况均为错误
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(1, 9, k, n);
        return ans;
    }
};

int main()
{
    Solution sol;
    sol.combinationSum3(3, 7);
}
