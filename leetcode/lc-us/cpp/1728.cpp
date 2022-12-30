#include <bits/stdc++.h>

using namespace std;

const int N = 8, M = 100;

int f[N][N][N][N][M];

class Solution {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    const char WALL = '#', FOOD = 'F', CAT = 'C', MOUSE = 'M';
    int n, m;
    int cj, mj;
    vector<string> g;

    /**
     *
     * @param cx x-coordinate of the cat
     * @param cy y-coordinate of the cat
     * @param mx x-coordinate of the mouse
     * @param my y-coordinate of the mouse
     * @param turn The current turn, if {@code turn} is even, then it's mouse's turn to move, otherwise is cat's turn to move.
     *             If {@code turn} is greater than 100, then cat wins.
     * @return Whether the mouse wins
     */
    int dp(int cx, int cy, int mx, int my, int turn) {
        if (turn >= M) return 0;
        int &v = f[cx][cy][mx][my][turn];
        if (v != -1) return v;
        if (turn & 1) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= cj; j++) {
                    int x = cx + dx[i] * j, y = cy + dy[i] * j;
                    if (x < 0 || x == n || y < 0 || y == m || g[x][y] == WALL) break;
                    if (x == mx && y == my || g[x][y] == FOOD) return v = 0;
                    if (!dp(x, y, mx, my, turn + 1)) return v = 0;
                }
            }
            return v = 1;
        } else {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= mj; j++) {
                    int x = mx + dx[i] * j, y = my + dy[i] * j;
                    if (x < 0 || x == n || y < 0 || y == m || g[x][y] == WALL) break;
                    if (x == cx && y == cy) continue;
                    if (g[x][y] == FOOD) return v = 1;
                    if (dp(cx, cy, x, y, turn + 1)) return v = 1;
                }
            }
            return v = 0;
        }
    }

public:
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump) {
        memset(f, -1, sizeof f);
        g = grid, n = (int) g.size(), m = (int) g[0].size(), cj = catJump, mj = mouseJump;
        int cx, cy, mx, my;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == CAT) cx = i, cy = j;
                else if (g[i][j] == MOUSE) mx = i, my = j;
            }
        }
        return dp(cx, cy, mx, my, 0);
    }
};