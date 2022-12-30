#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>> &grid) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int n = (int) grid.size(), m = (int) grid[0].size();
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a < 0 || a == n || b < 0 || b == m) continue;
                int cost = f[t.first][t.second] + grid[a][b];
                if (f[a][b] > cost) {
                    f[a][b] = cost;
                    q.push({a, b});
                }
            }
        }
        return f[n - 1][m - 1];
    }
};