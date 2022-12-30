#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[nums[i]] < 0) return nums[i];
            } else {
                if (nums[-nums[i]] < 0) return -nums[i];
            }
            if (nums[i] > 0) nums[nums[i]] *= -1;
            else nums[-nums[i]] *= -1;
        }
        return 0;
    }
};