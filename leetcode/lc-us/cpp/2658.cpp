#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        bool st[n][m];
        memset(st, 0, sizeof st);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] && !st[i][j]) {
                    int te = 0;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    st[i][j] = true;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        int x = t.first, y = t.second;
                        te += g[x][y];
                        for (int d = 0; d < 4; d++) {
                            int a = x + dx[d], b = y + dy[d];
                            if (a < 0 || a == n || b < 0 || b == m || g[a][b] == 0 || st[a][b]) continue;
                            st[a][b] = true;
                            q.emplace(a, b);
                        }
                    }
                    res = max(te, res);
                }
            }
        }
        return res;
    }
};