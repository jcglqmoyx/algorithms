#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int len = res + 1; i + len <= n + 1 && j + len <= m + 1; len++) {
                    int s = sum[i + len - 1][j + len - 1] - sum[i - 1][j + len - 1] - sum[i + len - 1][j - 1] +
                            sum[i - 1][j - 1];
                    if (s <= threshold) res = len;
                    else break;
                }
            }
        }
        return res;
    }
};