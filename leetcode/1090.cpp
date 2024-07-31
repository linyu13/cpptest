#include "leetcode.hpp"

class Solution
{
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit)
    {
        vector<vector<int>> value_label;
        int n = values.size();
        for (int i = 0; i < n; i++) {
            std::vector<int> row;
            row.push_back(values[i]);
            row.push_back(labels[i]);
            value_label.push_back(row);
        }
        int ans = 0;
        std::sort(
            value_label.begin(),
            value_label.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
        char hash[20001] = {0};
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (hash[value_label[i][1]] < useLimit && cnt < numWanted){
                hash[value_label[i][1]]++;
                ans += value_label[i][0];
                cnt++;
            } 
            if (cnt == numWanted) {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> values, labels;
    values.assign({ 5,4,3,2,1 });
    labels.assign({ 1,1,2,2,3 });
    cout << sol.largestValsFromLabels(values, labels, 3, 1) << endl;
}
