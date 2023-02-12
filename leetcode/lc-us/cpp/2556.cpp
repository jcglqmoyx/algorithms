#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x == n - 1 && y == m - 1) return true;
            g[x][y] = 0;
            return x < n - 1 && g[x + 1][y] && dfs(x + 1, y) || y < m - 1 && g[x][y + 1] && dfs(x, y + 1);
        };
        return !dfs(0, 0) || !dfs(0, 0);
    }
};