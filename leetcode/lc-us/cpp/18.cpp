#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        using LL = long long;
        vector<vector<int>> res;
        int n = (int) nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if ((LL) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if ((LL) nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if ((LL) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if ((LL) nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                int low = j + 1, high = n - 1;
                while (low < high) {
                    LL sum = (LL) nums[i] + nums[j] + nums[low] + nums[high];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        high--;
                    } else if (sum < target) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};