#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &nums) {
        auto n = nums.size();
        vector<long long> res(n);
        long long s = 0;
        for (int i = 0, mx = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            s += mx + nums[i];
            res[i] = s;
        }
        return res;
    }
};