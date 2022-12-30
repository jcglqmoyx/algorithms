#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int validSubarraySplit(vector<int> &nums) {
        int n = (int) nums.size();
        if (nums[0] == 1 || nums[n - 1] == 0) return -1;
        int f[n];
        memset(f, -1, sizeof f);
        function<int(int)> dp = [&](int u) -> int {
            if (u == n) return 0;
            if (nums[u] == 1) return n + 1;
            if (f[u] != -1) return f[u];
            f[u] = n + 1;
            for (int i = u; i < n; i++) {
                if (gcd(nums[u], nums[i]) > 1) {
                    f[u] = min(f[u], dp(i + 1) + 1);
                }
            }
            return f[u];
        };

        int t = dp(0);
        if (t > n) return -1;
        return t;
    }

private:
    int gcd(int x, int y) {
        return x % y == 0 ? y : gcd(y, x % y);
    }
};