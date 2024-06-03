#include "leetcode.hpp"

class Solution
{
public:
    int maximumSwap(int num)
    {
        // 将数字变为字符串形式方便后续遍历
        string charArray = to_string(num);
        // 记录最大的数字作为答案
        int maxNum = num;
        // 二重遍历找到最大的概况
        for (int i = 0; i < charArray.size(); i++) {
            for (int j = i + 1; j < charArray.size(); j++) {
                // 先进行换位 再将字符串变为数字直接和已知的最大数字进行比较
                // 再将字符串换回来进行下一次交换
                swap(charArray[i], charArray[j]);
                maxNum = max(maxNum, stoi(charArray));
                swap(charArray[i], charArray[j]);
            }
        }
        return maxNum;
    }
};
