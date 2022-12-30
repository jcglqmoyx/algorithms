#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>> &indices) {
        vector<int> row(n), col(m);
        for (auto &index: indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        int odd_cells = 0;
        for (int i: row) {
            for (int j: col) {
                odd_cells += (i + j) & 1;
            }
        }
        return odd_cells;
    }
};