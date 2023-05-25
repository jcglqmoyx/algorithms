#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (!k) return 1.0;
        double f[n + maxPts];
        memset(f, 0, sizeof f);
        for (int i = k; i < min(n + 1, k + maxPts); i++) f[i] = 1.0;
        double s = 0;
        for (int i = k; i <= min(n, k + maxPts - 1); i++) f[k - 1] += f[i] / maxPts, s += f[i];
        for (int i = k - 2; i >= 0; i--) {
            s += f[i + 1] - f[i + maxPts + 1];
            f[i] = s / maxPts;
        }
        return f[0];
    }
};