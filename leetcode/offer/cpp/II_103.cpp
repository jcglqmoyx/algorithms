#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        const int INF = 1e9;
        vector<int> f(amount + 1, INF);
        f[0] = 0;
        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                f[i] = min(f[i], f[i - coin] + 1);
            }
        }
        if (f[amount] == INF) return -1;
        return f[amount];
    }
};