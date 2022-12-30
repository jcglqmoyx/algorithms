#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        using ll = long long;

        int n = (int) nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {nums[i], cost[i]};
        sort(v.begin(), v.end());

        ll res = 0;
        int p = v[0].first;
        ll l_sum = v[0].second, r_sum = 0;
        for (int i = 1; i < n; i++) {
            res += 1LL * (v[i].first - p) * v[i].second;
            r_sum += v[i].second;
        }
        ll l_cost = 0, r_cost = res;
        for (int i = 1; i < n; i++) {
            l_cost += (v[i].first - v[i - 1].first) * 1LL * l_sum;
            r_cost -= (v[i].first - v[i - 1].first) * 1LL * r_sum;
            res = min(res, l_cost + r_cost);
            l_sum += v[i].second, r_sum -= v[i].second;
        }
        return res;
    }
};