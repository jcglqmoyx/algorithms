#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        LL la = a, lb = b;
        if (la > lb) swap(la, lb);
        auto lcm = la * lb / __gcd(la, lb);
        LL l = 0, r = n * la;
        while (l < r) {
            auto mid = (l + r) >> 1;
            LL cnt = mid / la + mid / lb - mid / lcm;
            if (cnt >= n) r = mid;
            else l = mid + 1;
        }
        return (int) (l % MOD);
    }
};