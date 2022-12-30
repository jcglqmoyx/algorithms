#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int> &values) {
        int n = (int) values.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                f[i][j] = 1e8;
                if (len == 3) {
                    f[i][j] = values[i] * values[j] * values[i + 1];
                } else {
                    for (int k = i + 1; k <= j - 1; k++) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};