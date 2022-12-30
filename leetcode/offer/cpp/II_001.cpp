#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == 0) return 0;
        bool flag = false;
        if (a < 0 && b > 0 || a > 0 && b < 0) flag = true;
        LL m = (LL) abs(a), n = (LL) abs(b);
        if (m < n) return 0;
        LL res = divide(m, n);
        if (res > INT32_MAX) {
            if (flag) return INT32_MIN;
            else return INT32_MAX;
        }
        return flag ? -(int) res : (int) res;
    }

private:
    using LL = long long;

    LL divide(LL m, LL n) {
        if (m < n) return 0;
        LL tmp = n;
        LL res = 1;
        while (m >= tmp << 1) {
            tmp <<= 1;
            res <<= 1;
        }
        return res + divide(m - tmp, n);
    }
};