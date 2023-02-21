#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        int right_most[n + 1];
        iota(right_most, right_most + n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
//            right_most[l] = max(right_most[l], r);
            right_most[l] = r;
        }
        int res = 0, last = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            last = max(last, right_most[i]);
            if (i == last) return -1;
            if (i == pre) res++, pre = last;
        }
        return res;
    }
};