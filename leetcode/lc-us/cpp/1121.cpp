#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int> &nums, int k) {
        int pre = nums[0], cnt = 0;
        for (int n: nums) {
            if (n == pre)
                cnt++;
            else {
                pre = n;
                cnt = 1;
            }
            if (cnt * k > nums.size())
                return false;
        }
        return true;
    }
};