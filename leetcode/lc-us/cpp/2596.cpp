#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        if (grid[0][0]) return false;
        vector<pair<int, int>> v(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[grid[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < n * n - 1; i++) {
            int dx = abs(v[i].first - v[i + 1].first);
            int dy = abs(v[i].second - v[i + 1].second);
            if (dx == 1 && dy == 2 || dx == 2 && dy == 1) continue;
            return false;
        }
        return true;
    }
};