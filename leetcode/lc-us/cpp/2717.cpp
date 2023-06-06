#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int> &nums) {
        int n = (int) nums.size();
        int pa, pb;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) pa = i;
            if (nums[i] == n) pb = i;
        }
        int res = pa + (n - pb - 1);
        if (pa > pb) res--;
        return res;
    }
};