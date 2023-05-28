#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int it = n + m - 1; it; it--) {
            int i = it >= n ? 0 : n - it;
            int j = it >= n ? it - n : 0;
            unordered_map<int, int> s1, s2;
            for (int x = i, y = j; x < n && y < m; x++, y++) s2[grid[x][y]]++;
            for (int x = i, y = j; x < n && y < m; x++, y++) {
                s2[grid[x][y]]--;
                if (s2[grid[x][y]] == 0) s2.erase(grid[x][y]);
                res[x][y] = abs((int) s1.size() - (int) s2.size());
                s1[grid[x][y]]++;
            }
        }
        return res;
    }
};