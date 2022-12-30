#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        size_t n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[start[0]][start[1]] = true;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = t.first, y = t.second;
                while (x >= 0 && x < n && y >= 0 && y < m) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m || maze[a][b]) {
                        if (x == destination[0] && y == destination[1]) return true;
                        if (!vis[x][y]) {
                            q.push({x, y});
                            vis[x][y] = true;
                        }
                        break;
                    }
                    x = a, y = b;
                }
            }
        }
        return false;
    }
};