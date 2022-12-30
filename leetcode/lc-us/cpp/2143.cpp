#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubranges(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size(), mod = 1e9 + 7;
        int a = accumulate(nums1.begin(), nums1.end(), 0), b = accumulate(nums2.begin(), nums2.end(), 0);
        int f[n][a + b + 1];
        memset(f, 0, sizeof f);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums1[i], y = nums2[i];
            f[i][x + b]++;
            f[i][b - y]++;
            if (i) {
                for (int j = 0; j <= a + b; j++) {
                    if (f[i - 1][j]) {
                        f[i][j + x] = (f[i][j + x] + f[i - 1][j]) % mod;
                        f[i][j - y] = (f[i][j - y] + f[i - 1][j]) % mod;
                    }
                }
            }
            res = (res + f[i][0 + b]) % mod;
        }
        return res;
    }
};