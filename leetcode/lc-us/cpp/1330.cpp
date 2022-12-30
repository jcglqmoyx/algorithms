#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int> &nums) {
        int n = (int) nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            res += abs(nums[i] - nums[i + 1]);
        }
        int val = res;
        for (int i = 2; i < n; i++) {
            res = max(res, val - abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[0]));
        }
        for (int i = n - 3; i >= 0; i--) {
            res = max(res, val - abs(nums[i] - nums[i + 1]) + abs(nums[i] - nums[n - 1]));
        }
        int a = max(nums[0], nums[1]), b = min(nums[0], nums[1]);
        for (int i = 0; i < n - 1; i++) {
            a = min(a, max(nums[i], nums[i + 1]));
            b = max(b, min(nums[i], nums[i + 1]));
        }
        res = max(res, val + (b - a) * 2);
        return res;
    }
};