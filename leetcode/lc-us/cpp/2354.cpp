#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        using ll = long long;
        unordered_set<int> S;
        for (int x: nums) S.insert(x);

        int cnt[32] = {0};
        int ones[S.size()];
        memset(ones, 0, sizeof ones);
        int idx = 0;
        for (int x: S) {
            int t = __builtin_popcount(x);
            ones[idx++] = t;
            cnt[t]++;
        }
        ll res = 0;

        for (int i = 0; i < S.size(); i++) {
            int t = ones[i];
            if (t >= k) {
                res += (int) S.size();
            } else {
                for (int j = k - t; j < 32; j++) {
                    res += cnt[j];
                }
            }
        }
        return res;
    }
};