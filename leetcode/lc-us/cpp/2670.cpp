#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n);
        unordered_set<int> s;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = (int) s.size();
            s.insert(nums[i]);
        }
        s.clear();
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            res[i] = (int) s.size() - res[i];
        }
        return res;
    }
};