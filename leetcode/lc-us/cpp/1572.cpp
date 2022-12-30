#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int n = (int) mat.size();
        int center = mat[n / 2][n / 2];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        if ((n & 1) == 1) {
            sum -= center;
        }
        return sum;
    }
};