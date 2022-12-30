#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> cost;
public:
    int palindromePartition(string s, int k) {
        int n = (int) s.size();
        cost.resize(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                cost[i][j] = 0;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i - 1] != s[j - 1]);
            }
        }

        vector<vector<int>> f(n + 1, vector<int>(k + 1, 1e8));
        f[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                f[i][j] = f[i - 1][j - 1];
                for (int p = i - 1; p; p--) {
                    f[i][j] = min(f[i][j], f[p - 1][j - 1] + cost[p][i]);
                }
            }
        }
        return f[n][k];
    }
};