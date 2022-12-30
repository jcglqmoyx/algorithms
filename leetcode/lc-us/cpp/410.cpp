#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(vector<int> &nums, int mx, int m) {
        int cnt = 0, n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            cnt++;
            int j = i + 1;
            int s = nums[i];
            while (j < n && s + nums[j] <= mx) {
                s += nums[j];
                j++;
            }
            i = j - 1;
        }
        return cnt <= m;
    }

public:
    int splitArray(vector<int> &nums, int m) {
        int l = 0, r = 0;
        for (int x: nums) {
            l = max(l, x);
            r += x;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid, m)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};