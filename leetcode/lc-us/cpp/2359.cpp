#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5, M = N << 1;

int n;
int h[N], e[M], ne[M], idx;

bool st[N];
int q[N], dist1[N], dist2[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int start, int dist[]) {
    memset(st, false, sizeof(bool) * n);
    dist[start] = 0;
    int hh = 0, tt = -1;
    q[++tt] = start;
    st[start] = true;
    int step = 0;
    while (hh <= tt) {
        step++;
        for (int it = tt - hh + 1; it; it--) {
            int t = q[hh++];
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (st[j]) continue;
                st[j] = true;
                q[++tt] = j;
                dist[j] = step;
            }
        }
    }
}

class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        n = (int) edges.size();
        memset(h, -1, sizeof(int) * n), idx = 0;
        memset(st, false, sizeof(bool) * n);
        memset(dist1, 0x3f, sizeof(int) * n), memset(dist2, 0x3f, sizeof(int) * n);
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1) {
                add(i, edges[i]);
            }
        }
        bfs(node1, dist1);
        bfs(node2, dist2);

        int max_dist = -1, res = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != INF && dist2[i] != INF) {
                int t = max(dist1[i], dist2[i]);
                if (max_dist == -1 || t < max_dist) max_dist = t, res = i;
            }
        }
        return res;
    }
};