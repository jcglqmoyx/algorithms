#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    static bool check(vector<int> &batteries, LL time, int n) {
        LL sum = 0;
        for (int b: batteries) {
            sum += min((LL) b, time);
        }
        return sum >= time * n;
    }

public:
    long long maxRunTime(int n, vector<int> &batteries) {
        LL l = 0, r = 1e14;
        while (l < r) {
            LL mid = (l + r + 1) >> 1;
            if (check(batteries, mid, n)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};