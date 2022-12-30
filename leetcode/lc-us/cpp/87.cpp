#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = (int) s1.size();
        bool f[n][n][n + 1];
        memset(f, 0, sizeof f);
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i + k - 1 < n; i++) {
                for (int j = 0; j + k - 1 < n; j++) {
                    if (k == 1) f[i][j][k] = s1[i] == s2[j];
                    else {
                        for (int u = 1; u < k; u++) {
                            if (f[i][j + k - u][u] && f[i + u][j][k - u] || f[i][j][u] && f[i + u][j + u][k - u]) {
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return f[0][0][n];
    }
};