#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int n = (int) nums.size();
        return max(range_rob(nums, 0, n - 1), range_rob(nums, 1, n));
    }

private:
    int range_rob(vector<int> &nums, int start, int end) {
        int first = 0, second = 0;
        int max_amount = 0;
        for (int i = start; i < end; i++) {
            max_amount = max(first + nums[i], second);
            first = second;
            second = max_amount;
        }
        return max_amount;
    }
};