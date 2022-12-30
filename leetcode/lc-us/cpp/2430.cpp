#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    const int P = 13331;

    int n;
    vector<ULL> h, p;

    int f[4005];

    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int dfs(int u) {
        if (f[u]) return f[u];
        int res = 1;
        for (int len = 1; u + len * 2 - 1 <= n; len++) {
            if (get(u, u + len - 1) == get(u + len, u + len * 2 - 1)) {
                res = max(res, dfs(u + len) + 1);
            }
        }
        f[u] = res;
        return f[u];
    }

public:
    int deleteString(string s) {
        memset(f, 0, sizeof f);
        n = (int) s.size();
        h.resize(n + 1);
        for (int i = 1; i <= n; i++) h[i] = h[i - 1] * P + s[i - 1];
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * P;

        int res = 1;
        for (int len = 1; len <= n / 2; len++) {
            if (get(1, len) == get(len + 1, len * 2)) {
                res = max(res, 1 + dfs(len + 1));
            }
        }
        return res;
    }
};