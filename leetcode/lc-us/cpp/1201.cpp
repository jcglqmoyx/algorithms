#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        using LL = long long;

        int nums[3] = {a, b, c};
        sort(nums, nums + 3);
        LL la = nums[0], lb = nums[1], lc = nums[2];
        LL lcm_ab = la * lb / __gcd(la, lb);
        LL lcm_ac = la * lc / __gcd(la, lc);
        LL lcm_bc = lb * lc / __gcd(lb, lc);
        LL lcm_abc = lcm_ab * lc / __gcd(lcm_ab, lc);
        LL l = 1LL, r = n * la;
        while (l < r) {
            auto mid = (l + r) >> 1;
            auto cnt = mid / la + mid / lb + mid / lc - mid / lcm_ab - mid / lcm_ac - mid / lcm_bc + mid / lcm_abc;
            if (cnt >= n) r = mid;
            else l = mid + 1;
        }
        return (int) l;
    }
};