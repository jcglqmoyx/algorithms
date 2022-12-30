#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int len = (int) matrix.size(), wid = (int) matrix[0].size();
        int low = 0, high = len * wid - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / wid, col = mid % wid;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};