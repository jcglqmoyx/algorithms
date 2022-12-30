#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        vector<int> res;
        int max_area = -1e8;
        for (int l = 1; l <= m; l++) {
            for (int r = l; r <= m; r++) {
                int mn = 1e8, x = 0, y = l - 1;
                for (int i = 1; i <= n; i++) {
                    int sum = s[i][r] - s[0][r] - s[i][l - 1] + s[0][l - 1];
                    int diff = sum - mn;
                    if (diff > max_area) {
                        max_area = diff;
                        res = {x + 1, y, i - 1, r - 1};
                    }
                    if (sum > max_area) {
                        max_area = sum;
                        res = {0, y, i - 1, r - 1};
                    }
                    if (sum < mn) {
                        mn = sum;
                        x = i - 1, y = l - 1;
                    }
                }
            }
        }
        return res;
    }
};