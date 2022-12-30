#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        vector<int> res;
        unordered_map<int, int> M;
        for (auto &v: nums) {
            for (int x: v) {
                M[x]++;
            }
        }
        for (auto[k, v]: M) {
            if (v == nums.size()) {
                res.push_back(k);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};