#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        int n = (int) nums.size();
        unordered_set<int> S;
        for (int i = 0; i < n - 1; i++) {
            int s = nums[i] + nums[i + 1];
            if (S.count(s)) return true;
            S.insert(s);
        }
        return false;
    }
};