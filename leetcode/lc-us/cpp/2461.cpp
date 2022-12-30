#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        int n = (int) nums.size();
        long long res = 0, sum = 0;
        for (int j = 0, i = 0; i < n; i++) {
            sum += nums[i];
            cnt[nums[i]]++;
            if (i - j + 1 == k) {
                if (cnt.size() == k) res = max(res, sum);
                sum -= nums[j];
                cnt[nums[j]]--;
                if (cnt[nums[j]] == 0) cnt.erase(nums[j]);
                j++;
            }
        }
        return res;
    }
};