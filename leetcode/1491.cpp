#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), 0);
        sum -= salary.front();
        sum -= salary.back();
        return sum / (salary.size() - 2) * 1.0;
    }
};