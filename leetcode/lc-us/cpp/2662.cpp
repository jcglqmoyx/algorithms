#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads) {
        int n = (int) specialRoads.size();
        int dist[n * 2 + 2][n * 2 + 2];
        memset(dist, 0x3f, sizeof dist);
        vector<pair<int, int>> v;
        int u = 0;
        for (auto &r: specialRoads) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            v.emplace_back(x1, y1);
            v.emplace_back(x2, y2);
            dist[u][u + 1] = min(abs(x1 - x2) + abs(y1 - y2), r[4]);
            u += 2;
        }
        v.emplace_back(start[0], start[1]);
        v.emplace_back(target[0], target[1]);
        n = (int) v.size();

        int f[n];
        memset(f, 0x3f, sizeof f);
        bool st[n];
        memset(st, 0, sizeof st);
        f[n - 2] = 0;
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 0; j < n; j++) {
                if (!st[j] && (t == -1 || f[j] < f[t])) t = j;
            }
            st[t] = true;
            for (int j = 0; j < n; j++) {
                if (st[j]) continue;
                int d = min(dist[t][j], abs(v[t].first - v[j].first) + abs(v[t].second - v[j].second));
                if (f[j] > f[t] + d) f[j] = f[t] + d;
            }
        }
        return f[n - 1];
    }
};