#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};
