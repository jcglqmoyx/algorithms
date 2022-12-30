#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        int right_sum = 0;
        vector<int> sub;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            sub.push_back(nums[i]);
            right_sum += nums[i];
            if (right_sum > sum / 2) {
                break;
            }
        }
        return sub;
    }
};