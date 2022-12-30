#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int n = (int) s.size();
        int res = n, pre_best = n, pre_sum = 0;
        for (int j = 0; j < n; j++) {
            pre_best = min(pre_best, j - 2 * pre_sum);
            pre_sum += s[j] & 1;
            res = min(res, pre_best + 2 * pre_sum - j + n - 1);
        }
        return res;
    }
};