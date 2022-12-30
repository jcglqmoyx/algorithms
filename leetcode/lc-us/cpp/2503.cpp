#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int tot = n * m;
        p.resize(tot), sz.resize(tot, 1);
        for (int i = 0; i < tot; i++) p[i] = i;
        int k = (int) queries.size();

        vector<T> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back({grid[i][j], i, j});
            }
        }
        sort(v.begin(), v.end());

        vector<pair<int, int>> q(k);
        for (int i = 0; i < k; i++) {
            q[i] = {queries[i], i};
        }
        sort(q.begin(), q.end());

        vector<int> res(k);
        for (int i = 0, j = 0; j < k; j++) {
            while (i < tot && v[i].val < q[j].first) {
                int x = v[i].x, y = v[i].y;
                for (int u = 0; u < 4; u++) {
                    int a = x + dx[u], b = y + dy[u];
                    if (a < 0 || a == n || b < 0 || b == m || grid[a][b] >= q[j].first) continue;
                    connect(x * m + y, a * m + b);
                }
                i++;
            }
            if (grid[0][0] < q[j].first) res[q[j].second] = sz[find(0)];
        }
        return res;
    }

private:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<int> p, sz;

    struct T {
        int val;
        int x, y;

        bool operator<(const T &t) const {
            return val < t.val;
        }
    };

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (sz[px] > sz[py]) swap(px, py);
        p[px] = py;
        sz[py] += sz[px];
    }
};