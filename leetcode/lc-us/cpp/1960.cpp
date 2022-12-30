#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxProduct(string s) {
        using LL = long long;
        int n = (int) s.size();

        vector<int> p(n);
        p[0] = 1;
        int mr = 0, mid;
        for (int i = 1; i < n; i++) {
            if (i < mr) p[i] = min(mr - i, p[mid * 2 - i]);
            else p[i] = 1;
            while (i >= p[i] && s[i - p[i]] == s[i + p[i]]) p[i]++;
            if (i + p[i] > mr) {
                mr = i + p[i];
                mid = i;
            }
        }

        vector<int> f(n), g(n);
        for (int i = 0; i < n; i++) {
            int l = i - p[i] + 1, r = i + p[i] - 1;
            int len = r - l + 1;
            f[r] = max(f[r], len);
            g[l] = max(g[l], len);
        }
        for (int i = 1; i < n; i++) f[i] = max(f[i], f[i - 1]);
        for (int i = n - 2; i >= 0; i--) f[i] = max(f[i], f[i + 1] - 2);
        for (int i = n - 2; i >= 0; i--) g[i] = max(g[i], g[i + 1]);
        for (int i = 1; i < n; i++) g[i] = max(g[i], g[i - 1] - 2);

        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) res = f[0] * g[1];
            else if (i == n - 1) res = max(res, f[n - 2] * 1LL);
            else res = max(res, f[i] * 1LL * g[i + 1]);
        }
        return res;
    }
};