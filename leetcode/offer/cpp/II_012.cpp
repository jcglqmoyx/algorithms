#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0, left_sum = 0;
        for (int num: nums) {
            sum += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (sum - left_sum - nums[i] == left_sum) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};