#include "leetcode.hpp"

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        int n = players.size() - 1;
        int m = trainers.size() - 1;
        sort(trainers.begin(), trainers.end());
        
        int ans = 0;
        while (n >= 0 && m >= 0) {
            if (players[n] > trainers[m]) {
                n--;
            } else {
                n--;
                m--;
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> players, trainers;
    players.assign({4,7,9});
    trainers.assign({8,2,5,8});
    cout << sol.matchPlayersAndTrainers(players, trainers) << endl;
}