#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if (k >= n + m - 3) return n + m - 2;
        k = min(k, n + m - 3);
        struct Point {
            int x, y, step, change;
        };
        const int N = 40;
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int st[N][N][k + 1];
        memset(st, 0x3f, sizeof st);
        queue<Point> q;
        st[0][0][0] = 0;
        q.push({0, 0, 0, 0});
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                auto p = q.front();
                if (p.x == n - 1 && p.y == m - 1) return p.step;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = p.x + dx[i], b = p.y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m) continue;
                    if (grid[a][b]) {
                        if (p.change == k) continue;
                        if (p.step + 1 < st[a][b][p.change + 1]) {
                            st[a][b][p.change + 1] = p.step + 1;
                            q.push({a, b, p.step + 1, p.change + 1});
                        }
                    } else {
                        if (p.step + 1 < st[a][b][p.change]) {
                            st[a][b][p.change] = p.step + 1;
                            q.push({a, b, p.step + 1, p.change});
                        }
                    }
                }
            }
        }
        return -1;
    }
};