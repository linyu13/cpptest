#include "leetcode.hpp"

class Solution
{
public:

    void Insert(vector<int>& sortArr, int n)
    {
        // 获取 n 在sortArr所对应的 查找到的上界（即为大于 n 的第一个位置）
        auto upperBoundIt = upper_bound(sortArr.begin(), sortArr.end(), n);
        // 获取下标
        int upperBoundIndex = distance(sortArr.begin(), upperBoundIt);
        // 插入
        sortArr.insert(upperBoundIt, n);
    }

    int greaterCount(vector<int>& arr, vector<int>& sortArr, int n)
    {
        auto upperBoundIt = upper_bound(sortArr.begin(), sortArr.end(), n);
        int upperBoundIndex = distance(sortArr.begin(), upperBoundIt);
        // 二者之差即为严格大于 n 的个数
        return arr.size() - upperBoundIndex;
    }

    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> sortArr1;
        vector<int> sortArr2;
        int cnt_arr1 = 0;
        int cnt_arr2 = 0;
        int num = nums.size();
        // 初始化
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        sortArr1 = arr1;
        sortArr2 = arr2;
        for (int i = 2; i < num; i++) {
            int n = nums[i];
            // 调用函数判断严格大于 n 的数据数量
            if (greaterCount(arr1, sortArr1, n) > greaterCount(arr2, sortArr2, n)) {
                arr1.push_back(n);
                // 将 n 插入已排序的数组以便后续使用
                Insert(sortArr1, n);
                cnt_arr1++;
            }
            else if (greaterCount(arr1, sortArr1, n) < greaterCount(arr2, sortArr2, n)) {
                arr2.push_back(n);
                Insert(sortArr2, n);
                cnt_arr2++;
            }
            else if (greaterCount(arr1, sortArr1, n) == greaterCount(arr2, sortArr2, n)) {
                if (cnt_arr1 > cnt_arr2) {
                    arr2.push_back(n);
                    Insert(sortArr2, n);
                    cnt_arr2++;
                }
                else if (cnt_arr1 < cnt_arr2) {
                    arr1.push_back(n);
                    Insert(sortArr1, n);
                    cnt_arr1++;
                }
                else if (cnt_arr1 == cnt_arr2) {
                    arr1.push_back(n);
                    Insert(sortArr1, n);
                    cnt_arr1++;
                }
            }
        }
        // 合并数组
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};


// 没看懂   :(
// class BinaryIndexedTree
// {
// private:
//     vector<int> tree; // 存储树状数组节点值的数组

// public:
//     BinaryIndexedTree(int n)
//         : tree(n + 1)
//     {
//     } // 构造函数，初始化树状数组

//     void add(int i)
//     {                     // 向树状数组中添加元素
//         while (i < tree.size()) {
//             tree[i] += 1; // 更新节点值
//             cout << i + (i & -i) << endl;
//             i += i & -i;  // 移动到下一个节点
//         }
//     }

//     int get(int i)
//     { // 获取前缀和
//         int res = 0;
//         while (i > 0) {
//             res += tree[i]; // 累加节点值
//             i &= i - 1;     // 移动到上一个节点
//         }
//         return res;
//     }
// };

// class Solution
// {
// public:
//     vector<int> resultArray(vector<int>& nums)
//     {                                               // 返回按照特定规则排列的数组
//         int n = nums.size();
//         vector<int> sortedNums = nums;              // 复制 nums 数组
//         sort(sortedNums.begin(), sortedNums.end()); // 对复制的数组进行排序
//         unordered_map<int, int> index; // 存储排序后的数组元素与其索引的映射关系
//         for (int i = 0; i < n; ++i) {
//             index[sortedNums[i]] = i + 1; // 构建映射关系
//         }

//         vector<int> arr1 = { nums[0] };       // 创建两个子数组，初始化为第一个元素
//         vector<int> arr2 = { nums[1] };
//         BinaryIndexedTree tree1(n), tree2(n); // 创建两个树状数组
//         tree1.add(index[nums[0]]);            // 向树状数组中添加第一个元素的索引
//         tree2.add(index[nums[1]]);            // 向树状数组中添加第二个元素的索引

//         for (int i = 2; i < n; ++i) {
//             int count1 =
//                 arr1.size() - tree1.get(index[nums[i]]); // 计算第一个子数组中比当前元素小的元素个数
//             int count2 =
//                 arr2.size() - tree2.get(index[nums[i]]); // 计算第二个子数组中比当前元素小的元素个数
//             if (count1 > count2
//                 || (count1 == count2 && arr1.size() <= arr2.size())) { // 根据特定规则选择插入的数组
//                 arr1.push_back(nums[i]);   // 插入到第一个子数组
//                 tree1.add(index[nums[i]]); // 更新树状数组
//             }
//             else {
//                 arr2.push_back(nums[i]);   // 插入到第二个子数组
//                 tree2.add(index[nums[i]]); // 更新树状数组
//             }
//         }

//         arr1.insert(arr1.end(), arr2.begin(), arr2.end()); // 将第二个子数组插入到第一个子数组的末尾
//         return arr1;                                       // 返回最终结果数组
//     }
// };

int main()
{
    Solution sol;
    vector<int> nums;
    nums.assign({ 2,   1,  3,     3,    7,    6,   4,     56,  74,    544, 3,  45,  3,
                  7,   45, 762,   45,   2,    476, 234,   6,   34587, 56,  8,  5,   6,
                  324, 64, 568,   45,   63,   48,  5,     34,  51,    34,  5,  745, 74587,
                  68,  56, 45246, 4578, 46,   234, 52576, 3,   246,   545, 7,  4,   56,
                  3,   1,  4,     5,    2457, 3,   46,    445, 7,     568, 57, 8,   45 });
    vector<int> ans = sol.resultArray(nums);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}
