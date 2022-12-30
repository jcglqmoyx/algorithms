#include <bits/stdc++.h>

using namespace std;

class GridMaster {
public:
    bool canMove(char direction);

    void move(char direction);

    bool isTarget();
};

class Solution {
    static constexpr int INF = 0x3f3f3f3f;
    static constexpr int N = 1005;

    char d[4] = {'D', 'R', 'U', 'L'};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int g[N][N]{};

    struct Status {
        int x, y;
        GridMaster master;
    };

    void dfs(GridMaster &master, int x, int y) {
        if (master.isTarget()) {
            g[x][y] = 2;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (g[a][b] != INF) continue;
            if (!master.canMove(d[i])) {
                g[a][b] = 0;
            } else {
                g[a][b] = 1;
                master.move(d[i]);
                dfs(master, a, b);
                master.move(d[i ^ 2]);
            }
        }
    }

public:
    int findShortestPath(GridMaster &master) {
        memset(g, 0x3f, sizeof g);
        g[501][501] = -1;
        dfs(master, 501, 501);
        queue<pair<int, int>> q;
        q.push({501, 501});
        int res = 0;
        while (!q.empty()) {
            res++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a >= 0 && a <= 1002 && b >= 0 && b <= 1002 && g[a][b] != INF && g[a][b] != 0) {
                        if (g[a][b] == 2) return res;
                        g[a][b] = INF;
                        q.push({a, b});
                    }
                }
            }
        }
        return -1;
    }
};