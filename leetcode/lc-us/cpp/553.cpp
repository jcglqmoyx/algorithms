#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string res = to_string(nums[0]) + "/(";
        for (int i = 1; i < n; i++) {
            res += to_string(nums[i]) + "/";
        }
        res.pop_back();
        res.push_back(')');
        return res;
    }
};