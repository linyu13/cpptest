#include "leetcode.hpp"

class Solution
{
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int, int>> job_difficulty;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            job_difficulty.push_back(make_pair(difficulty[i], profit[i]));
        }
        // 将工作难度和工作价值匹配 对其和工人的能力进行排序 尽可能多的得到工作价值
        sort(worker.begin(), worker.end());
        sort(job_difficulty.begin(), job_difficulty.end());
        // int left = 0;
        // int right = 1;
        // int sum = 0;
        // int max_profit = max(job_difficulty[0].second, job_difficulty[1].second);
        // for (int i = 0; i < worker.size();) {
        //     if (worker[i] >= job_difficulty[left].first
        //         && worker[i] >= job_difficulty[right].first) {
        //         int max_in_function =
        //             max(job_difficulty[left].second, job_difficulty[right].second);
        //         max_profit = max(max_profit, max_in_function);
        //         if (right < n) {
        //             left++;
        //             right++;
        //         }
        //         if (right == n) {
        //             sum += max_profit;
        //             i++;
        //         }
        //     }
        //     else if (
        //         worker[i] >= job_difficulty[left].first
        //         && worker[i] < job_difficulty[right].first) {
        //         if (i == 0 && left == 0) {
        //             sum += job_difficulty[0].second;
        //         }
        //         else {
        //             sum += max_profit;
        //         }
        //         i++;
        //     }
        //     else {
        //         sum += 0;
        //         i++;
        //     }
        // }
        int sum = 0;
        int index = 0;
        int max_profit = 0;
        for (int i = 0; i < worker.size(); i++) {
            // 使用循环直接找到工人能力范围内最大的收益
            while (worker[i] >= job_difficulty[index].first && index < n) {
                max_profit = max(job_difficulty[index].second, max_profit);
                index++;
            }
            sum += max_profit;
        }
        // int sum = 0;
        // int i = 0;
        // int max_profit = 0;
        // for (int w : worker) {
        //     while (w >= job_difficulty[i].first && i < n) {
        //         max_profit = max(max_profit, job_difficulty[i].second);
        //         i++;
        //     }
        //     sum += max_profit;
        // }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> difficulty, profit, worker;
    difficulty.assign({2,4,6,8,10});
    profit.assign({10,20,30,40,50});
    worker.assign({4,5,6,7});
    cout << sol.maxProfitAssignment(difficulty, profit, worker) << endl;
}
