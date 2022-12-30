#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = (int) s.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (i == j) f[i][j] = 1;
                else {
                    if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                    else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return n - f[0][n - 1] <= k;
    }
};