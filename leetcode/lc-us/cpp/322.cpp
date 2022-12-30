#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        const int MAX = 1e9;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin: coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] >= MAX ? -1 : dp[amount];
    }
};