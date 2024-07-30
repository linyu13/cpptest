#include "leetcode.hpp"

class Solution
{
public:
    string discountPrices(string sentence, int discount)
    {
        int n = sentence.size();
        for (int i = 0; i < n; i++) {
            // 确保 $ 前面是空格
            if (sentence[i] == '$' && (i == 0 || sentence[i - 1] == ' ')) {
                int j = i + 1;
                int flag = 1;
                // 确保 $ 后只有数字
                while (j < n && sentence[j] != ' ') {
                    if (!isdigit(sentence[j])) {
                        flag = 0;
                        break;
                    }
                    j++;
                }
                // 对 $ 后的数字进行操作
                if (flag && j > i + 1) { 
                    // 剪切掉数字部分
                    string tempStr = sentence.substr(i + 1, j - i - 1);
                    // 计算
                    double price = stod(tempStr);
                    price = price - price * discount * 0.01;
                    // 两位小数
                    ostringstream oss;
                    oss << fixed << setprecision(2) << price;
                    string newPriceStr = oss.str();
                    // 替换
                    sentence.replace(i + 1, j - i - 1, newPriceStr);
                    // 更新字符串长度
                    n = sentence.size();
                    // 减少无效遍历 
                    i = i + newPriceStr.size();
                } else {
                    // 同为减少无效遍历
                    i = j; 
                }
            }
        }
        return sentence;
    }
};

int main()
{
    Solution sol;
    string ans = sol.discountPrices("706hzu76jjh7yufr5x9ot60v149k5 $7651913186 pw2o $", 28);
    cout << ans << endl;
}
