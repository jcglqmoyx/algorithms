#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if (n * m <= 2) return false;
        int dx[] = {1, 0}, dy[] = {0, 1};
        bool st[n][m];
        memset(st, 0, sizeof st);
        queue<pair<int, int>> q;
        q.push({0, 0});
        bool flag = false;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x == n - 1 && y == m - 1) flag = true;
                if (x < n && y < m && grid[x][y] && !st[x][y]) q.push({x, y}), st[x][y] = true;
            }
        }
        if (!flag) return true;
        int x = 0, y = 0;
        while (x != n - 1 || y != m - 1)) {
            int nx = x + 1;
            if (nx < n && grid[nx][y]) {
                x = nx;
                grid[x][y] = 0;
            } else {
                int ny = y + 1;
                if (ny < m && grid[x][ny]) {
                    y = ny;
                    grid[x][y] = 0;
                }
            }
        }
        memset(st, 0, sizeof st);
        q.push({0, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a == n - 1 && b == m - 1) return false;
                if (a < n && b < m && grid[a][b] && !st[a][b]) q.push({a, b}), st[a][b] = true;
            }
        }
        return true;
    }
};