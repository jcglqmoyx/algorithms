#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] != 1) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int score = n * (int) pow(2, m - 1);
        for (int j = 1; j < grid[0].size(); j++) {
            int count_one = 0;
            for (auto &i: grid) {
                if (i[j] == 1) {
                    count_one++;
                }
            }
            score += max(count_one, n - count_one) * (int) pow(2, m - j - 1);
        }
        return score;
    }
};