#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int n = (int) nums.size();
        unordered_map<int, int> cnt;
        int pos = (int) (find(nums.begin(), nums.end(), k) - nums.begin());
        int l = 0, g = 0;
        for (int i = pos; i >= 0; i--) {
            if (nums[i] <= k) l++;
            else g++;
            cnt[l - g]++;
        }
        int res = cnt[0] + cnt[1];
        l = g = 0;
        for (int i = pos + 1; i < n; i++) {
            if (nums[i] < k) l++;
            else g++;
            res += cnt[g - l] + cnt[g - l + 1];
        }
        return res;
    }
};
