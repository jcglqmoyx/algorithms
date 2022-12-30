#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        vector<vector<vector<bool>>> st(n, vector<vector<bool>>(n, vector<bool>(2)));
        queue<vector<int>> q;
        q.push({0, 1, 1});
        st[0][1][1] = true;

        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                int x = t[0], y = t[1], d = t[2];
                if (d == 0) {
                    if (y + 1 < n && !grid[x - 1][y + 1] && !grid[x][y + 1]) {
                        if (!st[x - 1][y + 1][1]) {
                            q.push({x - 1, y + 1, 1});
                            st[x - 1][y + 1][1] = true;
                        }
                        if (!st[x][y + 1][0]) {
                            q.push({x, y + 1, 0});
                            st[x][y + 1][0] = true;
                        }
                    }
                    if (x + 1 < n && !grid[x + 1][y] && !st[x + 1][y][0]) {
                        q.push({x + 1, y, 0});
                        st[x + 1][y][0] = true;
                    }
                } else {
                    if (x + 1 < n && !grid[x + 1][y - 1] && !grid[x + 1][y]) {
                        if (!st[x + 1][y - 1][0]) {
                            q.push({x + 1, y - 1, 0});
                            st[x + 1][y - 1][0] = true;
                        }
                        if (!st[x + 1][y][1]) {
                            if (x == n - 2 && y == n - 1) return step;
                            q.push({x + 1, y, 1});
                            st[x + 1][y][1] = true;
                        }
                    }
                    if (y + 1 < n && !grid[x][y + 1] && !st[x][y + 1][1]) {
                        if (x == n - 1 && y == n - 2) return step;
                        q.push({x, y + 1, 1});
                        st[x][y + 1][1] = true;
                    }
                }
            }
        }
        return -1;
    }
};