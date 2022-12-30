#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> depth;
    vector<int> p;
    bool nodes[1005];
    bool st[1005];

    void dfs(vector<vector<int>> &g, int u, int parent, int level) {
        depth[u] = level;
        if (parent != -1) p[u] = parent;
        for (int ne: g[u]) {
            if (!depth[ne]) {
                dfs(g, ne, u, level + 1);
            }
        }
    }

    int bfs(int node, vector<vector<int>> &g) {
        if (nodes[node]) return node;
        memset(st, false, sizeof st);
        int q[1005] = {};
        int hh = 0, tt = -1;
        q[++tt] = node;
        st[node] = true;
        while (hh <= tt) {
            int t = q[hh++];
            for (int ne: g[t]) {
                if (nodes[ne]) return ne;
                if (!st[ne]) {
                    q[++tt] = ne;
                    st[ne] = true;
                }
            }
        }
        return node;
    }

public:
    vector<int> closestNode(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
        depth = vector<int>(n), p = vector<int>(n);
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g, 0, -1, 1);
        vector<int> res;
        for (auto &q: query) {
            memset(nodes, false, sizeof(bool) * n);
            int from = q[0], to = q[1], node = q[2];
            nodes[from] = nodes[to] = true;
            while (from != to) {
                if (depth[from] < depth[to]) {
                    to = p[to];
                    nodes[to] = true;
                } else {
                    from = p[from];
                    nodes[from] = true;
                }
            }
            res.push_back(bfs(node, g));
        }
        return res;
    }
};