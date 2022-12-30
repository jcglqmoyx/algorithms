#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - prices[i - 1];
            max_profit += profit > 0 ? profit : 0;
        }
        return max_profit;
    }
};