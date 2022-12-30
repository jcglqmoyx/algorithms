#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef queue<pair<int, int>> QPII;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        QPII q;
        auto n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty() || q.size() == n * m) return -1;
        int res = 0;
        while (!q.empty()) {
            bool flag = false;
            for (auto k = q.size(); k; k--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = t.x + dx[i], y = t.y + dy[i];
                    if (~x && x < n && ~y && y < m && !grid[x][y]) {
                        grid[x][y] = 1;
                        q.push({x, y});
                        flag = true;
                    }
                }
            }
            if (flag) res++;
        }
        return res;
    }
};