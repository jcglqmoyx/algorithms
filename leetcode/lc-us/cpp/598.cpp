#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty()) {
            return m * n;
        }
        int min_row = 40000, min_col = 40000;
        for (const vector<int> &op: ops) {
            min_row = min(min_row, op[0]);
            min_col = min(min_col, op[1]);
        }
        return min_row * min_col;
    }
};