#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = (int) s.size();
        int l[2][n];
        memset(l, 0, sizeof l);
        for (int i = 0; i < 2; i++) {
            for (int j = 0, k = i, c = 0; j < n; j++, k ^= 1) {
                if (k != s[j] - '0') c++;
                l[i][j] = c;
            }
        }
        int res = min(l[0][n - 1], l[1][n - 1]);
        if (n & 1) {
            int r[2][n];
            memset(r, 0, sizeof r);
            for (int i = 0; i < 2; i++) {
                for (int j = n - 1, k = i, c = 0; j >= 0; j--, k ^= 1) {
                    if (k != s[j] - '0') c++;
                    r[i][j] = c;
                }
            }
            for (int i = 0; i < n - 1; i++) {
                res = min(res, l[0][i] + r[1][i + 1]);
                res = min(res, l[1][i] + r[0][i + 1]);
            }
        }
        return res;
    }
};