#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        int res = 0;
        for (int i = 0; i < 1 << m; i++) {
            if (__builtin_popcount(i) != numSelect) continue;
            int t = 0;
            for (int r = 0; r < n; r++) {
                bool flag = true;
                for (int c = 0; c < m; c++) {
                    if (matrix[r][c] && !(i >> c & 1)) {
                        flag = false;
                        break;
                    }
                }
                t += flag;
            }
            res = max(res, t);
        }
        return res;
    }
};