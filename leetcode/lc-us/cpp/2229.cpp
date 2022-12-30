#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isConsecutive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[0] + i) return false;
        }
        return true;
    }
};