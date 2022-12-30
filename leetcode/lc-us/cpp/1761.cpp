#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        const int INF = 1e8;

        int d[n + 1];
        bool st[(n + 5) * (n + 5)];
        memset(st, false, sizeof st);
        memset(d, 0, sizeof d);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            d[x]++, d[y]++;
            if (x > y) swap(x, y);
            st[x * (n + 1) + y] = true;
        }
        int res = INF;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (st[i * (n + 1) + j]) {
                    for (int k = j + 1; k <= n; k++) {
                        if (st[i * (n + 1) + k] && st[j * (n + 1) + k]) {
                            res = min(res, d[i] + d[j] + d[k] - 6);
                        }
                    }
                }
            }
        }
        return res == INF ? -1 : res;
    }
};