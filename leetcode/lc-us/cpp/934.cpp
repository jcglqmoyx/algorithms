#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;

    void dfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || j < 0 || i == n || j == n || visited[i][j] || grid[i][j] == 0) return;
        visited[i][j] = true;
        q.push({i, j});
        dfs(grid, q, visited, i + 1, j);
        dfs(grid, q, visited, i - 1, j);
        dfs(grid, q, visited, i, j + 1);
        dfs(grid, q, visited, i, j - 1);
    }

public:
    int shortestBridge(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        n = (int) grid.size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(grid, q, visited, i, j);
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        int len = -1;
        while (!q.empty()) {
            len++;
            for (auto it = q.size(); it; it--) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                        if (grid[nx][ny]) return len;
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return len;
    }
};