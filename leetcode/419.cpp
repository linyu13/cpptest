#include "leetcode.hpp"

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    // 1 * k 行  所以检查上一行
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    // k * 1 列  所以检查前一列
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
