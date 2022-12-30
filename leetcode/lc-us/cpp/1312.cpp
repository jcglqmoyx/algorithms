#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = (int) s.size();
        int f[n + 2][n + 1];
        memset(f, 0, sizeof f);
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if (i == j) f[i][j] = 1;
                else if (s[i - 1] == s[j - 1]) f[i][j] = f[i + 1][j - 1] + 2;
                f[i][j] = max(f[i][j], max(f[i + 1][j], f[i][j - 1]));
            }
        }
        return n - f[1][n];
    }
};