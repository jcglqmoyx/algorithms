#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        vector<int> dp(n, 1);
        int max_len = 0;
        int max_value = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_value = nums[i];
                index = i;
            }
        }
        int cur_len = max_len;
        int cur_value = max_value;
        vector<int> res;
        for (int i = index; i >= 0; i--) {
            if (cur_len == 0) break;
            if (cur_value % nums[i] == 0 && cur_len == dp[i]) {
                res.push_back(nums[i]);
                cur_len--;
                cur_value = nums[i];
            }
        }
        return res;
    }
};