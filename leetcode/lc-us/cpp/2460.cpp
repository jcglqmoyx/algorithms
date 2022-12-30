#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> res(n);
        int idx = 0;
        for (int x: nums) {
            if (x) res[idx++] = x;
        }
        return res;
    }
};