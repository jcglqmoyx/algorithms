#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int securityCheck(vector<int> &capacities, int k) {
        for (int &x: capacities) x--;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int x: capacities) {
            for (int j = k; j >= 0; j--) {
                if (j < x) break;
                dp[j] = (dp[j] + dp[j - x]) % 1000000007;
            }
        }
        return dp[k];
    }
};