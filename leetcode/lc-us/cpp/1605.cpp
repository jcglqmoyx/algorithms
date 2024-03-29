#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int r = (int) rowSum.size(), c = (int) colSum.size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};