#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int n = (int) land.size(), m = (int) land[0].size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!land[i][j]) {
                    land[i][j] = 1;
                    int sz = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        for (int d = 0; d < 8; d++) {
                            int x = t.first + dx[d], y = t.second + dy[d];
                            if (x < 0 || x == n || y < 0 || y == m || land[x][y]) continue;
                            q.push({x, y});
                            land[x][y] = 1;
                            sz++;
                        }
                    }
                    res.emplace_back(sz);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};