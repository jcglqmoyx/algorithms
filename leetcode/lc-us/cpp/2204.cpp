#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool st[N];
int deg[N];
int h[N], e[N << 1], ne[N << 1], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>> &edges) {
        memset(st, false, sizeof st);
        memset(deg, 0, sizeof deg);
        memset(h, -1, sizeof h), memset(ne, 0, sizeof ne), idx = 0;
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
            deg[x]++, deg[y]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                deg[i] = 0;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (deg[j]) deg[j]--;
                if (deg[j] == 1) {
                    deg[j] = 0;
                    q.push(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (deg[i]) {
                q.push(i);
                st[i] = true;
            }
        }
        vector<int> res(n);
        int dist = 0;
        while (!q.empty()) {
            dist++;
            for (auto it = q.size(); it; it--) {
                int t = q.front();
                q.pop();
                for (int i = h[t]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (st[j]) continue;
                    res[j] = dist;
                    q.push(j);
                    st[j] = true;
                }
            }
        }
        return res;
    }
};