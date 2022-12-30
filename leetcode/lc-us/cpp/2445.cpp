#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfNodes(int n, vector<int> &queries) {
        bool flip[n + 1];
        int cnt[n + 1];
        memset(flip, 0, sizeof flip), memset(cnt, 0, sizeof cnt);
        for (int q: queries) flip[q] = !flip[q];

        function<void(int, int)> dfs = [&](int u, int total) {
            cnt[u] += total;
            if (flip[u]) cnt[u]++;
            if ((u << 1) <= n) dfs(u << 1, cnt[u]);
            if ((u << 1 | 1) <= n) dfs(u << 1 | 1, cnt[u]);
        };

        dfs(1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] & 1) res++;
        }
        return res;
    }
};