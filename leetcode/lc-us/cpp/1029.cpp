#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] - a[1] < b[0] - b[1];
    }

public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int min_cost = 0;
        sort(costs.begin(), costs.end(), &cmp);
        for (int i = 0; i < costs.size() / 2; i++) {
            min_cost += costs[i][0] + costs[i + costs.size() / 2][1];
        }
        return min_cost;
    }
};