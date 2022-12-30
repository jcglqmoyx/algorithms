#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        vector<int> coins = {1, 5, 10, 25};
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int coin: coins) {
            for (int i = coin; i <= n; i++) {
                dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
            }
        }
        return dp[n];
    }
};