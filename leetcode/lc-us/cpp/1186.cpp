#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int mx = *max_element(arr.begin(), arr.end());
        if (mx <= 0) return mx;
        int res = INT32_MIN;
        int dp1 = 0, dp2 = 0;
        for (int x: arr) {
            dp1 = max(dp1 + x, dp2);
            dp2 = max(dp2 + x, 0);
            res = max(res, dp1);
        }
        return res;
    }
};