#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        if (nums.empty()) {
            if (lower == upper) return {to_string(lower)};
            else return {to_string(lower) + "->" + to_string(upper)};
        }
        vector<string> missing_ranges;
        if (lower < nums.front()) {
            if (lower < nums.front() - 1) {
                missing_ranges.push_back(to_string(lower) + "->" + to_string(nums.front() - 1));
            } else {
                missing_ranges.push_back(to_string(lower));
            }
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] > 2) {
                missing_ranges.push_back(to_string(nums[i] + 1) + "->" + to_string(nums[i + 1] - 1));
            } else if (nums[i + 1] - nums[i] == 2) {
                missing_ranges.push_back(to_string(nums[i] + 1));
            }
        }
        if (upper - nums.back() > 1) {
            missing_ranges.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        } else if (upper - nums.back() == 1) {
            missing_ranges.push_back(to_string(nums.back() + 1));
        }
        return missing_ranges;
    }
};