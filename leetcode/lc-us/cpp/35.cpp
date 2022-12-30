#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0, high = (int) nums.size() - 1, mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (target > nums[low]) {
            return low + 1;
        } else {
            return low;
        }
    }
};