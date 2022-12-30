#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int even = 0, odd = 1;
        while (even < nums.size() && odd < nums.size()) {
            while (even < nums.size() && nums[even] % 2 == 0) {
                even += 2;
            }
            while (odd < nums.size() && nums[odd] % 2 == 1) {
                odd += 2;
            }
            if (odd < nums.size() && even < nums.size()) {
                swap(nums[odd], nums[even]);
            }
            odd += 2;
            even += 2;
        }
        return nums;
    }
};