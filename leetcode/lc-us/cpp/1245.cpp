#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int N = 10010, M = N << 1;
    int res;
    int h[N], e[M], ne[M], idx;
    bool st[N];

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int bfs(int start) {
        memset(st, false, sizeof st);
        int last;
        queue<int> q;
        q.push(start);
        st[start] = true;
        int dist = -1;
        while (!q.empty()) {
            dist++;
            for (int it = (int) q.size(); it; it--) {
                int t = q.front();
                q.pop();
                for (int i = h[t]; i != -1; i = ne[i]) {
                    int j = e[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                        last = j;
                    }
                }
            }
        }
        res = max(res, dist);
        return last;
    }

public:
    int treeDiameter(vector<vector<int>> &edges) {
        res = 0;
        memset(h, -1, sizeof h), idx = 0;

        int deg[N];
        memset(deg, 0, sizeof deg);

        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
            deg[x]++, deg[y]++;
        }
        int n = (int) edges.size();
        int last;
        for (int i = 0; i <= n; i++) {
            if (deg[i] == 1) {
                last = bfs(i);
                bfs(last);
                break;
            }
        }
        return res;
    }
};