#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        int size = (int) original.size();
        if (size != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0, idx = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = original[idx++];
            }
        }
        return res;
    }
};