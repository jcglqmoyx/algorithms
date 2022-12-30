#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        int size = n * m;
        p.resize(size), rk.resize(size, 1), st.resize(n, vector<bool>(m));
        for (int i = 0; i < size; i++) p[i] = i;
        priority_queue<Point> heap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heap.push({i, j, grid[i][j]});
            }
        }
        int res = min(grid[0][0], grid[n - 1][m - 1]);
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int x = t.x, y = t.y, w = t.w;
            if (st[x][y]) continue;
            st[x][y] = true;
            res = min(res, w);
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m) continue;
                if (st[a][b]) {
                    connect(a * m + b, x * m + y);
                }
            }
            if (find(0) == find(size - 1)) break;
        }
        return res;
    }

private:
    struct Point {
        int x, y, w;

        bool operator<(const Point &point) const {
            return w < point.w;
        }
    };

    int n, m;

    vector<int> p, rk;
    vector<vector<bool>> st;

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rk[px] > rk[py]) swap(px, py);
            p[px] = py;
            rk[py] += rk[px];
        }
    }
};