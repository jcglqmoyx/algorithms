#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> f(n, vector<int>(n, 1e8));
        for (const auto &e: edges) {
            int x = e[0], y = e[1], w = e[2];
            f[x][y] = f[y][x] = w;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int mn = n, res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (f[i][j] <= distanceThreshold) {
                        cnt++;
                    }
                }
            }
            if (cnt <= mn) {
                mn = cnt;
                res = i;
            }
        }
        return res;
    }
};