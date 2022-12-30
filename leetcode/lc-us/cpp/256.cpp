#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int a = costs[0][0], b = costs[0][1], c = costs[0][2];
        for (int i = 1; i < costs.size(); i++) {
            int x = a, y = b, z = c;
            a = min(costs[i][0] + y, costs[i][0] + z);
            b = min(costs[i][1] + x, costs[i][1] + z);
            c = min(costs[i][2] + x, costs[i][2] + y);
        }
        return min(a, min(b, c));
    }
};