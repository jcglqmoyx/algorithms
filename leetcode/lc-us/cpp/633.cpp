#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a <= (long long) sqrt(c); a++) {
            long long b = c - a * a;
            auto st = (long long) sqrt(b);
            if (st * st == b) return true;
        }
        return false;
    }
};