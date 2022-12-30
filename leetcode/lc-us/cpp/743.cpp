#include <bits/stdc++.h>

using namespace std;

class Solution {
    const static int N = 105, INF = 0x3f3f3f3f;
    int g[N][N], dist[N];
    bool st[N];
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        memset(dist, 0x3f, sizeof dist);
        memset(g, 0x3f, sizeof g);
        dist[k] = 0;
        for (auto &t: times) g[t[0]][t[1]] = t[2];
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 1; j <= n; j++) {
                if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            st[t] = true;
            for (int j = 1; j <= n; j++) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};