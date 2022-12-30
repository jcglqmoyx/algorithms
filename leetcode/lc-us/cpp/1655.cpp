#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity) {
        unordered_map<int, int> cnt;
        for (int x: nums) cnt[x]++;
        int a[55] = {}, idx = 1;
        for (auto[k, v]: cnt) {
            a[idx++] = v;
        }
        int n = idx, m = (int) quantity.size();
        int s[1 << m];
        memset(s, 0, sizeof s);
        for (int i = 0; i < 1 << m; i++) {
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    s[i] += quantity[j];
                }
            }
        }
        int f[n + 1][1 << m];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1 << m; j++) {
                if (f[i][j]) {
                    f[i + 1][j] = true;
                    for (int t = j ^ (1 << m) - 1, k = t; k; k = (k - 1) & t) {
                        if (s[k] <= a[i + 1]) {
                            f[i + 1][j | k] = true;
                        }
                    }
                }
            }
        }
        return f[n][(1 << m) - 1];
    }
};