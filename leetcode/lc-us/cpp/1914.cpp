#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {
        using VI = vector<int>;
        using VVI = vector<vector<int>>;

        VVI res = grid;
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int a = n, b = m, i = 0; a > 0 && b > 0; a -= 2, b -= 2, i++) {
            int x = i, y = i;
            VVI q;
            for (int j = 0; j < b - 1; j++) q.push_back({x, ++y});
            for (int j = 0; j < a - 1; j++) q.push_back({++x, y});
            for (int j = 0; j < b - 1; j++) q.push_back({x, --y});
            for (int j = 0; j < a - 1; j++) q.push_back({--x, y});
            for (int j = 0; j < q.size(); j++) {
                int t = (j + k) % (int) q.size();
                res[q[j][0]][q[j][1]] = grid[q[t][0]][q[t][1]];
            }
        }
        return res;
    }
};