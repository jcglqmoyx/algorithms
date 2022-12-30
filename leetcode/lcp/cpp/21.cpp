#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> adj;
    vector<int> depth, parent;
    vector<bool> in_loop;
    int n, loop = 0;

    void dfs(int u, int p) {
        parent[u] = p;
        depth[u] = depth[p] + 1;
        for (int v: adj[u]) {
            if (v == p) continue;
            if (!depth[v]) dfs(v, u);
            else if (depth[v] < depth[u]) {
                int cu = u;
                while (cu != v) {
                    in_loop[cu] = true;
                    loop++;
                    cu = parent[cu];
                }
                in_loop[v] = true;
                loop++;
            }
        }
    }

    vector<int> bfs(int u, bool detect_loop) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        dist[u] = 0;
        q.push(u);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (detect_loop && in_loop[x]) return {x, dist[x]};
            for (int y: adj[x]) {
                if (dist[y] <= dist[x] + 1) continue;
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
        return dist;
    }

public:
    int chaseGame(vector<vector<int>> &edges, int startA, int startB) {
        n = (int) edges.size();
        adj = vector<vector<int>>(n + 1);
        for (auto v: edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
            if (v[0] == startA && v[1] == startB) return 1;
            if (v[0] == startB && v[1] == startA) return 1;
        }

        depth = vector<int>(n + 1);
        parent = vector<int>(n + 1);
        in_loop = vector<bool>(n + 1);
        dfs(1, 0);

        vector<int> da = bfs(startA, false);
        vector<int> db = bfs(startB, false);

        if (loop >= 4) {
            vector<int> qb = bfs(startB, true);
            if (qb[1] + 1 < da[qb[0]]) return -1;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (da[i] > db[i] + 1) ans = max(ans, da[i]);
        }
        return ans;
    }
};