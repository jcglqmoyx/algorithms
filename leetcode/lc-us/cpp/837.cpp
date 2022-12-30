#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1;
        double f[n + maxPts];
        memset(f, 0, sizeof f);
        for (int i = k; i <= n; i++) f[i] = 1;
        for (int i = 1; i <= maxPts; i++) f[k - 1] += 1.0 / maxPts * (f[k + i - 1]);
        for (int i = k - 2; i >= 0; i--) f[i] = f[i + 1] + 1.0 / maxPts * (f[i + 1] - f[i + maxPts + 1]);
        return f[0];
    }
};