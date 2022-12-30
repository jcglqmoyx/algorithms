#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        struct Node {
            int x, y, st;
        };
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

        int n = (int) grid.size(), m = (int) grid[0].size();
        int total_keys = 0;
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') x = i, y = j;
                else if (islower(grid[i][j])) total_keys++;
            }
        }
        int dist[n][m][1 << total_keys];
        memset(dist, 0x3f, sizeof dist);
        dist[x][y][0] = 0;
        queue<Node> q;
        q.push({x, y, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int d = dist[t.x][t.y][t.st];
            for (int i = 0; i < 4; i++) {
                int a = t.x + dx[i], b = t.y + dy[i], st = t.st;
                if (a < 0 || a == n || b < 0 || b == m || grid[a][b] == '#') continue;
                char c = grid[a][b];
                if (islower(c)) {
                    st |= 1 << (c - 'a');
                    if (dist[a][b][st] > d + 1) {
                        if (st == (1 << total_keys) - 1) return d + 1;
                        dist[a][b][st] = d + 1;
                        q.push({a, b, st});
                    }
                } else if (isupper(c)) {
                    if (st >> (c - 'A') & 1) {
                        if (dist[a][b][st] > d + 1) {
                            dist[a][b][st] = d + 1;
                            q.push({a, b, st});
                        }
                    }
                } else {
                    if (dist[a][b][st] > d + 1) {
                        dist[a][b][st] = d + 1;
                        q.push({a, b, st});
                    }
                }
            }
        }
        return -1;
    }
};