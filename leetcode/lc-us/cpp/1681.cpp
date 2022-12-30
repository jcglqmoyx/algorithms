#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int> &nums, int k) {
        const int INF = 0x3f3f3f3f;

        int n = (int) nums.size();
        if (k == n) return 0;
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > k) return -1;
        }

        unordered_map<int, int> incompatibility;
        bool st[n + 1];
        int sz = n / k;

        for (int i = 1; i < 1 << n; i++) {
            int p = __builtin_popcount(i);
            if (p == sz) {
                memset(st, false, sizeof st);
                bool flag = true;
                int mn = INF, mx = -INF;
                for (int u = 0; u < n; u++) {
                    if (i >> u & 1) {
                        if (st[nums[u]]) {
                            flag = false;
                            break;
                        }
                        st[nums[u]] = true;
                        mn = min(mn, nums[u]);
                        mx = max(mx, nums[u]);
                    }
                }
                if (flag) incompatibility[i] = mx - mn;
            }
        }

        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            int p1 = __builtin_popcount(i);
            if (p1 % sz == 0) {
                if (p1 == sz) {
                    if (incompatibility.count(i)) {
                        f[i] = incompatibility[i];
                    }
                } else {
                    for (int t = i; t; t = (t - 1) & i) {
                        int p2 = __builtin_popcount(t);
                        if (p1 - p2 == sz && incompatibility.count(i ^ t)) {
                            f[i] = min(f[i], f[t] + incompatibility[i ^ t]);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};