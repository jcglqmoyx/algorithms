#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        int k1 = a[0] + a[1], k2 = b[0] + b[1];
        if (k1 == k2) return a[0] > b[0];
        else return k1 < k2;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
        int n = (int) nums.size(), m = 0;
        for (vector<int> &row: nums) m = max(m, (int) row.size());
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                v.push_back({i, j, nums[i][j]});
            }
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        res.reserve(v.size());
        for (auto &t: v) res.push_back(t[2]);
        return res;
    }
};