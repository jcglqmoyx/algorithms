#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size(), m = (int) nums2.size();
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = nums1[i] * nums2[j];
                if (i) f[i][j] = max(f[i][j], f[i - 1][j]);
                if (j) f[i][j] = max(f[i][j], f[i][j - 1]);
                if (i && j) f[i][j] = max(f[i][j], f[i - 1][j - 1] + nums1[i] * nums2[j]);
            }
        }
        return f[n - 1][m - 1];
    }
};