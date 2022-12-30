#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        else if ((int) nums.size() == 1) return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        int max_money = second;
        for (int i = 2; i < nums.size(); i++) {
            max_money = max(max_money, max(first + nums[i], second));
            first = second;
            second = max_money;
        }
        return max_money;
    }
};