#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {
        vector<int> backup = nums;
        int n = (int) nums.size(), a = 0, b = 0;
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (flag) {
                if (nums[i] >= nums[i + 1]) {
                    a += nums[i] - nums[i + 1] + 1;
                }
            } else {
                if (nums[i] <= nums[i + 1]) {
                    a += nums[i + 1] - nums[i] + 1;
                    nums[i + 1] = nums[i] - 1;
                }
            }
            flag = !flag;
        }
        flag = true, nums = backup;
        for (int i = 0; i < n - 1; i++) {
            if (flag) {
                if (nums[i] <= nums[i + 1]) {
                    b += nums[i + 1] - nums[i] + 1;
                    nums[i + 1] = nums[i] - 1;
                }
            } else {
                if (nums[i] >= nums[i + 1]) {
                    b += nums[i] - nums[i + 1] + 1;
                }
            }
            flag = !flag;
        }
        return min(a, b);
    }
};