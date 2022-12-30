#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        const double eps = 1e-8;
        int n = (int) dist.size();
        double f[n + 1][n + 1];
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = 1e20;
                if (j != i) f[i][j] = ceil(f[i - 1][j] + (double) dist[i - 1] / speed - eps);
                if (j) f[i][j] = min(f[i][j], f[i - 1][j - 1] + (double) dist[i - 1] / speed);
            }
        }
        for (int i = 0; i <= n; i++) {
            if (f[n][i] < hoursBefore + eps) return i;
        }
        return -1;
    }
};