#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = nums[0], largest = sum;
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0) sum = nums[i];
            else sum += nums[i];
            largest = max(largest, sum);
        }
        return largest;
    }
};