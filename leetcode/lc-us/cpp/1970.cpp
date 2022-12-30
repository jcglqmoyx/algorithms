#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        _row = row, _col = col;
        g = vector<vector<int>>(row, vector<int>(col));
        _cells = cells;
        int low = 0, high = (int) cells.size();
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (check(mid)) low = mid;
            else high = mid - 1;
        }
        return low;
    }

private:
    int _row, _col;
    bool valid;
    vector<vector<int>> g;
    vector<vector<int>> _cells;

    bool check(int day) {
        for (int i = 0; i < _row; i++) for (int j = 0; j < _col; j++) g[i][j] = 0;
        for (int i = 0; i < day; i++) {
            auto cell = _cells[i];
            g[cell[0] - 1][cell[1] - 1] = 1;
        }
        valid = false;
        for (int j = 0; j < _col; j++) {
            if (g[0][j] == 0) {
                dfs(0, j);
                if (valid) return true;
            }
        }
        return false;
    }

    void dfs(int x, int y) {
        if (x < 0 || y < 0 || y >= _col) return;
        if (g[x][y] == 1) return;
        if (x == _row - 1) {
            valid = true;
            return;
        }
        g[x][y] = 1;
        dfs(x, y + 1);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x - 1, y);
    }
};