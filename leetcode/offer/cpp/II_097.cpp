#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int n = (int) s.size(), m = (int) t.size(), MOD = INT32_MAX;
        vector<vector<long>> f(n + 1, vector<long>(m + 1));
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                    f[i][j] %= MOD;
                }
            }
        }
        return f[n][m];
    }
};