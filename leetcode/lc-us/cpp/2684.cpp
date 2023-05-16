#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        int f[n][m];
        memset(f, 0, sizeof f);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) q.emplace(i, 0);
        int dx[3] = {-1, 0, 1};
        int dy[3] = {1, 1, 1};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 3; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m || g[a][b] <= g[x][y] || f[a][b] >= f[x][y] + 1) continue;
                f[a][b] = f[x][y] + 1;
                q.emplace(a, b);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res = max(res, f[i][j]);
        return res;
    }
};