#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (auto &r: grid) {
            sort(r.begin(), r.end(), greater<>());
        }
        int res = 0;
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, grid[i][j]);
            }
            res += mx;
        }
        return res;
    }
};