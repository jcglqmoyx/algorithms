#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] - nums[0] - mid >= k) r = mid - 1;
            else l = mid;
        }
        return nums[l] + k - (nums[l] - nums[0] - l);
    }
};