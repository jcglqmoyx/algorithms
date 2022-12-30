#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid & 1) {
                if (nums[mid] != nums[mid - 1]) r = mid;
                else l = mid + 1;
            } else {
                if (nums[mid] != nums[mid + 1]) r = mid;
                else l = mid + 1;
            }
        }
        return nums[l];
    }
};