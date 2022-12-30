#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &nums) {
        vector<bool> res(nums.size());
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num = ((num << 1) + nums[i]) % 5;
            res[i] = num == 0;
        }
        return res;
    }
};