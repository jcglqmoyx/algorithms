#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1, s = 0; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) s++;
            res += s;
        }
        return res;
    }
};