#include <bits/stdc++.h>

using namespace std;

class Solution {
    int flag[10] = {1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
    int v[5]{}, len{};
    int f[5][2]{};

    int dp(int u, bool is_limited, bool has_diff) {
        if (u == len) return has_diff;
        if (!is_limited && f[u][has_diff] != -1) return f[u][has_diff];
        int res = 0;
        int mx = is_limited ? v[u] : 9;
        for (int d = 0; d <= mx; d++) {
            if (!flag[d]) continue;
            res += dp(u + 1, is_limited && d == mx, has_diff || flag[d] == 2);
        }
        f[u][has_diff] = res;
        return res;
    }

public:
    int rotatedDigits(int n) {
        memset(f, -1, sizeof f);
        len = 0;
        while (n) {
            v[len++] = n % 10;
            n /= 10;
        }
        reverse(v, v + len);
        return dp(0, true, false);
    }
};