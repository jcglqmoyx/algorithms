#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum == target) return {nums[low], nums[high]};
            else if (sum > target) high--;
            else low++;
        }
        return {};
    }
};