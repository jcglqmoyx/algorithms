#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>> &grid) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                    visited[i][j] = true;
                    break;
                }
            }
        }
        int len = 0;
        while (!q.empty()) {
            len++;
            for (auto it = q.size(); it; it--) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                        if (grid[nx][ny] == '#') {
                            return len;
                        } else if (grid[nx][ny] == 'O') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};