#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) return true;
        int right_most = 0;
        for (int i = 0; i < nums.size(); i++) {
            right_most = max(right_most, i + nums[i]);
            if (right_most >= nums.size() - 1) return true;
            if (right_most == i) return false;
        }
        return false;
    }
};