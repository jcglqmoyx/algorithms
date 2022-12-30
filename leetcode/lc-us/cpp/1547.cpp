#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int> &cuts) {
        const int INF = 0x3f3f3f3f;
        cuts.push_back(0), cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        n = (int) cuts.size();
        int f[n][n];
        memset(f, 0x3f, sizeof f);
        function<int(int, int)> dp = [&](int l, int r) -> int {
            if (r - l < 2) return 0;
            if (f[l][r] != INF) return f[l][r];
            int t = INT32_MAX;
            for (int i = l + 1; i < r; i++) {
                t = min(t, dp(l, i) + dp(i, r) + cuts[r] - cuts[l]);
            }
            return f[l][r] = t;
        };
        return dp(0, n - 1);
    }
};