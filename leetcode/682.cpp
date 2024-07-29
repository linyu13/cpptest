#include "leetcode.hpp"

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        int index = -1;
        for (auto oper : operations) {
            if (oper == "D") {
                ans.push_back(ans[index] * 2);
                index++;
            } else if (oper == "+") {
                ans.push_back(ans[index] + ans[index - 1]);
                index++;
            } else if (oper == "C") {
                ans.pop_back();
                index--;
            } else {
                int n = stoi(oper);
                ans.push_back(n);
                index++;
            }
        }
        int ret = accumulate(ans.begin(), ans.end(), 0);
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> operations;
    operations.assign({"5","2","C","D","+"});
    cout << sol.calPoints(operations) << endl;
}