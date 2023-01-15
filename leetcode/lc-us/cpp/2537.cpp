#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        using LL = long long;
        LL res = 0;
        int pairs = 0;
        unordered_map<int, int> cnt;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            pairs += cnt[nums[r]];
            cnt[nums[r]]++;
            while (pairs >= k) {
                pairs -= cnt[nums[l]] - 1;
                cnt[nums[l]]--;
                l += 1;
            }
            res += l;
        }
        return res;
    }
};