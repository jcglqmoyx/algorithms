#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int len = matrix.size(), wid = matrix[0].size();
        int i = len - 1, j = 0;
        while (true) {
            while (i >= 0 && matrix[i][j] > target) {
                i--;
            }
            if (i < 0) break;
            while (j < wid && matrix[i][j] < target) {
                j++;
            }
            if (j == wid) break;
            if (matrix[i][j] == target) return true;
        }
        return false;
    }
};