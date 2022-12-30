#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % k) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > target) return false;
        int index = (int) nums.size() - 1;
        while (index >= 0 && nums[index] == target) {
            index--;
            k--;
        }
        vector<int> subsets(k);
        return backtrack(nums, subsets, index, target);
    }

private:
    bool backtrack(vector<int> &nums, vector<int> &subsets, int index, int target) {
        if (index < 0) return true;
        int selected = nums[index];
        for (int i = 0; i < subsets.size(); i++) {
            if (subsets[i] + selected <= target) {
                subsets[i] += selected;
                if (backtrack(nums, subsets, index - 1, target)) return true;
                subsets[i] -= selected;
            }
            if (subsets[i] == 0) break;
        }
        return false;
    }
};