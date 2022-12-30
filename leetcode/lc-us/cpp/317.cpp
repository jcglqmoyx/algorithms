#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>> &grid) {
        using PII = pair<int, int>;
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

        int n = (int) grid.size(), m = (int) grid[0].size();
        int one = 0;
        for (const auto &row: grid) {
            for (int x: row) {
                if (x == 1) one++;
            }
        }
        int dist[n][m], vis[n][m];
        bool st[n][m];
        memset(dist, 0, sizeof dist), memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    memset(st, false, sizeof st);
                    int move = 0;
                    queue<PII> q;
                    q.emplace(i, j);
                    st[i][j] = true;
                    while (!q.empty()) {
                        move++;
                        for (auto it = q.size(); it; it--) {
                            auto t = q.front();
                            q.pop();
                            for (int idx = 0; idx < 4; idx++) {
                                int a = t.first + dx[idx], b = t.second + dy[idx];
                                if (a < 0 || a == n || b < 0 || b == m || grid[a][b] || st[a][b]) continue;
                                st[a][b] = true;
                                vis[a][b]++;
                                dist[a][b] += move;
                                q.emplace(a, b);
                            }
                        }
                    }
                }
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == one) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};