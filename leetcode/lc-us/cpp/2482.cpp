#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<int> r0(n), r1(n), c0(m), c1(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) r1[i]++, c1[j]++;
                else r0[i]++, c0[j]++;
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = r1[i] + c1[j] - r0[i] - c0[j];
            }
        }
        return res;
    }
};