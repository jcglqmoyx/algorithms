#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int operations = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                operations += nums[i] + 1 - nums[i + 1];
                nums[i + 1] = nums[i] + 1;
            }
        }
        return operations;
    }
};