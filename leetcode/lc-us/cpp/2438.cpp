#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        const int MOD = 1e9 + 7;
        vector<int> v;
        while (n) {
            v.push_back(n & -n);
            n -= n & -n;
        }
        n = (int) v.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            long long x = 1;
            for (int j = i; j < n; j++) {
                x = x * v[j] % MOD;
                f[i][j] = (int) x;
            }
        }
        int m = (int) queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            auto x = queries[i][0], y = queries[i][1];
            res[i] = f[x][y];
        }
        return res;
    }
};