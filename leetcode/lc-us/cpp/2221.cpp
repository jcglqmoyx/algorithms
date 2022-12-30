#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangularSum(vector<int> &nums) {
        int n = (int) nums.size();
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};