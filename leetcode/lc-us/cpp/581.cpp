#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = (int) nums.size();
        int i = 0, j = n - 1;
        while (i < j && nums[i] <= nums[i + 1]) {
            i++;
        }
        while (j > i && nums[j] >= nums[j - 1]) {
            j--;
        }
        int mn = nums[i], mx = nums[i];
        for (int k = i + 1; k <= j; k++) {
            mn = min(mn, nums[k]);
            mx = max(mx, nums[k]);
        }
        if (i == j) return 0;
        int l = i, r = j;
        while (l >= 0 && nums[l] > mn) l--;
        l++;
        while (r < n && nums[r] < mx) r++;
        r--;
        return r - l + 1;
    }
};