#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 4e4 + 10;

bool st[N];
double dist[N];
int h[N], e[M], ne[M], idx;
double w[M];

inline void add(int a, int b, double c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start) {
    memset(dist, 0, sizeof dist);
    dist[start] = 1;
    priority_queue<pair<double, int>> heap;
    heap.push({1, start});
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        if (st[t.second]) continue;
        st[t.second] = true;
        for (int i = h[t.second]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] < t.first * w[i]) {
                dist[j] = t.first * w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        memset(h, -1, sizeof h), idx = 0;
        memset(st, false, sizeof st);
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];
            double distance = succProb[i];
            add(x, y, distance);
            add(y, x, distance);
        }
        dijkstra(start);
        return dist[end];
    }
};