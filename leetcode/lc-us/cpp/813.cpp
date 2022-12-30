#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int> &nums, int m) {
        int n = (int) nums.size();
        vector<double> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        vector<vector<double>> f(n + 1, vector<double>(m + 1, -1e9));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = max(f[i][j], f[k][j - 1] + (s[i] - s[k]) / (i - k));
                }
            }
        }
        return f[n][m];
    }
};