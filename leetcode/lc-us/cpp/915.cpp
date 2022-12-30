#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int> &nums) {
        const int INF = 1e9;
        int n = (int) nums.size();
        vector<int> l(n), r(n);
        int mx = -INF, mn = nums.back();
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            l[i] = mx;
        }
        for (int i = n - 2; i >= 0; i--) {
            mn = min(mn, nums[i + 1]);
            r[i] = mn;
        }
        for (int i = 0; i < n; i++) {
            if (l[i] <= r[i]) return i + 1;
        }
        return 0;
    }
};