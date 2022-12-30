#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        int res = 0;
        vector<int> q(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) q[j] = matrix[i][j];
            sort(q.begin(), q.end(), greater<>());
            for (int j = 0; j < m; j++) {
                res = max(res, q[j] * (j + 1));
            }
        }
        return res;
    }
};