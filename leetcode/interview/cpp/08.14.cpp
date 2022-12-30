#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countEval(string s, int result) {
        int n = (int) s.size();
        if (!n) return 0;
        if (n == 1) return s[0] - '0' == result;
        int f[n][n][2];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i += 2) f[i][i][s[i] - '0'] = 1;
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i += 2) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k += 2) {
                    int l0 = f[i][k - 1][0], l1 = f[i][k - 1][1], r0 = f[k + 1][j][0], r1 = f[k + 1][j][1];
                    int &f0 = f[i][j][0], &f1 = f[i][j][1];
                    if (s[k] == '&') {
                        f0 += (l0 + l1) * (r0 + r1) - l1 * r1;
                        f1 += l1 * r1;
                    } else if (s[k] == '|') {
                        f0 += l0 * r0;
                        f1 += (l0 + l1) * (r0 + r1) - l0 * r0;
                    } else if (s[k] == '^') {
                        f0 += l0 * r0 + l1 * r1;
                        f1 += l0 * r1 + l1 * r0;
                    }
                }
            }
        }
        return f[0][n - 1][result];
    }
};