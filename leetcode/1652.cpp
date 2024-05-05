#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                ans.push_back(0);
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                int flag = i;
                int num = 0;
                for (int j = 0; j < abs(k); j++) {
                    if (flag - 1 < 0) {
                        flag = n;
                    }
                    num += code[--flag];
                }
                ans.push_back(num);
            }
        } else {
            for (int i = 0; i < n; i++) {
                int flag = i;
                int num = 0;
                for (int j = 0; j < abs(k); j++) {
                    if (flag + 1 > n - 1) {
                        flag = -1;
                    }
                    num += code[++flag];
                }
                ans.push_back(num);
            }
        }
        return ans;
    }
};