#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 100010;

int p[N], sz[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct Node {
    int u, v, w, idx;

    bool operator<(const Node &node) const {
        return this->w < node.w;
    }
} e[N], q[N];

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        int m = (int) edgeList.size(), k = (int) queries.size();
        for (int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            e[i].u = edgeList[i][0];
            e[i].v = edgeList[i][1];
            e[i].w = edgeList[i][2];
        }
        for (int i = 0; i < k; i++) {
            q[i].u = queries[i][0];
            q[i].v = queries[i][1];
            q[i].w = queries[i][2];
            q[i].idx = i;
        }
        sort(e, e + m);
        sort(q, q + k);
        vector<bool> res(k);
        for (int i = 0, j = 0; i < k; i++) {
            int w = q[i].w;
            while (j < m && e[j].w < w) {
                int u = e[j].u, v = e[j].v;
                int pu = find(u), pv = find(v);
                if (pu != pv) {
                    if (sz[pu] < sz[pv]) swap(pu, pv);
                    p[pv] = pu;
                    sz[pu] += sz[pv];
                }
                j++;
            }
            if (find(q[i].u) == find(q[i].v)) res[q[i].idx] = true;
            else res[q[i].idx] = false;
        }
        return res;
    }
};