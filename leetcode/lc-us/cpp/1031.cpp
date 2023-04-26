#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int n = (int) nums.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        auto get = [&](int a, int b) {
            int f[n + 1];
            f[a - 1] = 0;
            for (int i = 1, seg = 0; i <= n; i++) {
                seg += nums[i - 1];
                if (i >= a) {
                    f[i] = max(seg, f[i - 1]);
                    seg -= nums[i - a];
                }
            }
            int res = 0;
            for (int j = n - b + 1; j > a; j--) {
                res = max(res, s[j + b - 1] - s[j - 1] + f[j - 1]);
            }
            return res;
        };
        return max(get(firstLen, secondLen), get(secondLen, firstLen));
    }
};