#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        int n = (int) flights.size(), k = (int) days[0].size();
        int f[n];
        memset(f, -1, sizeof f);
        f[0] = days[0][0];
        int res = f[0];
        for (int i = 1; i < n; i++) {
            f[i] = flights[0][i] ? days[i][0] : -1;
        }
        for (int i = 1; i < k; i++) {
            int g[n];
            memset(g, -1, sizeof g);
            for (int j = 0; j < n; j++) {
                for (int last = 0; last < n; last++) {
                    if (f[last] != -1 && (flights[last][j] || last == j)) {
                        g[j] = max(g[j], f[last] + days[j][i]);
                    }
                }
                res = max(res, g[j]);
            }
            for (int u = 0; u < n; u++) f[u] = g[u];
        }
        return res;
    }
};