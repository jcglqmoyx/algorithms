#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        using LL = long long;
        if (k == 1) return 0;
        int n = (int) nums.size();
        vector<int> p;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                p.push_back(i + 1);
            }
        }
        n = (int) p.size();
        vector<LL> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + p[i - 1];
        }
        int left_half = (k + 1) / 2, right_half = k - left_half;
        LL res = INT32_MAX;
        for (int i = 1; i + k - 1 <= n; i++) {
            int mi = i + left_half - 1;
            int mp = p[mi - 1];
            int lp = mp - left_half + 1;
            LL l = (LL) (lp + mp - 1) * (mp - lp) / 2 - (s[mi - 1] - s[i - 1]);

            int ri = i + k - 1;
            int rp = mp + right_half;
            LL r = (s[ri] - s[mi]) - (LL) (rp + mp + 1) * (rp - mp) / 2;

            res = min(res, l + r);
        }
        return (int) res;
    }
};