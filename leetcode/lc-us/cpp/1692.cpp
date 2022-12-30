#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToDistribute(int n, int k) {
        int MOD = 1e9 + 7;
        vector<int> f(k + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<int> g = f;
            for (int j = 1; j <= k; j++) {
                g[j] = (f[j - 1] + (long long) f[j] * j) % MOD;
            }
            g[0] = 0;
            f = move(g);
        }
        return f[k];
    }
};