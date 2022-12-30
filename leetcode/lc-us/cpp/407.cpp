#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>> &h) {
        int n = (int) h.size(), m = (int) h[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        priority_queue<Cell> heap;
        for (int i = 0; i < n; i++) {
            st[i][0] = st[i][m - 1] = true;
            heap.push({h[i][0], i, 0});
            heap.push({h[i][m - 1], i, m - 1});
        }
        for (int j = 1; j < m - 1; j++) {
            st[0][j] = st[n - 1][j] = true;
            heap.push({h[0][j], 0, j});
            heap.push({h[n - 1][j], n - 1, j});
        }
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        int res = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            res += t.h - h[t.x][t.y];
            for (int i = 0; i < 4; i++) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || st[x][y]) continue;
                heap.push({max(t.h, h[x][y]), x, y});
                st[x][y] = true;
            }
        }
        return res;
    }

private:
    struct Cell {
        int h, x, y;

        bool operator<(const Cell &cell) const {
            return h > cell.h;
        }
    };
};