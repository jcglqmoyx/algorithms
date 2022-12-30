#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int) word1.size(), n = (int) word2.size();
        int f[m + 1][n + 1];
        for (int i = 0; i <= n; i++) f[0][i] = i;
        for (int i = 0; i <= m; i++) f[i][0] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                } else {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        return f[m][n];
    }
};