#include "leetcode.hpp"

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n); // 返回答案
        stack<int> s;       // 定义一个模拟栈
        for (int i = 0; i < n; i++) {
            // 当s为空且这一个比栈顶元素大时进入
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int pre = s.top();  // 获取先前的下标
                ans[pre] = i - pre; // 写入ans
                s.pop();            // 弹栈
            }
            s.push(i);              // 压栈
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> temperatures;
    temperatures.assign({ 73, 74, 75, 71, 69, 72, 76, 73 });
    vector<int> ans = sol.dailyTemperatures(temperatures);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}
