#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binarySearchableNumbers(vector<int> &nums) {
        int n = (int) nums.size(), cnt = 0;
        int mn, mx = nums[0];
        vector<bool> f(n, true);
        for (int i = 0; i < n; i++) {
            if (nums[i] < mx) f[i] = false;
            mx = max(mx, nums[i]);
        }
        mn = nums[n - 1];
        for (int i = n - 1; ~i; i--) {
            if (nums[i] > mn) f[i] = false;
            mn = min(mn, nums[i]);
        }
        for (int i = 0; i < n; i++) if (f[i]) cnt++;
        return cnt;
    }
};