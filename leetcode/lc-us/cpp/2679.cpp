#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) {
        int n = (int) nums.size(), m = (int) nums[0].size();
        for (auto &r: nums) sort(r.begin(), r.end());
        int res = 0;
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, nums[i][j]);
            }
            res += mx;
        }
        return res;
    }
};