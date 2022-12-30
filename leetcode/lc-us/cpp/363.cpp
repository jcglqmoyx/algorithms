#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int res = INT32_MIN;
        for (int l = 1; l <= m; l++) {
            for (int r = l; r <= m; r++) {
                set<int> S;
                S.insert(0);
                for (int i = 1; i <= n; i++) {
                    int sum = s[i][r] - s[0][r] - s[i][l - 1] + s[0][l - 1];
                    auto it = S.lower_bound(sum - k);
                    if (it != S.end()) res = max(res, sum - *it);
                    S.insert(sum);
                }
            }
        }
        return res;
    }
};