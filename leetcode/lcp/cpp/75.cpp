#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int challengeOfTheKeeper(vector<string> &maze) {
        int n = (int) maze.size(), m = (int) maze[0].size();
        int sx, sy, tx, ty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'S') sx = i, sy = j;
                else if (maze[i][j] == 'T') tx = i, ty = j;
            }
        }

        const int INF = 0x3f3f3f3f;
        int dist[n][m];
        memset(dist, 0x3f, sizeof dist);

        short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
        typedef pair<int, int> PII;
        queue<PII> q;
        q.emplace(tx, ty);
        dist[tx][ty] = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (auto &k: dir) {
                int x = i + k[0], y = j + k[1];
                if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == '#' || dist[x][y] != INF) continue;
                q.emplace(x, y);
                dist[x][y] = dist[i][j] + 1;
            }
        }

        if (dist[sx][sy] == INF) return -1;

        int A[n][m];
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == '.') {
                    int x = n - 1 - i, y = j;
                    if (maze[x][y] != '#') A[i][j] = max(A[i][j], dist[x][y]);
                    x = i, y = m - 1 - j;
                    if (maze[x][y] != '#') A[i][j] = max(A[i][j], dist[x][y]);
                }
            }
        }

        int f[n][m];
        memset(f, -1, sizeof(f));

        typedef pair<int, PII> T;
        priority_queue<T> pq;
        pq.emplace(A[sx][sy], PII(sx, sy));
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int d = -t.first, i = t.second.first, j = t.second.second;
            if (f[i][j] >= 0) continue;
            f[i][j] = d;
            for (auto &k: dir) {
                int x = i + k[0], y = j + k[1];
                if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == '#') continue;
                pq.emplace(-max(d, A[x][y]), PII(x, y));
            }
        }

        if (f[tx][ty] < INF) return f[tx][ty];
        else return -1;
    }
};