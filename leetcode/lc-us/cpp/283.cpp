#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int low = 0;
        int count_zero = 0;
        for (int num: nums) {
            if (num == 0) {
                count_zero++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[low++] = nums[i];
            }
        }
        for (int i = (int) nums.size() - count_zero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};