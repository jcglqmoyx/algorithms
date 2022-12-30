#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        queue<vector<int>> q;
        int m = (int) isWater.size(), n = (int) isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t[0], y = t[1], d = t[2];
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b]) {
                    res[a][b] = d + 1;
                    q.push({a, b, d + 1});
                    visited[a][b] = true;
                }
            }
        }
        return res;
    }
};