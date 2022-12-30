#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int x = 0, y = 0, z = 0;
        for (auto &cost: costs) {
            int a = x, b = y, c = z;
            x = min(b, c) + cost[0];
            y = min(a, c) + cost[1];
            z = min(a, b) + cost[2];
        }
        return min(x, min(y, z));
    }
};