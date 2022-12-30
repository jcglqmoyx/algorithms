#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int profit = 0, max_profit = 0, wait = 0, res = 0, turn = 0;
        int i = 0;
        while (wait || i < customers.size()) {
            if (i < customers.size()) wait += customers[i], i++;
            int t = min(wait, 4);
            wait -= t;
            profit += t * boardingCost - runningCost;
            turn++;
            if (profit > max_profit) {
                max_profit = profit;
                res = turn;
            }
        }
        return res ? res : -1;
    }
};