#include <bits/stdc++.h>

using namespace std;

class Solution {
    int g(int x) {
        return max(0, x);
    }

public:
    double soupServings(int n) {
        n = (n + 24) / 25;
        if (n >= 500) return 1.0;
        vector<vector<double>> f(n + 1, vector<double>(n + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (!i && !j) f[i][j] = 0.5;
                else if (!i) f[i][j] = 1;
                else if (!j) f[i][j] = 0;
                else
                    f[i][j] = (f[g(i - 4)][j]
                               + f[g(i - 3)][g(j - 1)]
                               + f[g(i - 2)][g(j - 2)]
                               + f[g(i - 1)][g(j - 3)]) / 4;
            }
        }
        return f[n][n];
    }
};