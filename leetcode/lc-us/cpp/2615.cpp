#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int> &nums) {
        using LL = long long;
        int n = (int) nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }
        vector<LL> res(n);
        for (auto &[k, v]: map) {
            int m = (int) v.size();
            LL r = accumulate(v.begin(), v.end(), 0LL);
            LL l = 0;
            for (int i = 0; i < m; i++) {
                l += v[i], r -= v[i];
                res[v[i]] = (i + 1LL) * v[i] - l + r - (m - 1LL - i) * v[i];
            }
        }
        return res;
    }
};