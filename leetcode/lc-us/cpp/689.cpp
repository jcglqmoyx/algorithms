#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int max_sum1 = 0, max_sum12 = 0, max_sum = 0;
        int max_sum_idx1, max_sum12_idx1, max_sum12_idx2;
        vector<int> res;
        for (int i = k * 2; i < nums.size(); i++) {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1) {
                if (sum1 > max_sum1) {
                    max_sum1 = sum1;
                    max_sum_idx1 = i - k * 3 + 1;
                }
                if (max_sum1 + sum2 > max_sum12) {
                    max_sum12 = max_sum1 + sum2;
                    max_sum12_idx1 = max_sum_idx1;
                    max_sum12_idx2 = i - k * 2 + 1;
                }
                if (max_sum12 + sum3 > max_sum) {
                    max_sum = max_sum12 + sum3;
                    res = {max_sum12_idx1, max_sum12_idx2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return res;
    }
};