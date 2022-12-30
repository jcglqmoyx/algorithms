#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = (int) nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[n - 1]) {
                high = mid;
            } else if (nums[mid] >= nums[0]) {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};