#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        auto cost = [&](int m, int s) -> int {
            if (m < 0 || m > 99 || s < 0 || s > 99) {
                return INT32_MAX;
            }
            vector<int> digits = {m / 10, m % 10, s / 10, s % 10};
            int start = 0;
            while (start < 4 && digits[start] == 0) {
                start++;
            }
            int prev = startAt;
            int cost = 0;
            while (start < 4) {
                int cur = digits[start];
                if (cur != prev) {
                    cost += moveCost;
                }
                cost += pushCost;
                prev = cur;
                start++;
            }
            return cost;
        };
        int m = targetSeconds / 60, s = targetSeconds % 60;
        return min(cost(m, s), cost(m - 1, s + 60));
    }
};