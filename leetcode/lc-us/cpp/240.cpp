#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int len = (int) matrix.size(), wid = (int) matrix[0].size();
        int i = len - 1, j = 0;
        while (i >= 0 && j < wid) {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};
