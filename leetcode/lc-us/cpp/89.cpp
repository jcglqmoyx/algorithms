#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nums(1 << n);
        for (int i = 0; i < 1 << n; i++) {
            nums[i] = (i >> 1) ^ i;
        }
        return nums;
    }
};