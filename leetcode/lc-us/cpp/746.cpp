#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int prev = 0, cur = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int next = min(prev + cost[i - 2], cur + cost[i - 1]);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};