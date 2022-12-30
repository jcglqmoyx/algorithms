#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n{}, m{};
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int dist(vector<vector<int>> &grid, int x1, int y1, int x2, int y2) {
        if (grid[x1][y1] == 0) return -1;
        queue<pair<int, int>> q;
        vector<vector<bool>> st(n, vector<bool>(m));
        q.push({x1, y1});
        st[x1][y1] = true;
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a == x2 && b == y2) return step;
                    if (a < 0 || a == n || b < 0 || b == m || grid[a][b] == 0 || st[a][b]) continue;
                    st[a][b] = true;
                    q.push({a, b});
                }
            }
        }
        return -1;
    }

public:
    int cutOffTree(vector<vector<int>> &forest) {
        n = (int) forest.size(), m = (int) forest[0].size();
        vector<vector<int>> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) {
                    pos.push_back({i, j});
                }
            }
        }
        sort(pos.begin(), pos.end(), [&](const vector<int> &a, const vector<int> &b) {
            return forest[a[0]][a[1]] < forest[b[0]][b[1]];
        });
        int x = 0, y = 0;
        int res = 0;
        for (auto &p: pos) {
            if (x == p[0] && y == p[1]) continue;
            int t = dist(forest, x, y, p[0], p[1]);
            if (t == -1) return -1;
            res += t;
            x = p[0], y = p[1];
        }
        return res;
    }
};