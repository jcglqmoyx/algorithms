#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int l = 0, r = nums[n - 1] - nums[0];
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0, left = 0;
            for (int right = 1; right < n; right++) {
                while (left < right && nums[right] - nums[left] > mid) left++;
                cnt += right - left;
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};