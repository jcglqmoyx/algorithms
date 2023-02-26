#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftRigthDifference(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n), rs(n);
        for (int i = n - 2; i >= 0; i--) {
            rs[i] = rs[i + 1] + nums[i + 1];
        }
        int ls = 0;
        for (int i = 0; i < n; i++) {
            res[i] = abs(ls - rs[i]);
            ls += nums[i];
        }
        return res;
    }
};