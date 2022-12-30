#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int> &prices) {
        long long res = 0;
        int dp = 1;
        for (int i = 0; i < prices.size(); i++) {
            if (i && prices[i] == prices[i - 1] - 1) {
                dp++;
            } else {
                dp = 1;
            }
            res += dp;
        }
        return res;
    }
};