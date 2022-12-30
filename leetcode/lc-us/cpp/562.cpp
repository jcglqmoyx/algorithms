#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>> &mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        int len = (int) mat.size(), wid = (int) mat[0].size();
        vector<vector<int>> left(len, vector<int>(wid, 0));
        vector<vector<int>> upper(len, vector<int>(wid, 0));
        vector<vector<int>> upper_left(len, vector<int>(wid, 0));
        vector<vector<int>> upper_right(len, vector<int>(wid, 0));
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (mat[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        upper[i][j] = upper[i - 1][j] + 1;
                        upper_left[i][j] = upper_left[i - 1][j - 1] + 1;
                        left[i][j] = left[i][j - 1] + 1;
                    } else if (i > 0) {
                        upper[i][j] = upper[i - 1][j] + 1;
                        upper_left[i][j] = 1;
                        left[i][j] = 1;
                    } else if (j > 0) {
                        upper[i][j] = 1;
                        upper_left[i][j] = 1;
                        left[i][j] = left[i][j - 1] + 1;
                    } else {
                        upper[i][j] = 1;
                        upper_left[i][j] = 1;
                        left[i][j] = 1;
                    }
                    if (i > 0 && j < wid - 1) {
                        upper_right[i][j] = upper_right[i - 1][j + 1] + 1;
                    } else {
                        upper_right[i][j] = 1;
                    }
                    res = max(res, upper_left[i][j]);
                    res = max(res, upper[i][j]);
                    res = max(res, upper_right[i][j]);
                    res = max(res, left[i][j]);
                }
            }
        }
        return res;
    }
};