#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int w = sum / 2, n = (int) stones.size();
        vector<int> f(w + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = w; j >= stones[i - 1]; j--) {
                f[j] = max(f[j], f[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * f[w];
    }
};