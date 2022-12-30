#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = (int) customers.size();
        int profit = 0;
        int max_profit = 0;
        for (char c: customers) {
            if (c == 'Y') profit++;
            else profit--;
            max_profit = max(max_profit, profit);
        }
        if (!max_profit) return 0;
        profit = 0;
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'Y') profit++;
            else profit--;
            if (profit == max_profit) {
                return i;
            }
        }
        return 0;
    }
};