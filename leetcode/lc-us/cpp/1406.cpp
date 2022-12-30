#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int> &stoneValue) {
        int n = (int) stoneValue.size();
        vector<int> f(n + 1, -1e8);
        f[n] = 0;
        for (int i = n - 1; ~i; i--) {
            int pre = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                pre += stoneValue[j];
                f[i] = max(pre - f[j + 1], f[i]);
            }
        }
        return f[0] > 0 ? "Alice" : f[0] < 0 ? "Bob" : "Tie";
    }
};