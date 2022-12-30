#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> f(n, vector<vector<double>>(n, vector<double>(k + 1)));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) f[i][j][k] = 1;
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int step = k; step; step--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int u = 0; u < 8; u++) {
                        int a = i + dx[u], b = j + dy[u];
                        if (a >= 0 && a < n && b >= 0 && b < n) {
                            f[a][b][step - 1] += 0.125 * f[i][j][step];
                        }
                    }
                }
            }
        }
        return f[row][column][0];
    }
};