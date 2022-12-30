#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>> &grid) {
        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        struct T {
            int bx, by;
            int sx, sy;
        };

        int n = (int) grid.size(), m = (int) grid[0].size();

        int dist[n][m][n][m];
        bool st[n][m][n][m];
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);

        T start{};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    start.bx = i;
                    start.by = j;
                } else if (grid[i][j] == 'S') {
                    start.sx = i;
                    start.sy = j;
                }
            }
        }

        dist[start.bx][start.by][start.sx][start.sy] = 0;
        deque<T> q;
        q.push_back(start);
        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            int bx = t.bx, by = t.by, sx = t.sx, sy = t.sy;
            if (st[bx][by][sx][sy]) continue;
            st[bx][by][sx][sy] = true;
            int distance = dist[bx][by][sx][sy];
            if (grid[bx][by] == 'T') return distance;

            for (int i = 0; i < 4; i++) {
                int x = sx + dx[i], y = sy + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && dist[bx][by][x][y] > distance &&
                    !(x == bx && y == by)) {
                    dist[bx][by][x][y] = distance;
                    q.push_front({bx, by, x, y});
                }


                if (bx - sx == dx[i] && by - sy == dy[i]) {
                    x = bx + dx[i], y = by + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && dist[x][y][bx][by] > distance + 1) {
                        dist[x][y][bx][by] = distance + 1;
                        q.push_back({x, y, bx, by});
                    }
                }
            }
        }
        return -1;
    }
};