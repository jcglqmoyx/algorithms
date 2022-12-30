#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        vector<int> pos(n);
        for (int i = 0; i < m; i++) {
            bool flag = true;
            for (int row = 1; row < n; row++) {
                pos[row] = lower_bound(begin(mat[row]) + pos[row], end(mat[row]), mat[0][i]) - begin(mat[row]);
                if (pos[row] >= m) {
                    return false;
                }
                flag = mat[row][pos[row]] == mat[0][i];
                if (!flag) break;
            }
            if (flag) return mat[0][i];
        }
        return -1;
    }
};