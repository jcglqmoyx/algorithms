#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int low = 0, high = (int) nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) low = mid + 2;
            else high = mid;
        }
        return nums[low];
    }
};