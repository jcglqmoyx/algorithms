#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        int res = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};