#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int> &nums) {
        using ll = long long;
        const int MOD = 1e9 + 7;

        int n = (int) nums.size();
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + nums[i - 1];
        vector<int> l(n, -1), r(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (!s.empty()) l[i] = s.top();
            s.push(i);
        }
        stack<int> t;
        for (int i = n - 1; ~i; i--) {
            while (!t.empty() && nums[t.top()] >= nums[i]) t.pop();
            if (!t.empty()) r[i] = t.top();
            t.push(i);
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, nums[i] * (sum[r[i]] - sum[l[i] + 1]));
        }
        return (int) (res % MOD);
    }
};