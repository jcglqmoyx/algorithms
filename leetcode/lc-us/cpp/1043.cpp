#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = (int) arr.size();
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1, v = 0; j <= min(i, k); j++) {
                v = max(v, arr[i - j]);
                f[i] = max(f[i], f[i - j] + v * j);
            }
        }
        return f[n];
    }
};