#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        for (int i = n; i < 2 * n; i++) {
            nums[i] |= (nums[i - n] << 10);
        }
        for (int i = 0; i < n; i++) {
            int j = i * 2;
            nums[j] = nums[i + n] >> 10;
            nums[j + 1] = nums[i + n] & 1023;
        }
        return nums;
    }
};