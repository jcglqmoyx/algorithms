#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; i++) a[i] = nums[i - 1];
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 3; len <= n + 2; len++) {
            for (int i = 0; i + len - 1 <= n + 1; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k <= j - 1; k++) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return f[0][n + 1];
    }
};