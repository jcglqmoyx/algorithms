#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int> &nums, int k) {
        int prev = -10000000;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i - prev <= k) return false;
                prev = i;
            }
        }
        return true;
    }
};