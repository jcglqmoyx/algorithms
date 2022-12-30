#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCost(int n, vector<vector<int>> &highways, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &w: highways) {
            int x = w[0], y = w[1], z = w[2];
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        int f[n][1 << n];
        memset(f, -1, sizeof f);
        function<int(int, int)> dp = [&](int u, int st) -> int {
            int cnt = __builtin_popcount(st);
            if (cnt > k) return 0;
            if (f[u][st] != -1) return f[u][st];
            int ans = INT32_MIN;
            for (auto &ne: g[u]) {
                int p = ne.first, w = ne.second;
                if (!(st >> p & 1)) {
                    ans = max(ans, dp(p, st | (1 << p)) + w);
                }
            }
            f[u][st] = ans;
            return ans;
        };
        int res = -1;
        for (int i = 0; i < n; i++) {
            res = max(res, dp(i, 1 << i));
        }
        return res;
    }
};