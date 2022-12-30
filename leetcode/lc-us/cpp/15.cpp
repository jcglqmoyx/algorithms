#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int needed = -nums[i];
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];
                if (sum == needed) {
                    triplets.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low + 1] == nums[low]) low++;
                    while (high > low && nums[high - 1] == nums[high]) high--;
                    low++;
                    high--;
                } else if (sum > needed) high--;
                else low++;
            }
        }
        return triplets;
    }
};