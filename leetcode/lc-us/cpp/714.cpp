#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int a = 0, b = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int x = max(a, b + prices[i] - fee);
            int y = max(b, a - prices[i]);
            a = x, b = y;
        }
        return max(a, b);
    }
};