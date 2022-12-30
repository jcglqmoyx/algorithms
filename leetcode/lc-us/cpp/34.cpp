#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binary_search(vector<int> &nums, int target, bool lower) {
        int low = 0, high = (int) nums.size() - 1;
        int ans = (int) nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target || lower && nums[mid] == target) {
                high = mid - 1;
                ans = mid;
            } else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = binary_search(nums, target, true);
        int right = binary_search(nums, target, false) - 1;
        if (left >= 0 && left < nums.size() && right >= 0 && right < nums.size() && nums[left] == target &&
            nums[right] == target) {
            return {left, right};
        }
        return {-1, -1};
    }
};