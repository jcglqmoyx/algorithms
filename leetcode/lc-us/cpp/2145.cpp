#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        using LL = long long;
        LL sum = 0;
        LL mn = INT64_MAX, mx = INT64_MIN;
        for (int x: differences) {
            sum += x;
            mn = min(mn, sum), mx = max(mx, sum);
        }
        if (lower + mx > upper || upper + mn < lower) return 0;
        LL r = min(upper - mx, (LL) upper), l = max(lower - mn, (LL) lower);
        int res = (int) (r - l + 1);
        return max(res, 0);
    }
};