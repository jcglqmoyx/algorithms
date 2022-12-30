#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        using LL = long long;
        int n = (int) nums.size(), res = 0;
        vector<unordered_map<LL, int>> f(n);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                LL d = (LL) nums[j] - nums[i];
                auto it = f[i].find(d);
                int t = 0;
                if (it != f[i].end()) {
                    res += it->second;
                    t = it->second;
                }
                f[j][d] += t + 1;
            }
        }
        return res;
    }
};