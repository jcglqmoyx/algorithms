#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int> &nums, int k) {
        using LL = long long;
        int n = (int) nums.size(), res0 = 0, res1 = 0;

        unordered_map<LL, int> ML, MR;

        LL s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += nums[i];
            MR[s]++;
        }

        LL si = 0;
        for (int i = 1; i <= n; i++) {
            si += nums[i - 1];
            if (i < n && si * 2 == s) res0++;
            LL t = s + k - nums[i - 1];
            LL suffix = s - si + nums[i - 1];
            MR[suffix]--;
            if (!(t & 1)) {
                int l = 0, r = 0;
                if (i < n) l = MR[t / 2];
                if (i > 1) r = ML[t / 2];
                res1 = max(res1, l + r);
            }
            ML[si]++;
        }
        return max(res0, res1);
    }
};