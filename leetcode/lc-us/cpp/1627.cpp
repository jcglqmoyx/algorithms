#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p, sz;

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

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries) {
        p.resize(n + 1), sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = threshold + 1; i <= n; i++) {
            for (int m = i << 1; m <= n; m += i) {
                connect(i, m);
            }
        }
        vector<bool> res;
        res.reserve(queries.size());
        for (auto &q: queries) {
            res.push_back(find(q[0]) == find(q[1]));
        }
        return res;
    }
};