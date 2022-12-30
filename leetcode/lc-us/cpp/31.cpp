#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = (int) nums.size(), i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        int j = n - 1;
        if (i >= 0) {
            while (nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};