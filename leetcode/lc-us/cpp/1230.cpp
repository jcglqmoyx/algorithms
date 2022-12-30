#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double probabilityOfHeads(vector<double> &prob, int target) {
        int n = (int) prob.size();
        vector<vector<double>> f(n + 1, vector<double>(target + 1));
        f[0][0] = 1;
        double p = 1;
        for (int i = 1; i <= n; i++) {
            p *= 1 - prob[i - 1];
            f[i][0] = p;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, target); j++) {
                f[i][j] = f[i - 1][j] * (1 - prob[i - 1]) + f[i - 1][j - 1] * prob[i - 1];
            }
        }
        return f[n][target];
    }
};