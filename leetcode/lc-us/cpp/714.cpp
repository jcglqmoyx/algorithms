#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = (int) prices.size();
        vector<vector<int>> f(n, vector<int>(2));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i] - fee);
        }
        return max(f[n - 1][0], f[n - 1][1]);
    }
};