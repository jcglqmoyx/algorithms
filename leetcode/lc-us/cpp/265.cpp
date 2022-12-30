#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        const int INF = 1e8;
        int n = (int) costs.size(), m = (int) costs[0].size();
        vector<int> f = costs[0];
        for (int i = 0, first = 0, second = 0, p; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p == j) {
                    f[j] = second + costs[i][j];
                } else {
                    f[j] = first + costs[i][j];
                }
            }
            first = second = INF;
            for (int j = 0; j < m; j++) {
                if (f[j] <= second) {
                    if (f[j] <= first) {
                        second = first;
                        first = f[j];
                        p = j;
                    } else {
                        second = f[j];
                    }
                }
            }
        }
        return *min_element(f.begin(), f.end());
    }
};