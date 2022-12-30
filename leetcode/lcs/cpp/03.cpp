#include <bits/stdc++.h>

using namespace std;

class Solution {
    using PII = pair<int, int>;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
    vector<vector<bool>> st;

    int bfs(vector<string> &grid, int x0, int y0) {
        int cnt = 0;
        queue<PII> q;
        q.push({x0, y0});
        st[x0][y0] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a < 0 || a == n || b < 0 || b == m || st[a][b] || grid[a][b] != grid[t.first][t.second]) continue;
                q.push({a, b});
                st[a][b] = true;
            }
        }
        return cnt;
    }

public:
    int largestArea(vector<string> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        st.resize(n, vector<bool>(m));
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    q.push({i, j});
                    st[i][j] = true;
                }
                if (grid[i][j] == '0') {
                    st[i][j] = true;
                    for (int it = 0; it < 4; it++) {
                        int a = i + dx[it], b = j + dy[it];
                        if (a < 0 || a == n || b < 0 || b == m || st[a][b]) continue;
                        q.push({a, b});
                        st[a][b] = true;
                    }
                }
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m || st[a][b] || grid[a][b] != grid[x][y]) continue;
                q.push({a, b});
                st[a][b] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!st[i][j]) {
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }
};