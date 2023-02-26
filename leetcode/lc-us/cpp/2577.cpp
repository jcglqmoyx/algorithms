#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>> &grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

        const int INF = 0x3f3f3f3f;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        int n = (int) grid.size(), m = (int) grid[0].size();
        int f[n][m];
        memset(f, -1, sizeof f);
        f[0][0] = 0;

        struct T {
            int dist, x, y;

            bool operator<(const T &t) const {
                return this->dist > t.dist;
            }
        };

        priority_queue<T> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = t.x + dx[i], ny = t.y + dy[i];
                if (nx < 0 || nx == n || ny < 0 || ny == m || f[nx][ny] != -1) continue;
                if (t.dist + 1 >= grid[nx][ny]) f[nx][ny] = t.dist + 1;
                else f[nx][ny] = grid[nx][ny] + !(grid[nx][ny] - t.dist & 1);
                if (nx == n - 1 && ny == m - 1) return f[nx][ny];
                q.push({f[nx][ny], nx, ny});
            }
        }
        return -1;
    }
};