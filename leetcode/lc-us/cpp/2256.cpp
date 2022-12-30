#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        int n = (int) nums.size();
        long long left = 0, right = 0;
        for (int x: nums) right += x;
        long long min_avg = INT32_MAX;
        int idx;
        for (int i = 0; i < n; i++) {
            left += nums[i], right -= nums[i];
            long long avg = left / (i + 1);
            if (n - i - 1) avg -= right / (n - i - 1);
            avg = abs(avg);
            if (avg < min_avg) {
                min_avg = avg;
                idx = i;
            }
        }
        return idx;
    }
};