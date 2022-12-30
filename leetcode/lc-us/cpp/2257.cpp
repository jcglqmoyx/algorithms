#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        const int WALL = 1, GUARD = 2, GUARDED = 3, UNGUARDED = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<vector<int>> g(m, vector<int>(n));
        for (const auto &wall: walls) {
            g[wall[0]][wall[1]] = WALL;
        }
        for (const auto &guard: guards) {
            g[guard[0]][guard[1]] = GUARD;
        }

        auto valid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == GUARD) {
                    for (int d = 0; d < 4; d++) {
                        int x = i, y = j;
                        for (int step = 0;; step++) {
                            x += dx[d], y += dy[d];
                            if (!valid(x, y) || g[x][y] == WALL || g[x][y] == GUARD) break;
                            if (g[x][y] == UNGUARDED) g[x][y] = GUARDED;
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == UNGUARDED) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};