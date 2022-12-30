#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int> &stones) {
        auto n = stones.size();
        vector<int> pre;
        partial_sum(stones.begin(), stones.end(), back_inserter(pre));
        vector<int> f(n);
        f[n - 1] = pre[n - 1];
        for (auto i = n - 2; i > 0; i--) {
            f[i] = max(f[i + 1], pre[i] - f[i + 1]);
        }
        return f[1];
    }
};