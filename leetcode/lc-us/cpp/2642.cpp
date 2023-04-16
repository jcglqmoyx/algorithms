#include <bits/stdc++.h>

using namespace std;

class Graph {
    const int INF = 0x3f3f3f3f;
    int m;
    vector<vector<int>> g;
    bool st[105];
    int dist[105];
public:
    Graph(int n, vector<vector<int>> &edges) {
        m = n;
        g.resize(m, vector<int>(m, INF));
        for (int i = 0; i < m; i++) g[i][i] = 0;
        for (auto &e: edges) {
            g[e[0]][e[1]] = e[2];
        }
    }

    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int node1, int node2) {
        memset(st, 0, sizeof st);
        memset(dist, 0x3f, sizeof dist);
        dist[node1] = 0;
        for (int i = 0; i < m - 1; i++) {
            int t = -1;
            for (int j = 0; j < m; j++) {
                if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
            }
            for (int j = 0; j < m; j++) {
                if (!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
            st[t] = true;
        }
        return dist[node2] == INF ? -1 : dist[node2];
    }
};