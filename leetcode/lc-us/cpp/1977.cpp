#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfCombinations(string num) {
        int MOD = 1e9 + 7;

        if (num[0] == '0') return 0;

        int n = (int) num.size();
        int lcp[n][n];
        memset(lcp, 0, sizeof lcp);
        for (int i = n - 1; i >= 0; i--) {
            lcp[i][n - 1] = (num[i] == num[n - 1]);
            for (int j = i; j < n - 1; j++) {
                lcp[i][j] = num[i] == num[j] ? lcp[i + 1][j + 1] + 1 : 0;
            }
        }

        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) f[0][i] = 1;
        for (int i = 1; i < n; i++) {
            if (num[i] == '0') continue;
            int pre_sum = 0;
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                f[i][j] = pre_sum;
                if (i - len >= 0) {
                    if (lcp[i - len][i] >= len || num[i - len + lcp[i - len][i]] < num[i + lcp[i - len][i]]) {
                        f[i][j] = (f[i][j] + f[i - len][i - 1]) % MOD;
                    }
                    pre_sum = (pre_sum + f[i - len][i - 1]) % MOD;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + f[i][n - 1]) % MOD;
        }
        return res;
    }
};