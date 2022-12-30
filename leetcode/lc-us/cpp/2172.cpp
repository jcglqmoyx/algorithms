#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int> &nums, int numSlots) {
        int tot = (int) pow(3, numSlots);
        vector<int> f(tot);
        for (int mask = 1; mask < tot; mask++) {
            int cnt = 0;
            for (int dummy = mask, i = 0; i < numSlots; i++, dummy /= 3) {
                cnt += dummy % 3;
            }
            if (cnt > nums.size()) continue;
            for (int dummy = mask, w = 1, i = 1; i <= numSlots; i++, w *= 3, dummy /= 3) {
                int has = dummy % 3;
                if (has) {
                    f[mask] = max(f[mask], f[mask - w] + (nums[cnt - 1] & i));
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};