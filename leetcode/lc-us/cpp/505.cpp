#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int n = (int) maze.size(), m = (int) maze[0].size();
        vector<vector<int>> f(n, vector<int>(m, 1e9));
        queue<vector<int>> q;
        q.push({start[0], start[1], 0});
        int res = 1e9;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = t[0], y = t[1], dist = t[2];
                while (x >= 0 && x < n && y >= 0 && y < m) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m || maze[a][b]) {
                        if (x == destination[0] && y == destination[1]) res = min(res, dist);
                        if (dist < f[x][y]) f[x][y] = dist, q.push({x, y, dist});
                        break;
                    }
                    x = a, y = b;
                    dist++;
                }
            }
        }
        return res == 1e9 ? -1 : res;
    }
};