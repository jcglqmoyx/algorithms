#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &cost) {
        int n = (int) cost.size();
        int res = 0;
        sort(cost.begin(), cost.end(), greater<>());
        for (int i = 0; i < n; i++) {
            if (i % 3 == 2) continue;
            res += cost[i];
        }
        return res;
    }
};