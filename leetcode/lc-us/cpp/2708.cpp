#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int> &nums) {
        long long res = 1;
        int max_neg = -10;
        int cnt_non_zero = 0;
        bool has_zero = false;
        for (int x: nums) {
            if (!x) has_zero = true;
            else res *= x, cnt_non_zero++;
            if (x < 0) max_neg = max(max_neg, x);
        }
        if (!cnt_non_zero) res = 0;
        else if (res < 0) {
            if (max_neg != -10) {
                if (cnt_non_zero > 1) res /= max_neg;
                else if (has_zero) res = 0;
            } else if (has_zero) res = 0;
        }
        return res;
    }
};