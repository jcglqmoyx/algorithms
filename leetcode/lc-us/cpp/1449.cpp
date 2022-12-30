#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &cost, int target) {
        vector<int> f(target + 1, -1e8);
        f[0] = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = cost[i]; j <= target; j++) {
                f[j] = max(f[j], f[j - cost[i]] + 1);
            }
        }
        if (f[target] <= 0) return "0";
        string res;
        for (int i = 8, j = target; i >= 0; i--) {
            while (j >= cost[i] && f[j] == f[j - cost[i]] + 1) {
                j -= cost[i];
                res += to_string(i + 1);
            }
        }
        return res;
    }
};