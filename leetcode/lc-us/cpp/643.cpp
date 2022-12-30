#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double sum = 0.0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double max_sum = sum;
        for (int i = 1; i <= nums.size() - k; i++) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum / k;
    }
};