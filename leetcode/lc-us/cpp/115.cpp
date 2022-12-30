#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using LL = long long;

    int numDistinct(string s, string t) {
        int m = (int) s.size(), n = (int) t.size();
        if (m < n) return 0;
        vector<vector<LL>> f(m + 1, vector<LL>(n + 1));
        for (int i = 0; i <= m; i++) f[i][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i - 1] == t[j - 1]) f[i][j] += f[i - 1][j - 1];
                f[i][j] %= (int) (1e9 + 7);
            }
        }
        return (int) f[m][n];
    }
};