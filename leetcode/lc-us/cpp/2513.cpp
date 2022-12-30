#include <bits/stdc++.h>

using namespace std;

class Solution {
    int gcd(int x, int y) {
        if (x % y == 0) return y;
        return gcd(y, x % y);
    }

public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        int l = 1, r = 2e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid - mid / d1 >= u1) r = mid;
            else l = mid + 1;
        }
        int res = l;

        l = 1, r = 2e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid - mid / d2 >= u2) r = mid;
            else l = mid + 1;
        }
        res = max(res, l);

        l = 1, r = 2e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid - u1 - u2 - mid / ((long long) d1 * d2 / gcd(d1, d2)) >= 0) r = mid;
            else l = mid + 1;
        }
        return max(res, l);
    }
};