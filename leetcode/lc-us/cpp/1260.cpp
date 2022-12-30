#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        queue<int> q;
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                q.push(grid[i][j]);
        for (; k > 0; k--) {
            auto t = q.front();
            q.pop();
            q.push(t);
        }
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                grid[i][j] = q.front();
                q.pop();
            }
        return grid;
    }
};