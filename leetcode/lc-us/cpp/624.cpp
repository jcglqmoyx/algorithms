#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int mn = INT32_MAX, mx = INT32_MIN;
        int n = (int) arrays.size();
        mn = min(mn, arrays[0][0]), mx = max(mx, arrays[0].back());
        int res = 0;
        for (int i = 1; i < n; i++) {
            auto &a = arrays[i];
            res = max(res, max(abs(a[0] - mx), abs(a.back() - mn)));
            mn = min(mn, a[0]), mx = max(mx, a.back());
        }
        return res;
    }
};