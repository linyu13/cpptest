#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = 1; i < 10; i++)
        {
            int num = i;
            for (int j = i + 1; j < 10; j++)
            {
                num = num * 10 + j;
                if (num <= high && num >= low)
                {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.sequentialDigits(1, 1000000000);
    /*copy 是 C++ 标准库中的一个算法，它用于将一个范围的元素复制到另一个范围中。
    它通常用于容器之间的元素复制，也可以用于将元素输出到输出流中。
    ostream_iterator 是一个输出迭代器，用于将元素写入输出流。
    它是模板类，用于输出特定类型的元素到输出流中。
    它的构造函数接受一个输出流对象和一个分隔符（可选），用于分隔输出的元素。*/
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
    cout << endl;
}