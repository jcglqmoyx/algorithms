#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, int k) {
        using LL = long long;
        int MOD = 1e9 + 7;
        int n = (int) nums.size();
        unordered_map<int, vector<int>> cnt;
        LL res = 0, s = 0;
        int x;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                x = nums[i - k];
                s = s - cnt[x].back();
                cnt[x].pop_back();
                if (!cnt[x].empty()) s += cnt[x].back();
                s = (s + MOD) % MOD;
            }
            x = nums[i];
            if (cnt[x].empty()) cnt[x].push_back(x), s += x;
            else cnt[x].push_back(cnt[x].back() * 1LL * x % MOD), s += cnt[x].back() - cnt[x][cnt[x].size() - 2];
            s = (s + MOD) % MOD;
            if (i >= k - 1) res = max(res, s);
        }
        return (int) res;
    }
};