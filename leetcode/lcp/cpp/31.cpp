#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[5] = {0, 1, 0, -1, 0};
    int dy[5] = {1, 0, -1, 0, 0};
    int n{}, m{};
    int max_step{};
    bool visited[55][55][105][2][2] = {false};
public:
    bool dfs(int x, int y, int step, bool magic1, bool magic2, const vector<vector<string>> &maze) {
        if (visited[x][y][step][magic1][magic2]) return false;
        visited[x][y][step][magic1][magic2] = true;
        if (x == n - 1 && y == m - 1) return true;
        if (step == max_step) return false;
        if (max_step - step < n - 1 - x + m - 1 - y) return false;
        for (int i = 0; i < 5; i++) {
            int fx = x + dx[i];
            int fy = y + dy[i];
            if (fx >= 0 && fx < n && fy >= 0 && fy < m) {
                if (maze[step + 1][fx][fy] == '.') {
                    if (dfs(fx, fy, step + 1, magic1, magic2, maze)) return true;
                } else {
                    if (!magic1) {
                        if (dfs(fx, fy, step + 1, true, magic2, maze)) return true;
                    }
                    if (!magic2) {
                        for (int idx = step + 1; idx <= max_step; idx++) {
                            if (dfs(fx, fy, idx, magic1, true, maze)) return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool escapeMaze(vector<vector<string>> &maze) {
        n = (int) maze[0].size();
        m = (int) maze[0][0].size();
        max_step = maze.size() - 1;
        return dfs(0, 0, 0, false, false, maze);
    }
};