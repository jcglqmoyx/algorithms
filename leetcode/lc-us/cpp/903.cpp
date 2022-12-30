#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPermsDISequence(string s) {
        const int MOD = 1e9 + 7;
        int n = (int) s.size();
        int f[n + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'D') {
                for (int j = i - 1; j >= 0; j--) {
                    f[i][j] = (f[i - 1][j] + f[i][j + 1]) % MOD;
                }
            } else {
                for (int j = 1; j <= i; j++) {
                    f[i][j] = (f[i - 1][j - 1] + f[i][j - 1]) % MOD;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; i++) res = (res + f[n][i]) % MOD;
        return res;
    }
};