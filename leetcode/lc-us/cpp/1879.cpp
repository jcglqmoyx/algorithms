#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size(), INF = 1e9;
        vector<int> f(1 << n, INF);
        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) s++;
            }
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i - (1 << j)] + (nums1[s - 1] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};