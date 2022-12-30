#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>> &mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        int sum = 0;
        for (const auto &row: mat) {
            for (int x: row) {
                sum += x;
            }
        }
        if (!sum) return 0;
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        set<vector<vector<int>>> st;
        st.insert(mat);
        queue<vector<vector<int>>> q;
        q.push(mat);
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        auto grid = t;
                        grid[i][j] ^= 1;
                        for (int idx = 0; idx < 4; idx++) {
                            int a = i + dx[idx], b = j + dy[idx];
                            if (a < 0 || a == n || b < 0 || b == m) continue;
                            grid[a][b] ^= 1;
                        }
                        if (st.count(grid)) continue;
                        st.insert(grid);
                        q.push(grid);
                        int s = 0;
                        for (auto &row: grid) {
                            for (int num: row) {
                                s += num;
                            }
                        }
                        if (!s) return step;
                    }
                }
            }
        }
        return -1;
    }
};