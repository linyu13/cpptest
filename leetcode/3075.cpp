#include "leetcode.hpp"

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long sum = 0;
        int n = happiness.size() - 1;
        int cnt = 0;
        for (int i = n; i > n - k; i--) {
            sum += (happiness[i] - cnt) > 0 ? happiness[i] - cnt : 0;
            cnt++;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> happiness;
    happiness.assign({2,83,62});
    cout << sol.maximumHappinessSum(happiness, 3) << endl;
    // copy(happiness.begin(), happiness.end(), ostream_iterator<int>(cout, "\n"));
}