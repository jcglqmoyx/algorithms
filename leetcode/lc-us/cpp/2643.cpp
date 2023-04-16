#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
        auto n = mat.size(), m = mat[0].size();
        int idx = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            int c1 = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) c1++;
            }
            if (c1 > cnt) cnt = c1, idx = i;
        }
        return {idx, cnt};
    }
};