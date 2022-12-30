#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int l = 1; l <= m; l++) {
            for (int r = l; r <= m; r++) {
                unordered_map<int, int> hash;
                hash[0] = 1;
                for (int i = 1; i <= n; i++) {
                    int sum = s[i][r] - s[0][r] - s[i][l - 1] + s[0][l - 1];
                    if (hash.count(sum - target)) res += hash[sum - target];
                    hash[sum]++;
                }
            }
        }
        return res;
    }
};