#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        using LL = long long;
        sort(rides.begin(), rides.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        vector<LL> dp(n + 1);
        for (int i = 1, j = 0; i <= n; i++) {
            dp[i] = dp[i - 1];
            while (j < rides.size() && rides[j][1] == i) {
                dp[i] = max(dp[i], (LL) rides[j][1] - rides[j][0] + rides[j][2] + dp[rides[j][0]]);
                j++;
            }
        }
        return dp[n];
    }
};