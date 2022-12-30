#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] != 2 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        q.push({i, j});
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int orangesRotting(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j);
                }
            }
        }
        int minutes = -1;
        while (!q.empty()) {
            minutes++;
            for (auto it = q.size(); it; it--) {
                auto[x, y]= q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return minutes == -1 ? 0 : minutes;
    }
};