#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD = 1e9 + 7;
        int n = (int) s.size();
        int pre[n][4], next[n][4];
        memset(pre, n, sizeof pre), memset(next, -1, sizeof next);

        int pos[4];
        memset(pos, -1, sizeof pos);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                pre[i][j] = pos[j];
            }
            pos[s[i] - 'a'] = i;
        }
        for (int &p: pos) p = n;
        for (int i = n - 1; ~i; i--) {
            for (int j = 0; j < 4; j++) {
                next[i][j] = pos[j];
            }
            pos[s[i] - 'a'] = i;
        }

        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            f[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int l = next[i][s[i] - 'a'];
                    int r = pre[j][s[j] - 'a'];
                    if (l > r) {
                        f[i][j] = (f[i + 1][j - 1] * 2 + 2) % MOD;
                    } else if (l == r) {
                        f[i][j] = (f[i + 1][j - 1] * 2 + 1) % MOD;
                    } else {
                        f[i][j] = (int) ((0LL + f[i + 1][j - 1] * 2 - f[l + 1][r - 1] + MOD) % MOD);
                    }
                } else {
                    f[i][j] = (int) ((0LL + f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1] + MOD) % MOD);
                }
            }
        }

        return f[0][n - 1];
    }
};