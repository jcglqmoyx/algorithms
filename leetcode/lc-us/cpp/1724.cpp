#include <bits/stdc++.h>

using namespace std;

class DistanceLimitedPathsExist {
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>> &edgeList) {
        f.resize(n), w.resize(n, 1e9), sz.resize(n, 1);
        for (int i = 0; i < n; i++) f[i] = i;
        sort(edgeList.begin(), edgeList.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        for (auto &e: edgeList) merge(e[0], e[1], e[2]);
    }

    bool query(int p, int q, int limit) {
        return find(p, limit) == find(q, limit);
    }

private:
    vector<int> f, w, sz;

    int find(int x, int v) {
        while (w[x] < v) x = f[x];
        return x;
    }

    void merge(int x, int y, int v) {
        x = find(x, v + 1), y = find(y, v + 1);
        if (x != y) {
            if (sz[x] > sz[y]) {
                f[y] = x;
                sz[x] += sz[y];
                w[y] = v;
            } else {
                f[x] = y;
                sz[y] += sz[x];
                w[x] = v;
            }
        }
    }
};