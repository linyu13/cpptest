#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(image[i][j], image[i][n - j - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                image[i][j] = image[i][j] ? 0 : 1;
            }
        }

        return image;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> ans = sol.flipAndInvertImage(image);
    return 0;
}