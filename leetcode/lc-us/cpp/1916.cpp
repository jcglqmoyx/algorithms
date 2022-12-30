#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToBuildRooms(vector<int> &prevRoom) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        function<LL(LL, LL)> quick_power = [](LL x, LL y) -> LL {
            LL res = 1;
            while (y) {
                if (y & 1) res = (res * x) % MOD;
                x = (x * x) % MOD;
                y >>= 1;
            }
            return res;
        };

        int n = (int) prevRoom.size();

        LL fact[n + 1], inv[n + 1];
        fact[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = quick_power(fact[i], MOD - 2);
        }

        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[prevRoom[i]].push_back(i);
        }

        long long f[n];
        int sz[n];
        memset(f, 0, sizeof f), memset(sz, 0, sizeof sz);

        function<LL(int)> dfs = [&](int u) -> LL {
            f[u] = 1;
            for (int ne: g[u]) {
                LL x = dfs(ne);
                sz[u] += sz[ne];
                f[u] = (f[u] * x) % MOD;
            }
            f[u] = (f[u] * fact[sz[u]]) % MOD;
            for (int ne: g[u]) {
                f[u] = f[u] * inv[sz[ne]] % MOD;
            }
            sz[u]++;
            return f[u];
        };

        return (int) dfs(0);
    }
};