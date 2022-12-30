#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = (int) nums.size();
        vector<vector<int>> res;
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1, target = -nums[i];
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int p = l + 1;
                    while (p < r && nums[p] == nums[l]) p++;
                    l = p;
                } else if (sum > target) r--;
                else l++;
            }
        }
        return res;
    }
};