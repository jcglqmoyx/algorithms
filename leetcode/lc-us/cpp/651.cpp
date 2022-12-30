#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxA(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + 1;
            for (int j = 1; j < i; j++) {
                f[i] = max(f[i], f[j] * (i - j - 1));
            }
        }
        return f[n];
    }
};