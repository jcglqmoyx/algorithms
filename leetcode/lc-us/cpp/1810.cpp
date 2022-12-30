#include <bits/stdc++.h>

using namespace std;

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    static constexpr int N = 205;

    int g[N][N]{};
    bool st[N][N]{};
    char d[4] = {'D', 'R', 'U', 'L'};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int xx{}, yy{};

    void dfs(int x, int y, GridMaster &master) {
        if (master.isTarget()) {
            xx = x, yy = y;
            st[x][y] = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (master.canMove(d[i]) && !st[a][b]) {
                g[a][b] = master.move(d[i]);
                st[a][b] = true;
                dfs(a, b, master);
                master.move(d[i ^ 2]);
            }
        }
    }

    int findShortestPath(GridMaster &master) {
        memset(g, 0x3f, sizeof g);
        memset(st, false, sizeof st);
        st[101][101] = true;
        g[0][0] = 0;
        dfs(101, 101, master);

        int dist[N][N];
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        dist[101][101] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        heap.push({0, 101, 101});
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int cost = get<0>(t), x = get<1>(t), y = get<2>(t);
            if (st[x][y]) continue;
            if (x == xx && yy == y) {
                return cost;
            }
            st[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (g[a][b] != INF && dist[a][b] > cost + g[a][b]) {
                    dist[a][b] = cost + g[a][b];
                    heap.push({dist[a][b], a, b});
                }
            }
        }
        return -1;
    }
};