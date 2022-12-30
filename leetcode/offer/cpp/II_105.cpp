#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        queue<pair<int, int>> q;
        int res = 0;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    int area = 0;
                    while (!q.empty()) {
                        area++;
                        res = max(res, area);
                        auto t = q.front();
                        q.pop();
                        int x = t.first, y = t.second;
                        for (int idx = 0; idx < 4; idx++) {
                            int a = x + dx[idx], b = y + dy[idx];
                            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b]) {
                                q.push({a, b});
                                grid[a][b] = 0;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};