#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0) {
                joker++;
                continue;
            } else if (nums[i] == nums[i + 1])
                return false;
            joker -= nums[i + 1] - nums[i] - 1;
        }
        return joker >= 0;
    }
};