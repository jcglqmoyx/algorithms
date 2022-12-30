#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = (int) s1.size(), m = (int) s2.size(), INF = 1e9;
        s1 = ' ' + s1, s2 = ' ' + s2;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) f[i][0] = f[i - 1][0] + s1[i];
        for (int i = 1; i <= m; i++) f[0][i] = f[0][i - 1] + s2[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + s1[i] + s2[j]);
                f[i][j] = min(f[i][j], f[i - 1][j] + s1[i]);
                f[i][j] = min(f[i][j], f[i][j - 1] + s2[j]);
                if (s1[i] == s2[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }
        return f[n][m];
    }
};