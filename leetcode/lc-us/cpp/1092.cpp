#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = (int) s1.size(), m = (int) s2.size();
        int f[n + 2][m + 2];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        string res;
        int i = n, j = m;
        while (f[i][j]) {
            if (s1[i - 1] == s2[j - 1]) res.push_back(s1[--i]), j--;
            else {
                if (f[i - 1][j] > f[i][j - 1]) res.push_back(s1[--i]);
                else res.push_back(s2[--j]);
            }
        }
        while (i) res.push_back(s1[--i]);
        while (j) res.push_back(s2[--j]);
        reverse(res.begin(), res.end());
        return res;
    }
};