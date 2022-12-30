#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            while (i >= 0 && matrix[i][j] > target) {
                i--;
            }
            if (i < 0) break;
            if (matrix[i][j] == target) return true;
            while (j < m && matrix[i][j] < target) j++;
            if (j == m) break;
        }
        return false;
    }
};