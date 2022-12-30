#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        int f[n][m];
        struct Time {
            int time, left, up;
        };
        auto bfs = [&](queue<pair<int, int>> &q) -> Time {
            memset(f, -1, sizeof f);
            int time = 0;
            while (!q.empty()) {
                for (auto it = q.size(); it; it--) {
                    auto t = q.front();
                    q.pop();
                    int x = t.first, y = t.second;
                    f[x][y] = time;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (nx < 0 || nx == n || ny < 0 || ny == m || grid[nx][ny] || f[nx][ny] != -1) continue;
                        q.push({nx, ny});
                    }
                }
                time++;
            }
            return {f[n - 1][m - 1], f[n - 1][m - 2], f[n - 2][m - 1]};
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        auto human = bfs(q);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        auto fire = bfs(q);
        if (human.time == -1) return -1;
        if (fire.time == -1) return 1e9;
        int ans = fire.time - human.time;
        if (ans < 0) return -1;
        if (human.left < 0 || human.up < 0 || fire.left - human.left == ans && fire.up - human.up == ans) {
            return ans - 1;
        }
        return ans;
    }
};