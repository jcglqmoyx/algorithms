#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestSubarray(vector<int> &nums, int k) {
        vector<int> res;
        int max_beginning = 0;
        int max_index = 0;
        for (int i = 0; i <= nums.size() - k; i++) {
            if (nums[i] > max_beginning) {
                max_beginning = nums[i];
                max_index = i;
            }
        }
        for (int i = max_index; i < max_index + k; i++) {
            res.push_back(nums[i]);
        }
        return res;
    }
};