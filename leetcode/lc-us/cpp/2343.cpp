#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        int n = (int) nums.size(), m = (int) nums[0].size();
        vector<int> res;
        for (auto &q: queries) {
            int k = q[0], t = q[1];
            vector<pair<string, int>> v(n);
            for (int i = 0; i < n; i++) {
                v[i] = {nums[i].substr(m - t), i};
            }
            sort(v.begin(), v.end());
            res.push_back(v[k - 1].second);
        }
        return res;
    }
};