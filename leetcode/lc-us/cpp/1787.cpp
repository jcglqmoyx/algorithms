#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<vector<int>> g(k);
        for (int i = 0; i < n; i++) {
            g[i % k].push_back(nums[i]);
        }
        int f[k + 1][1024];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        int minv = INT32_MAX, sum = 0;
        for (int i = 1; i <= k; i++) {
            int cnt[1024] = {};
            for (int x: g[i - 1]) {
                cnt[x]++;
            }
            int maxv = 0;
            for (int x: cnt) {
                maxv = max(maxv, x);
            }
            minv = min(minv, maxv);
            sum += (int) g[i - 1].size() - maxv;
            for (int j = 0; j < 1024; j++) {
                for (int x: g[i - 1]) {
                    int cost = (int) g[i - 1].size() - cnt[x];
                    f[i][j] = min(f[i][j], f[i - 1][j ^ x] + cost);
                }
            }
        }
        return min(f[k][0], sum + minv);
    }
};